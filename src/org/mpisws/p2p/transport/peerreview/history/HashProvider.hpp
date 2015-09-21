// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/HashProvider.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct org::mpisws::p2p::transport::peerreview::history::HashProvider
    : public virtual ::java::lang::Object
{
    virtual ::int8_tArray* hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash) = 0;
    virtual ::int8_tArray* hash(::java::nio::ByteBufferArray*/*...*/ hashMe) = 0;
    virtual int16_t getHashSizeBytes() = 0;
    virtual ::int8_tArray* getEmptyHash() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
