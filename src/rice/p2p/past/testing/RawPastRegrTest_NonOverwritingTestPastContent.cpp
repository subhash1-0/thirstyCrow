// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_NonOverwritingTestPastContent.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContent.hpp>

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

rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::RawPastRegrTest_NonOverwritingTestPastContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::RawPastRegrTest_NonOverwritingTestPastContent(::rice::p2p::commonapi::Id* id, int32_t version) 
    : RawPastRegrTest_NonOverwritingTestPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,version);
}

rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::RawPastRegrTest_NonOverwritingTestPastContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd)  /* throws(IOException) */
    : RawPastRegrTest_NonOverwritingTestPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,pcd);
}

constexpr int16_t rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::TYPE;

void rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::ctor(::rice::p2p::commonapi::Id* id, int32_t version)
{
    super::ctor(id, version);
}

rice::p2p::past::PastContent* rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */
{
    return existingContent;
}

java::lang::String* rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::toString()
{
    return ::java::lang::StringBuilder().append(u"NonOverwritingTestPastContent("_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u", "_j)
        ->append(version)
        ->append(u")"_j)->toString();
}

int16_t rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::getType()
{
    return TYPE;
}

void rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    super::ctor(buf, endpoint, pcd);
}

bool rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< RawPastRegrTest_NonOverwritingTestPastContent* >(o) != nullptr))
        return false;

    return (npc(npc((java_cast< RawPastRegrTest_NonOverwritingTestPastContent* >(o)))->id)->equals(id) && (npc((java_cast< RawPastRegrTest_NonOverwritingTestPastContent* >(o)))->version == version));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.RawPastRegrTest.NonOverwritingTestPastContent", 67);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_NonOverwritingTestPastContent::getClass0()
{
    return class_();
}

