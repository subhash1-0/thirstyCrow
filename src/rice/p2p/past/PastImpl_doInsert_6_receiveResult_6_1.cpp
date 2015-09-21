// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_doInsert_6_receiveResult_6_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/past/PastException.hpp>
#include <rice/p2p/past/PastImpl_doInsert_6.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>
#include <Array.hpp>

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

rice::p2p::past::PastImpl_doInsert_6_receiveResult_6_1::PastImpl_doInsert_6_receiveResult_6_1(PastImpl_doInsert_6 *PastImpl_doInsert_6_this, ::rice::Continuation* parent, int32_t num)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_doInsert_6_this(PastImpl_doInsert_6_this)
{
    clinit();
    ctor(parent, num);
}

bool rice::p2p::past::PastImpl_doInsert_6_receiveResult_6_1::isDone() /* throws(Exception) */
{
    auto numSuccess = int32_t(0);
    for (auto i = int32_t(0); i < npc(haveResult)->length; i++) 
                if(((*haveResult)[i]) && (npc(::java::lang::Boolean::TRUE())->equals((*result)[i])))
            numSuccess++;


    if(numSuccess >= (PastImpl_doInsert_6_this->PastImpl_this->SUCCESSFUL_INSERT_THRESHOLD * npc(haveResult)->length))
        return true;

    if(super::isDone()) {
        for (auto i = int32_t(0); i < npc(result)->length; i++) 
                        if(dynamic_cast< ::java::lang::Exception* >((*result)[i]) != nullptr)
                if(npc(PastImpl_doInsert_6_this->PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(PastImpl_doInsert_6_this->PastImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"result["_j)->append(i)
                        ->append(u"]:"_j)->toString(), java_cast< ::java::lang::Exception* >((*result)[i]));



        throw new PastException(::java::lang::StringBuilder().append(u"Had only "_j)->append(numSuccess)
            ->append(u" successful inserts out of "_j)
            ->append(npc(result)->length)
            ->append(u" - aborting."_j)->toString());
    }
    return false;
}

java::lang::Object* rice::p2p::past::PastImpl_doInsert_6_receiveResult_6_1::getResult()
{
    auto b = new ::java::lang::BooleanArray(npc(result)->length);
    for (auto i = int32_t(0); i < npc(b)->length; i++) 
                b->set(i, new ::java::lang::Boolean(((*result)[i] == nullptr) || npc(::java::lang::Boolean::TRUE())->equals((*result)[i])));

    return b;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_doInsert_6_receiveResult_6_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_doInsert_6_receiveResult_6_1::getClass0()
{
    return class_();
}

