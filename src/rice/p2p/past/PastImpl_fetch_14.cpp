// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_fetch_14.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
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

rice::p2p::past::PastImpl_fetch_14::PastImpl_fetch_14(PastImpl *PastImpl_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , id(id)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_fetch_14::receiveResult(::java::lang::Object* o)
{
    if(o == nullptr) {
        if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Could not fetch id "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u" - policy returned null in namespace "_j)
                ->append(PastImpl_this->instance)->toString());

        npc(parent)->receiveResult(new ::java::lang::Boolean(false));
    } else {
        if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"inserting replica of id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

        if(!(dynamic_cast< PastContent* >(o) != nullptr))
            if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"ERROR! Not PastContent "_j)->append(npc(npc(o)->getClass())->getName())
                    ->append(u" "_j)
                    ->append(static_cast< ::java::lang::Object* >(o))->toString());


        npc(npc(PastImpl_this->storage)->getStorage())->store(npc((java_cast< PastContent* >(o)))->getId(), nullptr, java_cast< PastContent* >(o), parent);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_fetch_14::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_fetch_14::getClass0()
{
    return class_();
}

