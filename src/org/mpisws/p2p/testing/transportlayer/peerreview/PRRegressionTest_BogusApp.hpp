// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewCallback
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
    PRRegressionTest_Player* player {  };
    ::rice::environment::Environment* env {  };
    ::java::util::Random* rand {  };
    int64_t nextSendTime {  };

private:
    PRRegressionTest_HandleImpl* dest {  };
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
protected:
    void ctor(PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env);

public:
    void init_() override;
    virtual void scheduleMessageToBeSent();
    virtual void scheduleMessageToBeSent(int64_t time, bool reschedule);
    virtual void sendMessage();

public: /* protected */
    virtual ::int8_tArray* generateMessage();

public:
    void storeCheckpoint(::rice::p2p::commonapi::rawserialization::OutputBuffer* buffer) /* throws(IOException) */ override;
    bool loadCheckpoint(::rice::p2p::commonapi::rawserialization::InputBuffer* buffer) /* throws(IOException) */ override;
    void destroy() override;
    virtual void notifyCertificateAvailable(PRRegressionTest_IdImpl* id);
    virtual void receive(PRRegressionTest_HandleImpl* source, bool datagram, ::java::nio::ByteBuffer* msg);
    virtual void sendComplete(int64_t id);
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual void messageReceived(PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    virtual void getWitnesses(PRRegressionTest_IdImpl* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback);
    virtual void notifyStatusChange(PRRegressionTest_IdImpl* id, int32_t newStatus);
    ::java::util::Collection* getMyWitnessedNodes() override;
    ::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* getReplayInstance(::org::mpisws::p2p::transport::peerreview::replay::Verifier* v) override;

    // Generated
    PRRegressionTest_BogusApp(PRRegressionTest *PRRegressionTest_this, PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env);
protected:
    PRRegressionTest_BogusApp(PRRegressionTest *PRRegressionTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void getWitnesses(::java::lang::Object* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback) override;
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual void notifyCertificateAvailable(::java::lang::Object* id) override;
    virtual void notifyStatusChange(::java::lang::Object* id, int32_t newStatus) override;
    PRRegressionTest *PRRegressionTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRRegressionTest;
    friend class PRRegressionTest_IdExtractor;
    friend class PRRegressionTest_HandleSerializer;
    friend class PRRegressionTest_IdSerializer;
    friend class PRRegressionTest_HandleImpl;
    friend class PRRegressionTest_IdImpl;
    friend class PRRegressionTest_BogusTransport;
    friend class PRRegressionTest_BogusTransport_receiveMessage_1;
    friend class PRRegressionTest_BogusApp_scheduleMessageToBeSent_1;
    friend class PRRegressionTest_BogusApp_sendMessage_2;
    friend class PRRegressionTest_Player;
    friend class PRRegressionTest_Player_Player_1;
    friend class PRRegressionTest_Player_getIdTransport_2;
    friend class PRRegressionTest_getIdStrTranslator_1;
    friend class PRRegressionTest_MyIdTL;
    friend class PRRegressionTest_MyIdTL_requestCertificate_1;
    friend class PRRegressionTest_PRRegressionTest_2;
    friend class PRRegressionTest_PRRegressionTest_3;
};
