// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/SocketManager.java
#include <org/mpisws/p2p/transport/wire/SocketManager_shutdownOutput_3.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/wire/SocketManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::SocketManager_shutdownOutput_3::SocketManager_shutdownOutput_3(SocketManager *SocketManager_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketManager_this(SocketManager_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::wire::SocketManager_shutdownOutput_3::run()
{
    if(SocketManager_this->writer != nullptr) {
        npc(SocketManager_this->writer)->receiveException(SocketManager_this, new ::org::mpisws::p2p::transport::ClosedChannelException(u"Channel shut down."_j));
        SocketManager_this->writer = nullptr;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::SocketManager_shutdownOutput_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::SocketManager_shutdownOutput_3::getClass0()
{
    return class_();
}

