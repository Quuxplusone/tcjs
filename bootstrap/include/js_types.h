#pragma once
#include <type_traits>
#include <optional>
#include <emscripten/val.h>
#include <emscripten/wire.h>
#include "noncopyable.h"
#include "type_list.h"
#include "type_traits.h"
#include "tc_move.h"
#include "js_ref.h"

namespace tc::js {
namespace wrapper_detail {
namespace no_adl {
template<typename T, typename Name>
struct CPropertyProxy : tc::nonmovable {
    CPropertyProxy(emscripten::val m_emval, Name m_name)
        : m_emval(tc_move(m_emval))
        , m_name(tc_move(m_name)) {
    }

    // TODO: it's still possible to use incorrectly:
    // auto x = foo["bar"]; // Presumably copy.
    // foo["bar"] = undefined;
    // baz(tc_move(x)); // 'Moving' value to baz.
    operator T() && { return m_emval[m_name].template as<T>(); }
    T const& operator=(T const& value) && {
        m_emval.set(m_name, emscripten::val(value));
        return value;
    }

private:
    emscripten::val m_emval;
    Name m_name;
};
} // namespace no_adl
using no_adl::CPropertyProxy;
} // namespace wrapper_detail

namespace no_adl {
struct IAny : virtual IJsBase {
};

template<typename, typename = void, typename = void>
struct IJsFunction {};

template<typename R, typename... Args, typename TThis, typename TArgs>
struct IJsFunction<R(Args...), TThis, TArgs> : virtual IJsBase {
    static_assert(tc::is_decayed<R>::value);
    static_assert(std::conjunction<tc::is_decayed<Args>...>::value);
    static_assert(tc::is_decayed<TThis>::value);
    static_assert(tc::is_decayed<TArgs>::value);
};

template<typename R, typename... Args>
struct IJsFunction<R(Args...), void, void> : virtual IJsBase {
    static_assert(tc::is_decayed<R>::value);
    static_assert(std::conjunction<tc::is_decayed<Args>...>::value);

    R operator()(Args... args) noexcept {
        return m_emval(tc_move(args)...).template as<R>();
    }
};
} // namespace no_adl
using no_adl::IAny;
using no_adl::IJsFunction;
} // namespace tc::js

// Custom marshalling
namespace emscripten::internal {
    // TODO: optimize by providing JS-side toWireType/fromWireType for integrals/bools and getting rid of emscripten::val
    template<typename T>
    struct TypeID<T, tc::void_t<std::enable_if_t<tc::is_instance<std::optional, tc::remove_cvref_t<T>>::value>>> {
        static constexpr TYPEID get() {
            // Ensure that the underlying type can be marshalled.
            TypeID<typename tc::remove_cvref_t<T>::value_type>::get();
            return TypeID<val>::get();
        }
    };

    template<typename T>
    struct BindingType<std::optional<T>> {
        typedef typename BindingType<emscripten::val>::WireType WireType;

        static WireType toWireType(std::optional<T> const& optv) {
            if (optv) {
                emscripten::val emval(optv.value());
                _ASSERT(!emval.isUndefined());
                return BindingType<emscripten::val>::toWireType(emval);
            } else {
                return BindingType<emscripten::val>::toWireType(emscripten::val::undefined());
            }
        }

        static auto fromWireType(WireType wire) {
            auto emval = BindingType<emscripten::val>::fromWireType(wire);
            std::optional<T> result;
            if (!emval.isUndefined()) {
                result.emplace(tc_move(emval).as<T>());
            }
            return result;
        }
    };
}
