// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/filetransfer/BBReceipt.hpp>
#include <org/mpisws/p2p/filetransfer/FileAllocationStrategy.hpp>
#include <org/mpisws/p2p/filetransfer/FileReceipt.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferCallback.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_enqueue_1.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_BBDataReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_BBHeaderReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_BBReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_ChunkReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_DataReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileHeaderReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileNameReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MessageWrapper.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MsgTypeReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_Reader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_ReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_SimpleMessageWrapper.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferListener.hpp>
#include <org/mpisws/p2p/filetransfer/Receipt.hpp>
#include <org/mpisws/p2p/filetransfer/TempFileAllocationStrategy.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/p2p/util/SortedLinkedList.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <Array.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::filetransfer::FileTransferImpl::FileTransferImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl::FileTransferImpl(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env, ::rice::environment::processing::Processor* p) 
    : FileTransferImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,callback,fileAllocater,env,p);
}

org::mpisws::p2p::filetransfer::FileTransferImpl::FileTransferImpl(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env, ::rice::environment::processing::Processor* p, int32_t chunkSize, int32_t numChunksToWriteToNetwork) 
    : FileTransferImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,callback,fileAllocater,env,p,chunkSize,numChunksToWriteToNetwork);
}

org::mpisws::p2p::filetransfer::FileTransferImpl::FileTransferImpl(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, ::rice::environment::Environment* env) 
    : FileTransferImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,callback,env);
}

org::mpisws::p2p::filetransfer::FileTransferImpl::FileTransferImpl(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env) 
    : FileTransferImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,callback,fileAllocater,env);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::init()
{
    MAX_QUEUE_SIZE = int32_t(1024);
    CHUNK_SIZE = int32_t(8192);
    NUM_OUTSTANDING_CHUNKS_TO_WRITE_TO_NETWORK = int32_t(10);
    FILE_CACHE = int32_t(10);
    failed = false;
    fileChunksInMemory = int32_t(0);
    seq = ::java::lang::Integer::MIN_VALUE;
    messageThatIsBeingWritten = nullptr;
    registered = false;
    listeners = new ::java::util::ArrayList();
    outgoingData = new ::java::util::HashMap();
    msgTypeReader = new FileTransferImpl_MsgTypeReader(this);
    bbHeaderReader = new FileTransferImpl_BBHeaderReader(this);
    fileHeaderReader = new FileTransferImpl_FileHeaderReader(this);
    fileNameReader = new FileTransferImpl_FileNameReader(this);
    chunkReader = new FileTransferImpl_ChunkReader(this);
    reader = msgTypeReader;
    incomingData = new ::java::util::HashMap();
}

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::MSG_FILE_HEADER;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::MSG_BB_HEADER;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::MSG_CHUNK;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::MSG_CANCEL;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::MSG_CANCEL_REQUEST;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::MAX_PRIORITY;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::HIGH_PRIORITY;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::MEDIUM_HIGH_PRIORITY;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::MEDIUM_PRIORITY;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::MEDIUM_LOW_PRIORITY;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::LOW_PRIORITY;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::LOWEST_PRIORITY;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::DEFAULT_PRIORITY;

constexpr int8_t org::mpisws::p2p::filetransfer::FileTransferImpl::CANCEL_PRIORITY;

constexpr int32_t org::mpisws::p2p::filetransfer::FileTransferImpl::MAX_FILE_CHUNKS_IN_MEMORY;

void org::mpisws::p2p::filetransfer::FileTransferImpl::ctor(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env, ::rice::environment::processing::Processor* p)
{
    ctor(socket, callback, fileAllocater, env, nullptr, -int32_t(1), -int32_t(1));
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::ctor(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env, ::rice::environment::processing::Processor* p, int32_t chunkSize, int32_t numChunksToWriteToNetwork)
{
    super::ctor();
    init();
    if(chunkSize > 0) {
        CHUNK_SIZE = chunkSize;
    }
    if(numChunksToWriteToNetwork > 0) {
        NUM_OUTSTANDING_CHUNKS_TO_WRITE_TO_NETWORK = numChunksToWriteToNetwork;
    }
    this->socket = socket;
    this->callback = callback;
    this->fileAllocater = fileAllocater;
    if(this->fileAllocater == nullptr)
        this->fileAllocater = new TempFileAllocationStrategy();

    this->queue = new ::rice::p2p::util::SortedLinkedList();
    this->selectorManager = npc(env)->getSelectorManager();
    this->logger = npc(npc(env)->getLogManager())->getLogger(FileTransferImpl::class_(), nullptr);
    this->processor = p;
    if(this->processor == nullptr)
        this->processor = npc(env)->getProcessor();

    this->environment = env;
    npc(socket)->register_(true, false, -int32_t(1), this);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::ctor(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, ::rice::environment::Environment* env)
{
    ctor(socket, callback, nullptr, env);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::ctor(::rice::p2p::commonapi::appsocket::AppSocket* socket, FileTransferCallback* callback, FileAllocationStrategy* fileAllocater, ::rice::environment::Environment* env)
{
    ctor(socket, callback, fileAllocater, env, nullptr);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::socketClosed()
{
    receiveException(socket, static_cast< ::java::lang::Exception* >(new ::org::mpisws::p2p::transport::ClosedChannelException(u"Underlying socket was closed."_j)));
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e)
{
    {
        synchronized synchronized_0(queue);
        {
            if(failed)
                return;

        }
    }
    if(callback != nullptr)
        npc(callback)->receiveException(e);

    purge();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::purge()
{
    ::java::lang::Iterable* dropMe;
    {
        synchronized synchronized_1(queue);
        {
            failed = true;
            dropMe = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(queue));
        }
    }
    for (auto _i = npc(dropMe)->iterator(); _i->hasNext(); ) {
        FileTransferImpl_MessageWrapper* foo = java_cast< FileTransferImpl_MessageWrapper* >(_i->next());
        {
            npc(foo)->drop();
        }
    }
    for (auto _i = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(incomingData)->values()))->iterator(); _i->hasNext(); ) {
        FileTransferImpl_DataReader* r = java_cast< FileTransferImpl_DataReader* >(_i->next());
        {
            notifyListenersTransferFailed(r, true);
        }
    }
    for (auto _i = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(outgoingData)->values()))->iterator(); _i->hasNext(); ) {
        FileTransferImpl_ReceiptImpl* r = java_cast< FileTransferImpl_ReceiptImpl* >(_i->next());
        {
            npc(r)->failed();
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::enqueue(FileTransferImpl_MessageWrapper* ret)
{
    {
        synchronized synchronized_2(queue);
        {
            if(failed)
                return;

            npc(queue)->add(static_cast< ::java::lang::Comparable* >(ret));
            while (npc(queue)->size() > MAX_QUEUE_SIZE) {
                auto w = java_cast< FileTransferImpl_MessageWrapper* >(npc(queue)->removeLast());
                if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping "_j)->append(static_cast< ::java::lang::Object* >(w))
                        ->append(u" because queue is full. MAX_QUEUE_SIZE:"_j)
                        ->append(MAX_QUEUE_SIZE)->toString());

                npc(w)->drop();
            }
        }
    }
    if(npc(selectorManager)->isSelectorThread()) {
        scheduleToWriteIfNeeded();
    } else {
        npc(selectorManager)->invoke(new FileTransferImpl_enqueue_1(this));
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::scheduleToWriteIfNeeded()
{
    if(!npc(selectorManager)->isSelectorThread())
        throw new ::java::lang::IllegalStateException(u"Must be called on the selector"_j);

    if(!registered) {
        if(haveMessageToSend()) {
            registered = true;
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".scheduleToWriteIfNeeded() registering to write"_j)->toString());

            npc(socket)->register_(false, true, 300000, this);
        }
    }
}

org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapper* org::mpisws::p2p::filetransfer::FileTransferImpl::peek()
{
    {
        synchronized synchronized_3(queue);
        {
            if(messageThatIsBeingWritten == nullptr) {
                return java_cast< FileTransferImpl_MessageWrapper* >(npc(queue)->peek());
            }
            return messageThatIsBeingWritten;
        }
    }
}

org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapper* org::mpisws::p2p::filetransfer::FileTransferImpl::poll()
{
    {
        synchronized synchronized_4(queue);
        {
            if(messageThatIsBeingWritten == nullptr) {
                messageThatIsBeingWritten = java_cast< FileTransferImpl_MessageWrapper* >(npc(queue)->poll());
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                    npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".poll() set messageThatIsBeingWritten = "_j)
                        ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))->toString());

            }
            if(npc(queue)->size() >= (MAX_QUEUE_SIZE - int32_t(1)) && npc(logger)->level <= ::rice::environment::logging::Logger::INFO) {
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"polling from full queue ("_j)
                    ->append(npc(queue)->size())
                    ->append(u") (this is a good thing) "_j)
                    ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))->toString());
            }
            return messageThatIsBeingWritten;
        }
    }
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl::haveMessageToSend()
{
    {
        synchronized synchronized_5(queue);
        {
            if(messageThatIsBeingWritten == nullptr && npc(queue)->isEmpty())
                return false;

            return true;
        }
    }
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl::complete(FileTransferImpl_MessageWrapper* wrapper)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".complete("_j)
            ->append(static_cast< ::java::lang::Object* >(wrapper))
            ->append(u")"_j)->toString());

    if(wrapper != messageThatIsBeingWritten)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Wrapper:"_j)->append(static_cast< ::java::lang::Object* >(wrapper))
            ->append(u" messageThatIsBeingWritten:"_j)
            ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))->toString());

    messageThatIsBeingWritten = nullptr;
    npc(wrapper)->complete();
    return true;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::addListener(FileTransferListener* listener)
{
    {
        synchronized synchronized_6(listeners);
        {
            npc(listeners)->add(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::removeListener(FileTransferListener* listener)
{
    {
        synchronized synchronized_7(listeners);
        {
            npc(listeners)->remove(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

java::lang::Iterable* org::mpisws::p2p::filetransfer::FileTransferImpl::getListeners()
{
    {
        synchronized synchronized_8(listeners);
        {
            return new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::notifyListenersSendMsgProgress(BBReceipt* receipt, int32_t bytesSent, int32_t bytesTotal)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyListenersSendMsgProgress("_j)->append(static_cast< ::java::lang::Object* >(receipt))
            ->append(u","_j)
            ->append(bytesSent)
            ->append(u","_j)
            ->append(bytesTotal)
            ->append(u")"_j)->toString());

    for (auto _i = npc(getListeners())->iterator(); _i->hasNext(); ) {
        FileTransferListener* l = java_cast< FileTransferListener* >(_i->next());
        {
            npc(l)->msgTransferred(receipt, bytesSent, bytesTotal, false);
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::notifyListenersReceiveMsgProgress(BBReceipt* receipt, int32_t bytesReceived, int32_t bytesTotal)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyListenersReceiveMsgProgress("_j)->append(static_cast< ::java::lang::Object* >(receipt))
            ->append(u","_j)
            ->append(bytesReceived)
            ->append(u","_j)
            ->append(bytesTotal)
            ->append(u")"_j)->toString());

    for (auto _i = npc(getListeners())->iterator(); _i->hasNext(); ) {
        FileTransferListener* l = java_cast< FileTransferListener* >(_i->next());
        {
            npc(l)->msgTransferred(receipt, bytesReceived, bytesTotal, true);
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::notifyListenersSendFileProgress(FileReceipt* receipt, int64_t bytesSent, int64_t bytesTotal)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyListenersSendFileProgress("_j)->append(static_cast< ::java::lang::Object* >(receipt))
            ->append(u","_j)
            ->append(bytesSent)
            ->append(u","_j)
            ->append(bytesTotal)
            ->append(u")"_j)->toString());

    for (auto _i = npc(getListeners())->iterator(); _i->hasNext(); ) {
        FileTransferListener* l = java_cast< FileTransferListener* >(_i->next());
        {
            npc(l)->fileTransferred(receipt, bytesSent, bytesTotal, false);
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::notifyListenersReceiveFileProgress(FileReceipt* receipt, int64_t bytesReceived, int64_t bytesTotal)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyListenersReceiveFileProgress("_j)->append(static_cast< ::java::lang::Object* >(receipt))
            ->append(u","_j)
            ->append(bytesReceived)
            ->append(u","_j)
            ->append(bytesTotal)
            ->append(u")"_j)->toString());

    for (auto _i = npc(getListeners())->iterator(); _i->hasNext(); ) {
        FileTransferListener* l = java_cast< FileTransferListener* >(_i->next());
        {
            npc(l)->fileTransferred(receipt, bytesReceived, bytesTotal, true);
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::notifyListenersSenderCancelled(FileTransferImpl_DataReader* receipt)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyListenersSenderCancelled("_j)->append(static_cast< ::java::lang::Object* >(receipt))
            ->append(u")"_j)->toString());

    for (auto _i = npc(getListeners())->iterator(); _i->hasNext(); ) {
        FileTransferListener* l = java_cast< FileTransferListener* >(_i->next());
        {
            npc(l)->transferCancelled(receipt, true);
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::notifyListenersReceiverCancelled(Receipt* receipt)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyListenersReceiverCancelled("_j)->append(static_cast< ::java::lang::Object* >(receipt))
            ->append(u")"_j)->toString());

    for (auto _i = npc(getListeners())->iterator(); _i->hasNext(); ) {
        FileTransferListener* l = java_cast< FileTransferListener* >(_i->next());
        {
            npc(l)->transferCancelled(receipt, false);
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::notifyListenersTransferFailed(Receipt* receipt, bool incoming)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyListenersTransferFailed("_j)->append(static_cast< ::java::lang::Object* >(receipt))
            ->append(u")"_j)->toString());

    for (auto _i = npc(getListeners())->iterator(); _i->hasNext(); ) {
        FileTransferListener* l = java_cast< FileTransferListener* >(_i->next());
        {
            npc(l)->transferFailed(receipt, incoming);
        }
    }
}

org::mpisws::p2p::filetransfer::FileReceipt* org::mpisws::p2p::filetransfer::FileTransferImpl::sendFile(::java::io::File* f, ::java::nio::ByteBuffer* metadata, int8_t priority, ::rice::Continuation* c) /* throws(IOException) */
{
    return sendFile(f, metadata, priority, static_cast< int64_t >(int32_t(0)), npc(f)->length(), c);
}

org::mpisws::p2p::filetransfer::FileReceipt* org::mpisws::p2p::filetransfer::FileTransferImpl::sendFile(::java::io::File* f, ::java::nio::ByteBuffer* metadataBB, int8_t priority, int64_t offset, int64_t length, ::rice::Continuation* c) /* throws(IOException) */
{
    if(f == nullptr || !npc(f)->exists() || npc(f)->isDirectory())
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"File f must be non-null, exist, and must not be a directory. "_j)->append(static_cast< ::java::lang::Object* >(f))->toString());

    auto metadata = new ::int8_tArray(npc(metadataBB)->remaining());
    npc(metadataBB)->get(metadata);
    auto ret = new FileTransferImpl_FileReceiptImpl(this, f, metadata, priority, offset, length, getUid(), c);
    return ret;
}

org::mpisws::p2p::filetransfer::BBReceipt* org::mpisws::p2p::filetransfer::FileTransferImpl::sendMsg(::java::nio::ByteBuffer* bb, int8_t priority, ::rice::Continuation* c)
{
    if(bb == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"ByteBuffer bb must be non-null"_j);

    auto ret = new FileTransferImpl_BBReceiptImpl(this, bb, priority, getUid(), c);
    return ret;
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl::getUid()
{
    return seq++;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite)
{
    if(canWrite) {
        try {
            registered = false;
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"receivedSelectResult("_j)->append(static_cast< ::java::lang::Object* >(socket))
                    ->append(u","_j)
                    ->append(canRead)
                    ->append(u","_j)
                    ->append(canWrite)->toString());

            auto current = poll();
            while (current != nullptr && npc(current)->receiveSelectResult(socket)) {
                current = poll();
            }
            scheduleToWriteIfNeeded();
        } catch (::java::io::IOException* ioe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".rsr("_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))
                    ->append(u")"_j)->toString(), ioe);

            receiveException(socket, static_cast< ::java::lang::Exception* >(ioe));
            return;
        }
    }
    if(canRead) {
        try {
            while (npc(reader)->read(socket)) 
                                ;

            registerToReadIfPossible();
        } catch (::java::io::IOException* ioe) {
            receiveException(socket, static_cast< ::java::lang::Exception* >(ioe));
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::incrementFileChunksInMemory()
{
    if(!npc(npc(environment)->getSelectorManager())->isSelectorThread())
        throw new ::java::lang::IllegalStateException(u"Must be called on selector thread to maintain sync."_j);

    fileChunksInMemory++;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::decrementFileChunksInMemory()
{
    if(!npc(npc(environment)->getSelectorManager())->isSelectorThread())
        throw new ::java::lang::IllegalStateException(u"Must be called on selector thread to maintain sync."_j);

    fileChunksInMemory--;
    registerToReadIfPossible();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::registerToReadIfPossible()
{
    if(!npc(npc(environment)->getSelectorManager())->isSelectorThread())
        throw new ::java::lang::IllegalStateException(u"Must be called on selector thread to maintain sync."_j);

    if(fileChunksInMemory < MAX_FILE_CHUNKS_IN_MEMORY) {
        npc(socket)->register_(true, false, -int32_t(1), this);
    } else {
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::receiverCancelled(int32_t uid)
{
    auto writer = java_cast< FileTransferImpl_ReceiptImpl* >(npc(outgoingData)->remove(::java::lang::Integer::valueOf(uid)));
    if(writer != nullptr) {
        npc(writer)->cancel();
        npc(writer)->notifyReceiverCancelled();
        notifyListenersReceiverCancelled(writer);
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"receiverCanclled("_j)->append(uid)
                ->append(u") no record of the uid."_j)->toString());

    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::senderCancelled(int32_t uid)
{
    auto reader = java_cast< FileTransferImpl_DataReader* >(npc(incomingData)->remove(::java::lang::Integer::valueOf(uid)));
    if(reader != nullptr) {
        npc(reader)->cancelled(reader);
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"senderCanclled("_j)->append(uid)
                ->append(u") no record of the uid."_j)->toString());

    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::addIncomingMessage(int32_t uid, int32_t size)
{
    if(npc(incomingData)->containsKey(::java::lang::Integer::valueOf(uid)))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"DataReader with uid "_j)->append(uid)
            ->append(u" already exists! "_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< FileTransferImpl_DataReader* >(npc(incomingData)->get(::java::lang::Integer::valueOf(uid)))))
            ->append(u" "_j)
            ->append(size)->toString());

    auto bbdr = new FileTransferImpl_BBDataReader(this, uid, size);
    npc(incomingData)->put(::java::lang::Integer::valueOf(uid), bbdr);
    notifyListenersReceiveMsgProgress(bbdr, 0, size);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::addIncomingFile(int32_t uid, ::int8_tArray* metadata, int64_t offset, int64_t length) /* throws(IOException) */
{
    auto f = npc(fileAllocater)->getFile(::java::nio::ByteBuffer::wrap(metadata), offset, length);
    if(npc(incomingData)->containsKey(::java::lang::Integer::valueOf(uid)))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"DataReader with uid "_j)->append(uid)
            ->append(u" already exists! "_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< FileTransferImpl_DataReader* >(npc(incomingData)->get(::java::lang::Integer::valueOf(uid)))))
            ->append(u" "_j)
            ->append(npc(metadata)->length)->toString());

    auto fdr = new FileTransferImpl_FileDataReader(this, uid, metadata, f, offset, length);
    npc(incomingData)->put(::java::lang::Integer::valueOf(uid), fdr);
    notifyListenersReceiveFileProgress(fdr, 0, length);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl::receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket)
{
    throw new ::java::lang::RuntimeException(u"Not Implemented, shouldn't be called."_j);
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl::requestCancel(int32_t uid)
{
    enqueue(new FileTransferImpl_SimpleMessageWrapper(this, MSG_CANCEL_REQUEST, uid));
    return false;
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl::sendCancel(int32_t uid)
{
    enqueue(new FileTransferImpl_SimpleMessageWrapper(this, MSG_CANCEL, uid));
    return false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl", 44);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl::getClass0()
{
    return class_();
}

