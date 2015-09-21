// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupServiceTest.java
#include <rice/tutorial/lookup/LookupServiceTest.hpp>

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
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/tutorial/lookup/LookupService.hpp>
#include <rice/tutorial/lookup/LookupServiceTest_LookupServiceTest_1.hpp>
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
rice::tutorial::lookup::LookupServiceTest::LookupServiceTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::lookup::LookupServiceTest::LookupServiceTest(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env)  /* throws(Exception) */
    : LookupServiceTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,numNodes,env);
}

void rice::tutorial::lookup::LookupServiceTest::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env) /* throws(Exception) */
{
    super::ctor();
    auto lookups = new ::java::util::ArrayList();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::PastryNodeFactory* factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, bindport, env);
    for (auto curNode = int32_t(0); curNode < numNodes; curNode++) {
        auto node = npc(factory)->newNode();
        auto ls = new LookupService(node);
        npc(lookups)->add(static_cast< ::java::lang::Object* >(ls));
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
    npc(npc(env)->getTimeSource())->sleep(10000);
    for (auto _i = npc(lookups)->iterator(); _i->hasNext(); ) {
        LookupService* ls = java_cast< LookupService* >(_i->next());
        {
            auto const id = npc(nidFactory)->generateNodeId();
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Requesting id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());
            npc(ls)->requestNodeHandles(id, 3, new LookupServiceTest_LookupServiceTest_1(this, id));
        }
    }
}

void rice::tutorial::lookup::LookupServiceTest::main(::java::lang::StringArray* args) /* throws(Exception) */
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
        auto lt = new LookupServiceTest(bindport, bootaddress, numNodes, env);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.lookup.LookupServiceTest localbindport bootIP bootPort numNodes"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.lookup.LookupServiceTest 9001 pokey.cs.almamater.edu 9001 10"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupServiceTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.lookup.LookupServiceTest", 38);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupServiceTest::getClass0()
{
    return class_();
}

