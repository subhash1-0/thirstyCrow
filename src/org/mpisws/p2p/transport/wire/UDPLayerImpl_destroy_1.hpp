// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/UDPLayerImpl.java

#pragma once

#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::UDPLayerImpl_destroy_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    UDPLayerImpl_destroy_1(UDPLayerImpl *UDPLayerImpl_this);
    static ::java::lang::Class *class_();
    UDPLayerImpl *UDPLayerImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class UDPLayerImpl;
    friend class UDPLayerImpl_Envelope;
    friend class UDPLayerImpl_acceptMessages_2;
};
