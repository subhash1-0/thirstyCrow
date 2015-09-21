// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_TestPastContent.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_TestPastContentHandle.hpp>

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

rice::p2p::past::testing::RawPastRegrTest_TestPastContent::RawPastRegrTest_TestPastContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::RawPastRegrTest_TestPastContent::RawPastRegrTest_TestPastContent(::rice::p2p::commonapi::Id* id) 
    : RawPastRegrTest_TestPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

rice::p2p::past::testing::RawPastRegrTest_TestPastContent::RawPastRegrTest_TestPastContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd)  /* throws(IOException) */
    : RawPastRegrTest_TestPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,pcd);
}

constexpr int16_t rice::p2p::past::testing::RawPastRegrTest_TestPastContent::TYPE;

void rice::p2p::past::testing::RawPastRegrTest_TestPastContent::ctor(::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    this->id = id;
}

rice::p2p::past::PastContent* rice::p2p::past::testing::RawPastRegrTest_TestPastContent::checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */
{
    existing = java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(existingContent);
    return this;
}

rice::p2p::past::PastContentHandle* rice::p2p::past::testing::RawPastRegrTest_TestPastContent::getHandle(::rice::p2p::past::Past* past)
{
    return new RawPastRegrTest_TestPastContentHandle(past, id);
}

rice::p2p::commonapi::Id* rice::p2p::past::testing::RawPastRegrTest_TestPastContent::getId()
{
    return id;
}

bool rice::p2p::past::testing::RawPastRegrTest_TestPastContent::isMutable()
{
    return true;
}

bool rice::p2p::past::testing::RawPastRegrTest_TestPastContent::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< RawPastRegrTest_TestPastContent* >(o) != nullptr))
        return false;

    return npc(npc((java_cast< RawPastRegrTest_TestPastContent* >(o)))->id)->equals(id);
}

java::lang::String* rice::p2p::past::testing::RawPastRegrTest_TestPastContent::toString()
{
    return ::java::lang::StringBuilder().append(u"TestPastContent("_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u")"_j)->toString();
}

int16_t rice::p2p::past::testing::RawPastRegrTest_TestPastContent::getType()
{
    return TYPE;
}

void rice::p2p::past::testing::RawPastRegrTest_TestPastContent::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    super::ctor();
    id = npc(endpoint)->readId(buf, npc(buf)->readShort());
    if(npc(buf)->readBoolean()) {
        auto contentType = npc(buf)->readShort();
        existing = java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(npc(pcd)->deserializePastContent(buf, endpoint, contentType));
    }
}

void rice::p2p::past::testing::RawPastRegrTest_TestPastContent::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
    if(existing == nullptr) {
        npc(buf)->writeBoolean(false);
    } else {
        npc(buf)->writeBoolean(true);
        npc(buf)->writeShort(npc(existing)->getType());
        npc(existing)->serialize(buf);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_TestPastContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.RawPastRegrTest.TestPastContent", 53);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_TestPastContent::getClass0()
{
    return class_();
}

