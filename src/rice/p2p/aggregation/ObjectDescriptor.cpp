// Generated from /pastry-2.1/src/rice/p2p/aggregation/ObjectDescriptor.java
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>

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

rice::p2p::aggregation::ObjectDescriptor::ObjectDescriptor(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::ObjectDescriptor::ObjectDescriptor(::rice::p2p::commonapi::Id* key, int64_t version, int64_t currentLifetime, int64_t refreshedLifetime, int32_t size) 
    : ObjectDescriptor(*static_cast< ::default_init_tag* >(0))
{
    ctor(key,version,currentLifetime,refreshedLifetime,size);
}

constexpr int64_t rice::p2p::aggregation::ObjectDescriptor::serialVersionUID;

void rice::p2p::aggregation::ObjectDescriptor::ctor(::rice::p2p::commonapi::Id* key, int64_t version, int64_t currentLifetime, int64_t refreshedLifetime, int32_t size)
{
    super::ctor();
    this->key = key;
    this->currentLifetime = currentLifetime;
    this->refreshedLifetime = refreshedLifetime;
    this->size = size;
    this->version = version;
}

java::lang::String* rice::p2p::aggregation::ObjectDescriptor::toString()
{
    return ::java::lang::StringBuilder().append(u"objDesc["_j)->append(npc(key)->toStringFull())
        ->append(u"v"_j)
        ->append(version)
        ->append(u", lt="_j)
        ->append(currentLifetime)
        ->append(u", rt="_j)
        ->append(refreshedLifetime)
        ->append(u", size="_j)
        ->append(size)
        ->append(u"]"_j)->toString();
}

bool rice::p2p::aggregation::ObjectDescriptor::isAliveAt(int64_t pointInTime)
{
    return (currentLifetime > pointInTime) || (refreshedLifetime > pointInTime);
}

int32_t rice::p2p::aggregation::ObjectDescriptor::compareTo(ObjectDescriptor* other)
{
    auto metadata = java_cast< ObjectDescriptor* >(other);
    auto result = npc(this->key)->compareTo(npc(metadata)->key);
    if(result != 0)
        return result;

    if(npc(metadata)->version > this->version)
        return -int32_t(1);

    if(npc(metadata)->version < this->version)
        return 1;

    if(npc(metadata)->currentLifetime > this->currentLifetime)
        return -int32_t(1);

    if(npc(metadata)->currentLifetime < this->currentLifetime)
        return 1;

    if(npc(metadata)->refreshedLifetime > this->refreshedLifetime)
        return -int32_t(1);

    if(npc(metadata)->refreshedLifetime < this->refreshedLifetime)
        return 1;

    if(npc(metadata)->size > this->size)
        return -int32_t(1);
    else if(npc(metadata)->size < this->size)
        return 1;

    return 0;
}

int32_t rice::p2p::aggregation::ObjectDescriptor::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< ObjectDescriptor* >(o));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::ObjectDescriptor::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.ObjectDescriptor", 37);
    return c;
}

java::lang::Class* rice::p2p::aggregation::ObjectDescriptor::getClass0()
{
    return class_();
}

