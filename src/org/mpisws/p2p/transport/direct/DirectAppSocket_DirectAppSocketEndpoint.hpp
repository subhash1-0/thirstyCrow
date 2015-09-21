// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocket
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
    DirectAppSocket_DirectAppSocketEndpoint* counterpart {  };
    ::org::mpisws::p2p::transport::P2PSocketReceiver* reader {  };
    ::org::mpisws::p2p::transport::P2PSocketReceiver* writer {  };
    ::java::lang::Object* localNodeHandle {  };
    int32_t seq {  };
    bool outputClosed {  };
    int32_t bytesInFlight {  };
    ::java::util::LinkedList* byteDeliveries {  };
    int32_t firstOffset {  };
protected:
    void ctor(::java::lang::Object* localNodeHandle, ::rice::environment::logging::Logger* logger);

public:
    virtual void setCounterpart(DirectAppSocket_DirectAppSocketEndpoint* counterpart);
    virtual ::java::lang::Object* getRemoteNodeHandle();
    int64_t read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */ override;
    int64_t write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ override;

public: /* protected */
    virtual void addToReadQueue(::int8_tArray* msg);
    virtual void notifyCanWrite();
    virtual void notifyCanRead();

public:
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;
    void shutdownOutput() override;
    virtual void shutdownInput();
    void close() override;
    ::java::lang::String* toString() override;
    ::java::lang::Object* getIdentifier() override;
    ::java::util::Map* getOptions() override;

    // Generated
    DirectAppSocket_DirectAppSocketEndpoint(DirectAppSocket *DirectAppSocket_this, ::java::lang::Object* localNodeHandle, ::rice::environment::logging::Logger* logger);
protected:
    DirectAppSocket_DirectAppSocketEndpoint(DirectAppSocket *DirectAppSocket_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    DirectAppSocket *DirectAppSocket_this;
    virtual ::java::lang::Class* getClass0();
    friend class DirectAppSocket;
    friend class DirectAppSocket_DirectAppSocketEndpoint_read_1;
    friend class DirectAppSocket_DirectAppSocketEndpoint_write_2;
    friend class DirectAppSocket_DirectAppSocketEndpoint_register_3;
    friend class DirectAppSocket_DirectAppSocketEndpoint_register_4;
    friend class DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5;
    friend class DirectAppSocket_AcceptorDelivery;
    friend class DirectAppSocket_ConnectorDelivery;
};
