// Generated from /pastry-2.1/src/rice/pastry/testing/PartitionChecker.java
#include <rice/pastry/testing/PartitionChecker_buildRing_1.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/ConnectException.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketTimeoutException.hpp>
#include <java/util/HashSet.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSet.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/testing/PartitionChecker_Ring.hpp>
#include <rice/pastry/testing/PartitionChecker.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

namespace
{
    template<typename F>
    struct finally_
    {
        finally_(F f) : f(f), moved(false) { }
        finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
        ~finally_() { if(!moved) f(); }
    private:
        finally_(const finally_&); finally_& operator=(const finally_&);
        F f;
        bool moved;
    };

    template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
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
rice::pastry::testing::PartitionChecker_buildRing_1::PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
    , handle(handle)
    , ring(ring)
    , unseen(unseen)
{
    clinit();
    ctor();
}

rice::pastry::testing::PartitionChecker_buildRing_1::PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::Runnable* arg0)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
    , handle(handle)
    , ring(ring)
    , unseen(unseen)
{
    clinit();
    ctor(arg0);
}

rice::pastry::testing::PartitionChecker_buildRing_1::PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::String* arg0)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
    , handle(handle)
    , ring(ring)
    , unseen(unseen)
{
    clinit();
    ctor(arg0);
}

rice::pastry::testing::PartitionChecker_buildRing_1::PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::Runnable* arg0, ::java::security::AccessControlContext* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
    , handle(handle)
    , ring(ring)
    , unseen(unseen)
{
    clinit();
    ctor(arg0, arg1);
}

rice::pastry::testing::PartitionChecker_buildRing_1::PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
    , handle(handle)
    , ring(ring)
    , unseen(unseen)
{
    clinit();
    ctor(arg0, arg1);
}

rice::pastry::testing::PartitionChecker_buildRing_1::PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
    , handle(handle)
    , ring(ring)
    , unseen(unseen)
{
    clinit();
    ctor(arg0, arg1);
}

rice::pastry::testing::PartitionChecker_buildRing_1::PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::Runnable* arg0, ::java::lang::String* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
    , handle(handle)
    , ring(ring)
    , unseen(unseen)
{
    clinit();
    ctor(arg0, arg1);
}

rice::pastry::testing::PartitionChecker_buildRing_1::PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
    , handle(handle)
    , ring(ring)
    , unseen(unseen)
{
    clinit();
    ctor(arg0, arg1, arg2);
}

rice::pastry::testing::PartitionChecker_buildRing_1::PartitionChecker_buildRing_1(PartitionChecker *PartitionChecker_this, ::rice::pastry::socket::SocketNodeHandle* handle, PartitionChecker_Ring* ring, ::java::util::HashSet* unseen, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2, int64_t arg3)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
    , handle(handle)
    , ring(ring)
    , unseen(unseen)
{
    clinit();
    ctor(arg0, arg1, arg2, arg3);
}

void rice::pastry::testing::PartitionChecker_buildRing_1::run()
{
    {
        auto finally0 = finally([&] {
            {
                synchronized synchronized_0(unseen);
                {
                    PartitionChecker_this->numThreads--;
                    npc(unseen)->notifyAll();
                }
            }
        });
        try {
            auto ls = PartitionChecker_this->getLeafSet(handle);
            npc(PartitionChecker_this->ps)->println(::java::lang::StringBuilder().append(npc(npc(npc(handle)->getInetSocketAddress())->getAddress())->getHostAddress())->append(u":"_j)
                ->append(npc(npc(handle)->getInetSocketAddress())->getPort())->toString());
            auto ns = npc(ls)->neighborSet(::java::lang::Integer::MAX_VALUE);
            if(!npc(npc(ns)->get(int32_t(0)))->equals(static_cast< ::java::lang::Object* >(handle))) {
                npc(ring)->addFailure(handle, new ::java::lang::Exception(::java::lang::StringBuilder().append(u"Node is now "_j)->append(static_cast< ::java::lang::Object* >(npc(ns)->get(int32_t(0))))->toString()));
            }
            {
                synchronized synchronized_1(unseen);
                {
                    for (auto i = int32_t(1); i < npc(ns)->size(); i++) 
                                                if((!npc(ring)->contains(npc(ns)->get(i))) && (!npc(PartitionChecker_this->dead)->contains(static_cast< ::java::lang::Object* >(npc(ns)->get(i)))))
                            npc(unseen)->add(static_cast< ::java::lang::Object* >(npc(ns)->get(i)));


                }
            }
        } catch (::java::net::ConnectException* e) {
            npc(ring)->addFailure(handle, e);
            npc(PartitionChecker_this->dead)->add(static_cast< ::java::lang::Object* >(handle));
        } catch (::java::net::SocketTimeoutException* e) {
            npc(ring)->addFailure(handle, e);
            npc(PartitionChecker_this->dead)->add(static_cast< ::java::lang::Object* >(handle));
        } catch (::java::io::IOException* e) {
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PartitionChecker_buildRing_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::PartitionChecker_buildRing_1::getClass0()
{
    return class_();
}

