// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamDistTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Thread.hpp>

struct default_init_tag;

class rice::p2p::splitstream::testing::SplitStreamDistTest_main_2
    : public ::java::lang::Thread
{

public:
    typedef ::java::lang::Thread super;
    void run() override;

    // Generated
    SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node);
    SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::Runnable* arg0);
    SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::String* arg0);

public: /* package */
    SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::Runnable* arg0, ::java::security::AccessControlContext* arg1);

public:
    SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1);
    SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1);
    SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::Runnable* arg0, ::java::lang::String* arg1);
    SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2);
    SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2, int64_t arg3);
    static ::java::lang::Class *class_();
    ::rice::environment::Environment* env;
    ::rice::pastry::PastryNode* node;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SplitStreamDistTest;
    friend class SplitStreamDistTest_main_1;
};
