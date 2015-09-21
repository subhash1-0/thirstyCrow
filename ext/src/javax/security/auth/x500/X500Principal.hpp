// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/security/auth/x500/fwd-pastry-2.1.hpp>
#include <sun/security/x509/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/Principal.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class javax::security::auth::x500::X500Principal final
    : public virtual ::java::lang::Object
    , public ::java::security::Principal
    , public ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* CANONICAL_;
    static ::java::lang::String* RFC1779_;
    static ::java::lang::String* RFC2253_;
    static constexpr int64_t serialVersionUID { int64_t(-500463348111345721LL) };
    ::sun::security::x509::X500Name* thisX500Name {  };

protected:
    void ctor(::sun::security::x509::X500Name* arg0);
    void ctor(::java::lang::String* arg0);
    void ctor(::int8_tArray* arg0);
    void ctor(::java::io::InputStream* arg0);
    void ctor(::java::lang::String* arg0, ::java::util::Map* arg1);

public:
    bool equals(::java::lang::Object* arg0) override;
    ::int8_tArray* getEncoded();
    ::java::lang::String* getName() override;
    ::java::lang::String* getName(::java::lang::String* arg0);
    ::java::lang::String* getName(::java::lang::String* arg0, ::java::util::Map* arg1);
    int32_t hashCode() override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    ::java::lang::String* toString() override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated

public: /* package */
    X500Principal(::sun::security::x509::X500Name* arg0);

public:
    X500Principal(::java::lang::String* arg0);
    X500Principal(::int8_tArray* arg0);
    X500Principal(::java::io::InputStream* arg0);
    X500Principal(::java::lang::String* arg0, ::java::util::Map* arg1);
protected:
    X500Principal(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static ::java::lang::String*& CANONICAL();
    static ::java::lang::String*& RFC1779();
    static ::java::lang::String*& RFC2253();

private:
    virtual ::java::lang::Class* getClass0();
};
