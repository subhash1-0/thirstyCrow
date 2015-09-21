// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/Writer.hpp>

struct default_init_tag;

class java::io::BufferedWriter
    : public Writer
{

public:
    typedef Writer super;

private:
    ::char16_tArray* cb {  };
    static int32_t defaultCharBufferSize_;
    ::java::lang::String* lineSeparator {  };
    int32_t nChars {  };
    int32_t nextChar {  };
    Writer* out {  };

protected:
    void ctor(Writer* arg0);
    void ctor(Writer* arg0, int32_t arg1);

public:
    void close() override;
    /*void ensureOpen(); (private) */
    void flush() override;

public: /* package */
    virtual void flushBuffer();
    /*int32_t min(int32_t arg0, int32_t arg1); (private) */

public:
    virtual void newLine();
    void write(int32_t arg0) override;
    void write(::char16_tArray* arg0, int32_t arg1, int32_t arg2) override;
    void write(::java::lang::String* arg0, int32_t arg1, int32_t arg2) override;

    // Generated
    BufferedWriter(Writer* arg0);
    BufferedWriter(Writer* arg0, int32_t arg1);
protected:
    BufferedWriter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void write(::char16_tArray* arg0);
    virtual void write(::java::lang::String* arg0);

private:
    static int32_t& defaultCharBufferSize();
    virtual ::java::lang::Class* getClass0();
};
