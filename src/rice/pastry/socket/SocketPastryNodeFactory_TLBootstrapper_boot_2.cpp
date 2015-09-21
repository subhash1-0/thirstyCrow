// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_2.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

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
rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_2::SocketPastryNodeFactory_TLBootstrapper_boot_2(SocketPastryNodeFactory_TLBootstrapper *SocketPastryNodeFactory_TLBootstrapper_this, ::java::util::Collection* bootHandles, ::java::util::Collection* tempBootHandles, ::rice::Continuation* beginPns)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_TLBootstrapper_this(SocketPastryNodeFactory_TLBootstrapper_this)
    , bootHandles(bootHandles)
    , tempBootHandles(tempBootHandles)
    , beginPns(beginPns)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_2::init()
{
    logger = npc(npc(npc(SocketPastryNodeFactory_TLBootstrapper_this->pn)->getEnvironment())->getLogManager())->getLogger(SocketPastryNodeFactory::class_(), nullptr);
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_2::livenessChanged(::rice::pastry::NodeHandle* i2, int32_t val, ::java::util::Map* options)
{
    auto i = java_cast< SocketNodeHandle* >(i2);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"livenessChanged("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(val)
            ->append(u")"_j)->toString());

    if(val <= LIVENESS_SUSPECTED && npc(i)->getEpoch() != -int64_t(1LL)) {
        auto complete = false;
        {
            synchronized synchronized_0(bootHandles);
            {
                npc(bootHandles)->add(java_cast< SocketNodeHandle* >(i));
                if(npc(bootHandles)->size() == npc(tempBootHandles)->size()) {
                    complete = true;
                }
            }
        }
        if(complete) {
            npc(beginPns)->receiveResult(bootHandles);
        }
    }
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_2::livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options)
{ 
    livenessChanged(dynamic_cast< ::rice::pastry::NodeHandle* >(i), val, options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_2::getClass0()
{
    return class_();
}

