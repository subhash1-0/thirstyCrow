// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/nat/FirewallTLImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/nat/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::nat::FirewallTLImpl
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int32_t UDP_OPEN_MILLIS {  };
    ::java::util::Map* udpTable {  };
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::rice::environment::time::TimeSource* timeSource {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, int32_t udp_open_millis, ::rice::environment::Environment* env);

public:
    ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */ override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;

    // Generated
    FirewallTLImpl(::org::mpisws::p2p::transport::TransportLayer* tl, int32_t udp_open_millis, ::rice::environment::Environment* env);
protected:
    FirewallTLImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
