// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java
#include <rice/tutorial/sendfile/MyApp_MyApp_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransfer.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/tutorial/sendfile/MyApp_MyApp_1_receiveSocket_1_1.hpp>
#include <rice/tutorial/sendfile/MyApp_MyFileListener.hpp>
#include <rice/tutorial/sendfile/MyApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::sendfile::MyApp_MyApp_1::MyApp_MyApp_1(MyApp *MyApp_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyApp_this(MyApp_this)
{
    clinit();
    ctor();
}

void rice::tutorial::sendfile::MyApp_MyApp_1::receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket)
{
    MyApp_this->fileTransfer = new ::org::mpisws::p2p::filetransfer::FileTransferImpl(socket, new MyApp_MyApp_1_receiveSocket_1_1(this), npc(MyApp_this->node)->getEnvironment());
    npc(MyApp_this->fileTransfer)->addListener(new MyApp_MyFileListener(MyApp_this));
    npc(MyApp_this->endpoint)->accept(this);
}

void rice::tutorial::sendfile::MyApp_MyApp_1::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite)
{
    throw new ::java::lang::RuntimeException(u"Shouldn't be called."_j);
}

void rice::tutorial::sendfile::MyApp_MyApp_1::receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e)
{
    npc(e)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::sendfile::MyApp_MyApp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::sendfile::MyApp_MyApp_1::getClass0()
{
    return class_();
}

