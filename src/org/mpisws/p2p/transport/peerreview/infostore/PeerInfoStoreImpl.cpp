// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStoreImpl.java
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStoreImpl.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializer.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceRecord.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceSerializer.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/IdStrTranslator.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord_EvidenceRecordImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/StatusChangeListener.hpp>
#include <org/mpisws/p2p/transport/util/FileInputBuffer.hpp>
#include <org/mpisws/p2p/transport/util/FileOutputBuffer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
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

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
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

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::PeerInfoStoreImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::PeerInfoStoreImpl(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, IdStrTranslator* stringTranslator, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* authSerializer, EvidenceSerializer* evidenceSerializer, ::rice::environment::Environment* env) 
    : PeerInfoStoreImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(transport,stringTranslator,authSerializer,evidenceSerializer,env);
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::ctor(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, IdStrTranslator* stringTranslator, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* authSerializer, EvidenceSerializer* evidenceSerializer, ::rice::environment::Environment* env)
{
    super::ctor();
    this->peerInfoRecords = new ::java::util::HashMap();
    this->directory = nullptr;
    this->notificationEnabled = true;
    this->transport = transport;
    this->listener = nullptr;
    this->stringTranslator = stringTranslator;
    this->authSerializer = authSerializer;
    this->environment = env;
    this->evidenceSerializer = evidenceSerializer;
    this->logger = npc(npc(env)->getLogManager())->getLogger(PeerInfoStoreImpl::class_(), nullptr);
}

bool org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::isProof(Evidence* e)
{
    clinit();
    switch (npc(e)->getEvidenceType()) {
    case CHAL_AUDIT:
        return false;
    case CHAL_SEND:
        return false;
    case PROOF_INCONSISTENT:
        return true;
    case PROOF_NONCONFORMANT:
        return true;
    default:
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Cannot evaluate isProof("_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u"):"_j)
            ->append(npc(e)->getEvidenceType())->toString());
    }

}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::setStatusChangeListener(StatusChangeListener* listener)
{
    this->listener = listener;
}

org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::findEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp)
{
    return findEvidence(originator, subject, timestamp, false);
}

org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::findEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, bool create)
{
    auto rec = find(subject, create);
    if(rec == nullptr)
        return nullptr;

    return npc(rec)->findEvidence(originator, timestamp, create);
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::markEvidenceAvailable(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, bool isProof, ::java::lang::Object* interestedParty)
{
    auto rec = find(subject, true);
    EvidenceRecord* evi = npc(rec)->findEvidence(originator, timestamp, true);
    /* assert((rec != nullptr && evi != nullptr)) */ ;
    if(interestedParty != nullptr) {
        npc(evi)->setInterestedParty(interestedParty);
    }
    npc(evi)->setIsProof(isProof);
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::markResponseAvailable(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp)
{
    auto rec = find(subject, true);
    EvidenceRecord* evi = npc(rec)->findEvidence(originator, timestamp, true);
    npc(evi)->setHasResponse();
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::addEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, Evidence* evidence) /* throws(IOException) */
{
    addEvidence(originator, subject, timestamp, evidence, static_cast< ::java::lang::Object* >(nullptr));
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::addEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, Evidence* evidence, ::java::lang::Object* interestedParty) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"addEvidence(orig="_j)->append(static_cast< ::java::lang::Object* >(originator))
            ->append(u", subj="_j)
            ->append(static_cast< ::java::lang::Object* >(subject))
            ->append(u", seq="_j)
            ->append(timestamp)
            ->append(u")"_j)->toString());

    auto proof = isProof(evidence);
    auto outFile = getFile(subject, originator, timestamp, (proof ? u"proof"_j : u"challenge"_j));
    auto buf = new ::org::mpisws::p2p::transport::util::FileOutputBuffer(outFile);
    npc(buf)->writeByte(static_cast< int8_t >(npc(evidence)->getEvidenceType()));
    npc(evidence)->serialize(buf);
    npc(buf)->close();
    markEvidenceAvailable(originator, subject, timestamp, proof, interestedParty);
}

java::io::File* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::getFile(::java::lang::Object* subject, ::java::lang::Object* originator, int64_t timestamp, ::java::lang::String* suffix)
{
    auto outFile = new ::java::io::File(directory, ::java::lang::StringBuilder().append(npc(stringTranslator)->toString(subject))->append(u"-"_j)
        ->append(npc(stringTranslator)->toString(originator))
        ->append(u"-"_j)
        ->append(timestamp)
        ->append(u"."_j)
        ->append(suffix)->toString());
    return outFile;
}

int32_t org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::getStatus(::java::lang::Object* id)
{
    auto rec = find(id, false);
    return (rec != nullptr) ? npc(rec)->getStatus() : STATUS_TRUSTED;
}

bool org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::setStorageDirectory(::java::io::File* directory) /* throws(IOException) */
{
    if(!npc(directory)->exists()) {
        npc(directory)->mkdirs();
    } else {
        if(!npc(directory)->isDirectory()) {
            throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(npc(directory)->getAbsolutePath())->append(u" is not a directory."_j)->toString());
        }
    }
    this->directory = directory;
    auto notificationWasEnabled = notificationEnabled;
    notificationEnabled = false;
    auto bar = npc(directory)->listFiles();
    if(bar != nullptr) {
        for(auto ent : *npc(bar)) {
            if(npc(ent)->isDirectory())
                continue;

            auto d_name = npc(ent)->getName();
            auto foo = npc(d_name)->split(u"\\."_j);
            if(npc(foo)->length != 2)
                continue;

            auto first = (*foo)[int32_t(0)];
            auto suffix = (*foo)[int32_t(1)];
            if(npc(suffix)->equals(static_cast< ::java::lang::Object* >(u"info"_j))) {
                auto id = java_cast< ::java::lang::Object* >(npc(stringTranslator)->readIdentifierFromString(first));
                auto buf = new ::org::mpisws::p2p::transport::util::FileInputBuffer(ent, logger);
                auto lastAuth = npc(authSerializer)->deserialize(buf);
                npc(buf)->close();
                setLastCheckedAuth(id, lastAuth);
            } else if(npc(suffix)->equals(static_cast< ::java::lang::Object* >(u"challenge"_j)) || npc(suffix)->equals(static_cast< ::java::lang::Object* >(u"response"_j)) || npc(suffix)->equals(static_cast< ::java::lang::Object* >(u"proof"_j))) {
                auto parts = npc(first)->split(u"-"_j);
                if(npc(parts)->length != 3)
                    throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Error reading filename :"_j)->append(static_cast< ::java::lang::Object* >(ent))
                        ->append(u" did not split into 3 parts:"_j)
                        ->append(::java::util::Arrays::toString(static_cast< ::java::lang::ObjectArray* >(parts)))->toString());

                auto subject = java_cast< ::java::lang::Object* >(npc(stringTranslator)->readIdentifierFromString((*parts)[int32_t(0)]));
                auto originator = java_cast< ::java::lang::Object* >(npc(stringTranslator)->readIdentifierFromString((*parts)[int32_t(1)]));
                auto seq = ::java::lang::Long::parseLong((*parts)[int32_t(2)]);
                if(npc(suffix)->equals(static_cast< ::java::lang::Object* >(u"challenge"_j))) {
                    markEvidenceAvailable(originator, subject, seq, false, nullptr);
                } else if(npc(suffix)->equals(static_cast< ::java::lang::Object* >(u"proof"_j))) {
                    markEvidenceAvailable(originator, subject, seq, true, nullptr);
                } else if(npc(suffix)->equals(static_cast< ::java::lang::Object* >(u"response"_j))) {
                    markResponseAvailable(originator, subject, seq);
                }
            }
        }
    }
    notificationEnabled = notificationWasEnabled;
    return true;
}

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::find(::java::lang::Object* id)
{
    return find(id, false);
}

org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::find(::java::lang::Object* id, bool create)
{
    auto ret = java_cast< PeerInfoRecord* >(npc(peerInfoRecords)->get(id));
    if(ret == nullptr && create) {
        ret = new PeerInfoRecord(id, this);
        npc(peerInfoRecords)->put(id, ret);
    }
    return ret;
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::getLastCheckedAuth(::java::lang::Object* id)
{
    auto rec = find(id, false);
    if(rec == nullptr)
        return nullptr;

    return npc(rec)->getLastCheckedAuth();
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::setLastCheckedAuth(::java::lang::Object* id, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth)
{
    auto rec = find(id, true);
    try {
        npc(rec)->setLastCheckedAuth(auth, directory, stringTranslator);
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

org::mpisws::p2p::transport::peerreview::infostore::Evidence* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::getEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp) /* throws(IOException) */
{
    auto evi = findEvidence(originator, subject, timestamp, false);
    if(evi == nullptr)
        return nullptr;

    auto infile = getFile(subject, originator, timestamp, npc(evi)->isProof() ? u"proof"_j : u"challenge"_j);
    auto buf = new ::org::mpisws::p2p::transport::util::FileInputBuffer(infile, logger);
    auto type = npc(buf)->readByte();
    auto e = npc(evidenceSerializer)->deserialize(buf, type, false);
    npc(buf)->close();
    return e;
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::addResponse(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, Evidence* response) /* throws(IOException) */
{
    auto evi = findEvidence(originator, subject, timestamp);
    /* assert((evi != nullptr && !npc(evi)->isProof() && !npc(evi)->hasResponse())) */ ;
    auto outfile = new ::org::mpisws::p2p::transport::util::FileOutputBuffer(getFile(subject, originator, timestamp, u"response"_j));
    npc(outfile)->writeByte(static_cast< int8_t >(npc(response)->getEvidenceType()));
    npc(response)->serialize(outfile);
    npc(outfile)->close();
    markResponseAvailable(originator, subject, timestamp);
}

java::lang::String* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::getHistoryName(::java::lang::Object* subject)
{
    return (new ::java::io::File(directory, ::java::lang::StringBuilder().append(npc(stringTranslator)->toString(subject))->append(u"-log"_j)->toString()))->toString();
}

void org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::notifyStatusChanged(::java::lang::Object* subject, int32_t newStatus)
{
    if(!notificationEnabled || listener == nullptr)
        return;

    npc(listener)->notifyStatusChange(subject, newStatus);
}

org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::statFirstUnansweredChallenge(::java::lang::Object* subject)
{
    auto rec = find(subject);
    if(rec == nullptr)
        return nullptr;

    return npc(rec)->getFirstUnansweredChallenge();
}

org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::statProof(::java::lang::Object* subject)
{
    auto rec = find(subject);
    if(rec == nullptr)
        return nullptr;

    return npc(rec)->getFirstProof();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.infostore.PeerInfoStoreImpl", 63);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl::getClass0()
{
    return class_();
}

