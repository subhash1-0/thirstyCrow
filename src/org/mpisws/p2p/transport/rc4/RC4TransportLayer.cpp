// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/RC4TransportLayer.java
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/security/MessageDigest.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::rc4::RC4TransportLayer::RC4TransportLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::rc4::RC4TransportLayer::RC4TransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::java::lang::String* password, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler)  /* throws(NoSuchAlgorithmException) */
    : RC4TransportLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,env,password,errorHandler);
}

org::mpisws::p2p::transport::rc4::RC4TransportLayer::RC4TransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::java::lang::String* password, int32_t pwSeedLength, ::rice::environment::random::RandomSource* random, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler)  /* throws(NoSuchAlgorithmException) */
    : RC4TransportLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,env,password,pwSeedLength,random,errorHandler);
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::init()
{
    WRITE_BUFFER_SIZE = int32_t(1024);
}

constexpr int32_t org::mpisws::p2p::transport::rc4::RC4TransportLayer::KEY_LENGTH;

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::java::lang::String* password, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler) /* throws(NoSuchAlgorithmException) */
{
    ctor(tl, env, password, KEY_LENGTH, npc(env)->getRandomSource(), errorHandler);
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::java::lang::String* password, int32_t pwSeedLength, ::rice::environment::random::RandomSource* random, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler) /* throws(NoSuchAlgorithmException) */
{
    super::ctor();
    init();
    this->tl = tl;
    npc(java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(this->tl))->setCallback(this);
    this->env = env;
    this->password = npc(password)->getBytes();
    this->PW_SEED_LENGTH = pwSeedLength;
    this->logger = npc(npc(env)->getLogManager())->getLogger(RC4TransportLayer::class_(), nullptr);
    this->random = random;
    this->errorHandler = errorHandler;
    md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::rc4::RC4TransportLayer::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::rc4::RC4TransportLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto const ret = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(ret)->setSubCancellable(npc(tl)->openSocket(i, new RC4TransportLayer_openSocket_1(this, deliverSocketToMe, ret, i, options), options));
    return ret;
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    (new RC4TransportLayer_incomingSocket_2(this))->receiveSelectResult(s, true, false);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::rc4::RC4TransportLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::destroy()
{
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
}

java::lang::String*& org::mpisws::p2p::transport::rc4::RC4TransportLayer::ALGORITHM()
{
    clinit();
    return ALGORITHM_;
}
java::lang::String* org::mpisws::p2p::transport::rc4::RC4TransportLayer::ALGORITHM_;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.rc4.RC4TransportLayer", 46);
    return c;
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer::clinit()
{
struct string_init_ {
    string_init_() {
    ALGORITHM_ = u"RC4"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer::getClass0()
{
    return class_();
}

