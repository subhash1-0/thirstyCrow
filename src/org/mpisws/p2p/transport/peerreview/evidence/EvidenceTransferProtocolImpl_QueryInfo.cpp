// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl_QueryInfo.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl_CacheInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

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

org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_QueryInfo::EvidenceTransferProtocolImpl_QueryInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , EvidenceTransferProtocolImpl_this(EvidenceTransferProtocolImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_QueryInfo::EvidenceTransferProtocolImpl_QueryInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, ::java::util::Collection* subjects, ::rice::Continuation* c) 
    : EvidenceTransferProtocolImpl_QueryInfo(EvidenceTransferProtocolImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(subjects,c);
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_QueryInfo::init()
{
    numWitnessesWaitingFor = int32_t(0);
    done_ = false;
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_QueryInfo::ctor(::java::util::Collection* subjects, ::rice::Continuation* c)
{
    super::ctor();
    init();
    subjectList = new ::java::util::HashMap();
    numWitnessesWaitingFor = npc(subjects)->size();
    this->c = c;
    npc(EvidenceTransferProtocolImpl_this->pendingQuery)->add(this);
    for (auto _i = npc(subjects)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::rawserialization::RawSerializable* s = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(_i->next());
        {
            auto foo = EvidenceTransferProtocolImpl_this->getWitnesses(s);
            npc(subjectList)->put(s, foo);
            if(foo == nullptr) {
                EvidenceTransferProtocolImpl_this->requestWitnesses(s);
            } else {
                numWitnessesWaitingFor--;
            }
        }
    }
    if(numWitnessesWaitingFor == 0) {
        done();
    }
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_QueryInfo::updateWitnesses(EvidenceTransferProtocolImpl_CacheInfo* idx)
{
    if(npc(subjectList)->containsKey(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idx)->subject))) {
        auto ret = java_cast< ::java::util::Collection* >(npc(subjectList)->put(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idx)->subject), npc(idx)->witness));
        if(ret == nullptr || npc(ret)->isEmpty()) {
            numWitnessesWaitingFor--;
            if(numWitnessesWaitingFor == 0) {
                done();
            }
        }
    }
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_QueryInfo::done()
{
    if(done_)
        return;

    done_ = true;
    npc(EvidenceTransferProtocolImpl_this->pendingQuery)->remove(this);
    npc(c)->receiveResult(subjectList);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_QueryInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.evidence.EvidenceTransferProtocolImpl.QueryInfo", 83);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_QueryInfo::getClass0()
{
    return class_();
}

