// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/TimeoutResponseStrategy.java
#include <org/mpisws/p2p/transport/rendezvous/TimeoutResponseStrategy.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/util/TimerWeakHashMap.hpp>
#include <rice/selector/SelectorManager.hpp>

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

org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy::TimeoutResponseStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy::TimeoutResponseStrategy(int32_t timeout, ::rice::environment::Environment* env) 
    : TimeoutResponseStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(timeout,env);
}

void org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy::ctor(int32_t timeout, ::rice::environment::Environment* env)
{
    super::ctor();
    this->timeout = timeout;
    this->lastTimeReceived = new ::rice::p2p::util::TimerWeakHashMap(npc(env)->getSelectorManager(), int32_t(60000) + timeout);
    this->time = npc(env)->getTimeSource();
}

void org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options)
{
    npc(lastTimeReceived)->put(i, ::java::lang::Long::valueOf(npc(time)->currentTimeMillis()));
}

void org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy::messageSent(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options)
{
}

bool org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy::sendDirect(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options)
{
    int64_t lastTime = int32_t(0);
    if(npc(lastTimeReceived)->containsKey(i)) {
        lastTime = (npc(java_cast< ::java::lang::Long* >(npc(lastTimeReceived)->get(i))))->longValue();
    }
    return npc(time)->currentTimeMillis() <= (lastTime + timeout);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.rendezvous.TimeoutResponseStrategy", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy::getClass0()
{
    return class_();
}

