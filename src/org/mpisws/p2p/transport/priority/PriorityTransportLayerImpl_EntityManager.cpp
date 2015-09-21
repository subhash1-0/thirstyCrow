// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/net/SocketException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/nio/channels/ClosedChannelException.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/identity/MemoryExpiredException.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTypes.hpp>
#include <org/mpisws/p2p/transport/priority/MessageInfo.hpp>
#include <org/mpisws/p2p/transport/priority/PrimarySocketListener.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_clearState_1.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_send_6.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_MessageWrapper.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_PendingMessages.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_SizeReader.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/SortedLinkedList.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>

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
org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::PriorityTransportLayerImpl_EntityManager(PriorityTransportLayerImpl *PriorityTransportLayerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_this(PriorityTransportLayerImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::PriorityTransportLayerImpl_EntityManager(PriorityTransportLayerImpl *PriorityTransportLayerImpl_this, ::java::lang::Object* identifier) 
    : PriorityTransportLayerImpl_EntityManager(PriorityTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(identifier);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::init()
{
    seq = ::java::lang::Integer::MIN_VALUE;
    registered = false;
    livenessChecker = nullptr;
    pendingBigMessages = new ::java::util::HashMap();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::ctor(::java::lang::Object* identifier)
{
    super::ctor();
    init();
    this->identifier = new ::java::lang::ref::WeakReference(identifier);
    queue = new ::rice::p2p::util::SortedLinkedList();
    sockets = new ::java::util::HashSet();
}

java::lang::String* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::toString()
{
    return ::java::lang::StringBuilder().append(u"EM{"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(identifier)->get())))
        ->append(u"}"_j)->toString();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::clearState()
{
    if(!npc(PriorityTransportLayerImpl_this->selectorManager)->isSelectorThread()) {
        npc(PriorityTransportLayerImpl_this->selectorManager)->invoke(new PriorityTransportLayerImpl_EntityManager_clearState_1(this));
        return;
    }
    for (auto _i = npc(sockets)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::P2PSocket* socket = java_cast< ::org::mpisws::p2p::transport::P2PSocket* >(_i->next());
        {
            npc(socket)->close();
        }
    }
    {
        synchronized synchronized_0(queue);
        {
            npc(queue)->clear();
            messageThatIsBeingWritten = nullptr;
        }
    }
    {
        synchronized synchronized_1(this);
        {
            if(npc(PriorityTransportLayerImpl_this->logger)->level <= npc(PriorityTransportLayerImpl_this->logger)->INFO)
                npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".clearState() setting pendingSocket to null "_j)
                    ->append(static_cast< ::java::lang::Object* >(pendingSocket))->toString());

            if(pendingSocket != nullptr) {
                npc(pendingSocket)->cancel();
                stopLivenessChecker();
            }
            pendingSocket = nullptr;
        }
    }
}

bool org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::closeMe(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PriorityTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"closeMe("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u"):"_j)
            ->append((socket == writingSocket))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

    if(socket == writingSocket) {
        if(messageThatIsBeingWritten == nullptr) {
            npc(sockets)->remove(socket);
            npc(socket)->close();
            setWritingSocket(nullptr);
            return true;
        }
        closeWritingSocket = writingSocket;
        return false;
    } else {
        npc(sockets)->remove(socket);
        npc(socket)->close();
        return true;
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::primarySocketAvailable(::org::mpisws::p2p::transport::P2PSocket* s, ::org::mpisws::p2p::transport::SocketRequestHandle* receipt)
{
    if(!npc(PriorityTransportLayerImpl_this->selectorManager)->isSelectorThread())
        throw new ::java::lang::IllegalStateException(u"Must be called on the selector"_j);

    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"primarySocketAvailable("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(receipt))
            ->append(u")"_j)->toString());

    {
        synchronized synchronized_2(this);
        {
            if(receipt != nullptr) {
                if(receipt == pendingSocket) {
                    if(npc(PriorityTransportLayerImpl_this->logger)->level <= npc(PriorityTransportLayerImpl_this->logger)->INFO)
                        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".primarySocketAvailable setting pendingSocket to null "_j)
                            ->append(static_cast< ::java::lang::Object* >(pendingSocket))->toString());

                    stopLivenessChecker();
                    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"got socket:"_j)->append(static_cast< ::java::lang::Object* >(s))
                            ->append(u" clearing pendingSocket:"_j)
                            ->append(static_cast< ::java::lang::Object* >(pendingSocket))->toString());

                    pendingSocket = nullptr;
                } else {
                }
            }
        }
    }
    npc(sockets)->add(s);
    scheduleToWriteIfNeeded();
    new PriorityTransportLayerImpl_EntityManager_SizeReader(this, s);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::setWritingSocket(::org::mpisws::p2p::transport::P2PSocket* s)
{
    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO - int32_t(1))
        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".setWritingSocket("_j)
            ->append(static_cast< ::java::lang::Object* >(s))
            ->append(u")"_j)->toString());

    writingSocket = s;
    if(npc(PriorityTransportLayerImpl_this->primarySocketListeners)->isEmpty())
        return;

    if(s == nullptr) {
        for (auto _i = npc(PriorityTransportLayerImpl_this->primarySocketListeners)->iterator(); _i->hasNext(); ) {
            PrimarySocketListener* l = java_cast< PrimarySocketListener* >(_i->next());
            {
                npc(l)->notifyPrimarySocketClosed(java_cast< ::java::lang::Object* >(npc(identifier)->get()));
            }
        }
    } else {
        for (auto _i = npc(PriorityTransportLayerImpl_this->primarySocketListeners)->iterator(); _i->hasNext(); ) {
            PrimarySocketListener* l = java_cast< PrimarySocketListener* >(_i->next());
            {
                npc(l)->notifyPrimarySocketOpened(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()), npc(s)->getOptions());
            }
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::scheduleToWriteIfNeeded()
{
    if(!npc(PriorityTransportLayerImpl_this->selectorManager)->isSelectorThread())
        throw new ::java::lang::IllegalStateException(u"Must be called on the selector"_j);

    auto temp = java_cast< ::java::lang::Object* >(npc(identifier)->get());
    if(temp == nullptr) {
        purge(new ::org::mpisws::p2p::transport::identity::MemoryExpiredException(::java::lang::StringBuilder().append(u"No record of identifier for "_j)->append(static_cast< ::java::lang::Object* >(this))->toString()));
        return;
    }
    if(writingSocket == nullptr) {
        registered = false;
        if(!npc(sockets)->isEmpty()) {
            setWritingSocket(java_cast< ::org::mpisws::p2p::transport::P2PSocket* >(npc(npc(sockets)->iterator())->next()));
        } else {
            if(pendingSocket == nullptr) {
                auto peek = static_cast< PriorityTransportLayerImpl_EntityManager* >(this)->peek();
                if(peek != nullptr) {
                    openPrimarySocketHelper(temp, npc(peek)->options);
                }
            }
        }
    }
    if(!registered && writingSocket != nullptr) {
        if(haveMessageToSend()) {
            registered = true;
            if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".scheduleToWriteIfNeeded() registering to write on "_j)
                    ->append(static_cast< ::java::lang::Object* >(writingSocket))->toString());

            npc(writingSocket)->register_(false, true, this);
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::openPrimarySocketHelper(::java::lang::Object* i, ::java::util::Map* options)
{
    {
        synchronized synchronized_3(this);
        {
            if(pendingSocket != nullptr || writingSocket != nullptr)
                return;

            if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Opening Primary Socket to "_j)->append(static_cast< ::java::lang::Object* >(i))->toString());

            ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* const handle = new PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2(this, i, i, options, PriorityTransportLayerImpl_this->logger);
            if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".openPrimarySocketHelper() setting pendingSocket to "_j)
                    ->append(static_cast< ::java::lang::Object* >(handle))->toString());

            pendingSocket = handle;
            startLivenessChecker(i, options);
            npc(handle)->setSubCancellable(npc(PriorityTransportLayerImpl_this->tl)->openSocket(i, new PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3(this, handle, i), options));
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::startLivenessChecker(::java::lang::Object* temp, ::java::util::Map* options)
{
    if(options == nullptr) {
        throw new ::java::lang::IllegalArgumentException(u"Options is null"_j);
    }
    if(livenessChecker == nullptr) {
        if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"startLivenessChecker("_j)->append(static_cast< ::java::lang::Object* >(temp))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(options))
                ->append(u") pend:"_j)
                ->append(static_cast< ::java::lang::Object* >(pendingSocket))
                ->append(u" writingS:"_j)
                ->append(static_cast< ::java::lang::Object* >(writingSocket))
                ->append(u" theQueue:"_j)
                ->append(npc(queue)->size())->toString());

        livenessChecker = new PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4(this, temp, options);
        auto delay = npc(PriorityTransportLayerImpl_this->proximityProvider)->proximity(temp, options) * int32_t(4);
        if(delay < 5000)
            delay = 5000;

        if(delay > 40000)
            delay = 40000;

        npc(PriorityTransportLayerImpl_this->selectorManager)->schedule(livenessChecker, static_cast< int64_t >(delay));
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::stopLivenessChecker()
{
    if(livenessChecker == nullptr)
        return;

    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"stopLivenessChecker("_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(identifier)->get())))
            ->append(u") pend:"_j)
            ->append(static_cast< ::java::lang::Object* >(pendingSocket))
            ->append(u" writingS:"_j)
            ->append(static_cast< ::java::lang::Object* >(writingSocket))
            ->append(u" theQueue:"_j)
            ->append(npc(queue)->size())->toString());

    npc(livenessChecker)->cancel();
    livenessChecker = nullptr;
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::peek()
{
    {
        synchronized synchronized_4(queue);
        {
            if(messageThatIsBeingWritten == nullptr) {
                return java_cast< PriorityTransportLayerImpl_EntityManager_MessageWrapper* >(npc(queue)->peek());
            }
            return messageThatIsBeingWritten;
        }
    }
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::poll()
{
    {
        synchronized synchronized_5(queue);
        {
            if(messageThatIsBeingWritten == nullptr) {
                messageThatIsBeingWritten = java_cast< PriorityTransportLayerImpl_EntityManager_MessageWrapper* >(npc(queue)->poll());
                if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                    npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"poll("_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(identifier)->get())))
                        ->append(u") set messageThatIsBeingWritten = "_j)
                        ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))->toString());

            }
            if(npc(queue)->size() >= (PriorityTransportLayerImpl_this->MAX_QUEUE_SIZE - int32_t(1)) && npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO) {
                npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"polling from full queue (this is a good thing) "_j)
                    ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))->toString());
            }
            return messageThatIsBeingWritten;
        }
    }
}

bool org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::haveMessageToSend()
{
    if(messageThatIsBeingWritten == nullptr && npc(queue)->isEmpty())
        return false;

    return true;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER) {
        npc(PriorityTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".receiveException("_j)
            ->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(ioe))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))
            ->append(u" wrS:"_j)
            ->append(static_cast< ::java::lang::Object* >(writingSocket))->toString(), ioe);
    } else if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".receiveException("_j)
            ->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(ioe))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))
            ->append(u" wrS:"_j)
            ->append(static_cast< ::java::lang::Object* >(writingSocket))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(ioe))->toString());

    registered = false;
    npc(sockets)->remove(socket);
    if(dynamic_cast< ::java::nio::channels::ClosedChannelException* >(ioe) != nullptr) {
    } else {
        npc(socket)->close();
    }
    if(socket == writingSocket) {
        clearAndEnqueue(messageThatIsBeingWritten);
    }
    scheduleToWriteIfNeeded();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    registered = false;
    if(canRead || !canWrite)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" Expected only to write. canRead:"_j)
            ->append(canRead)
            ->append(u" canWrite:"_j)
            ->append(canWrite)
            ->append(u" socket:"_j)
            ->append(static_cast< ::java::lang::Object* >(socket))->toString());

    if(socket != writingSocket) {
        if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"receivedSelectResult("_j)->append(static_cast< ::java::lang::Object* >(socket))
                ->append(u", r:"_j)
                ->append(canRead)
                ->append(u" w:"_j)
                ->append(canWrite)
                ->append(u") ws:"_j)
                ->append(static_cast< ::java::lang::Object* >(writingSocket))->toString());

        return;
    }
    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"receivedSelectResult("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u","_j)
            ->append(canRead)
            ->append(u","_j)
            ->append(canWrite)->toString());

    auto current = poll();
    while (current != nullptr && npc(current)->receiveSelectResult(writingSocket)) {
        current = poll();
    }
    scheduleToWriteIfNeeded();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::receiveSocketException(::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, ::java::lang::Exception* ex)
{
    {
        synchronized synchronized_6(this);
        {
            if(static_cast< ::java::lang::Object* >(handle) == static_cast< ::java::lang::Object* >(pendingSocket)) {
                if(npc(PriorityTransportLayerImpl_this->logger)->level <= npc(PriorityTransportLayerImpl_this->logger)->INFO)
                    npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".receiveSocketException("_j)
                        ->append(static_cast< ::java::lang::Object* >(ex))
                        ->append(u") setting pendingSocket to null "_j)
                        ->append(static_cast< ::java::lang::Object* >(pendingSocket))->toString());

                stopLivenessChecker();
                pendingSocket = nullptr;
            }
        }
    }
    scheduleToWriteIfNeeded();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::enqueue(PriorityTransportLayerImpl_EntityManager_MessageWrapper* ret)
{
    {
        synchronized synchronized_7(queue);
        {
            npc(queue)->add(static_cast< ::java::lang::Comparable* >(ret));
            while (npc(queue)->size() > PriorityTransportLayerImpl_this->MAX_QUEUE_SIZE) {
                auto w = java_cast< PriorityTransportLayerImpl_EntityManager_MessageWrapper* >(npc(queue)->removeLast());
                if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::CONFIG)
                    npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Dropping "_j)->append(static_cast< ::java::lang::Object* >(w))
                        ->append(u" because queue is full. MAX_QUEUE_SIZE:"_j)
                        ->append(PriorityTransportLayerImpl_this->MAX_QUEUE_SIZE)->toString());

                npc(w)->drop();
            }
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::markDead()
{
    purge(new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(java_cast< ::java::lang::Object* >(npc(identifier)->get())));
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::purge(::java::io::IOException* ioe)
{
    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"purge("_j)
            ->append(static_cast< ::java::lang::Object* >(ioe))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))->toString());

    auto callSendFailed = new ::java::util::ArrayList();
    {
        synchronized synchronized_8(queue);
        {
            if(messageThatIsBeingWritten != nullptr) {
                npc(messageThatIsBeingWritten)->reset();
                if(npc(messageThatIsBeingWritten)->deliverAckToMe != nullptr) {
                    npc(callSendFailed)->add(static_cast< ::java::lang::Object* >(new ::rice::p2p::util::tuples::Tuple(npc(messageThatIsBeingWritten)->deliverAckToMe, messageThatIsBeingWritten)));
                }
                messageThatIsBeingWritten = nullptr;
            }
            for (auto _i = npc(queue)->iterator(); _i->hasNext(); ) {
                PriorityTransportLayerImpl_EntityManager_MessageWrapper* msg = java_cast< PriorityTransportLayerImpl_EntityManager_MessageWrapper* >(_i->next());
                {
                    if(npc(msg)->deliverAckToMe != nullptr) {
                        npc(callSendFailed)->add(static_cast< ::java::lang::Object* >(new ::rice::p2p::util::tuples::Tuple(npc(msg)->deliverAckToMe, msg)));
                    }
                }
            }
            npc(queue)->clear();
        }
    }
    for (auto _i = npc(callSendFailed)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::util::tuples::Tuple* t = java_cast< ::rice::p2p::util::tuples::Tuple* >(_i->next());
        {
            npc(java_cast< ::org::mpisws::p2p::transport::MessageCallback* >(npc(t)->a()))->sendFailed(java_cast< PriorityTransportLayerImpl_EntityManager_MessageWrapper* >(npc(t)->b()), ioe);
        }
    }
    {
        synchronized synchronized_9(sockets);
        {
            for (auto _i = npc(sockets)->iterator(); _i->hasNext(); ) {
                ::org::mpisws::p2p::transport::P2PSocket* sock = java_cast< ::org::mpisws::p2p::transport::P2PSocket* >(_i->next());
                {
                    npc(sock)->close();
                }
            }
            npc(sockets)->clear();
        }
    }
    setWritingSocket(nullptr);
    {
        synchronized synchronized_10(this);
        {
            if(npc(PriorityTransportLayerImpl_this->logger)->level <= npc(PriorityTransportLayerImpl_this->logger)->INFO)
                npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".purge setting pendingSocket to null "_j)
                    ->append(static_cast< ::java::lang::Object* >(pendingSocket))->toString());

            if(pendingSocket != nullptr) {
                stopLivenessChecker();
                npc(pendingSocket)->cancel();
            }
            pendingSocket = nullptr;
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::handleBigMsgSocket(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"handling BIG message socket from:"_j)->append(static_cast< ::java::lang::Object* >(socket))->toString());

    try {
        (new PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5(this))->receiveSelectResult(socket, true, false);
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
    }
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::send(::java::lang::Object* temp, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"send("_j)
            ->append(static_cast< ::java::lang::Object* >(message))
            ->append(u")"_j)->toString());

    int32_t priority = PriorityTransportLayer::DEFAULT_PRIORITY;
    if(options != nullptr) {
        if(npc(options)->containsKey(PriorityTransportLayer::OPTION_PRIORITY())) {
            priority = npc((java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(PriorityTransportLayer::OPTION_PRIORITY())))))->intValue();
        }
    }
    PriorityTransportLayerImpl_EntityManager_MessageWrapper* ret;
    auto remaining = npc(message)->remaining();
    if(remaining > PriorityTransportLayerImpl_this->MAX_MSG_SIZE) {
        if(remaining > PriorityTransportLayerImpl_this->MAX_BIG_MSG_SIZE) {
            ret = new PriorityTransportLayerImpl_EntityManager_MessageWrapper(this, temp, message, deliverAckToMe, options, priority, int32_t(0));
            if(deliverAckToMe != nullptr)
                npc(deliverAckToMe)->sendFailed(ret, new ::java::net::SocketException(::java::lang::StringBuilder().append(u"Message too large. msg:"_j)->append(static_cast< ::java::lang::Object* >(message))
                    ->append(u" size:"_j)
                    ->append(remaining)
                    ->append(u" max:"_j)
                    ->append(::java::lang::Math::max(PriorityTransportLayerImpl_this->MAX_MSG_SIZE, PriorityTransportLayerImpl_this->MAX_BIG_MSG_SIZE))->toString()));

            return ret;
        }
        auto pm = java_cast< PriorityTransportLayerImpl_EntityManager_PendingMessages* >(npc(pendingBigMessages)->get(temp));
        if(pm == nullptr) {
            pm = new PriorityTransportLayerImpl_EntityManager_PendingMessages(this, temp);
            auto ret2 = npc(pm)->addMessage(message, deliverAckToMe, options);
            npc(pendingBigMessages)->put(temp, pm);
            npc(pm)->start(options);
            return ret2;
        } else {
            return npc(pm)->addMessage(message, deliverAckToMe, options);
        }
    }
    if(npc(PriorityTransportLayerImpl_this->livenessProvider)->getLiveness(temp, options) >= ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD) {
        ret = new PriorityTransportLayerImpl_EntityManager_MessageWrapper(this, temp, message, deliverAckToMe, options, priority, int32_t(0));
        if(deliverAckToMe != nullptr)
            npc(deliverAckToMe)->sendFailed(ret, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(temp, message));

        return ret;
    }
    ret = new PriorityTransportLayerImpl_EntityManager_MessageWrapper(this, temp, message, deliverAckToMe, options, priority, seq++);
    PriorityTransportLayerImpl_this->notifyListenersEnqueued(npc(ret)->originalSize, temp, options);
    enqueue(ret);
    if(npc(PriorityTransportLayerImpl_this->selectorManager)->isSelectorThread()) {
        scheduleToWriteIfNeeded();
    } else {
        npc(PriorityTransportLayerImpl_this->selectorManager)->invoke(new PriorityTransportLayerImpl_EntityManager_send_6(this));
    }
    return ret;
}

bool org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::complete(PriorityTransportLayerImpl_EntityManager_MessageWrapper* wrapper)
{
    if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".complete("_j)
            ->append(static_cast< ::java::lang::Object* >(wrapper))
            ->append(u")"_j)->toString());

    if(wrapper != messageThatIsBeingWritten)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Wrapper:"_j)->append(static_cast< ::java::lang::Object* >(wrapper))
            ->append(u" messageThatIsBeingWritten:"_j)
            ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))->toString());

    {
        synchronized synchronized_11(queue);
        {
            messageThatIsBeingWritten = nullptr;
        }
    }
    npc(wrapper)->complete();
    if(closeWritingSocket == writingSocket) {
        npc(writingSocket)->close();
        setWritingSocket(nullptr);
        closeWritingSocket = nullptr;
        return false;
    }
    return true;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::clearAndEnqueue(PriorityTransportLayerImpl_EntityManager_MessageWrapper* wrapper)
{
    if(wrapper != messageThatIsBeingWritten)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Wrapper:"_j)->append(static_cast< ::java::lang::Object* >(wrapper))
            ->append(u" messageThatIsBeingWritten:"_j)
            ->append(static_cast< ::java::lang::Object* >(messageThatIsBeingWritten))->toString());

    {
        synchronized synchronized_12(queue);
        {
            if(messageThatIsBeingWritten != nullptr)
                npc(messageThatIsBeingWritten)->reset();

            messageThatIsBeingWritten = nullptr;
            if(writingSocket != nullptr) {
                npc(sockets)->remove(writingSocket);
                setWritingSocket(nullptr);
            }
            if(wrapper != nullptr) {
                npc(wrapper)->reset();
                enqueue(wrapper);
            }
        }
    }
}

int32_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::queueLength()
{
    auto ret = npc(queue)->size();
    if(messageThatIsBeingWritten != nullptr)
        ret++;

    return ret;
}

int64_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::bytesPending()
{
    int64_t ret = int32_t(0);
    {
        synchronized synchronized_13(queue);
        {
            if(messageThatIsBeingWritten != nullptr) {
                ret += npc(npc(messageThatIsBeingWritten)->message)->remaining();
            }
            for (auto _i = npc(queue)->iterator(); _i->hasNext(); ) {
                PriorityTransportLayerImpl_EntityManager_MessageWrapper* foo = java_cast< PriorityTransportLayerImpl_EntityManager_MessageWrapper* >(_i->next());
                {
                    ret += npc(npc(foo)->message)->remaining();
                }
            }
        }
    }
    return ret;
}

java::util::List* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::getPendingMessages()
{
    {
        synchronized synchronized_14(queue);
        {
            auto ret = new ::java::util::ArrayList(npc(queue)->size());
            for (auto _i = npc(queue)->iterator(); _i->hasNext(); ) {
                PriorityTransportLayerImpl_EntityManager_MessageWrapper* foo = java_cast< PriorityTransportLayerImpl_EntityManager_MessageWrapper* >(_i->next());
                {
                    npc(ret)->add(static_cast< ::java::lang::Object* >(npc(foo)->getMessageInfo()));
                }
            }
            return ret;
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.PriorityTransportLayerImpl.EntityManager", 74);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager::getClass0()
{
    return class_();
}

