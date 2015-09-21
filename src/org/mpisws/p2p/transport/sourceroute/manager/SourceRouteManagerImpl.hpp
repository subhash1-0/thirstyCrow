// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManager.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl
    : public virtual ::java::lang::Object
    , public virtual SourceRouteManager
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessListener
    , public virtual ::org::mpisws::p2p::transport::proximity::ProximityListener
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t DEFAULT_PROXIMITY { int32_t(3600000) };
    int64_t PING_THROTTLE {  };
    int32_t NUM_SOURCE_ROUTE_ATTEMPTS {  };
    int32_t CHECK_LIVENESS_THROTTLE {  };

public: /* package */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider {  };
    ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider {  };
    SourceRouteStrategy* strategy {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
    ::java::lang::Object* localAddress {  };
    ::java::util::Map* addressManagers {  };

private:
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };

public: /* package */
    ::java::util::Set* hardLinks {  };
    ::java::util::List* livenessListeners {  };
    ::java::util::List* pingListeners {  };
    ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory {  };
protected:
    void ctor(::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider, ::rice::environment::Environment* env, SourceRouteStrategy* strategy);

public:
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);

public: /* protected */
    virtual SourceRouteManagerImpl_AddressManager* getAddressManager(::java::lang::Object* address);

public:
    void clearState(::java::lang::Object* i) override;
    virtual void addHardLink(SourceRouteManagerImpl_AddressManager* am);
    virtual void removeHardLink(SourceRouteManagerImpl_AddressManager* am);
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    bool checkLiveness(::java::lang::Object* address, ::java::util::Map* options) override;
    int32_t getLiveness(::java::lang::Object* address, ::java::util::Map* options) override;
    int32_t proximity(::java::lang::Object* address, ::java::util::Map* options) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    void addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    bool removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;

private:
    void notifyLivenessListeners(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options);

public:
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual void messageReceived(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    virtual void livenessChanged(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t val, ::java::util::Map* options);

public: /* package */
    ::java::util::Collection* listeners {  };

public:
    void addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener) override;
    bool removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener) override;
    virtual void proximityChanged(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t newProximity, ::java::util::Map* options);
    virtual void notifyProximityListeners(::java::lang::Object* i, int32_t prox, ::java::util::Map* options);

    // Generated
    SourceRouteManagerImpl(::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider, ::rice::environment::Environment* env, SourceRouteStrategy* strategy);
protected:
    SourceRouteManagerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options) override;
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual void proximityChanged(::java::lang::Object* i, int32_t newProximity, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SourceRouteManagerImpl_AddressManager;
    friend class SourceRouteManagerImpl_AddressManager_PendingSocket;
    friend class SourceRouteManagerImpl_AddressManager_PendingMessage;
    friend class SourceRouteManagerImpl_AddressManager_sendMessage_1;
    friend class SourceRouteManagerImpl_AddressManager_openSocket_2;
};
