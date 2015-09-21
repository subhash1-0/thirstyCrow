// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <java/security/GeneralSecurityException.hpp>

struct default_init_tag;

class javax::crypto::NoSuchPaddingException
    : public ::java::security::GeneralSecurityException
{

public:
    typedef ::java::security::GeneralSecurityException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-4572885201200175466LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);

    // Generated

public:
    NoSuchPaddingException();
    NoSuchPaddingException(::java::lang::String* arg0);
protected:
    NoSuchPaddingException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
