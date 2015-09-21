// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/SecureHistoryImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl
    : public virtual ::java::lang::Object
    , public virtual SecureHistory
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
    HashProvider* hashProv {  };
    bool pointerAtEnd {  };
    IndexEntry* topEntry {  };
    int64_t baseSeq {  };
    int64_t nextSeq {  };
    int64_t numEntries {  };
    ::rice::p2p::util::RandomAccessFileIOBuffer* indexFile {  };
    ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile {  };
    bool readOnly {  };
    IndexEntryFactory* indexFactory {  };
protected:
    void ctor(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, HashProvider* hashProv, IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger) /* throws(IOException) */;

public:
    int64_t getBaseSeq() override;
    int64_t getLastSeq() override;
    int64_t getNumEntries() override;
    HashSeq* getTopLevelEntry() override;
    void appendEntry(int16_t type, bool storeFullEntry, ::java::nio::ByteBufferArray*/*...*/ entry) /* throws(IOException) */ override;
    void appendHash(int16_t type, ::int8_tArray* hash) /* throws(IOException) */ override;
    bool setNextSeq(int64_t nextSeq) override;
    void close() /* throws(IOException) */ override;
    int64_t findSeq(int64_t seq) /* throws(IOException) */ override;
    int64_t findSeqOrHigher(int64_t seq, bool allowHigher) /* throws(IOException) */ override;
    ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* serializeRange(int64_t idxFrom, int64_t idxTo, HashPolicy* hashPolicy) /* throws(IOException) */ override;
    virtual bool serializeRange2(int64_t idxFrom, int64_t idxTo, HashPolicy* hashPolicy, ::rice::p2p::commonapi::rawserialization::OutputBuffer* outfile) /* throws(IOException) */;
    IndexEntry* statEntry(int64_t idx) /* throws(IOException) */ override;
    ::int8_tArray* getEntry(int64_t idx, int32_t maxSizeToRead) /* throws(IOException) */ override;
    ::int8_tArray* getEntry(IndexEntry* ie, int32_t maxSizeToRead) /* throws(IOException) */ override;
    bool upgradeHashedEntry(int32_t idx, ::java::nio::ByteBuffer* entry) /* throws(IOException) */ override;
    int64_t findLastEntry(::int16_tArray* types, int64_t maxSeq) /* throws(IOException) */ override;
    void appendSnippetToHistory(::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet) /* throws(IOException) */ override;

    // Generated
    SecureHistoryImpl(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, HashProvider* hashProv, IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger);
protected:
    SecureHistoryImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
