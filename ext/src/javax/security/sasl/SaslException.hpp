// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/security/sasl/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class javax::security::sasl::SaslException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

private:
    ::java::lang::Throwable* _exception {  };
    static constexpr int64_t serialVersionUID { int64_t(4579784287983423626LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1);

public:
    ::java::lang::Throwable* getCause() override;
    ::java::lang::Throwable* initCause(::java::lang::Throwable* arg0) override;
    ::java::lang::String* toString() override;

    // Generated
    SaslException();
    SaslException(::java::lang::String* arg0);
    SaslException(::java::lang::String* arg0, ::java::lang::Throwable* arg1);
protected:
    SaslException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
