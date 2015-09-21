// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/OpenChannelMsg.java
#include <rice/pastry/socket/nat/rendezvous/OpenChannelMsg.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::OpenChannelMsg::OpenChannelMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::OpenChannelMsg::OpenChannelMsg(int32_t address, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid) 
    : OpenChannelMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(address,rendezvous,source,uid);
}

constexpr int16_t rice::pastry::socket::nat::rendezvous::OpenChannelMsg::TYPE;

void rice::pastry::socket::nat::rendezvous::OpenChannelMsg::ctor(int32_t address, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid)
{
    super::ctor(address);
    this->rendezvous = rendezvous;
    this->source = source;
    this->uid = uid;
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle* rice::pastry::socket::nat::rendezvous::OpenChannelMsg::getRendezvous()
{
    return rendezvous;
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle* rice::pastry::socket::nat::rendezvous::OpenChannelMsg::getSource()
{
    return source;
}

int32_t rice::pastry::socket::nat::rendezvous::OpenChannelMsg::getUid()
{
    return uid;
}

java::lang::String* rice::pastry::socket::nat::rendezvous::OpenChannelMsg::toString()
{
    return ::java::lang::StringBuilder().append(u"OpenChannelMsg<"_j)->append(uid)
        ->append(u"> source:"_j)
        ->append(static_cast< ::java::lang::Object* >(source))
        ->append(u" rendezvous:"_j)
        ->append(static_cast< ::java::lang::Object* >(rendezvous))->toString();
}

int16_t rice::pastry::socket::nat::rendezvous::OpenChannelMsg::getType()
{
    return TYPE;
}

void rice::pastry::socket::nat::rendezvous::OpenChannelMsg::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(rendezvous)->serialize(buf);
    npc(source)->serialize(buf);
    npc(buf)->writeInt(uid);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::OpenChannelMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.OpenChannelMsg", 48);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::OpenChannelMsg::getClass0()
{
    return class_();
}

