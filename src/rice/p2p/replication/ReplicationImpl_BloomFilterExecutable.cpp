// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java
#include <rice/p2p/replication/ReplicationImpl_BloomFilterExecutable.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/replication/ReplicationClient.hpp>
#include <rice/p2p/replication/ReplicationImpl.hpp>
#include <rice/p2p/util/IdBloomFilter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::ReplicationImpl_BloomFilterExecutable::ReplicationImpl_BloomFilterExecutable(ReplicationImpl *ReplicationImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationImpl_this(ReplicationImpl_this)
{
    clinit();
}

rice::p2p::replication::ReplicationImpl_BloomFilterExecutable::ReplicationImpl_BloomFilterExecutable(ReplicationImpl *ReplicationImpl_this, ::rice::p2p::commonapi::IdRange* range) 
    : ReplicationImpl_BloomFilterExecutable(ReplicationImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(range);
}

void rice::p2p::replication::ReplicationImpl_BloomFilterExecutable::ctor(::rice::p2p::commonapi::IdRange* range)
{
    super::ctor();
    this->range = range;
}

java::lang::String* rice::p2p::replication::ReplicationImpl_BloomFilterExecutable::toString()
{
    return ::java::lang::StringBuilder().append(u"bloomfilter range "_j)->append(static_cast< ::java::lang::Object* >(range))
        ->append(u" namespace "_j)
        ->append(ReplicationImpl_this->instance)->toString();
}

java::lang::Object* rice::p2p::replication::ReplicationImpl_BloomFilterExecutable::execute()
{
    return new ::rice::p2p::util::IdBloomFilter(npc(ReplicationImpl_this->client)->scan(range));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::ReplicationImpl_BloomFilterExecutable::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.ReplicationImpl.BloomFilterExecutable", 58);
    return c;
}

java::lang::Class* rice::p2p::replication::ReplicationImpl_BloomFilterExecutable::getClass0()
{
    return class_();
}

