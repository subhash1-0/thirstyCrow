// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/KeyStore_LoadStoreParameter.hpp>

struct default_init_tag;

class java::security::KeyStore_SimpleLoadStoreParameter
    : public virtual ::java::lang::Object
    , public virtual KeyStore_LoadStoreParameter
{

public:
    typedef ::java::lang::Object super;

private:
    KeyStore_ProtectionParameter* protection {  };

protected:
    void ctor(KeyStore_ProtectionParameter* arg0);

public:
    KeyStore_ProtectionParameter* getProtectionParameter() override;

    // Generated

public: /* package */
    KeyStore_SimpleLoadStoreParameter(KeyStore_ProtectionParameter* arg0);
protected:
    KeyStore_SimpleLoadStoreParameter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
