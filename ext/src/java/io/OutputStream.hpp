// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Closeable.hpp>
#include <java/io/Flushable.hpp>

struct default_init_tag;

class java::io::OutputStream
    : public virtual ::java::lang::Object
    , public virtual Closeable
    , public virtual Flushable
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();

public:
    void close() override;
    void flush() override;
    virtual void write(int32_t arg0) = 0;
    virtual void write(::int8_tArray* arg0);
    virtual void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2);

    // Generated
    OutputStream();
protected:
    OutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
