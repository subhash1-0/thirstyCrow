// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/KeyStore_Entry.hpp>

struct default_init_tag;

class java::security::KeyStore_TrustedCertificateEntry final
    : public virtual ::java::lang::Object
    , public KeyStore_Entry
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::Set* attributes {  };
    ::java::security::cert::Certificate* cert {  };

protected:
    void ctor(::java::security::cert::Certificate* arg0);
    void ctor(::java::security::cert::Certificate* arg0, ::java::util::Set* arg1);

public:
    ::java::util::Set* getAttributes() override;
    ::java::security::cert::Certificate* getTrustedCertificate();
    ::java::lang::String* toString() override;

    // Generated
    KeyStore_TrustedCertificateEntry(::java::security::cert::Certificate* arg0);
    KeyStore_TrustedCertificateEntry(::java::security::cert::Certificate* arg0, ::java::util::Set* arg1);
protected:
    KeyStore_TrustedCertificateEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
