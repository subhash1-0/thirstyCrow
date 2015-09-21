// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_deliver_12.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/CacheMessage.hpp>
#include <rice/p2p/past/messaging/LookupMessage.hpp>

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

rice::p2p::past::PastImpl_deliver_12::PastImpl_deliver_12(PastImpl *PastImpl_this, ::rice::p2p::past::messaging::LookupMessage* lmsg, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , lmsg(lmsg)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_deliver_12::receiveResult(::java::lang::Object* o)
{
    if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Received object "_j)->append(static_cast< ::java::lang::Object* >(o))
            ->append(u" for id "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(lmsg)->getId()))->toString());

    npc(parent)->receiveResult(o);
    if((npc(lmsg)->getPreviousNodeHandle() != nullptr) && (o != nullptr) && (!npc((java_cast< PastContent* >(o)))->isMutable())) {
        auto handle = npc(lmsg)->getPreviousNodeHandle();
        if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Pushing cached copy of "_j)->append(static_cast< ::java::lang::Object* >(npc((java_cast< PastContent* >(o)))->getId()))
                ->append(u" to "_j)
                ->append(static_cast< ::java::lang::Object* >(handle))->toString());

        auto cmsg = new ::rice::p2p::past::messaging::CacheMessage(PastImpl_this->getUID(), java_cast< PastContent* >(o), PastImpl_this->getLocalNodeHandle(), npc(handle)->getId());
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_deliver_12::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_deliver_12::getClass0()
{
    return class_();
}

