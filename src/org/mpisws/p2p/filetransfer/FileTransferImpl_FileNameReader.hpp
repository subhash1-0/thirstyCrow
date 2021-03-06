// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_Reader.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::FileTransferImpl_FileNameReader
    : public virtual ::java::lang::Object
    , public virtual FileTransferImpl_Reader
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::int8_tArray* bytes {  };
    ::java::nio::ByteBuffer* buf {  };
    int32_t uid {  };
    int64_t offset {  };
    int64_t length {  };

public:
    virtual void initialize(int32_t uid, int64_t offset, int64_t length, int32_t nameSize);
    bool read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */ override;

    // Generated
    FileTransferImpl_FileNameReader(FileTransferImpl *FileTransferImpl_this);
protected:
    void ctor();
    FileTransferImpl_FileNameReader(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&);


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
