// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/SocketManager.java
#include <org/mpisws/p2p/transport/wire/SocketManager_close_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/wire/SocketManager.hpp>
#include <org/mpisws/p2p/transport/wire/TCPLayer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::SocketManager_close_2::SocketManager_close_2(SocketManager *SocketManager_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketManager_this(SocketManager_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::wire::SocketManager_close_2::run()
{
    if(SocketManager_this->writer != nullptr) {
        if(SocketManager_this->writer == SocketManager_this->reader) {
            auto temp = SocketManager_this->writer;
            SocketManager_this->writer = nullptr;
            SocketManager_this->reader = nullptr;
            npc(temp)->receiveException(SocketManager_this, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Channel closed. "_j)->append(static_cast< ::java::lang::Object* >(SocketManager_this))->toString()));
        } else {
            auto temp = SocketManager_this->writer;
            SocketManager_this->writer = nullptr;
            npc(temp)->receiveException(SocketManager_this, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Channel closed. "_j)->append(static_cast< ::java::lang::Object* >(SocketManager_this))->toString()));
        }
    }
    if(SocketManager_this->reader != nullptr) {
        if(npc(SocketManager_this->tcp)->isDestroyed())
            return;

        auto temp = SocketManager_this->reader;
        SocketManager_this->reader = nullptr;
        npc(temp)->receiveException(SocketManager_this, new ::org::mpisws::p2p::transport::ClosedChannelException(u"Channel closed."_j));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::SocketManager_close_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::SocketManager_close_2::getClass0()
{
    return class_();
}

