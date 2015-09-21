// Generated from /pastry-2.1/src/rice/pastry/direct/DirectSizeChecker.java
#include <rice/pastry/direct/DirectSizeChecker.hpp>

#include <java/lang/Object.hpp>
#include <rice/pastry/direct/DirectNodeHandle.hpp>

rice::pastry::direct::DirectSizeChecker::DirectSizeChecker(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::DirectSizeChecker::DirectSizeChecker() 
    : DirectSizeChecker(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::direct::DirectSizeChecker::DirectSizeChecker(int32_t directNodeHandleSize) 
    : DirectSizeChecker(*static_cast< ::default_init_tag* >(0))
{
    ctor(directNodeHandleSize);
}

void rice::pastry::direct::DirectSizeChecker::init()
{
    directNodeHandleSize = int32_t(20) + int32_t(8) + int32_t(1)+ int32_t(6);
}

void rice::pastry::direct::DirectSizeChecker::ctor()
{
    super::ctor();
    init();
}

void rice::pastry::direct::DirectSizeChecker::ctor(int32_t directNodeHandleSize)
{
    ctor();
    this->directNodeHandleSize = directNodeHandleSize;
}

void rice::pastry::direct::DirectSizeChecker::writeSpecial(::java::lang::Object* o) /* throws(IOException) */
{
    if(dynamic_cast< DirectNodeHandle* >(o) != nullptr) {
        count += directNodeHandleSize;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectSizeChecker::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.DirectSizeChecker", 36);
    return c;
}

java::lang::Class* rice::pastry::direct::DirectSizeChecker::getClass0()
{
    return class_();
}

