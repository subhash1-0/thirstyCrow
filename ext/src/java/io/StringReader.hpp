// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/io/Reader.hpp>

struct default_init_tag;

class java::io::StringReader
    : public Reader
{

public:
    typedef Reader super;

private:
    int32_t length {  };
    int32_t mark_ {  };
    int32_t next {  };
    ::java::lang::String* str {  };

protected:
    void ctor(::java::lang::String* arg0);

public:
    void close() override;
    /*void ensureOpen(); (private) */
    void mark(int32_t arg0) override;
    bool markSupported() override;
    int32_t read() override;
    int32_t read(::char16_tArray* arg0, int32_t arg1, int32_t arg2) override;
    bool ready() override;
    void reset() override;
    int64_t skip(int64_t arg0) override;

    // Generated
    StringReader(::java::lang::String* arg0);
protected:
    StringReader(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    int32_t read(::java::nio::CharBuffer* arg0);
    virtual int32_t read(::char16_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
