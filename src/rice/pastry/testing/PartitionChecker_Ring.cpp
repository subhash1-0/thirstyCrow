// Generated from /pastry-2.1/src/rice/pastry/testing/PartitionChecker.java
#include <rice/pastry/testing/PartitionChecker_Ring.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/testing/PartitionChecker.hpp>

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
rice::pastry::testing::PartitionChecker_Ring::PartitionChecker_Ring(PartitionChecker *PartitionChecker_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionChecker_this(PartitionChecker_this)
{
    clinit();
}

rice::pastry::testing::PartitionChecker_Ring::PartitionChecker_Ring(PartitionChecker *PartitionChecker_this, ::java::net::InetSocketAddress* bootAddr) 
    : PartitionChecker_Ring(PartitionChecker_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(bootAddr);
}

void rice::pastry::testing::PartitionChecker_Ring::ctor(::java::net::InetSocketAddress* bootAddr)
{
    super::ctor();
    name = npc(bootAddr)->toString();
    myBootstraps = new ::java::util::HashSet();
    npc(myBootstraps)->add(static_cast< ::java::lang::Object* >(bootAddr));
    nodes = new ::java::util::HashSet();
}

bool rice::pastry::testing::PartitionChecker_Ring::contains(::rice::pastry::NodeHandle* handle)
{
    return npc(nodes)->contains(static_cast< ::java::lang::Object* >(handle));
}

java::lang::String* rice::pastry::testing::PartitionChecker_Ring::getName()
{
    return name;
}

void rice::pastry::testing::PartitionChecker_Ring::addFailure(::rice::pastry::socket::SocketNodeHandle* handle, ::java::lang::Exception* e)
{
}

void rice::pastry::testing::PartitionChecker_Ring::addNode(::rice::pastry::socket::SocketNodeHandle* snh)
{
    auto newAddr = npc(snh)->getInetSocketAddress();
    {
        synchronized synchronized_0(PartitionChecker_this->unmatchedBootstraps);
        {
            if(npc(PartitionChecker_this->unmatchedBootstraps)->contains(static_cast< ::java::lang::Object* >(newAddr))) {
                npc(PartitionChecker_this->unmatchedBootstraps)->remove(static_cast< ::java::lang::Object* >(newAddr));
            }
        }
    }
    if(npc(PartitionChecker_this->bootstraps)->contains(static_cast< ::java::lang::Object* >(newAddr))) {
        npc(myBootstraps)->add(static_cast< ::java::lang::Object* >(newAddr));
    }
    npc(nodes)->add(static_cast< ::java::lang::Object* >(snh));
}

java::lang::String* rice::pastry::testing::PartitionChecker_Ring::toString()
{
    auto s = ::java::lang::StringBuilder().append(npc(nodes)->size())->append(u":"_j)
        ->append(npc(myBootstraps)->size())
        ->append(u": boots:"_j)->toString();
    {
        synchronized synchronized_1(myBootstraps);
        {
            auto i = npc(myBootstraps)->iterator();
            s = ::java::lang::StringBuilder(s).append(static_cast< ::java::lang::Object* >(java_cast< ::java::net::InetSocketAddress* >(npc(i)->next())))->toString();
            while (npc(i)->hasNext()) {
                s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u","_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::net::InetSocketAddress* >(npc(i)->next())))->toString())->toString();
            }
        }
    }
    s = ::java::lang::StringBuilder(s).append(u" non-boots:"_j)->toString();
    {
        synchronized synchronized_2(nodes);
        {
            auto i = npc(nodes)->iterator();
            while (npc(i)->hasNext()) {
                auto nxt = java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next());
                if(!npc(PartitionChecker_this->bootstraps)->contains(static_cast< ::java::lang::Object* >(nxt)))
                    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u","_j)->append(static_cast< ::java::lang::Object* >(nxt))->toString())->toString();

            }
        }
    }
    return s;
}

int32_t rice::pastry::testing::PartitionChecker_Ring::compareTo(PartitionChecker_Ring* arg0)
{
    auto that = java_cast< PartitionChecker_Ring* >(arg0);
    return this->size() - npc(that)->size();
}

int32_t rice::pastry::testing::PartitionChecker_Ring::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< PartitionChecker_Ring* >(arg0));
}

int32_t rice::pastry::testing::PartitionChecker_Ring::size()
{
    return npc(nodes)->size();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PartitionChecker_Ring::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PartitionChecker.Ring", 41);
    return c;
}

java::lang::Class* rice::pastry::testing::PartitionChecker_Ring::getClass0()
{
    return class_();
}

