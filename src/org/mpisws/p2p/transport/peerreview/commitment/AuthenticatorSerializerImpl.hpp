// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl
    : public virtual ::java::lang::Object
    , public virtual AuthenticatorSerializer
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t hashLength {  };
    int32_t signatureLength {  };
protected:
    void ctor(int32_t hashLength, int32_t signatureLength);

public:
    Authenticator* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    int32_t getSerializedSize() override;

    // Generated
    AuthenticatorSerializerImpl(int32_t hashLength, int32_t signatureLength);
protected:
    AuthenticatorSerializerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
