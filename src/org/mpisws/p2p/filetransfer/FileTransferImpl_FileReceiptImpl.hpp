// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_ReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileReceipt.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::FileTransferImpl_FileReceiptImpl
    : public FileTransferImpl_ReceiptImpl
    , public virtual FileReceipt
{

public:
    typedef FileTransferImpl_ReceiptImpl super;

public: /* package */
    ::java::io::FileInputStream* file {  };
    ::java::io::File* f {  };
    ::int8_tArray* metadata {  };
    ::rice::Continuation* deliverAckToMe {  };
    ::java::util::List* outstanding {  };
    ::java::util::List* outstandingWRs {  };
    int32_t wrapperSeq {  };
    int64_t lastByte {  };
    int64_t ptr {  };
    int64_t length {  };
    int64_t initialPosition {  };
protected:
    void ctor(::java::io::File* f, ::int8_tArray* metadata, int8_t priority, int64_t offset, int64_t length, int32_t uid, ::rice::Continuation* c) /* throws(IOException) */;

public: /* package */
    void failed() override;

public:
    ::java::lang::String* toString() override;
    virtual void scheduleNewFileReaderIfNecessary();

public: /* package */
    bool closing {  };
    virtual void scheduleClose();
    void complete(FileTransferImpl_MessageWrapper* wrapper) override;

public:
    int64_t getSize() override;
    ::java::io::File* getFile() override;
    virtual int64_t getLength();
    ::java::nio::ByteBuffer* getMetadata() override;
    int64_t getOffset() override;
    bool cancel() override;

public: /* protected */
    virtual void superCancel();

public:
    void notifyReceiverCancelled() override;

    // Generated
    FileTransferImpl_FileReceiptImpl(FileTransferImpl *FileTransferImpl_this, ::java::io::File* f, ::int8_tArray* metadata, int8_t priority, int64_t offset, int64_t length, int32_t uid, ::rice::Continuation* c);
protected:
    FileTransferImpl_FileReceiptImpl(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual int8_t getPriority();
    virtual int32_t getUID();

private:
    virtual ::java::lang::Class* getClass0();
    friend class FileTransferImpl;
    friend class FileTransferImpl_enqueue_1;
    friend class FileTransferImpl_ReceiptImpl;
    friend class FileTransferImpl_BBReceiptImpl;
    friend class FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_1;
    friend class FileTransferImpl_FileReceiptImpl_scheduleNewFileReaderIfNecessary_2;
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
