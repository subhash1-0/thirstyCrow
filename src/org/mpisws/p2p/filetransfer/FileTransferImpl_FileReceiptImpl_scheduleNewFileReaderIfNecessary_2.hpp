// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/WorkRequest.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2
    : public ::rice::environment::processing::WorkRequest
{

public:
    typedef ::rice::environment::processing::WorkRequest super;
    ::java::lang::Object* doWork() /* throws(Exception) */ override;

    // Generated
    FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2(FileTransferImpl_FileReceiptImpl *FileTransferImpl_FileReceiptImpl_this, int32_t amtToRead, int64_t seq, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm);
    FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2(FileTransferImpl_FileReceiptImpl *FileTransferImpl_FileReceiptImpl_this, int32_t amtToRead, int64_t seq);
    static ::java::lang::Class *class_();
    FileTransferImpl_FileReceiptImpl *FileTransferImpl_FileReceiptImpl_this;
    int32_t amtToRead;
    int64_t seq;

private:
    virtual ::java::lang::Class* getClass0();
    friend class FileTransferImpl;
    friend class FileTransferImpl_enqueue_1;
    friend class FileTransferImpl_ReceiptImpl;
    friend class FileTransferImpl_BBReceiptImpl;
    friend class FileTransferImpl_FileReceiptImpl;
    friend class FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1;
    friend class FileTransferImpl_FileReceiptImpl_scheduleClose_3;
    friend class FileTransferImpl_FileReceiptImpl_scheduleClose_4;
    friend class FileTransferImpl_FileReceiptImpl_cancel_5;
    friend class FileTransferImpl_FileReceiptImpl_cancel_6;
    friend class FileTransferImpl_MessageWrapper;
    friend class FileTransferImpl_MessageWrapperImpl;
    friend class FileTransferImpl_Reader;
    friend class FileTransferImpl_MsgTypeReader;
    friend class FileTransferImpl_BBHeaderReader;
    friend class FileTransferImpl_FileHeaderReader;
    friend class FileTransferImpl_FileNameReader;
    friend class FileTransferImpl_ChunkReader;
    friend class FileTransferImpl_DataReader;
    friend class FileTransferImpl_BBDataReader;
    friend class FileTransferImpl_FileDataReader;
    friend class FileTransferImpl_FileDataReader_completeChunk_1;
    friend class FileTransferImpl_FileDataReader_completeChunk_2;
    friend class FileTransferImpl_FileDataReader_cancelled_3;
    friend class FileTransferImpl_FileDataReader_cancelled_4;
    friend class FileTransferImpl_SimpleMessageWrapper;
};
