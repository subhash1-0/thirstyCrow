// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/PilotForwardMsg.java
#include <rice/pastry/socket/nat/rendezvous/PilotForwardMsg.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/socket/nat/rendezvous/ByteBufferMsg.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::PilotForwardMsg::PilotForwardMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::PilotForwardMsg::PilotForwardMsg(int32_t address, ByteBufferMsg* msg, RendezvousSocketNodeHandle* target) 
    : PilotForwardMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(address,msg,target);
}

constexpr int16_t rice::pastry::socket::nat::rendezvous::PilotForwardMsg::TYPE;

void rice::pastry::socket::nat::rendezvous::PilotForwardMsg::ctor(int32_t address, ByteBufferMsg* msg, RendezvousSocketNodeHandle* target)
{
    super::ctor(address);
    this->msg = msg;
    this->target = target;
}

int16_t rice::pastry::socket::nat::rendezvous::PilotForwardMsg::getType()
{
    return TYPE;
}

void rice::pastry::socket::nat::rendezvous::PilotForwardMsg::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(target)->serialize(buf);
    npc(msg)->serialize(buf);
}

rice::pastry::socket::nat::rendezvous::ByteBufferMsg* rice::pastry::socket::nat::rendezvous::PilotForwardMsg::getBBMsg()
{
    return msg;
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle* rice::pastry::socket::nat::rendezvous::PilotForwardMsg::getTarget()
{
    return target;
}

java::lang::String* rice::pastry::socket::nat::rendezvous::PilotForwardMsg::toString()
{
    return ::java::lang::StringBuilder().append(u"PFM{"_j)->append(static_cast< ::java::lang::Object* >(msg))
        ->append(u"->"_j)
        ->append(static_cast< ::java::lang::Object* >(target))
        ->append(u"}"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::PilotForwardMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.PilotForwardMsg", 49);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::PilotForwardMsg::getClass0()
{
    return class_();
}

