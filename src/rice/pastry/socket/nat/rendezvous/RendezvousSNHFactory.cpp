// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSNHFactory.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSNHFactory.hpp>

#include <java/lang/ClassCastException.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousSNHFactory::RendezvousSNHFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousSNHFactory::RendezvousSNHFactory(::rice::pastry::PastryNode* pn) 
    : RendezvousSNHFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSNHFactory::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousSNHFactory::getNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* id)
{
    return getNodeHandle(i, epoch, id, static_cast< int8_t >(int32_t(0)));
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousSNHFactory::getNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* id, int8_t contactState)
{
    ::rice::pastry::socket::SocketNodeHandle* handle = new RendezvousSocketNodeHandle(i, epoch, id, pn, contactState);
    return java_cast< ::rice::pastry::socket::SocketNodeHandle* >(coalesce(handle));
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousSNHFactory::readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return coalesce(RendezvousSocketNodeHandle::RendezvousSocketNodeHandle_build(buf, pn));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSNHFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousSNHFactory", 54);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSNHFactory::getClass0()
{
    return class_();
}

