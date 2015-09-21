// Generated from /pastry-2.1/src/rice/pastry/NodeHandle.java
#include <rice/pastry/NodeHandle_ObsPri.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Observer.hpp>

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

rice::pastry::NodeHandle_ObsPri::NodeHandle_ObsPri(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::NodeHandle_ObsPri::NodeHandle_ObsPri(::java::util::Observer* o, int32_t priority) 
    : NodeHandle_ObsPri(*static_cast< ::default_init_tag* >(0))
{
    ctor(o,priority);
}

void rice::pastry::NodeHandle_ObsPri::ctor(::java::util::Observer* o, int32_t priority)
{
    super::ctor();
    obs = o;
    pri = priority;
}

int32_t rice::pastry::NodeHandle_ObsPri::compareTo(NodeHandle_ObsPri* o)
{
    auto that = java_cast< NodeHandle_ObsPri* >(o);
    auto ret = npc(that)->pri - pri;
    if(ret == 0) {
        if(npc(that)->equals(o)) {
            return 0;
        } else {
            return ::java::lang::System::identityHashCode(that) - ::java::lang::System::identityHashCode(this);
        }
    }
    return ret;
}

int32_t rice::pastry::NodeHandle_ObsPri::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< NodeHandle_ObsPri* >(o));
}

java::lang::String* rice::pastry::NodeHandle_ObsPri::toString()
{
    return ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(obs))->append(u":"_j)
        ->append(pri)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::NodeHandle_ObsPri::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.NodeHandle.ObsPri", 29);
    return c;
}

java::lang::Class* rice::pastry::NodeHandle_ObsPri::getClass0()
{
    return class_();
}

