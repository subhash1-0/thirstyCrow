// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/security/sasl/fwd-pastry-2.1.hpp>
#include <javax/security/sasl/SaslException.hpp>

struct default_init_tag;

class javax::security::sasl::AuthenticationException
    : public SaslException
{

public:
    typedef SaslException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-3579708765071815007LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1);

    // Generated

public:
    AuthenticationException();
    AuthenticationException(::java::lang::String* arg0);
    AuthenticationException(::java::lang::String* arg0, ::java::lang::Throwable* arg1);
protected:
    AuthenticationException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
