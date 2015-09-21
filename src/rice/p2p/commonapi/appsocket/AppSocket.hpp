// Generated from /pastry-2.1/src/rice/p2p/commonapi/appsocket/AppSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
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

struct rice::p2p::commonapi::appsocket::AppSocket
    : public virtual ::java::lang::Object
{
    virtual int64_t read(::java::nio::ByteBufferArray* dsts, int32_t offset, int32_t length) /* throws(IOException) */ = 0;
    virtual int64_t write(::java::nio::ByteBufferArray* srcs, int32_t offset, int32_t length) /* throws(IOException) */ = 0;
    virtual int64_t read(::java::nio::ByteBuffer* dst) /* throws(IOException) */ = 0;
    virtual int64_t write(::java::nio::ByteBuffer* src) /* throws(IOException) */ = 0;
    virtual void register_(bool wantToRead, bool wantToWrite, int32_t timeout, AppSocketReceiver* receiver) = 0;
    virtual void shutdownOutput() = 0;
    virtual void close() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
