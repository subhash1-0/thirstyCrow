// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLSocketManager.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/net/ssl/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/ssl/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::ssl::SSLSocketManager
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocket
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::security::cert::X509Certificate* peerCert {  };
    ::org::mpisws::p2p::transport::P2PSocket* socket {  };
    ::javax::net::ssl::SSLEngine* engine {  };
    SSLTransportLayerImpl* sslTL {  };
    ::rice::environment::logging::Logger* logger {  };
    bool handshaking {  };
    bool closed {  };
    ::javax::net::ssl::SSLEngineResult* result {  };
    ::javax::net::ssl::SSLEngineResult_HandshakeStatus* status {  };
    ::java::util::LinkedList* writeMe {  };
    ::java::util::LinkedList* unwrapMe {  };
    ::java::util::LinkedList* readMe {  };
    ::java::nio::ByteBuffer* bogusEncryptMe {  };
    int32_t appBufferMax {  };
    int32_t netBufferMax {  };
    ::rice::Continuation* c {  };
    bool doneHandshaking {  };
    ::java::util::Map* options {  };
    bool useClientAuth {  };
    bool server {  };
    ::java::lang::String* name {  };
protected:
    void ctor(SSLTransportLayerImpl* sslTL, ::org::mpisws::p2p::transport::P2PSocket* s, ::rice::Continuation* c, bool server, bool useClientAuth);

public:
    ::java::lang::String* toString() override;

public: /* protected */
    virtual void handleResult(::javax::net::ssl::SSLEngineResult* result);

public: /* package */
    bool handshakeFail {  };

public:
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;

public: /* protected */
    virtual bool read() /* throws(IOException) */;
    virtual void handshakeWrap();
    virtual void unwrap() /* throws(SSLException) */;
    virtual void handshakeUnwrap();
    virtual void fail(::java::lang::Exception* e);
    virtual void continueHandshaking();
    virtual bool checkDone();

public:
    virtual ::java::security::cert::X509Certificate* getCert();

public: /* package */
    bool runningTaskLock {  };

private:
    void runDelegatedTasks();
    static bool isEngineClosed(::javax::net::ssl::SSLEngine* engine);

public:
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;

public: /* package */
    ::org::mpisws::p2p::transport::P2PSocketReceiver* registeredToRead {  };
    ::org::mpisws::p2p::transport::P2PSocketReceiver* registeredToWrite {  };

public:
    int64_t read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */ override;
    int64_t write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ override;
    void close() override;
    ::java::lang::Object* getIdentifier() override;
    ::java::util::Map* getOptions() override;
    void shutdownOutput() override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;

    // Generated
    SSLSocketManager(SSLTransportLayerImpl* sslTL, ::org::mpisws::p2p::transport::P2PSocket* s, ::rice::Continuation* c, bool server, bool useClientAuth);
protected:
    SSLSocketManager(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class SSLSocketManager_runDelegatedTasks_1;
    friend class SSLSocketManager_runDelegatedTasks_2;
};
