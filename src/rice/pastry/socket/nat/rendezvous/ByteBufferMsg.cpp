// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/ByteBufferMsg.java
#include <rice/pastry/socket/nat/rendezvous/ByteBufferMsg.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::ByteBufferMsg::ByteBufferMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::ByteBufferMsg::ByteBufferMsg(::java::nio::ByteBuffer* buf, ::rice::p2p::commonapi::NodeHandle* sender, int32_t priority, int32_t dest) 
    : ByteBufferMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,sender,priority,dest);
}

constexpr int16_t rice::pastry::socket::nat::rendezvous::ByteBufferMsg::TYPE;

void rice::pastry::socket::nat::rendezvous::ByteBufferMsg::ctor(::java::nio::ByteBuffer* buf, ::rice::p2p::commonapi::NodeHandle* sender, int32_t priority, int32_t dest)
{
    super::ctor(dest);
    this->buffer = buf;
    setPriority(priority);
    if(sender == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"Sender == null"_j);

    originalSender = sender;
}

java::lang::String* rice::pastry::socket::nat::rendezvous::ByteBufferMsg::toString()
{
    return ::java::lang::StringBuilder().append(u"BBM["_j)->append(static_cast< ::java::lang::Object* >(buffer))
        ->append(u"] from "_j)
        ->append(static_cast< ::java::lang::Object* >(originalSender))->toString();
}

int16_t rice::pastry::socket::nat::rendezvous::ByteBufferMsg::getType()
{
    return TYPE;
}

void rice::pastry::socket::nat::rendezvous::ByteBufferMsg::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(originalSender)->serialize(buf);
    npc(buf)->writeInt(npc(buffer)->remaining());
    npc(buf)->write(npc(buffer)->array(), npc(buffer)->position(), npc(buffer)->remaining());
}

rice::p2p::commonapi::NodeHandle* rice::pastry::socket::nat::rendezvous::ByteBufferMsg::getOriginalSender()
{
    return originalSender;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::ByteBufferMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.ByteBufferMsg", 47);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::ByteBufferMsg::getClass0()
{
    return class_();
}

