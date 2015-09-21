// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java
#include <rice/p2p/replication/ReplicationImpl_replicate_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/RangeCannotBeDeterminedException.hpp>
#include <rice/p2p/replication/ReplicationImpl_replicate_2_receiveResult_2_1.hpp>
#include <rice/p2p/replication/ReplicationImpl_BloomFilterExecutable.hpp>
#include <rice/p2p/replication/ReplicationImpl.hpp>
#include <rice/p2p/util/IdBloomFilter.hpp>

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

rice::p2p::replication::ReplicationImpl_replicate_2::ReplicationImpl_replicate_2(ReplicationImpl *ReplicationImpl_this, ::rice::p2p::commonapi::NodeHandleSet* handles, ::rice::p2p::commonapi::IdRange* ourRange, ::java::lang::String* name, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationImpl_this(ReplicationImpl_this)
    , handles(handles)
    , ourRange(ourRange)
{
    clinit();
    init();
    ctor(name, env);
}

void rice::p2p::replication::ReplicationImpl_replicate_2::init()
{
    total = int32_t(0);
}

void rice::p2p::replication::ReplicationImpl_replicate_2::receiveResult(::java::lang::Object* o)
{
    if(ReplicationImpl_this->destroyed)
        return;

    auto const ourFilter = java_cast< ::rice::p2p::util::IdBloomFilter* >(o);
    for (auto i = int32_t(0); i < npc(handles)->size(); i++) {
        auto const handle = npc(handles)->getHandle(i);
        try {
            auto const handleRange = npc(ReplicationImpl_this->endpoint)->range(handle, 0, npc(handle)->getId());
            auto const range = npc(handleRange)->intersectRange(ReplicationImpl_this->getTotalRange());
            if((range != nullptr) && (!npc(npc(range)->intersectRange(ReplicationImpl_this->getTotalRange()))->isEmpty())) {
                npc(ReplicationImpl_this->endpoint)->process(new ReplicationImpl_BloomFilterExecutable(ReplicationImpl_this, range), new ReplicationImpl_replicate_2_receiveResult_2_1(this, handle, range, ourRange, ourFilter, this));
            }
        } catch (::rice::p2p::commonapi::RangeCannotBeDeterminedException* re) {
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"COUNT: Done sending replications requests with "_j)->append(total)
            ->append(u" in instance "_j)
            ->append(ReplicationImpl_this->instance)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::ReplicationImpl_replicate_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::replication::ReplicationImpl_replicate_2::getClass0()
{
    return class_();
}

