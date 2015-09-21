// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_lookupHandles_10_receiveResult_10_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/PastImpl_lookupHandles_10.hpp>
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

rice::p2p::past::PastImpl_lookupHandles_10_receiveResult_10_1::PastImpl_lookupHandles_10_receiveResult_10_1(PastImpl_lookupHandles_10 *PastImpl_lookupHandles_10_this, ::rice::Continuation* parent, int32_t num)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_lookupHandles_10_this(PastImpl_lookupHandles_10_this)
{
    clinit();
    ctor(parent, num);
}

java::lang::Object* rice::p2p::past::PastImpl_lookupHandles_10_receiveResult_10_1::getResult()
{
    auto p = new PastContentHandleArray(npc(result)->length);
    for (auto i = int32_t(0); i < npc(result)->length; i++) 
                if(dynamic_cast< PastContentHandle* >((*result)[i]) != nullptr)
            p->set(i, java_cast< PastContentHandle* >((*result)[i]));


    return p;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_lookupHandles_10_receiveResult_10_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_lookupHandles_10_receiveResult_10_1::getClass0()
{
    return class_();
}

