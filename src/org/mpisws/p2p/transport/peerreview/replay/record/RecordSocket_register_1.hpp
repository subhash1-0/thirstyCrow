// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket_register_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;

    // Generated
    RecordSocket_register_1(RecordSocket *RecordSocket_this, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver);
    static ::java::lang::Class *class_();
    RecordSocket *RecordSocket_this;
    ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RecordSocket;
};
