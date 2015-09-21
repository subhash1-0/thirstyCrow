// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader_completeChunk_1.hpp>

#include <java/io/File.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_1::FileTransferImpl_FileDataReader_completeChunk_1(FileTransferImpl_FileDataReader *FileTransferImpl_FileDataReader_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileDataReader_this(FileTransferImpl_FileDataReader_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_1::receiveResult(::java::lang::Long* myPtrL)
{
    FileTransferImpl_FileDataReader_this->FileTransferImpl_this->decrementFileChunksInMemory();
    if(FileTransferImpl_FileDataReader_this->cancelled_)
        return;

    auto myPtr = npc(myPtrL)->longValue();
    FileTransferImpl_FileDataReader_this->FileTransferImpl_this->notifyListenersReceiveFileProgress(FileTransferImpl_FileDataReader_this, myPtr - FileTransferImpl_FileDataReader_this->offset, FileTransferImpl_FileDataReader_this->length);
    if(myPtr == FileTransferImpl_FileDataReader_this->offset + FileTransferImpl_FileDataReader_this->length)
        FileTransferImpl_FileDataReader_this->complete();

}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::lang::Long* >(result));
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_1::receiveException(::java::lang::Exception* exception)
{
    if(npc(FileTransferImpl_FileDataReader_this->FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(FileTransferImpl_FileDataReader_this->FileTransferImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Error writing file "_j)->append(static_cast< ::java::lang::Object* >(FileTransferImpl_FileDataReader_this->f))
            ->append(u" "_j)
            ->append(npc(FileTransferImpl_FileDataReader_this->metadata)->length)->toString(), exception);

    FileTransferImpl_FileDataReader_this->cancel();
    FileTransferImpl_FileDataReader_this->FileTransferImpl_this->decrementFileChunksInMemory();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_1::getClass0()
{
    return class_();
}

