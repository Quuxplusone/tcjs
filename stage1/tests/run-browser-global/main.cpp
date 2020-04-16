#include "../../precompiled.h"
#include "MyLib.d.h"

int main() {
	_ASSERTEQUAL(tc::js::globals::sumOfTwo(10, 20), 30);

	_ASSERTEQUAL(tc::js::globals::initially10(), 10);
	tc::js::globals::initially10(12);
	_ASSERTEQUAL(tc::js::globals::initially10(), 12);

	tc::js::globals::SomeObject obj;
	_ASSERTEQUAL(tc::explicit_cast<std::string>(obj->str()), "");
	_ASSERTEQUAL(obj->arr()->length(), 0);
	_ASSERT(tc::empty(obj->arr()));
	_ASSERTEQUAL(tc::explicit_cast<std::string>(obj->foo(10)), "foo() retval number 10");

	tc::js::globals::SomeBaseClass objBase = obj;
	_ASSERT(objBase.getEmval().strictlyEquals(obj.getEmval()));
	_ASSERTEQUAL(tc::explicit_cast<std::string>(objBase->foo(10)), "foo() retval number 10");

	static_assert(std::is_enum<tc::js::globals::SomeEnum>::value);
	static_assert(10 == static_cast<int>(tc::js::globals::SomeEnum::ENUM10));
	static_assert(20 == static_cast<int>(tc::js::globals::SomeEnum::ENUM20));
	static_assert(21 == static_cast<int>(tc::js::globals::SomeEnum::ENUM21));

	_ASSERTEQUAL(tc::js::globals::SomeModule::sumOfThree(10, 20, 30), 60);

	tc::js::globals::SomeObject obj2 = tc::js::globals::createObject(tc::js::js_string("foobar"));
	_ASSERTEQUAL(tc::explicit_cast<std::string>(obj2->str()), "foobar");
	_ASSERTEQUAL(obj2->arr()->length(), 0);
	_ASSERT(tc::empty(obj2->arr()));

	tc::js::globals::SomeObject obj3 = tc::js::globals::appendToObjectStr(obj2);
	_ASSERT(obj3.getEmval().strictlyEquals(obj2.getEmval()));
	_ASSERTEQUAL(tc::explicit_cast<std::string>(obj3->str()), "foobarx");
	_ASSERTEQUAL(obj3->arr()->length(), 0);
	_ASSERT(tc::empty(obj3->arr()));

	printf("Success!\n");
}
