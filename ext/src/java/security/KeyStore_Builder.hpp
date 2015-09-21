// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::KeyStore_Builder
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int32_t MAX_CALLBACK_TRIES { int32_t(3) };

protected:
    void ctor();

public:
    virtual KeyStore* getKeyStore() = 0;
    virtual KeyStore_ProtectionParameter* getProtectionParameter(::java::lang::String* arg0) = 0;
    static KeyStore_Builder* newInstance(KeyStore* arg0, KeyStore_ProtectionParameter* arg1);
    static KeyStore_Builder* newInstance(::java::lang::String* arg0, Provider* arg1, KeyStore_ProtectionParameter* arg2);
    static KeyStore_Builder* newInstance(::java::lang::String* arg0, Provider* arg1, ::java::io::File* arg2, KeyStore_ProtectionParameter* arg3);

    // Generated

public: /* protected */
    KeyStore_Builder();
protected:
    KeyStore_Builder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
