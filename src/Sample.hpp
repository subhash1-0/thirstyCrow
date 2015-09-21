// Generated from /pastry-2.1/license/Sample.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class Sample
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    int32_t nothing {  };

private:
    int32_t something {  };
protected:
    void ctor(int32_t s);

public:
    virtual int32_t eat(int32_t x);

    // Generated
    Sample(int32_t s);
protected:
    Sample(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
