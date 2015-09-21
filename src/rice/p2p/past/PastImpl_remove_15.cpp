// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_remove_15.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/PastImpl_remove_15_receiveResult_15_1.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/persistence/Cache.hpp>
#include <rice/persistence/StorageManager.hpp>

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

rice::p2p::past::PastImpl_remove_15::PastImpl_remove_15(PastImpl *PastImpl_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , id(id)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_remove_15::receiveResult(::java::lang::Object* o)
{
    npc(PastImpl_this->backup)->cache(id, npc(PastImpl_this->storage)->getMetadata(id), java_cast< ::java::io::Serializable* >(o), new PastImpl_remove_15_receiveResult_15_1(this, id, parent));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_remove_15::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_remove_15::getClass0()
{
    return class_();
}

