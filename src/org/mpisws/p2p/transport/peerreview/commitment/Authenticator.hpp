// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/Authenticator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::commitment::Authenticator
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

private:
    int64_t seq {  };
    ::int8_tArray* hash {  };
    ::int8_tArray* signature {  };

public: /* package */
    int32_t hashCode_ {  };
protected:
    void ctor(int64_t seq, ::int8_tArray* hash, ::int8_tArray* signature);

public:
    virtual ::java::nio::ByteBuffer* getPartToHashThenSign();
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */;

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    int32_t hashCode() override;
    bool equals(::java::lang::Object* o) override;
    virtual int32_t compareTo(Authenticator* that);
    virtual int64_t getSeq();
    ::java::lang::String* toString() override;
    virtual ::int8_tArray* getHash();
    virtual ::int8_tArray* getSignature();

    // Generated
    Authenticator(int64_t seq, ::int8_tArray* hash, ::int8_tArray* signature);
    Authenticator(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize);
protected:
    Authenticator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
};
