// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/PastImpl_lookup_9.hpp>
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1.hpp>
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1.hpp>
#include <rice/p2p/past/PastImpl.hpp>
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

rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2(PastImpl_lookup_9_receiveResult_9_1 *PastImpl_lookup_9_receiveResult_9_1_this, bool cache, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_lookup_9_receiveResult_9_1_this(PastImpl_lookup_9_receiveResult_9_1_this)
    , cache(cache)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2::receiveResult(::java::lang::Object* o)
{
    auto handles = java_cast< PastContentHandleArray* >(o);
    for (auto i = int32_t(0); i < npc(handles)->length; i++) {
        if((*handles)[i] != nullptr) {
            PastImpl_lookup_9_receiveResult_9_1_this->PastImpl_lookup_9_this->PastImpl_this->fetch((*handles)[i], static_cast< ::rice::Continuation* >(new PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1(this, cache, command, PastImpl_lookup_9_receiveResult_9_1_this->parent)));
            return;
        }
    }
    npc(command)->receiveResult(nullptr);
}

void rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2::receiveException(::java::lang::Exception* e)
{
    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2::getClass0()
{
    return class_();
}

