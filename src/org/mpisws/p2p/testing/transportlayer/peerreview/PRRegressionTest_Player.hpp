// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
    PRRegressionTest_HandleImpl* localHandle {  };
    ::org::mpisws::p2p::transport::peerreview::PeerReview* pr {  };
    PRRegressionTest_MyIdTL* transport {  };

public:
    ::java::util::Collection* witnessed {  };

public: /* package */
    ::java::security::KeyPair* pair {  };
    ::java::security::cert::X509Certificate* cert {  };
    PRRegressionTest_BogusTransport* t1 {  };
    ::rice::environment::Environment* env {  };
    PRRegressionTest_BogusApp* app {  };
    PRRegressionTest_HandleImpl* destHandle {  };
protected:
    void ctor(PRRegressionTest_HandleImpl* localHandle, PRRegressionTest_HandleImpl* dstHandle, ::rice::environment::Environment* env2) /* throws(Exception) */;

public:
    virtual PRRegressionTest_BogusApp* getApp();
    virtual ::rice::environment::Environment* cloneEnvironment(::rice::environment::Environment* env2, ::java::lang::String* name, int32_t id);
    virtual void buildPlayerCryptoStuff();
    virtual PRRegressionTest_BogusTransport* getTL() /* throws(Exception) */;
    virtual PRRegressionTest_MyIdTL* getIdTransport() /* throws(Exception) */;

    // Generated
    PRRegressionTest_Player(PRRegressionTest *PRRegressionTest_this, PRRegressionTest_HandleImpl* localHandle, PRRegressionTest_HandleImpl* dstHandle, ::rice::environment::Environment* env2);
protected:
    PRRegressionTest_Player(PRRegressionTest *PRRegressionTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    PRRegressionTest *PRRegressionTest_this;
    virtual ::java::lang::Class* getClass0();
    friend class PRRegressionTest;
    friend class PRRegressionTest_IdExtractor;
    friend class PRRegressionTest_HandleSerializer;
    friend class PRRegressionTest_IdSerializer;
    friend class PRRegressionTest_HandleImpl;
    friend class PRRegressionTest_IdImpl;
    friend class PRRegressionTest_BogusTransport;
    friend class PRRegressionTest_BogusTransport_receiveMessage_1;
    friend class PRRegressionTest_BogusApp;
    friend class PRRegressionTest_BogusApp_scheduleMessageToBeSent_1;
    friend class PRRegressionTest_BogusApp_sendMessage_2;
    friend class PRRegressionTest_Player_Player_1;
    friend class PRRegressionTest_Player_getIdTransport_2;
    friend class PRRegressionTest_getIdStrTranslator_1;
    friend class PRRegressionTest_MyIdTL;
    friend class PRRegressionTest_MyIdTL_requestCertificate_1;
    friend class PRRegressionTest_PRRegressionTest_2;
    friend class PRRegressionTest_PRRegressionTest_3;
};
