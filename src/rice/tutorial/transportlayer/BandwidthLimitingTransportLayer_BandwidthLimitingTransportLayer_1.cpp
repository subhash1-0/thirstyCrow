// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_BandwidthLimitingSocket.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.hpp>

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
rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1::BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1(BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , BandwidthLimitingTransportLayer_this(BandwidthLimitingTransportLayer_this)
{
    clinit();
    ctor();
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1::run()
{
    {
        synchronized synchronized_0(this);
        {
            BandwidthLimitingTransportLayer_this->bucket = BandwidthLimitingTransportLayer_this->BUCKET_SIZE;
            for (auto _i = npc(BandwidthLimitingTransportLayer_this->sockets)->iterator(); _i->hasNext(); ) {
                BandwidthLimitingTransportLayer_BandwidthLimitingSocket* s = java_cast< BandwidthLimitingTransportLayer_BandwidthLimitingSocket* >(_i->next());
                {
                    npc(s)->notifyBandwidthRefilled();
                }
            }
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1::getClass0()
{
    return class_();
}

