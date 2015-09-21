// Generated from /pastry-2.1/src/rice/p2p/glacier/VersionKeyFactory.java
#include <rice/p2p/glacier/VersionKeyFactory.hpp>

#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/util/Random.hpp>
#include <java/util/StringTokenizer.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/VersionKeyRange.hpp>
#include <rice/p2p/glacier/VersionKeySet.hpp>
#include <rice/p2p/multiring/MultiringIdFactory.hpp>
#include <rice/p2p/multiring/RingId.hpp>
#include <rice/pastry/Id.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::VersionKeyFactory::VersionKeyFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::VersionKeyFactory::VersionKeyFactory(::rice::p2p::multiring::MultiringIdFactory* factory) 
    : VersionKeyFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory);
}

void rice::p2p::glacier::VersionKeyFactory::ctor(::rice::p2p::multiring::MultiringIdFactory* factory)
{
    super::ctor();
    FACTORY = factory;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKeyFactory::buildId(::int8_tArray* material)
{
    throw new ::java::lang::RuntimeException(u"VersionKeyFactory.buildId(byte[]) is not supported!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKeyFactory::buildId(::int32_tArray* material)
{
    throw new ::java::lang::RuntimeException(u"VersionKeyFactory.buildId(int[]) is not supported!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKeyFactory::buildId(::java::lang::String* string)
{
    throw new ::java::lang::RuntimeException(u"VersionKeyFactory.buildId(String) is not supported!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKeyFactory::buildRandomId(::java::util::Random* rng)
{
    return new VersionKey(npc(FACTORY)->buildRandomId(rng), npc(rng)->nextLong());
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKeyFactory::buildRandomId(::rice::environment::random::RandomSource* rng)
{
    return new VersionKey(npc(FACTORY)->buildRandomId(rng), npc(rng)->nextLong());
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKeyFactory::buildIdFromToString(::java::lang::String* string)
{
    auto stok = new ::java::util::StringTokenizer(string, u"(,)- :v#"_j);
    if(npc(stok)->countTokens() < 3) {
        return nullptr;
    }
    auto keyRingS = npc(stok)->nextToken();
    auto keyNodeS = npc(stok)->nextToken();
    auto versionS = npc(stok)->nextToken();
    auto key = npc(FACTORY)->buildRingId(static_cast< ::rice::p2p::commonapi::Id* >(::rice::pastry::Id::build(keyRingS)), static_cast< ::rice::p2p::commonapi::Id* >(::rice::pastry::Id::build(keyNodeS)));
    return new VersionKey(static_cast< ::rice::p2p::commonapi::Id* >(key), npc(::java::lang::Long::valueOf(versionS))->longValue());
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKeyFactory::buildIdFromToString(::char16_tArray* chars, int32_t offset, int32_t length)
{
    return buildIdFromToString(new ::java::lang::String(chars, offset, length));
}

rice::p2p::commonapi::Id_Distance* rice::p2p::glacier::VersionKeyFactory::buildIdDistance(::int8_tArray* material)
{
    throw new ::java::lang::RuntimeException(u"VersionKeyFactory.buildIdDistance() is not supported!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::VersionKeyFactory::buildIdRange(::rice::p2p::commonapi::Id* cw, ::rice::p2p::commonapi::Id* ccw)
{
    throw new ::java::lang::RuntimeException(u"VersionKeyFactory.buildIdRange() is not supported!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::glacier::VersionKeyFactory::buildIdRangeFromPrefix(::java::lang::String* string)
{
    return new VersionKeyRange(npc(FACTORY)->buildIdRangeFromPrefix(string));
}

rice::p2p::commonapi::IdSet* rice::p2p::glacier::VersionKeyFactory::buildIdSet()
{
    return new VersionKeySet();
}

rice::p2p::commonapi::IdSet* rice::p2p::glacier::VersionKeyFactory::buildIdSet(::java::util::SortedMap* map)
{
    return new VersionKeySet(map);
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::glacier::VersionKeyFactory::buildNodeHandleSet()
{
    throw new ::java::lang::RuntimeException(u"VersionKeyFactory.buildNodeHandleSet() is not supported!"_j);
}

int32_t rice::p2p::glacier::VersionKeyFactory::getIdToStringLength()
{
    return npc(FACTORY)->getIdToStringLength() + int32_t(13);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::VersionKeyFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.VersionKeyFactory", 34);
    return c;
}

java::lang::Class* rice::p2p::glacier::VersionKeyFactory::getClass0()
{
    return class_();
}

