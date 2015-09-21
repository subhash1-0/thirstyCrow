// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLSocketManager.java
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager_runDelegatedTasks_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_2::SSLSocketManager_runDelegatedTasks_2(SSLSocketManager *SSLSocketManager_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SSLSocketManager_this(SSLSocketManager_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_2::receiveException(::java::lang::Exception* exception)
{
    npc(exception)->printStackTrace();
}

void org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_2::receiveResult(::java::lang::Object* result)
{
    SSLSocketManager_this->runningTaskLock = false;
    SSLSocketManager_this->continueHandshaking();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_2::getClass0()
{
    return class_();
}

