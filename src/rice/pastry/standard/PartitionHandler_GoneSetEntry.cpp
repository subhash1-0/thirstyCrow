// Generated from /pastry-2.1/src/rice/pastry/standard/PartitionHandler.java
#include <rice/pastry/standard/PartitionHandler_GoneSetEntry.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
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

rice::pastry::standard::PartitionHandler_GoneSetEntry::PartitionHandler_GoneSetEntry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::PartitionHandler_GoneSetEntry::PartitionHandler_GoneSetEntry(::rice::pastry::NodeHandle* nh, int64_t timestamp) 
    : PartitionHandler_GoneSetEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(nh,timestamp);
}

void rice::pastry::standard::PartitionHandler_GoneSetEntry::ctor(::rice::pastry::NodeHandle* nh, int64_t timestamp)
{
    super::ctor();
    this->nh = nh;
    this->timestamp = timestamp;
}

bool rice::pastry::standard::PartitionHandler_GoneSetEntry::equals(::java::lang::Object* o)
{
    auto other = java_cast< PartitionHandler_GoneSetEntry* >(o);
    return npc(npc(npc(other)->nh)->getId())->equals(npc(nh)->getId());
}

java::lang::String* rice::pastry::standard::PartitionHandler_GoneSetEntry::toString()
{
    return ::java::lang::StringBuilder().append(npc(nh)->toString())->append(u" "_j)
        ->append(timestamp)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::PartitionHandler_GoneSetEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.PartitionHandler.GoneSetEntry", 50);
    return c;
}

java::lang::Class* rice::pastry::standard::PartitionHandler_GoneSetEntry::getClass0()
{
    return class_();
}

