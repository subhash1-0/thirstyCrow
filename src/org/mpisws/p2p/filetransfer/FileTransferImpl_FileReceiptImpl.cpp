// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl.hpp>

#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_scheduleClose_3.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_scheduleClose_4.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_cancel_5.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_cancel_6.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MessageWrapperImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <org/mpisws/p2p/filetransfer/OperationCancelledException.hpp>
#include <org/mpisws/p2p/filetransfer/TransferFailedException.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/environment/processing/WorkRequest.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <Array.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::FileTransferImpl_FileReceiptImpl(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::FileTransferImpl_FileReceiptImpl(FileTransferImpl *FileTransferImpl_this, ::java::io::File* f, ::int8_tArray* metadata, int8_t priority, int64_t offset, int64_t length, int32_t uid, ::rice::Continuation* c)  /* throws(IOException) */
    : FileTransferImpl_FileReceiptImpl(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(f,metadata,priority,offset,length,uid,c);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::init()
{
    outstanding = new ::java::util::ArrayList();
    outstandingWRs = new ::java::util::ArrayList();
    wrapperSeq = ::java::lang::Integer::MIN_VALUE;
    closing = false;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::ctor(::java::io::File* f, ::int8_tArray* metadata, int8_t priority, int64_t offset, int64_t length, int32_t uid, ::rice::Continuation* c) /* throws(IOException) */
{
    super::ctor(priority, uid);
    init();
    if(offset + length > npc(f)->length())
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"File is only "_j)->append(npc(f)->length())
            ->append(u" but you are trying to send "_j)
            ->append(length)
            ->append(u" bytes starting at "_j)
            ->append(offset)->toString());

    this->f = f;
    this->metadata = metadata;
    try {
        this->file = new ::java::io::FileInputStream(f);
    } catch (::java::io::IOException* ioe) {
        failed();
        throw ioe;
    } catch (::java::lang::RuntimeException* re) {
        failed();
        throw re;
    } catch (::java::lang::Throwable* t) {
        failed();
        throw new ::java::lang::RuntimeException(t);
    }
    npc(file)->skip(offset);
    lastByte = offset + length;
    this->deliverAckToMe = c;
    this->initialPosition = offset;
    this->ptr = offset;
    this->length = length;
    auto msgList = new ::java::util::ArrayList();
    auto hdr = ::java::nio::ByteBuffer::allocate(25);
    npc(hdr)->put(FileTransferImpl::MSG_FILE_HEADER);
    npc(hdr)->put(::rice::p2p::util::MathUtils::intToByteArray_(uid));
    npc(hdr)->put(::rice::p2p::util::MathUtils::longToByteArray_(offset));
    npc(hdr)->put(::rice::p2p::util::MathUtils::longToByteArray_(length));
    npc(hdr)->put(::rice::p2p::util::MathUtils::intToByteArray_(npc(metadata)->length));
    npc(hdr)->clear();
    npc(msgList)->add(static_cast< ::java::lang::Object* >(hdr));
    npc(msgList)->add(static_cast< ::java::lang::Object* >(::java::nio::ByteBuffer::wrap(metadata)));
    auto foo = new FileTransferImpl_MessageWrapperImpl(FileTransferImpl_this, this, wrapperSeq++, msgList);
    FileTransferImpl_this->enqueue(foo);
    for (auto i = int32_t(0); i < FileTransferImpl_this->NUM_OUTSTANDING_CHUNKS_TO_WRITE_TO_NETWORK - int32_t(1); i++) {
        scheduleNewFileReaderIfNecessary();
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::failed()
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->receiveException(new TransferFailedException(this));

    super::failed();
}

java::lang::String* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"Outgoing file<"_j)->append(uid)
        ->append(u"> "_j)
        ->append(npc(metadata)->length)
        ->append(u" size:"_j)
        ->append(getSize())
        ->append(u" priority:"_j)
        ->append(priority)
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(f))->toString();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::scheduleNewFileReaderIfNecessary()
{
    if(cancelled)
        return;

    if(ptr < lastByte) {
        auto const amtToRead = static_cast< int32_t >(::java::lang::Math::min(static_cast< int64_t >(FileTransferImpl_this->CHUNK_SIZE), lastByte - ptr));
        int64_t const seq = wrapperSeq++;
        ptr += amtToRead;
        ::rice::Continuation* c = new FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1(this);
        npc(FileTransferImpl_this->processor)->processBlockingIO(new FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2(this, amtToRead, seq, c, npc(FileTransferImpl_this->environment)->getSelectorManager()));
        if(ptr == lastByte) {
            scheduleClose();
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::scheduleClose()
{
    {
        synchronized synchronized_0(this);
        {
            if(closing)
                return;

            closing = true;
        }
    }
    ::rice::Continuation* c2 = new FileTransferImpl_FileReceiptImpl_scheduleClose_3(this);
    npc(FileTransferImpl_this->processor)->processBlockingIO(new FileTransferImpl_FileReceiptImpl_scheduleClose_4(this, c2, npc(FileTransferImpl_this->environment)->getSelectorManager()));
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::complete(FileTransferImpl_MessageWrapper* wrapper)
{
    FileTransferImpl_this->notifyListenersSendFileProgress(this, ptr - initialPosition, length);
    if(cancelled)
        return;

    scheduleNewFileReaderIfNecessary();
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::getSize()
{
    return length;
}

java::io::File* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::getFile()
{
    return f;
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::getLength()
{
    return length;
}

java::nio::ByteBuffer* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::getMetadata()
{
    return ::java::nio::ByteBuffer::wrap(metadata);
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::getOffset()
{
    return initialPosition;
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::cancel()
{
    cancelled = true;
    for (auto _i = npc(outstandingWRs)->iterator(); _i->hasNext(); ) {
        ::rice::environment::processing::WorkRequest* wr = java_cast< ::rice::environment::processing::WorkRequest* >(_i->next());
        {
            npc(wr)->cancel();
        }
    }
    for (auto _i = npc(outstanding)->iterator(); _i->hasNext(); ) {
        FileTransferImpl_MessageWrapperImpl* mri = java_cast< FileTransferImpl_MessageWrapperImpl* >(_i->next());
        {
            npc(mri)->cancel();
        }
    }
    scheduleClose();
    ::rice::Continuation* c = new FileTransferImpl_FileReceiptImpl_cancel_5(this);
    npc(FileTransferImpl_this->processor)->processBlockingIO(new FileTransferImpl_FileReceiptImpl_cancel_6(this, c, npc(FileTransferImpl_this->environment)->getSelectorManager()));
    return true;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::superCancel()
{
    super::cancel();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::notifyReceiverCancelled()
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->receiveException(new OperationCancelledException(this));

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.FileReceiptImpl", 60);
    return c;
}

int8_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::getPriority()
{
    return FileTransferImpl_ReceiptImpl::getPriority();
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::getUID()
{
    return FileTransferImpl_ReceiptImpl::getUID();
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl::getClass0()
{
    return class_();
}

