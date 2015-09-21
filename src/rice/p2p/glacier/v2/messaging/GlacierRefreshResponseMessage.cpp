// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierRefreshResponseMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshResponseMessage.hpp>

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

rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::GlacierRefreshResponseMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::GlacierRefreshResponseMessage(int32_t uid, ::rice::p2p::commonapi::IdRange* range, bool online, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierRefreshResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,range,online,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::GlacierRefreshResponseMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierRefreshResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::ctor(int32_t uid, ::rice::p2p::commonapi::IdRange* range, bool online, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    super::ctor(uid, source, dest, true, tag);
    this->range = range;
    this->online = online;
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::getRange()
{
    return range;
}

bool rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::isOnline()
{
    return online;
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierRefreshResponse for "_j)->append(static_cast< ::java::lang::Object* >(range))
        ->append(u", online="_j)
        ->append(online)
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(range)->serialize(buf);
    npc(buf)->writeBoolean(online);
}

rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage* rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierRefreshResponseMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    range = npc(endpoint)->readIdRange(buf);
    online = npc(buf)->readBoolean();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierRefreshResponseMessage", 59);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::getClass0()
{
    return class_();
}

