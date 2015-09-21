// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdFactory.java
#include <rice/p2p/multiring/MultiringIdFactory.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/multiring/MultiringIdFactory_MultiringSortedMap.hpp>
#include <rice/p2p/multiring/MultiringIdRange.hpp>
#include <rice/p2p/multiring/MultiringIdSet.hpp>
#include <rice/p2p/multiring/MultiringNodeHandleSet.hpp>
#include <rice/p2p/multiring/RingId.hpp>
#include <Array.hpp>

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

rice::p2p::multiring::MultiringIdFactory::MultiringIdFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringIdFactory::MultiringIdFactory(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdFactory* factory) 
    : MultiringIdFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,factory);
}

void rice::p2p::multiring::MultiringIdFactory::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdFactory* factory)
{
    super::ctor();
    this->ringId = ringId;
    this->factory = factory;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::getRingId()
{
    return ringId;
}

rice::p2p::multiring::RingId* rice::p2p::multiring::MultiringIdFactory::buildRingId(::rice::p2p::commonapi::Id* ringId, ::int8_tArray* material)
{
    return RingId::build(ringId, npc(factory)->buildId(material));
}

rice::p2p::multiring::RingId* rice::p2p::multiring::MultiringIdFactory::buildRingId(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Id* id)
{
    return RingId::build(ringId, id);
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::buildNormalId(::int8_tArray* material)
{
    return npc(factory)->buildId(material);
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::buildNormalId(::java::lang::String* material)
{
    return npc(factory)->buildId(material);
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::buildId(::int8_tArray* material)
{
    return RingId::build(getRingId(), npc(factory)->buildId(material));
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::buildId(::int32_tArray* material)
{
    return RingId::build(getRingId(), npc(factory)->buildId(material));
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::buildId(::java::lang::String* string)
{
    return RingId::build(getRingId(), npc(factory)->buildId(string));
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::buildRandomId(::java::util::Random* rng)
{
    return RingId::build(getRingId(), npc(factory)->buildRandomId(rng));
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::buildRandomId(::rice::environment::random::RandomSource* rng)
{
    return RingId::build(getRingId(), npc(factory)->buildRandomId(rng));
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::buildIdFromToString(::java::lang::String* string)
{
    string = npc(string)->substring(1);
    auto ring = npc(factory)->buildIdFromToString(npc(string)->substring(0, npc(string)->indexOf(u","_j)));
    string = npc(string)->substring(npc(string)->indexOf(u", "_j) + int32_t(2));
    auto normal = npc(factory)->buildIdFromToString(npc(string)->substring(0, npc(string)->length() - int32_t(1)));
    return RingId::build(ring, normal);
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdFactory::buildIdFromToString(::char16_tArray* chars, int32_t offset, int32_t length)
{
    auto ring = npc(factory)->buildIdFromToString(chars, 1, find(chars, u',') - int32_t(1));
    auto normal = npc(factory)->buildIdFromToString(chars, int32_t(2) + find(chars, u','), find(chars, u')') - (int32_t(2) + find(chars, u',')));
    return RingId::build(ring, normal);
}

int32_t rice::p2p::multiring::MultiringIdFactory::find(::char16_tArray* chars, char16_t value)
{
    clinit();
    for (auto i = int32_t(0); i < npc(chars)->length; i++) 
                if((*chars)[i] == value)
            return i;


    return npc(chars)->length;
}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringIdFactory::buildIdRangeFromPrefix(::java::lang::String* string)
{
    if(npc(string)->indexOf(u", "_j) < 0)
        return new MultiringIdRange(ringId, npc(factory)->buildIdRangeFromPrefix(string));

    string = npc(string)->substring(1);
    auto ring = npc(factory)->buildIdFromToString(npc(string)->substring(0, npc(string)->indexOf(u", "_j)));
    string = npc(string)->substring(npc(string)->indexOf(u", "_j) + int32_t(2));
    auto range = npc(factory)->buildIdRangeFromPrefix(string);
    return new MultiringIdRange(ring, range);
}

int32_t rice::p2p::multiring::MultiringIdFactory::getIdToStringLength()
{
    return int32_t(4) + (int32_t(2) * npc(factory)->getIdToStringLength());
}

rice::p2p::commonapi::Id_Distance* rice::p2p::multiring::MultiringIdFactory::buildIdDistance(::int8_tArray* material)
{
    return npc(factory)->buildIdDistance(material);
}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringIdFactory::buildIdRange(::rice::p2p::commonapi::Id* cw, ::rice::p2p::commonapi::Id* ccw)
{
    return new MultiringIdRange(getRingId(), npc(factory)->buildIdRange(npc((java_cast< RingId* >(cw)))->getId(), npc((java_cast< RingId* >(ccw)))->getId()));
}

rice::p2p::commonapi::IdSet* rice::p2p::multiring::MultiringIdFactory::buildIdSet()
{
    return new MultiringIdSet(getRingId(), npc(factory)->buildIdSet());
}

rice::p2p::commonapi::IdSet* rice::p2p::multiring::MultiringIdFactory::buildIdSet(::java::util::SortedMap* map)
{
    return new MultiringIdSet(getRingId(), npc(factory)->buildIdSet(new MultiringIdFactory_MultiringSortedMap(this, map)));
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::multiring::MultiringIdFactory::buildNodeHandleSet()
{
    return new MultiringNodeHandleSet(getRingId(), npc(factory)->buildNodeHandleSet());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringIdFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringIdFactory", 37);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringIdFactory::getClass0()
{
    return class_();
}

