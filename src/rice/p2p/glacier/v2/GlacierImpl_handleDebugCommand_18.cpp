// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_18.hpp>

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
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_18::GlacierImpl_handleDebugCommand_18(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::FragmentKey* thisKey, ::java::lang::StringBuffer* result, ::java::util::Iterator* iter, ::java::lang::StringArray* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , thisKey(thisKey)
    , result(result)
    , iter(iter)
    , ret(ret)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_18::init()
{
    currentKey = thisKey;
    totalChecks = int32_t(1);
    totalFailures = int32_t(0);
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_18::receiveResult(::java::lang::Object* o)
{
    auto fam = java_cast< FragmentAndManifest* >(o);
    auto success = npc(npc(fam)->manifest)->validatesFragment(npc(fam)->fragment, npc(currentKey)->getFragmentID(), npc(npc(GlacierImpl_this->environment)->getLogManager())->getLogger(Manifest::class_(), GlacierImpl_this->instance));
    if(!success)
        totalFailures++;

    npc(result)->append(::java::lang::StringBuilder().append(npc(currentKey)->toStringFull())->append(u" "_j)
        ->append((success ? u"OK"_j : u"FAIL"_j))
        ->append(u"\n"_j)->toString());
    advance();
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_18::receiveException(::java::lang::Exception* e)
{
    totalFailures++;
    npc(result)->append(::java::lang::StringBuilder().append(npc(currentKey)->toStringFull())->append(u" EXC: "_j)
        ->append(static_cast< ::java::lang::Object* >(e))
        ->append(u"\n"_j)->toString());
    advance();
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_18::advance()
{
    if(npc(iter)->hasNext()) {
        currentKey = java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        totalChecks++;
        npc(GlacierImpl_this->fragmentStorage)->getObject(currentKey, this);
    } else {
        if(totalFailures == 0)
            ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"OK ("_j)->append(totalChecks)
                ->append(u" fragments checked)"_j)->toString());
        else
            ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"FAIL, "_j)->append(totalFailures)
                ->append(u"/"_j)
                ->append(totalChecks)
                ->append(u" fragments damaged"_j)->toString());
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_18::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_18::getClass0()
{
    return class_();
}

