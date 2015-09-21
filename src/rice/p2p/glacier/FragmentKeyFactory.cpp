// Generated from /pastry-2.1/src/rice/p2p/glacier/FragmentKeyFactory.java
#include <rice/p2p/glacier/FragmentKeyFactory.hpp>

#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/util/Random.hpp>
#include <java/util/StringTokenizer.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/FragmentKeyRange.hpp>
#include <rice/p2p/glacier/FragmentKeySet.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/multiring/MultiringIdFactory.hpp>
#include <rice/p2p/multiring/RingId.hpp>
#include <rice/pastry/Id.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::FragmentKeyFactory::FragmentKeyFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::FragmentKeyFactory::FragmentKeyFactory(::rice::p2p::multiring::MultiringIdFactory* factory) 
    : FragmentKeyFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory);
}

void rice::p2p::glacier::FragmentKeyFactory::ctor(::rice::p2p::multiring::MultiringIdFactory* factory)
{
    super::ctor();
    FACTORY = factory;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKeyFactory::buildId(::int8_tArray* material)
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyFactory.buildId(byte[]) is not supported!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKeyFactory::buildId(::int32_tArray* material)
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyFactory.buildId(byte[]) is not supported!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKeyFactory::buildId(::java::lang::String* string)
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyFactory.buildId(String) is not supported!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKeyFactory::buildRandomId(::java::util::Random* rng)
{
    return new FragmentKey(new VersionKey(npc(FACTORY)->buildRandomId(rng), npc(rng)->nextLong()), npc(rng)->nextInt());
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKeyFactory::buildRandomId(::rice::environment::random::RandomSource* rng)
{
    return new FragmentKey(new VersionKey(npc(FACTORY)->buildRandomId(rng), npc(rng)->nextLong()), npc(rng)->nextInt());
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKeyFactory::buildIdFromToString(::java::lang::String* string)
{
    auto stok = new ::java::util::StringTokenizer(string, u"(,) :v#"_j);
    if(npc(stok)->countTokens() < 4) {
        return nullptr;
    }
    auto keyRingS = npc(stok)->nextToken();
    auto keyNodeS = npc(stok)->nextToken();
    auto versionS = npc(stok)->nextToken();
    auto fragmentIdS = npc(stok)->nextToken();
    auto key = npc(FACTORY)->buildRingId(static_cast< ::rice::p2p::commonapi::Id* >(::rice::pastry::Id::build(keyRingS)), static_cast< ::rice::p2p::commonapi::Id* >(::rice::pastry::Id::build(keyNodeS)));
    return new FragmentKey(new VersionKey(static_cast< ::rice::p2p::commonapi::Id* >(key), npc(::java::lang::Long::valueOf(versionS))->longValue()), npc(::java::lang::Integer::valueOf(fragmentIdS))->intValue());
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKeyFactory::buildIdFromToString(::char16_tArray* chars, int32_t offset, int32_t length)
{
    return buildIdFromToString(new ::java::lang::String(chars, offset, length));
}

rice::p2p::commonapi::Id_Distance* rice::p2p::glacier::FragmentKeyFactory::buildIdDistance(::int8_tArray* material)
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyFactory.buildIdDistance() is not supported!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::FragmentKeyFactory::buildIdRange(::rice::p2p::commonapi::Id* cw, ::rice::p2p::commonapi::Id* ccw)
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyFactory.buildIdRange() is not supported!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::FragmentKeyFactory::buildIdRangeFromPrefix(::java::lang::String* string)
{
    return new FragmentKeyRange(npc(FACTORY)->buildIdRangeFromPrefix(string));
}

rice::p2p::commonapi::IdSet* rice::p2p::glacier::FragmentKeyFactory::buildIdSet()
{
    return new FragmentKeySet();
}

rice::p2p::commonapi::IdSet* rice::p2p::glacier::FragmentKeyFactory::buildIdSet(::java::util::SortedMap* map)
{
    return new FragmentKeySet(map);
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::glacier::FragmentKeyFactory::buildNodeHandleSet()
{
    throw new ::java::lang::RuntimeException(u"FragmentKeyFactory.buildNodeHandleSet() is not supported!"_j);
}

int32_t rice::p2p::glacier::FragmentKeyFactory::getIdToStringLength()
{
    return npc(FACTORY)->getIdToStringLength() + int32_t(4);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::FragmentKeyFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.FragmentKeyFactory", 35);
    return c;
}

java::lang::Class* rice::p2p::glacier::FragmentKeyFactory::getClass0()
{
    return class_();
}

