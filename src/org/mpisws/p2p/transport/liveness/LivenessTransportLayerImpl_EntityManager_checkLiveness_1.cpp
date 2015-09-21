// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager_checkLiveness_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_DeadChecker.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <rice/selector/Timer.hpp>

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

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager_checkLiveness_1::LivenessTransportLayerImpl_EntityManager_checkLiveness_1(LivenessTransportLayerImpl_EntityManager *LivenessTransportLayerImpl_EntityManager_this, int32_t theRTO, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , LivenessTransportLayerImpl_EntityManager_this(LivenessTransportLayerImpl_EntityManager_this)
    , theRTO(theRTO)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager_checkLiveness_1::run()
{
    if(LivenessTransportLayerImpl_EntityManager_this->getPending() == nullptr)
        return;

    npc(LivenessTransportLayerImpl_EntityManager_this->LivenessTransportLayerImpl_this->timer)->schedule(LivenessTransportLayerImpl_EntityManager_this->getPending(), theRTO);
    auto temp = java_cast< ::java::lang::Object* >(npc(LivenessTransportLayerImpl_EntityManager_this->identifier)->get());
    if(temp != nullptr) {
        LivenessTransportLayerImpl_EntityManager_this->LivenessTransportLayerImpl_this->ping(temp, options);
    }
}

java::lang::String* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager_checkLiveness_1::toString()
{
    return LivenessTransportLayerImpl_EntityManager_this->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager_checkLiveness_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager_checkLiveness_1::getClass0()
{
    return class_();
}

