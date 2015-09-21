// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/RC4TransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rc4/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rc4::RC4TransportLayer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::rice::environment::Environment* env {  };
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    ::java::security::MessageDigest* md {  };

public:
    static constexpr int32_t KEY_LENGTH { int32_t(16) };

public: /* package */
    ::int8_tArray* password {  };
    int32_t PW_SEED_LENGTH {  };
    int32_t WRITE_BUFFER_SIZE {  };
    ::rice::environment::random::RandomSource* random {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::java::lang::String* password, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler) /* throws(NoSuchAlgorithmException) */;
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::java::lang::String* password, int32_t pwSeedLength, ::rice::environment::random::RandomSource* random, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler) /* throws(NoSuchAlgorithmException) */;

public:
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */ override;

private:
    static ::java::lang::String* ALGORITHM_;

    // Generated

public:
    RC4TransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::java::lang::String* password, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler);
    RC4TransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::java::lang::String* password, int32_t pwSeedLength, ::rice::environment::random::RandomSource* random, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler);
protected:
    RC4TransportLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();
    static ::java::lang::String*& ALGORITHM();
    virtual ::java::lang::Class* getClass0();
    friend class RC4TransportLayer_openSocket_1;
    friend class RC4TransportLayer_openSocket_1_receiveResult_1_1;
    friend class RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1;
    friend class RC4TransportLayer_incomingSocket_2;
    friend class RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1;
};
