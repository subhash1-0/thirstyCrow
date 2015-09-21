// Generated from /pastry-2.1/lib/bouncycastle.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/jce/provider/fwd-pastry-2.1.hpp>
#include <java/security/Provider.hpp>
#include <org/bouncycastle/jce/interfaces/ConfigurableProvider.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class org::bouncycastle::jce::provider::BouncyCastleProvider final
    : public ::java::security::Provider
    , public ::org::bouncycastle::jce::interfaces::ConfigurableProvider
{

public:
    typedef ::java::security::Provider super;

private:
    static ::java::lang::String* PROVIDER_NAME_;
    static ::java::lang::StringArray* SYMMETRIC_CIPHERS_;
    static ::java::lang::String* SYMMETRIC_CIPHER_PACKAGE_;
    static ::java::lang::String* info_;

protected:
    void ctor();
    /*void addHMACAlgorithm(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2); (private) */
    /*void addHMACAlias(::java::lang::String* arg0, ::org::bouncycastle::asn1::DERObjectIdentifier* arg1); (private) */
    /*void addMacAlgorithms(); (private) */
    /*void addMappings(::java::util::Map* arg0); (private) */
    /*void addMessageDigestAlgorithms(); (private) */
    /*void addSignatureAlgorithm(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::org::bouncycastle::asn1::DERObjectIdentifier* arg3); (private) */
    /*void addSignatureAlgorithms(); (private) */

public:
    void setParameter(::java::lang::String* arg0, ::java::lang::Object* arg1) override;

    // Generated
    BouncyCastleProvider();
protected:
    BouncyCastleProvider(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static ::java::lang::String*& PROVIDER_NAME();

private:
    static ::java::lang::StringArray*& SYMMETRIC_CIPHERS();
    static ::java::lang::String*& SYMMETRIC_CIPHER_PACKAGE();
    static ::java::lang::String*& info();
    virtual ::java::lang::Class* getClass0();
};
