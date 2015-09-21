// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/Receipt.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::FileTransferImpl_ReceiptImpl
    : public virtual ::java::lang::Object
    , public virtual Receipt
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int8_t priority {  };
    int32_t uid {  };
    bool cancelled {  };
    bool completed {  };
protected:
    void ctor(int8_t priority, int32_t uid);

public:
    int8_t getPriority() override;
    int32_t getUID() override;

public: /* package */
    virtual void failed();

public:
    virtual bool isCancelled();

public: /* package */
    virtual void complete(FileTransferImpl_MessageWrapper* wrapper) = 0;

public:
    bool cancel() override;
    virtual void notifyReceiverCancelled() = 0;

    // Generated
    FileTransferImpl_ReceiptImpl(FileTransferImpl *FileTransferImpl_this, int8_t priority, int32_t uid);
protected:
    FileTransferImpl_ReceiptImpl(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    FileTransferImpl *FileTransferImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class FileTransferImpl;
    friend class FileTransferImpl_enqueue_1;
    friend class FileTransferImpl_BBReceiptImpl;
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
