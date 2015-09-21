// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java
#include <rice/tutorial/sendfile/MyApp_MyFileListener.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <org/mpisws/p2p/filetransfer/BBReceipt.hpp>
#include <org/mpisws/p2p/filetransfer/FileReceipt.hpp>
#include <org/mpisws/p2p/filetransfer/Receipt.hpp>
#include <rice/tutorial/sendfile/MyApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::sendfile::MyApp_MyFileListener::MyApp_MyFileListener(MyApp *MyApp_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyApp_this(MyApp_this)
{
    clinit();
}

rice::tutorial::sendfile::MyApp_MyFileListener::MyApp_MyFileListener(MyApp *MyApp_this)
    : MyApp_MyFileListener(MyApp_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::tutorial::sendfile::MyApp_MyFileListener::fileTransferred(::org::mpisws::p2p::filetransfer::FileReceipt* receipt, int64_t bytesTransferred, int64_t total, bool incoming)
{
    ::java::lang::String* s;
    if(incoming) {
        s = u" Downloaded "_j;
    } else {
        s = u" Uploaded "_j;
    }
    auto percent = 100.0 * bytesTransferred / total;
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(MyApp_this))->append(s)
        ->append(percent)
        ->append(u"% of "_j)
        ->append(static_cast< ::java::lang::Object* >(receipt))->toString());
}

void rice::tutorial::sendfile::MyApp_MyFileListener::msgTransferred(::org::mpisws::p2p::filetransfer::BBReceipt* receipt, int32_t bytesTransferred, int32_t total, bool incoming)
{
    ::java::lang::String* s;
    if(incoming) {
        s = u" Downloaded "_j;
    } else {
        s = u" Uploaded "_j;
    }
    auto percent = 100.0 * bytesTransferred / total;
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(MyApp_this))->append(s)
        ->append(percent)
        ->append(u"% of "_j)
        ->append(static_cast< ::java::lang::Object* >(receipt))->toString());
}

void rice::tutorial::sendfile::MyApp_MyFileListener::transferCancelled(::org::mpisws::p2p::filetransfer::Receipt* receipt, bool incoming)
{
    ::java::lang::String* s;
    if(incoming) {
        s = u"download"_j;
    } else {
        s = u"upload"_j;
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(MyApp_this))->append(u": Cancelled "_j)
        ->append(s)
        ->append(u" of "_j)
        ->append(static_cast< ::java::lang::Object* >(receipt))->toString());
}

void rice::tutorial::sendfile::MyApp_MyFileListener::transferFailed(::org::mpisws::p2p::filetransfer::Receipt* receipt, bool incoming)
{
    ::java::lang::String* s;
    if(incoming) {
        s = u"download"_j;
    } else {
        s = u"upload"_j;
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(MyApp_this))->append(u": Transfer Failed "_j)
        ->append(s)
        ->append(u" of "_j)
        ->append(static_cast< ::java::lang::Object* >(receipt))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::sendfile::MyApp_MyFileListener::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.sendfile.MyApp.MyFileListener", 43);
    return c;
}

java::lang::Class* rice::tutorial::sendfile::MyApp_MyFileListener::getClass0()
{
    return class_();
}

