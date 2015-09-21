// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/EncryptedFileTest.java
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_2.hpp>
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_3.hpp>
#include <org/mpisws/p2p/testing/filetransfer/EncryptedFileTest_main_4.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>

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

org::mpisws::p2p::testing::filetransfer::EncryptedFileTest::EncryptedFileTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::filetransfer::EncryptedFileTest::EncryptedFileTest()
    : EncryptedFileTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::testing::filetransfer::EncryptedFileTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto const env = new ::rice::environment::Environment();
    auto local = ::java::net::InetAddress::getLocalHost();
    auto const logger = npc(npc(env)->getLogManager())->getLogger(EncryptedFileTest::class_(), nullptr);
    auto errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    npc(logger)->log(u"Encrypted Test"_j);
    auto addr1 = new ::java::net::InetSocketAddress(local, int32_t(9001));
    ::org::mpisws::p2p::transport::wire::WireTransportLayer* wtl1 = new ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl(addr1, env, errorHandler);
    auto idtl1 = new ::org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer(wtl1, new ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer(), nullptr, env, errorHandler);
    ::org::mpisws::p2p::transport::liveness::LivenessTransportLayer* ltl1 = new ::org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl(idtl1, env, errorHandler, int32_t(300000));
    npc(ltl1)->addLivenessListener(new EncryptedFileTest_main_1(logger));
    auto etl1 = new ::org::mpisws::p2p::transport::rc4::RC4TransportLayer(ltl1, env, u"badpassword"_j, errorHandler);
    npc(etl1)->setCallback(static_cast< ::org::mpisws::p2p::transport::TransportLayerCallback* >(new EncryptedFileTest_main_2(logger, env)));
    auto addr2 = new ::java::net::InetSocketAddress(local, int32_t(9002));
    ::org::mpisws::p2p::transport::wire::WireTransportLayer* wtl2 = new ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl(addr2, env, errorHandler);
    auto idtl2 = new ::org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer(wtl2, new ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer(), nullptr, env, errorHandler);
    ::org::mpisws::p2p::transport::liveness::LivenessTransportLayer* ltl2 = new ::org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl(idtl2, env, errorHandler, int32_t(300000));
    npc(ltl2)->addLivenessListener(new EncryptedFileTest_main_3(logger));
    npc(ltl2)->checkLiveness(addr1, nullptr);
    auto etl2 = new ::org::mpisws::p2p::transport::rc4::RC4TransportLayer(ltl2, env, u"badpassword"_j, errorHandler);
    npc(etl2)->openSocket(static_cast< ::java::lang::Object* >(addr1), static_cast< ::org::mpisws::p2p::transport::SocketCallback* >(new EncryptedFileTest_main_4(logger, env)), static_cast< ::java::util::Map* >(nullptr));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::filetransfer::EncryptedFileTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.filetransfer.EncryptedFileTest", 53);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::filetransfer::EncryptedFileTest::getClass0()
{
    return class_();
}

