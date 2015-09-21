// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdFactory.java
#include <rice/p2p/past/gc/GCIdFactory.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/past/gc/GCIdRange.hpp>
#include <rice/p2p/past/gc/GCIdSet.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCIdFactory::GCIdFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::GCIdFactory::GCIdFactory(::rice::p2p::commonapi::IdFactory* factory) 
    : GCIdFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory);
}

void rice::p2p::past::gc::GCIdFactory::ctor(::rice::p2p::commonapi::IdFactory* factory)
{
    super::ctor();
    this->factory = factory;
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdFactory::buildNormalId(::int8_tArray* material)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdFactory::buildId(::int8_tArray* material)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdFactory::buildId(::int32_tArray* material)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdFactory::buildId(::java::lang::String* string)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdFactory::buildRandomId(::java::util::Random* rng)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdFactory::buildRandomId(::rice::environment::random::RandomSource* rng)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdFactory::buildIdFromToString(::java::lang::String* string)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdFactory::buildIdFromToString(::char16_tArray* chars, int32_t offset, int32_t length)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCIdFactory::buildIdRangeFromPrefix(::java::lang::String* string)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

int32_t rice::p2p::past::gc::GCIdFactory::getIdToStringLength()
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build Ids!"_j);
}

rice::p2p::commonapi::Id_Distance* rice::p2p::past::gc::GCIdFactory::buildIdDistance(::int8_tArray* material)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build IdDistances!"_j);
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCIdFactory::buildIdRange(::rice::p2p::commonapi::Id* cw, ::rice::p2p::commonapi::Id* ccw)
{
    return new GCIdRange(npc(factory)->buildIdRange(cw, ccw));
}

rice::p2p::commonapi::IdSet* rice::p2p::past::gc::GCIdFactory::buildIdSet()
{
    return new GCIdSet(factory);
}

rice::p2p::commonapi::IdSet* rice::p2p::past::gc::GCIdFactory::buildIdSet(::java::util::SortedMap* map)
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory.buildIDSet()"_j);
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::past::gc::GCIdFactory::buildNodeHandleSet()
{
    throw new ::java::lang::UnsupportedOperationException(u"GCIdFactory cannot be used to build NodeHandleSets!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCIdFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCIdFactory", 28);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCIdFactory::getClass0()
{
    return class_();
}

