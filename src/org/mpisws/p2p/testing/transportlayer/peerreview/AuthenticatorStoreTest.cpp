// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/AuthenticatorStoreTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/AuthenticatorStoreTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/util/SortedSet.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/TestAuthenticatorStore.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/TestPeerReview.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializerImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::testing::transportlayer::peerreview::AuthenticatorStoreTest::AuthenticatorStoreTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::AuthenticatorStoreTest::AuthenticatorStoreTest()
    : AuthenticatorStoreTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t org::mpisws::p2p::testing::transportlayer::peerreview::AuthenticatorStoreTest::HASH_LEN;

constexpr int32_t org::mpisws::p2p::testing::transportlayer::peerreview::AuthenticatorStoreTest::SIGN_LEN;

void org::mpisws::p2p::testing::transportlayer::peerreview::AuthenticatorStoreTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    ::org::mpisws::p2p::transport::peerreview::PeerReview* pr = new TestPeerReview(env, new ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl(HASH_LEN, SIGN_LEN));
    auto store = new TestAuthenticatorStore(pr, false);
    auto id = new MyInetSocketAddress(::java::net::InetAddress::getLocalHost(), int32_t(6789));
    auto h1 = new ::int8_tArray(HASH_LEN);
    (*h1)[int32_t(2)] = 5;
    auto s1 = new ::int8_tArray(SIGN_LEN);
    (*s1)[int32_t(2)] = 17;
    auto a1 = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(42)), h1, s1);
    auto h2 = new ::int8_tArray(HASH_LEN);
    (*h2)[int32_t(2)] = 5;
    auto s2 = new ::int8_tArray(SIGN_LEN);
    (*s2)[int32_t(2)] = 17;
    auto a2 = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(42)), h2, s2);
    auto h3 = new ::int8_tArray(HASH_LEN);
    (*h3)[int32_t(2)] = 8;
    auto s3 = new ::int8_tArray(SIGN_LEN);
    (*s3)[int32_t(2)] = 17;
    auto a3 = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(42)), h3, s3);
    npc(store)->addAuthenticatorToMemory(id, new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(4)), h1, s1));
    npc(store)->addAuthenticatorToMemory(id, new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(7)), h1, s1));
    npc(store)->addAuthenticatorToMemory(id, new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(8)), h1, s1));
    npc(store)->addAuthenticatorToMemory(id, new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(9)), h1, s1));
    npc(store)->addAuthenticatorToMemory(id, new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(41)), h1, s1));
    npc(store)->addAuthenticatorToMemory(id, new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(43)), h1, s1));
    npc(store)->addAuthenticatorToMemory(id, new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(static_cast< int64_t >(int32_t(53)), h1, s1));
    npc(store)->addAuthenticatorToMemory(id, a1);
    npc(store)->addAuthenticatorToMemory(id, a2);
    auto fail = true;
    try {
        npc(store)->addAuthenticatorToMemory(id, a3);
        fail = false;
    } catch (::java::lang::RuntimeException* re) {
        fail = true;
    }
    if(!fail) {
        npc(::java::lang::System::out())->println(u"Allowed Duplicates, BAD!!!!"_j);
        return;
    }
    npc(store)->flushAuthenticatorsFromMemory(id, static_cast< int64_t >(int32_t(8)), static_cast< int64_t >(int32_t(42)));
    if(npc(npc(store)->findSubject(id))->size() != 4) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"flush failed! "_j)->append(static_cast< ::java::lang::Object* >(npc(store)->findSubject(id)))->toString());
    }
    npc(store)->flushAuthenticatorsFromMemory(id, static_cast< int64_t >(int32_t(43)), static_cast< int64_t >(int32_t(43)));
    if(npc(npc(store)->findSubject(id))->size() != 3) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"flush failed! "_j)->append(static_cast< ::java::lang::Object* >(npc(store)->findSubject(id)))->toString());
    }
    npc(::java::lang::System::out())->println(u"success"_j);
    npc(env)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::AuthenticatorStoreTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.AuthenticatorStoreTest", 71);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::AuthenticatorStoreTest::getClass0()
{
    return class_();
}

