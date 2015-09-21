// Generated from /pastry-2.1/lib/xmlpull_1_1_3_4a.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/xmlpull/v1/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class org::xmlpull::v1::XmlPullParserException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;

public: /* protected */
    int32_t column {  };
    ::java::lang::Throwable* detail {  };
    int32_t row {  };

protected:
    void ctor(::java::lang::String* s);
    void ctor(::java::lang::String* msg, XmlPullParser* parser, ::java::lang::Throwable* chain);

public:
    virtual int32_t getColumnNumber();
    virtual ::java::lang::Throwable* getDetail();
    virtual int32_t getLineNumber();
    void printStackTrace() override;

    // Generated
    XmlPullParserException(::java::lang::String* s);
    XmlPullParserException(::java::lang::String* msg, XmlPullParser* parser, ::java::lang::Throwable* chain);
protected:
    XmlPullParserException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void printStackTrace(::java::io::PrintStream* arg0);
    virtual void printStackTrace(::java::io::PrintWriter* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
