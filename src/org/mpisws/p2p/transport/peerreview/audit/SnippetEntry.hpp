// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/SnippetEntry.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::audit::SnippetEntry
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    int8_t type {  };
    int64_t seq {  };
    bool isHash {  };
    ::int8_tArray* content {  };
    static constexpr int32_t NUM_INDEXES { int32_t(1000000) };
protected:
    void ctor(int8_t type, int64_t seq, bool isHash, ::int8_tArray* content);
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, SnippetEntry* prev) /* throws(IOException) */;

public:
    bool equals(::java::lang::Object* o) override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int64_t seq, int32_t hashSize) /* throws(IOException) */;

public:
    ::java::lang::String* toString() override;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, SnippetEntry* prev) /* throws(IOException) */;

public: /* protected */
    static int64_t decodeSeq(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int64_t prevSeq) /* throws(IOException) */;
    virtual void encodeSeq(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, int64_t prevSeq) /* throws(IOException) */;

public:
    virtual int8_t getSizeCode();
    virtual void encodeSize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    virtual int32_t decodeSize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

    // Generated
    SnippetEntry(int8_t type, int64_t seq, bool isHash, ::int8_tArray* content);
    SnippetEntry(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, SnippetEntry* prev);
    SnippetEntry(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int64_t seq, int32_t hashSize);
protected:
    SnippetEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
