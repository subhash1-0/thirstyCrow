// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/charset/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/io/FilterOutputStream.hpp>
#include <java/lang/Appendable.hpp>
#include <java/io/Closeable.hpp>

struct default_init_tag;

class java::io::PrintStream
    : public FilterOutputStream
    , public virtual ::java::lang::Appendable
    , public virtual Closeable
{

public:
    typedef FilterOutputStream super;

private:
    bool autoFlush {  };
    OutputStreamWriter* charOut {  };
    bool closing {  };
    ::java::util::Formatter* formatter {  };
    BufferedWriter* textOut {  };
    bool trouble {  };

protected:
    void ctor(OutputStream* arg0);
    void ctor(::java::lang::String* arg0);
    void ctor(File* arg0);
    /*void ctor(bool arg0, OutputStream* arg1); (private) */
    void ctor(OutputStream* arg0, bool arg1);
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1);
    void ctor(File* arg0, ::java::lang::String* arg1);
    /*void ctor(bool arg0, OutputStream* arg1, ::java::nio::charset::Charset* arg2); (private) */
    /*void ctor(bool arg0, ::java::nio::charset::Charset* arg1, OutputStream* arg2); (private) */
    void ctor(OutputStream* arg0, bool arg1, ::java::lang::String* arg2);

public:
    PrintStream* append(::java::lang::CharSequence* arg0) override;
    PrintStream* append(char16_t arg0) override;
    PrintStream* append(::java::lang::CharSequence* arg0, int32_t arg1, int32_t arg2) override;
    virtual bool checkError();

public: /* protected */
    virtual void clearError();

public:
    void close() override;
    /*void ensureOpen(); (private) */
    void flush() override;
    virtual PrintStream* format(::java::lang::String* arg0, ::java::lang::ObjectArray* arg1);
    virtual PrintStream* format(::java::util::Locale* arg0, ::java::lang::String* arg1, ::java::lang::ObjectArray* arg2);
    /*void newLine(); (private) */
    virtual void print(bool arg0);
    virtual void print(char16_t arg0);
    virtual void print(int32_t arg0);
    virtual void print(int64_t arg0);
    virtual void print(float arg0);
    virtual void print(double arg0);
    virtual void print(::char16_tArray* arg0);
    virtual void print(::java::lang::String* arg0);
    virtual void print(::java::lang::Object* arg0);
    virtual PrintStream* printf(::java::lang::String* arg0, ::java::lang::ObjectArray* arg1);
    virtual PrintStream* printf(::java::util::Locale* arg0, ::java::lang::String* arg1, ::java::lang::ObjectArray* arg2);
    virtual void println();
    virtual void println(bool arg0);
    virtual void println(char16_t arg0);
    virtual void println(int32_t arg0);
    virtual void println(int64_t arg0);
    virtual void println(float arg0);
    virtual void println(double arg0);
    virtual void println(::char16_tArray* arg0);
    virtual void println(::java::lang::String* arg0);
    virtual void println(::java::lang::Object* arg0);
    /*static ::java::lang::Object* requireNonNull(::java::lang::Object* arg0, ::java::lang::String* arg1); (private) */

public: /* protected */
    virtual void setError();
    /*static ::java::nio::charset::Charset* toCharset(::java::lang::String* arg0); (private) */

public:
    void write(int32_t arg0) override;
    /*void write(::char16_tArray* arg0); (private) */
    /*void write(::java::lang::String* arg0); (private) */
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;

    // Generated
    PrintStream(OutputStream* arg0);
    PrintStream(::java::lang::String* arg0);
    PrintStream(File* arg0);
    PrintStream(OutputStream* arg0, bool arg1);
    PrintStream(::java::lang::String* arg0, ::java::lang::String* arg1);
    PrintStream(File* arg0, ::java::lang::String* arg1);
    PrintStream(OutputStream* arg0, bool arg1, ::java::lang::String* arg2);
protected:
    PrintStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    void write(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
