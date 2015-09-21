// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/KeyStore_Entry.hpp>

struct default_init_tag;

class java::security::KeyStore_SecretKeyEntry final
    : public virtual ::java::lang::Object
    , public KeyStore_Entry
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::Set* attributes {  };
    ::javax::crypto::SecretKey* sKey {  };

protected:
    void ctor(::javax::crypto::SecretKey* arg0);
    void ctor(::javax::crypto::SecretKey* arg0, ::java::util::Set* arg1);

public:
    ::java::util::Set* getAttributes() override;
    ::javax::crypto::SecretKey* getSecretKey();
    ::java::lang::String* toString() override;

    // Generated
    KeyStore_SecretKeyEntry(::javax::crypto::SecretKey* arg0);
    KeyStore_SecretKeyEntry(::javax::crypto::SecretKey* arg0, ::java::util::Set* arg1);
protected:
    KeyStore_SecretKeyEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
