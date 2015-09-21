// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/proximity/MinRTTProximityProvider.java
#include <org/mpisws/p2p/transport/proximity/MinRTTProximityProvider.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/liveness/Pinger.hpp>
#include <org/mpisws/p2p/transport/proximity/MinRTTProximityProvider_EntityManager.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>

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
org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::MinRTTProximityProvider(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::MinRTTProximityProvider(::org::mpisws::p2p::transport::liveness::Pinger* tl, ::rice::environment::Environment* env) 
    : MinRTTProximityProvider(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,env);
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::init()
{
    pingThrottle = int32_t(5000);
    listeners = new ::java::util::ArrayList();
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::ctor(::org::mpisws::p2p::transport::liveness::Pinger* tl, ::rice::environment::Environment* env)
{
    super::ctor();
    init();
    this->tl = tl;
    this->logger = npc(npc(env)->getLogManager())->getLogger(MinRTTProximityProvider::class_(), nullptr);
    this->time = npc(env)->getTimeSource();
    npc(tl)->addPingListener(this);
    this->managers = new ::java::util::HashMap();
}

int32_t org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::proximity(::java::lang::Object* i, ::java::util::Map* options)
{
    auto manager = getManager(i);
    auto ret = npc(manager)->proximity_;
    if(ret == DEFAULT_PROXIMITY) {
        npc(manager)->ping(options);
    }
    return ret;
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::pingResponse(::java::lang::Object* i, int32_t rtt, ::java::util::Map* options)
{
    npc(getManager(i))->markProximity(rtt, options);
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::pingReceived(::java::lang::Object* i, ::java::util::Map* options)
{
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::clearState(::java::lang::Object* i)
{
    {
        synchronized synchronized_0(managers);
        {
            npc(managers)->remove(i);
        }
    }
}

org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager* org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::getManager(::java::lang::Object* i)
{
    {
        synchronized synchronized_1(managers);
        {
            auto manager = java_cast< MinRTTProximityProvider_EntityManager* >(npc(managers)->get(i));
            if(manager == nullptr) {
                manager = new MinRTTProximityProvider_EntityManager(this, i);
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Creating EM for "_j)->append(static_cast< ::java::lang::Object* >(i))->toString());

                npc(managers)->put(i, manager);
            }
            return manager;
        }
    }
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::addProximityListener(ProximityListener* listener)
{
    {
        synchronized synchronized_2(listeners);
        {
            npc(listeners)->add(listener);
        }
    }
}

bool org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::removeProximityListener(ProximityListener* listener)
{
    {
        synchronized synchronized_3(listeners);
        {
            return npc(listeners)->remove(listener);
        }
    }
}

void org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::notifyProximityListeners(::java::lang::Object* i, int32_t prox, ::java::util::Map* options)
{
    ::java::util::Collection* temp;
    {
        synchronized synchronized_4(listeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ProximityListener* p = java_cast< ProximityListener* >(_i->next());
        {
            npc(p)->proximityChanged(i, prox, options);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.proximity.MinRTTProximityProvider", 58);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::proximity::MinRTTProximityProvider::getClass0()
{
    return class_();
}

