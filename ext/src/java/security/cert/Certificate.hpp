// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::security::cert::Certificate
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t hash {  };
    static constexpr int64_t serialVersionUID { int64_t(-3585440601605666277LL) };
    ::java::lang::String* type {  };

protected:
    void ctor(::java::lang::String* arg0);

public:
    bool equals(::java::lang::Object* arg0) override;
    virtual ::int8_tArray* getEncoded() = 0;
    virtual ::java::security::PublicKey* getPublicKey() = 0;
    ::java::lang::String* getType();
    int32_t hashCode() override;
    /*::java::lang::String* toString(); (already declared) */
    virtual void verify(::java::security::PublicKey* arg0) = 0;
    virtual void verify(::java::security::PublicKey* arg0, ::java::lang::String* arg1) = 0;
    virtual void verify(::java::security::PublicKey* arg0, ::java::security::Provider* arg1);

public: /* protected */
    virtual ::java::lang::Object* writeReplace();

    // Generated
    Certificate(::java::lang::String* arg0);
protected:
    Certificate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
