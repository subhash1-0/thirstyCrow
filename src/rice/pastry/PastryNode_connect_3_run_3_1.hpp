// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class rice::pastry::PastryNode_connect_3_run_3_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::org::mpisws::p2p::transport::P2PSocket* result) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;

    // Generated
    PastryNode_connect_3_run_3_1(PastryNode_connect_3 *PastryNode_connect_3_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, NodeHandle* i, ::java::nio::ByteBuffer* b, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe, ::rice::pastry::client::PastryAppl* appl);
    static ::java::lang::Class *class_();
    PastryNode_connect_3 *PastryNode_connect_3_this;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle;
    NodeHandle* i;
    ::java::nio::ByteBuffer* b;
    ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe;
    ::rice::pastry::client::PastryAppl* appl;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryNode;
    friend class PastryNode_getDefaultReadyStrategy_1;
    friend class PastryNode_destroy_2;
    friend class PastryNode_connect_3;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1;
    friend class PastryNode_incomingSocket_4;
    friend class PastryNode_incomingSocket_4_receiveSelectResult_4_1;
    friend class PastryNode_send_5;
    friend class PastryNode_send_6;
    friend class PastryNode_send_7;
};
