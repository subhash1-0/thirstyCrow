// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/VerifierFactoryImpl.java
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierFactoryImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySM.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/selector/SelectorManager.hpp>

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

org::mpisws::p2p::transport::peerreview::replay::VerifierFactoryImpl::VerifierFactoryImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::VerifierFactoryImpl::VerifierFactoryImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview) 
    : VerifierFactoryImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierFactoryImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview)
{
    super::ctor();
    this->peerreview = peerreview;
    this->logger = npc(npc(npc(peerreview)->getEnvironment())->getLogManager())->getLogger(VerifierFactoryImpl::class_(), nullptr);
}

org::mpisws::p2p::transport::peerreview::replay::Verifier* org::mpisws::p2p::transport::peerreview::replay::VerifierFactoryImpl::getVerifier(::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::rice::p2p::commonapi::rawserialization::RawSerializable* localHandle, int64_t firstEntryToReplay, int64_t initialTime, ::java::lang::Object* extInfo) /* throws(IOException) */
{
    auto env = ::org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::generateEnvironment(npc(localHandle)->toString(), 0, 0, npc(npc(peerreview)->getEnvironment())->getLogManager());
    auto ret = new VerifierImpl(peerreview, env, history, localHandle, firstEntryToReplay, extInfo);
    npc((java_cast< ::org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM* >(npc(env)->getSelectorManager())))->setVerifier(ret);
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::VerifierFactoryImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.VerifierFactoryImpl", 62);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::VerifierFactoryImpl::getClass0()
{
    return class_();
}

