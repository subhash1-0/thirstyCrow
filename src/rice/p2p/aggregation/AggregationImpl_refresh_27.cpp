// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_refresh_27.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <ObjectArray.hpp>

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

rice::p2p::aggregation::AggregationImpl_refresh_27::AggregationImpl_refresh_27(AggregationImpl *AggregationImpl_this, ::java::lang::ObjectArray* result, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , result(result)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_refresh_27::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::java::lang::ObjectArray* >(o) != nullptr) {
        auto subresult = java_cast< ::java::lang::ObjectArray* >(o);
        for (auto i = int32_t(0); i < npc(result)->length; i++) 
                        if((dynamic_cast< ::java::lang::Boolean* >((*result)[i]) != nullptr) && !(dynamic_cast< ::java::lang::Boolean* >((*subresult)[i]) != nullptr))
                result->set(i, (*subresult)[i]);


    } else {
        ::java::lang::Exception* e = new AggregationException(::java::lang::StringBuilder().append(u"Object store returns unexpected result: "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());
        for (auto i = int32_t(0); i < npc(result)->length; i++) 
                        result->set(i, e);

    }
    npc(command)->receiveResult(result);
}

void rice::p2p::aggregation::AggregationImpl_refresh_27::receiveException(::java::lang::Exception* e)
{
    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refresh_27::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refresh_27::getClass0()
{
    return class_();
}

