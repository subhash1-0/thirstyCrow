// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierRangeResponseMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierRangeResponseMessage.hpp>

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

rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::GlacierRangeResponseMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::GlacierRangeResponseMessage(int32_t uid, ::rice::p2p::commonapi::IdRange* commonRange, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierRangeResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,commonRange,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::GlacierRangeResponseMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierRangeResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::ctor(int32_t uid, ::rice::p2p::commonapi::IdRange* commonRange, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    super::ctor(uid, source, dest, true, tag);
    this->commonRange = commonRange;
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::getCommonRange()
{
    return commonRange;
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierRangeResponse to UID#"_j)->append(getUID())
        ->append(u", range="_j)
        ->append(static_cast< ::java::lang::Object* >(commonRange))
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(commonRange)->serialize(buf);
}

rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage* rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierRangeResponseMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    commonRange = npc(endpoint)->readIdRange(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierRangeResponseMessage", 57);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::getClass0()
{
    return class_();
}

