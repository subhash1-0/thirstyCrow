// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_17.hpp>

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
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_17::GlacierImpl_handleDebugCommand_17(GlacierImpl *GlacierImpl_this, ::java::lang::StringArray* ret, ::rice::p2p::glacier::FragmentKey* id, FragmentMetadata* metadata)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , ret(ret)
    , id(id)
    , metadata(metadata)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_17::receiveResult(::java::lang::Object* o)
{
    auto fam = java_cast< FragmentAndManifest* >(o);
    ::java::security::MessageDigest* md = nullptr;
    try {
        md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
    } catch (::java::security::NoSuchAlgorithmException* e) {
    }
    npc(md)->reset();
    npc(md)->update(npc(npc(fam)->fragment)->getPayload());
    ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"OK\n\nFragment: "_j)->append(npc(npc(npc(fam)->fragment)->getPayload())->length)
        ->append(u" bytes, Hash=["_j)
        ->append(GlacierImpl::dump(npc(md)->digest(), false))
        ->append(u"], ID="_j)
        ->append(npc(id)->getFragmentID())
        ->append(u"\n\nValidation: "_j)
        ->append((npc(npc(fam)->manifest)->validatesFragment(npc(fam)->fragment, npc(id)->getFragmentID(), npc(npc(GlacierImpl_this->environment)->getLogManager())->getLogger(Manifest::class_(), GlacierImpl_this->instance)) ? u"OK"_j : u"FAIL"_j))
        ->append(u"\n\n"_j)
        ->append(npc(npc(fam)->manifest)->toStringFull())
        ->append(u"\n\nMetadata:\n - Stored since: "_j)
        ->append(npc(metadata)->getStoredSince())
        ->append(u"\n - Current expiration: "_j)
        ->append(npc(metadata)->getCurrentExpiration())
        ->append(u"\n - Previous expiration: "_j)
        ->append(npc(metadata)->getPreviousExpiration())
        ->append(u"\n"_j)->toString());
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_17::receiveException(::java::lang::Exception* e)
{
    ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"exception("_j)->append(static_cast< ::java::lang::Object* >(e))
        ->append(u")"_j)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_17::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_17::getClass0()
{
    return class_();
}

