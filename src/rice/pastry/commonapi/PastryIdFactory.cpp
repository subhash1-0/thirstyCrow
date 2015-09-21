// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryIdFactory.java
#include <rice/pastry/commonapi/PastryIdFactory.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/IdRange.hpp>
#include <rice/pastry/IdSet.hpp>
#include <rice/pastry/NodeSet.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::commonapi::PastryIdFactory::PastryIdFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::commonapi::PastryIdFactory::PastryIdFactory(::rice::environment::Environment* env) 
    : PastryIdFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::pastry::commonapi::PastryIdFactory::ctor(::rice::environment::Environment* env)
{
    super::ctor();
    try {
        md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
    } catch (::java::security::NoSuchAlgorithmException* e) {
        auto logger = npc(npc(env)->getLogManager())->getLogger(getClass(), nullptr);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->log(u"No SHA support!"_j);

    }
}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryIdFactory::buildId(::int8_tArray* material)
{
    return ::rice::pastry::Id::build(material);
}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryIdFactory::buildId(::int32_tArray* material)
{
    return ::rice::pastry::Id::build(material);
}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryIdFactory::buildId(::java::lang::String* string)
{
    {
        synchronized synchronized_0(md);
        {
            npc(md)->update(npc(string)->getBytes());
            return buildId(npc(md)->digest());
        }
    }
}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryIdFactory::buildRandomId(::java::util::Random* rng)
{
    return ::rice::pastry::Id::makeRandomId(rng);
}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryIdFactory::buildRandomId(::rice::environment::random::RandomSource* rng)
{
    return ::rice::pastry::Id::makeRandomId(rng);
}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryIdFactory::buildIdFromToString(::java::lang::String* string)
{
    return ::rice::pastry::Id::build(string);
}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryIdFactory::buildIdFromToString(::char16_tArray* chars, int32_t offset, int32_t length)
{
    return ::rice::pastry::Id::build(chars, offset, length);
}

rice::p2p::commonapi::IdRange* rice::pastry::commonapi::PastryIdFactory::buildIdRangeFromPrefix(::java::lang::String* string)
{
    auto start = ::rice::pastry::Id::build(string);
    auto end = ::rice::pastry::Id::build(::java::lang::StringBuilder().append(string)->append(u"ffffffffffffffffffffffffffffffffffffffff"_j)->toString());
    end = npc(end)->getCW();
    return new ::rice::pastry::IdRange(start, end);
}

int32_t rice::pastry::commonapi::PastryIdFactory::getIdToStringLength()
{
    return ::rice::pastry::Id::IdBitLength / int32_t(4);
}

rice::p2p::commonapi::Id_Distance* rice::pastry::commonapi::PastryIdFactory::buildIdDistance(::int8_tArray* material)
{
    return new ::rice::pastry::Id_Distance(material);
}

rice::p2p::commonapi::IdRange* rice::pastry::commonapi::PastryIdFactory::buildIdRange(::rice::p2p::commonapi::Id* cw, ::rice::p2p::commonapi::Id* ccw)
{
    return new ::rice::pastry::IdRange(java_cast< ::rice::pastry::Id* >(cw), java_cast< ::rice::pastry::Id* >(ccw));
}

rice::p2p::commonapi::IdSet* rice::pastry::commonapi::PastryIdFactory::buildIdSet()
{
    return new ::rice::pastry::IdSet();
}

rice::p2p::commonapi::IdSet* rice::pastry::commonapi::PastryIdFactory::buildIdSet(::java::util::SortedMap* map)
{
    return new ::rice::pastry::IdSet(map);
}

rice::p2p::commonapi::NodeHandleSet* rice::pastry::commonapi::PastryIdFactory::buildNodeHandleSet()
{
    return new ::rice::pastry::NodeSet();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::commonapi::PastryIdFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.commonapi.PastryIdFactory", 37);
    return c;
}

java::lang::Class* rice::pastry::commonapi::PastryIdFactory::getClass0()
{
    return class_();
}

