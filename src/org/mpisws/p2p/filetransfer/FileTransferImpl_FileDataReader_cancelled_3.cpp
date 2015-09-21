// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader_cancelled_3.hpp>

#include <java/io/File.hpp>
#include <java/io/RandomAccessFile.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/filetransfer/FileAllocationStrategy.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_3::FileTransferImpl_FileDataReader_cancelled_3(FileTransferImpl_FileDataReader *FileTransferImpl_FileDataReader_this, FileTransferImpl_DataReader* reader)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileDataReader_this(FileTransferImpl_FileDataReader_this)
    , reader(reader)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_3::receiveResult(::java::io::RandomAccessFile* result)
{
    if(npc(FileTransferImpl_FileDataReader_this->FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(FileTransferImpl_FileDataReader_this->FileTransferImpl_this->logger)->log(::java::lang::StringBuilder().append(u"File Cancelled<"_j)->append(FileTransferImpl_FileDataReader_this->uid)
            ->append(u"> "_j)
            ->append(static_cast< ::java::lang::Object* >(FileTransferImpl_FileDataReader_this->f))
            ->append(u","_j)
            ->append(FileTransferImpl_FileDataReader_this->offset)
            ->append(u","_j)
            ->append((FileTransferImpl_FileDataReader_this->ptr - FileTransferImpl_FileDataReader_this->offset))
            ->append(u","_j)
            ->append(FileTransferImpl_FileDataReader_this->length)->toString());

    npc(FileTransferImpl_FileDataReader_this->FileTransferImpl_this->fileAllocater)->fileCancelled(::java::nio::ByteBuffer::wrap(FileTransferImpl_FileDataReader_this->metadata), FileTransferImpl_FileDataReader_this->f, FileTransferImpl_FileDataReader_this->offset, FileTransferImpl_FileDataReader_this->ptr - FileTransferImpl_FileDataReader_this->offset, FileTransferImpl_FileDataReader_this->length, FileTransferImpl_FileDataReader_this->exception);
    FileTransferImpl_FileDataReader_this->FileTransferImpl_this->notifyListenersSenderCancelled(reader);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_3::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::io::RandomAccessFile* >(result));
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_3::receiveException(::java::lang::Exception* exception)
{
    if(npc(FileTransferImpl_FileDataReader_this->FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(FileTransferImpl_FileDataReader_this->FileTransferImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Error closing file "_j)->append(static_cast< ::java::lang::Object* >(FileTransferImpl_FileDataReader_this->file))->toString(), exception);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_3::getClass0()
{
    return class_();
}

