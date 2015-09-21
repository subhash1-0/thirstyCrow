// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/nio/channels/spi/fwd-pastry-2.1.hpp>
#include <java/nio/channels/spi/AbstractSelectableChannel.hpp>
#include <java/nio/channels/ByteChannel.hpp>
#include <java/nio/channels/ScatteringByteChannel.hpp>
#include <java/nio/channels/GatheringByteChannel.hpp>
#include <java/nio/channels/NetworkChannel.hpp>

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

class java::nio::channels::SocketChannel
    : public ::java::nio::channels::spi::AbstractSelectableChannel
    , public virtual ByteChannel
    , public virtual ScatteringByteChannel
    , public virtual GatheringByteChannel
    , public virtual NetworkChannel
{

public:
    typedef ::java::nio::channels::spi::AbstractSelectableChannel super;

private:
    static bool $assertionsDisabled_;

protected:
    void ctor(::java::nio::channels::spi::SelectorProvider* arg0);

public:
    SocketChannel* bind(::java::net::SocketAddress* arg0) = 0;
    virtual bool connect(::java::net::SocketAddress* arg0) = 0;
    virtual bool finishConnect() = 0;
    /*::java::net::SocketAddress* getLocalAddress(); (already declared) */
    virtual ::java::net::SocketAddress* getRemoteAddress() = 0;
    virtual bool isConnected() = 0;
    virtual bool isConnectionPending() = 0;
    static SocketChannel* open();
    static SocketChannel* open(::java::net::SocketAddress* arg0);
    /*int32_t read(::java::nio::ByteBuffer* arg0); (already declared) */
    int64_t read(::java::nio::ByteBufferArray* arg0) override;
    /*int64_t read(::java::nio::ByteBufferArray* arg0, int32_t arg1, int32_t arg2); (already declared) */
    SocketChannel* setOption(::java::net::SocketOption* arg0, ::java::lang::Object* arg1) = 0;
    virtual SocketChannel* shutdownInput() = 0;
    virtual SocketChannel* shutdownOutput() = 0;
    virtual ::java::net::Socket* socket() = 0;
    int32_t validOps() override;
    /*int32_t write(::java::nio::ByteBuffer* arg0); (already declared) */
    int64_t write(::java::nio::ByteBufferArray* arg0) override;
    /*int64_t write(::java::nio::ByteBufferArray* arg0, int32_t arg1, int32_t arg2); (already declared) */

    // Generated

public: /* protected */
    SocketChannel(::java::nio::channels::spi::SelectorProvider* arg0);
protected:
    SocketChannel(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    void close();
    virtual bool isOpen();
    virtual int32_t read(::java::nio::ByteBuffer* dst) = 0;
    virtual int32_t write(::java::nio::ByteBuffer* arg0) = 0;
    virtual int64_t read(::java::nio::ByteBufferArray* dsts, int32_t offset, int32_t length) = 0;
    virtual int64_t write(::java::nio::ByteBufferArray* arg0, int32_t arg1, int32_t arg2) = 0;

public: /* package */
    static bool& $assertionsDisabled();

private:
    virtual ::java::lang::Class* getClass0();
};
