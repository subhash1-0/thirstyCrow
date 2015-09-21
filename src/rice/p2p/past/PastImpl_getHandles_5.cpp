// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_getHandles_5.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/past/PastException.hpp>
#include <rice/p2p/past/PastImpl.hpp>

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

rice::p2p::past::PastImpl_getHandles_5::PastImpl_getHandles_5(PastImpl *PastImpl_this, int32_t max, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , max(max)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_getHandles_5::receiveResult(::java::lang::Object* o)
{
    auto replicas = java_cast< ::rice::p2p::commonapi::NodeHandleSet* >(o);
    if(::java::lang::Math::min(max, npc(npc(PastImpl_this->endpoint)->replicaSet(npc(npc(PastImpl_this->endpoint)->getLocalNodeHandle())->getId(), PastImpl_this->replicationFactor + int32_t(1)))->size()) > npc(replicas)->size())
        npc(parent)->receiveException(new PastException(::java::lang::StringBuilder().append(u"Only received "_j)->append(npc(replicas)->size())
            ->append(u" replicas - cannot insert as we know about more nodes."_j)->toString()));
    else
        npc(parent)->receiveResult(replicas);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_getHandles_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_getHandles_5::getClass0()
{
    return class_();
}

