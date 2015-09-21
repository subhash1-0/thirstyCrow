// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/limitsockets/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t MAX_SOCKETS {  };

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::java::util::LinkedHashMap* cache {  };
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::rice::selector::Timer* timer {  };
    ::org::mpisws::p2p::transport::ErrorHandler* handler {  };
protected:
    void ctor(int32_t max_sockets, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::ErrorHandler* handler, ::rice::environment::Environment* env);

public:
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;

public: /* protected */
    virtual LimitSocketsTransportLayer_LSSocket* getLSSock(::org::mpisws::p2p::transport::P2PSocket* sock);
    virtual void closeIfNecessary();

public:
    virtual void touch(LimitSocketsTransportLayer_LSSocket* socket);
    ::java::lang::String* toString() override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */ override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;

    // Generated
    LimitSocketsTransportLayer(int32_t max_sockets, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::ErrorHandler* handler, ::rice::environment::Environment* env);
protected:
    LimitSocketsTransportLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class LimitSocketsTransportLayer_openSocket_1;
    friend class LimitSocketsTransportLayer_openSocket_2;
    friend class LimitSocketsTransportLayer_LSSocket;
    friend class LimitSocketsTransportLayer_LSSocket_forceClose_1;
};
