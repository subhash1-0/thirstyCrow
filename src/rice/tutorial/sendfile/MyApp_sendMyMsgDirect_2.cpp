// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java
#include <rice/tutorial/sendfile/MyApp_sendMyMsgDirect_2.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransfer.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/tutorial/sendfile/MyApp_sendMyMsgDirect_2_receiveSocket_2_1.hpp>
#include <rice/tutorial/sendfile/MyApp_MyFileListener.hpp>
#include <rice/tutorial/sendfile/MyApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2::MyApp_sendMyMsgDirect_2(MyApp *MyApp_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyApp_this(MyApp_this)
{
    clinit();
    ctor();
}

void rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2::receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket)
{
    ::org::mpisws::p2p::filetransfer::FileTransfer* sender = new ::org::mpisws::p2p::filetransfer::FileTransferImpl(socket, nullptr, npc(MyApp_this->node)->getEnvironment());
    npc(sender)->addListener(new MyApp_MyFileListener(MyApp_this));
    auto sendMe = ::java::nio::ByteBuffer::allocate(4);
    npc(sendMe)->put(static_cast< int8_t >(int32_t(1)));
    npc(sendMe)->put(static_cast< int8_t >(int32_t(2)));
    npc(sendMe)->put(static_cast< int8_t >(int32_t(3)));
    npc(sendMe)->put(static_cast< int8_t >(int32_t(4)));
    npc(sendMe)->flip();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Sending "_j)->append(static_cast< ::java::lang::Object* >(sendMe))->toString());
    npc(sender)->sendMsg(sendMe, static_cast< int8_t >(int32_t(1)), nullptr);
    try {
        auto const f = new ::java::io::File(u"delme.txt"_j);
        if(!npc(f)->exists()) {
            npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"File "_j)->append(static_cast< ::java::lang::Object* >(f))
                ->append(u" does not exist.  Please create a file called "_j)
                ->append(static_cast< ::java::lang::Object* >(f))
                ->append(u" and run the tutorial again."_j)->toString());
            ::java::lang::System::exit(1);
        }
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(sob)->writeUTF(npc(f)->getName());
        npc(sender)->sendFile(f, npc(sob)->getByteBuffer(), static_cast< int8_t >(int32_t(2)), new MyApp_sendMyMsgDirect_2_receiveSocket_2_1(this, f));
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
    }
}

void rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2::receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e)
{
    npc(e)->printStackTrace();
}

void rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite)
{
    throw new ::java::lang::RuntimeException(u"Shouldn't be called."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2::getClass0()
{
    return class_();
}

