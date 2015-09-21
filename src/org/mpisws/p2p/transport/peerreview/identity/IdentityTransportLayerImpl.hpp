// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/identity/IdentityTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/pki/x509/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/table/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl
    : public ::org::mpisws::p2p::transport::table::TableTransprotLayerImpl
    , public virtual IdentityTransport
{

public:
    typedef ::org::mpisws::p2p::transport::table::TableTransprotLayerImpl super;

private:
    static ::java::lang::String* DEFAULT_SIGNATURE_ALGORITHM_;

public:
    static constexpr int16_t DEFAULT_SIGNATURE_SIZE { int16_t(96) };

public: /* package */
    ::java::lang::String* signatureAlgorithm {  };
    ::java::lang::String* signatureImpl {  };
    ::java::security::Signature* signer {  };
    ::java::util::Map* verifiers {  };
    ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher {  };

private:
    ::rice::environment::Environment* environment {  };

public: /* package */
    static /* <H, I> */::org::mpisws::p2p::transport::table::TableStore* getTableStore(::java::lang::Object* localId, ::java::security::cert::X509Certificate* localCert, ::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::pki::x509::X509Serializer* cSerializer, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    void ctor(::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::pki::x509::X509Serializer* cSerializer, ::java::lang::Object* localId, ::java::security::cert::X509Certificate* localCert, ::java::security::PrivateKey* localPrivate, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher, ::rice::environment::Environment* env) /* throws(InvalidKeyException, NoSuchAlgorithmException, NoSuchProviderException) */;

public:
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    ::rice::p2p::commonapi::Cancellable* requestCertificate(::java::lang::Object* source, ::java::lang::Object* principal, ::rice::Continuation* c, ::java::util::Map* options) override;
    bool hasCertificate(::java::lang::Object* i) override;
    ::int8_tArray* sign(::int8_tArray* bytes) override;
    int32_t verify(::java::lang::Object* id, ::int8_tArray* msg, ::int8_tArray* signature) override;
    virtual ::java::security::Signature* getVerifier(::java::lang::Object* i);
    int16_t getSignatureSizeBytes() override;
    ::int8_tArray* getEmptyHash() override;
    int16_t getHashSizeBytes() override;
    ::int8_tArray* hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash) override;
    ::int8_tArray* hash(::java::nio::ByteBufferArray*/*...*/ hashMe) override;
    ::rice::environment::Environment* getEnvironment() override;

    // Generated
    IdentityTransportLayerImpl(::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::pki::x509::X509Serializer* cSerializer, ::java::lang::Object* localId, ::java::security::cert::X509Certificate* localCert, ::java::security::PrivateKey* localPrivate, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher, ::rice::environment::Environment* env);
protected:
    IdentityTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    virtual void acceptMessages(bool b);
    virtual void acceptSockets(bool b);
    virtual ::java::lang::Object* getLocalIdentifier();
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    virtual void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler);
    virtual void destroy();
    static ::java::lang::String*& DEFAULT_SIGNATURE_ALGORITHM();

private:
    virtual ::java::lang::Class* getClass0();
    friend class IdentityTransportLayerImpl_MyStore;
};
