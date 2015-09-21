// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/SocketManager.java
#include <org/mpisws/p2p/transport/wire/SocketManager_SocketManager_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/channels/SelectionKey.hpp>
#include <java/nio/channels/SocketChannel.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/wire/SocketManager.hpp>
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

org::mpisws::p2p::transport::wire::SocketManager_SocketManager_1::SocketManager_SocketManager_1(SocketManager *SocketManager_this, TCPLayer* tcp, ::java::net::InetSocketAddress* addr, ::org::mpisws::p2p::transport::SocketCallback* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketManager_this(SocketManager_this)
    , tcp(tcp)
    , addr(addr)
    , c(c)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::wire::SocketManager_SocketManager_1::write(::java::nio::channels::SelectionKey* key)
{
    SocketManager_this->write(key);
}

void org::mpisws::p2p::transport::wire::SocketManager_SocketManager_1::read(::java::nio::channels::SelectionKey* key)
{
    SocketManager_this->read(key);
}

void org::mpisws::p2p::transport::wire::SocketManager_SocketManager_1::modifyKey(::java::nio::channels::SelectionKey* key)
{
    SocketManager_this->modifyKey(key);
}

void org::mpisws::p2p::transport::wire::SocketManager_SocketManager_1::connect(::java::nio::channels::SelectionKey* key)
{
    try {
        if(npc(SocketManager_this->channel)->finishConnect()) {
            key = npc(npc(npc(npc(tcp)->wire)->environment)->getSelectorManager())->register_(SocketManager_this->channel, SocketManager_this, npc(key)->interestOps() & ~::java::nio::channels::SelectionKey::OP_CONNECT);
            SocketManager_this->delivered = true;
            if(npc(SocketManager_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(SocketManager_this->logger)->log(::java::lang::StringBuilder().append(u"delivering2 "_j)->append(static_cast< ::java::lang::Object* >(SocketManager_this))->toString());

            npc(npc(tcp)->wire)->broadcastChannelOpened(addr, java_cast< ::java::util::Map* >(SocketManager_this->options), true);
            npc(c)->receiveResult(SocketManager_this, SocketManager_this);
        }
    } catch (::java::io::IOException* e) {
        if(c == nullptr) {
            npc(npc(npc(tcp)->wire)->errorHandler)->receivedException(addr, e);
        } else {
            npc(c)->receiveException(SocketManager_this, e);
        }
        SocketManager_this->close();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::SocketManager_SocketManager_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::SocketManager_SocketManager_1::getClass0()
{
    return class_();
}

