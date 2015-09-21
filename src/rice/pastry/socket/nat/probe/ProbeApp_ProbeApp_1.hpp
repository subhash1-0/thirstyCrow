// Generated from /pastry-2.1/src/rice/pastry/socket/nat/probe/ProbeApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/probe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::probe::ProbeApp_ProbeApp_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    ProbeApp_ProbeApp_1(ProbeApp *ProbeApp_this);
    static ::java::lang::Class *class_();
    ProbeApp *ProbeApp_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProbeApp;
    friend class ProbeApp_requestProbe_2;
};
