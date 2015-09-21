// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/VirtualMachineError.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::VirtualMachineError::VirtualMachineError(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::VirtualMachineError::VirtualMachineError()
    : VirtualMachineError(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::VirtualMachineError::VirtualMachineError(String* arg0)
    : VirtualMachineError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::VirtualMachineError::VirtualMachineError(Throwable* arg0)
    : VirtualMachineError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::VirtualMachineError::VirtualMachineError(String* arg0, Throwable* arg1)
    : VirtualMachineError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::lang::VirtualMachineError::serialVersionUID;

void ::java::lang::VirtualMachineError::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::VirtualMachineError::ctor()");
}

void ::java::lang::VirtualMachineError::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::VirtualMachineError::ctor(String* arg0)");
}

void ::java::lang::VirtualMachineError::ctor(Throwable* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::VirtualMachineError::ctor(Throwable* arg0)");
}

void ::java::lang::VirtualMachineError::ctor(String* arg0, Throwable* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::VirtualMachineError::ctor(String* arg0, Throwable* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::VirtualMachineError::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.VirtualMachineError", 29);
    return c;
}

java::lang::Class* java::lang::VirtualMachineError::getClass0()
{
    return class_();
}

