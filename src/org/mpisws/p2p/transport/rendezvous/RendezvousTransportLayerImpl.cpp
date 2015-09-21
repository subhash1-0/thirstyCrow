// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDeserializer.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDirectStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/EphemeralDB.hpp>
#include <org/mpisws/p2p/transport/rendezvous/EphemeralDBImpl.hpp>
#include <org/mpisws/p2p/transport/rendezvous/IncomingPilotListener.hpp>
#include <org/mpisws/p2p/transport/rendezvous/OutgoingPilotListener.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotFinder.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousGenerationStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocketUsingRouting_2.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocketViaPilot_3.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_incomingSocket_4.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readConnectHeader_5.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openAcceptSocket_7.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_sendMessage_8.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openPilot_9.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_IncomingPilot.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_OutgoingPilot.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ResponseStrategy.hpp>
#include <org/mpisws/p2p/transport/sourceroute/Forwarder.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
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
org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::RendezvousTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::RendezvousTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::lang::String* RENDEZVOUS_CONTACT_STRING, RendezvousContact* myRendezvousContact, ContactDeserializer* deserializer, RendezvousGenerationStrategy* rendezvousGenerator, PilotFinder* pilotFinder, RendezvousStrategy* rendezvousStrategy, ResponseStrategy* responseStrategy, ContactDirectStrategy* contactDirectStrategy, ::rice::environment::Environment* env) 
    : RendezvousTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,RENDEZVOUS_CONTACT_STRING,myRendezvousContact,deserializer,rendezvousGenerator,pilotFinder,rendezvousStrategy,responseStrategy,contactDirectStrategy,env);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::init()
{
    expectedIncomingSockets = new ::java::util::HashMap();
    connectSockets = new ::java::util::HashMap();
    outgoingPilots = new ::java::util::HashMap();
    opListeners = new ::java::util::ArrayList();
    incomingPilots = new ::java::util::HashMap();
    ipListeners = new ::java::util::ArrayList();
}

constexpr int8_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::NORMAL_SOCKET;

constexpr int8_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::CONNECTOR_SOCKET;

constexpr int8_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::ACCEPTOR_SOCKET;

constexpr int8_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_SOCKET;

constexpr int8_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::CONNECTION_RESPONSE_FAILURE;

constexpr int8_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::CONNECTION_RESPONSE_SUCCESS;

constexpr int64_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::NO_TAG;

java::lang::String*& org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::TAG_KEY()
{
    clinit();
    return TAG_KEY_;
}
java::lang::String* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::TAG_KEY_;

java::lang::String*& org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::FROM_OVERLAY()
{
    clinit();
    return FROM_OVERLAY_;
}
java::lang::String* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::FROM_OVERLAY_;

java::lang::String*& org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::OPTION_USE_PILOT()
{
    clinit();
    return OPTION_USE_PILOT_;
}
java::lang::String* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::OPTION_USE_PILOT_;

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::lang::String* RENDEZVOUS_CONTACT_STRING, RendezvousContact* myRendezvousContact, ContactDeserializer* deserializer, RendezvousGenerationStrategy* rendezvousGenerator, PilotFinder* pilotFinder, RendezvousStrategy* rendezvousStrategy, ResponseStrategy* responseStrategy, ContactDirectStrategy* contactDirectStrategy, ::rice::environment::Environment* env)
{
    super::ctor();
    init();
    this->random = npc(env)->getRandomSource();
    this->time = npc(env)->getTimeSource();
    this->selectorManager = npc(env)->getSelectorManager();
    this->tl = tl;
    this->localNodeHandle = myRendezvousContact;
    this->serializer = deserializer;
    this->RENDEZVOUS_CONTACT_STRING = RENDEZVOUS_CONTACT_STRING;
    this->rendezvousGenerator = rendezvousGenerator;
    this->pilotFinder = pilotFinder;
    this->rendezvousStrategy = rendezvousStrategy;
    this->responseStrategy = responseStrategy;
    this->contactDirectStrategy = contactDirectStrategy;
    this->ephemeralDB = new EphemeralDBImpl(env, int32_t(2) * int32_t(60) * int32_t(60)* int32_t(1000));
    this->logger = npc(npc(env)->getLogManager())->getLogger(RendezvousTransportLayerImpl::class_(), nullptr);
    this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    npc(tl)->setCallback(this);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    ::org::mpisws::p2p::transport::SocketRequestHandle* const handle = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    auto const contact = java_cast< RendezvousContact* >(getHighIdentifier(options));
    if(contact == nullptr || npc(contact)->canContactDirect() || npc(contactDirectStrategy)->canContactDirect(contact)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
            auto s = u"null"_j;
            if(contact != nullptr) {
                s = ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(contact))->append(u" strat:"_j)
                    ->append(npc(contactDirectStrategy)->canContactDirect(contact))->toString();
            }
            npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(options))
                ->append(u") contact:"_j)
                ->append(s)->toString());
        }
        npc(tl)->openSocket(i, new RendezvousTransportLayerImpl_openSocket_1(this, deliverSocketToMe, handle), options);
        return handle;
    } else {
        if(npc(options)->containsKey(OPTION_USE_PILOT())) {
            auto middleMan = java_cast< RendezvousContact* >(java_cast< ::java::lang::Object* >(npc(options)->get(OPTION_USE_PILOT())));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Opening socket to "_j)->append(static_cast< ::java::lang::Object* >(contact))
                    ->append(u" OPTION_USE_PILOT->"_j)
                    ->append(static_cast< ::java::lang::Object* >(middleMan))->toString());

            openSocketViaPilot(contact, middleMan, handle, deliverSocketToMe, options);
            return handle;
        } else {
            if(npc(java_cast< RendezvousContact* >(localNodeHandle))->canContactDirect()) {
                if(openSocketUsingPilotToMe(contact, handle, deliverSocketToMe, options))
                    return handle;

                if(openSocketUsingPilotFinder(contact, handle, deliverSocketToMe, options))
                    return handle;

                openSocketUsingRouting(contact, handle, deliverSocketToMe, options);
                return handle;
            } else {
                if(openSocketUsingPilotFinder(contact, handle, deliverSocketToMe, options))
                    return handle;

                auto myPilots = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(outgoingPilots)->keySet()));
                if(npc(myPilots)->isEmpty())
                    npc(deliverSocketToMe)->receiveException(handle, new ::java::lang::IllegalStateException(u"No available outgoing pilots."_j));

                auto middleMan = java_cast< RendezvousContact* >(npc(myPilots)->get(npc(random)->nextInt(npc(myPilots)->size())));
                openSocketViaPilot(contact, middleMan, handle, deliverSocketToMe, options);
                return handle;
            }
        }
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openSocketUsingRouting(RendezvousContact* contact, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"opening a socket using routing to "_j)->append(static_cast< ::java::lang::Object* >(contact))->toString());

    auto const uid = npc(random)->nextInt();
    putExpectedIncomingSocket(contact, uid, deliverSocketToMe, handle);
    npc(rendezvousStrategy)->openChannel(contact, java_cast< RendezvousContact* >(localNodeHandle), java_cast< RendezvousContact* >(localNodeHandle), uid, new RendezvousTransportLayerImpl_openSocketUsingRouting_2(this, contact, deliverSocketToMe, options, handle), options);
}

bool org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openSocketUsingPilotFinder(RendezvousContact* contact, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto middleMan = java_cast< RendezvousContact* >(npc(pilotFinder)->findPilot(contact));
    if(middleMan == nullptr) {
        return false;
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"opening a socket to "_j)->append(static_cast< ::java::lang::Object* >(contact))
                ->append(u" via "_j)
                ->append(static_cast< ::java::lang::Object* >(middleMan))->toString());

        openSocketViaPilot(contact, middleMan, handle, deliverSocketToMe, options);
        return true;
    }
}

bool org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openSocketUsingPilotToMe(RendezvousContact* contact, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto uid = npc(random)->nextInt();
    putExpectedIncomingSocket(contact, uid, deliverSocketToMe, handle);
    if(npc(incomingPilots)->containsKey(contact)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Opening socket to firewalled node that I have a pilot to: "_j)->append(static_cast< ::java::lang::Object* >(contact))
                ->append(u" uid:"_j)
                ->append(uid)->toString());

        try {
            npc(java_cast< RendezvousTransportLayerImpl_IncomingPilot* >(npc(incomingPilots)->get(contact)))->requestSocket(java_cast< RendezvousContact* >(localNodeHandle), uid);
        } catch (::java::io::IOException* ioe) {
            removeExpectedIncomingSocket(contact, uid);
            npc(deliverSocketToMe)->receiveException(handle, ioe);
        }
        return true;
    }
    return false;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openSocketViaPilot(RendezvousContact* dest, RendezvousContact* middleMan, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(middleMan)->equals(java_cast< RendezvousContact* >(localNodeHandle))) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"openSocketViaPilot("_j)->append(static_cast< ::java::lang::Object* >(dest))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(middleMan))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u") can't use self as rendezvous."_j)->toString());
    }
    auto const uid = npc(random)->nextInt();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocketViaPilot<"_j)->append(uid)
            ->append(u">("_j)
            ->append(static_cast< ::java::lang::Object* >(dest))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(middleMan))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    try {
        npc(sob)->writeByte(CONNECTOR_SOCKET);
        npc(serializer)->serialize(dest, sob);
        npc(serializer)->serialize(java_cast< RendezvousContact* >(localNodeHandle), sob);
        npc(sob)->writeInt(uid);
    } catch (::java::io::IOException* ioe) {
        npc(deliverSocketToMe)->receiveException(handle, ioe);
    }
    auto const writeBuffer = npc(sob)->getByteBuffer();
    auto const readBuffer = ::java::nio::ByteBuffer::allocate(1);
    npc(tl)->openSocket(java_cast< ::java::lang::Object* >(npc(serializer)->convert(middleMan)), new RendezvousTransportLayerImpl_openSocketViaPilot_3(this, writeBuffer, deliverSocketToMe, handle, uid, dest, middleMan, readBuffer, options), options);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::routeForSocket()
{
    throw new ::java::lang::RuntimeException(u"Not implemented."_j);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u")"_j)->toString());

    (new RendezvousTransportLayerImpl_incomingSocket_4(this))->receiveSelectResult(s, true, false);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::readConnectHeader(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"readConnectHeader("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u")"_j)->toString());

    auto const sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(socket, int32_t(1024));
    ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver = new RendezvousTransportLayerImpl_readConnectHeader_5(this, sib);
    npc(receiver)->receiveSelectResult(socket, true, false);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::readAcceptHeader(::org::mpisws::p2p::transport::P2PSocket* acceptorSocket) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"readAcceptHeader("_j)->append(static_cast< ::java::lang::Object* >(acceptorSocket))
            ->append(u")"_j)->toString());

    auto const sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(acceptorSocket, int32_t(1024));
    ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver = new RendezvousTransportLayerImpl_readAcceptHeader_6(this, sib);
    npc(receiver)->receiveSelectResult(acceptorSocket, true, false);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::putExpectedIncomingSocket(RendezvousContact* contact, int32_t uid, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::SocketRequestHandle* requestHandle)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"putExpectedIncomingSocket("_j)->append(static_cast< ::java::lang::Object* >(contact))
            ->append(u"@"_j)
            ->append(::java::lang::System::identityHashCode(contact))
            ->append(u","_j)
            ->append(uid)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(requestHandle))
            ->append(u")"_j)->toString());

    auto one = java_cast< ::java::util::Map* >(npc(expectedIncomingSockets)->get(contact));
    if(one == nullptr) {
        one = new ::java::util::HashMap();
        npc(expectedIncomingSockets)->put(contact, one);
    }
    if(npc(one)->containsKey(::java::lang::Integer::valueOf(uid))) {
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"putExpectedIncomingSockets("_j)->append(static_cast< ::java::lang::Object* >(contact))
            ->append(u","_j)
            ->append(uid)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u") already contains "_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(one)->get(::java::lang::Integer::valueOf(uid)))))->toString());
    }
    npc(one)->put(::java::lang::Integer::valueOf(uid), new ::rice::p2p::util::tuples::Tuple(deliverSocketToMe, requestHandle));
}

rice::p2p::util::tuples::Tuple* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::removeExpectedIncomingSocket(RendezvousContact* target, int32_t uid)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"removeExpectedIncomingSocket("_j)->append(static_cast< ::java::lang::Object* >(target))
            ->append(u"@"_j)
            ->append(::java::lang::System::identityHashCode(target))
            ->append(u","_j)
            ->append(uid)
            ->append(u")"_j)->toString());

    auto one = java_cast< ::java::util::Map* >(npc(expectedIncomingSockets)->get(target));
    if(one == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
            auto s = u""_j;
            for (auto _i = npc(npc(expectedIncomingSockets)->keySet())->iterator(); _i->hasNext(); ) {
                RendezvousContact* h = java_cast< RendezvousContact* >(_i->next());
                {
                    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" "_j)->append(static_cast< ::java::lang::Object* >(h))->toString())->toString();
                }
            }
            npc(logger)->log(::java::lang::StringBuilder().append(u"removeExpectedIncomingSocket("_j)->append(static_cast< ::java::lang::Object* >(target))
                ->append(u"@"_j)
                ->append(::java::lang::System::identityHashCode(target))
                ->append(u","_j)
                ->append(uid)
                ->append(u") had no first level entry for target"_j)
                ->append(s)->toString());
        }
        return nullptr;
    }
    auto ret = java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(one)->get(::java::lang::Integer::valueOf(uid)));
    if(ret == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
            auto s = u""_j;
            for (auto _i = npc(npc(one)->keySet())->iterator(); _i->hasNext(); ) {
                ::java::lang::Integer* h = java_cast< ::java::lang::Integer* >(_i->next());
                {
                    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" "_j)->append(static_cast< ::java::lang::Object* >(h))->toString())->toString();
                }
            }
            npc(logger)->log(::java::lang::StringBuilder().append(u"removeExpectedIncomingSocket("_j)->append(static_cast< ::java::lang::Object* >(target))
                ->append(u"@"_j)
                ->append(::java::lang::System::identityHashCode(target))
                ->append(u","_j)
                ->append(uid)
                ->append(u") had no uid for target"_j)
                ->append(s)->toString());
        }
    } else {
        npc(one)->remove(::java::lang::Integer::valueOf(uid));
    }
    if(npc(one)->isEmpty())
        npc(expectedIncomingSockets)->remove(target);

    return ret;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::createForwarder(::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b, RendezvousContact* connector, RendezvousContact* acceptor, int32_t uid)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"createForwarder("_j)->append(static_cast< ::java::lang::Object* >(a))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(b))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(connector))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(acceptor))
            ->append(u","_j)
            ->append(uid)
            ->append(u")"_j)->toString());

    new ::org::mpisws::p2p::transport::sourceroute::Forwarder(nullptr, a, b, logger);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::putConnectSocket(RendezvousContact* requestor, RendezvousContact* target, int32_t uid, ::org::mpisws::p2p::transport::P2PSocket* socket)
{
    auto one = java_cast< ::java::util::Map* >(npc(connectSockets)->get(requestor));
    if(one == nullptr) {
        one = new ::java::util::HashMap();
        npc(connectSockets)->put(requestor, one);
    }
    auto two = java_cast< ::java::util::Map* >(npc(one)->get(target));
    if(two == nullptr) {
        two = new ::java::util::HashMap();
        npc(one)->put(target, two);
    }
    auto three = java_cast< ::org::mpisws::p2p::transport::P2PSocket* >(npc(two)->get(::java::lang::Integer::valueOf(uid)));
    if(three != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"error in storeConnectSocket() there is already a connector with the same UID!!!, dropping the new one.  Old:"_j)->append(static_cast< ::java::lang::Object* >(three))
                ->append(u" new:"_j)
                ->append(static_cast< ::java::lang::Object* >(socket))->toString());

        npc(socket)->close();
        return;
    }
    npc(two)->put(::java::lang::Integer::valueOf(uid), socket);
}

org::mpisws::p2p::transport::P2PSocket* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::removeConnectSocket(RendezvousContact* requestor, RendezvousContact* target, int32_t uid)
{
    auto one = java_cast< ::java::util::Map* >(npc(connectSockets)->get(requestor));
    if(one == nullptr) {
        return nullptr;
    }
    auto two = java_cast< ::java::util::Map* >(npc(one)->get(target));
    if(two == nullptr) {
        return nullptr;
    }
    auto three = java_cast< ::org::mpisws::p2p::transport::P2PSocket* >(npc(two)->remove(::java::lang::Integer::valueOf(uid)));
    if(npc(two)->isEmpty())
        npc(one)->remove(target);

    if(npc(one)->isEmpty())
        npc(connectSockets)->remove(requestor);

    return three;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openChannel(RendezvousContact* requestor, RendezvousContact* middleMan, int32_t uid)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openChannel("_j)->append(static_cast< ::java::lang::Object* >(requestor))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(middleMan))
            ->append(u","_j)
            ->append(uid)
            ->append(u")"_j)->toString());

    openAcceptSocket(requestor, middleMan, uid);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openChannel(::java::lang::Object* requestor, ::java::lang::Object* middleMan, int32_t uid)
{ 
    openChannel(dynamic_cast< RendezvousContact* >(requestor), dynamic_cast< RendezvousContact* >(middleMan), uid);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openAcceptSocket(RendezvousContact* requestor, RendezvousContact* middleMan, int32_t uid)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(middleMan))
            ->append(u","_j)
            ->append(uid)
            ->append(u")"_j)->toString());

    if(!npc(middleMan)->canContactDirect()) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(middleMan))
            ->append(u","_j)
            ->append(uid)
            ->append(u") middleMan is firewalled."_j)->toString());
    }
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    try {
        npc(sob)->writeByte(ACCEPTOR_SOCKET);
        npc(serializer)->serialize(java_cast< RendezvousContact* >(localNodeHandle), sob);
        npc(serializer)->serialize(requestor, sob);
        npc(sob)->writeInt(uid);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Error serializing in openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(middleMan))
                ->append(u","_j)
                ->append(uid)
                ->append(u")"_j)->toString(), ioe);

        return;
    }
    auto const writeBuffer = npc(sob)->getByteBuffer();
    auto const readBuffer = ::java::nio::ByteBuffer::allocate(1);
    npc(tl)->openSocket(java_cast< ::java::lang::Object* >(npc(serializer)->convert(middleMan)), new RendezvousTransportLayerImpl_openAcceptSocket_7(this, writeBuffer, requestor, middleMan, uid, readBuffer), ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(nullptr, RENDEZVOUS_CONTACT_STRING, requestor));
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::messageReceivedFromOverlay(RendezvousContact* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceivedFromOverlay("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    messageReceived(java_cast< ::java::lang::Object* >(npc(serializer)->convert(i)), m, ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, FROM_OVERLAY(), ::java::lang::Boolean::valueOf(true)));
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::messageReceivedFromOverlay(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options)
{ 
    messageReceivedFromOverlay(dynamic_cast< RendezvousContact* >(i), m, options);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    if(npc(options)->containsKey(FROM_OVERLAY()) && (npc((java_cast< ::java::lang::Boolean* >(java_cast< ::java::lang::Object* >(npc(options)->get(FROM_OVERLAY()))))))->booleanValue() == true) {
    } else {
        npc(responseStrategy)->messageReceived(i, m, options);
        options = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, TAG_KEY(), ::java::lang::Long::valueOf(npc(ephemeralDB)->getTagForEphemeral(i)));
    }
    npc(callback)->messageReceived(i, m, options);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

org::mpisws::p2p::transport::rendezvous::RendezvousContact* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::getHighIdentifier(::java::util::Map* options)
{
    if(options == nullptr)
        return nullptr;

    return java_cast< RendezvousContact* >(java_cast< ::java::lang::Object* >(npc(options)->get(RENDEZVOUS_CONTACT_STRING)));
}

int64_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::getTag(::java::util::Map* options)
{
    if(options == nullptr)
        return NO_TAG;

    auto ret = java_cast< ::java::lang::Object* >(npc(options)->get(TAG_KEY()));
    if(ret == nullptr)
        return NO_TAG;

    return npc((java_cast< ::java::lang::Long* >(ret)))->longValue();
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    auto high = java_cast< RendezvousContact* >(getHighIdentifier(options));
    if(high == nullptr) {
        auto tag = getTag(options);
        if(tag != NO_TAG) {
            i = java_cast< ::java::lang::Object* >(npc(ephemeralDB)->getEphemeral(tag, i));
        }
        npc(responseStrategy)->messageSent(i, m, options);
        return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
    } else {
        if(npc(high)->canContactDirect() || npc(contactDirectStrategy)->canContactDirect(high)) {
            npc(responseStrategy)->messageSent(i, m, options);
            return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
        } else {
            auto tag = getTag(options);
            if(tag != NO_TAG) {
                npc(ephemeralDB)->mapHighToTag(high, tag);
            }
            auto ephemeral = java_cast< ::java::lang::Object* >(npc(ephemeralDB)->getEphemeral(high));
            if(ephemeral != nullptr && npc(responseStrategy)->sendDirect(ephemeral, m, options)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Sending directly on ephemeral "_j)->append(static_cast< ::java::lang::Object* >(ephemeral))
                        ->append(u" for "_j)
                        ->append(static_cast< ::java::lang::Object* >(high))->toString());

                npc(responseStrategy)->messageSent(ephemeral, m, options);
                return npc(tl)->sendMessage(ephemeral, m, deliverAckToMe, options);
            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Not sending directly on ephemeral "_j)->append(static_cast< ::java::lang::Object* >(ephemeral))
                    ->append(u" for "_j)
                    ->append(static_cast< ::java::lang::Object* >(high))->toString());

            auto const ret = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
            ::org::mpisws::p2p::transport::MessageCallback* ack;
            if(deliverAckToMe == nullptr) {
                ack = nullptr;
            } else {
                ack = new RendezvousTransportLayerImpl_sendMessage_8(this, deliverAckToMe, ret);
            }
            if(npc(incomingPilots)->containsKey(high)) {
                options = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, OPTION_USE_PILOT(), high);
            }
            npc(ret)->setSubCancellable(npc(rendezvousStrategy)->sendMessage(high, m, ack, options));
            return ret;
        }
    }
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

java::lang::String* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"RendezvousTL{"_j)->append(static_cast< ::java::lang::Object* >(java_cast< RendezvousContact* >(localNodeHandle)))
        ->append(u"}"_j)->toString();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::destroy()
{
    npc(tl)->destroy();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::notifyOutgoingPilotAdded(RendezvousContact* i)
{
    auto temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(opListeners));
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        OutgoingPilotListener* l = java_cast< OutgoingPilotListener* >(_i->next());
        {
            npc(l)->pilotOpening(i);
        }
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::notifyOutgoingPilotRemoved(RendezvousContact* i)
{
    auto temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(opListeners));
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        OutgoingPilotListener* l = java_cast< OutgoingPilotListener* >(_i->next());
        {
            npc(l)->pilotClosed(i);
        }
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::addOutgoingPilotListener(OutgoingPilotListener* listener)
{
    {
        synchronized synchronized_0(opListeners);
        {
            npc(opListeners)->add(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::removeOutgoingPilotListener(OutgoingPilotListener* listener)
{
    {
        synchronized synchronized_1(opListeners);
        {
            npc(opListeners)->remove(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openPilot(RendezvousContact* i, ::rice::Continuation* deliverAckToMe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openPilot("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u")"_j)->toString());

    if(!npc(i)->canContactDirect())
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"can't open pilot to natted node:"_j)->append(static_cast< ::java::lang::Object* >(i))->toString());

    RendezvousTransportLayerImpl_OutgoingPilot* o2;
    ::java::util::Map* options;
    {
        synchronized synchronized_2(outgoingPilots);
        {
            if(npc(outgoingPilots)->containsKey(i)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"openPilot("_j)->append(static_cast< ::java::lang::Object* >(i))
                        ->append(u") already had one."_j)->toString());

                if(deliverAckToMe != nullptr)
                    npc(deliverAckToMe)->receiveResult(java_cast< RendezvousTransportLayerImpl_OutgoingPilot* >(npc(outgoingPilots)->get(i)));

                return java_cast< RendezvousTransportLayerImpl_OutgoingPilot* >(npc(outgoingPilots)->get(i));
            }
            options = npc(serializer)->getOptions(i);
            o2 = new RendezvousTransportLayerImpl_OutgoingPilot(this, i, options);
            npc(outgoingPilots)->put(i, o2);
        }
    }
    npc(o2)->init_();
    notifyOutgoingPilotAdded(i);
    auto const o = o2;
    npc(o)->setCancellable(npc(tl)->openSocket(java_cast< ::java::lang::Object* >(npc(serializer)->convert(i)), new RendezvousTransportLayerImpl_openPilot_9(this, o, deliverAckToMe), options));
    return o;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::openPilot(::java::lang::Object* i, ::rice::Continuation* deliverAckToMe)
{ 
    return openPilot(dynamic_cast< RendezvousContact* >(i), dynamic_cast< ::rice::Continuation* >(deliverAckToMe));
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::closePilot(RendezvousContact* i)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"closePilot("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u")"_j)->toString());

    RendezvousTransportLayerImpl_OutgoingPilot* closeMe;
    {
        synchronized synchronized_3(outgoingPilots);
        {
            closeMe = java_cast< RendezvousTransportLayerImpl_OutgoingPilot* >(npc(outgoingPilots)->remove(i));
        }
    }
    if(closeMe != nullptr) {
        npc(closeMe)->cancel();
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::closePilot(::java::lang::Object* i)
{ 
    closePilot(dynamic_cast< RendezvousContact* >(i));
}

constexpr int8_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_PING;

constexpr int8_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_PONG;

constexpr int8_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_REQUEST;

int8_tArray*& org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_PING_BYTES()
{
    clinit();
    return PILOT_PING_BYTES_;
}
int8_tArray* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_PING_BYTES_;

int8_tArray*& org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_PONG_BYTES()
{
    clinit();
    return PILOT_PONG_BYTES_;
}
int8_tArray* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_PONG_BYTES_;

int8_tArray*& org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_SOCKET_BYTES()
{
    clinit();
    return PILOT_SOCKET_BYTES_;
}
int8_tArray* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_SOCKET_BYTES_;

constexpr int32_t org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::PILOT_PING_PERIOD;

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::notifyIncomingPilotAdded(RendezvousContact* i)
{
    auto temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(ipListeners));
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        IncomingPilotListener* l = java_cast< IncomingPilotListener* >(_i->next());
        {
            npc(l)->pilotOpening(i);
        }
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::notifyIncomingPilotRemoved(RendezvousContact* i)
{
    auto temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(ipListeners));
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        IncomingPilotListener* l = java_cast< IncomingPilotListener* >(_i->next());
        {
            npc(l)->pilotClosed(i);
        }
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::addIncomingPilotListener(IncomingPilotListener* listener)
{
    {
        synchronized synchronized_4(ipListeners);
        {
            npc(ipListeners)->add(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::removeIncomingPilotListener(IncomingPilotListener* listener)
{
    {
        synchronized synchronized_5(ipListeners);
        {
            npc(ipListeners)->remove(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

int8_tArray* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::makeByteArray_(int8_t writeMe)
{
    clinit();
    auto foo = new ::int8_tArray(int32_t(1));
    (*foo)[int32_t(0)] = writeMe;
    return foo;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.rendezvous.RendezvousTransportLayerImpl", 64);
    return c;
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::clinit()
{
struct string_init_ {
    string_init_() {
    TAG_KEY_ = u"RendezvousTransportLayer.UDP_TAG"_j;
    FROM_OVERLAY_ = u"rendezvous.from_overlay"_j;
    OPTION_USE_PILOT_ = u"USE_PILOT"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        PILOT_PING_BYTES_ = (new ::int8_tArray({PILOT_PING}));
        PILOT_PONG_BYTES_ = (new ::int8_tArray({PILOT_PONG}));
        PILOT_SOCKET_BYTES_ = (new ::int8_tArray({PILOT_SOCKET}));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl::getClass0()
{
    return class_();
}

