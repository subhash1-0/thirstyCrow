// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/MessageDigest.hpp>

struct default_init_tag;

class java::security::MessageDigest_Delegate
    : public MessageDigest
{

public:
    typedef MessageDigest super;

private:
    MessageDigestSpi* digestSpi {  };

protected:
    void ctor(MessageDigestSpi* arg0, ::java::lang::String* arg1);

public:
    ::java::lang::Object* clone() override;

public: /* protected */
    ::int8_tArray* engineDigest() override;
    int32_t engineDigest(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    int32_t engineGetDigestLength() override;
    void engineReset() override;
    void engineUpdate(int8_t arg0) override;
    void engineUpdate(::java::nio::ByteBuffer* arg0) override;
    void engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;

    // Generated

public:
    MessageDigest_Delegate(MessageDigestSpi* arg0, ::java::lang::String* arg1);
protected:
    MessageDigest_Delegate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
