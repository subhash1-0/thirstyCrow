// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_IdentityMessageHandle.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

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

org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::IdentityImpl_IdentityMessageHandle(IdentityImpl *IdentityImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_this(IdentityImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::IdentityImpl_IdentityMessageHandle(IdentityImpl *IdentityImpl_this, ::java::lang::Object* identifier, ::java::lang::Object* message, ::java::util::Map* options, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe) 
    : IdentityImpl_IdentityMessageHandle(IdentityImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,message,options,deliverAckToMe);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::ctor(::java::lang::Object* identifier, ::java::lang::Object* message, ::java::util::Map* options, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe)
{
    super::ctor();
    this->identifier = identifier;
    this->message = message;
    this->options = options;
    this->deliverAckToMe = deliverAckToMe;
}

java::lang::Object* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(identifier);
}

java::lang::Object* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::getMessage()
{
    return java_cast< ::java::lang::Object* >(message);
}

java::util::Map* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::getOptions()
{
    return options;
}

void org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::deadForever()
{
    cancel();
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(this, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(java_cast< ::java::lang::Object* >(identifier), java_cast< ::java::lang::Object* >(message)));

}

bool org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::cancel()
{
    IdentityImpl_this->removePendingMessage(java_cast< ::java::lang::Object* >(identifier), this);
    return npc(subCancellable)->cancel();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::setSubCancellable(::rice::p2p::commonapi::Cancellable* cancellable)
{
    this->subCancellable = cancellable;
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::getSubCancellable()
{
    return subCancellable;
}

void org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    IdentityImpl_this->removePendingMessage(java_cast< ::java::lang::Object* >(identifier), this);
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(this);

}

void org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    IdentityImpl_this->removePendingMessage(java_cast< ::java::lang::Object* >(identifier), this);
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(this, reason);

}

java::lang::String* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::toString()
{
    return ::java::lang::StringBuilder().append(u"IdMsgHdl{"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(message)))
        ->append(u"}->"_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(identifier)))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.identity.IdentityImpl.IdentityMessageHandle", 68);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle::getClass0()
{
    return class_();
}

