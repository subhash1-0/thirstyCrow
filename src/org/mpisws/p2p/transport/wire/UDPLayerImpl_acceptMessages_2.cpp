// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/UDPLayerImpl.java
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl_acceptMessages_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/channels/SelectionKey.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::UDPLayerImpl_acceptMessages_2::UDPLayerImpl_acceptMessages_2(UDPLayerImpl *UDPLayerImpl_this, bool b)
    : super(*static_cast< ::default_init_tag* >(0))
    , UDPLayerImpl_this(UDPLayerImpl_this)
    , b(b)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl_acceptMessages_2::run()
{
    if(b) {
        npc(UDPLayerImpl_this->key)->interestOps(npc(UDPLayerImpl_this->key)->interestOps() | ::java::nio::channels::SelectionKey::OP_READ);
    } else {
        npc(UDPLayerImpl_this->key)->interestOps(npc(UDPLayerImpl_this->key)->interestOps() & ~::java::nio::channels::SelectionKey::OP_READ);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::UDPLayerImpl_acceptMessages_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::UDPLayerImpl_acceptMessages_2::getClass0()
{
    return class_();
}

