// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/SocketManager.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/selector/SelectionKeyHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <java/net/InetSocketAddress.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::SocketManager
    : public ::rice::selector::SelectionKeyHandler
    , public virtual ::org::mpisws::p2p::transport::P2PSocket
    , public virtual ::org::mpisws::p2p::transport::SocketRequestHandle
{

public:
    typedef ::rice::selector::SelectionKeyHandler super;

public: /* protected */
    ::java::nio::channels::SelectionKey* key {  };
    ::java::nio::channels::SocketChannel* channel {  };
    ::rice::selector::TimerTask* timer {  };
    TCPLayer* tcp {  };

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
    ::java::net::InetSocketAddress* addr {  };
    ::java::util::Map* options {  };

public: /* protected */
    ::org::mpisws::p2p::transport::P2PSocketReceiver* reader {  };
    ::org::mpisws::p2p::transport::P2PSocketReceiver* writer {  };

public: /* package */
    bool delivered {  };
protected:
    void ctor(TCPLayer* tcp, ::java::nio::channels::SelectionKey* serverKey) /* throws(IOException) */;
    void ctor(TCPLayer* tcp, ::java::net::InetSocketAddress* addr, ::org::mpisws::p2p::transport::SocketCallback* c, ::java::util::Map* options) /* throws(IOException) */;

public:
    ::java::lang::String* toString() override;
    void close() override;
    void modifyKey(::java::nio::channels::SelectionKey* key) override;
    void read(::java::nio::channels::SelectionKey* key) override;
    void write(::java::nio::channels::SelectionKey* key) override;
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;
    void shutdownOutput() override;
    int64_t read(::java::nio::ByteBuffer* dst) /* throws(IOException) */ override;
    int64_t write(::java::nio::ByteBuffer* src) /* throws(IOException) */ override;
    bool cancel() override;

private:
    void exceptionAndClose(::java::io::IOException* e);

public:
    ::java::net::InetSocketAddress* getIdentifier() override;
    ::java::util::Map* getOptions() override;
    virtual ::java::nio::channels::SocketChannel* getSocketChannel();

    // Generated
    SocketManager(TCPLayer* tcp, ::java::nio::channels::SelectionKey* serverKey);
    SocketManager(TCPLayer* tcp, ::java::net::InetSocketAddress* addr, ::org::mpisws::p2p::transport::SocketCallback* c, ::java::util::Map* options);
protected:
    SocketManager(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class SocketManager_SocketManager_1;
    friend class SocketManager_close_2;
    friend class SocketManager_shutdownOutput_3;
};
