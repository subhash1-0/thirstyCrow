// Generated from /pastry-2.1/src/rice/pastry/testing/PartitionChecker.java
#include <rice/pastry/testing/PartitionChecker.hpp>

#include <java/io/BufferedReader.hpp>
#include <java/io/FileOutputStream.hpp>
#include <java/io/FileReader.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/testing/PartitionChecker_buildRing_1.hpp>
#include <rice/pastry/testing/PartitionChecker_Ring.hpp>
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
rice::pastry::testing::PartitionChecker::PartitionChecker(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PartitionChecker::PartitionChecker(::java::lang::String* ringIdString)  /* throws(Exception) */
    : PartitionChecker(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringIdString);
}

void rice::pastry::testing::PartitionChecker::init()
{
    numThreads = int32_t(0);
    ps = new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(u"response.txt"_j)));
    dead = new ::java::util::HashSet();
}

constexpr int32_t rice::pastry::testing::PartitionChecker::MAX_THREADS;

void rice::pastry::testing::PartitionChecker::ctor(::java::lang::String* ringIdString) /* throws(Exception) */
{
    super::ctor();
    init();
    environment = new ::rice::environment::Environment();
    buildBootstrapSetFromCert(ringIdString);
    rings = new ::java::util::ArrayList();
    auto factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nullptr, int32_t(1), environment);
    while (npc(unmatchedBootstraps)->size() > 0) {
        npc(rings)->add(static_cast< ::java::lang::Object* >(buildRing(factory, java_cast< ::java::net::InetSocketAddress* >((java_cast< ::java::net::InetSocketAddress* >(npc(npc(unmatchedBootstraps)->iterator())->next()))))));
    }
    ::java::util::Collections::sort(rings);
    auto i = npc(rings)->iterator();
    while (npc(i)->hasNext()) {
        npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(java_cast< PartitionChecker_Ring* >(npc(i)->next())));
    }
}

void rice::pastry::testing::PartitionChecker::buildBootstrapSetFromCert(::java::lang::String* ringIdString) /* throws(Exception) */
{
    unmatchedBootstraps = new ::java::util::HashSet();
    bootstraps = new ::java::util::HashSet();
    auto in = new ::java::io::BufferedReader(new ::java::io::FileReader(ringIdString));
    ::java::lang::String* line;
    while (npc(in)->ready()) {
        line = npc(in)->readLine();
        auto parts = npc(line)->split(u":"_j);
        auto port = int32_t(10003);
        if(npc(parts)->length > 1) {
            port = ::java::lang::Integer::parseInt((*parts)[int32_t(1)]);
        }
        auto addr = new ::java::net::InetSocketAddress((*parts)[int32_t(0)], port);
        npc(unmatchedBootstraps)->add(static_cast< ::java::lang::Object* >(addr));
        npc(bootstraps)->add(static_cast< ::java::lang::Object* >(addr));
    }
}

rice::pastry::leafset::LeafSet* rice::pastry::testing::PartitionChecker::getLeafSet(::rice::pastry::NodeHandle* nh) /* throws(IOException) */
{
    return nullptr;
}

rice::pastry::testing::PartitionChecker_Ring* rice::pastry::testing::PartitionChecker::buildRing(::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddress* bootstrap) /* throws(Exception) */
{
    npc(unmatchedBootstraps)->remove(static_cast< ::java::lang::Object* >(bootstrap));
    numThreads = 0;
    auto const ring = new PartitionChecker_Ring(this, bootstrap);
    auto const unseen = new ::java::util::HashSet();
    npc(unseen)->add(static_cast< ::java::lang::Object* >(npc(factory)->getNodeHandle(bootstrap, int32_t(20000))));
    {
        synchronized synchronized_0(unseen);
        {
            while (true) {
                if(numThreads >= MAX_THREADS)
                    npc(unseen)->wait();

                if(npc(unseen)->size() > 0) {
                    numThreads++;
                    auto const handle = java_cast< ::rice::pastry::socket::SocketNodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(npc(unseen)->iterator())->next()));
                    if(handle == nullptr) {
                        break;
                    }
                    npc(unseen)->remove(static_cast< ::java::lang::Object* >(handle));
                    npc(ring)->addNode(handle);
                    ::java::lang::Thread* t = new PartitionChecker_buildRing_1(this, handle, ring, unseen);
                    npc(t)->start();
                } else if(numThreads > 0) {
                    npc(unseen)->wait();
                } else {
                    break;
                }
            }
        }
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"buildRing() complete:"_j)->append(static_cast< ::java::lang::Object* >(ring))->toString());
    return ring;
}

void rice::pastry::testing::PartitionChecker::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    new PartitionChecker((*args)[int32_t(0)]);
    ::java::lang::System::exit(0);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PartitionChecker::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PartitionChecker", 36);
    return c;
}

java::lang::Class* rice::pastry::testing::PartitionChecker::getClass0()
{
    return class_();
}

