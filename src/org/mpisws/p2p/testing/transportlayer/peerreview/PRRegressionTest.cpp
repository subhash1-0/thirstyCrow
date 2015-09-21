// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/security/KeyPairGenerator.hpp>
#include <java/security/SecureRandom.hpp>
#include <java/security/spec/AlgorithmParameterSpec.hpp>
#include <java/security/spec/RSAKeyGenParameterSpec.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map_Entry.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/pki/x509/CAToolImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_getIdStrTranslator_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_PRRegressionTest_2.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_PRRegressionTest_3.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleSerializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdExtractor.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdSerializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_MyIdTL.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactoryImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/hasher/SHA1HashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/IdStrTranslator.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/StatusChangeListener.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>
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

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::PRRegressionTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::PRRegressionTest(int32_t millisToFinish)  /* throws(Exception) */
    : PRRegressionTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(millisToFinish);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::init()
{
    playerTable = new ::java::util::HashMap();
    aliceHandle = new PRRegressionTest_HandleImpl(u"alice"_j, new PRRegressionTest_IdImpl(int32_t(1)));
    bobHandle = new PRRegressionTest_HandleImpl(u"bob"_j, new PRRegressionTest_IdImpl(int32_t(2)));
    carolHandle = new PRRegressionTest_HandleImpl(u"carol"_j, new PRRegressionTest_IdImpl(int32_t(3)));
    recordedStatus = new ::java::util::HashMap();
}

int8_tArray*& org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::EMPTY_ARRAY()
{
    clinit();
    return EMPTY_ARRAY_;
}
int8_tArray* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::EMPTY_ARRAY_;

java::util::Map*& org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::idTLTable()
{
    clinit();
    return idTLTable_;
}
java::util::Map* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::idTLTable_;

org::mpisws::p2p::transport::peerreview::PeerReviewImpl* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::getPeerReview(PRRegressionTest_Player* player, PRRegressionTest_MyIdTL* transport, ::rice::environment::Environment* env)
{
    return new ::org::mpisws::p2p::transport::peerreview::PeerReviewImpl(transport, env, new PRRegressionTest_HandleSerializer(), new PRRegressionTest_IdSerializer(), new PRRegressionTest_IdExtractor(), getIdStrTranslator());
}

org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::getIdStrTranslator()
{
    return new PRRegressionTest_getIdStrTranslator_1(this);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::setLoggingParams(::rice::environment::Environment* env)
{
    npc(npc(env)->getParameters())->setInt(u"org.mpisws.p2p.testing.transportlayer.peerreview_loglevel"_j, ::rice::environment::logging::Logger::INFO);
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::getBogusApp(PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::peerreview::PeerReview* pr, ::rice::environment::Environment* env)
{
    return new PRRegressionTest_BogusApp(this, player, pr, env);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::buildCryptoMaterial(::rice::environment::Environment* env) /* throws(Exception) */
{
    auto random = new ::java::security::SecureRandom();
    caTool = ::org::mpisws::p2p::pki::x509::CAToolImpl::getCATool(u"CommitmentTest"_j, npc(u"foo"_j)->toCharArray_());
    keyPairGen = ::java::security::KeyPairGenerator::getInstance(u"RSA"_j, u"BC"_j);
    npc(keyPairGen)->initialize(static_cast< ::java::security::spec::AlgorithmParameterSpec* >(new ::java::security::spec::RSAKeyGenParameterSpec(int32_t(768), ::java::security::spec::RSAKeyGenParameterSpec::F4())), random);
    hasher = new ::org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider();
    historyFactory = new ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl(hasher, env);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::buildPlayers(::rice::environment::Environment* env) /* throws(Exception) */
{
    alice = new PRRegressionTest_Player(this, aliceHandle, bobHandle, env);
    bob = new PRRegressionTest_Player(this, bobHandle, aliceHandle, env);
    carol = new PRRegressionTest_Player(this, carolHandle, nullptr, env);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::setupWitnesses()
{
    npc(npc(carol)->witnessed)->add(npc(alice)->localHandle);
    npc(npc(carol)->witnessed)->add(npc(bob)->localHandle);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::addStatusNotification(PRRegressionTest_HandleImpl* localHandle, PRRegressionTest_IdImpl* id, int32_t newStatus)
{
    auto foo = java_cast< ::java::util::Map* >(npc(recordedStatus)->get(localHandle));
    if(foo == nullptr) {
        foo = new ::java::util::HashMap();
        npc(recordedStatus)->put(localHandle, foo);
    }
    npc(foo)->put(id, ::java::lang::Integer::valueOf(newStatus));
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::finish()
{
    for (auto _i = npc(npc(recordedStatus)->entrySet())->iterator(); _i->hasNext(); ) {
        ::java::util::Map_Entry* foo = java_cast< ::java::util::Map_Entry* >(_i->next());
        {
            for (auto _i = npc(npc(java_cast< ::java::util::Map* >(npc(foo)->getValue()))->entrySet())->iterator(); _i->hasNext(); ) {
                ::java::util::Map_Entry* i = java_cast< ::java::util::Map_Entry* >(_i->next());
                {
                    if((npc(java_cast< ::java::lang::Integer* >(npc(i)->getValue())))->intValue() != ::org::mpisws::p2p::transport::peerreview::infostore::StatusChangeListener::STATUS_TRUSTED) {
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Fail: "_j)->append(static_cast< ::java::lang::Object* >(java_cast< PRRegressionTest_HandleImpl* >(npc(foo)->getKey())))
                            ->append(u" found "_j)
                            ->append(static_cast< ::java::lang::Object* >(java_cast< PRRegressionTest_IdImpl* >(npc(i)->getKey())))
                            ->append(u" "_j)
                            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Integer* >(npc(i)->getValue())))->toString());
                        ::java::lang::System::exit(1);
                    }
                }
            }
        }
    }
    npc(logger)->log(u"Success"_j);
    ::java::lang::System::exit(1);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::ctor(int32_t millisToFinish) /* throws(Exception) */
{
    super::ctor();
    init();
    env = ::org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::generateEnvironment();
    npc(npc(env)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new PRRegressionTest_PRRegressionTest_2(this)), static_cast< int64_t >(millisToFinish));
    logger = npc(npc(env)->getLogManager())->getLogger(PRRegressionTest::class_(), nullptr);
    setLoggingParams(env);
    buildCryptoMaterial(env);
    npc(npc(env)->getSelectorManager())->invoke(new PRRegressionTest_PRRegressionTest_3(this));
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::main(::java::lang::StringArray* agrs) /* throws(Exception) */
{
    clinit();
    new PRRegressionTest(int32_t(45000));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRRegressionTest", 65);
    return c;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        EMPTY_ARRAY_ = new ::int8_tArray(int32_t(0));
        idTLTable_ = new ::java::util::HashMap();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest::getClass0()
{
    return class_();
}

