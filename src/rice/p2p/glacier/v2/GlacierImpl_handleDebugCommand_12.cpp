// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_12.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_12::GlacierImpl_handleDebugCommand_12(GlacierImpl *GlacierImpl_this, ::java::lang::StringBuffer* result, int64_t now, ::java::util::Iterator* iter, ::java::lang::StringArray* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , result(result)
    , now(now)
    , iter(iter)
    , ret(ret)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_12::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr)
        npc(result)->append(::java::lang::StringBuilder().append(npc(currentLookup)->toStringFull())->append(u" "_j)
            ->append((npc((java_cast< ::java::lang::Long* >(o)))->longValue() - now))
            ->append(u"\n"_j)->toString());

    if(npc(iter)->hasNext()) {
        currentLookup = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        npc(GlacierImpl_this->neighborStorage)->getObject(currentLookup, this);
    } else {
        ret->set(int32_t(0), u"OK"_j);
    }
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_12::receiveException(::java::lang::Exception* e)
{
    ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"Exception: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_12::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_12::getClass0()
{
    return class_();
}

