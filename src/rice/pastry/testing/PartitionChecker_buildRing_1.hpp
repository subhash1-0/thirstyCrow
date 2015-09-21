// Generated from /pastry-2.1/src/rice/pastry/testing/PartitionChecker.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Thread.hpp>

struct default_init_tag;

class rice::pastry::testing::PartitionChecker_buildRing_1
    : public ::java::lang::Thread
{

public:
    typedef ::java::lang::Thread super;
    void run() override;

    // Generated
    PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen);
    PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::Runnable* arg0);
    PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::String* arg0);

public: /* package */
    PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::Runnable* arg0, ::java::security::AccessControlContext* arg1);

public:
    PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1);
    PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1);
    PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::Runnable* arg0, ::java::lang::String* arg1);
    PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2);
    PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2, int64_t arg3);
    static ::java::lang::Class *class_();
    PartitionChecker *PartitionChecker_this;
    ::rice::pastry::socket::SocketNodeHandle* handle;
    PartitionChecker_Ring* ring;
    ::java::util::HashSet* unseen;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PartitionChecker;
    friend class PartitionChecker_Ring;
};
