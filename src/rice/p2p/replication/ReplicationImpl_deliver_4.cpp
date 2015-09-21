// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java
#include <rice/p2p/replication/ReplicationImpl_deliver_4.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/replication/ReplicationClient.hpp>
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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::ReplicationImpl_deliver_4::ReplicationImpl_deliver_4(ReplicationImpl *ReplicationImpl_this, int32_t j, ::rice::p2p::replication::messaging::RequestMessage* rm)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationImpl_this(ReplicationImpl_this)
    , j(j)
    , rm(rm)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::replication::ReplicationImpl_deliver_4::toString()
{
    return ::java::lang::StringBuilder().append(u"process "_j)->append(j)
        ->append(u" of "_j)
        ->append(npc(npc(rm)->getRanges())->length)
        ->append(u" namespace "_j)
        ->append(ReplicationImpl_this->instance)->toString();
}

java::lang::Object* rice::p2p::replication::ReplicationImpl_deliver_4::execute()
{
    auto set = npc(ReplicationImpl_this->factory)->buildIdSet();
    npc((*npc(rm)->getFilters())[j])->check(npc(ReplicationImpl_this->client)->scan((*npc(rm)->getRanges())[j]), set, ReplicationImpl_this->MAX_KEYS_IN_MESSAGE);
    return set;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::ReplicationImpl_deliver_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::replication::ReplicationImpl_deliver_4::getClass0()
{
    return class_();
}

