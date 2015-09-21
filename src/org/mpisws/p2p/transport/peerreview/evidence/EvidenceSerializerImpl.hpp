// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceSerializerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceSerializer.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::evidence::EvidenceSerializerImpl
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int32_t hashSize {  };
    int32_t signatureSize {  };
    ::org::mpisws::p2p::transport::util::Serializer* handleSerializer {  };
    ::org::mpisws::p2p::transport::util::Serializer* idSerializer {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl* authSerializer {  };
protected:
    void ctor(::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize);

public:
    ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int8_t type, bool response) /* throws(IOException) */ override;

    // Generated
    EvidenceSerializerImpl(::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize);
protected:
    EvidenceSerializerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
