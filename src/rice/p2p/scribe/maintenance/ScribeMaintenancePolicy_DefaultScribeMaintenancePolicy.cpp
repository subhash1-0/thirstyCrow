// Generated from /pastry-2.1/src/rice/p2p/scribe/maintenance/ScribeMaintenancePolicy.java
#include <rice/p2p/scribe/maintenance/ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Set.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/scribe/maintenance/MaintainableScribe.hpp>
#include <rice/p2p/scribe/messaging/SubscribeMessage.hpp>

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

rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy(::rice::environment::Environment* environment) 
    : ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy(*static_cast< ::default_init_tag* >(0))
{
    ctor(environment);
}

void rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::ctor(::rice::environment::Environment* environment)
{
    super::ctor();
    logger = npc(npc(environment)->getLogManager())->getLogger(ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::class_(), nullptr);
}

void rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::doMaintenance(MaintainableScribe* scribe)
{
    auto manifest = new ::java::util::HashMap();
    for (auto _i = npc(npc(scribe)->getTopics())->iterator(); _i->hasNext(); ) {
        ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
        {
            auto parent = npc(scribe)->getParent(topic);
            if(parent != nullptr) {
                auto topics = java_cast< ::java::util::List* >(npc(manifest)->get(static_cast< ::java::lang::Object* >(parent)));
                if(topics == nullptr) {
                    topics = new ::java::util::ArrayList();
                    npc(manifest)->put(static_cast< ::java::lang::Object* >(parent), static_cast< ::java::lang::Object* >(topics));
                }
                npc(topics)->add(static_cast< ::java::lang::Object* >(topic));
            } else {
            }
        }
    }
    for (auto _i = npc(npc(manifest)->keySet())->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::NodeHandle* parent = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
        {
            auto topics = java_cast< ::java::util::List* >(npc(manifest)->get(static_cast< ::java::lang::Object* >(parent)));
            npc(npc(scribe)->getEndpoint())->route(npc(java_cast< ::rice::p2p::scribe::Topic* >(npc(topics)->get(0)))->getId(), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::SubscribeMessage(npc(npc(scribe)->getEndpoint())->getLocalNodeHandle(), topics, MaintainableScribe::MAINTENANCE_ID, implicitSubscribe(topics))), parent);
            npc(parent)->checkLiveness();
        }
    }
}

void rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::noLongerRoot(MaintainableScribe* scribe, ::java::util::List* topics)
{
    npc(scribe)->subscribe(topics, nullptr, implicitSubscribe(::java::util::Collections::unmodifiableList(topics)), nullptr);
}

void rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::nodeFaulty(MaintainableScribe* scribe, ::rice::p2p::commonapi::NodeHandle* handle, ::java::util::List* nodeWasParent, ::java::util::List* nodeWasChild)
{
    npc(scribe)->subscribe(nodeWasParent, nullptr, implicitSubscribe(::java::util::Collections::unmodifiableList(nodeWasParent)), nullptr);
}

void rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::subscribeFailed(MaintainableScribe* scribe, ::java::util::List* failedTopics)
{
    npc(scribe)->subscribe(failedTopics, nullptr, implicitSubscribe(::java::util::Collections::unmodifiableList(failedTopics)), nullptr);
}

rice::p2p::scribe::rawserialization::RawScribeContent* rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::implicitSubscribe(::java::util::List* topics)
{
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.maintenance.ScribeMaintenancePolicy.DefaultScribeMaintenancePolicy", 82);
    return c;
}

java::lang::Class* rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy::getClass0()
{
    return class_();
}

