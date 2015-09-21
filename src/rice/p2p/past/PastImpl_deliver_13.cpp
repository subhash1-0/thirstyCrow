// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_deliver_13.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/FetchHandleMessage.hpp>

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

rice::p2p::past::PastImpl_deliver_13::PastImpl_deliver_13(PastImpl *PastImpl_this, ::rice::p2p::past::messaging::FetchHandleMessage* fmsg, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , fmsg(fmsg)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_deliver_13::receiveResult(::java::lang::Object* o)
{
    auto content = java_cast< PastContent* >(o);
    if(content != nullptr) {
        if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Retrieved data for fetch handles of id "_j)->append(static_cast< ::java::lang::Object* >(npc(fmsg)->getId()))->toString());

        npc(parent)->receiveResult(npc(content)->getHandle(PastImpl_this));
    } else {
        npc(parent)->receiveResult(nullptr);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_deliver_13::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_deliver_13::getClass0()
{
    return class_();
}

