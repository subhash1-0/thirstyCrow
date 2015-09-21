// Generated from /pastry-2.1/src/rice/pastry/Id.java
#include <rice/pastry/Id_Distance.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <Array.hpp>
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
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
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

rice::pastry::Id_Distance::Id_Distance(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::Id_Distance::Id_Distance() 
    : Id_Distance(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::Id_Distance::Id_Distance(::int8_tArray* diff) 
    : Id_Distance(*static_cast< ::default_init_tag* >(0))
{
    ctor(diff);
}

rice::pastry::Id_Distance::Id_Distance(::int32_tArray* diff) 
    : Id_Distance(*static_cast< ::default_init_tag* >(0))
{
    ctor(diff);
}

constexpr int64_t rice::pastry::Id_Distance::serialVersionUID;

void rice::pastry::Id_Distance::ctor()
{
    super::ctor();
    difference = new ::int32_tArray(Id::nlen);
}

void rice::pastry::Id_Distance::ctor(::int8_tArray* diff)
{
    super::ctor();
    difference = new ::int32_tArray(Id::nlen);
    for (auto j = int32_t(0); (j < Id::IdBitLength / int32_t(8)) && (j < npc(diff)->length); j++) {
        auto k = (*diff)[j] & int32_t(255);
        (*difference)[j / int32_t(4)] |= k << ((j % int32_t(4)) * int32_t(8));
    }
}

void rice::pastry::Id_Distance::ctor(::int32_tArray* diff)
{
    super::ctor();
    difference = diff;
}

void rice::pastry::Id_Distance::blit(::int8_tArray* target)
{
    blit(target, 0);
}

void rice::pastry::Id_Distance::blit(::int8_tArray* target, int32_t offset)
{
    for (auto j = int32_t(0); j < Id::IdBitLength / int32_t(8); j++) {
        auto k = (*difference)[j / int32_t(4)] >> ((j % int32_t(4)) * int32_t(8));
        (*target)[offset + j] = static_cast< int8_t >((k & int32_t(255)));
    }
}

int8_tArray* rice::pastry::Id_Distance::copy()
{
    auto target = new ::int8_tArray(Id::IdBitLength / int32_t(8));
    blit(target);
    return target;
}

int32_t rice::pastry::Id_Distance::compareTo(::rice::p2p::commonapi::Id_Distance* obj)
{
    auto oth = java_cast< ::rice::pastry::Id_Distance* >(obj);
    for (auto i = Id::nlen - int32_t(1); i >= 0; i--) {
        if((*difference)[i] != (*npc(oth)->difference)[i]) {
            auto t = (*difference)[i] & int64_t(4294967295LL);
            auto o = (*npc(oth)->difference)[i] & int64_t(4294967295LL);
            if(t < o) {
                return -int32_t(1);
            } else {
                return 1;
            }
        }
    }
    return 0;
}

int32_t rice::pastry::Id_Distance::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< ::rice::p2p::commonapi::Id_Distance* >(arg0));
}

bool rice::pastry::Id_Distance::equals(::java::lang::Object* obj)
{
    if(compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(java_cast< ::rice::pastry::Id_Distance* >(obj))) == 0) {
        return true;
    } else {
        return false;
    }
}

rice::pastry::Id_Distance* rice::pastry::Id_Distance::shift(int32_t cnt, int32_t fill)
{
    return shift(cnt, fill, false);
}

rice::pastry::Id_Distance* rice::pastry::Id_Distance::shift(int32_t cnt, int32_t fill, bool roundUp)
{
    int32_t carry;
    auto bit = int32_t(0);
    auto lsb = int32_t(0);
    if(cnt > 0) {
        for (auto j = int32_t(0); j < cnt; j++) {
            carry = (fill == 0) ? int32_t(0) : int32_t(-0x7fffffff-1);
            for (auto i = Id::nlen - int32_t(1); i >= 0; i--) {
                bit = (*difference)[i] & int32_t(1);
                (*difference)[i] = (static_cast<int32_t>(static_cast<uint32_t>((*difference)[i]) >> int32_t(1))) | carry;
                carry = (bit == 0) ? int32_t(0) : int32_t(-0x7fffffff-1);
            }
            if(j == 0) {
                lsb = bit;
            }
        }
        if(roundUp && lsb > 0) {
            inc();
        }
    } else {
        for (auto j = int32_t(0); j < -cnt; j++) {
            carry = (fill == 0) ? int32_t(0) : int32_t(1);
            for (auto i = int32_t(0); i < Id::nlen; i++) {
                bit = (*difference)[i] & int32_t(-0x7fffffff-1);
                (*difference)[i] = ((*difference)[i] << int32_t(1)) | carry;
                carry = (bit == 0) ? int32_t(0) : int32_t(1);
            }
        }
    }
    return this;
}

int32_t rice::pastry::Id_Distance::hashCode()
{
    auto h = int32_t(0);
    for (auto i = int32_t(0); i < Id::nlen; i++) {
        h ^= (*difference)[i];
    }
    return h;
}

java::lang::String* rice::pastry::Id_Distance::toString()
{
    auto s = u"0x"_j;
    auto tran = (new ::java::lang::StringArray({
        u"0"_j
        , u"1"_j
        , u"2"_j
        , u"3"_j
        , u"4"_j
        , u"5"_j
        , u"6"_j
        , u"7"_j
        , u"8"_j
        , u"9"_j
        , u"A"_j
        , u"B"_j
        , u"C"_j
        , u"D"_j
        , u"E"_j
        , u"F"_j
    }));
    for (auto j = Id::IdBitLength / int32_t(8) - int32_t(1); j >= 0; j--) {
        auto k = (*difference)[j / int32_t(4)] >> ((j % int32_t(4)) * int32_t(8));
        s = ::java::lang::StringBuilder().append(s)->append((*tran)[(k >> int32_t(4)) & int32_t(15)])
            ->append((*tran)[k & int32_t(15)])->toString();
    }
    return ::java::lang::StringBuilder().append(u"< Id.distance "_j)->append(s)
        ->append(u" >"_j)->toString();
}

rice::p2p::commonapi::Id_Distance* rice::pastry::Id_Distance::shiftDistance(int32_t cnt, int32_t fill)
{
    return shift(cnt, fill);
}

void rice::pastry::Id_Distance::inc()
{
    int64_t x;
    int64_t sum;
    auto carry = int32_t(1);
    for (auto i = int32_t(0); i < Id::nlen; i++) {
        x = (*difference)[i] & int64_t(4294967295LL);
        sum = x + carry;
        if(sum >= 4294967296LL) {
            carry = 1;
        } else {
            carry = 0;
        }
        (*difference)[i] = static_cast< int32_t >(sum);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::Id_Distance::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.Id.Distance", 23);
    return c;
}

java::lang::Class* rice::pastry::Id_Distance::getClass0()
{
    return class_();
}

