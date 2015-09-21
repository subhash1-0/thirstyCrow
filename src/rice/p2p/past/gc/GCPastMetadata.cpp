// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastMetadata.java
#include <rice/p2p/past/gc/GCPastMetadata.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>

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

rice::p2p::past::gc::GCPastMetadata::GCPastMetadata(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::GCPastMetadata::GCPastMetadata(int64_t expiration) 
    : GCPastMetadata(*static_cast< ::default_init_tag* >(0))
{
    ctor(expiration);
}

constexpr int64_t rice::p2p::past::gc::GCPastMetadata::serialVersionUID;

void rice::p2p::past::gc::GCPastMetadata::ctor(int64_t expiration)
{
    super::ctor();
    this->expiration = expiration;
}

int64_t rice::p2p::past::gc::GCPastMetadata::getExpiration()
{
    return expiration;
}

rice::p2p::past::gc::GCPastMetadata* rice::p2p::past::gc::GCPastMetadata::setExpiration(int64_t expiration)
{
    return new GCPastMetadata(expiration);
}

bool rice::p2p::past::gc::GCPastMetadata::equals(::java::lang::Object* o)
{
    return npc((java_cast< GCPastMetadata* >(o)))->expiration == expiration;
}

int32_t rice::p2p::past::gc::GCPastMetadata::hashCode()
{
    return static_cast< int32_t >(expiration);
}

int32_t rice::p2p::past::gc::GCPastMetadata::compareTo(GCPastMetadata* other)
{
    auto metadata = java_cast< GCPastMetadata* >(other);
    if(npc(metadata)->expiration > expiration)
        return -int32_t(1);
    else if(npc(metadata)->expiration < expiration)
        return 1;
    else
        return 0;
}

int32_t rice::p2p::past::gc::GCPastMetadata::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< GCPastMetadata* >(o));
}

java::lang::String* rice::p2p::past::gc::GCPastMetadata::toString()
{
    return ::java::lang::StringBuilder().append(u"GCPMetadata "_j)->append(expiration)->toString();
}

void rice::p2p::past::gc::GCPastMetadata::readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */
{
    npc(ois)->defaultReadObject();
    if(expiration == 1096560000000LL)
        expiration = GCPastImpl::DEFAULT_EXPIRATION;

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastMetadata::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCPastMetadata", 31);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastMetadata::getClass0()
{
    return class_();
}

