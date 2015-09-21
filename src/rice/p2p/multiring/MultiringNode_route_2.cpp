// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNode.java
#include <rice/p2p/multiring/MultiringNode_route_2.hpp>

#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/multiring/MultiringNode.hpp>
#include <rice/p2p/multiring/RingId.hpp>

rice::p2p::multiring::MultiringNode_route_2::MultiringNode_route_2(MultiringNode *MultiringNode_this, ::rice::p2p::commonapi::rawserialization::RawMessage* message, RingId* id)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiringNode_this(MultiringNode_this)
    , message(message)
    , id(id)
{
    clinit();
    ctor();
}

bool rice::p2p::multiring::MultiringNode_route_2::cancel()
{
    return false;
}

rice::p2p::commonapi::Message* rice::p2p::multiring::MultiringNode_route_2::getMessage()
{
    return message;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringNode_route_2::getId()
{
    return id;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringNode_route_2::getHint()
{
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringNode_route_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringNode_route_2::getClass0()
{
    return class_();
}

