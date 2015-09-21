// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/stub/NullHashProvider.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/stub/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>

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

class org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::history::HashProvider
{

public:
    typedef ::java::lang::Object super;

private:
    static ::int8_tArray* EMPTY_HASH_;

public:
    ::int8_tArray* hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash) override;
    ::int8_tArray* hash(::java::nio::ByteBufferArray*/*...*/ hashMe) override;
    virtual ::int8_tArray* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
    ::int8_tArray* getEmptyHash() override;
    int16_t getHashSizeBytes() override;
    virtual ::int8_tArray* build(::int8_tArray* hashBytes, int32_t start, int32_t length);

    // Generated
    NullHashProvider();
protected:
    NullHashProvider(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::int8_tArray*& EMPTY_HASH();

private:
    virtual ::java::lang::Class* getClass0();
};
