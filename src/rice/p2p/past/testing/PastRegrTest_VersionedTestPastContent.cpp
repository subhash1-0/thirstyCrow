// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_VersionedTestPastContent.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
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

rice::p2p::past::testing::PastRegrTest_VersionedTestPastContent::PastRegrTest_VersionedTestPastContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::PastRegrTest_VersionedTestPastContent::PastRegrTest_VersionedTestPastContent(::rice::p2p::commonapi::Id* id, int32_t version) 
    : PastRegrTest_VersionedTestPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,version);
}

void rice::p2p::past::testing::PastRegrTest_VersionedTestPastContent::init()
{
    version = int32_t(0);
}

void rice::p2p::past::testing::PastRegrTest_VersionedTestPastContent::ctor(::rice::p2p::commonapi::Id* id, int32_t version)
{
    super::ctor(id);
    init();
    this->version = version;
}

bool rice::p2p::past::testing::PastRegrTest_VersionedTestPastContent::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< PastRegrTest_VersionedTestPastContent* >(o) != nullptr))
        return false;

    return (npc(npc((java_cast< PastRegrTest_VersionedTestPastContent* >(o)))->id)->equals(id) && (npc((java_cast< PastRegrTest_VersionedTestPastContent* >(o)))->version == version));
}

java::lang::String* rice::p2p::past::testing::PastRegrTest_VersionedTestPastContent::toString()
{
    return ::java::lang::StringBuilder().append(u"VersionedTestPastContent("_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u", "_j)
        ->append(version)
        ->append(u")"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_VersionedTestPastContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.PastRegrTest.VersionedTestPastContent", 59);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_VersionedTestPastContent::getClass0()
{
    return class_();
}

