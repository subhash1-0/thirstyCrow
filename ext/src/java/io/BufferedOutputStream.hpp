// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/io/FilterOutputStream.hpp>

struct default_init_tag;

class java::io::BufferedOutputStream
    : public FilterOutputStream
{

public:
    typedef FilterOutputStream super;

public: /* protected */
    ::int8_tArray* buf {  };
    int32_t count {  };

protected:
    void ctor(OutputStream* arg0);
    void ctor(OutputStream* arg0, int32_t arg1);

public:
    void flush() override;
    /*void flushBuffer(); (private) */
    void write(int32_t arg0) override;
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;

    // Generated
    BufferedOutputStream(OutputStream* arg0);
    BufferedOutputStream(OutputStream* arg0, int32_t arg1);
protected:
    BufferedOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    void write(::int8_tArray* b);

private:
    virtual ::java::lang::Class* getClass0();
};
