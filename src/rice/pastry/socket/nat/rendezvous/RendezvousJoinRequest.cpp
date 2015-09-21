// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousJoinRequest.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinRequest.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>

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

rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::RendezvousJoinRequest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::RendezvousJoinRequest(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength, int64_t timestamp, ::rice::pastry::NodeHandle* pilot) 
    : RendezvousJoinRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(nh,rtBaseBitLength,timestamp,pilot);
}

rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::RendezvousJoinRequest(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender, ::rice::pastry::PastryNode* localNode)  /* throws(IOException) */
    : RendezvousJoinRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,nhf,sender,localNode);
}

constexpr int16_t rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::TYPE;

void rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::ctor(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength, int64_t timestamp, ::rice::pastry::NodeHandle* pilot)
{
    super::ctor(nh, rtBaseBitLength, timestamp);
    this->pilot = pilot;
}

java::lang::String* rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::toString()
{
    return ::java::lang::StringBuilder().append(u"RendezvousJoinRequest("_j)->append(static_cast< ::java::lang::Object* >((handle != nullptr ? npc(handle)->getNodeId() : static_cast< ::rice::pastry::Id* >(nullptr))))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >((joinHandle != nullptr ? npc(joinHandle)->getNodeId() : static_cast< ::rice::pastry::Id* >(nullptr))))
        ->append(u","_j)
        ->append(timestamp)
        ->append(u" pilot:"_j)
        ->append(static_cast< ::java::lang::Object* >(pilot))
        ->append(u")"_j)->toString();
}

int16_t rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::getType()
{
    return TYPE;
}

void rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    super::serialize(buf);
    npc(pilot)->serialize(buf);
}

void rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender, ::rice::pastry::PastryNode* localNode) /* throws(IOException) */
{
    super::ctor(buf, nhf, sender, localNode);
    pilot = java_cast< ::rice::pastry::NodeHandle* >(npc(nhf)->readNodeHandle(buf));
}

rice::pastry::NodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::getPilot()
{
    return pilot;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousJoinRequest", 55);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest::getClass0()
{
    return class_();
}

