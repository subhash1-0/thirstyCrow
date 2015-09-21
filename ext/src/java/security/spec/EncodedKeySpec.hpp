// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/spec/KeySpec.hpp>

struct default_init_tag;

class java::security::spec::EncodedKeySpec
    : public virtual ::java::lang::Object
    , public virtual KeySpec
{

public:
    typedef ::java::lang::Object super;

private:
    ::int8_tArray* encodedKey {  };

protected:
    void ctor(::int8_tArray* arg0);

public:
    virtual ::int8_tArray* getEncoded();
    virtual ::java::lang::String* getFormat() = 0;

    // Generated
    EncodedKeySpec(::int8_tArray* arg0);
protected:
    EncodedKeySpec(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
