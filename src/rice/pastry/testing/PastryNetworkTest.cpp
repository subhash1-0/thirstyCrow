// Generated from /pastry-2.1/src/rice/pastry/testing/PastryNetworkTest.java
#include <rice/pastry/testing/PastryNetworkTest.hpp>

#include <java/io/FileOutputStream.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Observer.hpp>
#include <java/util/Set.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/testing/PastryNetworkTest_fetchLeafSets_1.hpp>
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
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > NodeHandleSetArray;
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeSetI, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeHandleSetArray > NodeSetIArray;

        namespace routing
        {
typedef ::SubArray< ::rice::pastry::routing::RouteSet, ::java::lang::ObjectArray, ::rice::pastry::NodeSetIArray, ::java::io::SerializableArray, ::java::util::ObserverArray, ::java::lang::IterableArray > RouteSetArray;
        } // routing
    } // pastry
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
rice::pastry::testing::PastryNetworkTest::PastryNetworkTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PastryNetworkTest::PastryNetworkTest(::rice::environment::Environment* env, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddress* bootstrap) 
    : PastryNetworkTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,factory,bootstrap);
}

void rice::pastry::testing::PastryNetworkTest::init()
{
    numThreads = int32_t(0);
}

constexpr int32_t rice::pastry::testing::PastryNetworkTest::MAX_THREADS;

void rice::pastry::testing::PastryNetworkTest::ctor(::rice::environment::Environment* env, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddress* bootstrap)
{
    super::ctor();
    init();
    this->environment = env;
    this->factory = factory;
    this->bootstrap = bootstrap;
    this->nodes = new ::java::util::HashSet();
    this->dead = new ::java::util::HashSet();
    this->unknown = new ::java::util::HashSet();
}

java::util::HashMap* rice::pastry::testing::PastryNetworkTest::fetchLeafSets() /* throws(Exception) */
{
    auto const leafsets = new ::java::util::HashMap();
    auto const unseen = new ::java::util::HashSet();
    auto const ps = new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(u"response.txt"_j)));
    npc(unseen)->add(static_cast< ::java::lang::Object* >(npc(factory)->getNodeHandle(bootstrap)));
    {
        synchronized synchronized_0(unseen);
        {
            while (true) {
                if(numThreads >= MAX_THREADS)
                    npc(unseen)->wait();

                if(npc(unseen)->size() > 0) {
                    numThreads++;
                    auto const handle = java_cast< ::rice::pastry::socket::SocketNodeHandle* >(java_cast< ::java::lang::Object* >(npc(npc(unseen)->iterator())->next()));
                    npc(unseen)->remove(static_cast< ::java::lang::Object* >(handle));
                    npc(nodes)->add(static_cast< ::java::lang::Object* >(handle));
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Fetching leafset of "_j)->append(static_cast< ::java::lang::Object* >(handle))
                        ->append(u" (thread "_j)
                        ->append(numThreads)
                        ->append(u" of "_j)
                        ->append(MAX_THREADS)
                        ->append(u")"_j)->toString());
                    ::java::lang::Thread* t = new PastryNetworkTest_fetchLeafSets_1(this, handle, ps, leafsets, unseen);
                    npc(t)->start();
                } else if(numThreads > 0) {
                    npc(unseen)->wait();
                } else {
                    break;
                }
            }
        }
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Fetched all leafsets - return...  Found "_j)->append(npc(nodes)->size())
        ->append(u" nodes."_j)->toString());
    return leafsets;
}

void rice::pastry::testing::PastryNetworkTest::testLeafSets() /* throws(Exception) */
{
    auto leafsets = fetchLeafSets();
    auto sets = npc(npc(leafsets)->values())->iterator();
    while (npc(sets)->hasNext()) {
        auto nodes = npc(npc(leafsets)->keySet())->iterator();
        auto set = java_cast< ::rice::pastry::leafset::LeafSet* >(java_cast< ::java::lang::Object* >(npc(sets)->next()));
        if(set != nullptr) {
            while (npc(nodes)->hasNext()) {
                auto node = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(nodes)->next()));
                if(npc(dead)->contains(static_cast< ::java::lang::Object* >(node)) && npc(set)->member(node)) {
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"LEAFSET ERROR: Leafset for "_j)->append(static_cast< ::java::lang::Object* >(npc(set)->get(0)))
                        ->append(u" contains dead node "_j)
                        ->append(static_cast< ::java::lang::Object* >(node))->toString());
                } else if((!npc(dead)->contains(static_cast< ::java::lang::Object* >(node))) && npc(set)->isComplete() && npc(set)->test(node)) {
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"LEAFSET ERROR: Leafset for "_j)->append(static_cast< ::java::lang::Object* >(npc(set)->get(0)))
                        ->append(u" is missing "_j)
                        ->append(static_cast< ::java::lang::Object* >(node))->toString());
                }
            }
        }
    }
    npc(::java::lang::System::out())->println(u"Done testing..."_j);
}

java::util::HashMap* rice::pastry::testing::PastryNetworkTest::fetchRouteRow(int32_t row) /* throws(IOException) */
{
    auto routerows = new ::java::util::HashMap();
    auto i = npc(nodes)->iterator();
    while (npc(i)->hasNext()) {
        auto handle = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Fetching route row "_j)->append(row)
            ->append(u" of "_j)
            ->append(static_cast< ::java::lang::Object* >(handle))->toString());
        ::rice::pastry::routing::RouteSetArray* set = nullptr;
        if(set != nullptr)
            npc(routerows)->put(static_cast< ::java::lang::Object* >(handle), static_cast< ::java::lang::Object* >(set));

    }
    npc(::java::lang::System::out())->println(u"Fetched all route rows - return..."_j);
    return routerows;
}

void rice::pastry::testing::PastryNetworkTest::testRouteRow(int32_t row) /* throws(IOException) */
{
    auto routerows = fetchRouteRow(row);
    auto i = npc(nodes)->iterator();
    while (npc(i)->hasNext()) {
        auto node = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        auto rt = new ::rice::pastry::routing::RoutingTable(node, int32_t(1), static_cast< int8_t >(npc(npc(environment)->getParameters())->getInt(u"pastry_rtBaseBitLength"_j)), npc((java_cast< ::rice::pastry::socket::SocketNodeHandle* >(node)))->getLocalNode());
        auto j = npc(nodes)->iterator();
        while (npc(j)->hasNext()) 
                        npc(rt)->put(java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(j)->next())));

        auto ideal = java_cast< ::rice::pastry::routing::RouteSetArray* >(npc(rt)->getRow(row));
        auto actual = java_cast< ::rice::pastry::routing::RouteSetArray* >(java_cast< ::java::lang::Object* >(npc(routerows)->get(static_cast< ::java::lang::Object* >(node))));
        for (auto k = int32_t(0); k < npc(ideal)->length; k++) {
            if((((*actual)[k] == nullptr) || (npc((*actual)[k])->size() == 0)) && (((*ideal)[k] != nullptr) && (npc((*ideal)[k])->size() > 0)))
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ROUTING TABLE ERROR: "_j)->append(static_cast< ::java::lang::Object* >(node))
                    ->append(u" has no entry in row "_j)
                    ->append(row)
                    ->append(u" column "_j)
                    ->append(k)
                    ->append(u" but "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc((*ideal)[k])->get(int32_t(0))))
                    ->append(u" exists"_j)->toString());

            if((((*actual)[k] != nullptr) && (npc((*actual)[k])->size() > 0)) && (((*ideal)[k] == nullptr) || (npc((*ideal)[k])->size() == 0)))
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ROUTING TABLE ERROR: "_j)->append(static_cast< ::java::lang::Object* >(node))
                    ->append(u" has no non-existent entry in row "_j)
                    ->append(row)
                    ->append(u" column "_j)
                    ->append(k)
                    ->append(u" entry "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc((*actual)[k])->get(int32_t(0))))
                    ->append(u" exists"_j)->toString());

        }
    }
    npc(::java::lang::System::out())->println(u"Done testing..."_j);
}

void rice::pastry::testing::PastryNetworkTest::testRoutingTables() /* throws(Exception) */
{
    testRouteRow(39);
    testRouteRow(38);
}

void rice::pastry::testing::PastryNetworkTest::start() /* throws(Exception) */
{
    testLeafSets();
    ::java::lang::System::exit(0);
}

void rice::pastry::testing::PastryNetworkTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    auto test = new PastryNetworkTest(env, new ::rice::pastry::socket::SocketPastryNodeFactory(nullptr, int32_t(1), env), new ::java::net::InetSocketAddress((*args)[int32_t(0)], ::java::lang::Integer::parseInt((*args)[int32_t(1)])));
    npc(test)->start();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PastryNetworkTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PastryNetworkTest", 37);
    return c;
}

java::lang::Class* rice::pastry::testing::PastryNetworkTest::getClass0()
{
    return class_();
}

