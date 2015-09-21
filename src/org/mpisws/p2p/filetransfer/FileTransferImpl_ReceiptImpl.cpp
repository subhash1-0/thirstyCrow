// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_ReceiptImpl.hpp>

#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::FileTransferImpl_ReceiptImpl(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::FileTransferImpl_ReceiptImpl(FileTransferImpl *FileTransferImpl_this, int8_t priority, int32_t uid) 
    : FileTransferImpl_ReceiptImpl(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(priority,uid);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::init()
{
    cancelled = false;
    completed = false;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::ctor(int8_t priority, int32_t uid)
{
    super::ctor();
    init();
    this->priority = priority;
    this->uid = uid;
    npc(FileTransferImpl_this->outgoingData)->put(::java::lang::Integer::valueOf(uid), this);
}

int8_t org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::getPriority()
{
    return priority;
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::getUID()
{
    return uid;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::failed()
{
    FileTransferImpl_this->notifyListenersTransferFailed(this, false);
    cancelled = true;
    npc(FileTransferImpl_this->outgoingData)->remove(::java::lang::Integer::valueOf(uid));
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::isCancelled()
{
    return cancelled;
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::cancel()
{
    cancelled = true;
    npc(FileTransferImpl_this->outgoingData)->remove(::java::lang::Integer::valueOf(uid));
    FileTransferImpl_this->sendCancel(uid);
    return !completed;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.ReceiptImpl", 56);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl::getClass0()
{
    return class_();
}

