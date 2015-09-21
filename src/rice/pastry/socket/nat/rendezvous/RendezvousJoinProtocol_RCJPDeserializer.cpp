// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol_RCJPDeserializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinRequest.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_RCJPDeserializer::RendezvousJoinProtocol_RCJPDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_RCJPDeserializer::RendezvousJoinProtocol_RCJPDeserializer(::rice::pastry::PastryNode* pn) 
    : RendezvousJoinProtocol_RCJPDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_RCJPDeserializer::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

rice::pastry::messaging::Message* rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_RCJPDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case RendezvousJoinRequest::TYPE:
        return new RendezvousJoinRequest(buf, static_cast< ::rice::pastry::NodeHandleFactory* >(pn), java_cast< ::rice::pastry::NodeHandle* >(sender), pn);
    }

    return super::deserialize(buf, type, priority, sender);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_RCJPDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousJoinProtocol.RCJPDeserializer", 73);
    return c;
}

rice::p2p::commonapi::Message* rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_RCJPDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender)
{
    return super::deserialize(buf, type, priority, sender);
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_RCJPDeserializer::getClass0()
{
    return class_();
}

