// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamRegrTest.java
#include <rice/p2p/splitstream/testing/SplitStreamRegrTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Observable.hpp>
#include <rice/Destructable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/splitstream/Channel.hpp>
#include <rice/p2p/splitstream/ChannelId.hpp>
#include <rice/p2p/splitstream/SplitStream.hpp>
#include <rice/p2p/splitstream/SplitStreamClient.hpp>
#include <rice/p2p/splitstream/SplitStreamImpl.hpp>
#include <rice/p2p/splitstream/SplitStreamScribePolicy.hpp>
#include <rice/p2p/splitstream/Stripe.hpp>
#include <rice/p2p/splitstream/StripeId.hpp>
#include <rice/p2p/splitstream/testing/SplitStreamRegrTest_SplitStreamTestClient.hpp>
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

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
typedef ::SubArray< ::rice::Destructable, ::java::lang::ObjectArray > DestructableArray;

    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::ScribeClient, ::java::lang::ObjectArray > ScribeClientArray;
        } // scribe

        namespace splitstream
        {
typedef ::SubArray< ::rice::p2p::splitstream::SplitStream, ::java::lang::ObjectArray, ::rice::DestructableArray > SplitStreamArray;
typedef ::SubArray< ::rice::p2p::splitstream::SplitStreamClient, ::java::lang::ObjectArray > SplitStreamClientArray;
typedef ::SubArray< ::rice::p2p::splitstream::SplitStreamImpl, ::java::lang::ObjectArray, SplitStreamArray > SplitStreamImplArray;
typedef ::SubArray< ::rice::p2p::splitstream::Stripe, ::java::lang::ObjectArray, ::rice::p2p::scribe::ScribeClientArray > StripeArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient, ::java::lang::ObjectArray, ::rice::p2p::splitstream::SplitStreamClientArray > SplitStreamRegrTest_SplitStreamTestClientArray;
            } // testing
        } // splitstream
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

rice::p2p::splitstream::testing::SplitStreamRegrTest::SplitStreamRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::testing::SplitStreamRegrTest::SplitStreamRegrTest(::rice::environment::Environment* env)  /* throws(IOException) */
    : SplitStreamRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

java::lang::String*& rice::p2p::splitstream::testing::SplitStreamRegrTest::INSTANCE()
{
    clinit();
    return INSTANCE_;
}
java::lang::String* rice::p2p::splitstream::testing::SplitStreamRegrTest::INSTANCE_;

void rice::p2p::splitstream::testing::SplitStreamRegrTest::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(env);
    splitstreams = new ::rice::p2p::splitstream::SplitStreamImplArray(NUM_NODES);
    ssclients = new SplitStreamRegrTest_SplitStreamTestClientArray(NUM_NODES);
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto env = parseArgs(args);
    auto splitstreamTest = new SplitStreamRegrTest(env);
    npc(splitstreamTest)->start();
    npc(env)->destroy();
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest::processNode(int32_t num, ::rice::p2p::commonapi::Node* node)
{
    splitstreams->set(num, new ::rice::p2p::splitstream::SplitStreamImpl(node, INSTANCE_));
    ssclients->set(num, new SplitStreamRegrTest_SplitStreamTestClient(this, node, (*splitstreams)[num]));
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest::runTest()
{
    if(NUM_NODES < 2) {
        npc(::java::lang::System::out())->println(u"The DistScribeRegrTest must be run with at least 2 nodes for proper testing.  Use the '-nodes n' to specify the number of nodes."_j);
        return;
    }
    testBasic();
    testBandwidthUsage();
    testIndependence();
    testMaintenance(NUM_NODES / int32_t(10));
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest::testBandwidthUsage()
{
    auto DEFAULT_MAX_CHILDREN = npc(npc(environment)->getParameters())->getInt(u"p2p_splitStream_policy_default_maximum_children"_j);
    auto result = true;
    auto count = int32_t(0);
    auto total = int32_t(0);
    ::rice::p2p::splitstream::Channel* channel;
    sectionStart(u"BandwidthUsage Test"_j);
    stepStart(u"Usage"_j);
    simulate();
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        channel = npc((*ssclients)[i])->getChannel();
        count = npc((java_cast< ::rice::p2p::splitstream::SplitStreamScribePolicy* >(npc((*splitstreams)[i])->getPolicy())))->getTotalChildren(channel);
        if(count > DEFAULT_MAX_CHILDREN)
            result = false;

        total += count;
    }
    if(result && (total <= (NUM_NODES - int32_t(1)) * DEFAULT_MAX_CHILDREN)) {
        stepDone(SUCCESS());
    } else {
        stepDone(FAILURE());
    }
    sectionDone();
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest::testIndependence()
{
    auto result = true;
    auto count = int32_t(0);
    auto num = int32_t(0);
    auto array = new ::int32_tArray(int32_t(20));
    ::rice::p2p::splitstream::Channel* channel;
    ::rice::p2p::splitstream::StripeArray* stripes;
    sectionStart(u"Path Independence Test"_j);
    stepStart(u"Usage"_j);
    simulate();
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        channel = npc((*ssclients)[i])->getChannel();
        stripes = npc(channel)->getStripes();
        num = 0;
        for (auto j = int32_t(0); j < npc(stripes)->length; j++) {
            count = npc(npc((*stripes)[j])->getChildren())->length;
            if(count > 0)
                num++;

        }
        (*array)[num]++;
    }
    for (auto i = int32_t(0); i < 20; i++) 
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(i)->append(u"\t"_j)
            ->append((*array)[i])->toString());

    sectionDone();
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest::testMaintenance(int32_t num)
{
    sectionStart(u"Maintenance of multicast trees"_j);
    stepStart(u"Killing Nodes"_j);
    for (auto i = int32_t(0); i < num; i++) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Killing "_j)->append(static_cast< ::java::lang::Object* >(npc((*ssclients)[i])->getId()))->toString());
        npc((*ssclients)[i])->destroy();
        kill(i);
        simulate();
    }
    waitToRecoverFromKilling(npc(params)->getInt(u"p2p_scribe_message_timeout"_j) * int32_t(10));
    if(checkTree(num, NUM_NODES))
        stepDone(SUCCESS());
    else {
        stepDone(FAILURE(), u"not all have parent"_j);
    }
    stepStart(u"Tree Recovery"_j);
    auto data = (new ::int8_tArray({
        static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(1))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(1))
        , static_cast< int8_t >(int32_t(1))
    }));
    auto pass = true;
    for (auto i = int32_t(0); i < 10; i++) {
        npc((*ssclients)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES - num) + num])->publishAll(data);
        simulate();
        auto totalmsgs = int32_t(0);
        for (auto j = int32_t(0); j < NUM_NODES - num; j++) {
            totalmsgs = totalmsgs + npc((*ssclients)[j + num])->getNumMesgs();
            if(npc((*ssclients)[j + num])->getNumMesgs() != 16)
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(npc((*ssclients)[j + num])->getId()))->append(u" recived "_j)
                    ->append(npc((*ssclients)[j + num])->getNumMesgs())->toString());

            npc((*ssclients)[j + num])->reset();
        }
        if(totalmsgs != ((NUM_NODES - num) * int32_t(16))) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Expected "_j)->append(((NUM_NODES - num) * int32_t(16)))
                ->append(u" messages, got "_j)
                ->append(totalmsgs)->toString());
            pass = false;
            stepDone(FAILURE());
        }
    }
    if(pass) {
        stepDone(SUCCESS());
    } else {
        stepDone(FAILURE());
    }
    sectionDone();
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest::testBasic()
{
    sectionStart(u"Basic Test"_j);
    stepStart(u"Creating Channel"_j);
    auto creator = npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES);
    auto id = new ::rice::p2p::splitstream::ChannelId(generateId());
    npc((*ssclients)[creator])->createChannel(id);
    simulate();
    stepDone(SUCCESS());
    stepStart(u"Attaching and Joining Stripes"_j);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        npc((*ssclients)[i])->attachChannel(id);
        simulate();
    }
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        npc((*ssclients)[i])->getStripes();
        simulate();
    }
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        npc((*ssclients)[i])->subscribeStripes();
        simulate();
    }
    if(checkTree(0, NUM_NODES))
        stepDone(SUCCESS());
    else
        stepDone(FAILURE(), u"not all stripes have a parent"_j);
    stepStart(u"Sending Data"_j);
    auto data = (new ::int8_tArray({
        static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(1))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(1))
        , static_cast< int8_t >(int32_t(1))
    }));
    npc((*ssclients)[creator])->publishAll(data);
    simulate();
    npc((*ssclients)[creator])->publishAll(new ::int8_tArray(int32_t(0)));
    simulate();
    auto totalmsgs = int32_t(0);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        totalmsgs = totalmsgs + npc((*ssclients)[i])->getNumMesgs();
        npc((*ssclients)[i])->reset();
    }
    if(totalmsgs == (NUM_NODES * int32_t(16) * int32_t(2))) {
        stepDone(SUCCESS());
    } else {
        stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected "_j)->append((NUM_NODES * int32_t(16) * int32_t(2)))
            ->append(u" messages, got "_j)
            ->append(totalmsgs)->toString());
    }
    sectionDone();
    testFailure(1);
}

bool rice::p2p::splitstream::testing::SplitStreamRegrTest::checkTree(int32_t startindex, int32_t num)
{
    ::rice::p2p::splitstream::StripeArray* stripes;
    auto result = true;
    for (auto i = startindex; i < num; i++) {
        stripes = npc((*ssclients)[i])->getStripes();
        for (auto j = int32_t(0); j < npc(stripes)->length; j++) {
            if(npc((*stripes)[j])->getParent() == nullptr && !npc((*stripes)[j])->isRoot()) {
                result = false;
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(npc((*ssclients)[i])->getId()))
                    ->append(u" is parentless for topic "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(npc((*stripes)[j])->getStripeId())->getId()))->toString());
            }
        }
    }
    return result;
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest::testFailure(int32_t numnodes)
{
    sectionStart(u"Failure Test"_j);
    sectionDone();
}

rice::p2p::commonapi::Id* rice::p2p::splitstream::testing::SplitStreamRegrTest::generateId()
{
    auto data = new ::int8_tArray(int32_t(20));
    npc(npc(environment)->getRandomSource())->nextBytes(data);
    return npc(FACTORY)->buildId(data);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.testing.SplitStreamRegrTest", 48);
    return c;
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        INSTANCE_ = u"SplitStreamRegrTest"_j;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamRegrTest::getClass0()
{
    return class_();
}

