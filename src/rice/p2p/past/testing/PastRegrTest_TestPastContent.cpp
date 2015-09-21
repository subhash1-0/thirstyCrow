// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_TestPastContent.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/testing/PastRegrTest_TestPastContentHandle.hpp>

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

rice::p2p::past::testing::PastRegrTest_TestPastContent::PastRegrTest_TestPastContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::PastRegrTest_TestPastContent::PastRegrTest_TestPastContent(::rice::p2p::commonapi::Id* id) 
    : PastRegrTest_TestPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

void rice::p2p::past::testing::PastRegrTest_TestPastContent::ctor(::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    this->id = id;
}

rice::p2p::past::PastContent* rice::p2p::past::testing::PastRegrTest_TestPastContent::checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */
{
    existing = existingContent;
    return this;
}

rice::p2p::past::PastContentHandle* rice::p2p::past::testing::PastRegrTest_TestPastContent::getHandle(::rice::p2p::past::Past* past)
{
    return new PastRegrTest_TestPastContentHandle(past, id);
}

rice::p2p::commonapi::Id* rice::p2p::past::testing::PastRegrTest_TestPastContent::getId()
{
    return id;
}

bool rice::p2p::past::testing::PastRegrTest_TestPastContent::isMutable()
{
    return true;
}

bool rice::p2p::past::testing::PastRegrTest_TestPastContent::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< PastRegrTest_TestPastContent* >(o) != nullptr))
        return false;

    return npc(npc((java_cast< PastRegrTest_TestPastContent* >(o)))->id)->equals(id);
}

java::lang::String* rice::p2p::past::testing::PastRegrTest_TestPastContent::toString()
{
    return ::java::lang::StringBuilder().append(u"TestPastContent("_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u")"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_TestPastContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.PastRegrTest.TestPastContent", 50);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_TestPastContent::getClass0()
{
    return class_();
}

