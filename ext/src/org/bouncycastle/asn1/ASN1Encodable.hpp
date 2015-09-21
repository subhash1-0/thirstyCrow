// Generated from /pastry-2.1/lib/bouncycastle.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/bouncycastle/asn1/DEREncodable.hpp>

struct default_init_tag;

class org::bouncycastle::asn1::ASN1Encodable
    : public virtual ::java::lang::Object
    , public virtual DEREncodable
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* BER_;
    static ::java::lang::String* DER_;

protected:
    void ctor();

public:
    bool equals(::java::lang::Object* arg0) override;
    virtual ::int8_tArray* getDEREncoded();
    DERObject* getDERObject() override;
    virtual ::int8_tArray* getEncoded();
    virtual ::int8_tArray* getEncoded(::java::lang::String* arg0);
    int32_t hashCode() override;
    virtual DERObject* toASN1Object() = 0;

    // Generated
    ASN1Encodable();
protected:
    ASN1Encodable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static ::java::lang::String*& BER();
    static ::java::lang::String*& DER();

private:
    virtual ::java::lang::Class* getClass0();
};
