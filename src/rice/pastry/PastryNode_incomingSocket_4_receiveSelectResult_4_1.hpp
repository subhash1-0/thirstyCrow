// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class rice::pastry::PastryNode_incomingSocket_4_receiveSelectResult_4_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;

    // Generated
    PastryNode_incomingSocket_4_receiveSelectResult_4_1(PastryNode_incomingSocket_4 *PastryNode_incomingSocket_4_this, int32_t appId);
    static ::java::lang::Class *class_();
    PastryNode_incomingSocket_4 *PastryNode_incomingSocket_4_this;
    int32_t appId;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryNode;
    friend class PastryNode_getDefaultReadyStrategy_1;
    friend class PastryNode_destroy_2;
    friend class PastryNode_connect_3;
    friend class PastryNode_connect_3_run_3_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1;
    friend class PastryNode_incomingSocket_4;
    friend class PastryNode_send_5;
    friend class PastryNode_send_6;
    friend class PastryNode_send_7;
};
