// Generated from /pastry-2.1/src/rice/pastry/direct/BasicNetworkSimulator.java
#include <rice/pastry/direct/BasicNetworkSimulator.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/direct/Delivery.hpp>
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/pastry/direct/BasicNetworkSimulator_Tupel.hpp>
#include <rice/pastry/direct/DeliveryTimerTask.hpp>
#include <rice/pastry/direct/DirectNodeHandle.hpp>
#include <rice/pastry/direct/DirectTimerTask.hpp>
#include <rice/pastry/direct/MessageDelivery.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
#include <rice/selector/TimerTask.hpp>

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
rice::pastry::direct::BasicNetworkSimulator::BasicNetworkSimulator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::BasicNetworkSimulator::BasicNetworkSimulator(::rice::environment::Environment* env, ::rice::environment::random::RandomSource* random, NetworkSimulator* sim) 
    : BasicNetworkSimulator(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,random,sim);
}

void rice::pastry::direct::BasicNetworkSimulator::init()
{
    nodes = ::java::util::Collections::synchronizedMap(new ::java::util::HashMap());
    MIN_DELAY = int32_t(1);
    livenessListeners = new ::java::util::ArrayList();
}

void rice::pastry::direct::BasicNetworkSimulator::ctor(::rice::environment::Environment* env, ::rice::environment::random::RandomSource* random, NetworkSimulator* sim)
{
    super::ctor(env, random, npc(npc(env)->getLogManager())->getLogger(BasicNetworkSimulator::class_(), nullptr));
    init();
    this->sim = sim;
    npc(manager)->useLoopListeners(false);
    auto params = npc(env)->getParameters();
    maxDiameter = npc(params)->getInt(u"pastry_direct_max_diameter"_j);
    minDelay = npc(params)->getInt(u"pastry_direct_min_delay"_j);
    start();
}

void rice::pastry::direct::BasicNetworkSimulator::addTask(::rice::selector::TimerTask* dtt)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"addTask("_j)->append(static_cast< ::java::lang::Object* >(dtt))
            ->append(u")"_j)->toString());

    npc(npc(manager)->getTimer())->schedule(dtt);
}

rice::p2p::commonapi::CancellableTask* rice::pastry::direct::BasicNetworkSimulator::enqueueDelivery(::org::mpisws::p2p::transport::direct::Delivery* d, int32_t delay)
{
    auto time = npc(timeSource)->currentTimeMillis() + delay;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"BNS: enqueueDelivery "_j)->append(static_cast< ::java::lang::Object* >(d))
            ->append(u":"_j)
            ->append(time)->toString());

    DeliveryTimerTask* dtt = nullptr;
    dtt = new DeliveryTimerTask(d, time, npc(d)->getSeq());
    addTask(dtt);
    return dtt;
}

rice::p2p::commonapi::Cancellable* rice::pastry::direct::BasicNetworkSimulator::deliverMessage(::java::lang::Object* msg, ::java::lang::Object* node, ::java::lang::Object* from)
{
    return deliverMessage(msg, node, from, int32_t(0));
}

rice::p2p::commonapi::Cancellable* rice::pastry::direct::BasicNetworkSimulator::deliverMessage(::java::lang::Object* msg, ::java::lang::Object* node, ::java::lang::Object* from, int32_t delay)
{
    if(delay > 0) {
        npc(sim)->notifySimulatorListenersSent(msg, from, node, delay);
    }
    return deliverMessage(msg, node, from, delay, 0);
}

void rice::pastry::direct::BasicNetworkSimulator::notifySimulatorListenersReceived(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to)
{
    npc(sim)->notifySimulatorListenersReceived(m, from, to);
}

rice::p2p::commonapi::Cancellable* rice::pastry::direct::BasicNetworkSimulator::deliverMessageFixedRate(::java::lang::Object* msg, ::java::lang::Object* node, ::java::lang::Object* from, int32_t delay, int32_t period)
{
    return deliverMessage(msg, node, from, delay, period);
}

rice::p2p::commonapi::Cancellable* rice::pastry::direct::BasicNetworkSimulator::deliverMessage(::java::lang::Object* msg, ::java::lang::Object* node, ::java::lang::Object* from, int32_t delay, int32_t period)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"BNS: deliver "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(node))->toString());

    DirectTimerTask* dtt = nullptr;
    if(from == nullptr || isAlive(from)) {
        auto md = new MessageDelivery(msg, node, from, nullptr, this);
        dtt = new DirectTimerTask(md, npc(timeSource)->currentTimeMillis() + delay, period);
        addTask(dtt);
    }
    return dtt;
}

void rice::pastry::direct::BasicNetworkSimulator::registerIdentifier(::java::lang::Object* i, ::org::mpisws::p2p::transport::direct::DirectTransportLayer* dtl, NodeRecord* record)
{
    npc(nodes)->put(i, new BasicNetworkSimulator_Tupel(this, i, dtl, record));
}

void rice::pastry::direct::BasicNetworkSimulator::remove(::java::lang::Object* i)
{
    if(!npc(npc(environment)->getSelectorManager())->isSelectorThread())
        throw new ::java::lang::IllegalStateException(u"Operation not permitted on non-selector thread."_j);

    npc(nodes)->remove(i);
    notifyLivenessListeners(i, ::org::mpisws::p2p::transport::liveness::LivenessListener::LIVENESS_DEAD, nullptr);
}

rice::environment::Environment* rice::pastry::direct::BasicNetworkSimulator::getEnvironment()
{
    return environment;
}

rice::environment::Environment* rice::pastry::direct::BasicNetworkSimulator::getEnvironment(::java::lang::Object* i)
{
    return npc(java_cast< ::org::mpisws::p2p::transport::direct::DirectTransportLayer* >(npc(java_cast< BasicNetworkSimulator_Tupel* >(npc(nodes)->get(i)))->tl))->getEnvironment();
}

rice::environment::random::RandomSource* rice::pastry::direct::BasicNetworkSimulator::getRandomSource()
{
    return random;
}

bool rice::pastry::direct::BasicNetworkSimulator::isAlive(::java::lang::Object* i)
{
    return npc(nodes)->containsKey(i);
}

org::mpisws::p2p::transport::direct::DirectTransportLayer* rice::pastry::direct::BasicNetworkSimulator::getTL(::java::lang::Object* i)
{
    auto t = java_cast< BasicNetworkSimulator_Tupel* >(npc(nodes)->get(i));
    if(t == nullptr)
        return nullptr;

    return npc(t)->tl;
}

float rice::pastry::direct::BasicNetworkSimulator::networkDelay(::java::lang::Object* a, ::java::lang::Object* b)
{
    auto ta = java_cast< BasicNetworkSimulator_Tupel* >(npc(nodes)->get(a));
    auto tb = java_cast< BasicNetworkSimulator_Tupel* >(npc(nodes)->get(b));
    if(ta == nullptr) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"asking about node proximity for unknown node "_j)->append(static_cast< ::java::lang::Object* >(a))->toString());
    }
    if(tb == nullptr) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"asking about node proximity for unknown node "_j)->append(static_cast< ::java::lang::Object* >(b))->toString());
    }
    auto nra = npc(ta)->record;
    auto nrb = npc(tb)->record;
    return npc(nra)->networkDelay(nrb);
}

float rice::pastry::direct::BasicNetworkSimulator::proximity(::java::lang::Object* a, ::java::lang::Object* b)
{
    auto ta = java_cast< BasicNetworkSimulator_Tupel* >(npc(nodes)->get(a));
    auto tb = java_cast< BasicNetworkSimulator_Tupel* >(npc(nodes)->get(b));
    if(ta == nullptr) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"asking about node proximity for unknown node "_j)->append(static_cast< ::java::lang::Object* >(a))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(b))->toString());
    }
    if(tb == nullptr) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"asking about node proximity for unknown node "_j)->append(static_cast< ::java::lang::Object* >(b))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(a))->toString());
    }
    auto nra = npc(ta)->record;
    auto nrb = npc(tb)->record;
    return npc(nra)->proximity(nrb);
}

rice::pastry::direct::NodeRecord* rice::pastry::direct::BasicNetworkSimulator::getNodeRecord(DirectNodeHandle* handle)
{
    auto t = java_cast< BasicNetworkSimulator_Tupel* >(npc(nodes)->get(handle));
    if(t == nullptr)
        return nullptr;

    return npc(t)->record;
}

void rice::pastry::direct::BasicNetworkSimulator::addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    {
        synchronized synchronized_0(livenessListeners);
        {
            npc(livenessListeners)->add(static_cast< ::java::lang::Object* >(name));
        }
    }
}

bool rice::pastry::direct::BasicNetworkSimulator::removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    {
        synchronized synchronized_1(livenessListeners);
        {
            return npc(livenessListeners)->remove(static_cast< ::java::lang::Object* >(name));
        }
    }
}

void rice::pastry::direct::BasicNetworkSimulator::notifyLivenessListeners(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyLivenessListeners("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(liveness)
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::org::mpisws::p2p::transport::liveness::LivenessListener* >(npc(livenessListeners)->get(0))))->toString());

    ::java::util::List* temp;
    {
        synchronized synchronized_2(livenessListeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(livenessListeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::liveness::LivenessListener* listener = java_cast< ::org::mpisws::p2p::transport::liveness::LivenessListener* >(_i->next());
        {
            npc(listener)->livenessChanged(i, liveness, options);
        }
    }
}

bool rice::pastry::direct::BasicNetworkSimulator::checkLiveness(::java::lang::Object* i, ::java::util::Map* options)
{
    return false;
}

int32_t rice::pastry::direct::BasicNetworkSimulator::getLiveness(::java::lang::Object* i, ::java::util::Map* options)
{
    if(npc(nodes)->containsKey(i)) {
        return ::org::mpisws::p2p::transport::liveness::LivenessListener::LIVENESS_ALIVE;
    }
    return ::org::mpisws::p2p::transport::liveness::LivenessListener::LIVENESS_DEAD;
}

void rice::pastry::direct::BasicNetworkSimulator::clearState(::java::lang::Object* i)
{
    throw new ::java::lang::IllegalStateException(u"not implemented"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::BasicNetworkSimulator::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.BasicNetworkSimulator", 40);
    return c;
}

void rice::pastry::direct::BasicNetworkSimulator::setFullSpeed()
{
    EventSimulator::setFullSpeed();
}

void rice::pastry::direct::BasicNetworkSimulator::setMaxSpeed(float rate)
{
    EventSimulator::setMaxSpeed(rate);
}

void rice::pastry::direct::BasicNetworkSimulator::start()
{
    EventSimulator::start();
}

void rice::pastry::direct::BasicNetworkSimulator::stop()
{
    EventSimulator::stop();
}

java::lang::Class* rice::pastry::direct::BasicNetworkSimulator::getClass0()
{
    return class_();
}

