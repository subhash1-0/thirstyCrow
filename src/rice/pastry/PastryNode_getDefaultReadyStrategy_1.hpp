// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/ReadyStrategy.hpp>

struct default_init_tag;

class rice::pastry::PastryNode_getDefaultReadyStrategy_1
    : public virtual ::java::lang::Object
    , public virtual ReadyStrategy
{

public:
    typedef ::java::lang::Object super;

private:
    bool ready {  };

public:
    void setReady(bool r) override;
    bool isReady() override;
    void start() override;
    void stop() override;

    // Generated
    PastryNode_getDefaultReadyStrategy_1(PastryNode *PastryNode_this);
    static ::java::lang::Class *class_();

private:
    void init();
    PastryNode *PastryNode_this;
    virtual ::java::lang::Class* getClass0();
    friend class PastryNode;
    friend class PastryNode_destroy_2;
    friend class PastryNode_connect_3;
    friend class PastryNode_connect_3_run_3_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1;
    friend class PastryNode_incomingSocket_4;
    friend class PastryNode_incomingSocket_4_receiveSelectResult_4_1;
    friend class PastryNode_send_5;
    friend class PastryNode_send_6;
    friend class PastryNode_send_7;
};
