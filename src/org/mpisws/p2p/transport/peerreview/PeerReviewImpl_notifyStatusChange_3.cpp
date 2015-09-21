// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_notifyStatusChange_3.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::PeerReviewImpl_notifyStatusChange_3::PeerReviewImpl_notifyStatusChange_3(PeerReviewImpl *PeerReviewImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* id, int32_t newStatus)
    : super(*static_cast< ::default_init_tag* >(0))
    , PeerReviewImpl_this(PeerReviewImpl_this)
    , id(id)
    , newStatus(newStatus)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl_notifyStatusChange_3::run()
{
    npc(PeerReviewImpl_this->callback)->notifyStatusChange(id, newStatus);
}

java::lang::String* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_notifyStatusChange_3::toString()
{
    return ::java::lang::StringBuilder().append(u"NotifyStatusChangeTask: "_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u"=>"_j)
        ->append(newStatus)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_notifyStatusChange_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_notifyStatusChange_3::getClass0()
{
    return class_();
}

