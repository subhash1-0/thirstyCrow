// Generated from /pastry-2.1/src/rice/p2p/util/tuples/MutableTuple.java
#include <rice/p2p/util/tuples/MutableTuple.hpp>

#include <java/lang/Object.hpp>

rice::p2p::util::tuples::MutableTuple::MutableTuple(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::tuples::MutableTuple::MutableTuple(::java::lang::Object* a, ::java::lang::Object* b) 
    : MutableTuple(*static_cast< ::default_init_tag* >(0))
{
    ctor(a,b);
}

rice::p2p::util::tuples::MutableTuple::MutableTuple() 
    : MutableTuple(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::tuples::MutableTuple::ctor(::java::lang::Object* a, ::java::lang::Object* b)
{
    super::ctor(a, b);
}

void rice::p2p::util::tuples::MutableTuple::ctor()
{
    super::ctor(nullptr, nullptr);
}

void rice::p2p::util::tuples::MutableTuple::set(::java::lang::Object* a, ::java::lang::Object* b)
{
    setA(a);
    setB(b);
}

void rice::p2p::util::tuples::MutableTuple::setA(::java::lang::Object* a)
{
    this->a_ = a;
}

void rice::p2p::util::tuples::MutableTuple::setB(::java::lang::Object* b)
{
    this->b_ = b;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::tuples::MutableTuple::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.tuples.MutableTuple", 33);
    return c;
}

java::lang::Class* rice::p2p::util::tuples::MutableTuple::getClass0()
{
    return class_();
}

