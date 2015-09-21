// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket
    : public ::org::mpisws::p2p::transport::util::SocketWrapperSocket
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::org::mpisws::p2p::transport::util::SocketWrapperSocket super;

public: /* package */
    int32_t socketId {  };
    ::java::nio::ByteBuffer* socketIdBuffer {  };
    RecordLayer* recordLayer {  };
    bool closed {  };
    bool outputShutdown {  };
protected:
    void ctor(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::java::util::Map* options, int32_t socketId, ::java::nio::ByteBuffer* sib, RecordLayer* recordLayer);

public:
    int64_t read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */ override;
    int64_t write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ override;
    void close() override;
    void shutdownOutput() override;
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;

    // Generated
    RecordSocket(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::java::util::Map* options, int32_t socketId, ::java::nio::ByteBuffer* sib, RecordLayer* recordLayer);
protected:
    RecordSocket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class RecordSocket_register_1;
};
