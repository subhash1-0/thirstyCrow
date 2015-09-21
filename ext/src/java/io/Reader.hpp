// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Readable.hpp>
#include <java/io/Closeable.hpp>

struct default_init_tag;

class java::io::Reader
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Readable
    , public virtual Closeable
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::Object* lock {  };

private:
    static constexpr int32_t maxSkipBufferSize { int32_t(8192) };
    ::char16_tArray* skipBuffer {  };

protected:
    void ctor();
    void ctor(::java::lang::Object* arg0);
    /*void close(); (already declared) */

public:
    virtual void mark(int32_t arg0);
    virtual bool markSupported();
    virtual int32_t read();
    int32_t read(::java::nio::CharBuffer* arg0) override;
    virtual int32_t read(::char16_tArray* arg0);
    virtual int32_t read(::char16_tArray* arg0, int32_t arg1, int32_t arg2) = 0;
    virtual bool ready();
    virtual void reset();
    virtual int64_t skip(int64_t arg0);

    // Generated

public: /* protected */
    Reader();
    Reader(::java::lang::Object* arg0);
protected:
    Reader(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
