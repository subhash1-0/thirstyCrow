// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/RC4TransportLayer.java
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_openSocket_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_openSocket_1_receiveResult_1_1.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1::RC4TransportLayer_openSocket_1(RC4TransportLayer *RC4TransportLayer_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , RC4TransportLayer_this(RC4TransportLayer_this)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
    , i(i)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(s, ex);
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    auto const decryptSeed = new ::int8_tArray(RC4TransportLayer_this->PW_SEED_LENGTH);
    npc(RC4TransportLayer_this->random)->nextBytes(decryptSeed);
    ::org::mpisws::p2p::transport::P2PSocketReceiver* writeDecryptSeedReceiver = new RC4TransportLayer_openSocket_1_receiveResult_1_1(this, decryptSeed, deliverSocketToMe, ret, i, options);
    try {
        npc(writeDecryptSeedReceiver)->receiveSelectResult(sock, false, true);
    } catch (::java::io::IOException* ioe) {
        npc(deliverSocketToMe)->receiveException(ret, ioe);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1::getClass0()
{
    return class_();
}

