// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/security/fwd-pastry-2.1.hpp>
#include <javax/security/auth/callback/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/KeyStore_ProtectionParameter.hpp>

struct default_init_tag;

class java::security::KeyStore_CallbackHandlerProtection
    : public virtual ::java::lang::Object
    , public virtual KeyStore_ProtectionParameter
{

public:
    typedef ::java::lang::Object super;

private:
    ::javax::security::auth::callback::CallbackHandler* handler {  };

protected:
    void ctor(::javax::security::auth::callback::CallbackHandler* arg0);

public:
    virtual ::javax::security::auth::callback::CallbackHandler* getCallbackHandler();

    // Generated
    KeyStore_CallbackHandlerProtection(::javax::security::auth::callback::CallbackHandler* arg0);
protected:
    KeyStore_CallbackHandlerProtection(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
