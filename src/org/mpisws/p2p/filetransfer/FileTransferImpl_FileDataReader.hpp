// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_DataReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileReceipt.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader
    : public virtual ::java::lang::Object
    , public virtual FileTransferImpl_DataReader
    , public virtual FileReceipt
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t uid {  };
    ::int8_tArray* bytes {  };
    ::java::nio::ByteBuffer* curReader {  };
    ::java::io::RandomAccessFile* file {  };
    ::java::io::File* f {  };
    ::int8_tArray* metadata {  };
    int64_t offset {  };
    int64_t length {  };
    int64_t ptr {  };
    bool requestedCancel {  };
    bool cancelled_ {  };
    ::java::lang::Exception* exception {  };
protected:
    void ctor(int32_t uid, ::int8_tArray* metadata, ::java::io::File* f, int64_t offset, int64_t length) /* throws(IOException) */;

public:
    ::java::lang::String* toString() override;
    bool read(::rice::p2p::commonapi::appsocket::AppSocket* socket, int32_t numToRead) /* throws(IOException) */ override;
    bool read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */ override;
    virtual void completeChunk();
    virtual void complete();
    virtual ::int8_tArray* getBytes();
    int8_t getPriority() override;
    int64_t getSize() override;
    int32_t getUID() override;
    bool cancel() override;
    ::java::io::File* getFile() override;
    virtual int64_t getLength();
    ::java::nio::ByteBuffer* getMetadata() override;
    int64_t getOffset() override;
    void cancelled(FileTransferImpl_DataReader* reader) override;

    // Generated
    FileTransferImpl_FileDataReader(FileTransferImpl *FileTransferImpl_this, int32_t uid, ::int8_tArray* metadata, ::java::io::File* f, int64_t offset, int64_t length);
protected:
    FileTransferImpl_FileDataReader(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&);


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
    friend class FileTransferImpl_BBDataReader;
    friend class FileTransferImpl_FileDataReader_completeChunk_1;
    friend class FileTransferImpl_FileDataReader_completeChunk_2;
    friend class FileTransferImpl_FileDataReader_cancelled_3;
    friend class FileTransferImpl_FileDataReader_cancelled_4;
    friend class FileTransferImpl_SimpleMessageWrapper;
};
