// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamDistTest.java
#include <rice/p2p/splitstream/testing/SplitStreamDistTest.hpp>

#include <java/io/FileOutputStream.hpp>
#include <java/io/OutputStream.hpp>
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
#include <java/lang/Runnable.hpp>
#include <java/lang/Runtime.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/net/DatagramSocket.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/ServerSocket.hpp>
#include <java/nio/channels/DatagramChannel.hpp>
#include <java/nio/channels/ServerSocketChannel.hpp>
#include <java/util/Random.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/splitstream/ChannelId.hpp>
#include <rice/p2p/splitstream/testing/MySplitStreamClient.hpp>
#include <rice/p2p/splitstream/testing/SplitStreamDistTest_main_1.hpp>
#include <rice/p2p/splitstream/testing/SplitStreamDistTest_main_2.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
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
rice::p2p::splitstream::testing::SplitStreamDistTest::SplitStreamDistTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::testing::SplitStreamDistTest::SplitStreamDistTest()
    : SplitStreamDistTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t rice::p2p::splitstream::testing::SplitStreamDistTest::DEFAULT_PORT;

constexpr int32_t rice::p2p::splitstream::testing::SplitStreamDistTest::WAIT_TO_JOIN_DELAY;

constexpr int32_t rice::p2p::splitstream::testing::SplitStreamDistTest::WAIT_TO_SUBSCRIBE_DELAY;

constexpr int32_t rice::p2p::splitstream::testing::SplitStreamDistTest::IM_ALIVE_PERIOD;

java::lang::String*& rice::p2p::splitstream::testing::SplitStreamDistTest::INSTANCE()
{
    clinit();
    return INSTANCE_;
}
java::lang::String* rice::p2p::splitstream::testing::SplitStreamDistTest::INSTANCE_;

java::lang::String*& rice::p2p::splitstream::testing::SplitStreamDistTest::BOOTNODE()
{
    clinit();
    return BOOTNODE_;
}
java::lang::String* rice::p2p::splitstream::testing::SplitStreamDistTest::BOOTNODE_;

constexpr bool rice::p2p::splitstream::testing::SplitStreamDistTest::nameSelf;

void rice::p2p::splitstream::testing::SplitStreamDistTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto suffix = u""_j;
    if(nameSelf) {
        suffix = ::java::lang::StringBuilder(suffix).append(::java::lang::StringBuilder().append(u"."_j)->append(npc(::java::net::InetAddress::getLocalHost())->getHostName())->toString())->toString();
    }
    auto outfileString = ::java::lang::StringBuilder().append(u"ss.txt"_j)->append(suffix)->toString();
    auto ps = new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(outfileString, true)));
    ::java::lang::System::setErr(ps);
    ::java::lang::System::setOut(ps);
    auto const env = new ::rice::environment::Environment();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"BOOTUP:"_j)->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());
    auto artificialChurn = false;
    if(npc(args)->length > 0) {
    }
    auto bootNode = SplitStreamDistTest::BOOTNODE_;
    if(npc(args)->length > 1) {
        bootNode = (*args)[int32_t(1)];
    }
    auto port = SplitStreamDistTest::DEFAULT_PORT;
    if(npc(args)->length > 2) {
        port = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
    }
    auto isBootNode = false;
    auto localAddress = ::java::net::InetAddress::getLocalHost();
    if(npc(npc(localAddress)->getHostName())->startsWith(bootNode)) {
        isBootNode = true;
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"isBootNode:"_j)->append(isBootNode)->toString());
    if(IM_ALIVE_PERIOD > 0) {
        (new ::java::lang::Thread(static_cast< ::java::lang::Runnable* >(new SplitStreamDistTest_main_1(env)), u"ImALIVE"_j))->start();
    }
    if(!isBootNode) {
        auto waitTime = npc(npc(env)->getRandomSource())->nextInt(WAIT_TO_JOIN_DELAY);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Waiting for "_j)->append(waitTime)
            ->append(u" millis before continuing..."_j)
            ->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());
        ::java::lang::Thread::sleep(waitTime);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Starting connection process "_j)->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());
    }
    auto success = false;
    while (!success) {
        try {
            auto bindAddress = new ::java::net::InetSocketAddress(::java::net::InetAddress::getLocalHost(), port);
            auto channel = ::java::nio::channels::DatagramChannel::open();
            npc(channel)->configureBlocking(false);
            npc(npc(channel)->socket())->bind(bindAddress);
            npc(channel)->close();
            auto channel1 = ::java::nio::channels::ServerSocketChannel::open();
            npc(channel1)->configureBlocking(false);
            npc(npc(channel1)->socket())->bind(bindAddress);
            npc(channel1)->close();
            success = true;
        } catch (::java::lang::Exception* e) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Couldn't bind on port "_j)->append(port)
                ->append(u" trying "_j)
                ->append((port + int32_t(1)))->toString());
            port++;
        }
    }
    auto bootaddr = ::java::net::InetAddress::getByName(bootNode);
    auto bootport = port;
    if(npc(args)->length > 3) {
        bootport = ::java::lang::Integer::parseInt((*args)[int32_t(3)]);
    }
    auto bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::PastryNodeFactory* factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, port, env);
    auto bootHandle = npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(bootaddress);
    if(bootHandle == nullptr) {
        if(isBootNode) {
        } else {
            npc(::java::lang::System::out())->println(u"Couldn't find bootstrap... exiting."_j);
            ::java::lang::System::exit(23);
        }
    }
    auto const node = npc(factory)->newNode(bootHandle);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(node))
        ->append(u" created."_j)->toString());
    npc(::java::lang::Runtime::getRuntime())->addShutdownHook(new SplitStreamDistTest_main_2(env, node));
    {
        synchronized synchronized_0(node);
        {
            while (!npc(node)->isReady()) {
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Waiting for node to go ready.  "_j)->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());
                npc(node)->wait(5000);
            }
        }
    }
    auto app = new MySplitStreamClient(node, INSTANCE_);
    auto CHANNEL_ID = new ::rice::p2p::splitstream::ChannelId(static_cast< ::rice::p2p::commonapi::Id* >(generateId()));
    npc(app)->attachChannel(CHANNEL_ID);
    if(!isBootNode) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Sleeping(2) for "_j)->append(WAIT_TO_SUBSCRIBE_DELAY)
            ->append(u" at "_j)
            ->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());
        ::java::lang::Thread::sleep(WAIT_TO_SUBSCRIBE_DELAY);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Done(2) sleeping at "_j)->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());
    }
    npc(app)->subscribeToAllChannels();
    npc(app)->startPublishTask();
    if(artificialChurn) {
        while (true) {
            ::java::lang::Thread::sleep(int32_t(1) * int32_t(60) * int32_t(1000));
            if(!isBootNode) {
                if(npc(npc(env)->getRandomSource())->nextInt(60) == 0) {
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Killing self to cause churn. "_j)->append(npc(npc(env)->getTimeSource())->currentTimeMillis())
                        ->append(u":"_j)
                        ->append(static_cast< ::java::lang::Object* >(node))->toString());
                    ::java::lang::System::exit(25);
                }
            }
        }
    }
}

rice::pastry::Id* rice::p2p::splitstream::testing::SplitStreamDistTest::generateId()
{
    clinit();
    auto data = new ::int8_tArray(int32_t(20));
    (new ::java::util::Random(int32_t(100)))->nextBytes(data);
    return ::rice::pastry::Id::build(data);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamDistTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.testing.SplitStreamDistTest", 48);
    return c;
}

void rice::p2p::splitstream::testing::SplitStreamDistTest::clinit()
{
struct string_init_ {
    string_init_() {
    BOOTNODE_ = u"swsao9509"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        INSTANCE_ = u"DistSplitStreamTest"_j;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamDistTest::getClass0()
{
    return class_();
}

