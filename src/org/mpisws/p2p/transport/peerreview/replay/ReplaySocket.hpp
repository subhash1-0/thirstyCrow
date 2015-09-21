// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/ReplaySocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::ReplaySocket
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocket
    , public virtual ::org::mpisws::p2p::transport::SocketRequestHandle
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::rawserialization::RawSerializable* identifier {  };
    int32_t socketId {  };
    VerifierImpl* verifier {  };

public: /* package */
    bool closed {  };
    bool outputShutdown {  };
    ::java::util::Map* options {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* identifier, int32_t socketId, VerifierImpl* verifier, ::java::util::Map* options);

public:
    ::rice::p2p::commonapi::rawserialization::RawSerializable* getIdentifier() override;
    ::java::util::Map* getOptions() override;
    int64_t read(::java::nio::ByteBuffer* dst) /* throws(IOException) */ override;
    int64_t write(::java::nio::ByteBuffer* src) /* throws(IOException) */ override;

public: /* package */
    ::org::mpisws::p2p::transport::P2PSocketReceiver* reader {  };
    ::org::mpisws::p2p::transport::P2PSocketReceiver* writer {  };

public:
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;
    virtual void notifyIO(bool canRead, bool canWrite) /* throws(IOException) */;
    void close() override;

public: /* package */
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe {  };

public:
    virtual void setDeliverSocketToMe(::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe);
    virtual void socketOpened();
    void shutdownOutput() override;
    virtual void receiveException(::java::io::IOException* ioe);
    bool cancel() override;

    // Generated
    ReplaySocket(::rice::p2p::commonapi::rawserialization::RawSerializable* identifier, int32_t socketId, VerifierImpl* verifier, ::java::util::Map* options);
protected:
    ReplaySocket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
