// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_AggregationImpl_3.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/aggregation/AggregateHandle.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>

rice::p2p::aggregation::AggregationImpl_AggregationImpl_3::AggregationImpl_AggregationImpl_3(AggregationImpl *AggregationImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
{
    clinit();
    ctor();
}

rice::p2p::past::PastContentHandle* rice::p2p::aggregation::AggregationImpl_AggregationImpl_3::deserializePastContentHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */
{
    switch (contentType) {
    case AggregateHandle::TYPE:
        return new AggregateHandle(buf, endpoint);
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown Type:"_j)->append(contentType)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_AggregationImpl_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_AggregationImpl_3::getClass0()
{
    return class_();
}

