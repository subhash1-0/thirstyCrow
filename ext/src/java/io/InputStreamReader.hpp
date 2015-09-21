// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/nio/charset/fwd-pastry-2.1.hpp>
#include <sun/nio/cs/fwd-pastry-2.1.hpp>
#include <java/io/Reader.hpp>

struct default_init_tag;

class java::io::InputStreamReader
    : public Reader
{

public:
    typedef Reader super;

private:
    ::sun::nio::cs::StreamDecoder* sd {  };

protected:
    void ctor(InputStream* arg0);
    void ctor(InputStream* arg0, ::java::lang::String* arg1);
    void ctor(InputStream* arg0, ::java::nio::charset::Charset* arg1);
    void ctor(InputStream* arg0, ::java::nio::charset::CharsetDecoder* arg1);

public:
    void close() override;
    virtual ::java::lang::String* getEncoding();
    int32_t read() override;
    int32_t read(::char16_tArray* arg0, int32_t arg1, int32_t arg2) override;
    bool ready() override;

    // Generated
    InputStreamReader(InputStream* arg0);
    InputStreamReader(InputStream* arg0, ::java::lang::String* arg1);
    InputStreamReader(InputStream* arg0, ::java::nio::charset::Charset* arg1);
    InputStreamReader(InputStream* arg0, ::java::nio::charset::CharsetDecoder* arg1);
protected:
    InputStreamReader(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    int32_t read(::java::nio::CharBuffer* arg0);
    virtual int32_t read(::char16_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
