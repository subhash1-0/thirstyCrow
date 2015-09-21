// Generated from /pastry-2.1/src/rice/p2p/commonapi/testing/CommonAPITest.java
#include <rice/p2p/commonapi/testing/CommonAPITest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/lang/Throwable.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/UnknownHostException.hpp>
#include <java/util/Arrays.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/params/simple/SimpleParameters.hpp>
#include <rice/environment/processing/sim/SimProcessor.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/environment/time/simple/SimpleTimeSource.hpp>
#include <rice/environment/time/simulated/DirectTimeSource.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/EuclideanNetwork.hpp>
#include <rice/pastry/direct/GenericNetwork.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/direct/SphereNetwork.hpp>
#include <rice/pastry/dist/DistPastryNodeFactory.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Node, ::java::lang::ObjectArray > NodeArray;
        } // commonapi
    } // p2p
} // rice

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
rice::p2p::commonapi::testing::CommonAPITest::CommonAPITest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::commonapi::testing::CommonAPITest::CommonAPITest(::rice::environment::Environment* env)  /* throws(IOException) */
    : CommonAPITest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

java::lang::String*& rice::p2p::commonapi::testing::CommonAPITest::SUCCESS()
{
    clinit();
    return SUCCESS_;
}
java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::SUCCESS_;

java::lang::String*& rice::p2p::commonapi::testing::CommonAPITest::FAILURE()
{
    clinit();
    return FAILURE_;
}
java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::FAILURE_;

constexpr int32_t rice::p2p::commonapi::testing::CommonAPITest::PAD_SIZE;

java::lang::String*& rice::p2p::commonapi::testing::CommonAPITest::PROTOCOL_DIRECT()
{
    clinit();
    return PROTOCOL_DIRECT_;
}
java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::PROTOCOL_DIRECT_;

java::lang::String*& rice::p2p::commonapi::testing::CommonAPITest::PROTOCOL_SOCKET()
{
    clinit();
    return PROTOCOL_SOCKET_;
}
java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::PROTOCOL_SOCKET_;

java::lang::String*& rice::p2p::commonapi::testing::CommonAPITest::PROTOCOL_RENDEZVOUS()
{
    clinit();
    return PROTOCOL_RENDEZVOUS_;
}
java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::PROTOCOL_RENDEZVOUS_;

java::lang::String*& rice::p2p::commonapi::testing::CommonAPITest::SIMULATOR_SPHERE()
{
    clinit();
    return SIMULATOR_SPHERE_;
}
java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::SIMULATOR_SPHERE_;

java::lang::String*& rice::p2p::commonapi::testing::CommonAPITest::SIMULATOR_EUCLIDEAN()
{
    clinit();
    return SIMULATOR_EUCLIDEAN_;
}
java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::SIMULATOR_EUCLIDEAN_;

java::lang::String*& rice::p2p::commonapi::testing::CommonAPITest::SIMULATOR_GT_ITM()
{
    clinit();
    return SIMULATOR_GT_ITM_;
}
java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::SIMULATOR_GT_ITM_;

int32_t& rice::p2p::commonapi::testing::CommonAPITest::BOOTSTRAP_PORT()
{
    clinit();
    return BOOTSTRAP_PORT_;
}
int32_t rice::p2p::commonapi::testing::CommonAPITest::BOOTSTRAP_PORT_;

java::lang::String*& rice::p2p::commonapi::testing::CommonAPITest::INSTANCE_NAME()
{
    clinit();
    return INSTANCE_NAME_;
}
java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::INSTANCE_NAME_;

void rice::p2p::commonapi::testing::CommonAPITest::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor();
    this->environment = env;
    setupParams(env);
    FACTORY = new ::rice::pastry::commonapi::PastryIdFactory(env);
    idFactory = new ::rice::pastry::standard::RandomNodeIdFactory(environment);
    if(npc(PROTOCOL)->equalsIgnoreCase(PROTOCOL_DIRECT_)) {
        if(npc(SIMULATOR)->equalsIgnoreCase(SIMULATOR_SPHERE_)) {
            simulator = new ::rice::pastry::direct::SphereNetwork(env);
        } else if(npc(SIMULATOR)->equalsIgnoreCase(SIMULATOR_GT_ITM_)) {
            simulator = new ::rice::pastry::direct::GenericNetwork(env);
        } else {
            simulator = new ::rice::pastry::direct::EuclideanNetwork(env);
        }
        factory = new ::rice::pastry::direct::DirectPastryNodeFactory(idFactory, simulator, env);
    } else if(npc(PROTOCOL)->equalsIgnoreCase(PROTOCOL_SOCKET_)) {
        auto address = npc(params)->getInetSocketAddress(u"commonapi_testing_bootstrap"_j);
        factory = new ::rice::pastry::socket::SocketPastryNodeFactory(idFactory, npc(address)->getAddress(), PORT, env);
    } else if(npc(PROTOCOL)->equalsIgnoreCase(PROTOCOL_RENDEZVOUS_)) {
        auto address = npc(params)->getInetSocketAddress(u"commonapi_testing_bootstrap"_j);
        factory = new ::rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory(idFactory, npc(address)->getAddress(), PORT, env, false);
    }
    if(factory == nullptr) {
        factory = ::rice::pastry::dist::DistPastryNodeFactory::getFactory(idFactory, ::rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_SOCKET(), PORT, env);
    }
    nodes = new ::rice::p2p::commonapi::NodeArray(NUM_NODES + int32_t(1));
}

constexpr int32_t rice::p2p::commonapi::testing::CommonAPITest::LEASE_PERIOD;

constexpr int32_t rice::p2p::commonapi::testing::CommonAPITest::TIME_TO_FIND_FAULTY;

void rice::p2p::commonapi::testing::CommonAPITest::waitToRecoverFromKilling(int32_t additionalTime)
{
    waitOnClock(LEASE_PERIOD + TIME_TO_FIND_FAULTY + additionalTime);
}

void rice::p2p::commonapi::testing::CommonAPITest::waitOnClock(int32_t time)
{
    if(npc(npc(environment)->getSelectorManager())->isSelectorThread())
        return;

    try {
        npc(npc(environment)->getTimeSource())->sleep(time);
    } catch (::java::lang::InterruptedException* e) {
    }
}

void rice::p2p::commonapi::testing::CommonAPITest::setupParams(::rice::environment::Environment* env)
{
    params = npc(env)->getParameters();
    npc(params)->setInt(u"pastry_socket_scm_num_ping_tries"_j, 2);
    npc(params)->setString(u"nat_search_policy"_j, u"never"_j);
    npc(params)->setInt(u"pastry_protocol_periodicLeafSet_ping_neighbor_period"_j, 8000);
    npc(params)->setInt(u"pastry_protocol_periodicLeafSet_lease_period"_j, LEASE_PERIOD);
    npc(params)->setInt(u"pastry_protocol_periodicLeafSet_request_lease_throttle"_j, 2000);
    this->logger = npc(npc(env)->getLogManager())->getLogger(getClass(), nullptr);
    NUM_NODES = npc(params)->getInt(u"commonapi_testing_num_nodes"_j);
    PORT = npc(params)->getInt(u"commonapi_testing_startPort"_j);
    PROTOCOL = npc(params)->getString(u"commonapi_testing_protocol"_j);
    SIMULATOR = npc(params)->getString(u"direct_simulator_topology"_j);
}

void rice::p2p::commonapi::testing::CommonAPITest::createNodes()
{
    if(simulator != nullptr)
        npc(simulator)->setMaxSpeed(10.0f);

    auto last = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        nodes->set(i, createNode(i));
        simulate();
        processNode(i, (*nodes)[i]);
        simulate();
        auto now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Created node "_j)->append(i)
            ->append(u" with id "_j)
            ->append(static_cast< ::java::lang::Object* >((*nodes)[i]))
            ->append(u" at "_j)
            ->append(now)
            ->append(u" "_j)
            ->append((now - last))->toString());
        last = now;
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(npc(npc((java_cast< ::rice::pastry::PastryNode* >((*nodes)[i])))->getLeafSet())->toString());

    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(npc(npc((java_cast< ::rice::pastry::PastryNode* >((*nodes)[int32_t(0)])))->getLeafSet())->toString());

    if(simulator != nullptr)
        npc(simulator)->setFullSpeed();

}

void rice::p2p::commonapi::testing::CommonAPITest::start()
{
    createNodes();
    npc(::java::lang::System::out())->println(u"\nTest Beginning\n"_j);
    runTest();
}

void rice::p2p::commonapi::testing::CommonAPITest::simulate()
{
    simulate(1);
}

void rice::p2p::commonapi::testing::CommonAPITest::simulate(int32_t numOps)
{
    if(npc(npc(environment)->getSelectorManager())->isSelectorThread())
        return;

    {
        synchronized synchronized_0(this);
        {
            try {
                wait(int32_t(500) * numOps);
            } catch (::java::lang::InterruptedException* e) {
            }
        }
    }
}

rice::p2p::commonapi::Node* rice::p2p::commonapi::testing::CommonAPITest::createNode(int32_t num)
{
    ::rice::pastry::PastryNode* ret;
    if(num == 0) {
        ret = npc(factory)->newNode(static_cast< ::rice::pastry::NodeHandle* >(nullptr));
    } else {
        ret = npc(factory)->newNode(getBootstrap());
    }
    {
        synchronized synchronized_1(ret);
        {
            while (!npc(ret)->isReady()) {
                try {
                    npc(ret)->wait(1000);
                } catch (::java::lang::InterruptedException* ie) {
                    npc(ie)->printStackTrace();
                    return nullptr;
                }
                if(!npc(ret)->isReady()) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(ret))
                            ->append(u" is not yet ready."_j)->toString());

                }
            }
        }
    }
    return ret;
}

rice::pastry::NodeHandle* rice::p2p::commonapi::testing::CommonAPITest::getBootstrap()
{
    if(npc(PROTOCOL)->equalsIgnoreCase(PROTOCOL_DIRECT_)) {
        return npc((java_cast< ::rice::pastry::PastryNode* >((*nodes)[int32_t(0)])))->getLocalHandle();
    } else {
        try {
            auto address = npc(params)->getInetSocketAddress(u"commonapi_testing_bootstrap"_j);
            return npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(address);
        } catch (::java::net::UnknownHostException* uhe) {
            throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(uhe));
        }
    }
}

void rice::p2p::commonapi::testing::CommonAPITest::pause(int32_t ms)
{
    try {
        npc(npc(environment)->getTimeSource())->sleep(ms);
    } catch (::java::lang::InterruptedException* e) {
    }
}

void rice::p2p::commonapi::testing::CommonAPITest::kill(int32_t n)
{
    npc((java_cast< ::rice::pastry::PastryNode* >((*nodes)[n])))->destroy();
    if(!npc(PROTOCOL)->equalsIgnoreCase(PROTOCOL_DIRECT_)) {
        pause(2000);
    }
}

void rice::p2p::commonapi::testing::CommonAPITest::sectionStart(::java::lang::String* name)
{
    npc(::java::lang::System::out())->println(name);
}

void rice::p2p::commonapi::testing::CommonAPITest::sectionDone()
{
    npc(::java::lang::System::out())->println();
}

void rice::p2p::commonapi::testing::CommonAPITest::stepStart(::java::lang::String* name)
{
    npc(::java::lang::System::out())->print(pad(::java::lang::StringBuilder().append(u"  "_j)->append(name)->toString()));
}

void rice::p2p::commonapi::testing::CommonAPITest::stepDone()
{
    stepDone(SUCCESS_);
}

void rice::p2p::commonapi::testing::CommonAPITest::stepDone(::java::lang::String* status)
{
    stepDone(status, u""_j);
}

void rice::p2p::commonapi::testing::CommonAPITest::stepDone(::java::lang::String* status, ::java::lang::String* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"["_j)->append(status)
        ->append(u"]"_j)->toString());
    if((message != nullptr) && (!npc(message)->equals(static_cast< ::java::lang::Object* >(u""_j)))) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"     "_j)->append(message)->toString());
    }
    if(npc(status)->equals(static_cast< ::java::lang::Object* >(FAILURE_))) {
        if(npc(npc(environment)->getParameters())->getBoolean(u"commonapi_testing_exit_on_failure"_j)) {
            ::java::lang::System::exit(1);
        } else {
            try {
                ::java::lang::Thread::sleep(100000000);
            } catch (::java::lang::InterruptedException* ie) {
                ::java::lang::System::exit(1);
            }
        }
    }
}

void rice::p2p::commonapi::testing::CommonAPITest::stepException(::java::lang::Exception* e)
{
    npc(logger)->logException(u"\nException occurred during testing."_j, e);
    ::java::lang::System::exit(2);
}

java::lang::String* rice::p2p::commonapi::testing::CommonAPITest::pad(::java::lang::String* start)
{
    if(npc(start)->length() >= PAD_SIZE) {
        return npc(start)->substring(0, PAD_SIZE);
    } else {
        auto spaceLength = PAD_SIZE - npc(start)->length();
        auto spaces = new ::char16_tArray(spaceLength);
        ::java::util::Arrays::fill(spaces, u'.');
        return npc(start)->concat(new ::java::lang::String(spaces));
    }
}

void rice::p2p::commonapi::testing::CommonAPITest::assertTrue(::java::lang::String* intention, bool test)
{
    if(!test) {
        stepDone(FAILURE_, ::java::lang::StringBuilder().append(u"Assertion '"_j)->append(intention)
            ->append(u"' failed."_j)->toString());
    }
}

void rice::p2p::commonapi::testing::CommonAPITest::assertEquals(::java::lang::String* description, ::java::lang::Object* expected, ::java::lang::Object* actual)
{
    if(!npc(expected)->equals(actual)) {
        stepDone(FAILURE_, ::java::lang::StringBuilder().append(u"Assertion '"_j)->append(description)
            ->append(u"' failed, expected: '"_j)
            ->append(static_cast< ::java::lang::Object* >(expected))
            ->append(u"' got: "_j)
            ->append(static_cast< ::java::lang::Object* >(actual))
            ->append(u"'"_j)->toString());
    }
}

rice::environment::Environment* rice::p2p::commonapi::testing::CommonAPITest::parseArgs(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-help"_j))) {
            npc(::java::lang::System::out())->println(u"Usage: DistCommonAPITest [-params paramsfile] [-port p] [-protocol (direct|socket)] [-bootstrap host[:port]] [-help]"_j);
            ::java::lang::System::exit(1);
        }
    }
    ::rice::environment::params::Parameters* params = nullptr;
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-params"_j)) && i + int32_t(1) < npc(args)->length) {
            params = new ::rice::environment::params::simple::SimpleParameters(::rice::environment::Environment::defaultParamFileArray_(), (*args)[i + int32_t(1)]);
            break;
        }
    }
    if(params == nullptr) {
        params = new ::rice::environment::params::simple::SimpleParameters(::rice::environment::Environment::defaultParamFileArray_(), nullptr);
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-protocol"_j)) && i + int32_t(1) < npc(args)->length) {
            npc(params)->setString(u"commonapi_testing_protocol"_j, (*args)[i + int32_t(1)]);
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-simulator"_j)) && i + int32_t(1) < npc(args)->length) {
            npc(params)->setString(u"direct_simulator_topology"_j, (*args)[i + int32_t(1)]);
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-nodes"_j)) && i + int32_t(1) < npc(args)->length) {
            auto p = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(p > 0)
                npc(params)->setInt(u"commonapi_testing_num_nodes"_j, p);

            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-port"_j)) && i + int32_t(1) < npc(args)->length) {
            auto p = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(p > 0)
                npc(params)->setInt(u"commonapi_testing_startPort"_j, p);

            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-bootstrap"_j)) && i + int32_t(1) < npc(args)->length) {
            auto str = (*args)[i + int32_t(1)];
            auto index = npc(str)->indexOf(static_cast< int32_t >(u':'));
            if(index == -int32_t(1)) {
                npc(params)->setInetSocketAddress(u"commonapi_testing_bootstrap"_j, new ::java::net::InetSocketAddress(::java::net::InetAddress::getByName(str), npc(params)->getInt(u"commonapi_testing_startPort"_j)));
            } else {
                npc(params)->setString(u"commonapi_testing_bootstrap"_j, str);
            }
            break;
        }
    }
    if(!npc(params)->contains(u"commonapi_testing_bootstrap"_j)) {
        try {
            auto localHost = ::java::net::InetAddress::getLocalHost();
            npc(params)->setInetSocketAddress(u"commonapi_testing_bootstrap"_j, new ::java::net::InetSocketAddress(localHost, npc(params)->getInt(u"commonapi_testing_startPort"_j)));
        } catch (::java::net::UnknownHostException* e) {
            npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"Error determining local host: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
        }
    }
    ::rice::environment::time::TimeSource* timeSource;
    ::rice::selector::SelectorManager* selector = nullptr;
    ::rice::environment::processing::Processor* proc = nullptr;
    ::rice::environment::logging::LogManager* logManager = nullptr;
    ::rice::environment::random::RandomSource* rand = nullptr;
    if(npc(npc(params)->getString(u"commonapi_testing_protocol"_j))->equals(static_cast< ::java::lang::Object* >(u"direct"_j))) {
        timeSource = new ::rice::environment::time::simulated::DirectTimeSource(params);
        logManager = ::rice::environment::Environment::generateDefaultLogManager(timeSource, params);
        rand = ::rice::environment::Environment::generateDefaultRandomSource(params, logManager);
        npc((java_cast< ::rice::environment::time::simulated::DirectTimeSource* >(timeSource)))->setLogManager(logManager);
        selector = ::rice::environment::Environment::generateDefaultSelectorManager(timeSource, logManager, rand);
        npc((java_cast< ::rice::environment::time::simulated::DirectTimeSource* >(timeSource)))->setSelectorManager(selector);
        proc = new ::rice::environment::processing::sim::SimProcessor(selector);
    } else {
        timeSource = new ::rice::environment::time::simple::SimpleTimeSource();
    }
    return new ::rice::environment::Environment(selector, proc, nullptr, timeSource, logManager, params, nullptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::commonapi::testing::CommonAPITest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.commonapi.testing.CommonAPITest", 40);
    return c;
}

void rice::p2p::commonapi::testing::CommonAPITest::clinit()
{
struct string_init_ {
    string_init_() {
    SUCCESS_ = u"SUCCESS"_j;
    FAILURE_ = u"FAILURE"_j;
    PROTOCOL_DIRECT_ = u"direct"_j;
    PROTOCOL_SOCKET_ = u"socket"_j;
    PROTOCOL_RENDEZVOUS_ = u"rendezvous"_j;
    SIMULATOR_SPHERE_ = u"sphere"_j;
    SIMULATOR_EUCLIDEAN_ = u"euclidean"_j;
    SIMULATOR_GT_ITM_ = u"gt-itm"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        BOOTSTRAP_PORT_ = int32_t(5009);
        INSTANCE_NAME_ = u"DistCommonAPITest"_j;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::commonapi::testing::CommonAPITest::getClass0()
{
    return class_();
}

