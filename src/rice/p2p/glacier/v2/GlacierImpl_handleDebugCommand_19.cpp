// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_19.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierFetchMessage.hpp>
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
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

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

rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_19::GlacierImpl_handleDebugCommand_19(GlacierImpl *GlacierImpl_this, ::rice::p2p::commonapi::Id* fragmentLoc, ::rice::p2p::glacier::FragmentKey* id, ::java::lang::StringArray* ret, int64_t now)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , fragmentLoc(fragmentLoc)
    , id(id)
    , ret(ret)
    , now(now)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_19::toString()
{
    return u"DebugFetch continuation"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_19::init_()
{
    GlacierImpl_this->sendMessage(fragmentLoc, new ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage(getMyUID(), id, ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_FRAGMENT_AND_MANIFEST, GlacierImpl_this->getLocalNodeHandle(), fragmentLoc, GlacierImpl_this->tagDebug), nullptr);
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_19::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o) != nullptr) {
        auto gdm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* >(o);
        ::java::security::MessageDigest* md = nullptr;
        try {
            md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
        } catch (::java::security::NoSuchAlgorithmException* e) {
        }
        npc(md)->reset();
        npc(md)->update(npc(npc(gdm)->getFragment(0))->getPayload());
        ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"\n\nResponse: "_j)->append(npc(npc(gdm)->getKey(0))->toStringFull())
            ->append(u" ("_j)
            ->append(npc(gdm)->numKeys())
            ->append(u" keys)\n"_j)
            ->append(u"Holder: "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(gdm)->getSource()))
            ->append(u"\n"_j)
            ->append(u"Fragment: "_j)
            ->append(npc(npc(npc(gdm)->getFragment(0))->getPayload())->length)
            ->append(u" bytes, Hash=["_j)
            ->append(GlacierImpl::dump(npc(md)->digest(), false))
            ->append(u"]\n\nValidation: "_j)
            ->append((npc(npc(gdm)->getManifest(0))->validatesFragment(npc(gdm)->getFragment(0), npc(npc(gdm)->getKey(0))->getFragmentID(), npc(npc(GlacierImpl_this->environment)->getLogManager())->getLogger(Manifest::class_(), GlacierImpl_this->instance)) ? u"OK"_j : u"FAIL"_j))
            ->append(u"\n\n"_j)
            ->append(npc(npc(gdm)->getManifest(0))->toStringFull())->toString());
        terminate();
    } else {
        ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"Received "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());
        terminate();
    }
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_19::receiveException(::java::lang::Exception* e)
{
    ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"Exception="_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    terminate();
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_19::timeoutExpired()
{
    ret->set(int32_t(0), u"Timeout"_j);
    terminate();
}

int64_t rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_19::getTimeout()
{
    return now + int32_t(5) * GlacierImpl_this->SECONDS;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_19::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_19::getClass0()
{
    return class_();
}

