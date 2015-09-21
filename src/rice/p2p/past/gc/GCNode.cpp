// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCNode.java
#include <rice/p2p/past/gc/GCNode.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/gc/GCEndpoint.hpp>
#include <rice/p2p/past/gc/GCIdFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCNode::GCNode(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::GCNode::GCNode(::rice::p2p::commonapi::Node* node) 
    : GCNode(*static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::p2p::past::gc::GCNode::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->node = node;
}

rice::p2p::commonapi::Endpoint* rice::p2p::past::gc::GCNode::registerApplication(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance)
{
    auto gce = new GCEndpoint(npc(node)->buildEndpoint(application, instance));
    npc(gce)->register_();
    return gce;
}

rice::p2p::commonapi::Endpoint* rice::p2p::past::gc::GCNode::buildEndpoint(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance)
{
    return new GCEndpoint(npc(node)->buildEndpoint(application, instance));
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::gc::GCNode::getLocalNodeHandle()
{
    return npc(node)->getLocalNodeHandle();
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCNode::getId()
{
    return npc(node)->getId();
}

rice::p2p::commonapi::IdFactory* rice::p2p::past::gc::GCNode::getIdFactory()
{
    return new GCIdFactory(npc(node)->getIdFactory());
}

java::lang::String* rice::p2p::past::gc::GCNode::toString()
{
    return ::java::lang::StringBuilder().append(u"{GCNode "_j)->append(static_cast< ::java::lang::Object* >(node))
        ->append(u"}"_j)->toString();
}

rice::environment::Environment* rice::p2p::past::gc::GCNode::getEnvironment()
{
    return npc(node)->getEnvironment();
}

java::lang::String* rice::p2p::past::gc::GCNode::printRouteState()
{
    return npc(node)->printRouteState();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCNode::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCNode", 23);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCNode::getClass0()
{
    return class_();
}

