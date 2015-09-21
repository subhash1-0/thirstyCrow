// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/VirtualMachineError.hpp>

struct default_init_tag;

class java::lang::StackOverflowError
    : public VirtualMachineError
{

public:
    typedef VirtualMachineError super;

private:
    static constexpr int64_t serialVersionUID { int64_t(8609175038441759607LL) };

protected:
    void ctor();
    void ctor(String* arg0);

    // Generated

public:
    StackOverflowError();
    StackOverflowError(String* arg0);
protected:
    StackOverflowError(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
