// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/nio/channels/spi/fwd-pastry-2.1.hpp>
#include <java/nio/channels/spi/AbstractSelectableChannel.hpp>
#include <java/nio/channels/NetworkChannel.hpp>

struct default_init_tag;

class java::nio::channels::ServerSocketChannel
    : public ::java::nio::channels::spi::AbstractSelectableChannel
    , public virtual NetworkChannel
{

public:
    typedef ::java::nio::channels::spi::AbstractSelectableChannel super;

protected:
    void ctor(::java::nio::channels::spi::SelectorProvider* arg0);

public:
    virtual SocketChannel* accept() = 0;
    ServerSocketChannel* bind(::java::net::SocketAddress* arg0) override;
    virtual ServerSocketChannel* bind(::java::net::SocketAddress* arg0, int32_t arg1) = 0;
    /*::java::net::SocketAddress* getLocalAddress(); (already declared) */
    static ServerSocketChannel* open();
    ServerSocketChannel* setOption(::java::net::SocketOption* arg0, ::java::lang::Object* arg1) = 0;
    virtual ::java::net::ServerSocket* socket() = 0;
    int32_t validOps() override;

    // Generated

public: /* protected */
    ServerSocketChannel(::java::nio::channels::spi::SelectorProvider* arg0);
protected:
    ServerSocketChannel(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    void close();
    virtual bool isOpen();

private:
    virtual ::java::lang::Class* getClass0();
};
