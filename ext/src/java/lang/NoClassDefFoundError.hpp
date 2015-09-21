// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/LinkageError.hpp>

struct default_init_tag;

class java::lang::NoClassDefFoundError
    : public LinkageError
{

public:
    typedef LinkageError super;

private:
    static constexpr int64_t serialVersionUID { int64_t(9095859863287012458LL) };

protected:
    void ctor();
    void ctor(String* arg0);

    // Generated

public:
    NoClassDefFoundError();
    NoClassDefFoundError(String* arg0);
protected:
    NoClassDefFoundError(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
