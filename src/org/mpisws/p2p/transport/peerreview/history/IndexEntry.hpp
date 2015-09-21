// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/IndexEntry.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::IndexEntry
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int64_t seq {  };
    int64_t fileIndex {  };
    int32_t sizeInFile {  };
    int16_t type {  };
    ::int8_tArray* contentHash {  };
    ::int8_tArray* nodeHash {  };
protected:
    void ctor(int64_t seq);
    void ctor(int64_t seq, int64_t index, int16_t type, int32_t size, ::int8_tArray* contentHash, ::int8_tArray* nodeHash);

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    virtual ::int8_tArray* getContentHash();
    virtual int64_t getFileIndex();
    virtual ::int8_tArray* getNodeHash();
    virtual int64_t getSeq();
    virtual int32_t getSizeInFile();
    virtual int16_t getType();
    ::java::lang::String* toString() override;
    virtual bool isHashed();

    // Generated
    IndexEntry(int64_t seq);
    IndexEntry(int64_t seq, int64_t index, int16_t type, int32_t size, ::int8_tArray* contentHash, ::int8_tArray* nodeHash);
protected:
    IndexEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
