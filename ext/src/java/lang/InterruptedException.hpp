// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class java::lang::InterruptedException
    : public Exception
{

public:
    typedef Exception super;

private:
    static constexpr int64_t serialVersionUID { int64_t(6700697376100628473LL) };

protected:
    void ctor();
    void ctor(String* arg0);

    // Generated

public:
    InterruptedException();
    InterruptedException(String* arg0);
protected:
    InterruptedException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
