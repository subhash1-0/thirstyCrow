// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNode.java
#include <rice/pastry/direct/DirectPastryNode.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Thread.hpp>
#include <java/util/Hashtable.hpp>
#include <rice/pastry/PastryNode.hpp>

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

rice::pastry::direct::DirectPastryNode::DirectPastryNode(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::DirectPastryNode::DirectPastryNode()
    : DirectPastryNode(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::util::Hashtable*& rice::pastry::direct::DirectPastryNode::currentNode()
{
    clinit();
    return currentNode_;
}
java::util::Hashtable* rice::pastry::direct::DirectPastryNode::currentNode_;

rice::pastry::PastryNode* rice::pastry::direct::DirectPastryNode::setCurrentNode(::rice::pastry::PastryNode* dpn)
{
    clinit();
    auto current = ::java::lang::Thread::currentThread();
    auto ret = java_cast< ::rice::pastry::PastryNode* >(npc(currentNode_)->get(static_cast< ::java::lang::Object* >(current)));
    if(dpn == nullptr) {
        npc(currentNode_)->remove(static_cast< ::java::lang::Object* >(current));
    } else {
        npc(currentNode_)->put(static_cast< ::java::lang::Object* >(current), static_cast< ::java::lang::Object* >(dpn));
    }
    return ret;
}

rice::pastry::PastryNode* rice::pastry::direct::DirectPastryNode::getCurrentNode()
{
    clinit();
    auto current = ::java::lang::Thread::currentThread();
    auto ret = java_cast< ::rice::pastry::PastryNode* >(npc(currentNode_)->get(static_cast< ::java::lang::Object* >(current)));
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectPastryNode::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.DirectPastryNode", 35);
    return c;
}

void rice::pastry::direct::DirectPastryNode::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        currentNode_ = new ::java::util::Hashtable();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::direct::DirectPastryNode::getClass0()
{
    return class_();
}

