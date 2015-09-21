// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::KeyFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::String* algorithm {  };
    static ::sun::security::util::Debug* debug_;
    ::java::lang::Object* lock {  };
    Provider* provider {  };
    ::java::util::Iterator* serviceIterator {  };
    std::atomic< KeyFactorySpi* > spi {  };

    /*void ctor(::java::lang::String* arg0); (private) */
protected:
    void ctor(KeyFactorySpi* arg0, Provider* arg1, ::java::lang::String* arg2);

public:
    PrivateKey* generatePrivate(::java::security::spec::KeySpec* arg0);
    PublicKey* generatePublic(::java::security::spec::KeySpec* arg0);
    ::java::lang::String* getAlgorithm();
    static KeyFactory* getInstance(::java::lang::String* arg0);
    static KeyFactory* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static KeyFactory* getInstance(::java::lang::String* arg0, Provider* arg1);
    ::java::security::spec::KeySpec* getKeySpec(Key* arg0, ::java::lang::Class* arg1);
    Provider* getProvider();
    /*KeyFactorySpi* nextSpi(KeyFactorySpi* arg0); (private) */
    Key* translateKey(Key* arg0);

    // Generated

public: /* protected */
    KeyFactory(KeyFactorySpi* arg0, Provider* arg1, ::java::lang::String* arg2);
protected:
    KeyFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::sun::security::util::Debug*& debug();
    virtual ::java::lang::Class* getClass0();
};
