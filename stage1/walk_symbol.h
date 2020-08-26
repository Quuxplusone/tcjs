#ifndef WALK_SYMBOL_H_
#define WALK_SYMBOL_H_

#include <vector>
#include "typescript.d.bootstrap.h"

extern std::vector<tc::js::ts::Symbol> g_vecjsymEnum, g_vecjsymClass, g_vecjsymTypeAlias;

enum ERecurse {
    erecurseCONTINUE,
    erecurseSKIP,
    erecurseSTOP
};

template<typename Func>
tc::break_or_continue ForEachChildTypeNode(tc::js::ts::Node jnode, Func fn) noexcept {
    switch([&]() noexcept {
        if(auto ojtypenode = tc::js::ts_ext::isTypeNode(jnode)) {
            return fn(*ojtypenode);
        } else {
            return erecurseCONTINUE;
        }
    }()) {
        case erecurseCONTINUE:
        {
            tc::break_or_continue bc = tc::continue_;
            tc::js::ts::forEachChild(jnode, tc::jst::js_lambda_wrap([&](tc::js::ts::Node jnodeInner) noexcept -> tc::jst::js_unknown { 
                if(tc::continue_==bc) {
                    bc = ForEachChildTypeNode(jnodeInner, fn); 
                }
                return tc::jst::js_undefined();
            }));
            return bc;
        }
        case erecurseSKIP:
            return tc::continue_;
        case erecurseSTOP:
            return tc::break_;
    }
}


bool IsEnumInCpp(tc::js::ts::Symbol jsymType) noexcept;
bool IsClassInCpp(tc::js::ts::Symbol jsymType) noexcept;
bool IsTypeAliasInCpp(tc::js::ts::TypeChecker const& jtsTypeChecker, tc::js::ts::Symbol jsymType) noexcept;

void WalkSymbol(tc::js::ts::TypeChecker const& jtsTypeChecker, int nOffset, tc::js::ts::Symbol jsymType) noexcept;

std::vector<tc::js::ts::Symbol> ListSourceFileTopLevel(tc::js::ts::TypeChecker const& jtsTypeChecker, tc::js::ts::SourceFile const jtsSourceFile) noexcept;

#endif // WALK_SYMBOL_H_
