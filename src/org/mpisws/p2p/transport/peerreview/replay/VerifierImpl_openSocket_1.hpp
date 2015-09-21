// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/VerifierImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::VerifierImpl_openSocket_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketRequestHandle
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* getIdentifier() override;
    ::java::util::Map* getOptions() override;
    bool cancel() override;

    // Generated
    VerifierImpl_openSocket_1(VerifierImpl *VerifierImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* i, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    VerifierImpl *VerifierImpl_this;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* i;
    ::java::util::Map* options;

private:
    virtual ::java::lang::Class* getClass0();
    friend class VerifierImpl;
};
