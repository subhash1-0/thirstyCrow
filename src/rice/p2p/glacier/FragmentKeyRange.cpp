// Generated from /pastry-2.1/src/rice/p2p/glacier/FragmentKeyRange.java
#include <rice/p2p/glacier/FragmentKeyRange.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
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

rice::p2p::glacier::FragmentKeyRange::FragmentKeyRange(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::FragmentKeyRange::FragmentKeyRange(::rice::p2p::commonapi::IdRange* range) 
    : FragmentKeyRange(*static_cast< ::default_init_tag* >(0))
{
    ctor(range);
}

void rice::p2p::glacier::FragmentKeyRange::ctor(::rice::p2p::commonapi::IdRange* range)
{
    super::ctor();
    this->range = range;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKeyRange::getCCWId()
{
    return new FragmentKey(new VersionKey(npc(range)->getCCWId(), int64_t(0LL)), int32_t(0));
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKeyRange::getCWId()
{
    return new FragmentKey(new VersionKey(npc(range)->getCWId(), int64_t(0LL)), int32_t(0));
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::FragmentKeyRange::getComplementRange()
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyRange.getComplementRange() is not supported!"_j);
}

bool rice::p2p::glacier::FragmentKeyRange::isEmpty()
{
    return npc(range)->isEmpty();
}

bool rice::p2p::glacier::FragmentKeyRange::containsId(::rice::p2p::commonapi::Id* key)
{
    return npc(range)->containsId(npc(npc((java_cast< FragmentKey* >(key)))->key)->id);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::FragmentKeyRange::mergeRange(::rice::p2p::commonapi::IdRange* merge)
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyRange.mergeRange() is not supported!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::FragmentKeyRange::diffRange(::rice::p2p::commonapi::IdRange* diff)
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyRange.diffRange() is not supported!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::FragmentKeyRange::intersectRange(::rice::p2p::commonapi::IdRange* intersect)
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyRange.intersectRange() is not supported!"_j);
}

bool rice::p2p::glacier::FragmentKeyRange::equals(::java::lang::Object* o)
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyRange.equals() is not supported!"_j);
}

int32_t rice::p2p::glacier::FragmentKeyRange::hashCode()
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyRange.hashCode() is not supported!"_j);
}

java::lang::String* rice::p2p::glacier::FragmentKeyRange::toString()
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyRange.toString() is not supported!"_j);
}

void rice::p2p::glacier::FragmentKeyRange::FragmentKeyRange_(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    range = npc(endpoint)->readIdRange(buf);
}

void rice::p2p::glacier::FragmentKeyRange::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(range)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::FragmentKeyRange::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.FragmentKeyRange", 33);
    return c;
}

java::lang::Class* rice::p2p::glacier::FragmentKeyRange::getClass0()
{
    return class_();
}

