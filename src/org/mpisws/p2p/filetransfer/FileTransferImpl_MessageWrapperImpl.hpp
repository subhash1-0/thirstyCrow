// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MessageWrapper.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl
    : public virtual ::java::lang::Object
    , public virtual FileTransferImpl_MessageWrapper
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    bool started {  };
    FileTransferImpl_ReceiptImpl* receipt {  };
    ::java::util::List* message {  };
    int64_t seq {  };
protected:
    void ctor(FileTransferImpl_ReceiptImpl* receipt, int64_t seq, ::java::util::List* message);

public:
    ::java::lang::String* toString() override;
    void drop() override;
    virtual bool cancel();
    virtual void clear(::java::util::LinkedList* message, int64_t seq);
    virtual int32_t compareTo(FileTransferImpl_MessageWrapper* that);
    bool receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */ override;
    void complete() override;
    int8_t getPriority() override;
    int64_t getSeq() override;
    int32_t getUid() override;

    // Generated
    FileTransferImpl_MessageWrapperImpl(FileTransferImpl *FileTransferImpl_this, FileTransferImpl_ReceiptImpl* receipt, int64_t seq, ::java::util::List* message);
protected:
    FileTransferImpl_MessageWrapperImpl(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual int32_t compareTo(::java::lang::Object* arg0) override;
    FileTransferImpl *FileTransferImpl_this;

private:
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
