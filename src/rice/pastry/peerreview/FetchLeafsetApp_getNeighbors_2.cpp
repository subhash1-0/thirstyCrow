// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetApp.java
#include <rice/pastry/peerreview/FetchLeafsetApp_getNeighbors_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/peerreview/FetchLeafsetApp.hpp>
#include <rice/pastry/peerreview/FetchLeafsetRequest.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/Router.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::peerreview::FetchLeafsetApp_getNeighbors_2::FetchLeafsetApp_getNeighbors_2(FetchLeafsetApp *FetchLeafsetApp_this, ::rice::pastry::Id* subject)
    : super(*static_cast< ::default_init_tag* >(0))
    , FetchLeafsetApp_this(FetchLeafsetApp_this)
    , subject(subject)
{
    clinit();
    ctor();
}

void rice::pastry::peerreview::FetchLeafsetApp_getNeighbors_2::run()
{
    npc(FetchLeafsetApp_this->logger)->log(::java::lang::StringBuilder().append(u"getNeighbors("_j)->append(static_cast< ::java::lang::Object* >(subject))
        ->append(u") sending fetch"_j)->toString());
    npc(npc(FetchLeafsetApp_this->thePastryNode)->getRouter())->route(new ::rice::pastry::routing::RouteMessage(subject, new FetchLeafsetRequest(npc(FetchLeafsetApp_this->thePastryNode)->getLocalHandle(), subject), FetchLeafsetApp_this->routeMsgVersion));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::peerreview::FetchLeafsetApp_getNeighbors_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::peerreview::FetchLeafsetApp_getNeighbors_2::getClass0()
{
    return class_();
}

