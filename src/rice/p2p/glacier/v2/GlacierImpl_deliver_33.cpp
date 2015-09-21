// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_33.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierSyncMessage.hpp>
#include <rice/persistence/StorageManager.hpp>
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

        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;

            namespace v2
            {
typedef ::SubArray< ::rice::p2p::glacier::v2::Manifest, ::java::lang::ObjectArray, ::java::io::SerializableArray > ManifestArray;
            } // v2
        } // glacier
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

rice::p2p::glacier::v2::GlacierImpl_deliver_33::GlacierImpl_deliver_33(GlacierImpl *GlacierImpl_this, ::java::util::Vector* missing, ::rice::p2p::glacier::v2::messaging::GlacierSyncMessage* gsm, int32_t offset)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , missing(missing)
    , gsm(gsm)
    , offset(offset)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_33::init()
{
    currentLookup = int32_t(0);
    manifestIndex = int32_t(0);
    numLookups = npc(missing)->size();
    manifests = new ManifestArray(::java::lang::Math::min(numLookups, GlacierImpl_this->manifestAggregationFactor));
    fragments = new ::rice::p2p::glacier::FragmentArray(::java::lang::Math::min(numLookups, GlacierImpl_this->manifestAggregationFactor));
    keys = new ::rice::p2p::glacier::FragmentKeyArray(::java::lang::Math::min(numLookups, GlacierImpl_this->manifestAggregationFactor));
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_33::receiveResult(::java::lang::Object* o)
{
    auto const thisKey = java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(missing)->elementAt(currentLookup)));
    if(o == nullptr) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"SYN2: Fragment "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                ->append(u" not found -- canceled SYN"_j)->toString());

        return;
    }
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Retrieved manifest "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
            ->append(u" (dest="_j)
            ->append(static_cast< ::java::lang::Object* >(npc(npc(gsm)->getSource())->getId()))
            ->append(u", offset="_j)
            ->append(offset)
            ->append(u")"_j)->toString());

    auto fam = java_cast< FragmentAndManifest* >(o);
    if(!npc(GlacierImpl_this->policy)->checkSignature(npc(fam)->manifest, npc(thisKey)->getVersionKey()))
        GlacierImpl_this->panic(u"Signature mismatch!!"_j);

    fragments->set(manifestIndex, nullptr);
    manifests->set(manifestIndex, npc(fam)->manifest);
    auto hisFID = npc(thisKey)->getFragmentID() - offset;
    if(hisFID < 0)
        hisFID += GlacierImpl_this->numFragments;

    if(hisFID >= GlacierImpl_this->numFragments)
        GlacierImpl_this->panic(u"Assertion failed: L938"_j);

    keys->set(manifestIndex, new ::rice::p2p::glacier::FragmentKey(npc(thisKey)->getVersionKey(), hisFID));
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"He should have key "_j)->append(static_cast< ::java::lang::Object* >((*keys)[manifestIndex]))
            ->append(u" @"_j)
            ->append(static_cast< ::java::lang::Object* >(GlacierImpl_this->getFragmentLocation((*keys)[manifestIndex])))->toString());

    manifestIndex++;
    currentLookup++;
    if((manifestIndex == GlacierImpl_this->manifestAggregationFactor) || (currentLookup == numLookups)) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Sending a packet with "_j)->append(npc(keys)->length)
                ->append(u" manifests to "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(npc(gsm)->getSource())->getId()))->toString());

        GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierDataMessage(GlacierImpl_this->getUID(), keys, fragments, manifests, GlacierImpl_this->getLocalNodeHandle(), npc(npc(gsm)->getSource())->getId(), false, GlacierImpl_this->tagSyncManifests), npc(gsm)->getSource());
        manifestIndex = 0;
        manifests = new ManifestArray(::java::lang::Math::min(numLookups - currentLookup, GlacierImpl_this->manifestAggregationFactor));
        keys = new ::rice::p2p::glacier::FragmentKeyArray(::java::lang::Math::min(numLookups - currentLookup, GlacierImpl_this->manifestAggregationFactor));
        fragments = new ::rice::p2p::glacier::FragmentArray(::java::lang::Math::min(numLookups - currentLookup, GlacierImpl_this->manifestAggregationFactor));
    }
    if(currentLookup < numLookups)
        npc(GlacierImpl_this->fragmentStorage)->getObject(java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(missing)->elementAt(currentLookup))), this);

}

void rice::p2p::glacier::v2::GlacierImpl_deliver_33::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"SYN2: Exception while retrieving fragment "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(missing)->elementAt(currentLookup))))
            ->append(u", e="_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u" -- canceled SYN"_j)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_33::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_33::getClass0()
{
    return class_();
}

