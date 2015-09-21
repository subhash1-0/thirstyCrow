// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_newNode_11_run_11_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_newNode_11.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::socket::SocketPastryNodeFactory_newNode_11_run_11_1::SocketPastryNodeFactory_newNode_11_run_11_1(SocketPastryNodeFactory_newNode_11 *SocketPastryNodeFactory_newNode_11_this, ::java::util::ArrayList* pn, ::java::util::ArrayList* re)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_newNode_11_this(SocketPastryNodeFactory_newNode_11_this)
    , pn(pn)
    , re(re)
{
    clinit();
    ctor();
}

void rice::pastry::socket::SocketPastryNodeFactory_newNode_11_run_11_1::receiveResult(::rice::pastry::PastryNode* node)
{
    {
        synchronized synchronized_0(pn);
        {
            npc(pn)->add(static_cast< ::java::lang::Object* >(node));
            npc(pn)->notify();
        }
    }
}

void rice::pastry::socket::SocketPastryNodeFactory_newNode_11_run_11_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::PastryNode* >(result));
}

void rice::pastry::socket::SocketPastryNodeFactory_newNode_11_run_11_1::receiveException(::java::io::IOException* exception)
{
    {
        synchronized synchronized_1(pn);
        {
            npc(re)->add(static_cast< ::java::lang::Object* >(exception));
            npc(pn)->notify();
        }
    }
}

void rice::pastry::socket::SocketPastryNodeFactory_newNode_11_run_11_1::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_newNode_11_run_11_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_newNode_11_run_11_1::getClass0()
{
    return class_();
}

