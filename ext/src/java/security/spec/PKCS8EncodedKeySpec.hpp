// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/security/spec/EncodedKeySpec.hpp>

struct default_init_tag;

class java::security::spec::PKCS8EncodedKeySpec
    : public EncodedKeySpec
{

public:
    typedef EncodedKeySpec super;

protected:
    void ctor(::int8_tArray* arg0);

public:
    ::int8_tArray* getEncoded() override;
    ::java::lang::String* getFormat() override;

    // Generated
    PKCS8EncodedKeySpec(::int8_tArray* arg0);
protected:
    PKCS8EncodedKeySpec(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
