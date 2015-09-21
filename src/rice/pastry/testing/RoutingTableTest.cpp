// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeImpl.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/pastry/direct/DirectNodeHandle.hpp>
#include <rice/pastry/direct/DirectPastryNode.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/EuclideanNetwork.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/routing/InitiateRouteSetMaintenance.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/Router.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/pastry/testing/RoutingTableTest_createNode_4.hpp>
#include <rice/pastry/testing/RoutingTableTest_createNode_5.hpp>
#include <rice/pastry/testing/RoutingTableTest_finishNode_6.hpp>
#include <rice/pastry/testing/RoutingTableTest_finishNode_7.hpp>
#include <rice/pastry/testing/RoutingTableTest_testLeafSets_8.hpp>
#include <rice/pastry/testing/RoutingTableTest_main_9.hpp>
#include <rice/pastry/testing/RoutingTableTest_startLoggerTask_1.hpp>
#include <rice/pastry/testing/RoutingTableTest_startLoggerTask_2.hpp>
#include <rice/pastry/testing/RoutingTableTest_createNode_3.hpp>
#include <rice/pastry/testing/RoutingTableTest_CreatorTimerTask.hpp>
#include <rice/pastry/testing/RoutingTableTest_MyApp.hpp>
#include <rice/pastry/testing/RoutingTableTest_TestScribeClient.hpp>
#include <rice/pastry/testing/RoutingTableTest_TestScribeContent.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
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
rice::pastry::testing::RoutingTableTest::RoutingTableTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::RoutingTableTest::RoutingTableTest(int32_t numNodes, int32_t meanSessionTime, bool useScribe, int32_t msgSendRate, int32_t rtMaintTime, int32_t tryNum, ::rice::environment::Environment* env)  /* throws(Exception) */
    : RoutingTableTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(numNodes,meanSessionTime,useScribe,msgSendRate,rtMaintTime,tryNum,env);
}

void rice::pastry::testing::RoutingTableTest::init()
{
    printLiveness = false;
    printLeafSets = false;
    nodes = new ::java::util::Vector();
    apps = new ::java::util::HashMap();
    timeToFindFaulty = int32_t(30000);
    reportRate = int32_t(60) * int32_t(1000);
    testTime = int32_t(60) * int32_t(1000) * int32_t(60)* int32_t(10);
    thePenalty = int32_t(0);
}

constexpr bool rice::pastry::testing::RoutingTableTest::logHeavy;

void rice::pastry::testing::RoutingTableTest::ctor(int32_t numNodes, int32_t meanSessionTime, bool useScribe, int32_t msgSendRate, int32_t rtMaintTime, int32_t tryNum, ::rice::environment::Environment* env) /* throws(Exception) */
{
    super::ctor();
    init();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"numNodes:"_j)->append(numNodes)
        ->append(u" meanSessionTime:"_j)
        ->append(meanSessionTime)
        ->append(u" scribe:"_j)
        ->append(useScribe)
        ->append(u" msgSendRate:"_j)
        ->append(msgSendRate)
        ->append(u" rtMaint:"_j)
        ->append(rtMaintTime)
        ->append(u" try:"_j)
        ->append(tryNum)->toString());
    this->env = env;
    this->numNodes = numNodes;
    this->meanSessionTime = meanSessionTime;
    this->useScribe = useScribe;
    this->msgSendRate = msgSendRate;
    this->rtMaintTime = rtMaintTime;
    this->tryNum = tryNum;
    idFactory = new ::rice::pastry::commonapi::PastryIdFactory(env);
    topic = new ::rice::p2p::scribe::Topic(npc(idFactory)->buildId(u"test"_j));
    nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    npc(npc(env)->getParameters())->setInt(u"pastry_direct_gtitm_max_overlay_size"_j, numNodes);
    npc(npc(env)->getParameters())->setString(u"pastry_direct_gtitm_matrix_file"_j, u"sample_10k"_j);
    factory = new ::rice::pastry::direct::DirectPastryNodeFactory(nidFactory, new ::rice::pastry::direct::EuclideanNetwork(env), env);
    createNodes();
}

void rice::pastry::testing::RoutingTableTest::startLoggerTask()
{
    npc(npc(npc(env)->getSelectorManager())->getTimer())->schedule(new RoutingTableTest_startLoggerTask_1(this), reportRate, reportRate);
    npc(npc(npc(env)->getSelectorManager())->getTimer())->schedule(new RoutingTableTest_startLoggerTask_2(this), testTime);
}

void rice::pastry::testing::RoutingTableTest::createNodes() /* throws(InterruptedException) */
{
    auto ctt = new RoutingTableTest_CreatorTimerTask(this);
    npc(npc(npc(env)->getSelectorManager())->getTimer())->schedule(ctt, 1000, 1000);
}

void rice::pastry::testing::RoutingTableTest::sendSomeMessages()
{
    auto appIterator = npc(npc(apps)->values())->iterator();
    while (npc(appIterator)->hasNext()) {
        auto app = java_cast< RoutingTableTest_MyApp* >(java_cast< ::java::lang::Object* >(npc(appIterator)->next()));
        ::rice::p2p::commonapi::Id* randId = npc(nidFactory)->generateNodeId();
        npc(app)->routeMyMsg(randId);
    }
}

void rice::pastry::testing::RoutingTableTest::sendSomeScribeMessages()
{
    auto appIterator = npc(npc(apps)->values())->iterator();
    while (npc(appIterator)->hasNext()) {
        auto app = java_cast< ::rice::p2p::scribe::Scribe* >(java_cast< ::java::lang::Object* >(npc(appIterator)->next()));
        npc(app)->publish(topic, new RoutingTableTest_TestScribeContent(topic, int32_t(0)));
    }
}

rice::pastry::PastryNode* rice::pastry::testing::RoutingTableTest::createNode() /* throws(InterruptedException, IOException) */
{
    ::rice::pastry::NodeHandle* bootHandle = nullptr;
    if(npc(nodes)->size() > 0) {
        ::rice::pastry::PastryNode* bootNode = nullptr;
        while (bootNode == nullptr || !npc(bootNode)->isReady()) {
            bootNode = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::rice::pastry::PastryNode* >(npc(nodes)->get(npc(npc(env)->getRandomSource())->nextInt(npc(nodes)->size()))));
            bootHandle = npc(bootNode)->getLocalHandle();
        }
    }
    auto const node = npc(factory)->newNode();
    npc(node)->addObserver(new RoutingTableTest_createNode_3(this));
    npc(node)->addDestructable(new RoutingTableTest_createNode_4(this, node));
    npc(node)->boot(static_cast< ::java::lang::Object* >(bootHandle));
    if(printLiveness)
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Creating "_j)->append(static_cast< ::java::lang::Object* >(node))->toString());

    {
        synchronized synchronized_0(node);
        {
            if(npc(node)->isReady()) {
                finishNode(node);
            } else {
                npc(node)->addObserver(new RoutingTableTest_createNode_5(this, node));
            }
        }
    }
    return node;
}

void rice::pastry::testing::RoutingTableTest::finishNode(::rice::pastry::PastryNode* node)
{
    npc(nodes)->add(static_cast< ::java::lang::Object* >(node));
    if((meanSessionTime > 0)) {
        npc(npc(npc(env)->getSelectorManager())->getTimer())->schedule(new RoutingTableTest_finishNode_6(this, node), int32_t(60) * int32_t(1000), int32_t(60) * int32_t(1000));
    }
    if(msgSendRate > 0) {
        if(useScribe) {
            ::rice::p2p::scribe::Scribe* app = new ::rice::p2p::scribe::ScribeImpl(node, u"test"_j);
            ::rice::p2p::scribe::ScribeClient* client = new RoutingTableTest_TestScribeClient(this, app, topic);
            npc(app)->subscribe(topic, client);
            npc(apps)->put(static_cast< ::java::lang::Object* >(node), static_cast< ::java::lang::Object* >(app));
        } else {
            auto app = new RoutingTableTest_MyApp(this, node);
            npc(apps)->put(static_cast< ::java::lang::Object* >(node), static_cast< ::java::lang::Object* >(app));
        }
        npc(npc(npc(env)->getSelectorManager())->getTimer())->schedule(new RoutingTableTest_finishNode_7(this), msgSendRate);
    }
    if(rtMaintTime > 0)
        npc(node)->scheduleMsg(new ::rice::pastry::routing::InitiateRouteSetMaintenance(), rtMaintTime * int32_t(1000), rtMaintTime * int32_t(1000));

    if(printLiveness)
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Finished creating new node("_j)->append(npc(nodes)->size())
            ->append(u") "_j)
            ->append(static_cast< ::java::lang::Object* >(node))
            ->append(u" at "_j)
            ->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());

}

void rice::pastry::testing::RoutingTableTest::testLeafSets()
{
    auto nds = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(nodes));
    ::java::util::Collections::sort(nds, new RoutingTableTest_testLeafSets_8(this));
    auto i = npc(nds)->iterator();
    while (npc(i)->hasNext()) {
        auto n = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(npc(n)->isReady())->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(n)->getLeafSet()))->toString());
    }
}

void rice::pastry::testing::RoutingTableTest::testRoutingTables(int32_t round)
{
    if(printLeafSets)
        testLeafSets();

    double streatch;
    int32_t holes;
    if(numNodes <= 1000) {
        streatch = testRoutingTables1();
        holes = testRoutingTables2();
    } else {
        streatch = testRoutingTables1a();
        holes = testRoutingTables2a();
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(round)->append(u","_j)
        ->append(streatch)
        ->append(u","_j)
        ->append(holes)
        ->append(u" numNodes:"_j)
        ->append(npc(nodes)->size())->toString());
    if(round % int32_t(50) == 0) {
        auto pn = java_cast< ::rice::pastry::PastryNode* >(npc(nodes)->get(npc(nodes)->size() / int32_t(2)));
        npc(::java::lang::System::out())->println(npc(npc(pn)->getRoutingTable())->printSelf());
        npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(npc(pn)->getLeafSet()));
        auto randomMaterial = new ::int8_tArray(int32_t(20));
        npc(npc(npc(pn)->getEnvironment())->getRandomSource())->nextBytes(randomMaterial);
        auto key = ::rice::pastry::Id::build(randomMaterial);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Key "_j)->append(npc(key)->toStringBare())->toString());
        auto i = npc(npc(pn)->getRouter())->getBestRoutingCandidates(key);
        while (npc(i)->hasNext()) {
            npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next())));
        }
    }
}

double rice::pastry::testing::RoutingTableTest::testRoutingTables1()
{
    auto nodeIterator = npc(nodes)->iterator();
    auto ctr = int32_t(0);
    double acc = int32_t(0);
    while (npc(nodeIterator)->hasNext()) {
        auto node = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(nodeIterator)->next()));
        auto rt = npc(node)->getRoutingTable();
        auto i2 = npc(nodes)->iterator();
        while (npc(i2)->hasNext()) {
            auto that = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(i2)->next()));
            if((that != node) && npc(that)->isReady() && npc(node)->isReady()) {
                auto thatHandle = npc(that)->getLocalHandle();
                auto latency = calcLatency(node, thatHandle);
                auto proximity = npc(node)->proximity(thatHandle);
                if(proximity == 0) {
                    throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"proximity zero:"_j)->append(static_cast< ::java::lang::Object* >(node))
                        ->append(u".proximity("_j)
                        ->append(static_cast< ::java::lang::Object* >(thatHandle))
                        ->append(u")"_j)->toString());
                }
                if(latency < proximity) {
                    latency = proximity;
                }
                auto streatch = (1.0 * latency) / (1.0 * proximity);
                acc += streatch;
                ctr++;
            }
        }
    }
    return acc / ctr;
}

double rice::pastry::testing::RoutingTableTest::testRoutingTables1a()
{
    auto ctr = int32_t(0);
    double acc = int32_t(0);
    auto rand = npc(env)->getRandomSource();
    for (auto i = int32_t(0); i < 1000000; i++) {
        auto node = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::rice::pastry::PastryNode* >(npc(nodes)->get(npc(rand)->nextInt(npc(nodes)->size()))));
        auto rt = npc(node)->getRoutingTable();
        auto that = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::rice::pastry::PastryNode* >(npc(nodes)->get(npc(rand)->nextInt(npc(nodes)->size()))));
        if((that != node) && npc(that)->isReady() && npc(node)->isReady()) {
            auto thatHandle = npc(that)->getLocalHandle();
            auto latency = calcLatency(node, thatHandle);
            auto proximity = npc(node)->proximity(thatHandle);
            if(proximity == 0) {
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"proximity zero:"_j)->append(static_cast< ::java::lang::Object* >(node))
                    ->append(u".proximity("_j)
                    ->append(static_cast< ::java::lang::Object* >(thatHandle))
                    ->append(u")"_j)->toString());
            }
            if(latency < proximity) {
                latency = proximity;
            }
            auto streatch = (1.0 * latency) / (1.0 * proximity);
            acc += streatch;
            ctr++;
        }
    }
    return acc / ctr;
}

int32_t rice::pastry::testing::RoutingTableTest::testRoutingTables2()
{
    auto nodeIterator = npc(nodes)->iterator();
    auto curNodeIndex = int32_t(0);
    auto ctr = int32_t(0);
    auto ctrs = new ::int32_tArray(int32_t(5));
    while (npc(nodeIterator)->hasNext()) {
        auto node = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(nodeIterator)->next()));
        if(!npc(node)->isReady())
            continue;

        auto temp = ::rice::pastry::direct::DirectPastryNode::setCurrentNode(node);
        auto rt = npc(node)->getRoutingTable();
        auto i2 = npc(nodes)->iterator();
        while (npc(i2)->hasNext()) {
            auto that = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(i2)->next()));
            if(!npc(that)->isReady())
                continue;

            auto thatHandle = npc(that)->getLocalHandle();
            auto response = npc(rt)->test(thatHandle);
            if(response > 1) {
                (*ctrs)[response]++;
                ctr++;
                if(logHeavy)
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(response)->append(u": ("_j)
                        ->append(curNodeIndex)
                        ->append(u")"_j)
                        ->append(static_cast< ::java::lang::Object* >(node))
                        ->append(u" could have held "_j)
                        ->append(static_cast< ::java::lang::Object* >(thatHandle))->toString());

            }
        }
        ::rice::pastry::direct::DirectPastryNode::setCurrentNode(temp);
        curNodeIndex++;
    }
    return ctr;
}

int32_t rice::pastry::testing::RoutingTableTest::testRoutingTables2a()
{
    auto nodeIterator = npc(nodes)->iterator();
    auto curNodeIndex = int32_t(0);
    auto ctr = int32_t(0);
    auto ctrs = new ::int32_tArray(int32_t(5));
    auto rand = npc(env)->getRandomSource();
    for (auto i = int32_t(0); i < 1000000; i++) {
        auto node = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::rice::pastry::PastryNode* >(npc(nodes)->get(npc(rand)->nextInt(npc(nodes)->size()))));
        if(!npc(node)->isReady())
            continue;

        auto temp = ::rice::pastry::direct::DirectPastryNode::setCurrentNode(node);
        auto rt = npc(node)->getRoutingTable();
        auto i2 = npc(nodes)->iterator();
        auto that = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::rice::pastry::PastryNode* >(npc(nodes)->get(npc(rand)->nextInt(npc(nodes)->size()))));
        if(!npc(that)->isReady())
            continue;

        auto thatHandle = npc(that)->getLocalHandle();
        auto response = npc(rt)->test(thatHandle);
        if(response > 1) {
            (*ctrs)[response]++;
            ctr++;
            if(logHeavy)
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(response)->append(u": ("_j)
                    ->append(curNodeIndex)
                    ->append(u")"_j)
                    ->append(static_cast< ::java::lang::Object* >(node))
                    ->append(u" could have held "_j)
                    ->append(static_cast< ::java::lang::Object* >(thatHandle))->toString());

        }
        ::rice::pastry::direct::DirectPastryNode::setCurrentNode(temp);
        curNodeIndex++;
    }
    return ctr;
}

int32_t rice::pastry::testing::RoutingTableTest::calcLatency(::rice::pastry::PastryNode* node, ::rice::pastry::NodeHandle* thatHandle)
{
    auto rt = npc(node)->getRoutingTable();
    auto ls = npc(node)->getLeafSet();
    thePenalty = 0;
    auto next = getNextHop(rt, ls, thatHandle, node);
    auto penalty = thePenalty;
    if(next == thatHandle)
        return npc(node)->proximity(thatHandle);

    auto dnh = java_cast< ::rice::pastry::direct::DirectNodeHandle* >(next);
    auto nextNode = npc(dnh)->getRemote();
    return penalty + npc(node)->proximity(next) + calcLatency(nextNode, thatHandle);
}

rice::pastry::NodeHandle* rice::pastry::testing::RoutingTableTest::getNextHop(::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::NodeHandle* thatHandle, ::rice::pastry::PastryNode* localNode)
{
    auto target = java_cast< ::rice::pastry::Id* >(npc(thatHandle)->getId());
    auto cwSize = npc(ls)->cwSize();
    auto ccwSize = npc(ls)->ccwSize();
    auto lsPos = npc(ls)->mostSimilar(target);
    if(lsPos == 0)
        throw new ::java::lang::RuntimeException(u"can't happen: probably a partition"_j);
    else if((lsPos > 0 && (lsPos < cwSize || !npc(npc(npc(ls)->get(lsPos))->getNodeId())->clockwise(target))) || (lsPos < 0 && (-lsPos < ccwSize || npc(npc(npc(ls)->get(lsPos))->getNodeId())->clockwise(target)))) {
        auto handle = npc(ls)->get(lsPos);
        if(npc(handle)->isAlive() == false) {
            thePenalty += timeToFindFaulty;
            auto ls2 = npc(ls)->copy();
            npc(ls2)->remove(handle);
            return getNextHop(rt, ls2, thatHandle, localNode);
        } else {
            return handle;
        }
    } else {
        auto rs = npc(rt)->getBestEntry(target);
        ::rice::pastry::NodeHandle* handle = nullptr;
        ::rice::pastry::NodeHandle* notAlive = nullptr;
        if(rs != nullptr && ((notAlive = npc(rs)->closestNode(10)) != nullptr)) {
            if((notAlive != nullptr) && !npc(notAlive)->isAlive())
                thePenalty += npc(localNode)->proximity(notAlive) * int32_t(4);

        }
        if(rs == nullptr || ((handle = npc(rs)->closestNode(::rice::pastry::NodeHandle::LIVENESS_ALIVE)) == nullptr)) {
            ::rice::pastry::NodeHandle* notAlive2 = nullptr;
            notAlive2 = npc(rt)->bestAlternateRoute(10, target);
            if(notAlive2 == notAlive) {
            } else {
                if((notAlive2 != nullptr) && !npc(notAlive2)->isAlive())
                    thePenalty += npc(localNode)->proximity(notAlive2) * int32_t(4);

            }
            handle = npc(rt)->bestAlternateRoute(::rice::pastry::NodeHandle::LIVENESS_ALIVE, target);
            if(handle == nullptr) {
                handle = npc(ls)->get(lsPos);
                if(npc(handle)->isAlive() == false) {
                    thePenalty += timeToFindFaulty;
                    auto ls2 = npc(ls)->copy();
                    npc(ls2)->remove(handle);
                    return getNextHop(rt, ls2, thatHandle, localNode);
                }
            } else {
                ::rice::p2p::commonapi::Id_Distance* altDist = npc(npc(handle)->getNodeId())->distance(target);
                ::rice::p2p::commonapi::Id_Distance* lsDist = npc(npc(npc(ls)->get(lsPos))->getNodeId())->distance(target);
                if(npc(lsDist)->compareTo(altDist) < 0) {
                    handle = npc(ls)->get(lsPos);
                    if(npc(handle)->isAlive() == false) {
                        thePenalty += timeToFindFaulty;
                        auto ls2 = npc(ls)->copy();
                        npc(ls2)->remove(handle);
                        return getNextHop(rt, ls2, thatHandle, localNode);
                    }
                }
            }
        }
        return handle;
    }
}

void rice::pastry::testing::RoutingTableTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto numNodes = int32_t(100);
    auto meanSessionTime = int32_t(0);
    auto useScribeIndex = int32_t(1);
    auto rtMaintIndex = int32_t(0);
    auto msgSendRateIndex = int32_t(0);
    auto numNodesIndex = -int32_t(1);
    if(npc(args)->length > 0) {
        numNodes = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
    }
    if(npc(args)->length > 1) {
        meanSessionTime = ::java::lang::Integer::parseInt((*args)[int32_t(1)]);
    }
    auto rtMaintVals = (new ::int32_tArray({
        int32_t(0)
        , int32_t(60)
        , int32_t(15)
        , int32_t(1)
    }));
    auto msgSendVals = (new ::int32_tArray({
        int32_t(0)
        , int32_t(10000)
        , int32_t(1000)
        , int32_t(100)
    }));
    auto numNodesVals = (new ::int32_tArray({
        int32_t(100)
        , int32_t(200)
        , int32_t(500)
        , int32_t(1000)
        , int32_t(2000)
        , int32_t(5000)
        , int32_t(10000)
    }));
    for (useScribeIndex = 0; useScribeIndex < 2; useScribeIndex++) 
                for (msgSendRateIndex = ((useScribeIndex == 0) ? int32_t(0) : int32_t(1)); msgSendRateIndex < 4; msgSendRateIndex++) 
                        for (rtMaintIndex = 0; rtMaintIndex < 4; rtMaintIndex++) 
                                for (auto tries = int32_t(0); tries < 10; tries++) {
                    if(numNodesIndex >= 0)
                        numNodes = (*numNodesVals)[numNodesIndex];

                    auto useScribe = true;
                    if(useScribeIndex == 0)
                        useScribe = false;

                    auto const lock = new ::java::lang::Object();
                    auto env = ::rice::environment::Environment::directEnvironment();
                    npc(env)->addDestructable(new RoutingTableTest_main_9(lock));
                    if(logHeavy) {
                        npc(npc(env)->getParameters())->setInt(u"rice.pastry.standard.ConsistentJoinProtocol_loglevel"_j, ::rice::environment::logging::Logger::FINE);
                        npc(npc(env)->getParameters())->setInt(u"rice.pastry.standard.StandardRouteSetProtocol_loglevel"_j, 405);
                        npc(npc(env)->getParameters())->setInt(u"rice.pastry.standard.StandardRouter_loglevel"_j, ::rice::environment::logging::Logger::FINE);
                    }
                    auto dt = new RoutingTableTest(numNodes, meanSessionTime, useScribe, (*msgSendVals)[msgSendRateIndex], (*rtMaintVals)[rtMaintIndex], tries, env);
                    {
                        synchronized synchronized_1(lock);
                        {
                            npc(lock)->wait();
                        }
                    }
                }



}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.RoutingTableTest", 36);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest::getClass0()
{
    return class_();
}

