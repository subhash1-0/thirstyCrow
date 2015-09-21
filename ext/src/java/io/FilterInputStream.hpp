// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/io/InputStream.hpp>

struct default_init_tag;

class java::io::FilterInputStream
    : public InputStream
{

public:
    typedef InputStream super;

public: /* protected */
    std::atomic< InputStream* > in {  };

protected:
    void ctor(InputStream* arg0);

public:
    int32_t available() override;
    void close() override;
    void mark(int32_t arg0) override;
    bool markSupported() override;
    int32_t read() override;
    int32_t read(::int8_tArray* arg0) override;
    int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    void reset() override;
    int64_t skip(int64_t arg0) override;

    // Generated

public: /* protected */
    FilterInputStream(InputStream* arg0);
protected:
    FilterInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
