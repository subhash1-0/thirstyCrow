// Generated from /pastry-2.1/src/rice/p2p/util/tuples/Tuple3.java
#include <rice/p2p/util/tuples/Tuple3.hpp>

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

rice::p2p::util::tuples::Tuple3::Tuple3(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::tuples::Tuple3::Tuple3(::java::lang::Object* a, ::java::lang::Object* b, ::java::lang::Object* c) 
    : Tuple3(*static_cast< ::default_init_tag* >(0))
{
    ctor(a,b,c);
}

void rice::p2p::util::tuples::Tuple3::ctor(::java::lang::Object* a, ::java::lang::Object* b, ::java::lang::Object* c)
{
    super::ctor();
    this->a_ = a;
    this->b_ = b;
    this->c_ = c;
}

java::lang::Object* rice::p2p::util::tuples::Tuple3::a()
{
    return java_cast< ::java::lang::Object* >(a_);
}

java::lang::Object* rice::p2p::util::tuples::Tuple3::b()
{
    return java_cast< ::java::lang::Object* >(b_);
}

java::lang::Object* rice::p2p::util::tuples::Tuple3::c()
{
    return java_cast< ::java::lang::Object* >(c_);
}

bool rice::p2p::util::tuples::Tuple3::equals(::java::lang::Object* obj)
{
    if(dynamic_cast< Tuple3* >(obj) != nullptr) {
        auto that = java_cast< Tuple3* >(obj);
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
        if(java_cast< ::java::lang::Object* >(this->c_) == nullptr) {
            if(java_cast< ::java::lang::Object* >(npc(that)->c_) != nullptr)
                return false;

        } else {
            if(java_cast< ::java::lang::Object* >(npc(that)->c_) == nullptr)
                return false;

            if(!npc(java_cast< ::java::lang::Object* >(this->c_))->equals(java_cast< ::java::lang::Object* >(npc(that)->c_)))
                return false;

        }
        return true;
    }
    return false;
}

int32_t rice::p2p::util::tuples::Tuple3::hashCode()
{
    auto hashA = int32_t(0);
    if(java_cast< ::java::lang::Object* >(a_) != nullptr)
        hashA = npc(java_cast< ::java::lang::Object* >(a_))->hashCode();

    auto hashB = int32_t(0);
    if(java_cast< ::java::lang::Object* >(b_) != nullptr)
        hashB = npc(java_cast< ::java::lang::Object* >(b_))->hashCode();

    auto hashC = int32_t(0);
    if(java_cast< ::java::lang::Object* >(b_) != nullptr)
        hashC = npc(java_cast< ::java::lang::Object* >(c_))->hashCode();

    return hashA ^ hashB ^ hashC;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::tuples::Tuple3::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.tuples.Tuple3", 27);
    return c;
}

java::lang::Class* rice::p2p::util::tuples::Tuple3::getClass0()
{
    return class_();
}

