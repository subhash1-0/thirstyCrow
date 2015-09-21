// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java
#include <rice/tutorial/sendfile/MyApp_MyApp_1_receiveSocket_1_1.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/tutorial/sendfile/MyApp_MyApp_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::sendfile::MyApp_MyApp_1_receiveSocket_1_1::MyApp_MyApp_1_receiveSocket_1_1(MyApp_MyApp_1 *MyApp_MyApp_1_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyApp_MyApp_1_this(MyApp_MyApp_1_this)
{
    clinit();
    ctor();
}

void rice::tutorial::sendfile::MyApp_MyApp_1_receiveSocket_1_1::messageReceived(::java::nio::ByteBuffer* bb)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Message received: "_j)->append(static_cast< ::java::lang::Object* >(bb))->toString());
}

void rice::tutorial::sendfile::MyApp_MyApp_1_receiveSocket_1_1::fileReceived(::java::io::File* f, ::java::nio::ByteBuffer* metadata)
{
    try {
        auto originalFileName = (new ::rice::p2p::util::rawserialization::SimpleInputBuffer(metadata))->readUTF();
        auto dest = new ::java::io::File(u"delme2.txt"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Moving "_j)->append(static_cast< ::java::lang::Object* >(f))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(dest))
            ->append(u" original:"_j)
            ->append(originalFileName)->toString());
        npc(::java::lang::System::out())->println(npc(f)->renameTo(dest));
    } catch (::java::io::IOException* ioe) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Error deserializing file name. "_j)->append(static_cast< ::java::lang::Object* >(ioe))->toString());
    }
}

void rice::tutorial::sendfile::MyApp_MyApp_1_receiveSocket_1_1::receiveException(::java::lang::Exception* ioe)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"FTC.receiveException() "_j)->append(static_cast< ::java::lang::Object* >(ioe))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::sendfile::MyApp_MyApp_1_receiveSocket_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::sendfile::MyApp_MyApp_1_receiveSocket_1_1::getClass0()
{
    return class_();
}

