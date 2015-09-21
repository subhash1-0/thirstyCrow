// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/pki/x509/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::int8_tArray* EMPTY_ARRAY_;
    static ::java::util::Map* idTLTable_;

public: /* package */
    ::org::mpisws::p2p::pki::x509::CATool* caTool {  };
    ::java::security::KeyPairGenerator* keyPairGen {  };
    ::java::util::Map* playerTable {  };

public: /* protected */
    virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewImpl* getPeerReview(PRRegressionTest_Player* player, PRRegressionTest_MyIdTL* transport, ::rice::environment::Environment* env);

public:
    virtual ::org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator* getIdStrTranslator();

private:
    ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* historyFactory {  };

public: /* package */
    PRRegressionTest_Player* alice {  };
    PRRegressionTest_Player* bob {  };
    PRRegressionTest_Player* carol {  };
    PRRegressionTest_HandleImpl* aliceHandle {  };
    PRRegressionTest_HandleImpl* bobHandle {  };
    PRRegressionTest_HandleImpl* carolHandle {  };

public:
    virtual void setLoggingParams(::rice::environment::Environment* env);

public: /* protected */
    virtual PRRegressionTest_BogusApp* getBogusApp(PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::peerreview::PeerReview* pr, ::rice::environment::Environment* env);

public:
    virtual void buildCryptoMaterial(::rice::environment::Environment* env) /* throws(Exception) */;
    virtual void buildPlayers(::rice::environment::Environment* env) /* throws(Exception) */;
    virtual void setupWitnesses();

public: /* protected */
    ::java::util::Map* recordedStatus {  };
    virtual void addStatusNotification(PRRegressionTest_HandleImpl* localHandle, PRRegressionTest_IdImpl* id, int32_t newStatus);

public:
    virtual void finish();

public: /* package */
    ::rice::environment::Environment* env {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(int32_t millisToFinish) /* throws(Exception) */;

public:
    static void main(::java::lang::StringArray* agrs) /* throws(Exception) */;

    // Generated
    PRRegressionTest(int32_t millisToFinish);
protected:
    PRRegressionTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static ::int8_tArray*& EMPTY_ARRAY();

public: /* package */
    static ::java::util::Map*& idTLTable();

private:
    virtual ::java::lang::Class* getClass0();
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
    friend class PRRegressionTest_Player;
    friend class PRRegressionTest_Player_Player_1;
    friend class PRRegressionTest_Player_getIdTransport_2;
    friend class PRRegressionTest_getIdStrTranslator_1;
    friend class PRRegressionTest_MyIdTL;
    friend class PRRegressionTest_MyIdTL_requestCertificate_1;
    friend class PRRegressionTest_PRRegressionTest_2;
    friend class PRRegressionTest_PRRegressionTest_3;
};
