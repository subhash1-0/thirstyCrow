// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java
#include <rice/p2p/scribe/testing/ScribeRegrTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Observer.hpp>
#include <rice/Destructable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/scribe/BaseScribe.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/ScribeImpl.hpp>
#include <rice/p2p/scribe/ScribePolicy_DefaultScribePolicy.hpp>
#include <rice/p2p/scribe/ScribePolicy.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/scribe/javaserialized/JavaScribe.hpp>
#include <rice/p2p/scribe/maintenance/MaintainableScribe.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribe.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>
#include <rice/p2p/scribe/testing/ScribeRegrTest_TestScribeClient.hpp>
#include <rice/p2p/scribe/testing/ScribeRegrTest_TestScribeContent.hpp>
#include <rice/p2p/scribe/testing/ScribeRegrTest_TestScribePolicy.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
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
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
typedef ::SubArray< ::rice::Destructable, ::java::lang::ObjectArray > DestructableArray;

    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Application, ::java::lang::ObjectArray > ApplicationArray;
typedef ::SubArray< ::rice::p2p::commonapi::Node, ::java::lang::ObjectArray > NodeArray;
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::BaseScribe, ::java::lang::ObjectArray, ::rice::DestructableArray > BaseScribeArray;

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::scribe::rawserialization::RawScribe, ::java::lang::ObjectArray, ::rice::p2p::scribe::BaseScribeArray > RawScribeArray;
            } // rawserialization

            namespace javaserialized
            {
typedef ::SubArray< ::rice::p2p::scribe::javaserialized::JavaScribe, ::java::lang::ObjectArray, ::rice::p2p::scribe::BaseScribeArray > JavaScribeArray;
            } // javaserialized
typedef ::SubArray< ::rice::p2p::scribe::Scribe, ::java::lang::ObjectArray, ::rice::p2p::scribe::rawserialization::RawScribeArray, ::rice::p2p::scribe::javaserialized::JavaScribeArray > ScribeArray;
typedef ::SubArray< ::rice::p2p::scribe::ScribeClient, ::java::lang::ObjectArray > ScribeClientArray;

            namespace maintenance
            {
typedef ::SubArray< ::rice::p2p::scribe::maintenance::MaintainableScribe, ::java::lang::ObjectArray, ::rice::p2p::scribe::BaseScribeArray > MaintainableScribeArray;
            } // maintenance
typedef ::SubArray< ::rice::p2p::scribe::ScribeImpl, ::java::lang::ObjectArray, ScribeArray, ::rice::p2p::scribe::maintenance::MaintainableScribeArray, ::rice::p2p::commonapi::ApplicationArray, ::java::util::ObserverArray > ScribeImplArray;
typedef ::SubArray< ::rice::p2p::scribe::ScribePolicy, ::java::lang::ObjectArray > ScribePolicyArray;
typedef ::SubArray< ::rice::p2p::scribe::ScribePolicy_DefaultScribePolicy, ::java::lang::ObjectArray, ScribePolicyArray > ScribePolicy_DefaultScribePolicyArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient, ::java::lang::ObjectArray, ::rice::p2p::scribe::ScribeClientArray > ScribeRegrTest_TestScribeClientArray;
typedef ::SubArray< ::rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy, ::rice::p2p::scribe::ScribePolicy_DefaultScribePolicyArray > ScribeRegrTest_TestScribePolicyArray;
            } // testing
        } // scribe
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
rice::p2p::scribe::testing::ScribeRegrTest::ScribeRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::testing::ScribeRegrTest::ScribeRegrTest(::rice::environment::Environment* env)  /* throws(IOException) */
    : ScribeRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

java::lang::String*& rice::p2p::scribe::testing::ScribeRegrTest::INSTANCE()
{
    clinit();
    return INSTANCE_;
}
java::lang::String* rice::p2p::scribe::testing::ScribeRegrTest::INSTANCE_;

void rice::p2p::scribe::testing::ScribeRegrTest::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(env);
    scribes = new ::rice::p2p::scribe::ScribeImplArray(NUM_NODES + int32_t(1));
    policies = new ScribeRegrTest_TestScribePolicyArray(NUM_NODES + int32_t(1));
}

rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent* rice::p2p::scribe::testing::ScribeRegrTest::buildTestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t numMessages)
{
    return new ScribeRegrTest_TestScribeContent(topic, numMessages);
}

void rice::p2p::scribe::testing::ScribeRegrTest::setupParams(::rice::environment::Environment* env)
{
    super::setupParams(env);
    npc(npc(env)->getParameters())->setInt(u"p2p_scribe_message_timeout"_j, 3000);
}

void rice::p2p::scribe::testing::ScribeRegrTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto env = parseArgs(args);
    auto scribeTest = new ScribeRegrTest(env);
    npc(scribeTest)->start();
    npc(env)->destroy();
}

void rice::p2p::scribe::testing::ScribeRegrTest::processNode(int32_t num, ::rice::p2p::commonapi::Node* node)
{
    scribes->set(num, new ::rice::p2p::scribe::ScribeImpl(node, INSTANCE_));
    policies->set(num, new ScribeRegrTest_TestScribePolicy(this, (*scribes)[num]));
    npc((*scribes)[num])->setPolicy(static_cast< ::rice::p2p::scribe::ScribePolicy* >((*policies)[num]));
}

void rice::p2p::scribe::testing::ScribeRegrTest::runTest()
{
    if(NUM_NODES < 2) {
        npc(::java::lang::System::out())->println(u"The DistScribeRegrTest must be run with at least 2 nodes for proper testing.  Use the '-nodes n' to specify the number of nodes."_j);
        return;
    }
    testBasic(1, u"Basic"_j);
    testBasic(2, u"Partial (1)"_j);
    testBasic(4, u"Partial (2)"_j);
    testMultiSubscribe(1, u"Basic"_j);
    testSingleRoot(u"Single rooted Trees"_j);
    testAPI();
    testFailureNotification();
    testAddNode();
    testMaintenance();
}

void rice::p2p::scribe::testing::ScribeRegrTest::testAddNode()
{
    auto name = u"TestAddNode"_j;
    auto topic = new ::rice::p2p::scribe::Topic(generateId());
    auto id = npc(topic)->getId();
    auto clients = new ScribeRegrTest_TestScribeClientArray(NUM_NODES);
    sectionStart(u"Test Add Node"_j);
    stepStart(::java::lang::StringBuilder().append(u"Tree Construction id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        clients->set(i, new ScribeRegrTest_TestScribeClient(this, static_cast< ::rice::p2p::scribe::Scribe* >((*scribes)[i]), topic, i));
        npc((*scribes)[i])->subscribe(topic, static_cast< ::rice::p2p::scribe::ScribeClient* >((*clients)[i]));
        simulate();
    }
    stepDone(SUCCESS());
    stepStart(u"Add New Root"_j);
    auto pn = npc(factory)->newNode(getBootstrap(), java_cast< ::rice::pastry::Id* >(id));
    nodes->set(NUM_NODES, pn);
    processNode(NUM_NODES, static_cast< ::rice::p2p::commonapi::Node* >(pn));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Adding new root: "_j)->append(static_cast< ::java::lang::Object* >(pn))->toString());

    {
        synchronized synchronized_0((*nodes)[NUM_NODES]);
        {
            while (!npc(pn)->isReady()) {
                try {
                    npc(pn)->wait(1000);
                } catch (::java::lang::InterruptedException* ie) {
                    return;
                }
            }
        }
    }
    auto children = npc((*scribes)[NUM_NODES])->getChildrenOfTopic(topic);
    if(npc(children)->size() >= 1) {
        stepDone(SUCCESS());
    } else {
        stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Node should be the root, has "_j)->append(npc(children)->size())
            ->append(u" children for topic "_j)
            ->append(static_cast< ::java::lang::Object* >(topic))
            ->append(u"."_j)->toString());
    }
    sectionDone();
}

void rice::p2p::scribe::testing::ScribeRegrTest::testBasic(int32_t skip, ::java::lang::String* name)
{
    sectionStart(::java::lang::StringBuilder().append(name)->append(u" Scribe Networks"_j)->toString());
    auto NUM_MESSAGES = int32_t(5);
    auto SKIP = skip;
    auto topic = new ::rice::p2p::scribe::Topic(generateId());
    auto clients = new ScribeRegrTest_TestScribeClientArray(NUM_NODES / SKIP);
    stepStart(::java::lang::StringBuilder().append(name)->append(u" Tree Construction"_j)->toString());
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        clients->set(i, new ScribeRegrTest_TestScribeClient(this, static_cast< ::rice::p2p::scribe::Scribe* >((*scribes)[i]), topic, i));
        npc((*scribes)[i])->subscribe(topic, static_cast< ::rice::p2p::scribe::ScribeClient* >((*clients)[i]));
        simulate();
    }
    simulate(NUM_NODES / SKIP);
    auto numWithParent = int32_t(0);
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        if(npc((*scribes)[i])->getParent(topic) != nullptr)
            numWithParent++;

    }
    if(numWithParent < (NUM_NODES / SKIP) - int32_t(1))
        stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected at least "_j)->append((NUM_NODES / SKIP - int32_t(1)))
            ->append(u" nodes with parents, found "_j)
            ->append(numWithParent)->toString());
    else
        stepDone(SUCCESS());
    stepStart(::java::lang::StringBuilder().append(name)->append(u" Publish"_j)->toString());
    auto local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES / SKIP)];
    for (auto i = int32_t(0); i < NUM_MESSAGES; i++) {
        npc(local)->publish(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, i)));
        simulate();
    }
    auto failed = false;
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        if(npc(npc((*clients)[i])->getPublishMessages())->size() != NUM_MESSAGES) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected client "_j)->append(static_cast< ::java::lang::Object* >((*clients)[i]))
                ->append(u" to receive all "_j)
                ->append(NUM_MESSAGES)
                ->append(u" messages, received "_j)
                ->append(npc(npc((*clients)[i])->getPublishMessages())->size())->toString());
            failed = true;
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    stepStart(::java::lang::StringBuilder().append(name)->append(u" Anycast - No Accept"_j)->toString());
    local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    npc(local)->anycast(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, 59)));
    simulate(NUM_NODES);
    failed = false;
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        if(npc(npc((*clients)[i])->getAnycastMessages())->size() != 0) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected no accepters for anycast, found one at "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))->toString());
            failed = true;
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    stepStart(::java::lang::StringBuilder().append(name)->append(u" Anycast - 1 Accept"_j)->toString());
    auto client = (*clients)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES / SKIP)];
    npc(client)->acceptAnycast(true);
    local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    npc(local)->anycast(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, 60)));
    simulate(NUM_NODES);
    failed = false;
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        if(npc((*clients)[i])->equals(client)) {
            if(npc(npc((*clients)[i])->getAnycastMessages())->size() != 1) {
                auto s = u""_j;
                for (auto _i = npc(npc((*clients)[i])->getAnycastMessages())->iterator(); _i->hasNext(); ) {
                    ::rice::p2p::scribe::ScribeContent* item = java_cast< ::rice::p2p::scribe::ScribeContent* >(_i->next());
                    {
                        s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" "_j)->append(static_cast< ::java::lang::Object* >(item))->toString())->toString();
                    }
                }
                stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected node "_j)->append(static_cast< ::java::lang::Object* >(npc(client)->scribe))
                    ->append(u" to accept anycast at "_j)
                    ->append(static_cast< ::java::lang::Object* >(client))
                    ->append(u" accepted "_j)
                    ->append(npc(npc((*clients)[i])->getAnycastMessages())->size())
                    ->append(u" local "_j)
                    ->append(static_cast< ::java::lang::Object* >(local))
                    ->append(u" "_j)
                    ->append(s)->toString());
                failed = true;
            }
        } else {
            if(npc(npc((*clients)[i])->getAnycastMessages())->size() != 0) {
                stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected no accepters for anycast, found one at "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))->toString());
                failed = true;
            }
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    stepStart(::java::lang::StringBuilder().append(name)->append(u" Anycast - All Accept"_j)->toString());
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        npc((*clients)[i])->acceptAnycast(true);
    }
    local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES / SKIP)];
    npc(local)->anycast(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, 61)));
    simulate(NUM_NODES);
    auto total = int32_t(0);
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        total += npc(npc((*clients)[i])->getAnycastMessages())->size();
    }
    if(total != 2) {
        auto str = u""_j;
        for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
            if(npc(npc((*clients)[i])->getAnycastMessages())->size() != 0) {
                for (auto _i = npc(npc((*clients)[i])->getAnycastMessages())->iterator(); _i->hasNext(); ) {
                    ::rice::p2p::scribe::ScribeContent* sc = java_cast< ::rice::p2p::scribe::ScribeContent* >(_i->next());
                    {
                        str = ::java::lang::StringBuilder(str).append(::java::lang::StringBuilder().append(u"\n"_j)->append(static_cast< ::java::lang::Object* >((*clients)[i]))
                            ->append(u" "_j)
                            ->append(static_cast< ::java::lang::Object* >(sc))->toString())->toString();
                    }
                }
            }
        }
        stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected 2 anycast messages to be found, found "_j)->append(total)
            ->append(u" l:"_j)
            ->append(str)->toString());
    } else {
        stepDone(SUCCESS());
    }
    stepStart(::java::lang::StringBuilder().append(name)->append(u" Unsubscribe"_j)->toString());
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        npc((*scribes)[i])->unsubscribe(topic, static_cast< ::rice::p2p::scribe::ScribeClient* >((*clients)[i]));
        simulate();
    }
    local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    npc(local)->publish(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, 100)));
    simulate(NUM_NODES);
    failed = false;
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        if(npc(npc((*clients)[i])->getPublishMessages())->size() != NUM_MESSAGES) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected client "_j)->append(static_cast< ::java::lang::Object* >((*clients)[i]))
                ->append(u" to receive no additional messages, received "_j)
                ->append(npc(npc((*clients)[i])->getPublishMessages())->size())->toString());
            failed = true;
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    stepStart(::java::lang::StringBuilder().append(name)->append(u" Tree Completely Demolished"_j)->toString());
    failed = false;
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        if(npc(npc((*scribes)[i])->getClients(topic))->size() > 0) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected scribe "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))
                ->append(u" to have no clients, had "_j)
                ->append(npc(npc((*scribes)[i])->getClients(topic))->size())->toString());
            failed = true;
        }
        if(npc(npc((*scribes)[i])->getChildren(topic))->length > 0) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected scribe "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))
                ->append(u" to have no children, had "_j)
                ->append(npc(npc((*scribes)[i])->getChildren(topic))->length)->toString());
            failed = true;
        }
        if(npc((*scribes)[i])->getParent(topic) != nullptr) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected scribe "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))
                ->append(u" to have no parent, had "_j)
                ->append(static_cast< ::java::lang::Object* >(npc((*scribes)[i])->getParent(topic)))->toString());
            failed = true;
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    sectionDone();
}

void rice::p2p::scribe::testing::ScribeRegrTest::testMultiSubscribe(int32_t skip, ::java::lang::String* name)
{
    sectionStart(::java::lang::StringBuilder().append(name)->append(u" MultiSubscription Scribe Network"_j)->toString());
    auto NUM_MESSAGES = int32_t(5);
    auto SKIP = skip;
    auto NUM_TOPICS = int32_t(2);
    auto clients = new ScribeRegrTest_TestScribeClientArray(NUM_NODES);
    ::java::util::List* topics = new ::java::util::ArrayList(NUM_TOPICS);
    auto id1 = (new ::int32_tArray({
        int32_t(0)
        , int32_t(0)
        , int32_t(0)
        , int32_t(0)
        , int32_t(-0x7fffffff-1)
    }));
    auto id2 = (new ::int32_tArray({
        int32_t(0)
        , int32_t(0)
        , int32_t(0)
        , int32_t(0)
        , int32_t(0)
    }));
    npc(topics)->add(static_cast< ::java::lang::Object* >(new ::rice::p2p::scribe::Topic(npc(FACTORY)->buildId(id1))));
    npc(topics)->add(static_cast< ::java::lang::Object* >(new ::rice::p2p::scribe::Topic(npc(FACTORY)->buildId(id2))));
    stepStart(::java::lang::StringBuilder().append(name)->append(u" Tree Construction (Parent Independence)"_j)->toString());
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        clients->set(i, new ScribeRegrTest_TestScribeClient(this, static_cast< ::rice::p2p::scribe::Scribe* >((*scribes)[i]), topics, i));
        npc((*scribes)[i])->subscribe(static_cast< ::java::util::Collection* >(topics), static_cast< ::rice::p2p::scribe::ScribeClient* >((*clients)[i]), static_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(nullptr), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
        simulate();
    }
    auto numWithParent = int32_t(0);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        if(npc((*scribes)[i])->getParent(java_cast< ::rice::p2p::scribe::Topic* >(npc(topics)->get(0))) == npc((*scribes)[i])->getParent(java_cast< ::rice::p2p::scribe::Topic* >(npc(topics)->get(1)))) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Topics "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::scribe::Topic* >(npc(topics)->get(0))))
                ->append(u" and "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::scribe::Topic* >(npc(topics)->get(1))))
                ->append(u" had same parent "_j)
                ->append(static_cast< ::java::lang::Object* >(npc((*scribes)[i])->getParent(java_cast< ::rice::p2p::scribe::Topic* >(npc(topics)->get(0)))))
                ->append(u" on node "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(npc((*scribes)[i])->getEndpoint())->getLocalNodeHandle()))->toString());
        }
    }
    stepDone(SUCCESS());
    stepStart(::java::lang::StringBuilder().append(name)->append(u" Publish"_j)->toString());
    auto local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES / SKIP)];
    for (auto i = int32_t(0); i < NUM_MESSAGES; i++) {
        for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
            ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
            {
                npc(local)->publish(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, i)));
            }
        }
        simulate();
    }
    auto failed = false;
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        if(npc(npc((*clients)[i])->getPublishMessages())->size() != NUM_MESSAGES * NUM_TOPICS) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(::java::lang::StringBuilder().append(::java::lang::StringBuilder().append(u"Expected client "_j)->append(static_cast< ::java::lang::Object* >((*clients)[i]))
                ->append(u" to receive all "_j)
                ->append(NUM_MESSAGES * NUM_TOPICS)->toString())->append(u" messages, received "_j)->toString())->append(npc(npc((*clients)[i])->getPublishMessages())->size())->toString());
            failed = true;
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    stepStart(::java::lang::StringBuilder().append(name)->append(u" Anycast - No Accept"_j)->toString());
    local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
        
                        npc(local)->anycast(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, 62)));

    }
    simulate(NUM_NODES * NUM_TOPICS);
    failed = false;
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        if(npc(npc((*clients)[i])->getAnycastMessages())->size() != 0) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected no accepters for anycast, found one at "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))->toString());
            failed = true;
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    stepStart(::java::lang::StringBuilder().append(name)->append(u" Anycast - 1 Accept"_j)->toString());
    auto client = (*clients)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES / SKIP)];
    npc(client)->acceptAnycast(true);
    local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
        
                        npc(local)->anycast(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, 63)));

    }
    simulate(NUM_NODES * NUM_TOPICS);
    failed = false;
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        if(npc((*clients)[i])->equals(client)) {
            if(npc(npc((*clients)[i])->getAnycastMessages())->size() != NUM_TOPICS) {
                auto s = u""_j;
                for (auto _i = npc(npc((*clients)[i])->getAnycastMessages())->iterator(); _i->hasNext(); ) {
                    ::rice::p2p::scribe::ScribeContent* item = java_cast< ::rice::p2p::scribe::ScribeContent* >(_i->next());
                    {
                        s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" "_j)->append(static_cast< ::java::lang::Object* >(item))->toString())->toString();
                    }
                }
                stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected node to accept "_j)->append(NUM_TOPICS)
                    ->append(u" anycasts at "_j)
                    ->append(static_cast< ::java::lang::Object* >(client))
                    ->append(u" accepted "_j)
                    ->append(npc(npc((*clients)[i])->getAnycastMessages())->size())
                    ->append(u" local "_j)
                    ->append(static_cast< ::java::lang::Object* >(local))
                    ->append(u" "_j)
                    ->append(s)->toString());
                failed = true;
            }
        } else {
            if(npc(npc((*clients)[i])->getAnycastMessages())->size() != 0) {
                stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected no accepters for anycast, found one at "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))->toString());
                failed = true;
            }
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    stepStart(::java::lang::StringBuilder().append(name)->append(u" Anycast - All Accept"_j)->toString());
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        npc((*clients)[i])->acceptAnycast(true);
    }
    local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES / SKIP)];
    for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
        
                        npc(local)->anycast(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, 64)));

    }
    simulate(NUM_TOPICS);
    auto total = int32_t(0);
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        total += npc(npc((*clients)[i])->getAnycastMessages())->size();
    }
    if(total != NUM_TOPICS * int32_t(2)) {
        auto str = u""_j;
        for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
            if(npc(npc((*clients)[i])->getAnycastMessages())->size() != 0) {
                for (auto _i = npc(npc((*clients)[i])->getAnycastMessages())->iterator(); _i->hasNext(); ) {
                    ::rice::p2p::scribe::ScribeContent* sc = java_cast< ::rice::p2p::scribe::ScribeContent* >(_i->next());
                    {
                        str = ::java::lang::StringBuilder(str).append(::java::lang::StringBuilder().append(u"\n"_j)->append(static_cast< ::java::lang::Object* >((*clients)[i]))
                            ->append(u" "_j)
                            ->append(static_cast< ::java::lang::Object* >(sc))->toString())->toString();
                    }
                }
            }
        }
        stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected "_j)->append((NUM_TOPICS * int32_t(2)))
            ->append(u" anycast messages to be found, found "_j)
            ->append(total)
            ->append(u" l:"_j)
            ->append(str)->toString());
    } else {
        stepDone(SUCCESS());
    }
    stepStart(::java::lang::StringBuilder().append(name)->append(u" Unsubscribe"_j)->toString());
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
            ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
            {
                npc((*scribes)[i])->unsubscribe(topic, static_cast< ::rice::p2p::scribe::ScribeClient* >((*clients)[i]));
            }
        }
        simulate();
    }
    local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
        
                        npc(local)->publish(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, 100)));

    }
    simulate();
    failed = false;
    for (auto i = int32_t(0); i < NUM_NODES / SKIP; i++) {
        if(npc(npc((*clients)[i])->getPublishMessages())->size() != NUM_MESSAGES * NUM_TOPICS) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected client "_j)->append(static_cast< ::java::lang::Object* >((*clients)[i]))
                ->append(u" to receive no additional messages, received "_j)
                ->append(npc(npc((*clients)[i])->getPublishMessages())->size())->toString());
            failed = true;
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    stepStart(::java::lang::StringBuilder().append(name)->append(u" Tree Completely Demolished"_j)->toString());
    failed = false;
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
            ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
            {
                if(npc(npc((*scribes)[i])->getClients(topic))->size() > 0) {
                    stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected scribe "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))
                        ->append(u" to have no clients, had "_j)
                        ->append(npc(npc((*scribes)[i])->getClients(topic))->size())->toString());
                    failed = true;
                }
                if(npc(npc((*scribes)[i])->getChildren(topic))->length > 0) {
                    stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected scribe "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))
                        ->append(u" to have no children, had "_j)
                        ->append(npc(npc((*scribes)[i])->getChildren(topic))->length)->toString());
                    failed = true;
                }
                if(npc((*scribes)[i])->getParent(topic) != nullptr) {
                    stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected scribe "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))
                        ->append(u" to have no parent, had "_j)
                        ->append(static_cast< ::java::lang::Object* >(npc((*scribes)[i])->getParent(topic)))->toString());
                    failed = true;
                }
            }
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    sectionDone();
}

void rice::p2p::scribe::testing::ScribeRegrTest::testAPI()
{
    sectionStart(u"Scribe API Functionality"_j);
    auto NUM_MESSAGES = int32_t(5);
    auto topic = new ::rice::p2p::scribe::Topic(generateId());
    auto clients = new ScribeRegrTest_TestScribeClientArray(NUM_NODES);
    stepStart(u"Tree Construction"_j);
    for (auto i = int32_t(0); i < NUM_NODES; i++) 
                npc((*policies)[i])->allowSubscribe(false);

    for (auto i = int32_t(0); i < NUM_NODES / int32_t(2); i++) {
        clients->set(i, new ScribeRegrTest_TestScribeClient(this, static_cast< ::rice::p2p::scribe::Scribe* >((*scribes)[i]), topic, i));
        npc((*scribes)[i])->subscribe(topic, static_cast< ::rice::p2p::scribe::ScribeClient* >((*clients)[i]));
        simulate();
    }
    simulate(NUM_NODES);
    auto numWithParent = int32_t(0);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        if(npc((*scribes)[i])->getParent(topic) != nullptr)
            numWithParent++;

    }
    if(numWithParent < (NUM_NODES / int32_t(2)) - int32_t(1)) {
        auto s = u""_j;
        for (auto i = int32_t(0); i < NUM_NODES; i++) {
            if(npc((*scribes)[i])->getParent(topic) == nullptr) {
                s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" "_j)->append(static_cast< ::java::lang::Object* >((*scribes)[i]))->toString())->toString();
            }
        }
        stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected at least "_j)->append((NUM_NODES / int32_t(2) - int32_t(1)))
            ->append(u" nodes with parents, found "_j)
            ->append(numWithParent)
            ->append(u" "_j)
            ->append(s)->toString());
    } else if(numWithParent > (NUM_NODES / int32_t(2)))
        stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected no more than "_j)->append((NUM_NODES / int32_t(2)))
            ->append(u" nodes with parents, due to policy, found "_j)
            ->append(numWithParent)->toString());
    else
        stepDone(SUCCESS());
    stepStart(u"Drop Child"_j);
    ::rice::p2p::scribe::ScribeImpl* scribe = nullptr;
    ScribeRegrTest_TestScribeClient* client = nullptr;
    ScribeRegrTest_TestScribePolicy* policy = nullptr;
    for (auto i = int32_t(0); (i < NUM_NODES) && (scribe == nullptr); i++) {
        if(npc(npc((*scribes)[i])->getChildren(topic))->length > 0) {
            scribe = (*scribes)[i];
            client = (*clients)[i];
            policy = (*policies)[i];
        }
    }
    if(scribe == nullptr) {
        stepDone(FAILURE(), u"Could not find any scribes with children"_j);
    } else {
        auto child = (*npc(scribe)->getChildren(topic))[int32_t(0)];
        npc(policy)->neverAllowSubscribe(true);
        npc(scribe)->removeChild(topic, child);
        simulate();
        auto local = (*scribes)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
        for (auto i = int32_t(0); i < NUM_MESSAGES; i++) {
            npc(local)->publish(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, i)));
            simulate();
        }
        auto failed = false;
        for (auto i = int32_t(0); i < NUM_NODES / int32_t(2); i++) {
            if(npc(npc((*clients)[i])->getPublishMessages())->size() != NUM_MESSAGES) {
                stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected client "_j)->append(static_cast< ::java::lang::Object* >((*clients)[i]))
                    ->append(u" to receive all "_j)
                    ->append(NUM_MESSAGES)
                    ->append(u" messages, received "_j)
                    ->append(npc(npc((*clients)[i])->getPublishMessages())->size())->toString());
                failed = true;
            }
        }
        auto children = npc(scribe)->getChildren(topic);
        if(npc(::java::util::Arrays::asList(children))->contains(static_cast< ::java::lang::Object* >(child))) {
            stepDone(FAILURE(), u"Child resubscribed to previous node, policy should prevent this."_j);
            failed = true;
        }
        if(!failed)
            stepDone(SUCCESS());

    }
    stepStart(u"Reset Policies"_j);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        npc((*policies)[i])->allowSubscribe(true);
        npc((*policies)[i])->neverAllowSubscribe(false);
    }
    stepDone(SUCCESS());
    sectionDone();
}

void rice::p2p::scribe::testing::ScribeRegrTest::testFailureNotification()
{
    sectionStart(u"Subscribe Failure Notification"_j);
    auto topic = new ::rice::p2p::scribe::Topic(generateId());
    ScribeRegrTest_TestScribeClient* client;
    stepStart(u"Policy Change"_j);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        npc((*policies)[i])->neverAllowSubscribe(true);
    }
    stepDone(SUCCESS());
    stepStart(u"Subscribe Attempt"_j);
    auto i = npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES - int32_t(1));
    while (npc((*scribes)[i])->isRoot(topic)) 
                i = npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES - int32_t(1));

    client = new ScribeRegrTest_TestScribeClient(this, static_cast< ::rice::p2p::scribe::Scribe* >((*scribes)[i]), topic, i);
    npc((*scribes)[i])->subscribe(topic, static_cast< ::rice::p2p::scribe::ScribeClient* >(client));
    simulate();
    stepDone(SUCCESS());
    stepStart(u"Failure Notification Delivered"_j);
    if(!npc(client)->getSubscribeFailed())
        stepDone(FAILURE(), u"Expected subscribe to fail, but did not."_j);
    else
        stepDone(SUCCESS());
    stepStart(u"Policy Reset"_j);
    for (auto j = int32_t(0); j < NUM_NODES; j++) {
        npc((*policies)[j])->neverAllowSubscribe(false);
    }
    stepDone(SUCCESS());
    sectionDone();
}

void rice::p2p::scribe::testing::ScribeRegrTest::testSingleRoot(::java::lang::String* name)
{
    sectionStart(::java::lang::StringBuilder().append(name)->append(u""_j)->toString());
    auto numTrees = int32_t(10);
    auto failed = false;
    for (auto num = int32_t(0); num < numTrees; num++) {
        auto topic = new ::rice::p2p::scribe::Topic(generateId());
        auto clients = new ScribeRegrTest_TestScribeClientArray(NUM_NODES);
        stepStart(::java::lang::StringBuilder().append(name)->append(u" TopicId="_j)
            ->append(static_cast< ::java::lang::Object* >(npc(topic)->getId()))->toString());
        for (auto i = int32_t(0); i < NUM_NODES; i++) {
            clients->set(i, new ScribeRegrTest_TestScribeClient(this, static_cast< ::rice::p2p::scribe::Scribe* >((*scribes)[i]), topic, i));
            npc((*scribes)[i])->subscribe(topic, static_cast< ::rice::p2p::scribe::ScribeClient* >((*clients)[i]));
            simulate();
        }
        auto numRoot = int32_t(0);
        for (auto i = int32_t(0); i < NUM_NODES; i++) {
            if(npc((*scribes)[i])->isRoot(topic)) {
                numRoot++;
            }
        }
        if(numRoot != 1) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Number of roots= "_j)->append(numRoot)->toString());
            failed = true;
        } else
            stepDone(SUCCESS());
    }
    sectionDone();
}

void rice::p2p::scribe::testing::ScribeRegrTest::testMaintenance()
{
    sectionStart(u"Tree Maintenance Under Node Death"_j);
    auto NUM_MESSAGES = int32_t(5);
    auto topic = new ::rice::p2p::scribe::Topic(generateId());
    auto clients = new ScribeRegrTest_TestScribeClientArray(NUM_NODES);
    stepStart(u"Tree Construction"_j);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        clients->set(i, new ScribeRegrTest_TestScribeClient(this, static_cast< ::rice::p2p::scribe::Scribe* >((*scribes)[i]), topic, i));
        npc((*scribes)[i])->subscribe(topic, static_cast< ::rice::p2p::scribe::ScribeClient* >((*clients)[i]));
        simulate();
    }
    simulate(NUM_NODES);
    auto numWithParent = int32_t(0);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        if(npc((*scribes)[i])->getParent(topic) != nullptr)
            numWithParent++;

    }
    if(numWithParent < NUM_NODES - int32_t(1))
        stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected at least "_j)->append((NUM_NODES - int32_t(1)))
            ->append(u" nodes with parents, found "_j)
            ->append(numWithParent)->toString());
    else
        stepDone(SUCCESS());
    stepStart(u"Killing Nodes"_j);
    for (auto i = int32_t(0); i < NUM_NODES / int32_t(2); i++) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Killing "_j)->append(static_cast< ::java::lang::Object* >((*nodes)[i]))->toString());

        npc((*scribes)[i])->destroy();
        kill(i);
        simulate(5);
    }
    waitToRecoverFromKilling(npc((*scribes)[int32_t(0)])->MESSAGE_TIMEOUT);
    stepDone(SUCCESS());
    stepStart(u"Tree Recovery"_j);
    auto localIndex = npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES / int32_t(2)) + NUM_NODES / int32_t(2);
    auto local = (*scribes)[localIndex];
    for (auto i = int32_t(0); i < NUM_MESSAGES; i++) {
        npc(local)->publish(topic, static_cast< ::rice::p2p::scribe::ScribeContent* >(buildTestScribeContent(topic, i)));
        simulate(5);
    }
    auto failed = false;
    for (auto i = NUM_NODES / int32_t(2); i < NUM_NODES; i++) {
        if(npc(npc((*clients)[i])->getPublishMessages())->size() != NUM_MESSAGES) {
            stepDone(FAILURE(), ::java::lang::StringBuilder().append(u"Expected client "_j)->append(static_cast< ::java::lang::Object* >((*nodes)[i]))
                ->append(u":"_j)
                ->append(static_cast< ::java::lang::Object* >((*clients)[i]))
                ->append(u" to receive all "_j)
                ->append(NUM_MESSAGES)
                ->append(u" messages, received "_j)
                ->append(npc(npc((*clients)[i])->getPublishMessages())->size())->toString());
            failed = true;
        }
    }
    if(!failed)
        stepDone(SUCCESS());

    sectionDone();
}

rice::p2p::commonapi::Id* rice::p2p::scribe::testing::ScribeRegrTest::generateId()
{
    auto data = new ::int8_tArray(int32_t(20));
    npc(npc(environment)->getRandomSource())->nextBytes(data);
    return npc(FACTORY)->buildId(data);
}

java::util::List* rice::p2p::scribe::testing::ScribeRegrTest::buildListOf1(::rice::p2p::scribe::Topic* topic)
{
    clinit();
    ::java::util::List* ret = new ::java::util::ArrayList(int32_t(1));
    npc(ret)->add(static_cast< ::java::lang::Object* >(topic));
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.testing.ScribeRegrTest", 38);
    return c;
}

void rice::p2p::scribe::testing::ScribeRegrTest::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        INSTANCE_ = u"ScribeRegrTest"_j;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest::getClass0()
{
    return class_();
}

