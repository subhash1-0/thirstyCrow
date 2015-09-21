// Generated from /pastry-2.1/src/rice/tutorial/past/PastTutorial.java
#include <rice/tutorial/past/PastTutorial.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/persistence/LRUCache.hpp>
#include <rice/persistence/MemoryStorage.hpp>
#include <rice/persistence/StorageManagerImpl.hpp>
#include <rice/tutorial/past/MyPastContent.hpp>
#include <rice/tutorial/past/PastTutorial_PastTutorial_1.hpp>
#include <rice/tutorial/past/PastTutorial_PastTutorial_2.hpp>
#include <rice/tutorial/past/PastTutorial_PastTutorial_3.hpp>
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
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
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
rice::tutorial::past::PastTutorial::PastTutorial(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::past::PastTutorial::PastTutorial(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env)  /* throws(Exception) */
    : PastTutorial(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,numNodes,env);
}

void rice::tutorial::past::PastTutorial::init()
{
    apps = new ::java::util::Vector();
}

void rice::tutorial::past::PastTutorial::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env) /* throws(Exception) */
{
    super::ctor();
    init();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::PastryNodeFactory* factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, bindport, env);
    for (auto curNode = int32_t(0); curNode < numNodes; curNode++) {
        auto node = npc(factory)->newNode();
        auto idf = new ::rice::pastry::commonapi::PastryIdFactory(env);
        auto storageDirectory = ::java::lang::StringBuilder().append(u"./storage"_j)->append(npc(npc(node)->getId())->hashCode())->toString();
        ::rice::persistence::Storage* stor = new ::rice::persistence::MemoryStorage(idf);
        ::rice::p2p::past::Past* app = new ::rice::p2p::past::PastImpl(node, new ::rice::persistence::StorageManagerImpl(idf, stor, new ::rice::persistence::LRUCache(new ::rice::persistence::MemoryStorage(idf), int32_t(512) * int32_t(1024), npc(node)->getEnvironment())), int32_t(0), u""_j);
        npc(apps)->add(static_cast< ::java::lang::Object* >(app));
        npc(node)->boot(static_cast< ::java::lang::Object* >(bootaddress));
        {
            synchronized synchronized_0(node);
            {
                while (!npc(node)->isReady() && !npc(node)->joinFailed()) {
                    npc(node)->wait(500);
                    if(npc(node)->joinFailed()) {
                        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not join the FreePastry ring.  Reason:"_j)->append(static_cast< ::java::lang::Object* >(npc(node)->joinFailedReason()))->toString());
                    }
                }
            }
        }
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Finished creating new node "_j)->append(static_cast< ::java::lang::Object* >(node))->toString());
    }
    npc(npc(env)->getTimeSource())->sleep(5000);
    auto localFactory = new ::rice::pastry::commonapi::PastryIdFactory(env);
    npc(::java::lang::System::out())->println(u"Storing 5 keys"_j);
    auto storedKey = new ::rice::p2p::commonapi::IdArray(int32_t(5));
    for (auto ctr = int32_t(0); ctr < npc(storedKey)->length; ctr++) {
        auto const s = ::java::lang::StringBuilder().append(u"test"_j)->append(npc(npc(env)->getRandomSource())->nextInt())->toString();
        ::rice::p2p::past::PastContent* const myContent = new MyPastContent(npc(localFactory)->buildId(s), s);
        storedKey->set(ctr, npc(myContent)->getId());
        auto p = java_cast< ::rice::p2p::past::Past* >(java_cast< ::rice::p2p::past::Past* >(npc(apps)->get(npc(npc(env)->getRandomSource())->nextInt(numNodes))));
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Inserting "_j)->append(static_cast< ::java::lang::Object* >(myContent))
            ->append(u" at node "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(p)->getLocalNodeHandle()))->toString());
        npc(p)->insert(myContent, new PastTutorial_PastTutorial_1(this, myContent));
    }
    npc(npc(env)->getTimeSource())->sleep(5000);
    npc(::java::lang::System::out())->println(u"Looking up the 5 keys"_j);
    for (auto ctr = int32_t(0); ctr < npc(storedKey)->length; ctr++) {
        auto const lookupKey = (*storedKey)[ctr];
        auto p = java_cast< ::rice::p2p::past::Past* >(java_cast< ::rice::p2p::past::Past* >(npc(apps)->get(npc(npc(env)->getRandomSource())->nextInt(numNodes))));
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Looking up "_j)->append(static_cast< ::java::lang::Object* >(lookupKey))
            ->append(u" at node "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(p)->getLocalNodeHandle()))->toString());
        npc(p)->lookup(lookupKey, new PastTutorial_PastTutorial_2(this, lookupKey));
    }
    npc(npc(env)->getTimeSource())->sleep(5000);
    npc(::java::lang::System::out())->println(u"Looking up a bogus key"_j);
    auto const bogusKey = npc(localFactory)->buildId(u"bogus"_j);
    auto p = java_cast< ::rice::p2p::past::Past* >(java_cast< ::rice::p2p::past::Past* >(npc(apps)->get(npc(npc(env)->getRandomSource())->nextInt(numNodes))));
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Looking up bogus key "_j)->append(static_cast< ::java::lang::Object* >(bogusKey))
        ->append(u" at node "_j)
        ->append(static_cast< ::java::lang::Object* >(npc(p)->getLocalNodeHandle()))->toString());
    npc(p)->lookup(bogusKey, new PastTutorial_PastTutorial_3(this, bogusKey, env));
}

void rice::tutorial::past::PastTutorial::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    npc(npc(env)->getParameters())->setString(u"nat_search_policy"_j, u"never"_j);
    try {
        auto bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
        auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
        auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
        auto bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
        auto numNodes = ::java::lang::Integer::parseInt((*args)[int32_t(3)]);
        auto dt = new PastTutorial(bindport, bootaddress, numNodes, env);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.past.PastTutorial localbindport bootIP bootPort numNodes"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.past.PastTutorial 9001 pokey.cs.almamater.edu 9001 10"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::past::PastTutorial::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.past.PastTutorial", 31);
    return c;
}

java::lang::Class* rice::tutorial::past::PastTutorial::getClass0()
{
    return class_();
}

