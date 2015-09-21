// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_collect_8_receiveResult_8_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/gc/GCPastImpl_collect_8.hpp>
#include <rice/p2p/past/gc/GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
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

rice::p2p::past::gc::GCPastImpl_collect_8_receiveResult_8_1::GCPastImpl_collect_8_receiveResult_8_1(GCPastImpl_collect_8 *GCPastImpl_collect_8_this, ::rice::p2p::commonapi::Id* gid, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_collect_8_this(GCPastImpl_collect_8_this)
    , gid(gid)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_collect_8_receiveResult_8_1::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr) {
        npc(GCPastImpl_collect_8_this->GCPastImpl_this->trash)->store(gid, npc(GCPastImpl_collect_8_this->GCPastImpl_this->storage)->getMetadata(gid), java_cast< ::java::io::Serializable* >(o), new GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1(this, gid, parent));
    } else {
        npc(GCPastImpl_collect_8_this->GCPastImpl_this->storage)->unstore(gid, this);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_collect_8_receiveResult_8_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_collect_8_receiveResult_8_1::getClass0()
{
    return class_();
}

