// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/UDPLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/selector/SelectionKeyHandler.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::UDPLayerImpl
    : public ::rice::selector::SelectionKeyHandler
    , public virtual UDPLayer
{

public:
    typedef ::rice::selector::SelectionKeyHandler super;

private:
    static ::java::util::Map* OPTIONS_;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };

private:
    ::java::nio::channels::DatagramChannel* channel {  };
    ::java::nio::channels::SelectionKey* key {  };

public:
    int32_t DATAGRAM_RECEIVE_BUFFER_SIZE {  };
    int32_t DATAGRAM_SEND_BUFFER_SIZE {  };

public: /* package */
    ::java::util::List* pendingMsgs {  };
    WireTransportLayerImpl* wire {  };
    ::java::nio::ByteBuffer* readBuffer {  };
protected:
    void ctor(WireTransportLayerImpl* wire) /* throws(IOException) */;

public:
    ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* msg, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

public: /* protected */
    virtual void openServerSocket() /* throws(IOException) */;

public:
    void read(::java::nio::channels::SelectionKey* key) override;

public: /* protected */
    virtual void readHeader(::java::net::InetSocketAddress* address) /* throws(IOException) */;

public:
    void write(::java::nio::channels::SelectionKey* key) override;

public: /* package */
    int64_t lastTimePrinted {  };

public:
    void modifyKey(::java::nio::channels::SelectionKey* key) override;
    void destroy() override;
    void acceptMessages(bool b) override;

    // Generated
    UDPLayerImpl(WireTransportLayerImpl* wire);
protected:
    UDPLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static ::java::util::Map*& OPTIONS();

private:
    virtual ::java::lang::Class* getClass0();
    friend class UDPLayerImpl_Envelope;
    friend class UDPLayerImpl_destroy_1;
    friend class UDPLayerImpl_acceptMessages_2;
};
