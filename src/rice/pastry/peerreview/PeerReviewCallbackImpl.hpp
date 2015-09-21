// Generated from /pastry-2.1/src/rice/pastry/peerreview/PeerReviewCallbackImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/peerreview/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>

struct default_init_tag;

class rice::pastry::peerreview::PeerReviewCallbackImpl
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewCallback
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    CallbackFactory* nodeFactory {  };
    ::rice::pastry::PastryNode* pn {  };
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    FetchLeafsetApp* fetchLeafSetApp {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, CallbackFactory* nodeFactory);
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl);

public:
    ::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* getReplayInstance(::org::mpisws::p2p::transport::peerreview::replay::Verifier* v) override;
    void storeCheckpoint(::rice::p2p::commonapi::rawserialization::OutputBuffer* buffer) /* throws(IOException) */ override;
    bool loadCheckpoint(::rice::p2p::commonapi::rawserialization::InputBuffer* buffer) /* throws(IOException) */ override;
    ::java::util::Collection* getMyWitnessedNodes() override;
    void init_() override;
    void destroy() override;
    virtual void notifyCertificateAvailable(::rice::pastry::Id* id);
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual void messageReceived(::rice::pastry::socket::TransportLayerNodeHandle* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    virtual void notifyStatusChange(::rice::pastry::Id* id, int32_t newStatus);
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    virtual void getWitnesses(::rice::pastry::Id* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback);
    ::rice::pastry::socket::TransportLayerNodeHandle* getLocalIdentifier() override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::rice::pastry::socket::TransportLayerNodeHandle* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::rice::pastry::socket::TransportLayerNodeHandle* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);

    // Generated
    PeerReviewCallbackImpl(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, CallbackFactory* nodeFactory);

public: /* protected */
    PeerReviewCallbackImpl(::org::mpisws::p2p::transport::TransportLayer* tl);
protected:
    PeerReviewCallbackImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void getWitnesses(::java::lang::Object* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback) override;
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual void notifyCertificateAvailable(::java::lang::Object* id) override;
    virtual void notifyStatusChange(::java::lang::Object* id, int32_t newStatus) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeerReviewCallbackImpl_getWitnesses_1;
};
