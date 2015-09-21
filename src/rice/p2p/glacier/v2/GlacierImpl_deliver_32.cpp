// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_32.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierNeighborRequestMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierNeighborResponseMessage.hpp>
#include <rice/persistence/StorageManager.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
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

rice::p2p::glacier::v2::GlacierImpl_deliver_32::GlacierImpl_deliver_32(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage* gnrm, ::rice::p2p::commonapi::IdArray* neighbors, ::int64_tArray* lastSeen, int32_t numRequested)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , gnrm(gnrm)
    , neighbors(neighbors)
    , lastSeen(lastSeen)
    , numRequested(numRequested)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_32::init()
{
    currentLookup = int32_t(0);
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_32::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Continue: NeighborRequest from "_j)->append(static_cast< ::java::lang::Object* >(npc(npc(gnrm)->getSource())->getId()))
            ->append(u" for range "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(gnrm)->getRequestedRange()))->toString());

    if(o == nullptr) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(u"Problem while retrieving neighbors -- canceled"_j);

        return;
    }
    if(dynamic_cast< ::java::lang::Long* >(o) != nullptr) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Retr: Neighbor "_j)->append(static_cast< ::java::lang::Object* >((*neighbors)[currentLookup]))
                ->append(u" was last seen at "_j)
                ->append(static_cast< ::java::lang::Object* >(o))->toString());

        (*lastSeen)[currentLookup] = npc((java_cast< ::java::lang::Long* >(o)))->longValue();
        currentLookup++;
        if(currentLookup < numRequested) {
            npc(GlacierImpl_this->neighborStorage)->getObject((*neighbors)[currentLookup], this);
        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(u"Sending neighbor response..."_j);

            GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage(npc(gnrm)->getUID(), neighbors, lastSeen, GlacierImpl_this->getLocalNodeHandle(), npc(npc(gnrm)->getSource())->getId(), npc(gnrm)->getTag()), npc(gnrm)->getSource());
        }
    }
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_32::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Problem while retrieving neighbors in range "_j)->append(static_cast< ::java::lang::Object* >(npc(gnrm)->getRequestedRange()))
            ->append(u" for "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(gnrm)->getSource()))
            ->append(u" -- canceled"_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_32::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_32::getClass0()
{
    return class_();
}

