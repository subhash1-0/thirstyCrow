// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/io/OutputStream.hpp>

struct default_init_tag;

class java::io::FilterOutputStream
    : public OutputStream
{

public:
    typedef OutputStream super;

public: /* protected */
    OutputStream* out {  };

protected:
    void ctor(OutputStream* arg0);

public:
    void close() override;
    void flush() override;
    void write(int32_t arg0) override;
    void write(::int8_tArray* arg0) override;
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;

    // Generated
    FilterOutputStream(OutputStream* arg0);
protected:
    FilterOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
