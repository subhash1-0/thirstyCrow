// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/IllegalArgumentException.hpp>

struct default_init_tag;

class java::lang::NumberFormatException
    : public IllegalArgumentException
{

public:
    typedef IllegalArgumentException super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-2848938806368998894LL) };

protected:
    void ctor();
    void ctor(String* arg0);

public: /* package */
    static NumberFormatException* forInputString(String* arg0);

    // Generated

public:
    NumberFormatException();
    NumberFormatException(String* arg0);
protected:
    NumberFormatException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
