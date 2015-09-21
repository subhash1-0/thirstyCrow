// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/nio/channels/WritableByteChannel.hpp>

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

struct java::nio::channels::GatheringByteChannel
    : public virtual WritableByteChannel
{

    virtual int64_t write(::java::nio::ByteBufferArray* arg0) = 0;
    virtual int64_t write(::java::nio::ByteBufferArray* arg0, int32_t arg1, int32_t arg2) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual int32_t write(::java::nio::ByteBuffer* arg0) = 0;
};
