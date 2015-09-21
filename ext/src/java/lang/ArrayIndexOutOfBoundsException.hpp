// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/IndexOutOfBoundsException.hpp>

struct default_init_tag;

class java::lang::ArrayIndexOutOfBoundsException
    : public IndexOutOfBoundsException
{

public:
    typedef IndexOutOfBoundsException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-5116101128118950844LL) };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(String* arg0);

    // Generated

public:
    ArrayIndexOutOfBoundsException();
    ArrayIndexOutOfBoundsException(int32_t arg0);
    ArrayIndexOutOfBoundsException(String* arg0);
protected:
    ArrayIndexOutOfBoundsException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
