// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord.java
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord_EvidenceRecordImpl.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/StatusConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>

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

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::PeerInfoRecord_EvidenceRecordImpl(PeerInfoRecord *PeerInfoRecord_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PeerInfoRecord_this(PeerInfoRecord_this)
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::PeerInfoRecord_EvidenceRecordImpl(PeerInfoRecord *PeerInfoRecord_this, ::java::lang::Object* originator, int64_t timestamp) 
    : PeerInfoRecord_EvidenceRecordImpl(PeerInfoRecord_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(originator,timestamp);
}

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::PeerInfoRecord_EvidenceRecordImpl(PeerInfoRecord *PeerInfoRecord_this, ::java::lang::Object* originator, int64_t timestamp, bool isProof, ::java::lang::Object* interestedParty) 
    : PeerInfoRecord_EvidenceRecordImpl(PeerInfoRecord_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(originator,timestamp,isProof,interestedParty);
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::ctor(::java::lang::Object* originator, int64_t timestamp)
{
    ctor(originator, timestamp, false, nullptr);
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::ctor(::java::lang::Object* originator, int64_t timestamp, bool isProof, ::java::lang::Object* interestedParty)
{
    super::ctor();
    this->originator = originator;
    this->timestamp = timestamp;
    this->isProof_ = isProof;
    this->interestedParty = interestedParty;
}

bool org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::hasResponse()
{
    auto foo = java_cast< ::java::util::Map* >(npc(PeerInfoRecord_this->answeredEvidence)->get(java_cast< ::java::lang::Object* >(originator)));
    if(foo == nullptr)
        return false;

    return npc(foo)->containsKey(::java::lang::Long::valueOf(timestamp));
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::setIsProof(bool isProof)
{
    this->isProof_ = isProof;
    if(isProof && (PeerInfoRecord_this->status != ::org::mpisws::p2p::transport::peerreview::StatusConstants::STATUS_EXPOSED)) {
        PeerInfoRecord_this->status = ::org::mpisws::p2p::transport::peerreview::StatusConstants::STATUS_EXPOSED;
        npc(PeerInfoRecord_this->store)->notifyStatusChanged(java_cast< ::java::lang::Object* >(PeerInfoRecord_this->subject), ::org::mpisws::p2p::transport::peerreview::StatusConstants::STATUS_EXPOSED);
    } else if(!isProof && (PeerInfoRecord_this->status == ::org::mpisws::p2p::transport::peerreview::StatusConstants::STATUS_TRUSTED)) {
        PeerInfoRecord_this->status = ::org::mpisws::p2p::transport::peerreview::StatusConstants::STATUS_SUSPECTED;
        npc(PeerInfoRecord_this->store)->notifyStatusChanged(java_cast< ::java::lang::Object* >(PeerInfoRecord_this->subject), ::org::mpisws::p2p::transport::peerreview::StatusConstants::STATUS_SUSPECTED);
    }
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::setInterestedParty(::java::lang::Object* interestedParty)
{
    this->interestedParty = interestedParty;
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::setHasResponse()
{
    /* assert((!isProof())) */ ;
    auto foo = java_cast< ::java::util::Map* >(npc(PeerInfoRecord_this->unansweredEvidence)->get(java_cast< ::java::lang::Object* >(originator)));
    if(foo != nullptr) {
        npc(foo)->remove(::java::lang::Long::valueOf(timestamp));
        if(npc(foo)->isEmpty()) {
            npc(PeerInfoRecord_this->unansweredEvidence)->remove(java_cast< ::java::lang::Object* >(originator));
        }
    }
    foo = java_cast< ::java::util::Map* >(npc(PeerInfoRecord_this->answeredEvidence)->get(java_cast< ::java::lang::Object* >(originator)));
    if(foo == nullptr) {
        foo = new ::java::util::HashMap();
        npc(PeerInfoRecord_this->answeredEvidence)->put(java_cast< ::java::lang::Object* >(originator), foo);
    }
    npc(foo)->put(::java::lang::Long::valueOf(timestamp), this);
    if((PeerInfoRecord_this->status == ::org::mpisws::p2p::transport::peerreview::StatusConstants::STATUS_SUSPECTED) && npc(PeerInfoRecord_this->unansweredEvidence)->isEmpty()) {
        PeerInfoRecord_this->status = ::org::mpisws::p2p::transport::peerreview::StatusConstants::STATUS_TRUSTED;
        npc(PeerInfoRecord_this->store)->notifyStatusChanged(java_cast< ::java::lang::Object* >(PeerInfoRecord_this->subject), ::org::mpisws::p2p::transport::peerreview::StatusConstants::STATUS_TRUSTED);
    }
}

bool org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::isProof()
{
    return isProof_;
}

int64_t org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::getTimeStamp()
{
    return timestamp;
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::getOriginator()
{
    return java_cast< ::java::lang::Object* >(originator);
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::getInterestedParty()
{
    return java_cast< ::java::lang::Object* >(interestedParty);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.infostore.PeerInfoRecord.EvidenceRecordImpl", 79);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl::getClass0()
{
    return class_();
}

