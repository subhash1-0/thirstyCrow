// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_getDefaultReadyStrategy_1.hpp>

#include <rice/pastry/PastryNode.hpp>

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
rice::pastry::PastryNode_getDefaultReadyStrategy_1::PastryNode_getDefaultReadyStrategy_1(PastryNode *PastryNode_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_this(PastryNode_this)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::PastryNode_getDefaultReadyStrategy_1::init()
{
    ready = false;
}

void rice::pastry::PastryNode_getDefaultReadyStrategy_1::setReady(bool r)
{
    if(r != ready) {
        {
            synchronized synchronized_0(PastryNode_this);
            {
                ready = r;
            }
        }
        PastryNode_this->notifyReadyObservers();
    }
}

bool rice::pastry::PastryNode_getDefaultReadyStrategy_1::isReady()
{
    return ready;
}

void rice::pastry::PastryNode_getDefaultReadyStrategy_1::start()
{
    setReady(true);
}

void rice::pastry::PastryNode_getDefaultReadyStrategy_1::stop()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_getDefaultReadyStrategy_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_getDefaultReadyStrategy_1::getClass0()
{
    return class_();
}

