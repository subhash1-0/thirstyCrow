// Generated from /pastry-2.1/src/rice/p2p/util/AttachableCancellable.java
#include <rice/p2p/util/AttachableCancellable.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

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
rice::p2p::util::AttachableCancellable::AttachableCancellable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::AttachableCancellable::AttachableCancellable()
    : AttachableCancellable(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::AttachableCancellable::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::AttachableCancellable::init()
{
    subCancellable = new ::java::util::ArrayList();
}

bool rice::p2p::util::AttachableCancellable::isCancelled()
{
    return subCancellable == nullptr;
}

bool rice::p2p::util::AttachableCancellable::cancel()
{
    ::java::util::Collection* delme;
    {
        synchronized synchronized_0(this);
        {
            if(subCancellable == nullptr)
                return true;

            delme = subCancellable;
            subCancellable = nullptr;
        }
    }
    auto ret = true;
    for (auto _i = npc(delme)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::Cancellable* c = java_cast< ::rice::p2p::commonapi::Cancellable* >(_i->next());
        {
            if(!npc(c)->cancel())
                ret = false;

        }
    }
    return ret;
}

void rice::p2p::util::AttachableCancellable::attach(::rice::p2p::commonapi::Cancellable* c)
{
    if(c == nullptr)
        return;

    auto cancel = false;
    {
        synchronized synchronized_1(this);
        {
            if(subCancellable == nullptr) {
                cancel = true;
            } else {
                npc(subCancellable)->add(c);
            }
        }
    }
    if(cancel) {
        npc(c)->cancel();
    }
}

void rice::p2p::util::AttachableCancellable::detach(::rice::p2p::commonapi::Cancellable* c)
{
    if(c == nullptr)
        return;

    {
        synchronized synchronized_2(this);
        {
            if(subCancellable == nullptr)
                return;

            npc(subCancellable)->remove(c);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::AttachableCancellable::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.AttachableCancellable", 35);
    return c;
}

java::lang::Class* rice::p2p::util::AttachableCancellable::getClass0()
{
    return class_();
}

