// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/TransportPastryNodeFactory.hpp>

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

struct default_init_tag;

class rice::pastry::direct::DirectPastryNodeFactory
    : public ::rice::pastry::transport::TransportPastryNodeFactory
{

public:
    typedef ::rice::pastry::transport::TransportPastryNodeFactory super;

public: /* protected */
    ::rice::pastry::NodeIdFactory* nidFactory {  };
    NetworkSimulator* simulator {  };
    ::java::util::Collection* listeners {  };
protected:
    void ctor(::rice::pastry::NodeIdFactory* nf, NetworkSimulator* sim, ::rice::environment::Environment* env);

public: /* protected */
    ::rice::pastry::leafset::LeafSetProtocol* getLeafSetProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable) override;

public:
    virtual NetworkSimulator* getNetworkSimulator();
    ::rice::pastry::PastryNode* newNode(::rice::pastry::NodeHandle* bootstrap) override;
    ::rice::pastry::PastryNode* newNode() /* throws(IOException) */ override;

public: /* package */
    ::java::util::HashMap* recordTable {  };

public:
    ::rice::pastry::PastryNode* newNode(::rice::pastry::NodeHandle* bootstrap, ::rice::pastry::Id* nodeId) override;
    ::rice::pastry::PastryNode* newNode(::rice::pastry::Id* nodeId) /* throws(IOException) */ override;
    virtual ::rice::pastry::leafset::LeafSet* getLeafSet(::rice::pastry::NodeHandle* handle) /* throws(IOException) */;
    virtual ::rice::p2p::commonapi::CancellableTask* getLeafSet(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c);
    virtual ::rice::pastry::routing::RouteSetArray* getRouteRow(::rice::pastry::NodeHandle* handle, int32_t row) /* throws(IOException) */;
    virtual ::rice::p2p::commonapi::CancellableTask* getRouteRow(::rice::pastry::NodeHandle* handle, int32_t row, ::rice::Continuation* c);
    virtual int32_t getProximity(::rice::pastry::NodeHandle* local, ::rice::pastry::NodeHandle* remote);

public: /* protected */
    ::rice::pastry::NodeHandle* getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory) /* throws(IOException) */ override;
    ::rice::pastry::NodeHandleFactory* getNodeHandleFactory(::rice::pastry::PastryNode* pn) /* throws(IOException) */ override;
    ::rice::pastry::transport::NodeHandleAdapter* getNodeHandleAdapter(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::transport::TLDeserializer* deserializer) /* throws(IOException) */ override;
    virtual ::org::mpisws::p2p::transport::TransportLayer* getDirectTransportLayer(::rice::pastry::PastryNode* pn, NodeRecord* nr);
    ::rice::pastry::boot::Bootstrapper* getBootstrapper(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::NodeHandleAdapter* tl, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns) override;

    // Generated

public:
    DirectPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, NetworkSimulator* sim, ::rice::environment::Environment* env);
protected:
    DirectPastryNodeFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class DirectPastryNodeFactory_NullCancellableTask;
    friend class DirectPastryNodeFactory_getNodeHandleFactory_1;
    friend class DirectPastryNodeFactory_getNodeHandleAdapter_2;
    friend class DirectPastryNodeFactory_getBootstrapper_3;
    friend class DirectPastryNodeFactory_getBootstrapper_3_boot_3_1;
};
