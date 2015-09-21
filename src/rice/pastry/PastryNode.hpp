// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/util/Observable.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/Destructable.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>

struct default_init_tag;

class rice::pastry::PastryNode
    : public ::java::util::Observable
    , public virtual ::rice::p2p::commonapi::Node
    , public virtual ::rice::Destructable
    , public virtual NodeHandleFactory
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessProvider
    , public virtual ::org::mpisws::p2p::transport::proximity::ProximityProvider
    , public virtual ::org::mpisws::p2p::transport::proximity::ProximityListener
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessListener
{

public:
    typedef ::java::util::Observable super;
    static constexpr int8_t CONNECTION_UNKNOWN_ERROR { int8_t(-1) };
    static constexpr int8_t CONNECTION_UNKNOWN { int8_t(-100) };
    static constexpr int8_t CONNECTION_OK { int8_t(0) };
    static constexpr int8_t CONNECTION_NO_APP { int8_t(1) };
    static constexpr int8_t CONNECTION_NO_ACCEPTOR { int8_t(2) };

public: /* protected */
    Id* myNodeId {  };

private:
    ::rice::environment::Environment* myEnvironment {  };
    ::rice::pastry::messaging::MessageDispatch* myMessageDispatch {  };

public: /* protected */
    ::rice::pastry::leafset::LeafSet* leafSet {  };
    ::rice::pastry::routing::RoutingTable* routeSet {  };
    NodeHandle* localhandle {  };
    ::java::util::Vector* apps {  };
    ::rice::environment::logging::Logger* logger {  };

public: /* package */
    ReadyStrategy* readyStrategy {  };

public: /* protected */
    bool joinFailed_ {  };
    bool isDestroyed {  };
    ::rice::pastry::routing::Router* router {  };
    NodeHandleFactory* handleFactory {  };
    ::rice::pastry::join::JoinProtocol* joiner {  };
    ::rice::pastry::boot::Bootstrapper* bootstrapper {  };
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider {  };
protected:
    void ctor(Id* id, ::rice::environment::Environment* e);

public:
    virtual void boot(::java::lang::Object* o);
    virtual void boot(::java::util::Collection* o2);

public: /* package */
    ReadyStrategy* defaultReadyStrategy {  };

public:
    virtual ReadyStrategy* getDefaultReadyStrategy();
    virtual void setReadyStrategy(ReadyStrategy* rs);
    virtual void setElements(NodeHandle* lh, ::rice::pastry::messaging::MessageDispatch* md, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::routing::Router* router);
    virtual void setJoinProtocols(::rice::pastry::boot::Bootstrapper* boot, ::rice::pastry::join::JoinProtocol* joinP, ::rice::pastry::leafset::LeafSetProtocol* leafsetP, ::rice::pastry::routing::RouteSetProtocol* routeP);
    ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() override;
    ::rice::environment::Environment* getEnvironment() override;
    virtual NodeHandle* getLocalHandle();
    virtual Id* getNodeId();
    virtual bool isReady();
    virtual ::rice::pastry::messaging::MessageDispatch* getMessageDispatch();
    virtual void setMessageDispatch(::rice::pastry::messaging::MessageDispatch* md);
    virtual ::rice::Destructable* addDestructable(::rice::Destructable* d);
    virtual bool removeDestructable(::rice::Destructable* d);
    virtual void nodeIsReady(bool state);
    virtual void setReady();
    virtual void setReady(bool ready);
    NodeHandle* coalesce(NodeHandle* newHandle) override;

private:
    bool neverBeenReady {  };

public:
    virtual void notifyReadyObservers();
    virtual bool isClosest(Id* key);
    virtual ::rice::pastry::leafset::LeafSet* getLeafSet();
    virtual ::rice::pastry::routing::RoutingTable* getRoutingTable();
    virtual void addLeafSetObserver(::java::util::Observer* o);
    virtual void deleteLeafSetObserver(::java::util::Observer* o);
    virtual void addLeafSetListener(NodeSetListener* listener);
    virtual void deleteLeafSetListener(NodeSetListener* listener);
    virtual void addRouteSetObserver(::java::util::Observer* o);
    virtual void deleteRouteSetObserver(::java::util::Observer* o);
    virtual void addRouteSetListener(NodeSetListener* listener);
    virtual void removeRouteSetListener(NodeSetListener* listener);
    virtual void receiveMessage(::rice::pastry::messaging::Message* msg);
    virtual void registerReceiver(int32_t address, ::rice::pastry::client::PastryAppl* receiver);
    virtual void registerApp(::rice::pastry::client::PastryAppl* app);
    ::java::lang::String* toString() override;
    ::rice::p2p::commonapi::Endpoint* registerApplication(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance) override;
    ::rice::p2p::commonapi::Endpoint* buildEndpoint(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance) override;
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::IdFactory* getIdFactory() override;
    virtual void process(::rice::Executable* task, ::rice::Continuation* command);

public: /* package */
    ::java::util::HashSet* destructables {  };

public:
    void destroy() override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* connect(NodeHandle* i, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe, ::rice::pastry::client::PastryAppl* appl, int32_t timeout);

public: /* protected */
    JoinFailedException* joinFailedReason_ {  };

public:
    virtual void joinFailed(JoinFailedException* cje);
    virtual bool joinFailed();
    virtual JoinFailedException* joinFailedReason();
    virtual ::rice::pastry::routing::Router* getRouter();
    ::java::lang::String* printRouteState() override;

public: /* protected */
    int32_t leafSetMaintFreq {  }, routeSetMaintFreq {  };
    ScheduledMessage* leafSetRoutineMaintenance {  };
    ScheduledMessage* routeSetRoutineMaintenance {  };
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider {  };

public:
    virtual void setSocketElements(int32_t lsmf, int32_t rsmf, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider, NodeHandleFactory* handleFactory);

public: /* package */
    ::java::util::Map* vars {  };

public:
    virtual ::java::util::Map* getVars();
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;

public: /* protected */
    virtual void acceptAppSocket(int32_t appId) /* throws(AppSocketException) */;

public:
    virtual int32_t proximity(NodeHandle* nh);
    virtual int32_t proximity(NodeHandle* nh, ::java::util::Map* options);
    virtual ScheduledMessage* scheduleMsg(::rice::pastry::messaging::Message* msg, int64_t delay);
    virtual ScheduledMessage* scheduleMsg(::rice::pastry::messaging::Message* msg, int64_t delay, int64_t period);
    virtual ScheduledMessage* scheduleMsgAtFixedRate(::rice::pastry::messaging::Message* msg, int64_t delay, int64_t period);
    virtual ::rice::pastry::transport::PMessageReceipt* send(NodeHandle* handle, ::rice::pastry::messaging::Message* msg, ::rice::pastry::transport::PMessageNotification* deliverAckToMe, ::java::util::Map* tempOptions);
    virtual void messageReceived(NodeHandle* i, ::rice::p2p::commonapi::rawserialization::RawMessage* m, ::java::util::Map* options) /* throws(IOException) */;
    NodeHandle* readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    virtual ::rice::pastry::boot::Bootstrapper* getBootstrapper();
    virtual void doneNode(::java::util::Collection* bootstrap);
    virtual void livenessChanged(NodeHandle* i, int32_t val, ::java::util::Map* options);

public: /* package */
    ::java::util::Collection* livenessListeners {  };

public:
    void addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    bool removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;

public: /* protected */
    virtual void notifyLivenessListeners(NodeHandle* i, int32_t val, ::java::util::Map* options);

public:
    virtual bool checkLiveness(NodeHandle* i, ::java::util::Map* options);
    virtual int32_t getLiveness(NodeHandle* i, ::java::util::Map* options);
    virtual int32_t getLiveness(NodeHandle* i);
    virtual bool isAlive(NodeHandle* i);
    virtual void proximityChanged(NodeHandle* handle, int32_t val, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::liveness::LivenessProvider* getLivenessProvider();
    virtual ::org::mpisws::p2p::transport::proximity::ProximityProvider* getProxProvider();
    virtual ::org::mpisws::p2p::transport::TransportLayer* getTL();
    virtual void clearState(NodeHandle* i);
    void addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener) override;
    bool removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener) override;
    virtual void nodeIsReady();
    virtual NodeHandleFactory* getHandleFactroy();

private:
    ::java::util::ArrayList* networkListeners {  };

public:
    virtual void addNetworkListener(NetworkListener* listener);
    virtual void removeNetworkListener(NetworkListener* listener);

public: /* protected */
    virtual ::java::lang::Iterable* getNetworkListeners();

public:
    virtual void broadcastChannelClosed(::java::net::InetSocketAddress* addr);
    virtual void broadcastChannelOpened(::java::net::InetSocketAddress* addr, int32_t reason);
    virtual void broadcastSentListeners(int32_t address, int16_t msgType, ::java::net::InetSocketAddress* dest, int32_t size, int32_t wireType);
    virtual void broadcastReceivedListeners(int32_t address, int16_t msgType, ::java::net::InetSocketAddress* from, int32_t size, int32_t wireType);
    void addNodeHandleFactoryListener(NodeHandleFactoryListener* listener) override;
    void removeNodeHandleFactoryListener(NodeHandleFactoryListener* listener) override;

public: /* package */
    NodeHandleFetcher* nodeHandleFetcher {  };

public:
    virtual void setNodeHandleFetcher(NodeHandleFetcher* nodeHandleFetcher);
    virtual void getNodeHandle(::java::lang::Object* o, ::rice::Continuation* c);

    // Generated
    PastryNode(Id* id, ::rice::environment::Environment* e);
protected:
    PastryNode(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual bool checkLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual void clearState(::java::lang::Object* i) override;
    virtual int32_t getLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual void livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options) override;
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual int32_t proximity(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual void proximityChanged(::java::lang::Object* i, int32_t newProximity, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryNode_getDefaultReadyStrategy_1;
    friend class PastryNode_destroy_2;
    friend class PastryNode_connect_3;
    friend class PastryNode_connect_3_run_3_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1;
    friend class PastryNode_incomingSocket_4;
    friend class PastryNode_incomingSocket_4_receiveSelectResult_4_1;
    friend class PastryNode_send_5;
    friend class PastryNode_send_6;
    friend class PastryNode_send_7;
};
