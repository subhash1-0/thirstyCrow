// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Appendable.hpp>
#include <java/io/Closeable.hpp>
#include <java/io/Flushable.hpp>

struct default_init_tag;

class java::io::Writer
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Appendable
    , public virtual Closeable
    , public virtual Flushable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int32_t WRITE_BUFFER_SIZE { int32_t(1024) };

public: /* protected */
    ::java::lang::Object* lock {  };

private:
    ::char16_tArray* writeBuffer {  };

protected:
    void ctor();
    void ctor(::java::lang::Object* arg0);

public:
    Writer* append(::java::lang::CharSequence* arg0) override;
    Writer* append(char16_t arg0) override;
    Writer* append(::java::lang::CharSequence* arg0, int32_t arg1, int32_t arg2) override;
    /*void close(); (already declared) */
    /*void flush(); (already declared) */
    virtual void write(int32_t arg0);
    virtual void write(::char16_tArray* arg0);
    virtual void write(::java::lang::String* arg0);
    virtual void write(::char16_tArray* arg0, int32_t arg1, int32_t arg2) = 0;
    virtual void write(::java::lang::String* arg0, int32_t arg1, int32_t arg2);

    // Generated

public: /* protected */
    Writer();
    Writer(::java::lang::Object* arg0);
protected:
    Writer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
