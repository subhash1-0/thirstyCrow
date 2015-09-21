// Generated from /pastry-2.1/src/rice/tutorial/appsocket/MyApp.java
#include <rice/tutorial/appsocket/MyApp_MyApp_1.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/tutorial/appsocket/MyApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::appsocket::MyApp_MyApp_1::MyApp_MyApp_1(MyApp *MyApp_this, ::rice::p2p::commonapi::IdFactory* factory)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyApp_this(MyApp_this)
    , factory(factory)
{
    clinit();
    ctor();
}

void rice::tutorial::appsocket::MyApp_MyApp_1::receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket)
{
    npc(socket)->register_(true, false, 30000, this);
    npc(MyApp_this->endpoint)->accept(this);
}

void rice::tutorial::appsocket::MyApp_MyApp_1::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite)
{
    npc(MyApp_this->in)->clear();
    try {
        auto ret = npc(socket)->read(MyApp_this->in);
        if(ret != MyApp_this->MSG_LENGTH) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Error, we only received part of a message."_j)->append(ret)
                ->append(u" from "_j)
                ->append(static_cast< ::java::lang::Object* >(socket))->toString());
            return;
        }
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(npc(MyApp_this->node)->getLocalNodeHandle()))->append(u" Received message from "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(factory)->buildId(npc(MyApp_this->in)->array())))->toString());
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
    }
}

void rice::tutorial::appsocket::MyApp_MyApp_1::receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e)
{
    npc(e)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::appsocket::MyApp_MyApp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::appsocket::MyApp_MyApp_1::getClass0()
{
    return class_();
}

