// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::direct::DirectAppSocket
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::int8_tArray* EOF__;
    static constexpr int32_t MAX_BYTES_IN_FLIGHT { int32_t(10000) };

public: /* package */
    ::java::lang::Object* acceptor {  };
    ::java::lang::Object* connector {  };
    ::org::mpisws::p2p::transport::SocketCallback* connectorReceiver {  };
    GenericNetworkSimulator* simulator {  };
    DirectAppSocket_DirectAppSocketEndpoint* acceptorEndpoint {  };
    DirectAppSocket_DirectAppSocketEndpoint* connectorEndpoint {  };
    ::org::mpisws::p2p::transport::SocketRequestHandle* connectorHandle {  };
    ::rice::environment::logging::Logger* acceptorLogger {  };
    ::rice::environment::logging::Logger* connectorLogger {  };
    ::java::util::Map* options {  };
protected:
    void ctor(::java::lang::Object* acceptor, ::java::lang::Object* connector, ::org::mpisws::p2p::transport::SocketCallback* connectorCallback, GenericNetworkSimulator* simulator, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::java::util::Map* options);

public:
    virtual Delivery* getAcceptorDelivery();
    ::java::lang::String* toString() override;

    // Generated
    DirectAppSocket(::java::lang::Object* acceptor, ::java::lang::Object* connector, ::org::mpisws::p2p::transport::SocketCallback* connectorCallback, GenericNetworkSimulator* simulator, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::java::util::Map* options);
protected:
    DirectAppSocket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::int8_tArray*& EOF_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class DirectAppSocket_DirectAppSocketEndpoint;
    friend class DirectAppSocket_DirectAppSocketEndpoint_read_1;
    friend class DirectAppSocket_DirectAppSocketEndpoint_write_2;
    friend class DirectAppSocket_DirectAppSocketEndpoint_register_3;
    friend class DirectAppSocket_DirectAppSocketEndpoint_register_4;
    friend class DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5;
    friend class DirectAppSocket_AcceptorDelivery;
    friend class DirectAppSocket_ConnectorDelivery;
};
