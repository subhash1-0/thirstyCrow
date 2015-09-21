// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/Id.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::RendezvousSocketNodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::RendezvousSocketNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* eisa, int64_t epoch, ::rice::pastry::Id* id, ::rice::pastry::PastryNode* node, int8_t contactStatus) 
    : RendezvousSocketNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(eisa,epoch,id,node,contactStatus);
}

constexpr int8_t rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::CONTACT_DIRECT;

constexpr int8_t rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::CONTACT_FIREWALLED;

void rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* eisa, int64_t epoch, ::rice::pastry::Id* id, ::rice::pastry::PastryNode* node, int8_t contactStatus)
{
    super::ctor(eisa, epoch, id, node);
    this->contactStatus = contactStatus;
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    super::serialize(buf);
    npc(buf)->writeByte(contactStatus);
}

bool rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::canContactDirect()
{
    return contactStatus != CONTACT_FIREWALLED;
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::RendezvousSocketNodeHandle_build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::PastryNode* local) /* throws(IOException) */
{
    clinit();
    auto eaddr = ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::build(buf);
    auto epoch = npc(buf)->readLong();
    auto nid = ::rice::pastry::Id::build(buf);
    auto contactStatus = npc(buf)->readByte();
    return new RendezvousSocketNodeHandle(eaddr, epoch, nid, local, contactStatus);
}

int8_t rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::getContactStatus()
{
    return contactStatus;
}

java::lang::String* rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::toString()
{
    auto s = ::java::lang::StringBuilder().append(u"[RSNH: "_j)->append(static_cast< ::java::lang::Object* >(nodeId))
        ->append(u"/"_j)
        ->append(static_cast< ::java::lang::Object* >(eaddress))->toString();
    if(!canContactDirect())
        s = ::java::lang::StringBuilder(s).append(u"(FIREWALLED)"_j)->toString();

    s = ::java::lang::StringBuilder(s).append(u"]"_j)->toString();
    return s;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousSocketNodeHandle", 60);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle::getClass0()
{
    return class_();
}

