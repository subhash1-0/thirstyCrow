// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/direct/Delivery.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_write_2
    : public virtual ::java::lang::Object
    , public virtual Delivery
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t mySeq {  };

public:
    void deliver() override;
    int32_t getSeq() override;
    ::java::lang::String* toString() override;

    // Generated
    DirectAppSocket_DirectAppSocketEndpoint_write_2(DirectAppSocket_DirectAppSocketEndpoint *DirectAppSocket_DirectAppSocketEndpoint_this, ::int8_tArray* msg);
    static ::java::lang::Class *class_();

private:
    void init();
    DirectAppSocket_DirectAppSocketEndpoint *DirectAppSocket_DirectAppSocketEndpoint_this;
    ::int8_tArray* msg;
    virtual ::java::lang::Class* getClass0();
    friend class DirectAppSocket;
    friend class DirectAppSocket_DirectAppSocketEndpoint;
    friend class DirectAppSocket_DirectAppSocketEndpoint_read_1;
    friend class DirectAppSocket_DirectAppSocketEndpoint_register_3;
    friend class DirectAppSocket_DirectAppSocketEndpoint_register_4;
    friend class DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5;
    friend class DirectAppSocket_AcceptorDelivery;
    friend class DirectAppSocket_ConnectorDelivery;
};
