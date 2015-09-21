// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_cancel_5.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MessageWrapperImpl.hpp>
#include <rice/environment/processing/WorkRequest.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_cancel_5::FileTransferImpl_FileReceiptImpl_cancel_5(FileTransferImpl_FileReceiptImpl *FileTransferImpl_FileReceiptImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileReceiptImpl_this(FileTransferImpl_FileReceiptImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_cancel_5::receiveResult(::java::lang::Object* result)
{
    for (auto _i = npc(FileTransferImpl_FileReceiptImpl_this->outstandingWRs)->iterator(); _i->hasNext(); ) {
        ::rice::environment::processing::WorkRequest* wr = java_cast< ::rice::environment::processing::WorkRequest* >(_i->next());
        {
            npc(wr)->cancel();
        }
    }
    for (auto _i = npc(FileTransferImpl_FileReceiptImpl_this->outstanding)->iterator(); _i->hasNext(); ) {
        FileTransferImpl_MessageWrapperImpl* mri = java_cast< FileTransferImpl_MessageWrapperImpl* >(_i->next());
        {
            npc(mri)->cancel();
        }
    }
    FileTransferImpl_FileReceiptImpl_this->superCancel();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_cancel_5::receiveException(::java::lang::Exception* exception)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_cancel_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_cancel_5::getClass0()
{
    return class_();
}

