// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord.java
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord.hpp>

#include <java/io/File.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceRecord.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/IdStrTranslator.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord_EvidenceRecordImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>
#include <org/mpisws/p2p/transport/util/FileOutputBuffer.hpp>

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

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::PeerInfoRecord(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::PeerInfoRecord(::java::lang::Object* id, PeerInfoStore* store) 
    : PeerInfoRecord(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,store);
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::ctor(::java::lang::Object* id, PeerInfoStore* store)
{
    super::ctor();
    this->subject = id;
    this->store = store;
    unansweredEvidence = new ::java::util::HashMap();
    answeredEvidence = new ::java::util::HashMap();
    status = STATUS_TRUSTED;
}

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::findEvidence(::java::lang::Object* originator, int64_t timestamp, bool create)
{
    auto foo = java_cast< ::java::util::Map* >(npc(answeredEvidence)->get(originator));
    if(foo != nullptr) {
        auto bar = java_cast< PeerInfoRecord_EvidenceRecordImpl* >(npc(foo)->get(::java::lang::Long::valueOf(timestamp)));
        if(bar != nullptr) {
            return bar;
        }
    }
    foo = java_cast< ::java::util::Map* >(npc(unansweredEvidence)->get(originator));
    if(foo == nullptr) {
        if(create) {
            foo = new ::java::util::HashMap();
            npc(unansweredEvidence)->put(originator, foo);
            auto bar = new PeerInfoRecord_EvidenceRecordImpl(this, originator, timestamp);
            npc(foo)->put(::java::lang::Long::valueOf(timestamp), bar);
            return bar;
        }
        return nullptr;
    } else {
        auto bar = java_cast< PeerInfoRecord_EvidenceRecordImpl* >(npc(foo)->get(::java::lang::Long::valueOf(timestamp)));
        if(bar == nullptr && create) {
            bar = new PeerInfoRecord_EvidenceRecordImpl(this, originator, timestamp);
        }
        return bar;
    }
}

int32_t org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::getStatus()
{
    return status;
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::getLastCheckedAuth()
{
    return lastCheckedAuth;
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::setLastCheckedAuth(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth, ::java::io::File* dir, IdStrTranslator* translator) /* throws(IOException) */
{
    auto buf = new ::org::mpisws::p2p::transport::util::FileOutputBuffer(new ::java::io::File(dir, ::java::lang::StringBuilder().append(npc(translator)->toString(java_cast< ::java::lang::Object* >(subject)))->append(u".info"_j)->toString()));
    npc(auth)->serialize(buf);
    npc(buf)->close();
    lastCheckedAuth = auth;
}

org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::getFirstUnansweredChallenge()
{
    return getFirstUnansweredChallenge(false);
}

org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::getFirstUnansweredChallenge(bool proof)
{
    for (auto _i = npc(npc(unansweredEvidence)->values())->iterator(); _i->hasNext(); ) {
        ::java::util::Map* foo = java_cast< ::java::util::Map* >(_i->next());
        {
            for (auto _i = npc(npc(foo)->values())->iterator(); _i->hasNext(); ) {
                PeerInfoRecord_EvidenceRecordImpl* bar = java_cast< PeerInfoRecord_EvidenceRecordImpl* >(_i->next());
                {
                    if(proof) {
                        if(npc(bar)->isProof_)
                            return bar;

                    } else {
                        return bar;
                    }
                }
            }
        }
    }
    return nullptr;
}

org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::getFirstProof()
{
    return getFirstUnansweredChallenge(true);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.infostore.PeerInfoRecord", 60);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord::getClass0()
{
    return class_();
}

