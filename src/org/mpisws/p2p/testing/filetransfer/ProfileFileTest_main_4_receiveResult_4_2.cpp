// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_4_receiveResult_4_2.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <org/mpisws/p2p/filetransfer/FileReceipt.hpp>
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_4.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_2::ProfileFileTest_main_4_receiveResult_4_2(ProfileFileTest_main_4 *ProfileFileTest_main_4_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProfileFileTest_main_4_this(ProfileFileTest_main_4_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_2::receiveResult(::org::mpisws::p2p::filetransfer::FileReceipt* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Send success "_j)->append(static_cast< ::java::lang::Object* >(result))->toString());
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::filetransfer::FileReceipt* >(result));
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_2::receiveException(::java::lang::Exception* exception)
{
    npc(::java::lang::System::out())->println(u"Send Failed"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_2::getClass0()
{
    return class_();
}

