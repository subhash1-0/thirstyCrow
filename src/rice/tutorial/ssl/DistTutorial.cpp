// Generated from /pastry-2.1/src/rice/tutorial/ssl/DistTutorial.java
#include <rice/tutorial/ssl/DistTutorial.hpp>

#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/security/KeyStore.hpp>
#include <java/security/Security.hpp>
#include <org/bouncycastle/jce/provider/BouncyCastleProvider.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/tutorial/ssl/DistTutorial_DistTutorial_1.hpp>
#include <rice/tutorial/ssl/MyApp.hpp>
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
rice::tutorial::ssl::DistTutorial::DistTutorial(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::ssl::DistTutorial::DistTutorial(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env, ::java::io::File* keyStoreFile)  /* throws(Exception) */
    : DistTutorial(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,env,keyStoreFile);
}

void rice::tutorial::ssl::DistTutorial::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env, ::java::io::File* keyStoreFile) /* throws(Exception) */
{
    super::ctor();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::java::security::Security::addProvider(new ::org::bouncycastle::jce::provider::BouncyCastleProvider());
    auto const store = ::java::security::KeyStore::getInstance(u"UBER"_j, u"BC"_j);
    npc(store)->load(new ::java::io::FileInputStream(keyStoreFile), npc(u""_j)->toCharArray_());
    auto id = ::rice::pastry::Id::build((*npc(npc(keyStoreFile)->getName())->split(u"\\."_j))[int32_t(0)]);
    ::rice::pastry::PastryNodeFactory* factory = new DistTutorial_DistTutorial_1(this, store, nidFactory, bindport, env);
    auto node = npc(factory)->newNode(id);
    auto app = new MyApp(node);
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
    npc(npc(env)->getTimeSource())->sleep(10000);
    for (auto i = int32_t(0); i < 10; i++) {
        ::rice::p2p::commonapi::Id* randId = npc(nidFactory)->generateNodeId();
        npc(app)->routeMyMsg(randId);
        npc(npc(env)->getTimeSource())->sleep(1000);
    }
    npc(npc(env)->getTimeSource())->sleep(10000);
    auto leafSet = npc(node)->getLeafSet();
    for (auto i = -npc(leafSet)->ccwSize(); i <= npc(leafSet)->cwSize(); i++) {
        if(i != 0) {
            auto nh = npc(leafSet)->get(i);
            npc(app)->routeMyMsgDirect(nh);
            npc(npc(env)->getTimeSource())->sleep(1000);
        }
    }
}

void rice::tutorial::ssl::DistTutorial::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    npc(npc(env)->getParameters())->setString(u"nat_search_policy"_j, u"never"_j);
    try {
        auto bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
        auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
        auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
        auto bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
        auto keystoreFileName = (*args)[int32_t(3)];
        auto keystoreFile = new ::java::io::File(keystoreFileName);
        if(!npc(keystoreFile)->exists())
            throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"The file: "_j)->append(keystoreFileName)
                ->append(u" was not found."_j)->toString());

        auto dt = new DistTutorial(bindport, bootaddress, env, keystoreFile);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.lesson3.DistTutorial localbindport bootIP bootPort"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.DistTutorial 9001 pokey.cs.almamater.edu 9001"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::ssl::DistTutorial::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.ssl.DistTutorial", 30);
    return c;
}

java::lang::Class* rice::tutorial::ssl::DistTutorial::getClass0()
{
    return class_();
}

