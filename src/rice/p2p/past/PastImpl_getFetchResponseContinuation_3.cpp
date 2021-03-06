// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_getFetchResponseContinuation_3.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/ContinuationMessage.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>
#include <rice/p2p/past/rawserialization/SocketStrategy.hpp>

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

rice::p2p::past::PastImpl_getFetchResponseContinuation_3::PastImpl_getFetchResponseContinuation_3(PastImpl *PastImpl_this, ::rice::p2p::past::messaging::ContinuationMessage* cmsg, ::rice::p2p::past::messaging::PastMessage* msg)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , cmsg(cmsg)
    , msg(msg)
{
    clinit();
    ctor();
}

void rice::p2p::past::PastImpl_getFetchResponseContinuation_3::receiveResult(::java::lang::Object* o)
{
    npc(cmsg)->receiveResult(o);
    auto content = java_cast< PastContent* >(o);
    if(npc(PastImpl_this->socketStrategy)->sendAlongSocket(::rice::p2p::past::rawserialization::SocketStrategy::TYPE_FETCH, content)) {
        PastImpl_this->sendViaSocket(npc(msg)->getSource(), cmsg, nullptr);
    } else {
        npc(PastImpl_this->endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(cmsg), npc(msg)->getSource());
    }
}

void rice::p2p::past::PastImpl_getFetchResponseContinuation_3::receiveException(::java::lang::Exception* e)
{
    npc(cmsg)->receiveException(e);
    npc(PastImpl_this->endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(cmsg), npc(msg)->getSource());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_getFetchResponseContinuation_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_getFetchResponseContinuation_3::getClass0()
{
    return class_();
}

