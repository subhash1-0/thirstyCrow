// Generated from /pastry-2.1/src/rice/environment/random/simple/SimpleRandomSource.java
#include <rice/environment/random/simple/SimpleRandomSource.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/util/Random.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::random::simple::SimpleRandomSource::SimpleRandomSource(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::random::simple::SimpleRandomSource::SimpleRandomSource(int64_t seed, ::rice::environment::logging::LogManager* manager, ::java::lang::String* instance) 
    : SimpleRandomSource(*static_cast< ::default_init_tag* >(0))
{
    ctor(seed,manager,instance);
}

rice::environment::random::simple::SimpleRandomSource::SimpleRandomSource(int64_t seed, ::rice::environment::logging::LogManager* manager) 
    : SimpleRandomSource(*static_cast< ::default_init_tag* >(0))
{
    ctor(seed,manager);
}

rice::environment::random::simple::SimpleRandomSource::SimpleRandomSource(::rice::environment::logging::LogManager* manager) 
    : SimpleRandomSource(*static_cast< ::default_init_tag* >(0))
{
    ctor(manager);
}

rice::environment::random::simple::SimpleRandomSource::SimpleRandomSource(::rice::environment::logging::LogManager* manager, ::java::lang::String* instance) 
    : SimpleRandomSource(*static_cast< ::default_init_tag* >(0))
{
    ctor(manager,instance);
}

void rice::environment::random::simple::SimpleRandomSource::ctor(int64_t seed, ::rice::environment::logging::LogManager* manager, ::java::lang::String* instance)
{
    super::ctor();
    init_(seed, manager, instance);
}

void rice::environment::random::simple::SimpleRandomSource::ctor(int64_t seed, ::rice::environment::logging::LogManager* manager)
{
    ctor(seed, manager, nullptr);
}

void rice::environment::random::simple::SimpleRandomSource::ctor(::rice::environment::logging::LogManager* manager)
{
    ctor(manager, static_cast< ::java::lang::String* >(nullptr));
}

void rice::environment::random::simple::SimpleRandomSource::ctor(::rice::environment::logging::LogManager* manager, ::java::lang::String* instance)
{
    super::ctor();
    auto time = ::java::lang::System::currentTimeMillis();
    try {
        auto foo = npc(::java::net::InetAddress::getLocalHost())->getAddress();
        for (auto ctr = int32_t(0); ctr < npc(foo)->length; ctr++) {
            auto i = static_cast< int32_t >((*foo)[ctr]);
            i <<= (ctr * int32_t(8));
            time ^= i;
        }
    } catch (::java::lang::Exception* e) {
    }
    init_(time, manager, instance);
}

void rice::environment::random::simple::SimpleRandomSource::setLogManager(::rice::environment::logging::LogManager* manager)
{
    logger = npc(manager)->getLogger(SimpleRandomSource::class_(), instance);
}

void rice::environment::random::simple::SimpleRandomSource::init_(int64_t seed, ::rice::environment::logging::LogManager* manager, ::java::lang::String* instance)
{
    if(manager != nullptr)
        logger = npc(manager)->getLogger(SimpleRandomSource::class_(), instance);

    if(logger != nullptr)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"RNG seed = "_j)->append(seed)->toString());


    rnd = new ::java::util::Random(seed);
}

bool rice::environment::random::simple::SimpleRandomSource::nextBoolean()
{
    auto ret = npc(rnd)->nextBoolean();
    if(logger != nullptr)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"nextBoolean = "_j)->append(ret)->toString());


    return ret;
}

void rice::environment::random::simple::SimpleRandomSource::nextBytes(::int8_tArray* bytes)
{
    npc(rnd)->nextBytes(bytes);
    if(logger != nullptr)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"nextBytes["_j)->append(npc(bytes)->length)
                ->append(u"] = "_j)
                ->append(static_cast< ::java::lang::Object* >(bytes))->toString());


}

double rice::environment::random::simple::SimpleRandomSource::nextDouble()
{
    auto ret = npc(rnd)->nextDouble();
    if(logger != nullptr)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"nextDouble = "_j)->append(ret)->toString());


    return ret;
}

float rice::environment::random::simple::SimpleRandomSource::nextFloat()
{
    auto ret = npc(rnd)->nextFloat();
    if(logger != nullptr)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"nextFloat = "_j)->append(ret)->toString());


    return ret;
}

double rice::environment::random::simple::SimpleRandomSource::nextGaussian()
{
    auto ret = npc(rnd)->nextGaussian();
    if(logger != nullptr)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"nextGaussian = "_j)->append(ret)->toString());


    return ret;
}

int32_t rice::environment::random::simple::SimpleRandomSource::nextInt()
{
    auto ret = npc(rnd)->nextInt();
    if(logger != nullptr)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"nextInt = "_j)->append(ret)->toString());


    return ret;
}

int32_t rice::environment::random::simple::SimpleRandomSource::nextInt(int32_t max)
{
    auto ret = npc(rnd)->nextInt(max);
    if(logger != nullptr)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"nextInt2 = "_j)->append(ret)->toString());


    return ret;
}

int64_t rice::environment::random::simple::SimpleRandomSource::nextLong()
{
    auto ret = npc(rnd)->nextLong();
    if(logger != nullptr)
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"nextLong = "_j)->append(ret)->toString());


    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::random::simple::SimpleRandomSource::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.random.simple.SimpleRandomSource", 49);
    return c;
}

java::lang::Class* rice::environment::random::simple::SimpleRandomSource::getClass0()
{
    return class_();
}

