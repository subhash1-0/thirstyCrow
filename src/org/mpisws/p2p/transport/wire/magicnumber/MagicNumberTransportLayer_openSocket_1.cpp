// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_openSocket_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_openSocket_1_receiveResult_1_1.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_openSocket_1_receiveResult_1_2.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1::MagicNumberTransportLayer_openSocket_1(MagicNumberTransportLayer *MagicNumberTransportLayer_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* cancellable, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , MagicNumberTransportLayer_this(MagicNumberTransportLayer_this)
    , cancellable(cancellable)
    , deliverSocketToMe(deliverSocketToMe)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::org::mpisws::p2p::transport::P2PSocket* result)
{
    if(npc(cancellable)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(c) != npc(cancellable)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"c != cancellable.getSubCancellable() (indicates a bug in the code) c:"_j)->append(static_cast< ::java::lang::Object* >(c))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(cancellable)->getSubCancellable()))->toString());

    npc(cancellable)->setSubCancellable(new MagicNumberTransportLayer_openSocket_1_receiveResult_1_1(this, result));
    npc(result)->register_(false, true, new MagicNumberTransportLayer_openSocket_1_receiveResult_1_2(this, deliverSocketToMe, cancellable));
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::java::lang::Exception* exception)
{
    if(npc(cancellable)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(c) != npc(cancellable)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"c != cancellable.getSubCancellable() (indicates a bug in the code) c:"_j)->append(static_cast< ::java::lang::Object* >(c))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(cancellable)->getSubCancellable()))->toString());

    npc(deliverSocketToMe)->receiveException(cancellable, exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1::getClass0()
{
    return class_();
}

