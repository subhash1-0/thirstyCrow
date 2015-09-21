// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <rice/Continuation_StandardContinuation.hpp>

struct default_init_tag;

class rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1
    : public ::rice::Continuation_StandardContinuation
{

public:
    typedef ::rice::Continuation_StandardContinuation super;
    void receiveResult(::java::lang::Object* result) override;

    // Generated
    ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1(ReplicationManagerImpl_ReplicationManagerDeleter_go_1 *ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this, ::rice::Continuation* continuation);
    static ::java::lang::Class *class_();
    ReplicationManagerImpl_ReplicationManagerDeleter_go_1 *ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationManagerImpl;
    friend class ReplicationManagerImpl_informClient_1;
    friend class ReplicationManagerImpl_ReplicationManagerHelper;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter_go_1;
};
