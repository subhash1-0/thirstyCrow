// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_ReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/BBReceipt.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::FileTransferImpl_BBReceiptImpl
    : public FileTransferImpl_ReceiptImpl
    , public virtual BBReceipt
{

public:
    typedef FileTransferImpl_ReceiptImpl super;

public: /* package */
    ::java::nio::ByteBuffer* msg {  };
    ::int8_tArray* msgBytes {  };
    ::java::util::LinkedList* msgList {  };
    ::java::nio::ByteBuffer* header {  };
    FileTransferImpl_MessageWrapperImpl* outstanding {  };
    int32_t wrapperSeq {  };
    ::java::nio::ByteBuffer* chunkBuffer {  };
    int32_t initialPosition {  };
    ::rice::Continuation* deliverAckToMe {  };
protected:
    void ctor(::java::nio::ByteBuffer* bb, int8_t priority, int32_t uid, ::rice::Continuation* c);

public:
    ::java::lang::String* toString() override;

public: /* package */
    void failed() override;
    void complete(FileTransferImpl_MessageWrapper* wrapper) override;

public:
    ::int8_tArray* getBytes() override;
    int64_t getSize() override;
    bool cancel() override;
    void notifyReceiverCancelled() override;

    // Generated
    FileTransferImpl_BBReceiptImpl(FileTransferImpl *FileTransferImpl_this, ::java::nio::ByteBuffer* bb, int8_t priority, int32_t uid, ::rice::Continuation* c);
protected:
    FileTransferImpl_BBReceiptImpl(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&);


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
    friend class FileTransferImpl_FileReceiptImpl;
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
