// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java
#include <rice/p2p/replication/manager/ReplicationManagerImpl_ReplicationManagerHelper.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerClient.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl.hpp>

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

rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::ReplicationManagerImpl_ReplicationManagerHelper(ReplicationManagerImpl *ReplicationManagerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationManagerImpl_this(ReplicationManagerImpl_this)
{
    clinit();
}

rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::ReplicationManagerImpl_ReplicationManagerHelper(ReplicationManagerImpl *ReplicationManagerImpl_this) 
    : ReplicationManagerImpl_ReplicationManagerHelper(ReplicationManagerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::init()
{
    STATE_NOTHING = int32_t(0);
    STATE_WAITING = int32_t(1);
    STATE_SLEEPING = int32_t(2);
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::ctor()
{
    super::ctor();
    init();
    set = npc(ReplicationManagerImpl_this->factory)->buildIdSet();
    hints = new ::java::util::HashMap();
    state = STATE_NOTHING;
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::fetch(::rice::p2p::commonapi::IdSet* keySet, ::rice::p2p::commonapi::NodeHandle* hint)
{
    auto i = npc(keySet)->getIterator();
    while (npc(i)->hasNext()) {
        auto id = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        if(!(npc(set)->isMemberId(id) || npc(ReplicationManagerImpl_this->client)->exists(id) || ((current != nullptr) && (npc(id)->equals(current))))) {
            npc(set)->addId(id);
            npc(hints)->put(static_cast< ::java::lang::Object* >(id), static_cast< ::java::lang::Object* >(hint));
        }
    }
    if((state == STATE_NOTHING) && (npc(set)->numElements() > 0)) {
        send();
    }
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::setRange(::rice::p2p::commonapi::IdRange* range)
{
    auto notRange = npc(range)->getComplementRange();
    auto i = npc(npc(set)->subSet(notRange))->getIterator();
    while (npc(i)->hasNext()) {
        auto id = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        npc(set)->removeId(id);
        npc(hints)->remove(static_cast< ::java::lang::Object* >(id));
    }
}

rice::p2p::commonapi::IdSet* rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::scan(::rice::p2p::commonapi::IdRange* range)
{
    return npc(set)->subSet(range);
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::send()
{
    if((state != STATE_WAITING) && (npc(set)->numElements() > 0)) {
        auto id = getNextId();
        auto hint = java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(hints)->remove(static_cast< ::java::lang::Object* >(id))));
        if(id != nullptr) {
            state = STATE_WAITING;
            ReplicationManagerImpl_this->informClient(id, hint);
        } else {
            state = STATE_NOTHING;
        }
    } else if(state != STATE_WAITING) {
        state = STATE_NOTHING;
    }
}

rice::p2p::commonapi::Id* rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::getNextId()
{
    if(npc(set)->numElements() == 0) {
        if(npc(ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(ReplicationManagerImpl_this->logger)->log(u"GetNextId called without any ids available - aborting"_j);

        return nullptr;
    }
    current = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(npc(set)->getIterator())->next()));
    npc(set)->removeId(current);
    if(npc(ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(ReplicationManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Returing next id to fetch "_j)->append(static_cast< ::java::lang::Object* >(current))->toString());

    if(!npc(ReplicationManagerImpl_this->client)->exists(current))
        return current;
    else
        return getNextId();
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::wakeup()
{
    if(state == STATE_SLEEPING) {
        send();
    }
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::message(::rice::p2p::commonapi::Id* id)
{
    if((state == STATE_WAITING) && (current != nullptr) && (npc(current)->equals(id))) {
        state = STATE_SLEEPING;
        current = nullptr;
        ReplicationManagerImpl_this->scheduleNext();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.manager.ReplicationManagerImpl.ReplicationManagerHelper", 76);
    return c;
}

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper::getClass0()
{
    return class_();
}

