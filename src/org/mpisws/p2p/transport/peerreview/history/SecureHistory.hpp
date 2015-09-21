// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/SecureHistory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

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

struct org::mpisws::p2p::transport::peerreview::history::SecureHistory
    : public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{
    virtual int64_t getNumEntries() = 0;
    virtual int64_t getBaseSeq() = 0;
    virtual int64_t getLastSeq() = 0;
    virtual HashSeq* getTopLevelEntry() = 0;
    virtual void appendEntry(int16_t type, bool storeFullEntry, ::java::nio::ByteBufferArray*/*...*/ entry) /* throws(IOException) */ = 0;
    virtual void appendHash(int16_t type, ::int8_tArray* hash) /* throws(IOException) */ = 0;
    virtual bool setNextSeq(int64_t nextSeq) = 0;
    virtual void close() /* throws(IOException) */ = 0;
    virtual int64_t findSeq(int64_t seq) /* throws(IOException) */ = 0;
    virtual int64_t findSeqOrHigher(int64_t seq, bool allowHigher) /* throws(IOException) */ = 0;
    virtual ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* serializeRange(int64_t idxFrom, int64_t idxTo, HashPolicy* hashPolicy) /* throws(IOException) */ = 0;
    virtual IndexEntry* statEntry(int64_t idx) /* throws(IOException) */ = 0;
    virtual ::int8_tArray* getEntry(int64_t idx, int32_t maxSizeToRead) /* throws(IOException) */ = 0;
    virtual ::int8_tArray* getEntry(IndexEntry* ie, int32_t maxSizeToRead) /* throws(IOException) */ = 0;
    virtual bool upgradeHashedEntry(int32_t idx, ::java::nio::ByteBuffer* entry) /* throws(IOException) */ = 0;
    virtual int64_t findLastEntry(::int16_tArray* types, int64_t maxSeq) /* throws(IOException) */ = 0;
    virtual void appendSnippetToHistory(::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
