// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::util::Map* peerTable_;

public: /* package */
    PRRegressionTest_HandleImpl* localIdentifier {  };
    ::rice::environment::Environment* env {  };
protected:
    void ctor(PRRegressionTest_HandleImpl* handle, ::java::security::cert::X509Certificate* cert, ::rice::environment::Environment* env);

public:
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    PRRegressionTest_HandleImpl* getLocalIdentifier() override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(PRRegressionTest_HandleImpl* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);

public: /* package */
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };

private:
    void receiveMessage(PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m);

public:
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;

    // Generated
    PRRegressionTest_BogusTransport(PRRegressionTest_HandleImpl* handle, ::java::security::cert::X509Certificate* cert, ::rice::environment::Environment* env);
protected:
    PRRegressionTest_BogusTransport(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    static ::java::util::Map*& peerTable();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRRegressionTest;
    friend class PRRegressionTest_IdExtractor;
    friend class PRRegressionTest_HandleSerializer;
    friend class PRRegressionTest_IdSerializer;
    friend class PRRegressionTest_HandleImpl;
    friend class PRRegressionTest_IdImpl;
    friend class PRRegressionTest_BogusTransport_receiveMessage_1;
    friend class PRRegressionTest_BogusApp;
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
