// Generated from /pastry-2.1/src/rice/p2p/multiring/testing/MultiringRegrTest.java
#include <rice/p2p/multiring/testing/MultiringRegrTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/UnknownHostException.hpp>
#include <java/util/Arrays.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/multiring/MultiringNode.hpp>
#include <rice/p2p/multiring/testing/MultiringRegrTest_MultiringTestApp.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/EuclideanNetwork.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/direct/SphereNetwork.hpp>
#include <rice/pastry/dist/DistPastryNodeFactory.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
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
typedef ::SubArray< ::rice::p2p::commonapi::Application, ::java::lang::ObjectArray > ApplicationArray;
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
typedef ::SubArray< ::rice::p2p::commonapi::Node, ::java::lang::ObjectArray > NodeArray;
        } // commonapi

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::ScribeClient, ::java::lang::ObjectArray > ScribeClientArray;
        } // scribe

        namespace multiring
        {
typedef ::SubArray< ::rice::p2p::multiring::MultiringNode, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeArray, ::rice::p2p::scribe::ScribeClientArray > MultiringNodeArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp, ::java::lang::ObjectArray, ::rice::p2p::commonapi::ApplicationArray > MultiringRegrTest_MultiringTestAppArray;
            } // testing
typedef ::SubArray< ::rice::p2p::multiring::MultiringNodeArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > MultiringNodeArrayArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestAppArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > MultiringRegrTest_MultiringTestAppArrayArray;
            } // testing
        } // multiring
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
rice::p2p::multiring::testing::MultiringRegrTest::MultiringRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::testing::MultiringRegrTest::MultiringRegrTest(::rice::environment::Environment* env)  /* throws(IOException) */
    : MultiringRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

int32_t& rice::p2p::multiring::testing::MultiringRegrTest::NUM_GLOBAL_NODES()
{
    clinit();
    return NUM_GLOBAL_NODES_;
}
int32_t rice::p2p::multiring::testing::MultiringRegrTest::NUM_GLOBAL_NODES_;

int32_t& rice::p2p::multiring::testing::MultiringRegrTest::NUM_ORGANIZATIONS()
{
    clinit();
    return NUM_ORGANIZATIONS_;
}
int32_t rice::p2p::multiring::testing::MultiringRegrTest::NUM_ORGANIZATIONS_;

int32_t& rice::p2p::multiring::testing::MultiringRegrTest::NUM_INTERNAL_NODES()
{
    clinit();
    return NUM_INTERNAL_NODES_;
}
int32_t rice::p2p::multiring::testing::MultiringRegrTest::NUM_INTERNAL_NODES_;

int32_t& rice::p2p::multiring::testing::MultiringRegrTest::NUM_GATEWAY_NODES()
{
    clinit();
    return NUM_GATEWAY_NODES_;
}
int32_t rice::p2p::multiring::testing::MultiringRegrTest::NUM_GATEWAY_NODES_;

int32_t& rice::p2p::multiring::testing::MultiringRegrTest::NUM_ORGANIZATIONAL_NODES()
{
    clinit();
    return NUM_ORGANIZATIONAL_NODES_;
}
int32_t rice::p2p::multiring::testing::MultiringRegrTest::NUM_ORGANIZATIONAL_NODES_;

java::lang::String*& rice::p2p::multiring::testing::MultiringRegrTest::SUCCESS()
{
    clinit();
    return SUCCESS_;
}
java::lang::String* rice::p2p::multiring::testing::MultiringRegrTest::SUCCESS_;

java::lang::String*& rice::p2p::multiring::testing::MultiringRegrTest::FAILURE()
{
    clinit();
    return FAILURE_;
}
java::lang::String* rice::p2p::multiring::testing::MultiringRegrTest::FAILURE_;

constexpr int32_t rice::p2p::multiring::testing::MultiringRegrTest::PAD_SIZE;

constexpr int32_t rice::p2p::multiring::testing::MultiringRegrTest::PROTOCOL_DIRECT;

constexpr int32_t rice::p2p::multiring::testing::MultiringRegrTest::SIMULATOR_SPHERE;

constexpr int32_t rice::p2p::multiring::testing::MultiringRegrTest::SIMULATOR_EUCLIDEAN;

int32_t& rice::p2p::multiring::testing::MultiringRegrTest::PORT()
{
    clinit();
    return PORT_;
}
int32_t rice::p2p::multiring::testing::MultiringRegrTest::PORT_;

java::lang::String*& rice::p2p::multiring::testing::MultiringRegrTest::BOOTSTRAP_HOST()
{
    clinit();
    return BOOTSTRAP_HOST_;
}
java::lang::String* rice::p2p::multiring::testing::MultiringRegrTest::BOOTSTRAP_HOST_;

int32_t& rice::p2p::multiring::testing::MultiringRegrTest::BOOTSTRAP_PORT()
{
    clinit();
    return BOOTSTRAP_PORT_;
}
int32_t rice::p2p::multiring::testing::MultiringRegrTest::BOOTSTRAP_PORT_;

int32_t& rice::p2p::multiring::testing::MultiringRegrTest::PROTOCOL()
{
    clinit();
    return PROTOCOL_;
}
int32_t rice::p2p::multiring::testing::MultiringRegrTest::PROTOCOL_;

int32_t& rice::p2p::multiring::testing::MultiringRegrTest::SIMULATOR()
{
    clinit();
    return SIMULATOR_;
}
int32_t rice::p2p::multiring::testing::MultiringRegrTest::SIMULATOR_;

java::lang::String*& rice::p2p::multiring::testing::MultiringRegrTest::INSTANCE_NAME()
{
    clinit();
    return INSTANCE_NAME_;
}
java::lang::String* rice::p2p::multiring::testing::MultiringRegrTest::INSTANCE_NAME_;

void rice::p2p::multiring::testing::MultiringRegrTest::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor();
    this->environment = env;
    if(PROTOCOL_ == PROTOCOL_DIRECT) {
        if(SIMULATOR_ == SIMULATOR_SPHERE) {
            simulator = new ::rice::pastry::direct::SphereNetwork(env);
        } else {
            simulator = new ::rice::pastry::direct::EuclideanNetwork(env);
        }
        factory = new ::rice::pastry::direct::DirectPastryNodeFactory(new ::rice::pastry::standard::RandomNodeIdFactory(environment), simulator, env);
    } else {
        factory = ::rice::pastry::dist::DistPastryNodeFactory::getFactory(new ::rice::pastry::standard::RandomNodeIdFactory(environment), PROTOCOL_, PORT_, env);
    }
    NUM_GATEWAY_NODES_ = NUM_GLOBAL_NODES_ / NUM_ORGANIZATIONS_;
    NUM_ORGANIZATIONAL_NODES_ = NUM_GATEWAY_NODES_ + NUM_INTERNAL_NODES_;
    idFactory = new ::rice::pastry::commonapi::PastryIdFactory(env);
    globalRingId = npc(idFactory)->buildId(new ::int8_tArray(int32_t(20)));
    ringIds = new ::rice::p2p::commonapi::IdArray(NUM_ORGANIZATIONS_);
    globalNodes = new ::rice::p2p::multiring::MultiringNodeArray(NUM_GLOBAL_NODES_);
    organizationalNodes = new ::rice::p2p::multiring::MultiringNodeArrayArray(NUM_ORGANIZATIONS_);
    globalApps = new MultiringRegrTest_MultiringTestAppArray(NUM_GLOBAL_NODES_);
    organizationalApps = new MultiringRegrTest_MultiringTestAppArrayArray(NUM_ORGANIZATIONS_);
}

void rice::p2p::multiring::testing::MultiringRegrTest::createNodes()
{
    for (auto i = int32_t(0); i < NUM_GLOBAL_NODES_; i++) {
        globalNodes->set(i, createNode(globalRingId, (*globalNodes)[int32_t(0)]));
        simulate();
        globalApps->set(i, new MultiringRegrTest_MultiringTestApp(this, (*globalNodes)[i]));
        simulate();
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Created node "_j)->append(i)
            ->append(u" in the global ring with id "_j)
            ->append(static_cast< ::java::lang::Object* >(npc((*globalNodes)[i])->getId()))->toString());
    }
    for (auto i = int32_t(0); i < NUM_ORGANIZATIONS_; i++) {
        ringIds->set(i, generateId(int32_t(16) * (i + int32_t(1))));
        for (auto j = int32_t(0); j < NUM_GATEWAY_NODES_; j++) {
            (*organizationalNodes)[i]->set(j, createNode((*globalNodes)[i * NUM_GATEWAY_NODES_ + j], (*ringIds)[i], (*(*organizationalNodes)[i])[int32_t(0)]));
            simulate();
            (*organizationalApps)[i]->set(j, new MultiringRegrTest_MultiringTestApp(this, (*(*organizationalNodes)[i])[j]));
            simulate();
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Created gateway node "_j)->append(j)
                ->append(u" in ring "_j)
                ->append(static_cast< ::java::lang::Object* >((*ringIds)[i]))
                ->append(u" with id "_j)
                ->append(static_cast< ::java::lang::Object* >(npc((*(*organizationalNodes)[i])[j])->getId()))->toString());
        }
        for (auto j = MultiringRegrTest::NUM_GATEWAY_NODES_; j < NUM_ORGANIZATIONAL_NODES_; j++) {
            (*organizationalNodes)[i]->set(j, createNode((*ringIds)[i], (*(*organizationalNodes)[i])[int32_t(0)]));
            simulate();
            (*organizationalApps)[i]->set(j, new MultiringRegrTest_MultiringTestApp(this, (*(*organizationalNodes)[i])[j]));
            simulate();
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Created internal node "_j)->append((j - NUM_GATEWAY_NODES_))
                ->append(u" in ring "_j)
                ->append(static_cast< ::java::lang::Object* >((*ringIds)[i]))
                ->append(u" with id "_j)
                ->append(static_cast< ::java::lang::Object* >(npc((*(*organizationalNodes)[i])[j])->getId()))->toString());
        }
    }
}

void rice::p2p::multiring::testing::MultiringRegrTest::start()
{
    createNodes();
    npc(::java::lang::System::out())->println(u"\nTest Beginning\n"_j);
    runTest();
}

void rice::p2p::multiring::testing::MultiringRegrTest::simulate()
{
    try {
        ::java::lang::Thread::sleep(300);
    } catch (::java::lang::InterruptedException* ie) {
    }
}

rice::p2p::multiring::MultiringNode* rice::p2p::multiring::testing::MultiringRegrTest::createNode(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::multiring::MultiringNode* bootstrap)
{
    ::rice::p2p::multiring::MultiringNode* mn;
    if(bootstrap == nullptr) {
        mn = new ::rice::p2p::multiring::MultiringNode(ringId, npc(factory)->newNode(static_cast< ::rice::pastry::NodeHandle* >(nullptr)));
    } else {
        mn = new ::rice::p2p::multiring::MultiringNode(ringId, npc(factory)->newNode(getBootstrap(npc(bootstrap)->getNode())));
    }
    auto pn = java_cast< ::rice::pastry::PastryNode* >(npc(mn)->getNode());
    {
        synchronized synchronized_0(pn);
        {
            while (!npc(pn)->isReady()) {
                try {
                    npc(pn)->wait(500);
                } catch (::java::lang::InterruptedException* ie) {
                    return nullptr;
                }
            }
            if(!npc(pn)->isReady()) {
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Still waiting for node "_j)->append(static_cast< ::java::lang::Object* >(pn))
                    ->append(u" in ring "_j)
                    ->append(static_cast< ::java::lang::Object* >(ringId))
                    ->append(u" to be ready."_j)->toString());
            }
        }
    }
    return mn;
}

rice::p2p::multiring::MultiringNode* rice::p2p::multiring::testing::MultiringRegrTest::createNode(::rice::p2p::multiring::MultiringNode* existing, ::rice::p2p::commonapi::Id* ringId, ::rice::p2p::multiring::MultiringNode* bootstrap)
{
    if(existing == nullptr)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"EXISTING WAS NULL! "_j)->append(static_cast< ::java::lang::Object* >(ringId))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(bootstrap))->toString());

    if(bootstrap == nullptr) {
        return new ::rice::p2p::multiring::MultiringNode(ringId, npc(factory)->newNode(nullptr, java_cast< ::rice::pastry::Id* >(npc(existing)->getNodeId())), existing);
    } else {
        return new ::rice::p2p::multiring::MultiringNode(ringId, npc(factory)->newNode(getBootstrap(npc(bootstrap)->getNode()), java_cast< ::rice::pastry::Id* >(npc(existing)->getNodeId())), existing);
    }
}

rice::pastry::NodeHandle* rice::p2p::multiring::testing::MultiringRegrTest::getBootstrap(::rice::p2p::commonapi::Node* bootstrap)
{
    if(PROTOCOL_ == PROTOCOL_DIRECT) {
        return npc((java_cast< ::rice::pastry::PastryNode* >(bootstrap)))->getLocalHandle();
    } else {
        return npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(npc(npc((java_cast< ::rice::pastry::socket::SocketNodeHandle* >(npc((java_cast< ::rice::pastry::PastryNode* >(bootstrap)))->getLocalHandle())))->eaddress)->getInnermostAddress());
    }
}

void rice::p2p::multiring::testing::MultiringRegrTest::pause(int32_t ms)
{
    if(PROTOCOL_ != PROTOCOL_DIRECT)
        try {
            wait(ms);
        } catch (::java::lang::InterruptedException* e) {
        }

}

void rice::p2p::multiring::testing::MultiringRegrTest::kill(int32_t n)
{
}

rice::p2p::commonapi::Id* rice::p2p::multiring::testing::MultiringRegrTest::generateId()
{
    auto data = new ::int8_tArray(int32_t(20));
    npc(npc(environment)->getRandomSource())->nextBytes(data);
    return npc(idFactory)->buildId(data);
}

rice::p2p::commonapi::Id* rice::p2p::multiring::testing::MultiringRegrTest::generateId(int32_t i)
{
    auto data = new ::int8_tArray(int32_t(20));
    (*data)[npc(data)->length - int32_t(1)] = static_cast< int8_t >(int32_t(2));
    (*data)[npc(data)->length - int32_t(2)] = static_cast< int8_t >(i);
    return npc(idFactory)->buildId(data);
}

void rice::p2p::multiring::testing::MultiringRegrTest::runTest()
{
    auto rng = npc(environment)->getRandomSource();
    for (auto i = int32_t(0); i < 20; i++) {
        auto si = npc(rng)->nextInt(NUM_ORGANIZATIONS_);
        auto sj = npc(rng)->nextInt(NUM_ORGANIZATIONAL_NODES_);
        auto di = npc(rng)->nextInt(NUM_ORGANIZATIONS_);
        auto dj = npc(rng)->nextInt(NUM_ORGANIZATIONAL_NODES_);
        auto sourceApp = (*(*organizationalApps)[si])[sj];
        auto source = npc((*(*organizationalNodes)[si])[sj])->getId();
        auto dest = npc((*(*organizationalNodes)[di])[dj])->getId();
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(i)->append(u" SENDING FROM "_j)
            ->append(static_cast< ::java::lang::Object* >(source))
            ->append(u" TO "_j)
            ->append(static_cast< ::java::lang::Object* >(dest))->toString());
        npc(sourceApp)->send(dest);
        try {
            ::java::lang::Thread::sleep(500);
        } catch (::java::lang::Exception* e) {
        }
    }
}

void rice::p2p::multiring::testing::MultiringRegrTest::sectionStart(::java::lang::String* name)
{
    npc(::java::lang::System::out())->println(name);
}

void rice::p2p::multiring::testing::MultiringRegrTest::sectionDone()
{
    npc(::java::lang::System::out())->println();
}

void rice::p2p::multiring::testing::MultiringRegrTest::stepStart(::java::lang::String* name)
{
    npc(::java::lang::System::out())->print(pad(::java::lang::StringBuilder().append(u"  "_j)->append(name)->toString()));
}

void rice::p2p::multiring::testing::MultiringRegrTest::stepDone()
{
    stepDone(SUCCESS_);
}

void rice::p2p::multiring::testing::MultiringRegrTest::stepDone(::java::lang::String* status)
{
    stepDone(status, u""_j);
}

void rice::p2p::multiring::testing::MultiringRegrTest::stepDone(::java::lang::String* status, ::java::lang::String* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"["_j)->append(status)
        ->append(u"]"_j)->toString());
    if((message != nullptr) && (!npc(message)->equals(static_cast< ::java::lang::Object* >(u""_j)))) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"     "_j)->append(message)->toString());
    }
    if(npc(status)->equals(static_cast< ::java::lang::Object* >(FAILURE_)))
        ::java::lang::System::exit(0);

}

void rice::p2p::multiring::testing::MultiringRegrTest::stepException(::java::lang::Exception* e)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"\nException "_j)->append(static_cast< ::java::lang::Object* >(e))
        ->append(u" occurred during testing."_j)->toString());
    npc(e)->printStackTrace();
    ::java::lang::System::exit(0);
}

java::lang::String* rice::p2p::multiring::testing::MultiringRegrTest::pad(::java::lang::String* start)
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

void rice::p2p::multiring::testing::MultiringRegrTest::assertTrue(::java::lang::String* intention, bool test)
{
    if(!test) {
        stepDone(FAILURE_, ::java::lang::StringBuilder().append(u"Assertion '"_j)->append(intention)
            ->append(u"' failed."_j)->toString());
    }
}

void rice::p2p::multiring::testing::MultiringRegrTest::assertEquals(::java::lang::String* description, ::java::lang::Object* expected, ::java::lang::Object* actual)
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

void rice::p2p::multiring::testing::MultiringRegrTest::parseArgs(::java::lang::StringArray* args)
{
    clinit();
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-help"_j))) {
            npc(::java::lang::System::out())->println(u"Usage: DistCommonAPITest [-port p] [-protocol (rmi|wire)] [-bootstrap host[:port]] [-help]"_j);
            ::java::lang::System::exit(1);
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-globalNodes"_j)) && i + int32_t(1) < npc(args)->length) {
            auto p = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(p > 0)
                NUM_GLOBAL_NODES_ = p;

            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-organizations"_j)) && i + int32_t(1) < npc(args)->length) {
            auto p = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(p > 0)
                NUM_ORGANIZATIONS_ = p;

            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-internalNodes"_j)) && i + int32_t(1) < npc(args)->length) {
            auto p = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(p > 0)
                NUM_INTERNAL_NODES_ = p;

            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-port"_j)) && i + int32_t(1) < npc(args)->length) {
            auto p = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(p > 0)
                PORT_ = p;

            break;
        }
    }
    BOOTSTRAP_PORT_ = PORT_;
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-bootstrap"_j)) && i + int32_t(1) < npc(args)->length) {
            auto str = (*args)[i + int32_t(1)];
            auto index = npc(str)->indexOf(static_cast< int32_t >(u':'));
            if(index == -int32_t(1)) {
                BOOTSTRAP_HOST_ = str;
                BOOTSTRAP_PORT_ = PORT_;
            } else {
                BOOTSTRAP_HOST_ = npc(str)->substring(0, index);
                BOOTSTRAP_PORT_ = ::java::lang::Integer::parseInt(npc(str)->substring(index + int32_t(1)));
                if(BOOTSTRAP_PORT_ <= 0)
                    BOOTSTRAP_PORT_ = PORT_;

            }
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-protocol"_j)) && i + int32_t(1) < npc(args)->length) {
            auto s = (*args)[i + int32_t(1)];
            if(npc(s)->equalsIgnoreCase(u"socket"_j))
                PROTOCOL_ = ::rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_SOCKET();
            else if(npc(s)->equalsIgnoreCase(u"direct"_j))
                PROTOCOL_ = PROTOCOL_DIRECT;
            else
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR: Unsupported protocol: "_j)->append(s)->toString());
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-simulator"_j)) && i + int32_t(1) < npc(args)->length) {
            auto s = (*args)[i + int32_t(1)];
            if(npc(s)->equalsIgnoreCase(u"sphere"_j))
                SIMULATOR_ = SIMULATOR_SPHERE;
            else if(npc(s)->equalsIgnoreCase(u"euclidean"_j))
                PROTOCOL_ = SIMULATOR_EUCLIDEAN;
            else
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR: Unsupported simulator: "_j)->append(s)->toString());
            break;
        }
    }
}

void rice::p2p::multiring::testing::MultiringRegrTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    parseArgs(args);
    ::rice::environment::Environment* env;
    if(PROTOCOL_ == PROTOCOL_DIRECT) {
        env = ::rice::environment::Environment::directEnvironment();
    } else {
        env = new ::rice::environment::Environment();
    }
    auto test = new MultiringRegrTest(env);
    npc(test)->start();
    npc(env)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::testing::MultiringRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.testing.MultiringRegrTest", 44);
    return c;
}

void rice::p2p::multiring::testing::MultiringRegrTest::clinit()
{
struct string_init_ {
    string_init_() {
    SUCCESS_ = u"SUCCESS"_j;
    FAILURE_ = u"FAILURE"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        NUM_GLOBAL_NODES_ = int32_t(20);
        NUM_ORGANIZATIONS_ = int32_t(5);
        NUM_INTERNAL_NODES_ = int32_t(3);
        NUM_GATEWAY_NODES_ = NUM_GLOBAL_NODES_ / NUM_ORGANIZATIONS_;
        NUM_ORGANIZATIONAL_NODES_ = NUM_GATEWAY_NODES_ + NUM_INTERNAL_NODES_;
        PORT_ = int32_t(5009);
        BOOTSTRAP_HOST_ = u"localhost"_j;
        BOOTSTRAP_PORT_ = int32_t(5009);
        PROTOCOL_ = ::rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_DEFAULT();
        SIMULATOR_ = MultiringRegrTest::SIMULATOR_SPHERE;
        INSTANCE_NAME_ = u"MultiringRegrTest"_j;
        {
            try {
                BOOTSTRAP_HOST_ = npc(::java::net::InetAddress::getLocalHost())->getHostName();
            } catch (::java::net::UnknownHostException* e) {
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Error determining local host: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
            }
        }
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::multiring::testing::MultiringRegrTest::getClass0()
{
    return class_();
}

