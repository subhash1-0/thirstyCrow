// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerHelper
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    int32_t STATE_NOTHING {  };
    int32_t STATE_WAITING {  };
    int32_t STATE_SLEEPING {  };

public: /* protected */
    int32_t state {  };
    ::rice::p2p::commonapi::IdSet* set {  };
    ::rice::p2p::commonapi::Id* current {  };
    ::java::util::HashMap* hints {  };
protected:
    void ctor();

public:
    virtual void fetch(::rice::p2p::commonapi::IdSet* keySet, ::rice::p2p::commonapi::NodeHandle* hint);
    virtual void setRange(::rice::p2p::commonapi::IdRange* range);
    virtual ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range);

public: /* protected */
    virtual void send();
    virtual ::rice::p2p::commonapi::Id* getNextId();

public:
    virtual void wakeup();
    virtual void message(::rice::p2p::commonapi::Id* id);

    // Generated
    ReplicationManagerImpl_ReplicationManagerHelper(ReplicationManagerImpl *ReplicationManagerImpl_this);
protected:
    ReplicationManagerImpl_ReplicationManagerHelper(ReplicationManagerImpl *ReplicationManagerImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    ReplicationManagerImpl *ReplicationManagerImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationManagerImpl;
    friend class ReplicationManagerImpl_informClient_1;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter_go_1;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1;
};
