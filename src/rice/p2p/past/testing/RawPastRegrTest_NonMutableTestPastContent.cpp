// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_NonMutableTestPastContent.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Id.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::RawPastRegrTest_NonMutableTestPastContent::RawPastRegrTest_NonMutableTestPastContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::RawPastRegrTest_NonMutableTestPastContent::RawPastRegrTest_NonMutableTestPastContent(::rice::p2p::commonapi::Id* id) 
    : RawPastRegrTest_NonMutableTestPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

void rice::p2p::past::testing::RawPastRegrTest_NonMutableTestPastContent::ctor(::rice::p2p::commonapi::Id* id)
{
    super::ctor(id);
}

bool rice::p2p::past::testing::RawPastRegrTest_NonMutableTestPastContent::isMutable()
{
    return false;
}

bool rice::p2p::past::testing::RawPastRegrTest_NonMutableTestPastContent::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< RawPastRegrTest_NonMutableTestPastContent* >(o) != nullptr))
        return false;

    return npc(npc((java_cast< RawPastRegrTest_NonMutableTestPastContent* >(o)))->id)->equals(id);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_NonMutableTestPastContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.RawPastRegrTest.NonMutableTestPastContent", 63);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_NonMutableTestPastContent::getClass0()
{
    return class_();
}

