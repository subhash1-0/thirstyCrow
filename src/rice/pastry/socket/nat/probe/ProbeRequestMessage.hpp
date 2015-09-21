// Generated from /pastry-2.1/src/rice/pastry/socket/nat/probe/ProbeRequestMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/probe/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::probe::ProbeRequestMessage
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(1) };

public: /* package */
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* probeRequestor {  };
    int64_t uid {  };
protected:
    void ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* probeRequestor, int64_t uid, int32_t appAddress);

public:
    virtual ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* getProbeRequester();
    virtual int64_t getUID();
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static ProbeRequestMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t appAddress) /* throws(IOException) */;

    // Generated
    ProbeRequestMessage(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* probeRequestor, int64_t uid, int32_t appAddress);
protected:
    ProbeRequestMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
