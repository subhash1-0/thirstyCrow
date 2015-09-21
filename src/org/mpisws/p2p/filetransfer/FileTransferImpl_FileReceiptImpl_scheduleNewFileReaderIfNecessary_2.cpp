// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2.hpp>

#include <java/io/EOFException.hpp>
#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MessageWrapperImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2(FileTransferImpl_FileReceiptImpl *FileTransferImpl_FileReceiptImpl_this, int32_t amtToRead, int64_t seq, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileReceiptImpl_this(FileTransferImpl_FileReceiptImpl_this)
    , amtToRead(amtToRead)
    , seq(seq)
{
    clinit();
    ctor(c, sm);
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2(FileTransferImpl_FileReceiptImpl *FileTransferImpl_FileReceiptImpl_this, int32_t amtToRead, int64_t seq)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileReceiptImpl_this(FileTransferImpl_FileReceiptImpl_this)
    , amtToRead(amtToRead)
    , seq(seq)
{
    clinit();
    ctor();
}

java::lang::Object* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2::doWork() /* throws(Exception) */
{
    auto chunkBytes = new ::int8_tArray(int32_t(1) + int32_t(4) + int32_t(4)+ amtToRead);
    (*chunkBytes)[int32_t(0)] = FileTransferImpl::MSG_CHUNK;
    ::rice::p2p::util::MathUtils::intToByteArray_(FileTransferImpl_FileReceiptImpl_this->uid, chunkBytes, 1);
    ::rice::p2p::util::MathUtils::intToByteArray_(amtToRead, chunkBytes, 5);
    int64_t ret = npc(FileTransferImpl_FileReceiptImpl_this->file)->read(chunkBytes, int32_t(9), amtToRead);
    if(ret < 0) {
        throw new ::java::io::EOFException(::java::lang::StringBuilder().append(u"Unexpected EOF... cancelling "_j)->append(FileTransferImpl_FileReceiptImpl_this->uid)
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(FileTransferImpl_FileReceiptImpl_this->f))
            ->append(u"."_j)->toString());
    }
    auto foo = new ::java::util::ArrayList();
    npc(foo)->add(static_cast< ::java::lang::Object* >(::java::nio::ByteBuffer::wrap(chunkBytes)));
    FileTransferImpl_FileReceiptImpl_this->FileTransferImpl_this->enqueue(new FileTransferImpl_MessageWrapperImpl(FileTransferImpl_FileReceiptImpl_this->FileTransferImpl_this, FileTransferImpl_FileReceiptImpl_this, seq, foo));
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2::getClass0()
{
    return class_();
}

