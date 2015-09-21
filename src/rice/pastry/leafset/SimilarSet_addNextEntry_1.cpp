// Generated from /pastry-2.1/src/rice/pastry/leafset/SimilarSet.java
#include <rice/pastry/leafset/SimilarSet_addNextEntry_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/leafset/SimilarSet.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::leafset::SimilarSet_addNextEntry_1::SimilarSet_addNextEntry_1(SimilarSet *SimilarSet_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SimilarSet_this(SimilarSet_this)
{
    clinit();
    ctor();
}

int32_t rice::pastry::leafset::SimilarSet_addNextEntry_1::compare(::rice::pastry::NodeHandle* a, ::rice::pastry::NodeHandle* b)
{
    if(SimilarSet_this->clockwise)
        return npc(npc(a)->getId())->compareTo(npc(b)->getId());

    return npc(npc(b)->getId())->compareTo(npc(a)->getId());
}

int32_t rice::pastry::leafset::SimilarSet_addNextEntry_1::compare(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ 
    return compare(dynamic_cast< ::rice::pastry::NodeHandle* >(arg0), dynamic_cast< ::rice::pastry::NodeHandle* >(arg1));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::SimilarSet_addNextEntry_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

bool rice::pastry::leafset::SimilarSet_addNextEntry_1::equals(::java::lang::Object* arg0)
{
    return Object::equals(arg0);
}

java::lang::Class* rice::pastry::leafset::SimilarSet_addNextEntry_1::getClass0()
{
    return class_();
}

