// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/ConnectorExceptionDelivery.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/direct/Delivery.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::direct::ConnectorExceptionDelivery
    : public virtual ::java::lang::Object
    , public virtual Delivery
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::io::IOException* e {  };
    ::org::mpisws::p2p::transport::SocketCallback* connectorReceiver {  };
    ::org::mpisws::p2p::transport::SocketRequestHandle* connectorHandle {  };
protected:
    void ctor(::org::mpisws::p2p::transport::SocketCallback* connectorReceiver, ::org::mpisws::p2p::transport::SocketRequestHandle* connectorHandle, ::java::io::IOException* e);

public:
    void deliver() override;
    int32_t getSeq() override;

    // Generated
    ConnectorExceptionDelivery(::org::mpisws::p2p::transport::SocketCallback* connectorReceiver, ::org::mpisws::p2p::transport::SocketRequestHandle* connectorHandle, ::java::io::IOException* e);
protected:
    ConnectorExceptionDelivery(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
