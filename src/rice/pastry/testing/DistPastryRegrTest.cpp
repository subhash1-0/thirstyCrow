// Generated from /pastry-2.1/src/rice/pastry/testing/DistPastryRegrTest.java
#include <rice/pastry/testing/DistPastryRegrTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/UnknownHostException.hpp>
#include <java/util/Collections.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/dist/DistPastryNodeFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/IPNodeIdFactory.hpp>
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

rice::pastry::testing::DistPastryRegrTest::DistPastryRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::DistPastryRegrTest::DistPastryRegrTest(::rice::environment::Environment* env)  /* throws(IOException) */
    : DistPastryRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

int32_t& rice::pastry::testing::DistPastryRegrTest::port()
{
    clinit();
    return port_;
}
int32_t rice::pastry::testing::DistPastryRegrTest::port_;

java::lang::String*& rice::pastry::testing::DistPastryRegrTest::bshost()
{
    clinit();
    return bshost_;
}
java::lang::String* rice::pastry::testing::DistPastryRegrTest::bshost_;

int32_t& rice::pastry::testing::DistPastryRegrTest::bsport()
{
    clinit();
    return bsport_;
}
int32_t rice::pastry::testing::DistPastryRegrTest::bsport_;

int32_t& rice::pastry::testing::DistPastryRegrTest::numnodes()
{
    clinit();
    return numnodes_;
}
int32_t rice::pastry::testing::DistPastryRegrTest::numnodes_;

int32_t& rice::pastry::testing::DistPastryRegrTest::protocol()
{
    clinit();
    return protocol_;
}
int32_t rice::pastry::testing::DistPastryRegrTest::protocol_;

void rice::pastry::testing::DistPastryRegrTest::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(env);
    pastryNodesSorted = ::java::util::Collections::synchronizedSortedMap(pastryNodesSorted);
    factory = ::rice::pastry::dist::DistPastryNodeFactory::getFactory(new ::rice::pastry::standard::IPNodeIdFactory(::java::net::InetAddress::getLocalHost(), port_, env), protocol_, port_, env);
    try {
        bsaddress = new ::java::net::InetSocketAddress(bshost_, bsport_);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR (init): "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

rice::pastry::NodeHandle* rice::pastry::testing::DistPastryRegrTest::getBootstrap(bool firstNode)
{
    if(firstNode)
        return npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(bsaddress);
    else {
        ::java::net::InetSocketAddress* addr = nullptr;
        try {
            addr = new ::java::net::InetSocketAddress(npc(::java::net::InetAddress::getLocalHost())->getHostName(), port_);
        } catch (::java::net::UnknownHostException* e) {
            npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(e));
        }
        return npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(addr);
    }
}

void rice::pastry::testing::DistPastryRegrTest::doInitstuff(::java::lang::StringArray* args)
{
    clinit();
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-help"_j))) {
            npc(::java::lang::System::out())->println(u"Usage: DistPastryRegrTest [-port p] [-protocol (rmi|wire|socket)] [-nodes n] [-bootstrap host[:port]] [-help]"_j);
            ::java::lang::System::exit(1);
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-port"_j)) && i + int32_t(1) < npc(args)->length) {
            auto p = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(p > 0)
                port_ = p;

            break;
        }
    }
    bsport_ = port_;
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-bootstrap"_j)) && i + int32_t(1) < npc(args)->length) {
            auto str = (*args)[i + int32_t(1)];
            auto index = npc(str)->indexOf(static_cast< int32_t >(u':'));
            if(index == -int32_t(1)) {
                bshost_ = str;
                bsport_ = port_;
            } else {
                bshost_ = npc(str)->substring(0, index);
                bsport_ = ::java::lang::Integer::parseInt(npc(str)->substring(index + int32_t(1)));
                if(bsport_ <= 0)
                    bsport_ = port_;

            }
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-nodes"_j)) && i + int32_t(1) < npc(args)->length) {
            auto n = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(n > 0)
                numnodes_ = n;

            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-protocol"_j)) && i + int32_t(1) < npc(args)->length) {
            auto s = (*args)[i + int32_t(1)];
            if(npc(s)->equalsIgnoreCase(u"socket"_j))
                protocol_ = ::rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_SOCKET();
            else
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR: Unsupported protocol: "_j)->append(s)->toString());
            break;
        }
    }
}

void rice::pastry::testing::DistPastryRegrTest::registerapp(::rice::pastry::PastryNode* pn, RegrTestApp* app)
{
}

bool rice::pastry::testing::DistPastryRegrTest::simulate()
{
    return false;
}

void rice::pastry::testing::DistPastryRegrTest::pause(int32_t ms)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Waiting "_j)->append(ms)
        ->append(u"ms..."_j)->toString());
    try {
        wait(ms);
    } catch (::java::lang::InterruptedException* e) {
    }
}

bool rice::pastry::testing::DistPastryRegrTest::isReallyAlive(::rice::pastry::NodeHandle* nh)
{
    return false;
}

void rice::pastry::testing::DistPastryRegrTest::killNode(::rice::pastry::PastryNode* pn)
{
    npc(pn)->destroy();
    pause(int32_t(50000));
}

void rice::pastry::testing::DistPastryRegrTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    doInitstuff(args);
    auto pt = new DistPastryRegrTest(new ::rice::environment::Environment());
    mainfunc(pt, args, numnodes_, 1, 1, 20, 4);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::DistPastryRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.DistPastryRegrTest", 38);
    return c;
}

void rice::pastry::testing::DistPastryRegrTest::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        port_ = int32_t(5009);
        bsport_ = int32_t(5009);
        numnodes_ = int32_t(10);
        protocol_ = ::rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_DEFAULT();
        {
            try {
                bshost_ = npc(::java::net::InetAddress::getLocalHost())->getHostName();
            } catch (::java::net::UnknownHostException* e) {
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Error determining local host: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
            }
        }
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::DistPastryRegrTest::getClass0()
{
    return class_();
}

