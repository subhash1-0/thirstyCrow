// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLSocketManager.java
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager_runDelegatedTasks_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/String.hpp>
#include <javax/net/ssl/SSLEngine.hpp>
#include <javax/net/ssl/SSLEngineResult_HandshakeStatus.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_1::SSLSocketManager_runDelegatedTasks_1(SSLSocketManager *SSLSocketManager_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SSLSocketManager_this(SSLSocketManager_this)
{
    clinit();
    ctor();
}

java::lang::Object* org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_1::execute() /* throws(Exception) */
{
    ::java::lang::Runnable* runnable;
    while ((runnable = npc(SSLSocketManager_this->engine)->getDelegatedTask()) != nullptr) {
        npc(runnable)->run();
    }
    SSLSocketManager_this->status = npc(SSLSocketManager_this->engine)->getHandshakeStatus();
    if(SSLSocketManager_this->status == ::javax::net::ssl::SSLEngineResult_HandshakeStatus::NEED_TASK) {
        SSLSocketManager_this->fail(new ::java::io::IOException(u"handshake shouldn't need additional tasks"_j));
        return nullptr;
    }
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_1::getClass0()
{
    return class_();
}

