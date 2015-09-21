// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_8.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
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

rice::p2p::aggregation::AggregationImpl_handleDebugCommand_8::AggregationImpl_handleDebugCommand_8(AggregationImpl *AggregationImpl_this, ::java::lang::StringArray* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , ret(ret)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_8::receiveResult(::java::lang::Object* o)
{
    ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"result("_j)->append(static_cast< ::java::lang::Object* >(o))
        ->append(u")"_j)->toString());
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_8::receiveException(::java::lang::Exception* e)
{
    ret->set(int32_t(0), ::java::lang::StringBuilder().append(u"exception("_j)->append(static_cast< ::java::lang::Object* >(e))
        ->append(u")"_j)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_8::getClass0()
{
    return class_();
}

