// Generated from /pastry-2.1/src/rice/pastry/leafset/LSRangeCannotBeDeterminedException.java
#include <rice/pastry/leafset/LSRangeCannotBeDeterminedException.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::leafset::LSRangeCannotBeDeterminedException::LSRangeCannotBeDeterminedException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::leafset::LSRangeCannotBeDeterminedException::LSRangeCannotBeDeterminedException(::java::lang::String* string, int32_t r, int32_t pos, int32_t uniqueNodes, ::rice::p2p::commonapi::NodeHandle* nh, LeafSet* ls) 
    : LSRangeCannotBeDeterminedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(string,r,pos,uniqueNodes,nh,ls);
}

void rice::pastry::leafset::LSRangeCannotBeDeterminedException::ctor(::java::lang::String* string, int32_t r, int32_t pos, int32_t uniqueNodes, ::rice::p2p::commonapi::NodeHandle* nh, LeafSet* ls)
{
    super::ctor(::java::lang::StringBuilder().append(string)->append(u" replication factor:"_j)
        ->append(r)
        ->append(u" nh position:"_j)
        ->append(pos)
        ->append(u" handle:"_j)
        ->append(static_cast< ::java::lang::Object* >(nh))
        ->append(u" ls.uniqueNodes():"_j)
        ->append(uniqueNodes)
        ->append(u" "_j)
        ->append(npc(ls)->toString())->toString());
    this->r = r;
    this->pos = pos;
    this->nh = nh;
    this->uniqueCount = uniqueNodes;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::LSRangeCannotBeDeterminedException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.leafset.LSRangeCannotBeDeterminedException", 54);
    return c;
}

java::lang::Class* rice::pastry::leafset::LSRangeCannotBeDeterminedException::getClass0()
{
    return class_();
}

