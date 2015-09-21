// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader_completeChunk_2.hpp>

#include <java/io/RandomAccessFile.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader.hpp>
#include <Array.hpp>

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
org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_2::FileTransferImpl_FileDataReader_completeChunk_2(FileTransferImpl_FileDataReader *FileTransferImpl_FileDataReader_this, ::int8_tArray* writeMe, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileDataReader_this(FileTransferImpl_FileDataReader_this)
    , writeMe(writeMe)
{
    clinit();
    ctor(c, sm);
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_2::FileTransferImpl_FileDataReader_completeChunk_2(FileTransferImpl_FileDataReader *FileTransferImpl_FileDataReader_this, ::int8_tArray* writeMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_FileDataReader_this(FileTransferImpl_FileDataReader_this)
    , writeMe(writeMe)
{
    clinit();
    ctor();
}

java::lang::Long* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_2::doWork() /* throws(Exception) */
{
    if(cancelled)
        return ::java::lang::Long::valueOf(-int64_t(1LL));

    npc(FileTransferImpl_FileDataReader_this->file)->write(writeMe);
    {
        synchronized synchronized_0(FileTransferImpl_FileDataReader_this);
        {
            FileTransferImpl_FileDataReader_this->ptr += npc(writeMe)->length;
        }
    }
    return ::java::lang::Long::valueOf(FileTransferImpl_FileDataReader_this->ptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader_completeChunk_2::getClass0()
{
    return class_();
}

