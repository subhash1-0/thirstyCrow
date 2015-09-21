// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_9.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
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

rice::p2p::aggregation::AggregationImpl_handleDebugCommand_9::AggregationImpl_handleDebugCommand_9(AggregationImpl *AggregationImpl_this, ::java::lang::StringArray* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , ret(ret)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_9::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::past::PastContentHandleArray* >(o) != nullptr) {
        auto oA = java_cast< ::rice::p2p::past::PastContentHandleArray* >(o);
        ret->set(int32_t(0), u""_j);
        for (auto i = int32_t(0); i < npc(oA)->length; i++) 
                        ret->set(int32_t(0), ::java::lang::StringBuilder().append((*ret)[int32_t(0)])->append(u"#"_j)
                ->append(i)
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >((*oA)[i]))
                ->append(u"\n"_j)->toString());

        ret->set(int32_t(0), ::java::lang::StringBuilder().append((*ret)[int32_t(0)])->append(npc(oA)->length)
            ->append(u" handle(s) returned\n"_j)->toString());
    } else
        ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"result("_j)->append(static_cast< ::java::lang::Object* >(o))
            ->append(u") -- no handles returned!"_j)->toString());
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_9::receiveException(::java::lang::Exception* e)
{
    ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"exception("_j)->append(static_cast< ::java::lang::Object* >(e))
        ->append(u")"_j)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_9::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_9::getClass0()
{
    return class_();
}

