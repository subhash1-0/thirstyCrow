// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStoreImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl
    : public virtual ::java::lang::Object
    , public virtual AuthenticatorStore
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    bool allowDuplicateSeqs {  };

public: /* package */
    ::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview {  };
    int32_t numSubjects {  };
    ::rice::p2p::util::RandomAccessFileIOBuffer* authFile {  };
    ::java::util::Map* authenticators {  };
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::util::Serializer* idSerializer {  };
    AuthenticatorSerializer* authenticatorSerializer {  };
    bool memoryBufferDisabled {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview);
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, bool allowDuplicateSeqs);

public:
    virtual void destroy();
    void setFilename(::java::io::File* file) /* throws(IOException) */ override;

public: /* protected */
    virtual void addAuthenticatorToMemory(::rice::p2p::commonapi::rawserialization::RawSerializable* id, Authenticator* authenticator);
    virtual void flushAuthenticatorsFromMemory(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq);
    virtual ::java::util::SortedSet* findSubject(::rice::p2p::commonapi::rawserialization::RawSerializable* id);

public:
    virtual void addAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id, Authenticator* authenticator);
    virtual void flushAuthenticatorsFor(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq);
    virtual void flushAuthenticatorsFor(::rice::p2p::commonapi::rawserialization::RawSerializable* id);
    void garbageCollect() /* throws(IOException) */ override;
    int32_t getAuthenticatorSizeBytes() override;
    virtual ::java::util::List* getAuthenticators(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq);
    virtual ::java::util::List* getAuthenticators(::rice::p2p::commonapi::rawserialization::RawSerializable* id);
    virtual Authenticator* getLastAuthenticatorBefore(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq);
    virtual Authenticator* getMostRecentAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id);
    int32_t getNumSubjects() override;
    virtual Authenticator* getOldestAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id);
    ::java::util::List* getSubjects() override;
    virtual int32_t numAuthenticatorsFor(::rice::p2p::commonapi::rawserialization::RawSerializable* id);
    virtual int32_t numAuthenticatorsFor(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq);
    virtual Authenticator* statAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq);
    virtual void flush(::rice::p2p::commonapi::rawserialization::RawSerializable* id);
    void flushAll() override;
    void disableMemoryBuffer() override;

    // Generated
    AuthenticatorStoreImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview);
    AuthenticatorStoreImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, bool allowDuplicateSeqs);
protected:
    AuthenticatorStoreImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void addAuthenticator(::java::lang::Object* id, Authenticator* authenticator) override;
    virtual void flush(::java::lang::Object* id) override;
    virtual void flushAuthenticatorsFor(::java::lang::Object* id, int64_t minseq, int64_t maxseq) override;
    virtual void flushAuthenticatorsFor(::java::lang::Object* id) override;
    virtual ::java::util::List* getAuthenticators(::java::lang::Object* id, int64_t minseq, int64_t maxseq) override;
    virtual ::java::util::List* getAuthenticators(::java::lang::Object* id) override;
    virtual Authenticator* getLastAuthenticatorBefore(::java::lang::Object* id, int64_t seq) override;
    virtual Authenticator* getMostRecentAuthenticator(::java::lang::Object* id) override;
    virtual Authenticator* getOldestAuthenticator(::java::lang::Object* id) override;
    virtual int32_t numAuthenticatorsFor(::java::lang::Object* id) override;
    virtual int32_t numAuthenticatorsFor(::java::lang::Object* id, int64_t minseq, int64_t maxseq) override;
    virtual Authenticator* statAuthenticator(::java::lang::Object* id, int64_t seq) override;

private:
    virtual ::java::lang::Class* getClass0();
};
