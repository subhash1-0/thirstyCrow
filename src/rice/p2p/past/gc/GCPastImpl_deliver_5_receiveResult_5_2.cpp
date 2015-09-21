// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_deliver_5_receiveResult_5_2.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_5.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
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

rice::p2p::past::gc::GCPastImpl_deliver_5_receiveResult_5_2::GCPastImpl_deliver_5_receiveResult_5_2(GCPastImpl_deliver_5 *GCPastImpl_deliver_5_this, GCId* id, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_deliver_5_this(GCPastImpl_deliver_5_this)
    , id(id)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_deliver_5_receiveResult_5_2::receiveResult(::java::lang::Object* o)
{
    if((o != nullptr) && (dynamic_cast< GCPastContent* >(o) != nullptr)) {
        if(npc(GCPastImpl_deliver_5_this->GCPastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GCPastImpl_deliver_5_this->GCPastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"GCREFRESH: Restoring object "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u" from trash!"_j)->toString());

        auto content = java_cast< GCPastContent* >(o);
        npc(GCPastImpl_deliver_5_this->GCPastImpl_this->storage)->store(npc(id)->getId(), npc(content)->getMetadata(npc(id)->getExpiration()), content, new GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1(this, id, parent));
    } else {
        npc(parent)->receiveResult(::java::lang::Boolean::FALSE());
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_5_receiveResult_5_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_5_receiveResult_5_2::getClass0()
{
    return class_();
}

