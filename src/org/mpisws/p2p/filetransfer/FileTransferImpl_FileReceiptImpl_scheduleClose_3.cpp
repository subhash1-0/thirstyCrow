// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_scheduleClose_3.hpp>

#include <java/io/FileInputStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleClose_3::FileTransferImpl_FileReceiptImpl_scheduleClose_3(FileTransferImpl_FileReceiptImpl *FileTransferImpl_FileReceiptImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileReceiptImpl_this(FileTransferImpl_FileReceiptImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleClose_3::receiveResult(::java::lang::Object* result)
{
    npc(FileTransferImpl_FileReceiptImpl_this->FileTransferImpl_this->outgoingData)->remove(::java::lang::Integer::valueOf(FileTransferImpl_FileReceiptImpl_this->uid));
    if(FileTransferImpl_FileReceiptImpl_this->deliverAckToMe != nullptr)
        npc(FileTransferImpl_FileReceiptImpl_this->deliverAckToMe)->receiveResult(FileTransferImpl_FileReceiptImpl_this);

}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleClose_3::receiveException(::java::lang::Exception* exception)
{
    if(npc(FileTransferImpl_FileReceiptImpl_this->FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(FileTransferImpl_FileReceiptImpl_this->FileTransferImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Error closing file <"_j)->append(FileTransferImpl_FileReceiptImpl_this->uid)
            ->append(u"> "_j)
            ->append(static_cast< ::java::lang::Object* >(FileTransferImpl_FileReceiptImpl_this->file))
            ->append(u" "_j)
            ->append(npc(FileTransferImpl_FileReceiptImpl_this->metadata)->length)->toString(), exception);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleClose_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleClose_3::getClass0()
{
    return class_();
}

