// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::p2p::replication::manager::ReplicationManagerImpl_informClient_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;

    // Generated
    ReplicationManagerImpl_informClient_1(ReplicationManagerImpl *ReplicationManagerImpl_this, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::CancellableTask* timer);
    static ::java::lang::Class *class_();
    ReplicationManagerImpl *ReplicationManagerImpl_this;
    ::rice::p2p::commonapi::Id* id;
    ::rice::p2p::commonapi::CancellableTask* timer;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationManagerImpl;
    friend class ReplicationManagerImpl_ReplicationManagerHelper;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter_go_1;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1;
};
