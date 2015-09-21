// Generated from /pastry-2.1/src/rice/pastry/client/CommonAPIAppl.java
#include <rice/pastry/client/CommonAPIAppl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/IdRange.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSet.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/Router.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>

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

rice::pastry::client::CommonAPIAppl::CommonAPIAppl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::client::CommonAPIAppl::CommonAPIAppl(::rice::pastry::PastryNode* pn) 
    : CommonAPIAppl(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

rice::pastry::client::CommonAPIAppl::CommonAPIAppl(::rice::pastry::PastryNode* pn, ::java::lang::String* instance) 
    : CommonAPIAppl(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,instance);
}

void rice::pastry::client::CommonAPIAppl::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

void rice::pastry::client::CommonAPIAppl::ctor(::rice::pastry::PastryNode* pn, ::java::lang::String* instance)
{
    super::ctor(pn, instance);
}

void rice::pastry::client::CommonAPIAppl::route(::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* hint)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] route "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(key))->toString());

    auto rm = new ::rice::pastry::routing::RouteMessage(key, msg, hint, static_cast< int8_t >(npc(npc(npc(thePastryNode)->getEnvironment())->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j)));
    npc(rm)->setTLOptions(options);
    npc(npc(thePastryNode)->getRouter())->route(rm);
}

rice::pastry::NodeSet* rice::pastry::client::CommonAPIAppl::localLookup(::rice::pastry::Id* key, int32_t num, bool safe)
{
    return npc(getRoutingTable())->alternateRoutes(key, num);
}

rice::pastry::NodeSet* rice::pastry::client::CommonAPIAppl::neighborSet(int32_t num)
{
    return npc(getLeafSet())->neighborSet(num);
}

rice::pastry::NodeSet* rice::pastry::client::CommonAPIAppl::replicaSet(::rice::pastry::Id* key, int32_t max_rank)
{
    return npc(getLeafSet())->replicaSet(key, max_rank);
}

rice::pastry::IdRange* rice::pastry::client::CommonAPIAppl::range(::rice::pastry::NodeHandle* n, int32_t r, ::rice::pastry::Id* key, bool cumulative)
{
    if(cumulative)
        return npc(getLeafSet())->range(n, r);

    auto ccw = npc(getLeafSet())->range(n, r, false);
    auto cw = npc(getLeafSet())->range(n, r, true);
    if(cw == nullptr || npc(ccw)->contains(key) || npc(key)->isBetween(npc(cw)->getCW(), npc(ccw)->getCCW()))
        return ccw;
    else
        return cw;
}

rice::pastry::IdRange* rice::pastry::client::CommonAPIAppl::range(::rice::pastry::NodeHandle* n, int32_t r, ::rice::pastry::Id* key)
{
    return range(n, r, key, false);
}

void rice::pastry::client::CommonAPIAppl::forward(::rice::pastry::routing::RouteMessage* msg)
{
    return;
}

void rice::pastry::client::CommonAPIAppl::update(::rice::pastry::NodeHandle* nh, bool joined)
{
}

void rice::pastry::client::CommonAPIAppl::notifyReady()
{
}

void rice::pastry::client::CommonAPIAppl::messageForAppl(::rice::pastry::messaging::Message* msg)
{
}

void rice::pastry::client::CommonAPIAppl::leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    update(nh, wasAdded);
}

void rice::pastry::client::CommonAPIAppl::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"["_j)->append(static_cast< ::java::lang::Object* >(thePastryNode))
            ->append(u"] recv "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))->toString());

    if(dynamic_cast< ::rice::pastry::routing::RouteMessage* >(msg) != nullptr) {
        auto rm = java_cast< ::rice::pastry::routing::RouteMessage* >(msg);
        forward(rm);
        if(npc(rm)->getNextHop() != nullptr) {
            auto nextHop = npc(rm)->getNextHop();
            if(npc(getNodeId())->equals(npc(nextHop)->getNodeId())) {
                try {
                    deliver(npc(rm)->getTarget(), npc(rm)->unwrap(deserializer));
                } catch (::java::io::IOException* ioe) {
                    throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Error deserializing message "_j)->append(static_cast< ::java::lang::Object* >(rm))->toString(), ioe);
                }
            } else {
                npc(npc(thePastryNode)->getRouter())->route(rm);
            }
        }
    } else {
        deliver(nullptr, msg);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::client::CommonAPIAppl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.client.CommonAPIAppl", 32);
    return c;
}

java::lang::Class* rice::pastry::client::CommonAPIAppl::getClass0()
{
    return class_();
}

