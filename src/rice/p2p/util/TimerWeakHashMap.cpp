// Generated from /pastry-2.1/src/rice/p2p/util/TimerWeakHashMap.java
#include <rice/p2p/util/TimerWeakHashMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/util/TimerWeakHashMap_HardLinkTimerTask.hpp>
#include <rice/selector/Timer.hpp>

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

rice::p2p::util::TimerWeakHashMap::TimerWeakHashMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::TimerWeakHashMap::TimerWeakHashMap(::rice::selector::Timer* t, int32_t delay) 
    : TimerWeakHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(t,delay);
}

void rice::p2p::util::TimerWeakHashMap::ctor(::rice::selector::Timer* t, int32_t delay)
{
    super::ctor();
    this->defaultDelay = delay;
    timer = t;
}

java::lang::Object* rice::p2p::util::TimerWeakHashMap::put(::java::lang::Object* key, ::java::lang::Object* val)
{
    refresh(key);
    return java_cast< ::java::lang::Object* >(super::put(static_cast< ::java::lang::Object* >(key), static_cast< ::java::lang::Object* >(val)));
}

void rice::p2p::util::TimerWeakHashMap::refresh(::java::lang::Object* key)
{
    refresh(key, defaultDelay);
}

void rice::p2p::util::TimerWeakHashMap::refresh(::java::lang::Object* key, int32_t delay)
{
    npc(timer)->schedule(new TimerWeakHashMap_HardLinkTimerTask(key), delay);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::TimerWeakHashMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.TimerWeakHashMap", 30);
    return c;
}

java::lang::Class* rice::p2p::util::TimerWeakHashMap::getClass0()
{
    return class_();
}

