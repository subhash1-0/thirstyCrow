// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveObject_28.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/GlacierNotEnoughFragmentsException.hpp>
#include <rice/p2p/glacier/v2/GlacierPolicy.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierFetchMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>
#include <rice/p2p/past/PastContent.hpp>
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
} // java

namespace rice
{
    namespace p2p
    {
        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;
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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::GlacierImpl_retrieveObject_28(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::VersionKey* key, Manifest* manifest, ::rice::Continuation* c, char16_t tag, bool beStrict)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , key(key)
    , manifest(manifest)
    , c(c)
    , tag(tag)
    , beStrict(beStrict)
{
    clinit();
    ctor();
}

int32_t rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::numHaveFragments()
{
    auto result = int32_t(0);
    for (auto i = int32_t(0); i < npc(haveFragment)->length; i++) 
                if((*haveFragment)[i] != nullptr)
            result++;


    return result;
}

int32_t rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::numCheckedFragments()
{
    auto result = int32_t(0);
    for (auto i = int32_t(0); i < npc(checkedFragment)->length; i++) 
                if((*checkedFragment)[i])
            result++;


    return result;
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::toString()
{
    return ::java::lang::StringBuilder().append(u"retrieveObject("_j)->append(static_cast< ::java::lang::Object* >(key))
        ->append(u")"_j)->toString();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::init_()
{
    {
        synchronized synchronized_0(GlacierImpl_this->numActiveRestores);
        {
            (*GlacierImpl_this->numActiveRestores)[int32_t(0)]++;
        }
    }
    checkedFragment = new ::boolArray(GlacierImpl_this->numFragments);
    haveFragment = new ::rice::p2p::glacier::FragmentArray(GlacierImpl_this->numFragments);
    for (auto i = int32_t(0); i < GlacierImpl_this->numFragments; i++) {
        (*checkedFragment)[i] = false;
        haveFragment->set(i, nullptr);
    }
    timeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis();
    attemptsLeft = GlacierImpl_this->restoreMaxBoosts;
    timeoutExpired();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::localTerminate()
{
    {
        synchronized synchronized_1(GlacierImpl_this->numActiveRestores);
        {
            (*GlacierImpl_this->numActiveRestores)[int32_t(0)]--;
        }
    }
    terminate();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o) != nullptr) {
        auto gdm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o);
        auto fragmentID = npc(npc(gdm)->getKey(0))->getFragmentID();
        if(!npc(npc(npc(gdm)->getKey(0))->getVersionKey())->equals(static_cast< ::java::lang::Object* >(key)) || (fragmentID < 0) || (fragmentID >= GlacierImpl_this->numFragments)) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObject: Bad data message (contains "_j)->append(static_cast< ::java::lang::Object* >(npc(gdm)->getKey(0)))
                    ->append(u", expected "_j)
                    ->append(static_cast< ::java::lang::Object* >(key))->toString());

            return;
        }
        auto thisFragment = npc(gdm)->getFragment(0);
        if(thisFragment == nullptr) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fragment "_j)->append(static_cast< ::java::lang::Object* >(npc((java_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o)))->getKey(0)))
                    ->append(u" not available (GDM returned null), sending another request"_j)->toString());

            if(numCheckedFragments() < GlacierImpl_this->numFragments)
                sendRandomRequest();

            return;
        }
        if(!(*checkedFragment)[fragmentID]) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObject: Got fragment #"_j)->append(fragmentID)
                    ->append(u", but we never requested it -- ignored"_j)->toString());

            return;
        }
        if((*haveFragment)[fragmentID] != nullptr) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObject: Got duplicate fragment #"_j)->append(fragmentID)
                    ->append(u" -- discarded"_j)->toString());

            return;
        }
        if((manifest != nullptr) && !npc(manifest)->validatesFragment(thisFragment, fragmentID, npc(npc(GlacierImpl_this->environment)->getLogManager())->getLogger(Manifest::class_(), GlacierImpl_this->instance))) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Got invalid fragment #"_j)->append(fragmentID)
                    ->append(u" -- discarded"_j)->toString());

            return;
        }
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObject: Received fragment #"_j)->append(fragmentID)
                ->append(u" for "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(gdm)->getKey(0)))->toString());

        haveFragment->set(fragmentID, thisFragment);
        GlacierImpl_this->currentFragmentRequestTimeout -= GlacierImpl_this->fragmentRequestTimeoutDecrement;
        if(GlacierImpl_this->currentFragmentRequestTimeout < GlacierImpl_this->fragmentRequestTimeoutMin)
            GlacierImpl_this->currentFragmentRequestTimeout = GlacierImpl_this->fragmentRequestTimeoutMin;

        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Timeout decreased to "_j)->append(GlacierImpl_this->currentFragmentRequestTimeout)->toString());

        if(numHaveFragments() >= GlacierImpl_this->numSurvivors) {
            auto material = new ::rice::p2p::glacier::FragmentArray(GlacierImpl_this->numFragments);
            auto numAdded = int32_t(0);
            for (auto j = int32_t(0); j < GlacierImpl_this->numFragments; j++) {
                if(((*haveFragment)[j] != nullptr) && (numAdded < GlacierImpl_this->numSurvivors)) {
                    material->set(j, (*haveFragment)[j]);
                    numAdded++;
                } else {
                    material->set(j, nullptr);
                }
            }
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Decode object: "_j)->append(static_cast< ::java::lang::Object* >(key))->toString());

            auto theObject = npc(GlacierImpl_this->policy)->decodeObject(material, GlacierImpl_this->endpoint, GlacierImpl_this->contentDeserializer);
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Decode complete: "_j)->append(static_cast< ::java::lang::Object* >(key))->toString());

            if(theObject == nullptr) {
                if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObject: Decoder delivered "_j)->append(static_cast< ::java::lang::Object* >(theObject))
                        ->append(u", unexpected -- failed"_j)->toString());

                npc(c)->receiveException(new ::rice::p2p::glacier::GlacierException(::java::lang::StringBuilder().append(u"Decoder delivered "_j)->append(static_cast< ::java::lang::Object* >(theObject))
                    ->append(u", unexpected -- failed"_j)->toString()));
            } else {
                npc(c)->receiveResult(theObject);
            }
            localTerminate();
        }
    } else if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o) != nullptr) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fragment "_j)->append(static_cast< ::java::lang::Object* >(npc((java_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o)))->getKey(0)))
                ->append(u" not available"_j)->toString());

        if(numCheckedFragments() < GlacierImpl_this->numFragments)
            sendRandomRequest();

    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObject: Unexpected result: "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

    }
    return;
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(u"retrieveObject: Exception "_j, e);

    npc(c)->receiveException(e);
    localTerminate();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::sendRandomRequest()
{
    int32_t nextID;
    do {
        nextID = npc(npc(GlacierImpl_this->environment)->getRandomSource())->nextInt(GlacierImpl_this->numFragments);
    } while ((*checkedFragment)[nextID]);
    (*checkedFragment)[nextID] = true;
    auto nextKey = new ::rice::p2p::glacier::FragmentKey(key, nextID);
    auto nextLocation = GlacierImpl_this->getFragmentLocation(nextKey);
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObject: Asking "_j)->append(static_cast< ::java::lang::Object* >(nextLocation))
            ->append(u" for "_j)
            ->append(static_cast< ::java::lang::Object* >(nextKey))->toString());

    GlacierImpl_this->sendMessage(nextLocation, new ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage(getMyUID(), nextKey, ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_FRAGMENT, GlacierImpl_this->getLocalNodeHandle(), nextLocation, tag), nullptr);
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::timeoutExpired()
{
    if(attemptsLeft > 0) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObject: Retrying ("_j)->append(attemptsLeft)
                ->append(u" attempts left)"_j)->toString());

        if(attemptsLeft < GlacierImpl_this->restoreMaxBoosts) {
            GlacierImpl_this->currentFragmentRequestTimeout *= 2;
            if(GlacierImpl_this->currentFragmentRequestTimeout > GlacierImpl_this->fragmentRequestTimeoutMax)
                GlacierImpl_this->currentFragmentRequestTimeout = GlacierImpl_this->fragmentRequestTimeoutMax;

            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Timeout increased to "_j)->append(GlacierImpl_this->currentFragmentRequestTimeout)->toString());

        }
        timeout = timeout + GlacierImpl_this->currentFragmentRequestTimeout;
        attemptsLeft--;
        auto numRequests = GlacierImpl_this->numSurvivors - numHaveFragments();
        if(attemptsLeft < (GlacierImpl_this->restoreMaxBoosts - int32_t(1)))
            numRequests = ::java::lang::Math::min(int32_t(2) * numRequests, GlacierImpl_this->numFragments - numCheckedFragments());

        if((attemptsLeft == 0) && beStrict)
            numRequests = GlacierImpl_this->numFragments - numCheckedFragments();

        for (auto i = int32_t(0); (i < numRequests) && (numCheckedFragments() < GlacierImpl_this->numFragments); i++) {
            sendRandomRequest();
        }
    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObject: Giving up on "_j)->append(static_cast< ::java::lang::Object* >(key))
                ->append(u" ("_j)
                ->append(GlacierImpl_this->restoreMaxBoosts)
                ->append(u" attempts, "_j)
                ->append(numCheckedFragments())
                ->append(u" checked, "_j)
                ->append(numHaveFragments())
                ->append(u" gotten)"_j)->toString());

        npc(c)->receiveException(new GlacierNotEnoughFragmentsException(::java::lang::StringBuilder().append(u"Maximum number of attempts ("_j)->append(GlacierImpl_this->restoreMaxBoosts)
            ->append(u") reached for key "_j)
            ->append(static_cast< ::java::lang::Object* >(key))->toString(), numCheckedFragments(), numHaveFragments()));
        localTerminate();
    }
}

int64_t rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::getTimeout()
{
    return timeout;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveObject_28::getClass0()
{
    return class_();
}

