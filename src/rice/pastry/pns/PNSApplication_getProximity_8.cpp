// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getProximity_8.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Map.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::pns::PNSApplication_getProximity_8::PNSApplication_getProximity_8(PNSApplication *PNSApplication_this, ::rice::pastry::NodeHandle* handle, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , handle(handle)
    , c(c)
{
    clinit();
    ctor();
}

bool rice::pastry::pns::PNSApplication_getProximity_8::cancel()
{
    {
        synchronized synchronized_0(PNSApplication_this->waitingForPing);
        {
            auto waiters = java_cast< ::java::util::Collection* >(npc(PNSApplication_this->waitingForPing)->get(handle));
            if(waiters != nullptr) {
                npc(waiters)->remove(c);
                if(npc(waiters)->isEmpty()) {
                    npc(PNSApplication_this->waitingForPing)->remove(handle);
                }
            }
        }
    }
    super::cancel();
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getProximity_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getProximity_8::getClass0()
{
    return class_();
}

