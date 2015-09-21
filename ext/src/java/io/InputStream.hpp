// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Closeable.hpp>

struct default_init_tag;

class java::io::InputStream
    : public virtual ::java::lang::Object
    , public virtual Closeable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int32_t MAX_SKIP_BUFFER_SIZE { int32_t(2048) };

protected:
    void ctor();

public:
    virtual int32_t available();
    void close() override;
    virtual void mark(int32_t arg0);
    virtual bool markSupported();
    virtual int32_t read() = 0;
    virtual int32_t read(::int8_tArray* arg0);
    virtual int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    virtual void reset();
    virtual int64_t skip(int64_t arg0);

    // Generated
    InputStream();
protected:
    InputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
