// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransfer.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::FileTransferImpl
    : public virtual ::java::lang::Object
    , public virtual FileTransfer
    , public virtual ::rice::p2p::commonapi::appsocket::AppSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    static constexpr int8_t MSG_FILE_HEADER { int8_t(1) };
    static constexpr int8_t MSG_BB_HEADER { int8_t(2) };
    static constexpr int8_t MSG_CHUNK { int8_t(3) };
    static constexpr int8_t MSG_CANCEL { int8_t(4) };
    static constexpr int8_t MSG_CANCEL_REQUEST { int8_t(5) };

public: /* protected */
    FileAllocationStrategy* fileAllocater {  };
    ::rice::p2p::commonapi::appsocket::AppSocket* socket {  };
    FileTransferCallback* callback {  };

public: /* package */
    int32_t MAX_QUEUE_SIZE {  };

public: /* protected */
    int32_t CHUNK_SIZE {  };

public: /* package */
    int32_t NUM_OUTSTANDING_CHUNKS_TO_WRITE_TO_NETWORK {  };

public: /* protected */
    int32_t FILE_CACHE {  };

public: /* package */
    ::java::nio::ByteBuffer* byteBuffer {  };

public: /* protected */
    ::rice::selector::SelectorManager* selectorManager {  };
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::processing::Processor* processor {  };
    ::rice::environment::Environment* environment {  };

public:
    static constexpr int8_t MAX_PRIORITY { int8_t(-15) };
    static constexpr int8_t HIGH_PRIORITY { int8_t(-10) };
    static constexpr int8_t MEDIUM_HIGH_PRIORITY { int8_t(-5) };
    static constexpr int8_t MEDIUM_PRIORITY { int8_t(0) };
    static constexpr int8_t MEDIUM_LOW_PRIORITY { int8_t(5) };
    static constexpr int8_t LOW_PRIORITY { int8_t(10) };
    static constexpr int8_t LOWEST_PRIORITY { int8_t(15) };
    static constexpr int8_t DEFAULT_PRIORITY { int8_t(0) };
    static constexpr int8_t CANCEL_PRIORITY { int8_t(-20) };

public: /* package */
    bool failed {  };

public:
    static constexpr int32_t MAX_FILE_CHUNKS_IN_MEMORY { int32_t(100) };
    int32_t fileChunksInMemory {  };
protected:
    void ctor(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env, ::rice::environment::processing::Processor* p);
    void ctor(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env, ::rice::environment::processing::Processor* p, int32_t chunkSize, int32_t numChunksToWriteToNetwork);
    void ctor(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, ::rice::environment::Environment* env);
    void ctor(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env);

public: /* protected */
    virtual void socketClosed();

public:
    void receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e) override;

public: /* protected */
    virtual void purge();

public: /* package */
    int32_t seq {  };
    ::rice::p2p::util::SortedLinkedList* queue {  };
    FileTransferImpl_MessageWrapper* messageThatIsBeingWritten {  };
    bool registered {  };

private:
    void enqueue(FileTransferImpl_MessageWrapper* ret);

public: /* protected */
    virtual void scheduleToWriteIfNeeded();

private:
    FileTransferImpl_MessageWrapper* peek();
    FileTransferImpl_MessageWrapper* poll();
    bool haveMessageToSend();

public: /* protected */
    virtual bool complete(FileTransferImpl_MessageWrapper* wrapper);

public: /* package */
    ::java::util::ArrayList* listeners {  };

public:
    void addListener(FileTransferListener* listener) override;
    void removeListener(FileTransferListener* listener) override;
    virtual ::java::lang::Iterable* getListeners();

public: /* protected */
    virtual void notifyListenersSendMsgProgress(BBReceipt* receipt, int32_t bytesSent, int32_t bytesTotal);
    virtual void notifyListenersReceiveMsgProgress(BBReceipt* receipt, int32_t bytesReceived, int32_t bytesTotal);
    virtual void notifyListenersSendFileProgress(FileReceipt* receipt, int64_t bytesSent, int64_t bytesTotal);
    virtual void notifyListenersReceiveFileProgress(FileReceipt* receipt, int64_t bytesReceived, int64_t bytesTotal);
    virtual void notifyListenersSenderCancelled(FileTransferImpl_DataReader* receipt);
    virtual void notifyListenersReceiverCancelled(Receipt* receipt);
    virtual void notifyListenersTransferFailed(Receipt* receipt, bool incoming);

public:
    FileReceipt* sendFile(::java::io::File* f, ::java::nio::ByteBuffer* metadata, int8_t priority, ::rice::Continuation* c) /* throws(IOException) */ override;
    FileReceipt* sendFile(::java::io::File* f, ::java::nio::ByteBuffer* metadataBB, int8_t priority, int64_t offset, int64_t length, ::rice::Continuation* c) /* throws(IOException) */ override;
    BBReceipt* sendMsg(::java::nio::ByteBuffer* bb, int8_t priority, ::rice::Continuation* c) override;

public: /* protected */
    virtual int32_t getUid();

public: /* package */
    ::java::util::Map* outgoingData {  };

public:
    void receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite) override;

public: /* protected */
    virtual void incrementFileChunksInMemory();
    virtual void decrementFileChunksInMemory();

public:
    virtual void registerToReadIfPossible();

public: /* package */
    FileTransferImpl_MsgTypeReader* msgTypeReader {  };
    FileTransferImpl_BBHeaderReader* bbHeaderReader {  };
    FileTransferImpl_FileHeaderReader* fileHeaderReader {  };
    FileTransferImpl_FileNameReader* fileNameReader {  };
    FileTransferImpl_ChunkReader* chunkReader {  };
    FileTransferImpl_Reader* reader {  };

public: /* protected */
    virtual void receiverCancelled(int32_t uid);
    virtual void senderCancelled(int32_t uid);

public: /* package */
    ::java::util::Map* incomingData {  };

public:
    virtual void addIncomingMessage(int32_t uid, int32_t size);
    virtual void addIncomingFile(int32_t uid, ::int8_tArray* metadata, int64_t offset, int64_t length) /* throws(IOException) */;
    void receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket) override;

public: /* protected */
    virtual bool requestCancel(int32_t uid);
    virtual bool sendCancel(int32_t uid);

    // Generated

public:
    FileTransferImpl(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env, ::rice::environment::processing::Processor* p);
    FileTransferImpl(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env, ::rice::environment::processing::Processor* p, int32_t chunkSize, int32_t numChunksToWriteToNetwork);
    FileTransferImpl(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, ::rice::environment::Environment* env);
    FileTransferImpl(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env);
protected:
    FileTransferImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
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
    friend class FileTransferImpl_FileDataReader;
    friend class FileTransferImpl_FileDataReader_completeChunk_1;
    friend class FileTransferImpl_FileDataReader_completeChunk_2;
    friend class FileTransferImpl_FileDataReader_cancelled_3;
    friend class FileTransferImpl_FileDataReader_cancelled_4;
    friend class FileTransferImpl_SimpleMessageWrapper;
};
