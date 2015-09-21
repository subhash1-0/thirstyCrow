// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader_cancelled_4.hpp>

#include <java/io/RandomAccessFile.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_4::FileTransferImpl_FileDataReader_cancelled_4(FileTransferImpl_FileDataReader *FileTransferImpl_FileDataReader_this, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileDataReader_this(FileTransferImpl_FileDataReader_this)
{
    clinit();
    ctor(c, sm);
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_4::FileTransferImpl_FileDataReader_cancelled_4(FileTransferImpl_FileDataReader *FileTransferImpl_FileDataReader_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileDataReader_this(FileTransferImpl_FileDataReader_this)
{
    clinit();
    ctor();
}

java::io::RandomAccessFile* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_4::doWork() /* throws(Exception) */
{
    npc(FileTransferImpl_FileDataReader_this->file)->close();
    return FileTransferImpl_FileDataReader_this->file;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_cancelled_4::getClass0()
{
    return class_();
}

