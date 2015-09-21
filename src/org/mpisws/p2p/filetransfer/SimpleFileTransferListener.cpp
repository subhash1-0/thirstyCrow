// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/SimpleFileTransferListener.java
#include <org/mpisws/p2p/filetransfer/SimpleFileTransferListener.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <org/mpisws/p2p/filetransfer/BBReceipt.hpp>
#include <org/mpisws/p2p/filetransfer/FileReceipt.hpp>
#include <org/mpisws/p2p/filetransfer/Receipt.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::SimpleFileTransferListener::SimpleFileTransferListener(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::filetransfer::SimpleFileTransferListener::SimpleFileTransferListener(::java::lang::String* prefix) 
    : SimpleFileTransferListener(*static_cast< ::default_init_tag* >(0))
{
    ctor(prefix);
}

void org::mpisws::p2p::filetransfer::SimpleFileTransferListener::ctor(::java::lang::String* prefix)
{
    super::ctor();
    this->prefix = prefix;
}

void org::mpisws::p2p::filetransfer::SimpleFileTransferListener::fileTransferred(FileReceipt* receipt, int64_t bytesTransferred, int64_t total, bool incoming)
{
    ::java::lang::String* s;
    if(incoming) {
        s = u" Downloaded "_j;
    } else {
        s = u" Uploaded "_j;
    }
    auto percent = 100.0 * bytesTransferred / total;
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(prefix)->append(s)
        ->append(percent)
        ->append(u"% of "_j)
        ->append(static_cast< ::java::lang::Object* >(receipt))->toString());
}

void org::mpisws::p2p::filetransfer::SimpleFileTransferListener::msgTransferred(BBReceipt* receipt, int32_t bytesTransferred, int32_t total, bool incoming)
{
    ::java::lang::String* s;
    if(incoming) {
        s = u" Downloaded "_j;
    } else {
        s = u" Uploaded "_j;
    }
    auto percent = 100.0 * bytesTransferred / total;
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(prefix)->append(s)
        ->append(percent)
        ->append(u"% of "_j)
        ->append(static_cast< ::java::lang::Object* >(receipt))->toString());
}

void org::mpisws::p2p::filetransfer::SimpleFileTransferListener::transferCancelled(Receipt* receipt, bool incoming)
{
    ::java::lang::String* s;
    if(incoming) {
        s = u"download"_j;
    } else {
        s = u"upload"_j;
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(prefix)->append(u": Cancelled "_j)
        ->append(s)
        ->append(u" of "_j)
        ->append(static_cast< ::java::lang::Object* >(receipt))->toString());
}

void org::mpisws::p2p::filetransfer::SimpleFileTransferListener::transferFailed(Receipt* receipt, bool incoming)
{
    ::java::lang::String* s;
    if(incoming) {
        s = u"download"_j;
    } else {
        s = u"upload"_j;
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(prefix)->append(u": Failed "_j)
        ->append(s)
        ->append(u" of "_j)
        ->append(static_cast< ::java::lang::Object* >(receipt))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::SimpleFileTransferListener::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.SimpleFileTransferListener", 54);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::SimpleFileTransferListener::getClass0()
{
    return class_();
}

