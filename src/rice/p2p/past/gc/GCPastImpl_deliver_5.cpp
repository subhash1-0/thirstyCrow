// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_deliver_5.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Vector.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_5_receiveResult_5_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_5_receiveResult_5_2.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
#include <rice/persistence/StorageManager.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::Boolean, ObjectArray, ::java::io::SerializableArray, ComparableArray > BooleanArray;
    } // lang
} // java

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

rice::p2p::past::gc::GCPastImpl_deliver_5::GCPastImpl_deliver_5(GCPastImpl *GCPastImpl_this, ::java::util::Vector* result, ::java::util::Iterator* i, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
    , result(result)
    , i(i)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_deliver_5::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr)
        npc(result)->addElement(o);

    if(npc(i)->hasNext()) {
        auto const id = java_cast< GCId* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        if(npc(GCPastImpl_this->storage)->exists(npc(id)->getId())) {
            auto metadata = java_cast< GCPastMetadata* >(npc(GCPastImpl_this->storage)->getMetadata(npc(id)->getId()));
            if(metadata != nullptr) {
                if(npc(metadata)->getExpiration() < npc(id)->getExpiration()) {
                    npc(GCPastImpl_this->storage)->setMetadata(npc(id)->getId(), npc(metadata)->setExpiration(npc(id)->getExpiration()), this);
                } else {
                    receiveResult(static_cast< ::java::lang::Object* >(::java::lang::Boolean::FALSE()));
                }
            } else {
                npc(GCPastImpl_this->storage)->getObject(npc(id)->getId(), new GCPastImpl_deliver_5_receiveResult_5_1(this, id, this));
            }
        } else {
            if(GCPastImpl_this->trash != nullptr) {
                npc(GCPastImpl_this->trash)->getObject(npc(id)->getId(), new GCPastImpl_deliver_5_receiveResult_5_2(this, id, this));
            } else {
                receiveResult(static_cast< ::java::lang::Object* >(::java::lang::Boolean::FALSE()));
            }
        }
    } else {
        npc(parent)->receiveResult(java_cast< ::java::lang::ObjectArray* >(npc(result)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::java::lang::BooleanArray(int32_t(0))))));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_5::getClass0()
{
    return class_();
}

