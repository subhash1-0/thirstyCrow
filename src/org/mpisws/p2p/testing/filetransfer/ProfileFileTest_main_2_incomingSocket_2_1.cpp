// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_2_incomingSocket_2_1.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_2.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_1::ProfileFileTest_main_2_incomingSocket_2_1(ProfileFileTest_main_2 *ProfileFileTest_main_2_this, ::rice::environment::logging::Logger* logger)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProfileFileTest_main_2_this(ProfileFileTest_main_2_this)
    , logger(logger)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_1::messageReceived(::java::nio::ByteBuffer* bb)
{
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_1::fileReceived(::java::io::File* f, ::java::nio::ByteBuffer* metadata)
{
    try {
        auto name = (new ::rice::p2p::util::rawserialization::SimpleInputBuffer(metadata))->readUTF();
        npc(logger)->log(::java::lang::StringBuilder().append(u"file received "_j)->append(static_cast< ::java::lang::Object* >(f))
            ->append(u" named:"_j)
            ->append(name)
            ->append(u" size:"_j)
            ->append(npc(f)->length())->toString());
    } catch (::java::io::IOException* ioe) {
        npc(logger)->logException(u"Error interpreting filename "_j, ioe);
    }
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_1::receiveException(::java::lang::Exception* ioe)
{
    npc(logger)->logException(u"Receiver FTC.receiveException()"_j, ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_1::getClass0()
{
    return class_();
}

