// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java

#pragma once

#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::pastry::PastryNode_connect_3
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    PastryNode_connect_3(PastryNode *PastryNode_this, ::rice::pastry::client::PastryAppl* appl, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, NodeHandle* i, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe);
    static ::java::lang::Class *class_();
    PastryNode *PastryNode_this;
    ::rice::pastry::client::PastryAppl* appl;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle;
    NodeHandle* i;
    ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryNode;
    friend class PastryNode_getDefaultReadyStrategy_1;
    friend class PastryNode_destroy_2;
    friend class PastryNode_connect_3_run_3_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1;
    friend class PastryNode_incomingSocket_4;
    friend class PastryNode_incomingSocket_4_receiveSelectResult_4_1;
    friend class PastryNode_send_5;
    friend class PastryNode_send_6;
    friend class PastryNode_send_7;
};
