// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/List.hpp>
#include <java/util/Observer.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/CloneableLogManager.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>
#include <rice/pastry/direct/DirectNodeHandle.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory_getNodeHandleAdapter_2.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory_getBootstrapper_3.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory_getNodeHandleFactory_1.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory_NullCancellableTask.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/leafset/LeafSetProtocol.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/StandardLeafSetProtocol.hpp>
#include <rice/pastry/transport/NodeHandleAdapter.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > NodeHandleSetArray;
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeSetI, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeHandleSetArray > NodeSetIArray;

        namespace routing
        {
typedef ::SubArray< ::rice::pastry::routing::RouteSet, ::java::lang::ObjectArray, ::rice::pastry::NodeSetIArray, ::java::io::SerializableArray, ::java::util::ObserverArray, ::java::lang::IterableArray > RouteSetArray;
        } // routing
    } // pastry
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

rice::pastry::direct::DirectPastryNodeFactory::DirectPastryNodeFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::DirectPastryNodeFactory::DirectPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, NetworkSimulator* sim, ::rice::environment::Environment* env) 
    : DirectPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(nf,sim,env);
}

void rice::pastry::direct::DirectPastryNodeFactory::init()
{
    listeners = new ::java::util::ArrayList();
    recordTable = new ::java::util::HashMap();
}

void rice::pastry::direct::DirectPastryNodeFactory::ctor(::rice::pastry::NodeIdFactory* nf, NetworkSimulator* sim, ::rice::environment::Environment* env)
{
    super::ctor(env);
    init();
    npc(npc(env)->getParameters())->setInt(u"pastry_protocol_consistentJoin_max_time_to_be_scheduled"_j, 120000);
    nidFactory = nf;
    simulator = sim;
}

rice::pastry::leafset::LeafSetProtocol* rice::pastry::direct::DirectPastryNodeFactory::getLeafSetProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable)
{
    if(npc(npc(npc(pn)->getEnvironment())->getParameters())->getBoolean(u"pastry_direct_guarantee_consistency"_j)) {
        return super::getLeafSetProtocol(pn, leafSet, routeTable);
    } else {
        auto ret = new ::rice::pastry::standard::StandardLeafSetProtocol(pn, npc(pn)->getLocalHandle(), leafSet, routeTable);
        npc(ret)->register_();
        return ret;
    }
}

rice::pastry::direct::NetworkSimulator* rice::pastry::direct::DirectPastryNodeFactory::getNetworkSimulator()
{
    return simulator;
}

rice::pastry::PastryNode* rice::pastry::direct::DirectPastryNodeFactory::newNode(::rice::pastry::NodeHandle* bootstrap)
{
    return newNode(bootstrap, npc(nidFactory)->generateNodeId());
}

rice::pastry::PastryNode* rice::pastry::direct::DirectPastryNodeFactory::newNode() /* throws(IOException) */
{
    return newNode(npc(nidFactory)->generateNodeId());
}

rice::pastry::PastryNode* rice::pastry::direct::DirectPastryNodeFactory::newNode(::rice::pastry::NodeHandle* bootstrap, ::rice::pastry::Id* nodeId)
{
    try {
        if(bootstrap == nullptr)
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"No bootstrap node provided, starting a new ring..."_j);


        auto pn = newNode(nodeId);
        if(bootstrap == nullptr) {
            npc(npc(pn)->getBootstrapper())->boot(::java::util::Collections::EMPTY_LIST());
        } else {
            npc(npc(pn)->getBootstrapper())->boot(::java::util::Collections::singleton(bootstrap));
        }
        return pn;
    } catch (::java::io::IOException* ioe) {
        npc(logger)->logException(u"Couldn't construct node."_j, ioe);
        return nullptr;
    }
}

rice::pastry::PastryNode* rice::pastry::direct::DirectPastryNodeFactory::newNode(::rice::pastry::Id* nodeId) /* throws(IOException) */
{
    auto environment = this->environment;
    if(npc(npc(this->environment)->getParameters())->getBoolean(u"pastry_factory_multipleNodes"_j)) {
        if(dynamic_cast< ::rice::environment::logging::CloneableLogManager* >(npc(this->environment)->getLogManager()) != nullptr) {
            environment = new ::rice::environment::Environment(npc(this->environment)->getSelectorManager(), npc(this->environment)->getProcessor(), npc(this->environment)->getRandomSource(), npc(this->environment)->getTimeSource(), npc((java_cast< ::rice::environment::logging::CloneableLogManager* >(npc(this->environment)->getLogManager())))->clone(::java::lang::StringBuilder().append(u"0x"_j)->append(npc(nodeId)->toStringBare())->toString()), npc(this->environment)->getParameters(), npc(this->environment)->getExceptionStrategy());
        }
    }
    auto pn = new ::rice::pastry::PastryNode(nodeId, environment);
    nodeHandleHelper(pn);
    return pn;
}

rice::pastry::leafset::LeafSet* rice::pastry::direct::DirectPastryNodeFactory::getLeafSet(::rice::pastry::NodeHandle* handle) /* throws(IOException) */
{
    auto dHandle = java_cast< DirectNodeHandle* >(handle);
    return npc(npc(dHandle)->getRemote())->getLeafSet();
}

rice::p2p::commonapi::CancellableTask* rice::pastry::direct::DirectPastryNodeFactory::getLeafSet(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c)
{
    auto dHandle = java_cast< DirectNodeHandle* >(handle);
    npc(c)->receiveResult(npc(npc(dHandle)->getRemote())->getLeafSet());
    return new DirectPastryNodeFactory_NullCancellableTask();
}

rice::pastry::routing::RouteSetArray* rice::pastry::direct::DirectPastryNodeFactory::getRouteRow(::rice::pastry::NodeHandle* handle, int32_t row) /* throws(IOException) */
{
    auto dHandle = java_cast< DirectNodeHandle* >(handle);
    return npc(npc(npc(dHandle)->getRemote())->getRoutingTable())->getRow(row);
}

rice::p2p::commonapi::CancellableTask* rice::pastry::direct::DirectPastryNodeFactory::getRouteRow(::rice::pastry::NodeHandle* handle, int32_t row, ::rice::Continuation* c)
{
    auto dHandle = java_cast< DirectNodeHandle* >(handle);
    npc(c)->receiveResult(npc(npc(npc(dHandle)->getRemote())->getRoutingTable())->getRow(row));
    return new DirectPastryNodeFactory_NullCancellableTask();
}

int32_t rice::pastry::direct::DirectPastryNodeFactory::getProximity(::rice::pastry::NodeHandle* local, ::rice::pastry::NodeHandle* remote)
{
    return static_cast< int32_t >(npc(simulator)->proximity(java_cast< DirectNodeHandle* >(local), java_cast< DirectNodeHandle* >(remote)));
}

rice::pastry::NodeHandle* rice::pastry::direct::DirectPastryNodeFactory::getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory) /* throws(IOException) */
{
    auto localhandle = new DirectNodeHandle(pn, simulator);
    return localhandle;
}

rice::pastry::NodeHandleFactory* rice::pastry::direct::DirectPastryNodeFactory::getNodeHandleFactory(::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    return new DirectPastryNodeFactory_getNodeHandleFactory_1(this);
}

rice::pastry::transport::NodeHandleAdapter* rice::pastry::direct::DirectPastryNodeFactory::getNodeHandleAdapter(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::transport::TLDeserializer* deserializer) /* throws(IOException) */
{
    auto nr = java_cast< NodeRecord* >(java_cast< NodeRecord* >(npc(recordTable)->get(static_cast< ::java::lang::Object* >(npc(pn)->getId()))));
    if(nr == nullptr) {
        nr = npc(simulator)->generateNodeRecord();
        npc(recordTable)->put(static_cast< ::java::lang::Object* >(npc(pn)->getNodeId()), static_cast< ::java::lang::Object* >(nr));
    }
    auto tl = getDirectTransportLayer(pn, nr);
    auto nha = new ::rice::pastry::transport::NodeHandleAdapter(tl, npc(simulator)->getLivenessProvider(), new DirectPastryNodeFactory_getNodeHandleAdapter_2(this, pn));
    return nha;
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::direct::DirectPastryNodeFactory::getDirectTransportLayer(::rice::pastry::PastryNode* pn, NodeRecord* nr)
{
    auto tl = new ::org::mpisws::p2p::transport::direct::DirectTransportLayer(npc(pn)->getLocalHandle(), simulator, nr, npc(pn)->getEnvironment());
    return tl;
}

rice::pastry::boot::Bootstrapper* rice::pastry::direct::DirectPastryNodeFactory::getBootstrapper(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::NodeHandleAdapter* tl, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns)
{
    return new DirectPastryNodeFactory_getBootstrapper_3(this, pns, pn);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.DirectPastryNodeFactory", 42);
    return c;
}

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory::getClass0()
{
    return class_();
}

