// Generated from /pastry-2.1/src/rice/pastry/testing/PastryNetworkTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Thread.hpp>

struct default_init_tag;

class rice::pastry::testing::PastryNetworkTest_fetchLeafSets_1
    : public ::java::lang::Thread
{

public:
    typedef ::java::lang::Thread super;
    void run() override;

    // Generated
    PastryNetworkTest_fetchLeafSets_1(PastryNetworkTest *PastryNetworkTest_this, ::rice::pastry::socket::SocketNodeHandle* handle, ::java::io::PrintStream* ps, ::java::util::HashMap* leafsets, ::java::util::HashSet* unseen);
    PastryNetworkTest_fetchLeafSets_1(PastryNetworkTest *PastryNetworkTest_this, ::rice::pastry::socket::SocketNodeHandle* handle, ::java::io::PrintStream* ps, ::java::util::HashMap* leafsets, ::java::util::HashSet* unseen, ::java::lang::Runnable* arg0);
    PastryNetworkTest_fetchLeafSets_1(PastryNetworkTest *PastryNetworkTest_this, ::rice::pastry::socket::SocketNodeHandle* handle, ::java::io::PrintStream* ps, ::java::util::HashMap* leafsets, ::java::util::HashSet* unseen, ::java::lang::String* arg0);

public: /* package */
    PastryNetworkTest_fetchLeafSets_1(PastryNetworkTest *PastryNetworkTest_this, ::rice::pastry::socket::SocketNodeHandle* handle, ::java::io::PrintStream* ps, ::java::util::HashMap* leafsets, ::java::util::HashSet* unseen, ::java::lang::Runnable* arg0, ::java::security::AccessControlContext* arg1);

public:
    PastryNetworkTest_fetchLeafSets_1(PastryNetworkTest *PastryNetworkTest_this, ::rice::pastry::socket::SocketNodeHandle* handle, ::java::io::PrintStream* ps, ::java::util::HashMap* leafsets, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1);
    PastryNetworkTest_fetchLeafSets_1(PastryNetworkTest *PastryNetworkTest_this, ::rice::pastry::socket::SocketNodeHandle* handle, ::java::io::PrintStream* ps, ::java::util::HashMap* leafsets, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1);
    PastryNetworkTest_fetchLeafSets_1(PastryNetworkTest *PastryNetworkTest_this, ::rice::pastry::socket::SocketNodeHandle* handle, ::java::io::PrintStream* ps, ::java::util::HashMap* leafsets, ::java::util::HashSet* unseen, ::java::lang::Runnable* arg0, ::java::lang::String* arg1);
    PastryNetworkTest_fetchLeafSets_1(PastryNetworkTest *PastryNetworkTest_this, ::rice::pastry::socket::SocketNodeHandle* handle, ::java::io::PrintStream* ps, ::java::util::HashMap* leafsets, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2);
    PastryNetworkTest_fetchLeafSets_1(PastryNetworkTest *PastryNetworkTest_this, ::rice::pastry::socket::SocketNodeHandle* handle, ::java::io::PrintStream* ps, ::java::util::HashMap* leafsets, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2, int64_t arg3);
    static ::java::lang::Class *class_();
    PastryNetworkTest *PastryNetworkTest_this;
    ::rice::pastry::socket::SocketNodeHandle* handle;
    ::java::io::PrintStream* ps;
    ::java::util::HashMap* leafsets;
    ::java::util::HashSet* unseen;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryNetworkTest;
};
