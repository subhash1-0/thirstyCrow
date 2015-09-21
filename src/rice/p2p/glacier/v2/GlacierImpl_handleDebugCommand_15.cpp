// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_15.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierQueryMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>
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
typedef ::SubArray< ::java::lang::Boolean, ObjectArray, ::java::io::SerializableArray, ComparableArray > BooleanArray;
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
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
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;
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

rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::GlacierImpl_handleDebugCommand_15(GlacierImpl *GlacierImpl_this, ::rice::p2p::commonapi::Id* fragmentLoc, ::rice::p2p::glacier::FragmentKey* id, ::java::lang::StringArray* ret, int64_t now, ::java::lang::BooleanArray* done)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , fragmentLoc(fragmentLoc)
    , id(id)
    , ret(ret)
    , now(now)
    , done(done)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::init()
{
    receivedSoFar = int32_t(0);
}

constexpr int32_t rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::total;

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::toString()
{
    return u"Burst continuation"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::init_()
{
    for (auto i = int32_t(0); i < total; i++) {
        GlacierImpl_this->sendMessage(fragmentLoc, new ::rice::p2p::glacier::v2::messaging::GlacierQueryMessage(getMyUID(), new ::rice::p2p::glacier::FragmentKeyArray({id}), GlacierImpl_this->getLocalNodeHandle(), fragmentLoc, GlacierImpl_this->tagDebug), nullptr);
    }
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o) != nullptr) {
        ret->set(int32_t(0), ::java::lang::StringBuilder().append((*ret)[int32_t(0)])->append((npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() - now))
            ->append(u" msec ("_j)
            ->append(static_cast< ::java::lang::Object* >(npc(npc((java_cast< ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* >(o)))->getSource())->getId()))
            ->append(u")\n"_j)->toString());
        if((++receivedSoFar) == total)
            timeoutExpired();

    }
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::receiveException(::java::lang::Exception* e)
{
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::timeoutExpired()
{
    done->set(int32_t(0), new ::java::lang::Boolean(true));
    terminate();
}

int64_t rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::getTimeout()
{
    return now + int32_t(120) * GlacierImpl_this->SECONDS;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_15::getClass0()
{
    return class_();
}

