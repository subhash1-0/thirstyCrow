// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/util/zip/fwd-pastry-2.1.hpp>
#include <java/io/FilterOutputStream.hpp>

struct default_init_tag;

class java::util::zip::DeflaterOutputStream
    : public ::java::io::FilterOutputStream
{

public:
    typedef ::java::io::FilterOutputStream super;

public: /* protected */
    ::int8_tArray* buf {  };

private:
    bool closed {  };

public: /* protected */
    Deflater* def {  };

private:
    bool syncFlush {  };

public: /* package */
    bool usesDefaultDeflater {  };

protected:
    void ctor(::java::io::OutputStream* arg0);
    void ctor(::java::io::OutputStream* arg0, Deflater* arg1);
    void ctor(::java::io::OutputStream* arg0, bool arg1);
    void ctor(::java::io::OutputStream* arg0, Deflater* arg1, int32_t arg2);
    void ctor(::java::io::OutputStream* arg0, Deflater* arg1, bool arg2);
    void ctor(::java::io::OutputStream* arg0, Deflater* arg1, int32_t arg2, bool arg3);

public:
    void close() override;

public: /* protected */
    virtual void deflate();

public:
    virtual void finish();
    void flush() override;
    void write(int32_t arg0) override;
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;

    // Generated
    DeflaterOutputStream(::java::io::OutputStream* arg0);
    DeflaterOutputStream(::java::io::OutputStream* arg0, Deflater* arg1);
    DeflaterOutputStream(::java::io::OutputStream* arg0, bool arg1);
    DeflaterOutputStream(::java::io::OutputStream* arg0, Deflater* arg1, int32_t arg2);
    DeflaterOutputStream(::java::io::OutputStream* arg0, Deflater* arg1, bool arg2);
    DeflaterOutputStream(::java::io::OutputStream* arg0, Deflater* arg1, int32_t arg2, bool arg3);
protected:
    DeflaterOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    void write(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
