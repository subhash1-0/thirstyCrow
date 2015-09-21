// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_openSocket_1_receiveResult_1_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.hpp>

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

org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1_receiveResult_1_2::MagicNumberTransportLayer_openSocket_1_receiveResult_1_2(MagicNumberTransportLayer_openSocket_1 *MagicNumberTransportLayer_openSocket_1_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* cancellable)
    : super(*static_cast< ::default_init_tag* >(0))
    , MagicNumberTransportLayer_openSocket_1_this(MagicNumberTransportLayer_openSocket_1_this)
    , deliverSocketToMe(deliverSocketToMe)
    , cancellable(cancellable)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1_receiveResult_1_2::init()
{
    buf = ::java::nio::ByteBuffer::wrap(MagicNumberTransportLayer_openSocket_1_this->MagicNumberTransportLayer_this->HEADER);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1_receiveResult_1_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead)
        throw new ::java::io::IOException(u"Never asked to read!"_j);

    if(!canWrite)
        throw new ::java::io::IOException(u"Can't write!"_j);

    auto ret = npc(socket)->write(buf);
    if(ret < 0) {
        npc(socket)->close();
        return;
    }
    MagicNumberTransportLayer_openSocket_1_this->MagicNumberTransportLayer_this->notifyListenersWrite(static_cast< int32_t >(ret), java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), npc(socket)->getOptions(), false, true);
    if(npc(buf)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
    } else {
        npc(deliverSocketToMe)->receiveResult(cancellable, socket);
    }
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1_receiveResult_1_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    npc(deliverSocketToMe)->receiveException(cancellable, e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1_receiveResult_1_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1_receiveResult_1_2::getClass0()
{
    return class_();
}

