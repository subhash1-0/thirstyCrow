// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/EvidenceToolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl_SendEntryRecord
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int64_t seq {  };
    ::java::nio::ByteBuffer* hashedPlusPayload {  };
protected:
    void ctor(int64_t seq, ::java::nio::ByteBuffer* hashedPlusPayload);

    // Generated

public:
    EvidenceToolImpl_SendEntryRecord(int64_t seq, ::java::nio::ByteBuffer* hashedPlusPayload);
protected:
    EvidenceToolImpl_SendEntryRecord(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class EvidenceToolImpl;
};
