// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_VerifyHeaderReceiver.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Arrays.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/wire/exception/StalledSocketException.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::MagicNumberTransportLayer_VerifyHeaderReceiver(MagicNumberTransportLayer *MagicNumberTransportLayer_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MagicNumberTransportLayer_this(MagicNumberTransportLayer_this)
{
    clinit();
}

org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::MagicNumberTransportLayer_VerifyHeaderReceiver(MagicNumberTransportLayer *MagicNumberTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* s) 
    : MagicNumberTransportLayer_VerifyHeaderReceiver(MagicNumberTransportLayer_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(s);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::init()
{
    buf = ::java::nio::ByteBuffer::allocate(npc(MagicNumberTransportLayer_this->HEADER)->length);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::ctor(::org::mpisws::p2p::transport::P2PSocket* s)
{
    super::ctor();
    init();
    this->socket = s;
    npc(npc(npc(MagicNumberTransportLayer_this->environment)->getSelectorManager())->getTimer())->schedule(this, MagicNumberTransportLayer_this->SOCKET_TIMEOUT);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(MagicNumberTransportLayer_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), ioe);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canWrite)
        throw new ::java::io::IOException(u"Never asked to write!"_j);

    if(!canRead)
        throw new ::java::io::IOException(u"Can't read!"_j);

    int64_t bytesRead;
    if((bytesRead = npc(socket)->read(buf)) < 0) {
        npc(socket)->close();
        return;
    }
    MagicNumberTransportLayer_this->notifyListenersRead(static_cast< int32_t >(bytesRead), java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), npc(socket)->getOptions(), false, true);
    if(npc(buf)->hasRemaining()) {
        npc(socket)->register_(true, false, this);
    } else {
        if(::java::util::Arrays::equals(MagicNumberTransportLayer_this->HEADER, npc(buf)->array())) {
            cancel();
            npc(MagicNumberTransportLayer_this->callback)->incomingSocket(socket);
        } else {
            cancel();
            npc(MagicNumberTransportLayer_this->errorHandler)->receivedUnexpectedData(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), npc(buf)->array(), 0, nullptr);
        }
    }
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::run()
{
    npc(socket)->close();
    npc(MagicNumberTransportLayer_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), new ::org::mpisws::p2p::transport::wire::exception::StalledSocketException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), u"Timeout on incoming socket expired."_j));
}

java::lang::String* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::toString()
{
    return ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(MagicNumberTransportLayer_this))->append(u" VHR"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.magicnumber.MagicNumberTransportLayer.VerifyHeaderReceiver", 88);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver::getClass0()
{
    return class_();
}

