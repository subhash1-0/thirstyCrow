// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/limitsockets/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket
    : public ::org::mpisws::p2p::transport::util::SocketWrapperSocket
{

public:
    typedef ::org::mpisws::p2p::transport::util::SocketWrapperSocket super;

public: /* package */
    bool closed {  };
    bool forcedClose {  };
protected:
    void ctor(::org::mpisws::p2p::transport::P2PSocket* socket);

public:
    virtual void forceClose();
    void close() override;
    int64_t read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */ override;
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;
    int64_t write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ override;
    ::java::lang::String* toString() override;

    // Generated
    LimitSocketsTransportLayer_LSSocket(LimitSocketsTransportLayer *LimitSocketsTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* socket);
protected:
    LimitSocketsTransportLayer_LSSocket(LimitSocketsTransportLayer *LimitSocketsTransportLayer_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    LimitSocketsTransportLayer *LimitSocketsTransportLayer_this;
    virtual ::java::lang::Class* getClass0();
    friend class LimitSocketsTransportLayer;
    friend class LimitSocketsTransportLayer_openSocket_1;
    friend class LimitSocketsTransportLayer_openSocket_2;
    friend class LimitSocketsTransportLayer_LSSocket_forceClose_1;
};
