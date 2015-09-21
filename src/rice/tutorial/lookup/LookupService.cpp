// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java
#include <rice/tutorial/lookup/LookupService.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashMap.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/tutorial/lookup/LookupService_requestNodeHandle_3.hpp>
#include <rice/tutorial/lookup/LookupService_requestNodeHandles_1.hpp>
#include <rice/tutorial/lookup/LookupService_sendMessageWithRetries_2.hpp>
#include <rice/tutorial/lookup/LookupService_NodeLookupQuery.hpp>
#include <rice/tutorial/lookup/LookupService_NodeLookupResponse.hpp>
#include <rice/tutorial/lookup/LookupService_NodeLookupTimeout.hpp>
#include <rice/tutorial/lookup/LookupService_NodeLookupTimeoutException.hpp>

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

rice::tutorial::lookup::LookupService::LookupService(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::lookup::LookupService::LookupService(::rice::p2p::commonapi::Node* node, int64_t timeout) 
    : LookupService(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,timeout);
}

rice::tutorial::lookup::LookupService::LookupService(::rice::p2p::commonapi::Node* node) 
    : LookupService(*static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::tutorial::lookup::LookupService::ctor(::rice::p2p::commonapi::Node* node, int64_t timeout)
{
    super::ctor();
    this->pending = new ::java::util::HashMap();
    this->seqno = 42;
    this->endpoint = npc(node)->buildEndpoint(this, nullptr);
    npc(endpoint)->register_();
    this->logger = npc(npc(npc(endpoint)->getEnvironment())->getLogManager())->getLogger(getClass(), nullptr);
    this->firstTimeout = npc(npc(npc(endpoint)->getEnvironment())->getParameters())->getLong(u"lookup_service.firstTimeout"_j);
    if(timeout > 0) {
        this->timeout = timeout;
    } else {
        this->timeout = npc(npc(npc(endpoint)->getEnvironment())->getParameters())->getLong(u"lookup_service.timeout"_j);
        if(this->timeout <= 0)
            this->timeout = 30000;

    }
    if(this->firstTimeout <= 0)
        this->firstTimeout = this->timeout / int32_t(16);

}

void rice::tutorial::lookup::LookupService::ctor(::rice::p2p::commonapi::Node* node)
{
    ctor(node, -int32_t(1));
}

bool rice::tutorial::lookup::LookupService::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

void rice::tutorial::lookup::LookupService::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    if(dynamic_cast< LookupService_NodeLookupQuery* >(message) != nullptr) {
        auto query = java_cast< LookupService_NodeLookupQuery* >(message);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"NodeLookup query received for "_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u" with sequence number "_j)
                ->append(npc(query)->seqno)->toString());

        npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::Message* >(new LookupService_NodeLookupResponse(npc(endpoint)->replicaSet(id, npc(query)->numNodes), npc(query)->seqno)), npc(query)->source);
    } else if(dynamic_cast< LookupService_NodeLookupResponse* >(message) != nullptr) {
        auto response = java_cast< LookupService_NodeLookupResponse* >(message);
        if(npc(pending)->containsKey(::java::lang::Integer::valueOf(npc(response)->seqno))) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"NodeLookup response received with sequence number "_j)->append(npc(response)->seqno)->toString());

            npc(java_cast< ::rice::Continuation* >(npc(pending)->remove(::java::lang::Integer::valueOf(npc(response)->seqno))))->receiveResult(npc(response)->nodes);
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"NodeLookup received response for non-existent or expired lookup "_j)->append(npc(response)->seqno)->toString());

        }
    } else if(dynamic_cast< LookupService_NodeLookupTimeout* >(message) != nullptr) {
        auto response = java_cast< LookupService_NodeLookupTimeout* >(message);
        if(npc(pending)->containsKey(::java::lang::Integer::valueOf(npc(response)->seqno))) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"NodeLookup timed out with sequence number "_j)->append(npc(response)->seqno)->toString());

            npc(java_cast< ::rice::Continuation* >(npc(pending)->remove(::java::lang::Integer::valueOf(npc(response)->seqno))))->receiveException(new LookupService_NodeLookupTimeoutException());
        }
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"NodeLookup received unexpected message "_j)->append(static_cast< ::java::lang::Object* >(message))->toString());

    }
}

void rice::tutorial::lookup::LookupService::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

void rice::tutorial::lookup::LookupService::requestNodeHandles(::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont)
{
    npc(npc(npc(endpoint)->getEnvironment())->getSelectorManager())->invoke(new LookupService_requestNodeHandles_1(this, id, num, cont));
}

void rice::tutorial::lookup::LookupService::sendMessageWithRetries(::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont)
{
    auto const seq = seqno++;
    sendMessage(seq, id, num, new LookupService_sendMessageWithRetries_2(this, seq, id, num, cont), firstTimeout);
}

void rice::tutorial::lookup::LookupService::sendMessage(int32_t seq, ::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont, int64_t timeout)
{
    npc(pending)->put(::java::lang::Integer::valueOf(seq), static_cast< ::java::lang::Object* >(cont));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"NodeLookup being sent to id  "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" with sequence number "_j)
            ->append(seq)->toString());

    npc(endpoint)->route(id, static_cast< ::rice::p2p::commonapi::Message* >(new LookupService_NodeLookupQuery(npc(endpoint)->getLocalNodeHandle(), num, seq)), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
    npc(endpoint)->scheduleMessage(new LookupService_NodeLookupTimeout(seq), timeout);
}

void rice::tutorial::lookup::LookupService::requestNodeHandle(::rice::p2p::commonapi::Id* id, ::rice::Continuation* cont)
{
    npc(npc(npc(endpoint)->getEnvironment())->getSelectorManager())->invoke(new LookupService_requestNodeHandle_3(this, id, cont));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupService::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.lookup.LookupService", 34);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupService::getClass0()
{
    return class_();
}

