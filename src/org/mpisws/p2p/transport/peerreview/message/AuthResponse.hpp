// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AuthResponse.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::message::AuthResponse
    : public virtual ::java::lang::Object
    , public virtual PeerReviewMessage
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* subject {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo);

public:
    int16_t getType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    AuthResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo);
    AuthResponse(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t signatureSize);
protected:
    AuthResponse(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
