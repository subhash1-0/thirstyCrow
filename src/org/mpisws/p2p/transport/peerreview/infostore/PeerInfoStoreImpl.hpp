// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStoreImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl
    : public virtual ::java::lang::Object
    , public virtual PeerInfoStore
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport {  };
    ::java::io::File* directory {  };
    ::java::util::Map* peerInfoRecords {  };
    StatusChangeListener* listener {  };
    bool notificationEnabled {  };

public: /* protected */
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };

public: /* package */
    IdStrTranslator* stringTranslator {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* authSerializer {  };
    EvidenceSerializer* evidenceSerializer {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, IdStrTranslator* stringTranslator, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* authSerializer, EvidenceSerializer* evidenceSerializer, ::rice::environment::Environment* env);

public:
    static bool isProof(Evidence* e);
    void setStatusChangeListener(StatusChangeListener* listener) override;
    EvidenceRecord* findEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp) override;
    EvidenceRecord* findEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, bool create) override;
    virtual void markEvidenceAvailable(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, bool isProof, ::java::lang::Object* interestedParty);
    virtual void markResponseAvailable(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp);
    void addEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, Evidence* evidence) /* throws(IOException) */ override;
    void addEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, Evidence* evidence, ::java::lang::Object* interestedParty) /* throws(IOException) */ override;

public: /* protected */
    virtual ::java::io::File* getFile(::java::lang::Object* subject, ::java::lang::Object* originator, int64_t timestamp, ::java::lang::String* suffix);

public:
    int32_t getStatus(::java::lang::Object* id) override;
    bool setStorageDirectory(::java::io::File* directory) /* throws(IOException) */ override;
    virtual PeerInfoRecord* find(::java::lang::Object* id);
    virtual PeerInfoRecord* find(::java::lang::Object* id, bool create);
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* getLastCheckedAuth(::java::lang::Object* id) override;
    void setLastCheckedAuth(::java::lang::Object* id, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth) override;
    Evidence* getEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp) /* throws(IOException) */ override;
    void addResponse(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, Evidence* response) /* throws(IOException) */ override;
    ::java::lang::String* getHistoryName(::java::lang::Object* subject) override;
    void notifyStatusChanged(::java::lang::Object* subject, int32_t newStatus) override;
    EvidenceRecord* statFirstUnansweredChallenge(::java::lang::Object* subject) override;
    EvidenceRecord* statProof(::java::lang::Object* subject) override;

    // Generated
    PeerInfoStoreImpl(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, IdStrTranslator* stringTranslator, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* authSerializer, EvidenceSerializer* evidenceSerializer, ::rice::environment::Environment* env);
protected:
    PeerInfoStoreImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
