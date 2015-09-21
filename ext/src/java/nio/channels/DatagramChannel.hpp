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
#include <java/nio/channels/MulticastChannel.hpp>

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

class java::nio::channels::DatagramChannel
    : public ::java::nio::channels::spi::AbstractSelectableChannel
    , public virtual ByteChannel
    , public virtual ScatteringByteChannel
    , public virtual GatheringByteChannel
    , public virtual MulticastChannel
{

public:
    typedef ::java::nio::channels::spi::AbstractSelectableChannel super;

protected:
    void ctor(::java::nio::channels::spi::SelectorProvider* arg0);

public:
    DatagramChannel* bind(::java::net::SocketAddress* arg0) = 0;
    virtual DatagramChannel* connect(::java::net::SocketAddress* arg0) = 0;
    virtual DatagramChannel* disconnect() = 0;
    /*::java::net::SocketAddress* getLocalAddress(); (already declared) */
    virtual ::java::net::SocketAddress* getRemoteAddress() = 0;
    virtual bool isConnected() = 0;
    static DatagramChannel* open();
    static DatagramChannel* open(::java::net::ProtocolFamily* arg0);
    /*int32_t read(::java::nio::ByteBuffer* arg0); (already declared) */
    int64_t read(::java::nio::ByteBufferArray* arg0) override;
    /*int64_t read(::java::nio::ByteBufferArray* arg0, int32_t arg1, int32_t arg2); (already declared) */
    virtual ::java::net::SocketAddress* receive(::java::nio::ByteBuffer* arg0) = 0;
    virtual int32_t send(::java::nio::ByteBuffer* arg0, ::java::net::SocketAddress* arg1) = 0;
    DatagramChannel* setOption(::java::net::SocketOption* arg0, ::java::lang::Object* arg1) = 0;
    virtual ::java::net::DatagramSocket* socket() = 0;
    int32_t validOps() override;
    /*int32_t write(::java::nio::ByteBuffer* arg0); (already declared) */
    int64_t write(::java::nio::ByteBufferArray* arg0) override;
    /*int64_t write(::java::nio::ByteBufferArray* arg0, int32_t arg1, int32_t arg2); (already declared) */

    // Generated

public: /* protected */
    DatagramChannel(::java::nio::channels::spi::SelectorProvider* arg0);
protected:
    DatagramChannel(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool isOpen();
    void close();
    virtual int32_t read(::java::nio::ByteBuffer* arg0) = 0;
    virtual int32_t write(::java::nio::ByteBuffer* arg0) = 0;
    virtual int64_t read(::java::nio::ByteBufferArray* arg0, int32_t arg1, int32_t arg2) = 0;
    virtual int64_t write(::java::nio::ByteBufferArray* arg0, int32_t arg1, int32_t arg2) = 0;

private:
    virtual ::java::lang::Class* getClass0();
};
