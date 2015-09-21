// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_deliver_35.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierFetchMessage.hpp>
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
} // java

namespace rice
{
    namespace p2p
    {
        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;

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

rice::p2p::glacier::v2::GlacierImpl_deliver_35::GlacierImpl_deliver_35(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage* gfm)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , gfm(gfm)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_35::init()
{
    currentLookup = int32_t(0);
    fragment = new ::rice::p2p::glacier::FragmentArray(npc(gfm)->getNumKeys());
    manifest = new ManifestArray(npc(gfm)->getNumKeys());
    numFragments = int32_t(0);
    numManifests = int32_t(0);
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_35::returnResponse()
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Returning response with "_j)->append(numFragments)
            ->append(u" fragments, "_j)
            ->append(numManifests)
            ->append(u" manifests ("_j)
            ->append(npc(gfm)->getNumKeys())
            ->append(u" queries originally)"_j)->toString());

    GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierDataMessage(npc(gfm)->getUID(), npc(gfm)->getAllKeys(), fragment, manifest, GlacierImpl_this->getLocalNodeHandle(), npc(npc(gfm)->getSource())->getId(), true, npc(gfm)->getTag()), npc(gfm)->getSource());
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_35::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fragment "_j)->append(static_cast< ::java::lang::Object* >(npc(gfm)->getKey(currentLookup)))
                ->append(u" found ("_j)
                ->append(static_cast< ::java::lang::Object* >(o))
                ->append(u")"_j)->toString());

        auto fam = java_cast< FragmentAndManifest* >(o);
        fragment->set(currentLookup, ((npc(gfm)->getRequest() & ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_FRAGMENT) != 0) ? npc(fam)->fragment : static_cast< ::rice::p2p::glacier::Fragment* >(nullptr));
        if((*fragment)[currentLookup] != nullptr)
            numFragments++;

        manifest->set(currentLookup, ((npc(gfm)->getRequest() & ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_MANIFEST) != 0) ? npc(fam)->manifest : static_cast< Manifest* >(nullptr));
        if((*manifest)[currentLookup] != nullptr)
            numManifests++;

    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fragment "_j)->append(static_cast< ::java::lang::Object* >(npc(gfm)->getKey(currentLookup)))
                ->append(u" not found"_j)->toString());

        fragment->set(currentLookup, nullptr);
        manifest->set(currentLookup, nullptr);
    }
    nextLookup();
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_35::nextLookup()
{
    currentLookup++;
    if(currentLookup >= npc(gfm)->getNumKeys())
        returnResponse();
    else
        npc(GlacierImpl_this->fragmentStorage)->getObject(npc(gfm)->getKey(currentLookup), this);
}

void rice::p2p::glacier::v2::GlacierImpl_deliver_35::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Exception while retrieving fragment "_j)->append(static_cast< ::java::lang::Object* >(npc(gfm)->getKey(currentLookup)))
            ->append(u" (lookup #"_j)
            ->append(currentLookup)
            ->append(u"), e="_j)->toString(), e);

    fragment->set(currentLookup, nullptr);
    manifest->set(currentLookup, nullptr);
    nextLookup();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_35::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deliver_35::getClass0()
{
    return class_();
}

