// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/SocketManager.java
#include <org/mpisws/p2p/transport/wire/SocketManager.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/Socket.hpp>
#include <java/net/SocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/nio/channels/SelectableChannel.hpp>
#include <java/nio/channels/SelectionKey.hpp>
#include <java/nio/channels/ServerSocketChannel.hpp>
#include <java/nio/channels/SocketChannel.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/wire/SocketManager_close_2.hpp>
#include <org/mpisws/p2p/transport/wire/SocketManager_shutdownOutput_3.hpp>
#include <org/mpisws/p2p/transport/wire/SocketManager_SocketManager_1.hpp>
#include <org/mpisws/p2p/transport/wire/TCPLayer.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
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
org::mpisws::p2p::transport::wire::SocketManager::SocketManager(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::wire::SocketManager::SocketManager(TCPLayer* tcp, ::java::nio::channels::SelectionKey* serverKey)  /* throws(IOException) */
    : SocketManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(tcp,serverKey);
}

org::mpisws::p2p::transport::wire::SocketManager::SocketManager(TCPLayer* tcp, ::java::net::InetSocketAddress* addr, ::org::mpisws::p2p::transport::SocketCallback* c, ::java::util::Map* options)  /* throws(IOException) */
    : SocketManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(tcp,addr,c,options);
}

void org::mpisws::p2p::transport::wire::SocketManager::init()
{
    delivered = false;
}

void org::mpisws::p2p::transport::wire::SocketManager::ctor(TCPLayer* tcp, ::java::nio::channels::SelectionKey* serverKey) /* throws(IOException) */
{
    super::ctor();
    init();
    this->tcp = tcp;
    logger = npc(tcp)->logger;
    channel = java_cast< ::java::nio::channels::SocketChannel* >(npc((java_cast< ::java::nio::channels::ServerSocketChannel* >(npc(serverKey)->channel())))->accept());
    npc(npc(channel)->socket())->setSendBufferSize(npc(tcp)->SOCKET_BUFFER_SIZE);
    npc(npc(channel)->socket())->setReceiveBufferSize(npc(tcp)->SOCKET_BUFFER_SIZE);
    npc(npc(channel)->socket())->setTcpNoDelay(npc(tcp)->TCP_NO_DELAY);
    npc(channel)->configureBlocking(false);
    addr = java_cast< ::java::net::InetSocketAddress* >(npc(npc(channel)->socket())->getRemoteSocketAddress());
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"(SA) "_j)->append(u"Accepted incoming connection from "_j)
            ->append(static_cast< ::java::lang::Object* >(addr))->toString());

    key = npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->register_(channel, this, 0);
}

void org::mpisws::p2p::transport::wire::SocketManager::ctor(TCPLayer* tcp, ::java::net::InetSocketAddress* addr, ::org::mpisws::p2p::transport::SocketCallback* c, ::java::util::Map* options) /* throws(IOException) */
{
    super::ctor();
    init();
    this->tcp = tcp;
    this->options = options;
    logger = npc(tcp)->logger;
    this->addr = addr;
    channel = ::java::nio::channels::SocketChannel::open();
    npc(npc(channel)->socket())->setSendBufferSize(npc(tcp)->SOCKET_BUFFER_SIZE);
    npc(npc(channel)->socket())->setReceiveBufferSize(npc(tcp)->SOCKET_BUFFER_SIZE);
    if(npc(npc(tcp)->wire)->forceBindAddress && npc(npc(tcp)->wire)->bindAddress != nullptr)
        npc(npc(channel)->socket())->bind(new ::java::net::InetSocketAddress(npc(npc(npc(tcp)->wire)->bindAddress)->getAddress(), int32_t(0)));

    npc(channel)->configureBlocking(false);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"(SM) Initiating socket connection to "_j)->append(static_cast< ::java::lang::Object* >(addr))->toString());

    if(npc(channel)->connect(addr)) {
        key = npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->register_(channel, this, 0);
        delivered = true;
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"delivering1 "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

        npc(c)->receiveResult(this, this);
    } else {
        key = npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->register_(channel, new SocketManager_SocketManager_1(this, tcp, addr, c), ::java::nio::channels::SelectionKey::OP_CONNECT);
    }
}

java::lang::String* org::mpisws::p2p::transport::wire::SocketManager::toString()
{
    return ::java::lang::StringBuilder().append(u"SM "_j)->append(static_cast< ::java::lang::Object* >(addr))
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(channel))->toString();
}

void org::mpisws::p2p::transport::wire::SocketManager::close()
{
    try {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
            npc(logger)->log(::java::lang::StringBuilder().append(u"Closing "_j)->append(static_cast< ::java::lang::Object* >(this))
                ->append(u" r:"_j)
                ->append(static_cast< ::java::lang::Object* >(reader))
                ->append(u" w:"_j)
                ->append(static_cast< ::java::lang::Object* >(writer))->toString());
        } else if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Closing "_j)->append(static_cast< ::java::lang::Object* >(this))
                ->append(u" r:"_j)
                ->append(static_cast< ::java::lang::Object* >(reader))
                ->append(u" w:"_j)
                ->append(static_cast< ::java::lang::Object* >(writer))->toString(), new ::java::lang::Exception(u"Stack Trace"_j));
        }
        if(key != nullptr) {
            npc(key)->cancel();
            npc(key)->attach(nullptr);
            key = nullptr;
        } else {
            return;
        }
        if(channel != nullptr) {
            npc(channel)->close();
        }
        npc(tcp)->socketClosed(this);
        npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->invoke(new SocketManager_close_2(this));
    } catch (::java::io::IOException* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"ERROR: Recevied exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                ->append(u" while closing socket!"_j)->toString());

    }
}

void org::mpisws::p2p::transport::wire::SocketManager::modifyKey(::java::nio::channels::SelectionKey* key)
{
    auto flag = int32_t(0);
    if(reader != nullptr) {
        flag |= ::java::nio::channels::SelectionKey::OP_READ;
    }
    if(writer != nullptr) {
        flag |= ::java::nio::channels::SelectionKey::OP_WRITE;
    }
    npc(key)->interestOps(flag);
}

void org::mpisws::p2p::transport::wire::SocketManager::read(::java::nio::channels::SelectionKey* key)
{
    ::org::mpisws::p2p::transport::P2PSocketReceiver* temp = nullptr;
    {
        synchronized synchronized_0(this);
        {
            if(reader == nullptr) {
                npc(key)->interestOps(npc(key)->interestOps() & ~::java::nio::channels::SelectionKey::OP_READ);
                return;
            }
            temp = reader;
            reader = nullptr;
        }
    }
    try {
        npc(temp)->receiveSelectResult(this, true, false);
    } catch (::java::io::IOException* ioe) {
        npc(temp)->receiveException(this, ioe);
    }
    npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->modifyKey(key);
}

void org::mpisws::p2p::transport::wire::SocketManager::write(::java::nio::channels::SelectionKey* key)
{
    ::org::mpisws::p2p::transport::P2PSocketReceiver* temp = nullptr;
    {
        synchronized synchronized_1(this);
        {
            if(writer == nullptr) {
                npc(key)->interestOps(npc(key)->interestOps() & ~::java::nio::channels::SelectionKey::OP_WRITE);
                return;
            }
            temp = writer;
            writer = nullptr;
        }
    }
    try {
        npc(temp)->receiveSelectResult(this, false, true);
    } catch (::java::io::IOException* ioe) {
        npc(temp)->receiveException(this, ioe);
    }
    npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->modifyKey(key);
}

void org::mpisws::p2p::transport::wire::SocketManager::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".register("_j)
            ->append((wantToRead ? u"r"_j : u""_j))
            ->append((wantToWrite ? u"w"_j : u""_j))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(receiver))
            ->append(u")"_j)->toString());

    if(key == nullptr) {
        auto cce = new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(addr))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(this))
            ->append(u" is already closed."_j)->toString());
        if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(addr))
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(this))
                ->append(u" is already closed."_j)->toString(), cce);

        npc(receiver)->receiveException(this, cce);
        return;
    }
    if(wantToWrite) {
        if(npc(npc(channel)->socket())->isOutputShutdown()) {
            npc(receiver)->receiveException(this, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(addr))
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(this))
                ->append(u" already shut down output."_j)->toString()));
            return;
        }
        if(writer != nullptr) {
            if(writer != receiver) {
                throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Already registered "_j)->append(static_cast< ::java::lang::Object* >(writer))
                    ->append(u" for writing, you can't register "_j)
                    ->append(static_cast< ::java::lang::Object* >(receiver))
                    ->append(u" for writing as well! SM:"_j)
                    ->append(static_cast< ::java::lang::Object* >(this))->toString());
            }
        }
    }
    if(wantToRead) {
        if(reader != nullptr) {
            if(reader != receiver)
                throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Already registered "_j)->append(static_cast< ::java::lang::Object* >(reader))
                    ->append(u" for reading, you can't register "_j)
                    ->append(static_cast< ::java::lang::Object* >(receiver))
                    ->append(u" for reading as well!"_j)->toString());

        }
        reader = receiver;
    }
    if(wantToWrite) {
        writer = receiver;
    }
    npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->modifyKey(key);
}

void org::mpisws::p2p::transport::wire::SocketManager::shutdownOutput()
{
    auto closeMe = false;
    {
        synchronized synchronized_2(this);
        {
            if(key == nullptr) {
                throw new ::java::lang::IllegalStateException(u"Socket already closed."_j);
            }
            if(npc(npc(channel)->socket())->isClosed()) {
            }
            try {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Shutting down output on app connection "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

                npc(npc(channel)->socket())->shutdownOutput();
                npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->invoke(new SocketManager_shutdownOutput_3(this));
            } catch (::java::io::IOException* e) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"ERROR: Received exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                        ->append(u" while shutting down output for socket "_j)
                        ->append(static_cast< ::java::lang::Object* >(this))->toString());

                closeMe = true;
            }
        }
    }
    npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->modifyKey(key);
    if(closeMe) {
        close();
    }
}

int64_t org::mpisws::p2p::transport::wire::SocketManager::read(::java::nio::ByteBuffer* dst) /* throws(IOException) */
{
    if(key == nullptr || npc(npc(channel)->socket())->isInputShutdown())
        return -int32_t(1);

    try {
        int64_t ret = npc(channel)->read(dst);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"read("_j)
                    ->append(ret)
                    ->append(u"):"_j)
                    ->append(::java::util::Arrays::toString(npc(dst)->array()))->toString());
            } else {
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"read("_j)
                    ->append(ret)
                    ->append(u")"_j)->toString());
            }
        }
        return ret;
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
            npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" error reading"_j)->toString(), ioe);
        } else if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" error reading"_j)->toString());

        close();
        throw ioe;
    }
}

int64_t org::mpisws::p2p::transport::wire::SocketManager::write(::java::nio::ByteBuffer* src) /* throws(IOException) */
{
    if(key == nullptr || npc(npc(channel)->socket())->isOutputShutdown())
        return -int32_t(1);

    try {
        int64_t ret = npc(channel)->write(src);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"write("_j)
                    ->append(ret)
                    ->append(u"):"_j)
                    ->append(::java::util::Arrays::toString(npc(src)->array()))->toString());
            } else {
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"write("_j)
                    ->append(ret)
                    ->append(u")"_j)->toString());
            }
        }
        return ret;
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
            npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" error writing"_j)->toString(), ioe);
        } else if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" error writing"_j)->toString());

        close();
        throw ioe;
    }
}

bool org::mpisws::p2p::transport::wire::SocketManager::cancel()
{
    if(key == nullptr)
        return false;

    if(delivered)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".cancel() Can't cancel, already delivered"_j)->toString());

    close();
    return true;
}

void org::mpisws::p2p::transport::wire::SocketManager::exceptionAndClose(::java::io::IOException* e)
{
    npc(npc(npc(tcp)->wire)->errorHandler)->receivedException(addr, e);
    close();
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::wire::SocketManager::getIdentifier()
{
    return addr;
}

java::util::Map* org::mpisws::p2p::transport::wire::SocketManager::getOptions()
{
    return options;
}

java::nio::channels::SocketChannel* org::mpisws::p2p::transport::wire::SocketManager::getSocketChannel()
{
    npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->cancel(key);
    return channel;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::SocketManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.SocketManager", 43);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::SocketManager::getClass0()
{
    return class_();
}

