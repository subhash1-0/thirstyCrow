// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_LSSocket.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/LinkedHashMap.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_LSSocket_forceClose_1.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/selector/Timer.hpp>

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

org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::LimitSocketsTransportLayer_LSSocket(LimitSocketsTransportLayer *LimitSocketsTransportLayer_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , LimitSocketsTransportLayer_this(LimitSocketsTransportLayer_this)
{
    clinit();
}

org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::LimitSocketsTransportLayer_LSSocket(LimitSocketsTransportLayer *LimitSocketsTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* socket) 
    : LimitSocketsTransportLayer_LSSocket(LimitSocketsTransportLayer_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(socket);
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::init()
{
    closed = false;
    forcedClose = false;
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::ctor(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    super::ctor(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), socket, LimitSocketsTransportLayer_this->logger, LimitSocketsTransportLayer_this->handler, npc(socket)->getOptions());
    init();
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::forceClose()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".forceClose()"_j)->toString());

    forcedClose = true;
    super::shutdownOutput();
    npc(LimitSocketsTransportLayer_this->timer)->schedule(new LimitSocketsTransportLayer_LSSocket_forceClose_1(this), 3000);
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::close()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".close()"_j)->toString());

    closed = true;
    npc(LimitSocketsTransportLayer_this->cache)->remove(static_cast< ::java::lang::Object* >(this));
    super::close();
}

int64_t org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */
{
    if(!closed)
        LimitSocketsTransportLayer_this->touch(this);

    try {
        return super::read(dsts);
    } catch (::java::io::IOException* ioe) {
        close();
        throw ioe;
    }
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    if(forcedClose) {
        if(wantToWrite) {
            npc(receiver)->receiveException(this, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Limit Sockets forced close. "_j)->append(static_cast< ::java::lang::Object* >(this))->toString()));
        }
        if(wantToRead) {
            super::register_(true, false, static_cast< ::org::mpisws::p2p::transport::P2PSocketReceiver* >(receiver));
        }
        return;
    }
    if(!closed)
        LimitSocketsTransportLayer_this->touch(this);

    super::register_(wantToRead, wantToWrite, static_cast< ::org::mpisws::p2p::transport::P2PSocketReceiver* >(receiver));
}

int64_t org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    if(forcedClose)
        throw new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Limit Sockets forced close. "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

    if(!closed)
        LimitSocketsTransportLayer_this->touch(this);

    try {
        return super::write(srcs);
    } catch (::java::io::IOException* ioe) {
        close();
        throw ioe;
    }
}

java::lang::String* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::toString()
{
    return ::java::lang::StringBuilder().append(LimitSocketsTransportLayer_this->toString())->append(u"$LSSocket<"_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(identifier)))
        ->append(u">["_j)
        ->append((closed ? u"closed"_j : u"open"_j))
        ->append(u"]@"_j)
        ->append(::java::lang::System::identityHashCode(this))
        ->append(npc(socket)->toString())->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.limitsockets.LimitSocketsTransportLayer.LSSocket", 73);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket::getClass0()
{
    return class_();
}

