// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierTimeoutMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierTimeoutMessage.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage::GlacierTimeoutMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage::GlacierTimeoutMessage(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local) 
    : GlacierTimeoutMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,local);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage::ctor(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local)
{
    super::ctor(uid, local, npc(local)->getId(), false, static_cast< char16_t >(int32_t(0)));
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierTimeoutMessage "_j)->append(getUID())
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"serialize() not supported in GlacierTimeoutMessage"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierTimeoutMessage", 51);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage::getClass0()
{
    return class_();
}

