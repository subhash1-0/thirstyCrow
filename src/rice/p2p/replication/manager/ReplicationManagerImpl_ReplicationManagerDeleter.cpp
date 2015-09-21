// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java
#include <rice/p2p/replication/manager/ReplicationManagerImpl_ReplicationManagerDeleter.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerClient.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl_ReplicationManagerDeleter_go_1.hpp>
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

rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter::ReplicationManagerImpl_ReplicationManagerDeleter(ReplicationManagerImpl *ReplicationManagerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationManagerImpl_this(ReplicationManagerImpl_this)
{
    clinit();
}

rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter::ReplicationManagerImpl_ReplicationManagerDeleter(ReplicationManagerImpl *ReplicationManagerImpl_this) 
    : ReplicationManagerImpl_ReplicationManagerDeleter(ReplicationManagerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter::ctor()
{
    super::ctor();
    set = npc(ReplicationManagerImpl_this->factory)->buildIdSet();
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter::setRange(::rice::p2p::commonapi::IdRange* range)
{
    auto notRange = npc(range)->getComplementRange();
    auto i = npc(npc(ReplicationManagerImpl_this->client)->scan(notRange))->getIterator();
    auto count = int32_t(0);
    while (npc(i)->hasNext() && (count < ReplicationManagerImpl_this->NUM_DELETE_AT_ONCE)) {
        count++;
        auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        if((id == nullptr) || (!(npc(id)->equals(next))))
            npc(set)->addId(next);

    }
    auto j = npc(npc(set)->subSet(range))->getIterator();
    while (npc(j)->hasNext()) 
                npc(set)->removeId(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(j)->next())));

    go();
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter::go()
{
    if((id == nullptr) && (npc(set)->numElements() > 0)) {
        id = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(npc(set)->getIterator())->next()));
        npc(set)->removeId(id);
        if(npc(ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(ReplicationManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Deciding whether to remove "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

        npc(ReplicationManagerImpl_this->client)->existsInOverlay(id, new ReplicationManagerImpl_ReplicationManagerDeleter_go_1(this, this));
    }
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter::receiveResult(::java::lang::Object* o)
{
    if(id == nullptr)
        if(npc(ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(ReplicationManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"ERROR: RMImpl.deleter Received result "_j)->append(static_cast< ::java::lang::Object* >(o))
                ->append(u" unexpectedly!"_j)->toString());


    if(!npc(::java::lang::Boolean::TRUE())->equals(o))
        if(npc(ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(ReplicationManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"ERROR: RMImpl.deleter Unstore of "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u" did not succeed '"_j)
                ->append(static_cast< ::java::lang::Object* >(o))
                ->append(u"'!"_j)->toString());


    id = nullptr;
    go();
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter::receiveException(::java::lang::Exception* e)
{
    if(npc(ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
        npc(ReplicationManagerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"RMImpl.deleter Unstore of "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" caused exception '"_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u"'!"_j)->toString(), e);

    id = nullptr;
    go();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.manager.ReplicationManagerImpl.ReplicationManagerDeleter", 77);
    return c;
}

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter::getClass0()
{
    return class_();
}

