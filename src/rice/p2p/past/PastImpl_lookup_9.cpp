// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_lookup_9.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/LookupMessage.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastImpl_lookup_9::PastImpl_lookup_9(PastImpl *PastImpl_this, ::rice::Continuation* command, ::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , command(command)
    , id(id)
    , cache(cache)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_lookup_9::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr) {
        npc(command)->receiveResult(o);
    } else {
        PastImpl_this->sendRequest(id, static_cast< ::rice::p2p::past::messaging::PastMessage* >(new ::rice::p2p::past::messaging::LookupMessage(PastImpl_this->getUID(), id, PastImpl_this->getLocalNodeHandle(), id)), static_cast< ::rice::Continuation* >(new PastImpl_lookup_9_receiveResult_9_1(this, cache, command, id, ::java::lang::StringBuilder().append(u"LookupMessage for "_j)->append(static_cast< ::java::lang::Object* >(id))->toString(), this)));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_lookup_9::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_lookup_9::getClass0()
{
    return class_();
}

