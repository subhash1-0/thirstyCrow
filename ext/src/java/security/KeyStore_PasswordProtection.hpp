// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/KeyStore_ProtectionParameter.hpp>
#include <javax/security/auth/Destroyable.hpp>

struct default_init_tag;

class java::security::KeyStore_PasswordProtection
    : public virtual ::java::lang::Object
    , public virtual KeyStore_ProtectionParameter
    , public virtual ::javax::security::auth::Destroyable
{

public:
    typedef ::java::lang::Object super;

private:
    std::atomic< bool > destroyed {  };
    ::char16_tArray* password {  };
    ::java::lang::String* protectionAlgorithm {  };
    ::java::security::spec::AlgorithmParameterSpec* protectionParameters {  };

protected:
    void ctor(::char16_tArray* arg0);
    void ctor(::char16_tArray* arg0, ::java::lang::String* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2);

public:
    void destroy() override;
    virtual ::char16_tArray* getPassword();
    virtual ::java::lang::String* getProtectionAlgorithm();
    virtual ::java::security::spec::AlgorithmParameterSpec* getProtectionParameters();
    bool isDestroyed() override;

    // Generated
    KeyStore_PasswordProtection(::char16_tArray* arg0);
    KeyStore_PasswordProtection(::char16_tArray* arg0, ::java::lang::String* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2);
protected:
    KeyStore_PasswordProtection(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
