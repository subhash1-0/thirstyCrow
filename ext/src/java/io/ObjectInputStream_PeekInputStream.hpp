// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/io/InputStream.hpp>

struct default_init_tag;

class java::io::ObjectInputStream_PeekInputStream
    : public InputStream
{

public:
    typedef InputStream super;

private:
    InputStream* in {  };
    int32_t peekb {  };

protected:
    void ctor(InputStream* arg0);

public:
    int32_t available() override;
    void close() override;

public: /* package */
    virtual int32_t peek();

public:
    int32_t read() override;
    int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;

public: /* package */
    virtual void readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    int64_t skip(int64_t arg0) override;

    // Generated

public: /* package */
    ObjectInputStream_PeekInputStream(InputStream* arg0);
protected:
    ObjectInputStream_PeekInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t read(::int8_tArray* b);

private:
    virtual ::java::lang::Class* getClass0();
};
