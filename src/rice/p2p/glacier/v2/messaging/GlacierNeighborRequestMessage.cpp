// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierNeighborRequestMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierNeighborRequestMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::GlacierNeighborRequestMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::GlacierNeighborRequestMessage(int32_t uid, ::rice::p2p::commonapi::IdRange* requestedRange, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierNeighborRequestMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,requestedRange,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::GlacierNeighborRequestMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierNeighborRequestMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::ctor(int32_t uid, ::rice::p2p::commonapi::IdRange* requestedRange, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    super::ctor(uid, source, dest, false, tag);
    this->requestedRange = requestedRange;
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::getRequestedRange()
{
    return requestedRange;
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierNeighborRequest for "_j)->append(static_cast< ::java::lang::Object* >(requestedRange))
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(requestedRange)->serialize(buf);
}

rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage* rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierNeighborRequestMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    requestedRange = npc(endpoint)->readIdRange(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierNeighborRequestMessage", 59);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::getClass0()
{
    return class_();
}

