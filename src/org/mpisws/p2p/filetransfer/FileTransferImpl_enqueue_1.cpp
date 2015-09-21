// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_enqueue_1.hpp>

#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>

org::mpisws::p2p::filetransfer::FileTransferImpl_enqueue_1::FileTransferImpl_enqueue_1(FileTransferImpl *FileTransferImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_enqueue_1::run()
{
    FileTransferImpl_this->scheduleToWriteIfNeeded();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_enqueue_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_enqueue_1::getClass0()
{
    return class_();
}

