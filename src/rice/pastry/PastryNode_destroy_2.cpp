// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_destroy_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <rice/pastry/PastryNode.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::PastryNode_destroy_2::PastryNode_destroy_2(PastryNode *PastryNode_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_this(PastryNode_this)
{
    clinit();
    ctor();
}

void rice::pastry::PastryNode_destroy_2::run()
{
    if(PastryNode_this->tl != nullptr)
        npc(PastryNode_this->tl)->destroy();

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_destroy_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_destroy_2::getClass0()
{
    return class_();
}

