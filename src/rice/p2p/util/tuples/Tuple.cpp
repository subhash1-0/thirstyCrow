// Generated from /pastry-2.1/src/rice/p2p/util/tuples/Tuple.java
#include <rice/p2p/util/tuples/Tuple.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::tuples::Tuple::Tuple(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::tuples::Tuple::Tuple(::java::lang::Object* a, ::java::lang::Object* b) 
    : Tuple(*static_cast< ::default_init_tag* >(0))
{
    ctor(a,b);
}

void rice::p2p::util::tuples::Tuple::ctor(::java::lang::Object* a, ::java::lang::Object* b)
{
    super::ctor();
    this->a_ = a;
    this->b_ = b;
}

java::lang::Object* rice::p2p::util::tuples::Tuple::a()
{
    return java_cast< ::java::lang::Object* >(a_);
}

java::lang::Object* rice::p2p::util::tuples::Tuple::b()
{
    return java_cast< ::java::lang::Object* >(b_);
}

bool rice::p2p::util::tuples::Tuple::equals(::java::lang::Object* obj)
{
    if(dynamic_cast< Tuple* >(obj) != nullptr) {
        auto that = java_cast< Tuple* >(obj);
        if(java_cast< ::java::lang::Object* >(this->a_) == nullptr) {
            if(java_cast< ::java::lang::Object* >(npc(that)->a_) != nullptr)
                return false;

        } else {
            if(java_cast< ::java::lang::Object* >(npc(that)->a_) == nullptr)
                return false;

            if(!npc(java_cast< ::java::lang::Object* >(this->a_))->equals(java_cast< ::java::lang::Object* >(npc(that)->a_)))
                return false;

        }
        if(java_cast< ::java::lang::Object* >(this->b_) == nullptr) {
            if(java_cast< ::java::lang::Object* >(npc(that)->b_) != nullptr)
                return false;

        } else {
            if(java_cast< ::java::lang::Object* >(npc(that)->b_) == nullptr)
                return false;

            if(!npc(java_cast< ::java::lang::Object* >(this->b_))->equals(java_cast< ::java::lang::Object* >(npc(that)->b_)))
                return false;

        }
        return true;
    }
    return false;
}

int32_t rice::p2p::util::tuples::Tuple::hashCode()
{
    auto hashA = int32_t(0);
    if(java_cast< ::java::lang::Object* >(a_) != nullptr)
        hashA = npc(java_cast< ::java::lang::Object* >(a_))->hashCode();

    auto hashB = int32_t(0);
    if(java_cast< ::java::lang::Object* >(b_) != nullptr)
        hashB = npc(java_cast< ::java::lang::Object* >(b_))->hashCode();

    return hashA ^ hashB;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::tuples::Tuple::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.tuples.Tuple", 26);
    return c;
}

java::lang::Class* rice::p2p::util::tuples::Tuple::getClass0()
{
    return class_();
}

