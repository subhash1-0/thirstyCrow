// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_4_receiveResult_4_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_4.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_1::ProfileFileTest_main_4_receiveResult_4_1(ProfileFileTest_main_4 *ProfileFileTest_main_4_this, ::rice::environment::logging::Logger* logger)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProfileFileTest_main_4_this(ProfileFileTest_main_4_this)
    , logger(logger)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_1::messageReceived(::java::nio::ByteBuffer* bb)
{
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_1::fileReceived(::java::io::File* f, ::java::nio::ByteBuffer* metadata)
{
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_1::receiveException(::java::lang::Exception* ioe)
{
    npc(logger)->logException(u"Sender FTC.receiveException()"_j, ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_1::getClass0()
{
    return class_();
}

