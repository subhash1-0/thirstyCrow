// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::security::cert::Certificate_CertificateRep
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    ::int8_tArray* data {  };
    static constexpr int64_t serialVersionUID { int64_t(-8563758940495660020LL) };
    ::java::lang::String* type {  };

protected:
    void ctor(::java::lang::String* arg0, ::int8_tArray* arg1);

public: /* protected */
    virtual ::java::lang::Object* readResolve();

    // Generated
    Certificate_CertificateRep(::java::lang::String* arg0, ::int8_tArray* arg1);
protected:
    Certificate_CertificateRep(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
