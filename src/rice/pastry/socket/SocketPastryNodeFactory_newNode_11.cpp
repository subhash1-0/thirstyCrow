// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_newNode_11.hpp>

#include <java/util/ArrayList.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_newNode_11_run_11_1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

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
rice::pastry::socket::SocketPastryNodeFactory_newNode_11::SocketPastryNodeFactory_newNode_11(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::java::util::ArrayList* pn, ::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* pAddress, ::java::util::ArrayList* re)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
    , pn(pn)
    , nodeId(nodeId)
    , pAddress(pAddress)
    , re(re)
{
    clinit();
    ctor();
}

void rice::pastry::socket::SocketPastryNodeFactory_newNode_11::run()
{
    {
        synchronized synchronized_0(pn);
        {
            SocketPastryNodeFactory_this->newNodeSelector(nodeId, pAddress, new SocketPastryNodeFactory_newNode_11_run_11_1(this, pn, re), nullptr);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_newNode_11::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_newNode_11::getClass0()
{
    return class_();
}

