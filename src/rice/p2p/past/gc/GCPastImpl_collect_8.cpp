// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_collect_8.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/gc/GCPastImpl_collect_8_receiveResult_8_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
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

rice::p2p::past::gc::GCPastImpl_collect_8::GCPastImpl_collect_8(GCPastImpl *GCPastImpl_this, ::java::util::Iterator* i, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
    , i(i)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_collect_8::receiveResult(::java::lang::Object* o)
{
    if(npc(i)->hasNext()) {
        auto const gid = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        auto metadata = java_cast< GCPastMetadata* >(npc(GCPastImpl_this->storage)->getMetadata(gid));
        GCPastImpl_this->collected++;
        if(GCPastImpl_this->trash != nullptr) {
            npc(GCPastImpl_this->storage)->getObject(gid, new GCPastImpl_collect_8_receiveResult_8_1(this, gid, this));
        } else {
            npc(GCPastImpl_this->storage)->unstore(gid, this);
        }
    } else {
        npc(parent)->receiveResult(::java::lang::Boolean::TRUE());
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_collect_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_collect_8::getClass0()
{
    return class_();
}

