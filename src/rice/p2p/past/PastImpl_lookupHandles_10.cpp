// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_lookupHandles_10.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation_MultiContinuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/past/PastImpl_lookupHandles_10_receiveResult_10_1.hpp>
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

rice::p2p::past::PastImpl_lookupHandles_10::PastImpl_lookupHandles_10(PastImpl *PastImpl_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , id(id)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_lookupHandles_10::receiveResult(::java::lang::Object* o)
{
    auto replicas = java_cast< ::rice::p2p::commonapi::NodeHandleSet* >(o);
    if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Receiving replicas "_j)->append(static_cast< ::java::lang::Object* >(replicas))
            ->append(u" for lookup Id "_j)
            ->append(static_cast< ::java::lang::Object* >(id))->toString());

    ::rice::Continuation_MultiContinuation* multi = new PastImpl_lookupHandles_10_receiveResult_10_1(this, parent, npc(replicas)->size());
    for (auto i = int32_t(0); i < npc(replicas)->size(); i++) 
                PastImpl_this->lookupHandle(id, npc(replicas)->getHandle(i), npc(multi)->getSubContinuation(i));

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_lookupHandles_10::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_lookupHandles_10::getClass0()
{
    return class_();
}

