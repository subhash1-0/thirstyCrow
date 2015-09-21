// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_getExternalNodes_3.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_openSocket_4.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_incomingSocket_5.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleIpRequest_6.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleNodesRequest_7.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleIdRequest_8.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeRequest_9.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeResponse_10.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_sendMessage_11.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_verifyConnectivity_12.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_verifyConnectivity_13.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_probe_14.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_probe_15.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_getMyInetAddress_1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_getId_2.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ProbeStrategy.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.hpp>
#include <org/mpisws/p2p/transport/util/BufferReader.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
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
org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::NetworkInfoTransportLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::NetworkInfoTransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler) 
    : NetworkInfoTransportLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,env,errorHandler);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::init()
{
    serializedIds = new ::java::util::HashMap();
    addrSerializer = new ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer();
    verifyConnectionRequests = new ::java::util::HashMap();
}

constexpr int8_t org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_PASSTHROUGH_BYTE;

constexpr int8_t org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_IP_ADDRESS_REQUEST_BYTE;

constexpr int8_t org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_PROBE_REQUEST_BYTE;

constexpr int8_t org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_PROBE_RESPONSE_BYTE;

constexpr int8_t org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_NODES_REQUEST_BYTE;

constexpr int8_t org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_ID_REQUEST_BYTE;

int8_tArray*& org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_PASSTHROUGH()
{
    clinit();
    return HEADER_PASSTHROUGH_;
}
int8_tArray* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_PASSTHROUGH_;

int8_tArray*& org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_IP_ADDRESS_REQUEST()
{
    clinit();
    return HEADER_IP_ADDRESS_REQUEST_;
}
int8_tArray* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_IP_ADDRESS_REQUEST_;

int8_tArray*& org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_NODES_REQUEST()
{
    clinit();
    return HEADER_NODES_REQUEST_;
}
int8_tArray* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::HEADER_NODES_REQUEST_;

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler)
{
    super::ctor();
    init();
    this->logger = npc(npc(env)->getLogManager())->getLogger(NetworkInfoTransportLayer::class_(), nullptr);
    this->environment = env;
    this->tl = tl;
    this->errorHandler = errorHandler;
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->errorHandler) == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
    npc(tl)->setCallback(this);
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::getMyInetAddress(::java::net::InetSocketAddress* bootstrap, ::rice::Continuation* c, ::java::util::Map* options)
{
    auto ret = new ::rice::p2p::util::AttachableCancellable();
    npc(ret)->attach(openSocket(bootstrap, HEADER_IP_ADDRESS_REQUEST_, new NetworkInfoTransportLayer_getMyInetAddress_1(this, c), options));
    return ret;
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::setId(int8_t index, ::int8_tArray* value)
{
    npc(serializedIds)->put(::java::lang::Byte::valueOf(index), value);
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::getId(::java::net::InetSocketAddress* bootstrap, int8_t index, ::rice::Continuation* c, ::java::util::Map* options)
{
    auto hdr = new ::int8_tArray(int32_t(2));
    (*hdr)[int32_t(0)] = HEADER_ID_REQUEST_BYTE;
    (*hdr)[int32_t(1)] = index;
    auto ret = new ::rice::p2p::util::AttachableCancellable();
    npc(ret)->attach(openSocket(bootstrap, hdr, new NetworkInfoTransportLayer_getId_2(this, c), options));
    return ret;
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::getExternalNodes(::java::net::InetSocketAddress* bootstrap, ::rice::Continuation* c, ::java::util::Map* options)
{
    auto ret = new ::rice::p2p::util::AttachableCancellable();
    npc(ret)->attach(openSocket(bootstrap, HEADER_NODES_REQUEST_, new NetworkInfoTransportLayer_getExternalNodes_3(this, c), options));
    return ret;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::openSocket(::java::net::InetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO - int32_t(50))
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    return openSocket(i, HEADER_PASSTHROUGH_, deliverSocketToMe, options);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::openSocket(::java::net::InetSocketAddress* i, ::int8_tArray* header, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(npc(header)->length)
            ->append(u")"_j)->toString());

    if(deliverSocketToMe == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"deliverSocketToMe must be non-null!"_j);

    auto const cancellable = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(cancellable)->setSubCancellable(npc(tl)->openSocket(i, new NetworkInfoTransportLayer_openSocket_4(this, cancellable, header, i, deliverSocketToMe), options));
    return cancellable;
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u")"_j)->toString());

    (new NetworkInfoTransportLayer_incomingSocket_5(this, s))->receiveSelectResult(s, true, false);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::handleIpRequest(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */
{
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"HEADER_IP_ADDRESS_REQUEST_BYTE serializing "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier())))->toString());

    npc(addrSerializer)->serialize(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier()), static_cast< ::rice::p2p::commonapi::rawserialization::OutputBuffer* >(sob));
    auto const writeMe = npc(sob)->getByteBuffer();
    (new NetworkInfoTransportLayer_handleIpRequest_6(this, writeMe))->receiveSelectResult(socket, false, true);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::handleNodesRequest(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */
{
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    auto ret = npc(probeStrategy)->getExternalAddresses();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"serializing "_j)->append(npc(ret)->size())
            ->append(u" external addresses for "_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier())))->toString());

    if(npc(ret)->size() > 20) {
        auto temp = new ::java::util::ArrayList(int32_t(20));
        auto ctr = int32_t(0);
        for (auto _i = npc(ret)->iterator(); _i->hasNext(); ) {
            ::java::net::InetSocketAddress* foo = java_cast< ::java::net::InetSocketAddress* >(_i->next());
            {
                npc(temp)->add(static_cast< ::java::lang::Object* >(foo));
                ctr++;
                if(ctr > 20)
                    break;

            }
        }
        ret = temp;
    }
    npc(sob)->writeByte(npc(ret)->size());
    for (auto _i = npc(ret)->iterator(); _i->hasNext(); ) {
        ::java::net::InetSocketAddress* foo = java_cast< ::java::net::InetSocketAddress* >(_i->next());
        {
            npc(addrSerializer)->serialize(foo, static_cast< ::rice::p2p::commonapi::rawserialization::OutputBuffer* >(sob));
        }
    }
    auto const writeMe = npc(sob)->getByteBuffer();
    (new NetworkInfoTransportLayer_handleNodesRequest_7(this, writeMe))->receiveSelectResult(socket, false, true);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::handleIdRequest(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */
{
    auto const indexBuf = ::java::nio::ByteBuffer::allocate(1);
    new ::org::mpisws::p2p::transport::util::BufferReader(socket, new NetworkInfoTransportLayer_handleIdRequest_8(this, socket), int32_t(1));
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::handleProbeRequest(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    try {
        (new NetworkInfoTransportLayer_handleProbeRequest_9(this, socket))->receiveSelectResult(socket, true, false);
    } catch (::java::io::IOException* ioe) {
        npc(errorHandler)->receivedException(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier()), ioe);
        npc(socket)->close();
    }
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::handleProbeResponse(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    try {
        (new NetworkInfoTransportLayer_handleProbeResponse_10(this, socket))->receiveSelectResult(socket, true, false);
    } catch (::java::io::IOException* ioe) {
        npc(errorHandler)->receivedException(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier()), ioe);
        npc(socket)->close();
    }
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    if(handler == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
        return;
    }
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::getLocalIdentifier()
{
    return java_cast< ::java::net::InetSocketAddress* >(npc(tl)->getLocalIdentifier());
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::sendMessage(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    auto const ret = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    auto passThrough = ::java::nio::ByteBuffer::allocate(npc(m)->remaining() + int32_t(1));
    npc(passThrough)->put(HEADER_PASSTHROUGH_BYTE);
    npc(passThrough)->put(m);
    npc(passThrough)->flip();
    ::org::mpisws::p2p::transport::MessageCallback* myCallback = nullptr;
    if(deliverAckToMe != nullptr) {
        myCallback = new NetworkInfoTransportLayer_sendMessage_11(this, deliverAckToMe, ret);
    }
    npc(ret)->setSubCancellable(npc(tl)->sendMessage(i, passThrough, myCallback, options));
    return ret;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    auto header = npc(m)->get();
    {
        int64_t uid;
        switch (header) {
        case HEADER_PASSTHROUGH_BYTE:
            npc(callback)->messageReceived(i, m, options);
            return;
        case HEADER_PROBE_RESPONSE_BYTE:
            uid = npc(m)->getLong();
            npc(java_cast< ConnectivityResult* >(npc(verifyConnectionRequests)->get(::java::lang::Long::valueOf(uid))))->udpSuccess(i, nullptr);
        }
    }

}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::destroy()
{
    npc(verifyConnectionRequests)->clear();
    npc(tl)->destroy();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::setProbeStrategy(ProbeStrategy* probeStrategy)
{
    this->probeStrategy = probeStrategy;
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::verifyConnectivity(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::net::InetSocketAddress* probeAddress, ConnectivityResult* deliverResultToMe, ::java::util::Map* options)
{
    auto ret = new ::rice::p2p::util::AttachableCancellable();
    auto const uid = npc(npc(environment)->getRandomSource())->nextLong();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"verifyConnectivity("_j)->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeAddress))
            ->append(u"):"_j)
            ->append(uid)->toString());

    {
        synchronized synchronized_0(verifyConnectionRequests);
        {
            npc(verifyConnectionRequests)->put(::java::lang::Long::valueOf(uid), deliverResultToMe);
        }
    }
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    try {
        npc(sob)->writeByte(HEADER_PROBE_REQUEST_BYTE);
        npc(local)->serialize(sob);
        npc(sob)->writeLong(uid);
    } catch (::java::io::IOException* ioe) {
        {
            synchronized synchronized_1(verifyConnectionRequests);
            {
                npc(verifyConnectionRequests)->remove(::java::lang::Long::valueOf(uid));
            }
        }
        npc(deliverResultToMe)->receiveException(ioe);
        return nullptr;
    }
    npc(ret)->attach(new NetworkInfoTransportLayer_verifyConnectivity_12(this, uid));
    npc(ret)->attach(openSocket(probeAddress, npc(sob)->getBytes(), new NetworkInfoTransportLayer_verifyConnectivity_13(this, deliverResultToMe, probeAddress, local), options));
    return ret;
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::probe(::java::net::InetSocketAddress* addr, int64_t uid, ::rice::Continuation* deliverResponseToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"probe("_j)->append(static_cast< ::java::lang::Object* >(addr))
            ->append(u","_j)
            ->append(uid)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverResponseToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    auto const ret = new ::rice::p2p::util::AttachableCancellable();
    auto msg = ::java::nio::ByteBuffer::allocate(9);
    npc(msg)->put(HEADER_PROBE_RESPONSE_BYTE);
    npc(msg)->putLong(uid);
    npc(msg)->flip();
    auto const success = new ::boolArray(int32_t(2));
    (*success)[int32_t(0)] = false;
    (*success)[int32_t(1)] = false;
    ::org::mpisws::p2p::transport::MessageCallback* mc = nullptr;
    if(deliverResponseToMe != nullptr) {
        mc = new NetworkInfoTransportLayer_probe_14(this, addr, uid, deliverResponseToMe, options, success, ret);
    }
    npc(ret)->attach(npc(tl)->sendMessage(addr, msg, mc, options));
    auto const writeMe = ::java::nio::ByteBuffer::allocate(9);
    npc(writeMe)->put(HEADER_PROBE_RESPONSE_BYTE);
    npc(writeMe)->putLong(uid);
    npc(writeMe)->flip();
    npc(ret)->attach(openSocket(addr, npc(writeMe)->array(), new NetworkInfoTransportLayer_probe_15(this, addr, uid, deliverResponseToMe, options, success), options));
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.networkinfo.NetworkInfoTransportLayer", 62);
    return c;
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        HEADER_PASSTHROUGH_ = (new ::int8_tArray({HEADER_PASSTHROUGH_BYTE}));
        HEADER_IP_ADDRESS_REQUEST_ = (new ::int8_tArray({HEADER_IP_ADDRESS_REQUEST_BYTE}));
        HEADER_NODES_REQUEST_ = (new ::int8_tArray({HEADER_NODES_REQUEST_BYTE}));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer::getClass0()
{
    return class_();
}

