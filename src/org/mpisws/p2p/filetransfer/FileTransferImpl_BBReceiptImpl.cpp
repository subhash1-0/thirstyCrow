// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_BBReceiptImpl.hpp>

#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MessageWrapperImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <org/mpisws/p2p/filetransfer/OperationCancelledException.hpp>
#include <org/mpisws/p2p/filetransfer/TransferFailedException.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::FileTransferImpl_BBReceiptImpl(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::FileTransferImpl_BBReceiptImpl(FileTransferImpl *FileTransferImpl_this, ::java::nio::ByteBuffer* bb, int8_t priority, int32_t uid, ::rice::Continuation* c) 
    : FileTransferImpl_BBReceiptImpl(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(bb,priority,uid,c);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::init()
{
    wrapperSeq = ::java::lang::Integer::MIN_VALUE + int32_t(10);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::ctor(::java::nio::ByteBuffer* bb, int8_t priority, int32_t uid, ::rice::Continuation* c)
{
    super::ctor(priority, uid);
    init();
    this->deliverAckToMe = c;
    this->msg = bb;
    initialPosition = npc(msg)->position();
    this->msgBytes = npc(bb)->array();
    msgList = new ::java::util::LinkedList();
    chunkBuffer = ::java::nio::ByteBuffer::wrap(msgBytes);
    npc(chunkBuffer)->position(npc(msg)->position());
    npc(chunkBuffer)->limit(npc(msg)->limit());
    header = ::java::nio::ByteBuffer::allocate(9);
    npc(header)->put(FileTransferImpl::MSG_BB_HEADER);
    npc(header)->put(::rice::p2p::util::MathUtils::intToByteArray_(uid));
    npc(header)->put(::rice::p2p::util::MathUtils::intToByteArray_(npc(bb)->remaining()));
    npc(header)->clear();
    npc(msgList)->add(static_cast< ::java::lang::Object* >(header));
    outstanding = new FileTransferImpl_MessageWrapperImpl(FileTransferImpl_this, this, wrapperSeq++, msgList);
    FileTransferImpl_this->enqueue(outstanding);
}

java::lang::String* org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"Outgoing msg<"_j)->append(uid)
        ->append(u"> size:"_j)
        ->append(getSize())
        ->append(u" priority:"_j)
        ->append(priority)
        ->append(u" msg:"_j)
        ->append(static_cast< ::java::lang::Object* >(msg))->toString();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::failed()
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->receiveException(new TransferFailedException(this));

    super::failed();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::complete(FileTransferImpl_MessageWrapper* wrapper)
{
    npc(msg)->position(npc(chunkBuffer)->position());
    FileTransferImpl_this->notifyListenersSendMsgProgress(this, npc(msg)->position() - initialPosition, npc(msg)->limit() - initialPosition);
    if(npc(msg)->hasRemaining()) {
        if(npc(msg)->remaining() > FileTransferImpl_this->CHUNK_SIZE) {
            npc(chunkBuffer)->limit(npc(msg)->position() + FileTransferImpl_this->CHUNK_SIZE);
        } else {
            npc(chunkBuffer)->limit(npc(msg)->limit());
        }
        npc(header)->clear();
        npc(header)->put(FileTransferImpl::MSG_CHUNK);
        npc(header)->put(::rice::p2p::util::MathUtils::intToByteArray_(uid));
        npc(header)->put(::rice::p2p::util::MathUtils::intToByteArray_(npc(chunkBuffer)->remaining()));
        npc(header)->clear();
        npc(msgList)->add(static_cast< ::java::lang::Object* >(header));
        npc(msgList)->add(static_cast< ::java::lang::Object* >(chunkBuffer));
        npc(outstanding)->clear(msgList, wrapperSeq++);
        FileTransferImpl_this->enqueue(outstanding);
        return;
    }
    npc(FileTransferImpl_this->outgoingData)->remove(::java::lang::Integer::valueOf(uid));
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->receiveResult(this);

    completed = true;
}

int8_tArray* org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::getBytes()
{
    return msgBytes;
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::getSize()
{
    return npc(msg)->limit() - initialPosition;
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::cancel()
{
    npc(outstanding)->cancel();
    return super::cancel();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::notifyReceiverCancelled()
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->receiveException(new OperationCancelledException(this));

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.BBReceiptImpl", 58);
    return c;
}

int8_t org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::getPriority()
{
    return FileTransferImpl_ReceiptImpl::getPriority();
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::getUID()
{
    return FileTransferImpl_ReceiptImpl::getUID();
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl::getClass0()
{
    return class_();
}

