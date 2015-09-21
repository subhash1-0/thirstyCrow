// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/TCPLayer.java
#include <org/mpisws/p2p/transport/wire/TCPLayer_acceptSockets_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/channels/SelectionKey.hpp>
#include <org/mpisws/p2p/transport/wire/TCPLayer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::TCPLayer_acceptSockets_1::TCPLayer_acceptSockets_1(TCPLayer *TCPLayer_this, bool b)
    : super(*static_cast< ::default_init_tag* >(0))
    , TCPLayer_this(TCPLayer_this)
    , b(b)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::wire::TCPLayer_acceptSockets_1::run()
{
    if(b) {
        npc(TCPLayer_this->key)->interestOps(npc(TCPLayer_this->key)->interestOps() | ::java::nio::channels::SelectionKey::OP_ACCEPT);
    } else {
        npc(TCPLayer_this->key)->interestOps(npc(TCPLayer_this->key)->interestOps() & ~::java::nio::channels::SelectionKey::OP_ACCEPT);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::TCPLayer_acceptSockets_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::TCPLayer_acceptSockets_1::getClass0()
{
    return class_();
}

