// Generated from /pastry-2.1/src/rice/pastry/testing/ClosestRegrTest.java
#include <rice/pastry/testing/ClosestRegrTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/direct/DirectNodeHandle.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/direct/SphereNetwork.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>

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
rice::pastry::testing::ClosestRegrTest::ClosestRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::ClosestRegrTest::ClosestRegrTest()  /* throws(IOException) */
    : ClosestRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::testing::ClosestRegrTest::init()
{
    incorrect = int32_t(0);
    sum = int32_t(0);
}

int32_t& rice::pastry::testing::ClosestRegrTest::NUM_NODES()
{
    clinit();
    return NUM_NODES_;
}
int32_t rice::pastry::testing::ClosestRegrTest::NUM_NODES_;

void rice::pastry::testing::ClosestRegrTest::ctor() /* throws(IOException) */
{
    super::ctor();
    init();
    environment = ::rice::environment::Environment::directEnvironment();
    simulator = new ::rice::pastry::direct::SphereNetwork(environment);
    factory = new ::rice::pastry::direct::DirectPastryNodeFactory(new ::rice::pastry::standard::RandomNodeIdFactory(environment), simulator, environment);
    pastryNodes = new ::java::util::Vector();
}

rice::pastry::NodeHandle* rice::pastry::testing::ClosestRegrTest::getBootstrap()
{
    ::rice::pastry::NodeHandle* bootstrap = nullptr;
    try {
        auto lastnode = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->lastElement()));
        bootstrap = npc(lastnode)->getLocalHandle();
    } catch (::java::util::NoSuchElementException* e) {
    }
    return bootstrap;
}

void rice::pastry::testing::ClosestRegrTest::run()
{
    for (auto i = int32_t(0); i < NUM_NODES_; i++) {
        auto node = npc(factory)->newNode(getBootstrap());
        {
            synchronized synchronized_0(node);
            {
                while (!npc(node)->isReady()) {
                    try {
                        npc(node)->wait(500);
                    } catch (::java::lang::InterruptedException* ie) {
                        return;
                    }
                }
            }
        }
        if(i > 0)
            test(i, java_cast< ::rice::pastry::direct::DirectNodeHandle* >(npc(node)->getLocalHandle()));

        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"CREATED NODE "_j)->append(i)
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(node)->getNodeId()))->toString());
        npc(pastryNodes)->add(static_cast< ::java::lang::Object* >(node));
        auto ave = getAvgNumEntries(pastryNodes);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Avg Num Entries:"_j)->append(ave)->toString());
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"SO FAR: "_j)->append(incorrect)
        ->append(u"/"_j)
        ->append(NUM_NODES_)
        ->append(u" PERCENTAGE: "_j)
        ->append((sum / incorrect))->toString());
}

double rice::pastry::testing::ClosestRegrTest::getAvgNumEntries(::java::util::Collection* nds)
{
    double sum = int32_t(0);
    auto i = npc(nds)->iterator();
    while (npc(i)->hasNext()) {
        auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::rice::pastry::PastryNode* >(npc(i)->next()));
        sum += npc(npc(pn)->getRoutingTable())->numUniqueEntries();
    }
    return sum / npc(nds)->size();
}

void rice::pastry::testing::ClosestRegrTest::test(int32_t i, ::rice::pastry::direct::DirectNodeHandle* handle)
{
    auto bootNode = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->elementAt(npc(npc(environment)->getRandomSource())->nextInt(i))));
    auto bootstrap = npc(bootNode)->getLocalHandle();
    ::rice::pastry::direct::DirectNodeHandle* closest = nullptr;
    auto realClosest = npc(simulator)->getClosest(handle);
    if(!npc(npc(closest)->getNodeId())->equals(npc(realClosest)->getNodeId())) {
        auto cProx = npc(simulator)->proximity(closest, handle);
        auto rProx = npc(simulator)->proximity(realClosest, handle);
        if(cProx == 0) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR: factory.getNearest("_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u") returned "_j)
                ->append(static_cast< ::java::lang::Object* >(closest))->toString());
        }
        if(rProx < cProx) {
            incorrect++;
            sum += (cProx / rProx);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR: CLOSEST TO "_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u" WAS "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(closest)->getNodeId()))
                ->append(u":"_j)
                ->append(cProx)
                ->append(u" REAL CLOSEST: "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(realClosest)->getNodeId()))
                ->append(u":"_j)
                ->append(rProx)->toString());
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"SO FAR: "_j)->append(incorrect)
                ->append(u"/"_j)
                ->append(i)
                ->append(u" PERCENTAGE: "_j)
                ->append((sum / incorrect))->toString());
        }
    }
}

bool rice::pastry::testing::ClosestRegrTest::pass()
{
    return incorrect < NUM_NODES_ / int32_t(2);
}

void rice::pastry::testing::ClosestRegrTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto pt = new ClosestRegrTest();
    npc(pt)->run();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"pass:"_j)->append(npc(pt)->pass())->toString());
    npc(npc(pt)->environment)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::ClosestRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.ClosestRegrTest", 35);
    return c;
}

void rice::pastry::testing::ClosestRegrTest::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        NUM_NODES_ = int32_t(1000);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::ClosestRegrTest::getClass0()
{
    return class_();
}

