// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Executable.hpp>

struct default_init_tag;

class rice::p2p::replication::ReplicationImpl_BloomFilterExecutable
    : public virtual ::java::lang::Object
    , public virtual ::rice::Executable
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::IdRange* range {  };
protected:
    void ctor(::rice::p2p::commonapi::IdRange* range);

public:
    ::java::lang::String* toString() override;
    ::java::lang::Object* execute() override;

    // Generated
    ReplicationImpl_BloomFilterExecutable(ReplicationImpl *ReplicationImpl_this, ::rice::p2p::commonapi::IdRange* range);
protected:
    ReplicationImpl_BloomFilterExecutable(ReplicationImpl *ReplicationImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ReplicationImpl *ReplicationImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationImpl;
    friend class ReplicationImpl_ReplicationImpl_1;
    friend class ReplicationImpl_replicate_2;
    friend class ReplicationImpl_replicate_2_receiveResult_2_1;
    friend class ReplicationImpl_deliver_3;
    friend class ReplicationImpl_deliver_4;
};
