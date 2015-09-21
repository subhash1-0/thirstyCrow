// Generated from /pastry-2.1/src/rice/pastry/direct/NetworkSimulatorImpl.java
#include <rice/pastry/direct/NetworkSimulatorImpl.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/pastry/direct/BasicNetworkSimulator.hpp>
#include <rice/pastry/direct/GenericSimulatorListener.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>
#include <rice/pastry/direct/ProximityGenerator.hpp>
#include <rice/pastry/direct/TestRecord.hpp>

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
rice::pastry::direct::NetworkSimulatorImpl::NetworkSimulatorImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::NetworkSimulatorImpl::NetworkSimulatorImpl(::rice::environment::Environment* env, ProximityGenerator* generator) 
    : NetworkSimulatorImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,generator);
}

void rice::pastry::direct::NetworkSimulatorImpl::init()
{
    listeners = new ::java::util::ArrayList();
}

void rice::pastry::direct::NetworkSimulatorImpl::ctor(::rice::environment::Environment* env, ProximityGenerator* generator)
{
    super::ctor();
    init();
    auto params = npc(env)->getParameters();
    if(npc(params)->contains(u"pastry_direct_use_own_random"_j) && npc(params)->getBoolean(u"pastry_direct_use_own_random"_j)) {
        if(npc(params)->contains(u"pastry_direct_random_seed"_j) && !npc(npc(params)->getString(u"pastry_direct_random_seed"_j))->equalsIgnoreCase(u"clock"_j)) {
            this->random = new ::rice::environment::random::simple::SimpleRandomSource(npc(params)->getLong(u"pastry_direct_random_seed"_j), npc(env)->getLogManager(), u"direct"_j);
        } else {
            this->random = new ::rice::environment::random::simple::SimpleRandomSource(npc(env)->getLogManager(), u"direct"_j);
        }
    } else {
        this->random = npc(env)->getRandomSource();
    }
    npc(generator)->setRandom(random);
    this->generator = generator;
    simulator = new BasicNetworkSimulator(env, random, this);
    livenessProvider = simulator;
}

rice::environment::Environment* rice::pastry::direct::NetworkSimulatorImpl::getEnvironment()
{
    return npc(simulator)->getEnvironment();
}

void rice::pastry::direct::NetworkSimulatorImpl::setFullSpeed()
{
    npc(simulator)->setFullSpeed();
}

void rice::pastry::direct::NetworkSimulatorImpl::setMaxSpeed(float rate)
{
    npc(simulator)->setMaxSpeed(rate);
}

void rice::pastry::direct::NetworkSimulatorImpl::start()
{
    npc(simulator)->start();
}

void rice::pastry::direct::NetworkSimulatorImpl::stop()
{
    npc(simulator)->stop();
}

rice::pastry::direct::TestRecord* rice::pastry::direct::NetworkSimulatorImpl::getTestRecord()
{
    return testRecord;
}

void rice::pastry::direct::NetworkSimulatorImpl::setTestRecord(TestRecord* tr)
{
    testRecord = tr;
}

bool rice::pastry::direct::NetworkSimulatorImpl::addSimulatorListener(GenericSimulatorListener* sl)
{
    {
        synchronized synchronized_0(listeners);
        {
            if(npc(listeners)->contains(static_cast< ::java::lang::Object* >(sl)))
                return false;

            npc(listeners)->add(static_cast< ::java::lang::Object* >(sl));
            return true;
        }
    }
}

bool rice::pastry::direct::NetworkSimulatorImpl::removeSimulatorListener(GenericSimulatorListener* sl)
{
    {
        synchronized synchronized_1(listeners);
        {
            return npc(listeners)->remove(static_cast< ::java::lang::Object* >(sl));
        }
    }
}

void rice::pastry::direct::NetworkSimulatorImpl::notifySimulatorListenersSent(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to, int32_t delay)
{
    ::java::util::List* temp;
    {
        synchronized synchronized_2(listeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        GenericSimulatorListener* listener = java_cast< GenericSimulatorListener* >(_i->next());
        {
            npc(listener)->messageSent(m, from, to, delay);
        }
    }
}

void rice::pastry::direct::NetworkSimulatorImpl::notifySimulatorListenersReceived(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to)
{
    ::java::util::List* temp;
    {
        synchronized synchronized_3(listeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        GenericSimulatorListener* listener = java_cast< GenericSimulatorListener* >(_i->next());
        {
            npc(listener)->messageReceived(m, from, to);
        }
    }
}

void rice::pastry::direct::NetworkSimulatorImpl::destroy(DirectPastryNode* dpn)
{
}

rice::p2p::commonapi::CancellableTask* rice::pastry::direct::NetworkSimulatorImpl::enqueueDelivery(::org::mpisws::p2p::transport::direct::Delivery* del, int32_t delay)
{
    return nullptr;
}

rice::pastry::direct::NodeRecord* rice::pastry::direct::NetworkSimulatorImpl::generateNodeRecord()
{
    return npc(generator)->generateNodeRecord();
}

rice::pastry::direct::DirectNodeHandle* rice::pastry::direct::NetworkSimulatorImpl::getClosest(DirectNodeHandle* nh)
{
    return nullptr;
}

bool rice::pastry::direct::NetworkSimulatorImpl::isAlive(::java::lang::Object* nh)
{
    return npc(simulator)->isAlive(static_cast< ::java::lang::Object* >(nh));
}

float rice::pastry::direct::NetworkSimulatorImpl::networkDelay(::java::lang::Object* a, ::java::lang::Object* b)
{
    return npc(simulator)->networkDelay(static_cast< ::java::lang::Object* >(a), static_cast< ::java::lang::Object* >(b));
}

float rice::pastry::direct::NetworkSimulatorImpl::proximity(::java::lang::Object* a, ::java::lang::Object* b)
{
    return npc(simulator)->proximity(a, b);
}

void rice::pastry::direct::NetworkSimulatorImpl::removeNode(::rice::pastry::PastryNode* node)
{
}

rice::pastry::direct::NodeRecord* rice::pastry::direct::NetworkSimulatorImpl::getNodeRecord(DirectNodeHandle* handle)
{
    return npc(simulator)->getNodeRecord(handle);
}

org::mpisws::p2p::transport::liveness::LivenessProvider* rice::pastry::direct::NetworkSimulatorImpl::getLivenessProvider()
{
    return livenessProvider;
}

org::mpisws::p2p::transport::direct::GenericNetworkSimulator* rice::pastry::direct::NetworkSimulatorImpl::getGenericSimulator()
{
    return simulator;
}

void rice::pastry::direct::NetworkSimulatorImpl::registerNode(::java::lang::Object* i, ::org::mpisws::p2p::transport::direct::DirectTransportLayer* dtl, NodeRecord* nr)
{
    npc(simulator)->registerIdentifier(i, dtl, nr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::NetworkSimulatorImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.NetworkSimulatorImpl", 39);
    return c;
}

java::lang::Class* rice::pastry::direct::NetworkSimulatorImpl::getClass0()
{
    return class_();
}

