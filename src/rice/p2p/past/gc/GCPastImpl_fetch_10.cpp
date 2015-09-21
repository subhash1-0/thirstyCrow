// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_fetch_10.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
#include <rice/persistence/Storage.hpp>
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

rice::p2p::past::gc::GCPastImpl_fetch_10::GCPastImpl_fetch_10(GCPastImpl *GCPastImpl_this, ::rice::p2p::commonapi::Id* id, GCId* gcid, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
    , id(id)
    , gcid(gcid)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_fetch_10::receiveResult(::java::lang::Object* o)
{
    if(o == nullptr) {
        if(npc(GCPastImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GCPastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Could not fetch id "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u" - policy returned null in namespace "_j)
                ->append(GCPastImpl_this->instance)->toString());

        npc(parent)->receiveResult(new ::java::lang::Boolean(false));
    } else {
        auto content = java_cast< GCPastContent* >(o);
        if(npc(GCPastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(GCPastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"inserting replica of id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

        npc(npc(GCPastImpl_this->storage)->getStorage())->store(npc(gcid)->getId(), npc(content)->getMetadata(npc(gcid)->getExpiration()), content, parent);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_fetch_10::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_fetch_10::getClass0()
{
    return class_();
}

