// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/Tutorial2.java
#include <rice/tutorial/remotesocket/Tutorial2_Tutorial2_1_receiveResult_1_1.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/nio/channels/SocketChannel.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/tutorial/remotesocket/Tutorial2_Tutorial2_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::remotesocket::Tutorial2_Tutorial2_1_receiveResult_1_1::Tutorial2_Tutorial2_1_receiveResult_1_1(Tutorial2_Tutorial2_1 *Tutorial2_Tutorial2_1_this, ::java::nio::channels::SocketChannel* socket)
    : super(*static_cast< ::default_init_tag* >(0))
    , Tutorial2_Tutorial2_1_this(Tutorial2_Tutorial2_1_this)
    , socket(socket)
{
    clinit();
    ctor();
}

void rice::tutorial::remotesocket::Tutorial2_Tutorial2_1_receiveResult_1_1::run()
{
    auto const out = ::java::nio::ByteBuffer::wrap(npc(::rice::pastry::Id::build())->toByteArray_());
    try {
        npc(socket)->configureBlocking(true);
        npc(::java::lang::System::out())->println(u"Writing"_j);
        npc(socket)->write(out);
        npc(::java::lang::System::out())->println(u"Done writing"_j);
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::remotesocket::Tutorial2_Tutorial2_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::remotesocket::Tutorial2_Tutorial2_1_receiveResult_1_1::getClass0()
{
    return class_();
}

