// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_lookupHandles_26.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/v2/GlacierContentHandle.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io
} // java

namespace rice
{
    namespace p2p
    {
        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastContentHandle, ::java::lang::ObjectArray, ::java::io::SerializableArray > PastContentHandleArray;
        } // past
    } // p2p
} // rice

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

rice::p2p::glacier::v2::GlacierImpl_lookupHandles_26::GlacierImpl_lookupHandles_26(GlacierImpl *GlacierImpl_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* command, int64_t version)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , id(id)
    , command(command)
    , version(version)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_lookupHandles_26::init()
{
    haveAnswered = false;
}

void rice::p2p::glacier::v2::GlacierImpl_lookupHandles_26::receiveResult(::java::lang::Object* o)
{
    if(haveAnswered) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"lookupHandles("_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u"): received manifest "_j)
                ->append(static_cast< ::java::lang::Object* >(o))
                ->append(u" but has already answered. Discarding..."_j)->toString());

        return;
    }
    if(dynamic_cast< Manifest* >(o) != nullptr) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"lookupHandles("_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u"): received manifest "_j)
                ->append(static_cast< ::java::lang::Object* >(o))
                ->append(u", returning handle..."_j)->toString());

        haveAnswered = true;
        npc(command)->receiveResult(new ::rice::p2p::past::PastContentHandleArray({static_cast< ::rice::p2p::past::PastContentHandle* >(new GlacierContentHandle(id, version, GlacierImpl_this->getLocalNodeHandle(), java_cast< Manifest* >(o)))}));
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"lookupHandles("_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u"): Cannot retrieve manifest"_j)->toString());

        haveAnswered = true;
        npc(command)->receiveResult(new ::rice::p2p::past::PastContentHandleArray({static_cast< ::rice::p2p::past::PastContentHandle* >(nullptr)}));
    }
}

void rice::p2p::glacier::v2::GlacierImpl_lookupHandles_26::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"lookupHandles("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u"): Exception "_j)->toString(), e);

    haveAnswered = true;
    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_lookupHandles_26::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_lookupHandles_26::getClass0()
{
    return class_();
}

