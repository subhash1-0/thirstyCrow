// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::security::KeyPair final
    : public virtual ::java::lang::Object
    , public ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    PrivateKey* privateKey {  };
    PublicKey* publicKey {  };
    static constexpr int64_t serialVersionUID { int64_t(-7565189502268009837LL) };

protected:
    void ctor(PublicKey* arg0, PrivateKey* arg1);

public:
    PrivateKey* getPrivate();
    PublicKey* getPublic();

    // Generated
    KeyPair(PublicKey* arg0, PrivateKey* arg1);
protected:
    KeyPair(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
