// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLSocketManager.java
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/security/Principal.hpp>
#include <java/security/cert/Certificate.hpp>
#include <java/security/cert/X509Certificate.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <javax/net/ssl/SSLContext.hpp>
#include <javax/net/ssl/SSLEngine.hpp>
#include <javax/net/ssl/SSLEngineResult_HandshakeStatus.hpp>
#include <javax/net/ssl/SSLEngineResult.hpp>
#include <javax/net/ssl/SSLException.hpp>
#include <javax/net/ssl/SSLSession.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager_runDelegatedTasks_1.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager_runDelegatedTasks_2.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayer.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace security
    {
        namespace cert
        {
typedef ::SubArray< ::java::security::cert::Certificate, ::java::lang::ObjectArray, ::java::io::SerializableArray > CertificateArray;
        } // cert
    } // security
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

org::mpisws::p2p::transport::ssl::SSLSocketManager::SSLSocketManager(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::ssl::SSLSocketManager::SSLSocketManager(SSLTransportLayerImpl* sslTL, ::org::mpisws::p2p::transport::P2PSocket* s, ::rice::Continuation* c, bool server, bool useClientAuth) 
    : SSLSocketManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(sslTL,s,c,server,useClientAuth);
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::init()
{
    peerCert = nullptr;
    handshaking = true;
    closed = true;
    writeMe = new ::java::util::LinkedList();
    unwrapMe = new ::java::util::LinkedList();
    doneHandshaking = false;
    handshakeFail = false;
    runningTaskLock = false;
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::ctor(SSLTransportLayerImpl* sslTL, ::org::mpisws::p2p::transport::P2PSocket* s, ::rice::Continuation* c, bool server, bool useClientAuth)
{
    super::ctor();
    init();
    this->server = server;
    this->useClientAuth = useClientAuth;
    this->sslTL = sslTL;
    this->socket = s;
    this->c = c;
    this->logger = npc(sslTL)->logger;
    engine = npc(npc(sslTL)->context)->createSSLEngine(npc(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()))->toString(), 0);
    npc(engine)->setUseClientMode(!server);
    if(server && useClientAuth)
        npc(engine)->setNeedClientAuth(true);

    appBufferMax = npc(npc(engine)->getSession())->getApplicationBufferSize();
    netBufferMax = npc(npc(engine)->getSession())->getPacketBufferSize();
    bogusEncryptMe = ::java::nio::ByteBuffer::allocate(0);
    readMe = new ::java::util::LinkedList();
    npc(socket)->register_(true, false, this);
    handshakeWrap();
}

java::lang::String* org::mpisws::p2p::transport::ssl::SSLSocketManager::toString()
{
    return ::java::lang::StringBuilder().append(u"SSLSocket to "_j)->append((name == nullptr ? u"unknown"_j : name))
        ->append(u" at "_j)
        ->append(npc(socket)->toString())->toString();
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::handleResult(::javax::net::ssl::SSLEngineResult* result)
{
    this->result = result;
    this->status = npc(result)->getHandshakeStatus();
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(handshakeFail)
        return;

    if(canWrite) {
        auto i = npc(writeMe)->iterator();
        while (npc(i)->hasNext()) {
            auto b = java_cast< ::java::nio::ByteBuffer* >(npc(i)->next());
            npc(socket)->write(b);
            if(npc(b)->hasRemaining())
                break;

            npc(i)->remove();
        }
        if(npc(writeMe)->isEmpty()) {
            if(registeredToWrite != nullptr) {
                auto temp = registeredToWrite;
                registeredToWrite = nullptr;
                npc(temp)->receiveSelectResult(this, false, true);
            }
        } else {
            npc(socket)->register_(false, true, this);
        }
    }
    if(canRead) {
        if(doneHandshaking) {
            if(read()) {
                if(registeredToRead != nullptr) {
                    auto temp = registeredToRead;
                    registeredToRead = nullptr;
                    npc(temp)->receiveSelectResult(this, true, false);
                }
            }
        } else {
            read();
            continueHandshaking();
        }
    }
}

bool org::mpisws::p2p::transport::ssl::SSLSocketManager::read() /* throws(IOException) */
{
    auto foo = ::java::nio::ByteBuffer::allocate(netBufferMax);
    if(npc(socket)->read(foo) < 0) {
        closed = true;
        fail(new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Unexpected socket closure "_j)->append(static_cast< ::java::lang::Object* >(this))->toString()));
    }
    if(npc(foo)->position() != 0) {
        npc(foo)->flip();
        npc(unwrapMe)->addLast(static_cast< ::java::lang::Object* >(foo));
        return true;
    }
    return false;
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::handshakeWrap()
{
    try {
        auto outgoing = ::java::nio::ByteBuffer::allocate(netBufferMax);
        handleResult(npc(engine)->wrap(bogusEncryptMe, outgoing));
        if(npc(outgoing)->position() != 0) {
            npc(outgoing)->flip();
            npc(writeMe)->addLast(static_cast< ::java::lang::Object* >(outgoing));
            npc(socket)->register_(false, true, this);
        }
    } catch (::javax::net::ssl::SSLException* e) {
        fail(e);
        return;
    }
    continueHandshaking();
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::unwrap() /* throws(SSLException) */
{
    auto i = npc(unwrapMe)->iterator();
    while (npc(i)->hasNext()) {
        auto b = java_cast< ::java::nio::ByteBuffer* >(npc(i)->next());
        auto foo = ::java::nio::ByteBuffer::allocate(appBufferMax);
        handleResult(npc(engine)->unwrap(b, foo));
        if(npc(foo)->position() != 0) {
            npc(foo)->flip();
            npc(readMe)->addLast(static_cast< ::java::lang::Object* >(foo));
        }
        if(npc(b)->hasRemaining())
            break;

        npc(i)->remove();
    }
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::handshakeUnwrap()
{
    try {
        if(npc(unwrapMe)->isEmpty()) {
            if(read()) {
            } else {
                npc(socket)->register_(true, false, this);
                return;
            }
        }
        unwrap();
    } catch (::java::lang::Exception* e) {
        fail(e);
        return;
    }
    continueHandshaking();
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::fail(::java::lang::Exception* e)
{
    if(doneHandshaking)
        return;

    npc(logger)->logException(u"fail:"_j, e);
    ::java::lang::Throwable* e2 = e;
    while (npc(e2)->getCause() != nullptr) {
        npc(logger)->logException(u"fail cause:"_j, npc(e2)->getCause());
        e2 = npc(e2)->getCause();
    }
    handshakeFail = true;
    npc(c)->receiveException(e);
    npc(socket)->close();
    doneHandshaking = true;
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::continueHandshaking()
{
    if(runningTaskLock) {
        return;
    }
    {
        auto v = status;
        if((v == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::NOT_HANDSHAKING)) {
            return;
        }
        if((v == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::FINISHED)) {
            checkDone();
            return;
        }
        if((v == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::NEED_TASK)) {
            runDelegatedTasks();
        }
        if((v == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::NEED_TASK) || (v == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::NEED_WRAP)) {
            handshakeWrap();
            return;
        }
        if((v == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::NEED_UNWRAP)) {
            handshakeUnwrap();
            return;
        }
end_switch0:;
    }

}

bool org::mpisws::p2p::transport::ssl::SSLSocketManager::checkDone()
{
    if(((status == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::FINISHED) || (status == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::NOT_HANDSHAKING))) {
        if(!server || useClientAuth) {
            try {
                peerCert = (java_cast< ::java::security::cert::X509Certificate* >((*npc(npc(engine)->getSession())->getPeerCertificates())[int32_t(0)]));
                name = npc(npc(peerCert)->getSubjectDN())->getName();
                if(npc(name)->startsWith(u"CN="_j)) {
                    name = npc(name)->substring(3);
                    options = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(npc(socket)->getOptions(), SSLTransportLayer::OPTION_CERT_SUBJECT(), name);
                } else {
                    fail(new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"CN must start with CN= "_j)->append(name)
                        ->append(u" "_j)
                        ->append(static_cast< ::java::lang::Object* >(this))->toString()));
                    return false;
                }
            } catch (::java::lang::Exception* e) {
                fail(e);
                return false;
            }
        }
        doneHandshaking = true;
        npc(c)->receiveResult(this);
        return true;
    }
    return false;
}

java::security::cert::X509Certificate* org::mpisws::p2p::transport::ssl::SSLSocketManager::getCert()
{
    return peerCert;
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::runDelegatedTasks()
{
    if(npc(result)->getHandshakeStatus() == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::NEED_TASK) {
        runningTaskLock = true;
        npc(npc(npc(sslTL)->environment)->getProcessor())->process(new SSLSocketManager_runDelegatedTasks_1(this), new SSLSocketManager_runDelegatedTasks_2(this), npc(npc(sslTL)->environment)->getSelectorManager(), npc(npc(sslTL)->environment)->getTimeSource(), npc(npc(sslTL)->environment)->getLogManager());
    }
}

bool org::mpisws::p2p::transport::ssl::SSLSocketManager::isEngineClosed(::javax::net::ssl::SSLEngine* engine)
{
    clinit();
    return (npc(engine)->isOutboundDone() && npc(engine)->isInboundDone());
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    if(wantToRead) {
        if(!npc(readMe)->isEmpty()) {
            try {
                npc(receiver)->receiveSelectResult(this, true, false);
            } catch (::java::io::IOException* ioe) {
                npc(receiver)->receiveException(this, ioe);
            }
        } else {
            registeredToRead = receiver;
            npc(socket)->register_(true, false, this);
        }
    }
    if(wantToWrite) {
        if(npc(writeMe)->isEmpty()) {
            try {
                npc(receiver)->receiveSelectResult(this, false, true);
            } catch (::java::io::IOException* ioe) {
                npc(receiver)->receiveException(this, ioe);
            }
        } else {
            registeredToWrite = receiver;
            npc(socket)->register_(false, true, this);
        }
    }
}

int64_t org::mpisws::p2p::transport::ssl::SSLSocketManager::read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */
{
    int64_t start = npc(dsts)->position();
    unwrap();
    while (npc(dsts)->hasRemaining() && !npc(readMe)->isEmpty()) {
        auto foo = java_cast< ::java::nio::ByteBuffer* >(npc(readMe)->getFirst());
        auto len = ::java::lang::Math::min(npc(dsts)->remaining(), npc(foo)->remaining());
        auto pos = npc(foo)->position();
        npc(dsts)->put(npc(foo)->array(), pos, len);
        npc(foo)->position(pos + len);
        if(npc(foo)->hasRemaining()) {
            return npc(dsts)->position() - start;
        } else {
            npc(readMe)->removeFirst();
        }
    }
    if(npc(dsts)->hasRemaining()) {
        if(read()) {
            unwrap();
            npc(dsts)->put(java_cast< ::java::nio::ByteBuffer* >(npc(readMe)->getFirst()));
            if(npc(java_cast< ::java::nio::ByteBuffer* >(npc(readMe)->getFirst()))->hasRemaining()) {
                return npc(dsts)->position() - start;
            } else {
                npc(readMe)->removeFirst();
            }
        }
    }
    return npc(dsts)->position() - start;
}

int64_t org::mpisws::p2p::transport::ssl::SSLSocketManager::write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    auto outgoing = ::java::nio::ByteBuffer::allocate(netBufferMax);
    auto tempResult = npc(engine)->wrap(srcs, outgoing);
    if(npc(outgoing)->position() != 0) {
        npc(outgoing)->flip();
        npc(writeMe)->addLast(static_cast< ::java::lang::Object* >(outgoing));
        receiveSelectResult(socket, false, true);
    }
    return npc(tempResult)->bytesConsumed();
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::close()
{
    npc(socket)->close();
}

java::lang::Object* org::mpisws::p2p::transport::ssl::SSLSocketManager::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier());
}

java::util::Map* org::mpisws::p2p::transport::ssl::SSLSocketManager::getOptions()
{
    return options;
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::shutdownOutput()
{
    npc(engine)->closeOutbound();
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(c)->receiveException(ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLSocketManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.ssl.SSLSocketManager", 45);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLSocketManager::getClass0()
{
    return class_();
}

