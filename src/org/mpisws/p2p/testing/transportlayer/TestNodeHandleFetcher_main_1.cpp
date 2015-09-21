// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/TestNodeHandleFetcher.java
#include <org/mpisws/p2p/testing/transportlayer/TestNodeHandleFetcher_main_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/System.hpp>
#include <rice/pastry/NodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher_main_1::TestNodeHandleFetcher_main_1()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher_main_1::receiveResult(::rice::pastry::NodeHandle* result)
{
    npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(result));
}

void org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher_main_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::NodeHandle* >(result));
}

void org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher_main_1::receiveException(::java::lang::Exception* exception)
{
    npc(exception)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher_main_1::getClass0()
{
    return class_();
}

