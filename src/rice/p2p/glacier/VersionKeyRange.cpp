// Generated from /pastry-2.1/src/rice/p2p/glacier/VersionKeyRange.java
#include <rice/p2p/glacier/VersionKeyRange.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>

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

rice::p2p::glacier::VersionKeyRange::VersionKeyRange(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::VersionKeyRange::VersionKeyRange(::rice::p2p::commonapi::IdRange* range) 
    : VersionKeyRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(range);
}

void rice::p2p::glacier::VersionKeyRange::ctor(::rice::p2p::commonapi::IdRange* range)
{
    super::ctor();
    this->range = range;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKeyRange::getCCWId()
{
    return new VersionKey(npc(range)->getCCWId(), int64_t(0LL));
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKeyRange::getCWId()
{
    return new VersionKey(npc(range)->getCWId(), int64_t(0LL));
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::VersionKeyRange::getComplementRange()
{
    throw new ::java::lang::RuntimeException(u"VersionKeyRange.getComplementRange() is not supported!"_j);
}

bool rice::p2p::glacier::VersionKeyRange::isEmpty()
{
    return npc(range)->isEmpty();
}

bool rice::p2p::glacier::VersionKeyRange::containsId(::rice::p2p::commonapi::Id* key)
{
    return npc(range)->containsId(npc((java_cast< VersionKey* >(key)))->id);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::VersionKeyRange::mergeRange(::rice::p2p::commonapi::IdRange* merge)
{
    throw new ::java::lang::RuntimeException(u"VersionKeyRange.mergeRange() is not supported!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::VersionKeyRange::diffRange(::rice::p2p::commonapi::IdRange* diff)
{
    throw new ::java::lang::RuntimeException(u"VersionKeyRange.diffRange() is not supported!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::VersionKeyRange::intersectRange(::rice::p2p::commonapi::IdRange* intersect)
{
    throw new ::java::lang::RuntimeException(u"VersionKeyRange.intersectRange() is not supported!"_j);
}

bool rice::p2p::glacier::VersionKeyRange::equals(::java::lang::Object* o)
{
    return npc(npc((java_cast< VersionKeyRange* >(o)))->range)->equals(range);
}

int32_t rice::p2p::glacier::VersionKeyRange::hashCode()
{
    return npc(range)->hashCode();
}

java::lang::String* rice::p2p::glacier::VersionKeyRange::toString()
{
    return ::java::lang::StringBuilder().append(u"[VKRange "_j)->append(static_cast< ::java::lang::Object* >(range))
        ->append(u"]"_j)->toString();
}

void rice::p2p::glacier::VersionKeyRange::VersionKeyRange_(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    range = npc(endpoint)->readIdRange(buf);
}

void rice::p2p::glacier::VersionKeyRange::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(range)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::VersionKeyRange::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.VersionKeyRange", 32);
    return c;
}

java::lang::Class* rice::p2p::glacier::VersionKeyRange::getClass0()
{
    return class_();
}

