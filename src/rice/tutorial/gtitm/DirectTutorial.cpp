// Generated from /pastry-2.1/src/rice/tutorial/gtitm/DirectTutorial.java
#include <rice/tutorial/gtitm/DirectTutorial.hpp>

#include <java/io/File.hpp>
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
#include <java/util/Iterator.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/GenericNetwork.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/tutorial/gtitm/MyApp.hpp>
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
rice::tutorial::gtitm::DirectTutorial::DirectTutorial(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::gtitm::DirectTutorial::DirectTutorial(int32_t numNodes, ::rice::environment::Environment* env, ::java::lang::String* fileName)  /* throws(Exception) */
    : DirectTutorial(*static_cast< ::default_init_tag* >(0))
{
    ctor(numNodes,env,fileName);
}

void rice::tutorial::gtitm::DirectTutorial::init()
{
    apps = new ::java::util::Vector();
}

void rice::tutorial::gtitm::DirectTutorial::ctor(int32_t numNodes, ::rice::environment::Environment* env, ::java::lang::String* fileName) /* throws(Exception) */
{
    super::ctor();
    init();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::direct::NetworkSimulator* simulator = new ::rice::pastry::direct::GenericNetwork(env, new ::java::io::File(fileName));
    npc(simulator)->setMaxSpeed(1.0f);
    ::rice::pastry::PastryNodeFactory* factory = new ::rice::pastry::direct::DirectPastryNodeFactory(nidFactory, simulator, env);
    ::rice::pastry::NodeHandle* bootHandle = nullptr;
    for (auto curNode = int32_t(0); curNode < numNodes; curNode++) {
        auto node = npc(factory)->newNode();
        auto app = new MyApp(node);
        npc(apps)->add(static_cast< ::java::lang::Object* >(app));
        npc(node)->boot(static_cast< ::java::lang::Object* >(bootHandle));
        bootHandle = npc(node)->getLocalHandle();
        npc(simulator)->setMaxSpeed(curNode + int32_t(1));
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
    npc(simulator)->setFullSpeed();
    for (auto i = int32_t(0); i < 10; i++) {
        auto appIterator = npc(apps)->iterator();
        while (npc(appIterator)->hasNext()) {
            auto app = java_cast< MyApp* >(java_cast< MyApp* >(npc(appIterator)->next()));
            ::rice::p2p::commonapi::Id* randId = npc(nidFactory)->generateNodeId();
            npc(app)->routeMyMsg(randId);
            npc(npc(env)->getTimeSource())->sleep(100);
        }
    }
    npc(npc(env)->getTimeSource())->sleep(1000);
    auto appIterator = npc(apps)->iterator();
    while (npc(appIterator)->hasNext()) {
        auto app = java_cast< MyApp* >(java_cast< MyApp* >(npc(appIterator)->next()));
        auto node = java_cast< ::rice::pastry::PastryNode* >(npc(app)->getNode());
        auto leafSet = npc(node)->getLeafSet();
        for (auto i = -npc(leafSet)->ccwSize(); i <= npc(leafSet)->cwSize(); i++) {
            if(i != 0) {
                auto nh = npc(leafSet)->get(i);
                npc(app)->routeMyMsgDirect(nh);
                npc(npc(env)->getTimeSource())->sleep(100);
            }
        }
    }
}

void rice::tutorial::gtitm::DirectTutorial::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = ::rice::environment::Environment::directEnvironment();
    try {
        auto numNodes = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
        auto fileName = u"GNPINPUT"_j;
        if(npc(args)->length > 1)
            fileName = (*args)[int32_t(1)];

        auto dt = new DirectTutorial(numNodes, env, fileName);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.gtitm.DirectTutorial numNodes <filename>"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.gtitm.DirectTutorial 100 GNPINPUT"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::gtitm::DirectTutorial::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.gtitm.DirectTutorial", 34);
    return c;
}

java::lang::Class* rice::tutorial::gtitm::DirectTutorial::getClass0()
{
    return class_();
}

