// Generated from /pastry-2.1/src/rice/pastry/testing/PartitionChecker.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class rice::pastry::testing::PartitionChecker_Ring
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::HashSet* myBootstraps {  };
    ::java::util::HashSet* nodes {  };
    ::java::lang::String* name {  };
protected:
    void ctor(::java::net::InetSocketAddress* bootAddr);

public:
    virtual bool contains(::rice::pastry::NodeHandle* handle);
    virtual ::java::lang::String* getName();
    virtual void addFailure(::rice::pastry::socket::SocketNodeHandle* handle, ::java::lang::Exception* e);
    virtual void addNode(::rice::pastry::socket::SocketNodeHandle* snh);
    ::java::lang::String* toString() override;
    virtual int32_t compareTo(PartitionChecker_Ring* arg0);
    virtual int32_t size();

    // Generated
    PartitionChecker_Ring(PartitionChecker *PartitionChecker_this, ::java::net::InetSocketAddress* bootAddr);
protected:
    PartitionChecker_Ring(PartitionChecker *PartitionChecker_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* arg0) override;
    PartitionChecker *PartitionChecker_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PartitionChecker;
    friend class PartitionChecker_buildRing_1;
};
