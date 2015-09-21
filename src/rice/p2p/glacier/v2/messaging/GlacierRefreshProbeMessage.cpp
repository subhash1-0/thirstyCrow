// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierRefreshProbeMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshProbeMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::GlacierRefreshProbeMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::GlacierRefreshProbeMessage(int32_t uid, ::rice::p2p::commonapi::Id* requestedId, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierRefreshProbeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,requestedId,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::GlacierRefreshProbeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierRefreshProbeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::ctor(int32_t uid, ::rice::p2p::commonapi::Id* requestedId, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    super::ctor(uid, source, dest, false, tag);
    this->requestedId = requestedId;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::getRequestedId()
{
    return requestedId;
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierRefreshProbe #"_j)->append(getUID())
        ->append(u" for "_j)
        ->append(static_cast< ::java::lang::Object* >(requestedId))
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeShort(npc(requestedId)->getType());
    npc(requestedId)->serialize(buf);
}

rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage* rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierRefreshProbeMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    requestedId = npc(endpoint)->readId(buf, npc(buf)->readShort());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierRefreshProbeMessage", 56);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::getClass0()
{
    return class_();
}

