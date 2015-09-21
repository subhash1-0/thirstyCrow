// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Throwable_PrintStreamOrWriter.hpp>

struct default_init_tag;

class java::lang::Throwable_WrappedPrintWriter
    : public Throwable_PrintStreamOrWriter
{

public:
    typedef Throwable_PrintStreamOrWriter super;

private:
    ::java::io::PrintWriter* printWriter {  };

protected:
    void ctor(::java::io::PrintWriter* arg0);

public: /* package */
    Object* lock() override;
    void println(Object* arg0) override;

    // Generated
    Throwable_WrappedPrintWriter(::java::io::PrintWriter* arg0);
protected:
    Throwable_WrappedPrintWriter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
