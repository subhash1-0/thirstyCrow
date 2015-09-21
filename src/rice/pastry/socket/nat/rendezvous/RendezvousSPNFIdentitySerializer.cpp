// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSPNFIdentitySerializer.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSPNFIdentitySerializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

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

rice::pastry::socket::nat::rendezvous::RendezvousSPNFIdentitySerializer::RendezvousSPNFIdentitySerializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousSPNFIdentitySerializer::RendezvousSPNFIdentitySerializer(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketNodeHandleFactory* factory) 
    : RendezvousSPNFIdentitySerializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,factory);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSPNFIdentitySerializer::ctor(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketNodeHandleFactory* factory)
{
    super::ctor(pn, factory);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSPNFIdentitySerializer::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, ::rice::pastry::socket::TransportLayerNodeHandle* i) /* throws(IOException) */
{
    super::serialize(buf, i);
    npc(buf)->writeByte(npc((java_cast< RendezvousSocketNodeHandle* >(i)))->getContactStatus());
}

void rice::pastry::socket::nat::rendezvous::RendezvousSPNFIdentitySerializer::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, ::java::lang::Object* i)
{ 
    serialize(buf, dynamic_cast< ::rice::pastry::socket::TransportLayerNodeHandle* >(i));
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousSPNFIdentitySerializer::buildSNH(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* nid) /* throws(IOException) */
{
    return new RendezvousSocketNodeHandle(i, epoch, nid, pn, npc(buf)->readByte());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSPNFIdentitySerializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousSPNFIdentitySerializer", 66);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSPNFIdentitySerializer::getClass0()
{
    return class_();
}

