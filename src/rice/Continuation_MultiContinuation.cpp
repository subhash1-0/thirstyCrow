// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_MultiContinuation.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation_MultiContinuation_getSubContinuation_1.hpp>
#include <rice/Continuation.hpp>
#include <ObjectArray.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::Continuation_MultiContinuation::Continuation_MultiContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::Continuation_MultiContinuation::Continuation_MultiContinuation(Continuation* parent, int32_t num) 
    : Continuation_MultiContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor(parent,num);
}

void rice::Continuation_MultiContinuation::ctor(Continuation* parent, int32_t num)
{
    super::ctor();
    this->parent = parent;
    this->result = new ::java::lang::ObjectArray(num);
    this->haveResult = new ::boolArray(num);
    this->done = false;
}

rice::Continuation* rice::Continuation_MultiContinuation::getSubContinuation(int32_t index)
{
    return new Continuation_MultiContinuation_getSubContinuation_1(this, index);
}

void rice::Continuation_MultiContinuation::receive(int32_t index, ::java::lang::Object* o)
{
    if((!done) && (!(*haveResult)[index])) {
        (*haveResult)[index] = true;
        result->set(index, o);
        try {
            if(isDone()) {
                done = true;
                npc(parent)->receiveResult(getResult());
            }
        } catch (::java::lang::Exception* e) {
            done = true;
            npc(parent)->receiveException(e);
        }
    }
}

bool rice::Continuation_MultiContinuation::isDone() /* throws(Exception) */
{
    for (auto i = int32_t(0); i < npc(haveResult)->length; i++) 
                if(!(*haveResult)[i])
            return false;


    return true;
}

java::lang::Object* rice::Continuation_MultiContinuation::getResult()
{
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_MultiContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.Continuation.MultiContinuation", 35);
    return c;
}

java::lang::Class* rice::Continuation_MultiContinuation::getClass0()
{
    return class_();
}

