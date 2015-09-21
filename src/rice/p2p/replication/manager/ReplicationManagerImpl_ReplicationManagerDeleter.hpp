// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::IdSet* set {  };
    ::rice::p2p::commonapi::Id* id {  };
protected:
    void ctor();

public:
    virtual void setRange(::rice::p2p::commonapi::IdRange* range);

public: /* protected */
    virtual void go();

public:
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;

    // Generated
    ReplicationManagerImpl_ReplicationManagerDeleter(ReplicationManagerImpl *ReplicationManagerImpl_this);
protected:
    ReplicationManagerImpl_ReplicationManagerDeleter(ReplicationManagerImpl *ReplicationManagerImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ReplicationManagerImpl *ReplicationManagerImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationManagerImpl;
    friend class ReplicationManagerImpl_informClient_1;
    friend class ReplicationManagerImpl_ReplicationManagerHelper;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter_go_1;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1;
};
