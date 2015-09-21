// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getContactDeserializer_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>

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

rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::RendezvousSocketPastryNodeFactory_getContactDeserializer_1(RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this, ::rice::pastry::PastryNode* pn)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousSocketPastryNodeFactory_this(RendezvousSocketPastryNodeFactory_this)
    , pn(pn)
{
    clinit();
    ctor();
}

java::util::Map* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::getOptions(RendezvousSocketNodeHandle* high)
{
    return ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(nullptr, ::org::mpisws::p2p::transport::identity::IdentityImpl::NODE_HANDLE_FROM_INDEX(), high);
}

java::util::Map* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::getOptions(::java::lang::Object* high)
{ 
    return getOptions(dynamic_cast< RendezvousSocketNodeHandle* >(high));
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* sib) /* throws(IOException) */
{
    return java_cast< RendezvousSocketNodeHandle* >(npc(pn)->readNodeHandle(sib));
}

java::net::InetSocketAddress* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::convert(RendezvousSocketNodeHandle* high)
{
    return npc(npc(high)->eaddress)->getAddress(0);
}

java::lang::Object* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::convert(::java::lang::Object* high)
{ 
    return convert(dynamic_cast< RendezvousSocketNodeHandle* >(high));
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::serialize(RendezvousSocketNodeHandle* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(i)->serialize(buf);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf)
{ 
    serialize(dynamic_cast< RendezvousSocketNodeHandle* >(i), buf);
}

java::nio::ByteBuffer* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::serialize(RendezvousSocketNodeHandle* i) /* throws(IOException) */
{
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    serialize(i, static_cast< ::rice::p2p::commonapi::rawserialization::OutputBuffer* >(sob));
    return npc(sob)->getByteBuffer();
}

java::nio::ByteBuffer* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::serialize(::java::lang::Object* i)
{ 
    return serialize(dynamic_cast< RendezvousSocketNodeHandle* >(i));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1::getClass0()
{
    return class_();
}

