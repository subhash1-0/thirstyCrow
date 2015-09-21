// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_deliver_7.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/gc/GCPastContentHandle.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
#include <rice/p2p/past/messaging/FetchHandleMessage.hpp>
#include <rice/persistence/StorageManager.hpp>

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

rice::p2p::past::gc::GCPastImpl_deliver_7::GCPastImpl_deliver_7(GCPastImpl *GCPastImpl_this, ::rice::p2p::past::messaging::FetchHandleMessage* fmsg, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
    , fmsg(fmsg)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_deliver_7::receiveResult(::java::lang::Object* o)
{
    auto content = java_cast< GCPastContent* >(o);
    if(content != nullptr) {
        if(npc(GCPastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GCPastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Retrieved data for fetch handles of id "_j)->append(static_cast< ::java::lang::Object* >(npc(fmsg)->getId()))->toString());

        auto metadata = java_cast< GCPastMetadata* >(npc(GCPastImpl_this->storage)->getMetadata(npc(fmsg)->getId()));
        if(metadata != nullptr)
            npc(parent)->receiveResult(npc(content)->getHandle(GCPastImpl_this, npc(metadata)->getExpiration()));
        else
            npc(parent)->receiveResult(npc(content)->getHandle(GCPastImpl_this, GCPastImpl::DEFAULT_EXPIRATION));
    } else {
        npc(parent)->receiveResult(nullptr);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_7::getClass0()
{
    return class_();
}

