// Generated from /pastry-2.1/src/rice/tutorial/lesson1/DistTutorial.java
#include <rice/tutorial/lesson1/DistTutorial.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
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
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
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
rice::tutorial::lesson1::DistTutorial::DistTutorial(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::lesson1::DistTutorial::DistTutorial(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env)  /* throws(Exception) */
    : DistTutorial(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,env);
}

void rice::tutorial::lesson1::DistTutorial::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env) /* throws(Exception) */
{
    super::ctor();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::PastryNodeFactory* factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, bindport, env);
    auto node = npc(factory)->newNode();
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

void rice::tutorial::lesson1::DistTutorial::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    npc(npc(env)->getParameters())->setString(u"nat_search_policy"_j, u"never"_j);
    try {
        auto bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
        auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
        auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
        auto bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
        auto dt = new DistTutorial(bindport, bootaddress, env);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.lesson1.DistTutorial localbindport bootIP bootPort"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.DistTutorial 9001 pokey.cs.almamater.edu 9001"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lesson1::DistTutorial::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.lesson1.DistTutorial", 34);
    return c;
}

java::lang::Class* rice::tutorial::lesson1::DistTutorial::getClass0()
{
    return class_();
}

