// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/EncryptedFileTest.java
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_4.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransfer.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_4_receiveResult_4_1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_4_receiveResult_4_2.hpp>
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_4_receiveResult_4_3.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/pastry/transport/SocketAdapter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_4::EncryptedFileTest_main_4(::rice::environment::logging::Logger* logger, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , logger(logger)
    , env(env)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_4::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* s)
{
    npc(logger)->log(::java::lang::StringBuilder().append(u"opened Socket "_j)->append(static_cast< ::java::lang::Object* >(s))->toString());
    ::rice::p2p::commonapi::appsocket::AppSocket* const sock = new ::rice::pastry::transport::SocketAdapter(s, env);
    ::org::mpisws::p2p::filetransfer::FileTransfer* ft = new ::org::mpisws::p2p::filetransfer::FileTransferImpl(sock, new EncryptedFileTest_main_4_receiveResult_4_1(this, logger), env);
    npc(ft)->addListener(new EncryptedFileTest_main_4_receiveResult_4_2(this, u"Sender"_j));
    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(sob)->writeUTF(u"foo"_j);
        npc(ft)->sendFile(new ::java::io::File(u"delme.txt"_j), npc(sob)->getByteBuffer(), static_cast< int8_t >(int32_t(0)), new EncryptedFileTest_main_4_receiveResult_4_3(this));
    } catch (::java::io::IOException* ioe) {
        npc(logger)->logException(u"Error sending file."_j, ioe);
    }
}

void org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_4::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(logger)->logException(::java::lang::StringBuilder().append(u"receiveException("_j)->append(static_cast< ::java::lang::Object* >(s))
        ->append(u")"_j)->toString(), ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_4::getClass0()
{
    return class_();
}

