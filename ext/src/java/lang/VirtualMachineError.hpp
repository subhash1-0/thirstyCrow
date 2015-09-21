// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Error.hpp>

struct default_init_tag;

class java::lang::VirtualMachineError
    : public Error
{

public:
    typedef Error super;

private:
    static constexpr int64_t serialVersionUID { int64_t(4161983926571568670LL) };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(Throwable* arg0);
    void ctor(String* arg0, Throwable* arg1);

    // Generated

public:
    VirtualMachineError();
    VirtualMachineError(String* arg0);
    VirtualMachineError(Throwable* arg0);
    VirtualMachineError(String* arg0, Throwable* arg1);
protected:
    VirtualMachineError(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
