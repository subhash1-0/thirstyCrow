// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/text/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class java::text::ParseException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;

private:
    int32_t errorOffset {  };
    static constexpr int64_t serialVersionUID { int64_t(2703218443322787634LL) };

protected:
    void ctor(::java::lang::String* arg0, int32_t arg1);

public:
    virtual int32_t getErrorOffset();

    // Generated
    ParseException(::java::lang::String* arg0, int32_t arg1);
protected:
    ParseException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
