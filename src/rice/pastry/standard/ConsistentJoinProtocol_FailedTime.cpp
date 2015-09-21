// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinProtocol.java
#include <rice/pastry/standard/ConsistentJoinProtocol_FailedTime.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/NodeHandle.hpp>

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

rice::pastry::standard::ConsistentJoinProtocol_FailedTime::ConsistentJoinProtocol_FailedTime(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::ConsistentJoinProtocol_FailedTime::ConsistentJoinProtocol_FailedTime(::rice::pastry::NodeHandle* handle, int64_t time) 
    : ConsistentJoinProtocol_FailedTime(*static_cast< ::default_init_tag* >(0))
{
    ctor(handle,time);
}

void rice::pastry::standard::ConsistentJoinProtocol_FailedTime::ctor(::rice::pastry::NodeHandle* handle, int64_t time)
{
    super::ctor();
    this->time = time;
    this->handle = handle;
}

int32_t rice::pastry::standard::ConsistentJoinProtocol_FailedTime::compareTo(ConsistentJoinProtocol_FailedTime* arg0)
{
    auto ft = java_cast< ConsistentJoinProtocol_FailedTime* >(arg0);
    return static_cast< int32_t >((npc(ft)->time - this->time));
}

int32_t rice::pastry::standard::ConsistentJoinProtocol_FailedTime::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< ConsistentJoinProtocol_FailedTime* >(o));
}

java::lang::String* rice::pastry::standard::ConsistentJoinProtocol_FailedTime::toString()
{
    return ::java::lang::StringBuilder().append(u"FT:"_j)->append(static_cast< ::java::lang::Object* >(handle))
        ->append(u" "_j)
        ->append(time)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol_FailedTime::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.ConsistentJoinProtocol.FailedTime", 54);
    return c;
}

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol_FailedTime::getClass0()
{
    return class_();
}

