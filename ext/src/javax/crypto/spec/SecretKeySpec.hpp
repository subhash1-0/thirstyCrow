// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/crypto/spec/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/spec/KeySpec.hpp>
#include <javax/crypto/SecretKey.hpp>

struct default_init_tag;

class javax::crypto::spec::SecretKeySpec
    : public virtual ::java::lang::Object
    , public virtual ::java::security::spec::KeySpec
    , public virtual ::javax::crypto::SecretKey
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::String* algorithm {  };
    ::int8_tArray* key {  };
    static constexpr int64_t serialVersionUID { int64_t(6577238317307289933LL) };

protected:
    void ctor(::int8_tArray* arg0, ::java::lang::String* arg1);
    void ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3);

public:
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::String* getAlgorithm() override;
    ::int8_tArray* getEncoded() override;
    ::java::lang::String* getFormat() override;
    int32_t hashCode() override;

    // Generated
    SecretKeySpec(::int8_tArray* arg0, ::java::lang::String* arg1);
    SecretKeySpec(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3);
protected:
    SecretKeySpec(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
