// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/TCPLayer.java
#include <org/mpisws/p2p/transport/wire/TCPLayer.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/ServerSocket.hpp>
#include <java/nio/channels/SelectableChannel.hpp>
#include <java/nio/channels/SelectionKey.hpp>
#include <java/nio/channels/ServerSocketChannel.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/wire/SocketManager.hpp>
#include <org/mpisws/p2p/transport/wire/TCPLayer_acceptSockets_1.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/selector/SelectorManager.hpp>

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
org::mpisws::p2p::transport::wire::TCPLayer::TCPLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::wire::TCPLayer::TCPLayer(WireTransportLayerImpl* wire, bool enableServer)  /* throws(IOException) */
    : TCPLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(wire,enableServer);
}

void org::mpisws::p2p::transport::wire::TCPLayer::init()
{
    TCP_NO_DELAY = false;
    sockets = new ::java::util::HashSet();
}

java::util::Map*& org::mpisws::p2p::transport::wire::TCPLayer::OPTIONS()
{
    clinit();
    return OPTIONS_;
}
java::util::Map* org::mpisws::p2p::transport::wire::TCPLayer::OPTIONS_;

void org::mpisws::p2p::transport::wire::TCPLayer::ctor(WireTransportLayerImpl* wire, bool enableServer) /* throws(IOException) */
{
    super::ctor();
    init();
    this->wire = wire;
    this->logger = npc(npc(npc(wire)->environment)->getLogManager())->getLogger(TCPLayer::class_(), nullptr);
    auto p = npc(npc(wire)->environment)->getParameters();
    MAX_OPEN_SOCKETS = npc(p)->getInt(u"pastry_socket_scm_max_open_sockets"_j);
    SOCKET_BUFFER_SIZE = npc(p)->getInt(u"pastry_socket_scm_socket_buffer_size"_j);
    if(npc(p)->contains(u"transport_tcp_no_delay"_j)) {
        TCP_NO_DELAY = npc(p)->getBoolean(u"transport_tcp_no_delay"_j);
    }
    ::java::nio::channels::ServerSocketChannel* temp = nullptr;
    if(enableServer) {
        auto const channel = ::java::nio::channels::ServerSocketChannel::open();
        temp = channel;
        npc(channel)->configureBlocking(false);
        npc(npc(channel)->socket())->setReuseAddress(true);
        npc(npc(channel)->socket())->bind(npc(wire)->bindAddress);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"TCPLayer bound to "_j)->append(static_cast< ::java::lang::Object* >(npc(wire)->bindAddress))->toString());

        this->key = npc(npc(npc(wire)->environment)->getSelectorManager())->register_(channel, this, ::java::nio::channels::SelectionKey::OP_ACCEPT);
    }
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::wire::TCPLayer::openSocket(::java::net::InetSocketAddress* destination, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(isDestroyed())
        return nullptr;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
        npc(logger)->logException(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(destination))
            ->append(u")"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(destination))
                ->append(u")"_j)->toString());

    }
    if(deliverSocketToMe == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"deliverSocketToMe must be non-null!"_j);

    try {
        npc(wire)->broadcastChannelOpened(destination, options, true);
        {
            synchronized synchronized_0(sockets);
            {
                auto sm = new SocketManager(this, destination, deliverSocketToMe, options);
                npc(sockets)->add(sm);
                return sm;
            }
        }
    } catch (::java::io::IOException* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"GOT ERROR "_j)->append(static_cast< ::java::lang::Object* >(e))
                ->append(u" OPENING PATH - MARKING PATH "_j)
                ->append(static_cast< ::java::lang::Object* >(destination))
                ->append(u" AS DEAD!"_j)->toString(), e);

        ::org::mpisws::p2p::transport::SocketRequestHandle* can = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(destination, options, logger);
        npc(deliverSocketToMe)->receiveException(can, e);
        return can;
    }
}

void org::mpisws::p2p::transport::wire::TCPLayer::socketClosed(SocketManager* sm)
{
    npc(wire)->broadcastChannelClosed(npc(sm)->addr, npc(sm)->options);
    npc(sockets)->remove(sm);
}

void org::mpisws::p2p::transport::wire::TCPLayer::destroy()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"destroy()"_j);

    try {
        if(key != nullptr) {
            npc(npc(key)->channel())->close();
            npc(key)->cancel();
            npc(key)->attach(nullptr);
        }
    } catch (::java::io::IOException* ioe) {
        npc(npc(wire)->errorHandler)->receivedException(nullptr, ioe);
    }
    for (auto _i = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(sockets))->iterator(); _i->hasNext(); ) {
        SocketManager* socket = java_cast< SocketManager* >(_i->next());
        {
            npc(socket)->close();
        }
    }
}

void org::mpisws::p2p::transport::wire::TCPLayer::acceptSockets(bool b)
{
    ::java::lang::Runnable* r = new TCPLayer_acceptSockets_1(this, b);
    if(npc(npc(npc(wire)->environment)->getSelectorManager())->isSelectorThread()) {
        npc(r)->run();
    } else {
        npc(npc(npc(wire)->environment)->getSelectorManager())->invoke(r);
    }
}

void org::mpisws::p2p::transport::wire::TCPLayer::accept(::java::nio::channels::SelectionKey* key)
{
    try {
        auto sm = new SocketManager(this, key);
        {
            synchronized synchronized_1(sockets);
            {
                npc(sockets)->add(sm);
            }
        }
        npc(wire)->incomingSocket(sm);
    } catch (::java::io::IOException* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"ERROR (accepting connection): "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());

        npc(npc(wire)->errorHandler)->receivedException(nullptr, e);
    }
}

bool org::mpisws::p2p::transport::wire::TCPLayer::isDestroyed()
{
    return npc(wire)->isDestroyed();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::TCPLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.TCPLayer", 38);
    return c;
}

void org::mpisws::p2p::transport::wire::TCPLayer::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        {
            ::java::util::Map* map = new ::java::util::HashMap();
            npc(map)->put(WireTransportLayer::OPTION_TRANSPORT_TYPE(), ::java::lang::Integer::valueOf(WireTransportLayer::TRANSPORT_TYPE_GUARANTEED));
            OPTIONS_ = ::java::util::Collections::unmodifiableMap(map);
        }
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::transport::wire::TCPLayer::getClass0()
{
    return class_();
}

