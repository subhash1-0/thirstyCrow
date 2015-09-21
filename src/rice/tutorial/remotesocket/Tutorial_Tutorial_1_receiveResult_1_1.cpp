// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/Tutorial.java
#include <rice/tutorial/remotesocket/Tutorial_Tutorial_1_receiveResult_1_1.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/tutorial/remotesocket/Tutorial_Tutorial_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::remotesocket::Tutorial_Tutorial_1_receiveResult_1_1::Tutorial_Tutorial_1_receiveResult_1_1(Tutorial_Tutorial_1 *Tutorial_Tutorial_1_this, ::java::nio::ByteBuffer* out)
    : super(*static_cast< ::default_init_tag* >(0))
    , Tutorial_Tutorial_1_this(Tutorial_Tutorial_1_this)
    , out(out)
{
    clinit();
    ctor();
}

void rice::tutorial::remotesocket::Tutorial_Tutorial_1_receiveResult_1_1::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite)
{
    try {
        auto ret = npc(socket)->write(out);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Wrote "_j)->append(ret)
            ->append(u" bytes."_j)->toString());
        if(npc(out)->hasRemaining()) {
            npc(socket)->register_(false, true, 30000, this);
        } else {
            npc(socket)->shutdownOutput();
            npc(out)->clear();
        }
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
    }
}

void rice::tutorial::remotesocket::Tutorial_Tutorial_1_receiveResult_1_1::receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e)
{
    npc(e)->printStackTrace();
}

void rice::tutorial::remotesocket::Tutorial_Tutorial_1_receiveResult_1_1::receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket)
{
    throw new ::java::lang::RuntimeException(u"Should never be called."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::remotesocket::Tutorial_Tutorial_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::remotesocket::Tutorial_Tutorial_1_receiveResult_1_1::getClass0()
{
    return class_();
}

