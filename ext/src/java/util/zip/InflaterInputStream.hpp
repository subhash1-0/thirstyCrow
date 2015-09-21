// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/util/zip/fwd-pastry-2.1.hpp>
#include <java/io/FilterInputStream.hpp>

struct default_init_tag;

class java::util::zip::InflaterInputStream
    : public ::java::io::FilterInputStream
{

public:
    typedef ::java::io::FilterInputStream super;

private:
    ::int8_tArray* b {  };

public: /* protected */
    ::int8_tArray* buf {  };

private:
    bool closed {  };

public: /* protected */
    Inflater* inf {  };
    int32_t len {  };

private:
    bool reachEOF {  };
    ::int8_tArray* singleByteBuf {  };

public: /* package */
    bool usesDefaultInflater {  };

protected:
    void ctor(::java::io::InputStream* arg0);
    void ctor(::java::io::InputStream* arg0, Inflater* arg1);
    void ctor(::java::io::InputStream* arg0, Inflater* arg1, int32_t arg2);

public:
    int32_t available() override;
    void close() override;
    /*void ensureOpen(); (private) */

public: /* protected */
    virtual void fill();

public:
    void mark(int32_t arg0) override;
    bool markSupported() override;
    int32_t read() override;
    int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    void reset() override;
    int64_t skip(int64_t arg0) override;

    // Generated
    InflaterInputStream(::java::io::InputStream* arg0);
    InflaterInputStream(::java::io::InputStream* arg0, Inflater* arg1);
    InflaterInputStream(::java::io::InputStream* arg0, Inflater* arg1, int32_t arg2);
protected:
    InflaterInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    int32_t read(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
