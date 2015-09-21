// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player.hpp>

#include <java/io/File.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/security/KeyPair.hpp>
#include <java/security/KeyPairGenerator.hpp>
#include <java/security/cert/X509Certificate.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/pki/x509/CATool.hpp>
#include <org/mpisws/p2p/pki/x509/X509SerializerImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player_Player_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player_getIdTransport_2.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusTransport.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdSerializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_MyIdTL.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/hasher/SHA1HashProvider.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/selector/SelectorManager.hpp>
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
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::File, ::java::lang::ObjectArray, SerializableArray, ::java::lang::ComparableArray > FileArray;
    } // io
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::PRRegressionTest_Player(PRRegressionTest *PRRegressionTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_this(PRRegressionTest_this)
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::PRRegressionTest_Player(PRRegressionTest *PRRegressionTest_this, PRRegressionTest_HandleImpl* localHandle, PRRegressionTest_HandleImpl* dstHandle, ::rice::environment::Environment* env2)  /* throws(Exception) */
    : PRRegressionTest_Player(PRRegressionTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(localHandle,dstHandle,env2);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::init()
{
    witnessed = new ::java::util::ArrayList();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::ctor(PRRegressionTest_HandleImpl* localHandle, PRRegressionTest_HandleImpl* dstHandle, ::rice::environment::Environment* env2) /* throws(Exception) */
{
    super::ctor();
    init();
    this->destHandle = dstHandle;
    env = cloneEnvironment(env2, npc(localHandle)->name, npc(npc(localHandle)->id)->id);
    this->logger = npc(npc(env)->getLogManager())->getLogger(PRRegressionTest_Player::class_(), nullptr);
    auto f = new ::java::io::File(npc(localHandle)->name);
    if(npc(f)->exists()) {
        auto f2 = new ::java::io::File(f, u"peers"_j);
        auto foo = npc(f2)->listFiles();
        if(foo != nullptr) {
            for (auto c = int32_t(0); c < npc(foo)->length; c++) {
                npc((*foo)[c])->delete_();
            }
        }
        foo = npc(f)->listFiles();
        if(foo != nullptr) {
            for (auto c = int32_t(0); c < npc(foo)->length; c++) {
                npc((*foo)[c])->delete_();
            }
        }
    }
    this->localHandle = localHandle;
    npc(PRRegressionTest_this->playerTable)->put(localHandle, this);
    pair = npc(PRRegressionTest_this->keyPairGen)->generateKeyPair();
    cert = npc(PRRegressionTest_this->caTool)->sign(npc(localHandle)->name, npc(pair)->getPublic());
    t1 = getTL();
    transport = getIdTransport();
    npc(PRRegressionTest::idTLTable())->put(localHandle, transport);
    pr = PRRegressionTest_this->getPeerReview(this, transport, env);
    app = getApp();
    npc(pr)->setApp(app);
    npc(npc(env)->getSelectorManager())->invoke(new PRRegressionTest_Player_Player_1(this, env2));
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::getApp()
{
    return PRRegressionTest_this->getBogusApp(this, pr, env);
}

rice::environment::Environment* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::cloneEnvironment(::rice::environment::Environment* env2, ::java::lang::String* name, int32_t id)
{
    return npc(env2)->cloneEnvironment(name);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::buildPlayerCryptoStuff()
{
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::getTL() /* throws(Exception) */
{
    return new PRRegressionTest_BogusTransport(localHandle, cert, env);
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::getIdTransport() /* throws(Exception) */
{
    return new PRRegressionTest_Player_getIdTransport_2(this, new PRRegressionTest_IdSerializer(), new ::org::mpisws::p2p::pki::x509::X509SerializerImpl(), npc(this->localHandle)->id, cert, npc(pair)->getPrivate(), t1, new ::org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider(), env);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRRegressionTest.Player", 72);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player::getClass0()
{
    return class_();
}

