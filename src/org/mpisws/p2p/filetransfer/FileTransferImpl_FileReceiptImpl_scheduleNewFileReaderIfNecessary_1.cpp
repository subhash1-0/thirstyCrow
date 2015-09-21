// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/Continuation.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1(FileTransferImpl_FileReceiptImpl *FileTransferImpl_FileReceiptImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileReceiptImpl_this(FileTransferImpl_FileReceiptImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1::receiveResult(::java::lang::Object* result)
{
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1::receiveException(::java::lang::Exception* exception)
{
    if(FileTransferImpl_FileReceiptImpl_this->deliverAckToMe != nullptr)
        npc(FileTransferImpl_FileReceiptImpl_this->deliverAckToMe)->receiveException(exception);

    FileTransferImpl_FileReceiptImpl_this->FileTransferImpl_this->sendCancel(FileTransferImpl_FileReceiptImpl_this->uid);
    return;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1::getClass0()
{
    return class_();
}

