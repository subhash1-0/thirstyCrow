// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamDistTest.java
#include <rice/p2p/splitstream/testing/SplitStreamDistTest_main_2.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/PastryNode.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
    , node(node)
{
    clinit();
    ctor();
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::Runnable* arg0)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
    , node(node)
{
    clinit();
    ctor(arg0);
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::String* arg0)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
    , node(node)
{
    clinit();
    ctor(arg0);
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::Runnable* arg0, ::java::security::AccessControlContext* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
    , node(node)
{
    clinit();
    ctor(arg0, arg1);
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
    , node(node)
{
    clinit();
    ctor(arg0, arg1);
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
    , node(node)
{
    clinit();
    ctor(arg0, arg1);
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::Runnable* arg0, ::java::lang::String* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
    , node(node)
{
    clinit();
    ctor(arg0, arg1);
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
    , node(node)
{
    clinit();
    ctor(arg0, arg1, arg2);
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::SplitStreamDistTest_main_2(::rice::environment::Environment* env, ::rice::pastry::PastryNode* node, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2, int64_t arg3)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
    , node(node)
{
    clinit();
    ctor(arg0, arg1, arg2, arg3);
}

void rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::run()
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"SHUTDOWN "_j)->append(npc(npc(env)->getTimeSource())->currentTimeMillis())
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(node))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamDistTest_main_2::getClass0()
{
    return class_();
}

