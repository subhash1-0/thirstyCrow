// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/ListenableTransportLayer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
    , public virtual ::org::mpisws::p2p::transport::ListenableTransportLayer
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::Environment* environment {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    ::org::mpisws::p2p::transport::TransportLayer* wire {  };

public:
    ::int8_tArray* HEADER {  };
    int32_t SOCKET_TIMEOUT {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::int8_tArray* header, int32_t timeOut);

public:
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    void destroy() override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;

public: /* package */
    ::java::util::ArrayList* listeners {  };

public:
    void addTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener) override;
    void removeTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener) override;
    virtual void notifyListenersRead(int32_t bytesRead, ::java::lang::Object* identifier, ::java::util::Map* options, bool passthrough, bool socket);
    virtual void notifyListenersWrite(int32_t bytesRead, ::java::lang::Object* identifier, ::java::util::Map* options, bool passthrough, bool socket);

    // Generated
    MagicNumberTransportLayer(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::int8_tArray* header, int32_t timeOut);
protected:
    MagicNumberTransportLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MagicNumberTransportLayer_openSocket_1;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_1;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_2;
    friend class MagicNumberTransportLayer_sendMessage_2;
    friend class MagicNumberTransportLayer_VerifyHeaderReceiver;
};
