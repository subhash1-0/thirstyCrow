// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/EphemeralDBImpl.java
#include <org/mpisws/p2p/transport/rendezvous/EphemeralDBImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/util/tuples/MutableTuple.hpp>

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

org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::EphemeralDBImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::EphemeralDBImpl(::rice::environment::Environment* env, int64_t stalePortTime) 
    : EphemeralDBImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,stalePortTime);
}

void org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::init()
{
    STALE_PORT_TIME = int32_t(2) * int32_t(60) * int32_t(60)* int32_t(1000);
    nextTag = NO_TAG + int32_t(1);
    highToTag = new ::java::util::HashMap();
    ephemeralToTag = new ::java::util::HashMap();
    tagToEphemeral = new ::java::util::HashMap();
}

void org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::ctor(::rice::environment::Environment* env, int64_t stalePortTime)
{
    super::ctor();
    init();
    time = npc(env)->getTimeSource();
    this->logger = npc(npc(env)->getLogManager())->getLogger(EphemeralDBImpl::class_(), nullptr);
    this->STALE_PORT_TIME = stalePortTime;
}

void org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::mapHighToTag(::java::lang::Object* high, int64_t tag)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"mapHighToTag("_j)->append(static_cast< ::java::lang::Object* >(high))
            ->append(u","_j)
            ->append(tag)
            ->append(u")"_j)->toString());

    npc(highToTag)->put(high, ::java::lang::Long::valueOf(tag));
}

java::lang::Object* org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::getEphemeral(::java::lang::Object* high)
{
    auto tag = java_cast< ::java::lang::Long* >(npc(highToTag)->get(high));
    if(tag == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"getEphemeral("_j)->append(static_cast< ::java::lang::Object* >(high))
                ->append(u"):null"_j)->toString());

        return nullptr;
    }
    auto ret = java_cast< ::java::lang::Object* >(getEphemeral((npc(tag))->longValue(), static_cast< ::java::lang::Object* >(nullptr)));
    if(ret == nullptr) {
        npc(highToTag)->remove(high);
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"getEphemeral("_j)->append(static_cast< ::java::lang::Object* >(high))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(ret))->toString());

    return ret;
}

java::lang::Object* org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::getEphemeral(int64_t tag, ::java::lang::Object* i)
{
    auto ret = java_cast< ::rice::p2p::util::tuples::MutableTuple* >(npc(tagToEphemeral)->get(::java::lang::Long::valueOf(tag)));
    if(ret == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"getEphemeral("_j)->append(tag)
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(i))
                ->append(u"):"_j)
                ->append(static_cast< ::java::lang::Object* >(i))->toString());

        return i;
    }
    if((npc(java_cast< ::java::lang::Long* >(npc(ret)->b())))->longValue() < npc(time)->currentTimeMillis() - STALE_PORT_TIME) {
        clear(tag);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"getEphemeral("_j)->append(tag)
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(i))
                ->append(u"):"_j)
                ->append(static_cast< ::java::lang::Object* >(i))->toString());

        return i;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"getEphemeral("_j)->append(tag)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(i))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(ret)->a())))->toString());

    return java_cast< ::java::lang::Object* >(npc(ret)->a());
}

int64_t org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::getTagForEphemeral(::java::lang::Object* addr)
{
    auto now = npc(time)->currentTimeMillis();
    auto tag = java_cast< ::java::lang::Long* >(npc(ephemeralToTag)->get(addr));
    if(tag == nullptr) {
    } else {
        auto ret = java_cast< ::rice::p2p::util::tuples::MutableTuple* >(npc(tagToEphemeral)->get(tag));
        if((npc(java_cast< ::java::lang::Long* >(npc(ret)->b())))->longValue() < now - STALE_PORT_TIME) {
            clear((npc(tag))->longValue());
        } else {
            npc(ret)->setB(::java::lang::Long::valueOf(now));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"getTagForEphemeral("_j)->append(static_cast< ::java::lang::Object* >(addr))
                    ->append(u"):"_j)
                    ->append(static_cast< ::java::lang::Object* >(tag))->toString());

            return (npc(tag))->longValue();
        }
    }
    tag = ::java::lang::Long::valueOf(nextTag++);
    auto ret = new ::rice::p2p::util::tuples::MutableTuple(addr, ::java::lang::Long::valueOf(now));
    npc(ephemeralToTag)->put(addr, tag);
    npc(tagToEphemeral)->put(tag, ret);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"getTagForEphemeral("_j)->append(static_cast< ::java::lang::Object* >(addr))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(tag))->toString());

    return (npc(tag))->longValue();
}

void org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::clear(int64_t tag)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"clear("_j)->append(tag)
            ->append(u")"_j)->toString());

    auto ret = java_cast< ::rice::p2p::util::tuples::MutableTuple* >(npc(tagToEphemeral)->remove(::java::lang::Long::valueOf(tag)));
    npc(ephemeralToTag)->remove(java_cast< ::java::lang::Object* >(npc(ret)->a()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.rendezvous.EphemeralDBImpl", 51);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl::getClass0()
{
    return class_();
}

