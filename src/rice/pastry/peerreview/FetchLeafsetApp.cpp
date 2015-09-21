// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetApp.java
#include <rice/pastry/peerreview/FetchLeafsetApp.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeSet.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>
#include <rice/pastry/peerreview/FetchLeafsetApp_FetchLeafsetApp_1.hpp>
#include <rice/pastry/peerreview/FetchLeafsetApp_getNeighbors_2.hpp>
#include <rice/pastry/peerreview/FetchLeafsetRequest.hpp>
#include <rice/pastry/peerreview/FetchLeafsetResponse.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>

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

rice::pastry::peerreview::FetchLeafsetApp::FetchLeafsetApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::peerreview::FetchLeafsetApp::FetchLeafsetApp(::rice::pastry::PastryNode* pn, int32_t numNeighbors) 
    : FetchLeafsetApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,numNeighbors);
}

void rice::pastry::peerreview::FetchLeafsetApp::init()
{
    pendingLookups = new ::java::util::HashMap();
}

constexpr int32_t rice::pastry::peerreview::FetchLeafsetApp::APP_ID;

void rice::pastry::peerreview::FetchLeafsetApp::ctor(::rice::pastry::PastryNode* pn, int32_t numNeighbors)
{
    super::ctor(pn, nullptr, APP_ID, new FetchLeafsetApp_FetchLeafsetApp_1(this, pn));
    init();
    routeMsgVersion = static_cast< int8_t >(npc(npc(npc(thePastryNode)->getEnvironment())->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j));
    this->numNeighbors = numNeighbors;
}

void rice::pastry::peerreview::FetchLeafsetApp::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    auto m = java_cast< ::rice::pastry::messaging::PRawMessage* >(msg);
    {
        FetchLeafsetRequest* req;
        switch (npc(m)->getType()) {
        case FetchLeafsetRequest::TYPE:
            req = java_cast< FetchLeafsetRequest* >(m);
            npc(logger)->log(::java::lang::StringBuilder().append(u"getNeighbors("_j)->append(static_cast< ::java::lang::Object* >(npc(req)->subject))
                ->append(u") sending response"_j)->toString());
            npc(thePastryNode)->send(npc(req)->getSender(), new FetchLeafsetResponse(npc(req)->subject, npc(thePastryNode)->getLeafSet()), nullptr, nullptr);
            return;
        case FetchLeafsetResponse::TYPE:
            handleResponse(java_cast< FetchLeafsetResponse* >(m));
            return;
        }
    }

}

void rice::pastry::peerreview::FetchLeafsetApp::handleResponse(FetchLeafsetResponse* response)
{
    npc(logger)->log(::java::lang::StringBuilder().append(u"handleResponse("_j)->append(static_cast< ::java::lang::Object* >(npc(response)->subject))
        ->append(u")"_j)->toString());
    auto foo = java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(pendingLookups)->remove(npc(response)->subject));
    if(foo == nullptr)
        return;

    npc(java_cast< ::rice::selector::TimerTask* >(npc(foo)->a()))->cancel();
    auto ns = npc(npc(response)->leafSet)->replicaSet(npc(response)->subject, numNeighbors + int32_t(1));
    auto ret = npc(ns)->getCollection();
    for (auto _i = npc(java_cast< ::java::util::Collection* >(npc(foo)->b()))->iterator(); _i->hasNext(); ) {
        ::rice::Continuation* c = java_cast< ::rice::Continuation* >(_i->next());
        {
            npc(c)->receiveResult(ret);
        }
    }
}

void rice::pastry::peerreview::FetchLeafsetApp::getNeighbors(::rice::pastry::Id* subject, ::rice::Continuation* continuation)
{
    npc(logger)->log(::java::lang::StringBuilder().append(u"getNeighbors("_j)->append(static_cast< ::java::lang::Object* >(subject))
        ->append(u")"_j)->toString());
    auto foo = java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(pendingLookups)->get(subject));
    auto startTask = false;
    if(foo == nullptr) {
        startTask = true;
        foo = new ::rice::p2p::util::tuples::Tuple(new FetchLeafsetApp_getNeighbors_2(this, subject), new ::java::util::ArrayList());
        npc(pendingLookups)->put(subject, foo);
    }
    npc(java_cast< ::java::util::Collection* >(npc(foo)->b()))->add(continuation);
    if(startTask) {
        npc(npc(npc(thePastryNode)->getEnvironment())->getSelectorManager())->schedule(java_cast< ::rice::selector::TimerTask* >(npc(foo)->a()), static_cast< int64_t >(int32_t(0)), static_cast< int64_t >(int32_t(3000)));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::peerreview::FetchLeafsetApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.peerreview.FetchLeafsetApp", 38);
    return c;
}

java::lang::Class* rice::pastry::peerreview::FetchLeafsetApp::getClass0()
{
    return class_();
}

