// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/OutputStream.hpp>

struct default_init_tag;

class java::io::ByteArrayOutputStream
    : public OutputStream
{

public:
    typedef OutputStream super;

private:
    static constexpr int32_t MAX_ARRAY_SIZE { int32_t(2147483639) };

public: /* protected */
    ::int8_tArray* buf {  };
    int32_t count {  };

protected:
    void ctor();
    void ctor(int32_t arg0);

public:
    void close() override;
    /*void ensureCapacity(int32_t arg0); (private) */
    /*void grow(int32_t arg0); (private) */
    /*static int32_t hugeCapacity(int32_t arg0); (private) */
    virtual void reset();
    virtual int32_t size();
    virtual ::int8_tArray* toByteArray_();
    ::java::lang::String* toString() override;
    virtual ::java::lang::String* toString(::java::lang::String* arg0);
    virtual ::java::lang::String* toString(int32_t arg0);
    void write(int32_t arg0) override;
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    virtual void writeTo(OutputStream* arg0);

    // Generated
    ByteArrayOutputStream();
    ByteArrayOutputStream(int32_t arg0);
protected:
    ByteArrayOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void write(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
