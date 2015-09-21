// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/charset/fwd-pastry-2.1.hpp>
#include <sun/nio/cs/fwd-pastry-2.1.hpp>
#include <java/io/Writer.hpp>

struct default_init_tag;

class java::io::OutputStreamWriter
    : public Writer
{

public:
    typedef Writer super;

private:
    ::sun::nio::cs::StreamEncoder* se {  };

protected:
    void ctor(OutputStream* arg0);
    void ctor(OutputStream* arg0, ::java::lang::String* arg1);
    void ctor(OutputStream* arg0, ::java::nio::charset::Charset* arg1);
    void ctor(OutputStream* arg0, ::java::nio::charset::CharsetEncoder* arg1);

public:
    void close() override;
    void flush() override;

public: /* package */
    virtual void flushBuffer();

public:
    virtual ::java::lang::String* getEncoding();
    void write(int32_t arg0) override;
    void write(::char16_tArray* arg0, int32_t arg1, int32_t arg2) override;
    void write(::java::lang::String* arg0, int32_t arg1, int32_t arg2) override;

    // Generated
    OutputStreamWriter(OutputStream* arg0);
    OutputStreamWriter(OutputStream* arg0, ::java::lang::String* arg1);
    OutputStreamWriter(OutputStream* arg0, ::java::nio::charset::Charset* arg1);
    OutputStreamWriter(OutputStream* arg0, ::java::nio::charset::CharsetEncoder* arg1);
protected:
    OutputStreamWriter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void write(::char16_tArray* cbuf);
    virtual void write(::java::lang::String* str);

private:
    virtual ::java::lang::Class* getClass0();
};
