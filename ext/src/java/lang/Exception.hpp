// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Throwable.hpp>

struct default_init_tag;

class java::lang::Exception
    : public Throwable
{

public:
    typedef Throwable super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-3387516993124229948LL) };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(Throwable* arg0);
    void ctor(String* arg0, Throwable* arg1);
    void ctor(String* arg0, Throwable* arg1, bool arg2, bool arg3);

    // Generated

public:
    Exception();
    Exception(String* arg0);
    Exception(Throwable* arg0);
    Exception(String* arg0, Throwable* arg1);

public: /* protected */
    Exception(String* arg0, Throwable* arg1, bool arg2, bool arg3);
protected:
    Exception(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
