// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_DataReader.hpp>
#include <org/mpisws/p2p/filetransfer/BBReceipt.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader
    : public virtual ::java::lang::Object
    , public virtual FileTransferImpl_DataReader
    , public virtual BBReceipt
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t uid {  };
    ::int8_tArray* bytes {  };
    ::java::nio::ByteBuffer* curReader {  };
    bool requestedCancel {  };
protected:
    void ctor(int32_t uid, int32_t size);

public:
    ::java::lang::String* toString() override;
    bool read(::rice::p2p::commonapi::appsocket::AppSocket* socket, int32_t numToRead) /* throws(IOException) */ override;
    bool read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */ override;
    virtual void completeChunk();
    virtual void complete();
    ::int8_tArray* getBytes() override;
    int8_t getPriority() override;
    int64_t getSize() override;
    int32_t getUID() override;
    bool cancel() override;
    void cancelled(FileTransferImpl_DataReader* reader) override;

    // Generated
    FileTransferImpl_BBDataReader(FileTransferImpl *FileTransferImpl_this, int32_t uid, int32_t size);
protected:
    FileTransferImpl_BBDataReader(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    FileTransferImpl *FileTransferImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class FileTransferImpl;
    friend class FileTransferImpl_enqueue_1;
    friend class FileTransferImpl_ReceiptImpl;
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
    friend class FileTransferImpl_FileDataReader;
    friend class FileTransferImpl_FileDataReader_completeChunk_1;
    friend class FileTransferImpl_FileDataReader_completeChunk_2;
    friend class FileTransferImpl_FileDataReader_cancelled_3;
    friend class FileTransferImpl_FileDataReader_cancelled_4;
    friend class FileTransferImpl_SimpleMessageWrapper;
};
