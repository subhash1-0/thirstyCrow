// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/KeyStore_Builder.hpp>

struct default_init_tag;

class java::security::KeyStore_Builder_FileBuilder final
    : public KeyStore_Builder
{

public:
    typedef KeyStore_Builder super;

private:
    AccessControlContext* context {  };
    ::java::io::File* file {  };
    KeyStore_ProtectionParameter* keyProtection {  };
    KeyStore* keyStore {  };
    ::java::lang::Throwable* oldException {  };
    KeyStore_ProtectionParameter* protection {  };
    Provider* provider {  };
    ::java::lang::String* type {  };

protected:
    void ctor(::java::lang::String* arg0, Provider* arg1, ::java::io::File* arg2, KeyStore_ProtectionParameter* arg3, AccessControlContext* arg4);

public:
    KeyStore* getKeyStore() override;
    KeyStore_ProtectionParameter* getProtectionParameter(::java::lang::String* arg0) override;

    // Generated

public: /* package */
    KeyStore_Builder_FileBuilder(::java::lang::String* arg0, Provider* arg1, ::java::io::File* arg2, KeyStore_ProtectionParameter* arg3, AccessControlContext* arg4);
protected:
    KeyStore_Builder_FileBuilder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
