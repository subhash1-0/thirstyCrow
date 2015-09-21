// Generated from /pastry-2.1/src/rice/pastry/peerreview/PeerReviewCallbackImpl.java
#include <rice/pastry/peerreview/PeerReviewCallbackImpl_getWitnesses_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <org/mpisws/p2p/transport/peerreview/WitnessListener.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/peerreview/PeerReviewCallbackImpl.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>

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

rice::pastry::peerreview::PeerReviewCallbackImpl_getWitnesses_1::PeerReviewCallbackImpl_getWitnesses_1(PeerReviewCallbackImpl *PeerReviewCallbackImpl_this, ::rice::pastry::Id* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback)
    : super(*static_cast< ::default_init_tag* >(0))
    , PeerReviewCallbackImpl_this(PeerReviewCallbackImpl_this)
    , subject(subject)
    , callback(callback)
{
    clinit();
    ctor();
}

void rice::pastry::peerreview::PeerReviewCallbackImpl_getWitnesses_1::receiveResult(::java::util::Collection* result)
{
    auto ret = new ::java::util::ArrayList(npc(result)->size());
    for (auto _i = npc(result)->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandle* nh = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
        {
            if(!npc(npc(nh)->getId())->equals(subject))
                npc(ret)->add(static_cast< ::java::lang::Object* >(java_cast< ::rice::pastry::socket::TransportLayerNodeHandle* >(nh)));

        }
    }
    npc(PeerReviewCallbackImpl_this->logger)->log(::java::lang::StringBuilder().append(u"returning witnesses for "_j)->append(static_cast< ::java::lang::Object* >(subject))
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(ret))->toString());
    npc(callback)->notifyWitnessSet(subject, ret);
}

void rice::pastry::peerreview::PeerReviewCallbackImpl_getWitnesses_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::util::Collection* >(result));
}

void rice::pastry::peerreview::PeerReviewCallbackImpl_getWitnesses_1::receiveException(::java::lang::Exception* exception)
{
    throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::peerreview::PeerReviewCallbackImpl_getWitnesses_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::peerreview::PeerReviewCallbackImpl_getWitnesses_1::getClass0()
{
    return class_();
}

