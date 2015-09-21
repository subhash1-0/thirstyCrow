// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java
#include <rice/p2p/replication/ReplicationImpl_replicate_2_receiveResult_2_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/replication/ReplicationImpl_replicate_2.hpp>
#include <rice/p2p/replication/ReplicationImpl.hpp>
#include <rice/p2p/replication/messaging/RequestMessage.hpp>
#include <rice/p2p/util/IdBloomFilter.hpp>
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
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::IdRange, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdRangeArray;
        } // commonapi

        namespace util
        {
typedef ::SubArray< ::rice::p2p::util::IdBloomFilter, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdBloomFilterArray;
        } // util
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

rice::p2p::replication::ReplicationImpl_replicate_2_receiveResult_2_1::ReplicationImpl_replicate_2_receiveResult_2_1(ReplicationImpl_replicate_2 *ReplicationImpl_replicate_2_this, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::IdRange* range, ::rice::p2p::commonapi::IdRange* ourRange, ::rice::p2p::util::IdBloomFilter* ourFilter, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationImpl_replicate_2_this(ReplicationImpl_replicate_2_this)
    , handle(handle)
    , range(range)
    , ourRange(ourRange)
    , ourFilter(ourFilter)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::replication::ReplicationImpl_replicate_2_receiveResult_2_1::receiveResult(::java::lang::Object* o)
{
    auto filter = java_cast< ::rice::p2p::util::IdBloomFilter* >(o);
    if(npc(ReplicationImpl_replicate_2_this->ReplicationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(ReplicationImpl_replicate_2_this->ReplicationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"COUNT: Sending request to "_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u" for range "_j)
            ->append(static_cast< ::java::lang::Object* >(range))
            ->append(u", "_j)
            ->append(static_cast< ::java::lang::Object* >(ourRange))
            ->append(u" in instance "_j)
            ->append(ReplicationImpl_replicate_2_this->ReplicationImpl_this->instance)->toString());

    auto request = new ::rice::p2p::replication::messaging::RequestMessage(ReplicationImpl_replicate_2_this->ReplicationImpl_this->handle, new ::rice::p2p::commonapi::IdRangeArray({
        range
        , ourRange
    }), new ::rice::p2p::util::IdBloomFilterArray({
        filter
        , ourFilter
    }));
    npc(ReplicationImpl_replicate_2_this->ReplicationImpl_this->endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(request), handle);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::ReplicationImpl_replicate_2_receiveResult_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::replication::ReplicationImpl_replicate_2_receiveResult_2_1::getClass0()
{
    return class_();
}

