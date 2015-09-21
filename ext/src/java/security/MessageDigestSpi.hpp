// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::MessageDigestSpi
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::int8_tArray* tempArray_ {  };

protected:
    void ctor();

public:
    ::java::lang::Object* clone() override;

public: /* protected */
    virtual ::int8_tArray* engineDigest() = 0;
    virtual int32_t engineDigest(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    virtual int32_t engineGetDigestLength();
    virtual void engineReset() = 0;
    virtual void engineUpdate(int8_t arg0) = 0;
    virtual void engineUpdate(::java::nio::ByteBuffer* arg0);
    virtual void engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2) = 0;

    // Generated

public:
    MessageDigestSpi();
protected:
    MessageDigestSpi(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
