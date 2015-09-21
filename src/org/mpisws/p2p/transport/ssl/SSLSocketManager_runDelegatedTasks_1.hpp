// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLSocketManager.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/ssl/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Executable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::ssl::SSLSocketManager_runDelegatedTasks_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Executable
{

public:
    typedef ::java::lang::Object super;
    ::java::lang::Object* execute() /* throws(Exception) */ override;

    // Generated
    SSLSocketManager_runDelegatedTasks_1(SSLSocketManager *SSLSocketManager_this);
    static ::java::lang::Class *class_();
    SSLSocketManager *SSLSocketManager_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SSLSocketManager;
    friend class SSLSocketManager_runDelegatedTasks_2;
};
