// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/identity/IdentityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransportLayerImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/security/Signature.hpp>
#include <java/security/SignatureException.hpp>
#include <java/security/cert/Certificate.hpp>
#include <java/security/cert/X509Certificate.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/pki/x509/X509Serializer.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransportCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransportLayerImpl_MyStore.hpp>
#include <org/mpisws/p2p/transport/table/TableStore.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <Array.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::IdentityTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::IdentityTransportLayerImpl(::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::pki::x509::X509Serializer* cSerializer, ::java::lang::Object* localId, ::java::security::cert::X509Certificate* localCert, ::java::security::PrivateKey* localPrivate, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher, ::rice::environment::Environment* env)  /* throws(InvalidKeyException, NoSuchAlgorithmException, NoSuchProviderException) */
    : IdentityTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(iSerializer,cSerializer,localId,localCert,localPrivate,tl,hasher,env);
}

void org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::init()
{
    signatureAlgorithm = IdentityTransportLayerImpl::DEFAULT_SIGNATURE_ALGORITHM();
    signatureImpl = u"BC"_j;
    verifiers = new ::java::util::HashMap();
}

java::lang::String*& org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::DEFAULT_SIGNATURE_ALGORITHM()
{
    clinit();
    return DEFAULT_SIGNATURE_ALGORITHM_;
}
java::lang::String* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::DEFAULT_SIGNATURE_ALGORITHM_;

constexpr int16_t org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::DEFAULT_SIGNATURE_SIZE;

/* <H, I> */org::mpisws::p2p::transport::table::TableStore* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::getTableStore(::java::lang::Object* localId, ::java::security::cert::X509Certificate* localCert, ::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::pki::x509::X509Serializer* cSerializer, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf)
{
    clinit();
    auto ret = new IdentityTransportLayerImpl_MyStore();
    npc(ret)->put(static_cast< ::java::lang::Object* >(localId), localCert);
    if(buf != nullptr) {
        throw new ::java::lang::RuntimeException(u"Persistent version not implemented."_j);
    }
    return ret;
}

void org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::ctor(::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::pki::x509::X509Serializer* cSerializer, ::java::lang::Object* localId, ::java::security::cert::X509Certificate* localCert, ::java::security::PrivateKey* localPrivate, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher, ::rice::environment::Environment* env) /* throws(InvalidKeyException, NoSuchAlgorithmException, NoSuchProviderException) */
{
    super::ctor(iSerializer, cSerializer, getTableStore(localId, localCert, iSerializer, cSerializer, nullptr), tl, env);
    init();
    this->tl = tl;
    npc(tl)->setCallback(this);
    this->hasher = hasher;
    this->environment = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(IdentityTransportLayerImpl::class_(), nullptr);
    this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(this->logger);
    signer = ::java::security::Signature::getInstance(DEFAULT_SIGNATURE_ALGORITHM(), u"BC"_j);
    npc(signer)->initSign(localPrivate);
}

void org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    npc((java_cast< IdentityTransportLayerImpl_MyStore* >(knownValues)))->callback = java_cast< IdentityTransportCallback* >(callback);
    super::setCallback(static_cast< ::org::mpisws::p2p::transport::TransportLayerCallback* >(callback));
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::requestCertificate(::java::lang::Object* source, ::java::lang::Object* principal, ::rice::Continuation* c, ::java::util::Map* options)
{
    return super::requestValue(static_cast< ::java::lang::Object* >(source), static_cast< ::java::lang::Object* >(principal), static_cast< ::rice::Continuation* >(c), options);
}

bool org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::hasCertificate(::java::lang::Object* i)
{
    return super::hasKey(static_cast< ::java::lang::Object* >(i));
}

int8_tArray* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::sign(::int8_tArray* bytes)
{
    try {
        npc(signer)->update(bytes);
        auto ret = npc(signer)->sign();
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Signature of "_j)->append(::rice::p2p::util::MathUtils::toBase64(bytes))
                ->append(u" was "_j)
                ->append(::rice::p2p::util::MathUtils::toBase64(ret))->toString());

        return ret;
    } catch (::java::security::SignatureException* se) {
        auto throwMe = new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Couldn't sign "_j)->append(static_cast< ::java::lang::Object* >(bytes))->toString());
        npc(throwMe)->initCause(se);
        throw throwMe;
    }
}

int32_t org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::verify(::java::lang::Object* id, ::int8_tArray* msg, ::int8_tArray* signature)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Verify:"_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" "_j)
            ->append(npc(msg)->length)
            ->append(u" "_j)
            ->append(::rice::p2p::util::MathUtils::toBase64(msg))
            ->append(u" == "_j)
            ->append(npc(signature)->length)
            ->append(u" "_j)
            ->append(::rice::p2p::util::MathUtils::toBase64(signature))->toString());

    auto verifier = getVerifier(id);
    if(verifier == nullptr)
        return NO_CERTIFICATE;

    try {
        {
            synchronized synchronized_0(verifier);
            {
                npc(verifier)->update(msg);
                if(npc(verifier)->verify(signature)) {
                    return SIGNATURE_OK;
                }
            }
        }
    } catch (::java::security::SignatureException* se) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(se));
    }
    return SIGNATURE_BAD;
}

java::security::Signature* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::getVerifier(::java::lang::Object* i)
{
    auto ret = java_cast< ::java::security::Signature* >(npc(verifiers)->get(i));
    try {
        if(ret == nullptr) {
            if(npc(knownValues)->containsKey(i)) {
                auto cert = java_cast< ::java::security::cert::X509Certificate* >(npc(knownValues)->get(i));
                ret = ::java::security::Signature::getInstance(DEFAULT_SIGNATURE_ALGORITHM(), u"BC"_j);
                npc(ret)->initVerify(static_cast< ::java::security::cert::Certificate* >(cert));
                npc(verifiers)->put(i, ret);
            }
        }
    } catch (::java::lang::Exception* e) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
    }
    return ret;
}

int16_t org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::getSignatureSizeBytes()
{
    return DEFAULT_SIGNATURE_SIZE;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::getEmptyHash()
{
    return npc(hasher)->getEmptyHash();
}

int16_t org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::getHashSizeBytes()
{
    return npc(hasher)->getHashSizeBytes();
}

int8_tArray* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash)
{
    return npc(hasher)->hash(seq, type, nodeHash, contentHash);
}

int8_tArray* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::hash(::java::nio::ByteBufferArray*/*...*/ hashMe)
{
    return npc(hasher)->hash(hashMe);
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::getEnvironment()
{
    return environment;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.identity.IdentityTransportLayerImpl", 71);
    return c;
}

void org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::clinit()
{
struct string_init_ {
    string_init_() {
    DEFAULT_SIGNATURE_ALGORITHM_ = u"SHA1withRSA"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

void org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::acceptMessages(bool b)
{
    TableTransprotLayerImpl::acceptMessages(b);
}

void org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::acceptSockets(bool b)
{
    TableTransprotLayerImpl::acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(TableTransprotLayerImpl::getLocalIdentifier());
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    return java_cast< ::org::mpisws::p2p::transport::SocketRequestHandle* >(TableTransprotLayerImpl::openSocket(i, deliverSocketToMe, options));
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return java_cast< ::org::mpisws::p2p::transport::MessageRequestHandle* >(TableTransprotLayerImpl::sendMessage(i, java_cast< ::java::nio::ByteBuffer* >(m), deliverAckToMe, options));
}

void org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    TableTransprotLayerImpl::setErrorHandler(handler);
}

void org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::destroy()
{
    TableTransprotLayerImpl::destroy();
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl::getClass0()
{
    return class_();
}

