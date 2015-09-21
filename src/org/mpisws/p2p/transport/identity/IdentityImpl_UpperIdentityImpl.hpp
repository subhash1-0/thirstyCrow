// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/identity/UpperIdentity.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl
    : public virtual ::java::lang::Object
    , public virtual UpperIdentity
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessListener
    , public virtual ::org::mpisws::p2p::transport::proximity::ProximityListener
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox {  };

private:
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };

public: /* package */
    ::rice::environment::logging::Logger* logger {  };

private:
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider {  };
    ::java::lang::Object* localIdentifier {  };
protected:
    void ctor(::java::lang::Object* local, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* live, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox);

public:
    void clearState(::java::lang::Object* i) override;
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */ override;
    bool checkLiveness(::java::lang::Object* i, ::java::util::Map* options) override;

public: /* package */
    ::java::util::List* livenessListeners {  };

public:
    void addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    bool removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    int32_t getLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    void livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options) override;

public: /* protected */
    virtual void setLiveness(::java::lang::Object* i, int32_t val, ::java::util::Map* options);
    ::java::util::Map* liveness {  };
    virtual void notifyLivenessListeners(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options);

public: /* package */
    ::java::util::Collection* proxListeners {  };

public:
    void addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* name) override;
    bool removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* name) override;
    int32_t proximity(::java::lang::Object* i, ::java::util::Map* options) override;
    void proximityChanged(::java::lang::Object* i, int32_t newProx, ::java::util::Map* options) override;

private:
    void notifyProximityListeners(::java::lang::Object* i, int32_t newProx, ::java::util::Map* options);

public:
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;

    // Generated
    IdentityImpl_UpperIdentityImpl(IdentityImpl *IdentityImpl_this, ::java::lang::Object* local, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* live, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox);
protected:
    IdentityImpl_UpperIdentityImpl(IdentityImpl *IdentityImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    IdentityImpl *IdentityImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class IdentityImpl;
    friend class IdentityImpl_IdentityImpl_1;
    friend class IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1;
    friend class IdentityImpl_LowerIdentityImpl;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_1;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1_receiveSelectResult_1_2_1_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1;
    friend class IdentityImpl_LowerIdentityImpl_sendMessage_3;
    friend class IdentityImpl_UpperIdentityImpl_openSocket_1;
    friend class IdentityImpl_IdentityMessageHandle;
};
