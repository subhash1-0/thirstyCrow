// Generated from /pastry-2.1/src/rice/pastry/Id.java
#include <rice/pastry/Id.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/math/BigInteger.hpp>
#include <java/util/Random.hpp>
#include <java/util/WeakHashMap.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/Id_Distance.hpp>
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
rice::pastry::Id::Id(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::Id::Id(::int32_tArray* material) 
    : Id(*static_cast< ::default_init_tag* >(0))
{
    ctor(material);
}

constexpr int16_t rice::pastry::Id::TYPE;

java::util::WeakHashMap*& rice::pastry::Id::ID_MAP()
{
    clinit();
    return ID_MAP_;
}
java::util::WeakHashMap* rice::pastry::Id::ID_MAP_;

java::lang::StringArray*& rice::pastry::Id::tran()
{
    clinit();
    return tran_;
}
java::lang::StringArray* rice::pastry::Id::tran_;

constexpr int32_t rice::pastry::Id::IdBitLength;

constexpr int32_t rice::pastry::Id::nlen;

constexpr int64_t rice::pastry::Id::serialVersionUID;

int32_tArray*& rice::pastry::Id::Null()
{
    clinit();
    return Null_;
}
int32_tArray* rice::pastry::Id::Null_;

int32_tArray*& rice::pastry::Id::One()
{
    clinit();
    return One_;
}
int32_tArray* rice::pastry::Id::One_;

int32_tArray*& rice::pastry::Id::NegOne()
{
    clinit();
    return NegOne_;
}
int32_tArray* rice::pastry::Id::NegOne_;

int32_tArray*& rice::pastry::Id::Half()
{
    clinit();
    return Half_;
}
int32_tArray* rice::pastry::Id::Half_;

void rice::pastry::Id::ctor(::int32_tArray* material)
{
    super::ctor();
    Id_ = new ::int32_tArray(nlen);
    for (auto i = int32_t(0); (i < nlen) && (i < npc(material)->length); i++) 
                (*Id_)[i] = (*material)[i];

}

int32_t rice::pastry::Id::numDigits(int32_t base)
{
    clinit();
    return IdBitLength / base;
}

rice::pastry::Id* rice::pastry::Id::makeRandomId(::java::util::Random* rng)
{
    clinit();
    auto material = new ::int8_tArray(IdBitLength / int32_t(8));
    npc(rng)->nextBytes(material);
    return build(material);
}

rice::pastry::Id* rice::pastry::Id::makeRandomId(::rice::environment::random::RandomSource* rng)
{
    clinit();
    auto material = new ::int8_tArray(IdBitLength / int32_t(8));
    npc(rng)->nextBytes(material);
    return build(material);
}

rice::pastry::Id* rice::pastry::Id::build(::int32_tArray* material)
{
    clinit();
    return resolve(ID_MAP_, new ::rice::pastry::Id(material));
}

rice::pastry::Id* rice::pastry::Id::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    clinit();
    auto material = new ::int32_tArray(nlen);
    for (auto i = int32_t(0); i < npc(material)->length; i++) {
        (*material)[i] = npc(buf)->readInt();
    }
    return build(material);
}

void rice::pastry::Id::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    for (auto i = int32_t(0); i < npc(Id_)->length; i++) {
        npc(buf)->writeInt((*Id_)[i]);
    }
}

rice::pastry::Id* rice::pastry::Id::build(::java::lang::String* hex)
{
    clinit();
    while (npc(hex)->length() < IdBitLength / int32_t(4)) 
                hex = ::java::lang::StringBuilder().append(hex)->append(u"0"_j)->toString();

    return build(npc(npc(hex)->toUpperCase())->toCharArray_(), 0, npc(hex)->length());
}

rice::pastry::Id* rice::pastry::Id::build(::char16_tArray* chars, int32_t offset, int32_t length)
{
    clinit();
    auto array = new ::int32_tArray(nlen);
    for (auto i = int32_t(0); i < nlen; i++) 
                for (auto j = int32_t(0); j < 8; j++) 
                        (*array)[nlen - int32_t(1) - i] = ((*array)[nlen - int32_t(1) - i] << int32_t(4)) | trans((*chars)[offset + int32_t(8) * i + j]);


    return build(array);
}

int8_t rice::pastry::Id::trans(char16_t c)
{
    clinit();
    if((u'0' <= c) && (u'9' >= c))
        return static_cast< int8_t >((c - u'0'));
    else
        return static_cast< int8_t >((c - u'A' + int32_t(10)));
}

rice::pastry::Id* rice::pastry::Id::build(::int8_tArray* material)
{
    clinit();
    return build(trans(material));
}

int32_tArray* rice::pastry::Id::trans(::int8_tArray* material)
{
    clinit();
    auto array = new ::int32_tArray(nlen);
    for (auto j = int32_t(0); (j < IdBitLength / int32_t(8)) && (j < npc(material)->length); j++) {
        auto k = (*material)[j] & int32_t(255);
        (*array)[j / int32_t(4)] |= k << ((j % int32_t(4)) * int32_t(8));
    }
    return array;
}

rice::pastry::Id* rice::pastry::Id::build()
{
    clinit();
    return build(new ::int32_tArray(nlen));
}

int32_tArray* rice::pastry::Id::trans(::java::lang::String* hex)
{
    clinit();
    auto ints = new ::int32_tArray(nlen);
    for (auto i = int32_t(0); i < nlen; i++) {
        auto s = npc(hex)->substring(i * int32_t(8), (i + int32_t(1)) * int32_t(8));
        (*ints)[nlen - int32_t(1) - i] = (new ::java::math::BigInteger(s, int32_t(16)))->intValue();
    }
    return ints;
}

rice::pastry::Id* rice::pastry::Id::resolve(::java::util::WeakHashMap* map, ::rice::pastry::Id* id)
{
    clinit();
    {
        synchronized synchronized_0(map);
        {
            auto ref = java_cast< ::java::lang::ref::WeakReference* >(java_cast< ::java::lang::Object* >(npc(map)->get(static_cast< ::java::lang::Object* >(id))));
            ::rice::pastry::Id* result = nullptr;
            if((ref != nullptr) && ((result = java_cast< ::rice::pastry::Id* >(java_cast< ::java::lang::Object* >(npc(ref)->get()))) != nullptr)) {
                return result;
            } else {
                npc(map)->put(static_cast< ::java::lang::Object* >(id), static_cast< ::java::lang::Object* >(new ::java::lang::ref::WeakReference(id)));
                return id;
            }
        }
    }
}

java::lang::Object* rice::pastry::Id::readResolve() /* throws(ObjectStreamException) */
{
    return resolve(ID_MAP_, this);
}

rice::pastry::Id* rice::pastry::Id::getCW()
{
    auto one = new Id_Distance(One_);
    return add(one);
}

rice::pastry::Id* rice::pastry::Id::getCCW()
{
    auto negone = new Id_Distance(NegOne_);
    return add(negone);
}

bool rice::pastry::Id::isBetween(::rice::pastry::Id* ccw, ::rice::pastry::Id* cw)
{
    if(npc(ccw)->equals(cw)) {
        return false;
    }
    if(npc(ccw)->clockwise(cw)) {
        return this->clockwise(cw) && !this->clockwise(ccw);
    } else {
        return !this->clockwise(ccw) || this->clockwise(cw);
    }
}

int32_t rice::pastry::Id::getDigit(int32_t i, int32_t b)
{
    auto bitIndex = b * i + (IdBitLength % b);
    auto index = bitIndex / int32_t(32);
    auto shift = bitIndex % int32_t(32);
    int64_t val = (*Id_)[index];
    if(shift + b > 32) {
        val = (val & int64_t(4294967295LL)) | ((static_cast< int64_t >((*Id_)[index + int32_t(1)])) << int32_t(32));
    }
    return (static_cast< int32_t >((val >> shift))) & ((int32_t(1) << b) - int32_t(1));
}

rice::pastry::Id* rice::pastry::Id::getDomainPrefix(int32_t row, int32_t column, int32_t suffixDigit, int32_t b)
{
    auto res = new ::rice::pastry::Id(Id_);
    npc(res)->setDigit(row, column, b);
    for (auto i = int32_t(0); i < row; i++) {
        npc(res)->setDigit(i, suffixDigit, b);
    }
    return build(npc(res)->Id_);
}

rice::pastry::Id* rice::pastry::Id::getAlternateId(int32_t num, int32_t b, int32_t i)
{
    if(num > (int32_t(1) << b) || i < 0 || i >= num) {
        return nullptr;
    }
    auto res = new ::rice::pastry::Id(Id_);
    auto digit = npc(res)->getDigit(numDigits(b) - int32_t(1), b) + ((int32_t(1) << b) / num) * i;
    npc(res)->setDigit(numDigits(b) - int32_t(1), digit, b);
    return build(npc(res)->Id_);
}

bool rice::pastry::Id::isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw)
{
    return isBetween(java_cast< ::rice::pastry::Id* >(ccw), java_cast< ::rice::pastry::Id* >(cw));
}

void rice::pastry::Id::setDigit(int32_t i, int32_t v, int32_t b)
{
    auto bitIndex = b * i + (IdBitLength % b);
    auto index = bitIndex / int32_t(32);
    auto shift = bitIndex % int32_t(32);
    auto mask = (int32_t(1) << b) - int32_t(1);
    if(shift + b > 32) {
        auto newd = (static_cast< int64_t >((v & mask))) << shift;
        auto vmask = ~((static_cast< int64_t >(mask)) << shift);
        int64_t val = (*Id_)[index];
        val = (val & int64_t(4294967295LL)) | ((static_cast< int64_t >((*Id_)[index + int32_t(1)])) << int32_t(32));
        val = (val & vmask) | newd;
        (*Id_)[index] = static_cast< int32_t >(val);
        (*Id_)[index + int32_t(1)] = static_cast< int32_t >((val >> int32_t(32)));
    } else {
        auto newd = (v & mask) << shift;
        auto vmask = ~(mask << shift);
        (*Id_)[index] = ((*Id_)[index] & vmask) | newd;
    }
}

void rice::pastry::Id::blit(::int8_tArray* target)
{
    blit(target, 0);
}

void rice::pastry::Id::blit(::int8_tArray* target, int32_t offset)
{
    for (auto j = int32_t(0); j < IdBitLength / int32_t(8); j++) {
        auto k = (*Id_)[j / int32_t(4)] >> ((j % int32_t(4)) * int32_t(8));
        (*target)[offset + j] = static_cast< int8_t >((k & int32_t(255)));
    }
}

int8_tArray* rice::pastry::Id::copy()
{
    auto target = new ::int8_tArray(IdBitLength / int32_t(8));
    blit(target);
    return target;
}

bool rice::pastry::Id::equals(::java::lang::Object* obj)
{
    if((obj == nullptr) || (!(dynamic_cast< ::rice::pastry::Id* >(obj) != nullptr)))
        return false;

    auto nid = java_cast< ::rice::pastry::Id* >(obj);
    for (auto i = int32_t(0); i < nlen; i++) {
        if((*Id_)[i] != (*npc(nid)->Id_)[i]) {
            return false;
        }
    }
    return true;
}

int32_t rice::pastry::Id::compareTo(::rice::p2p::commonapi::Id* obj)
{
    auto oth = java_cast< ::rice::pastry::Id* >(obj);
    for (auto i = nlen - int32_t(1); i >= 0; i--) {
        if((*Id_)[i] != (*npc(oth)->Id_)[i]) {
            auto t = (*Id_)[i] & int64_t(4294967295LL);
            auto o = (*npc(oth)->Id_)[i] & int64_t(4294967295LL);
            if(t < o) {
                return -int32_t(1);
            } else {
                return 1;
            }
        }
    }
    return 0;
}

int32_t rice::pastry::Id::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< ::rice::p2p::commonapi::Id* >(arg0));
}

int8_tArray* rice::pastry::Id::toByteArray_()
{
    return copy();
}

void rice::pastry::Id::toByteArray_(::int8_tArray* array, int32_t offset)
{
    blit(array, offset);
}

int32_t rice::pastry::Id::getByteArrayLength()
{
    return static_cast< int32_t >(IdBitLength) / int32_t(8);
}

int32_t rice::pastry::Id::hashCode()
{
    auto h = int32_t(0);
    for (auto i = int32_t(0); i < nlen; i++) {
        h ^= (*Id_)[i];
    }
    return h;
}

rice::pastry::Id* rice::pastry::Id::add(Id_Distance* offset)
{
    auto array = new ::int32_tArray(nlen);
    int64_t x;
    int64_t y;
    int64_t sum;
    auto carry = int32_t(0);
    for (auto i = int32_t(0); i < nlen; i++) {
        x = (*Id_)[i] & int64_t(4294967295LL);
        y = (*npc(offset)->difference)[i] & int64_t(4294967295LL);
        sum = x + y + carry;
        if(sum >= 4294967296LL) {
            carry = 1;
        } else {
            carry = 0;
        }
        (*array)[i] = static_cast< int32_t >(sum);
    }
    return build(array);
}

rice::pastry::Id_Distance* rice::pastry::Id::distance(::rice::pastry::Id* nid)
{
    auto dist = absDistance(nid);
    if(((*dist)[nlen - int32_t(1)] & int32_t(-0x7fffffff-1)) != 0) {
        invert(dist);
    }
    auto d = new Id_Distance(dist);
    return d;
}

rice::pastry::Id_Distance* rice::pastry::Id::distance(::rice::pastry::Id* nid, Id_Distance* d)
{
    auto dist = npc(d)->difference;
    absDistance(nid, dist);
    if(((*dist)[nlen - int32_t(1)] & int32_t(-0x7fffffff-1)) != 0) {
        invert(dist);
    }
    return d;
}

rice::pastry::Id_Distance* rice::pastry::Id::longDistance(::rice::pastry::Id* nid)
{
    auto dist = absDistance(nid);
    if(((*dist)[nlen - int32_t(1)] & int32_t(-0x7fffffff-1)) == 0) {
        invert(dist);
    }
    auto d = new Id_Distance(dist);
    return d;
}

bool rice::pastry::Id::equals(::rice::pastry::Id* nid)
{
    if(nid == nullptr) {
        return false;
    }
    for (auto i = int32_t(0); i < nlen; i++) {
        if((*Id_)[i] != (*npc(nid)->Id_)[i]) {
            return false;
        }
    }
    return true;
}

bool rice::pastry::Id::clockwise(::rice::pastry::Id* nid)
{
    auto diffMSB = (((*Id_)[nlen - int32_t(1)] & int32_t(-0x7fffffff-1)) != ((*npc(nid)->Id_)[nlen - int32_t(1)] & int32_t(-0x7fffffff-1)));
    int32_t x;
    int32_t y;
    int32_t i;
    if((x = ((*Id_)[nlen - int32_t(1)] & int32_t(2147483647))) != (y = ((*npc(nid)->Id_)[nlen - int32_t(1)] & int32_t(2147483647)))) {
        return ((y > x) ^ diffMSB);
    } else {
        for (i = nlen - int32_t(2); i >= 0; i--) {
            if((*Id_)[i] != (*npc(nid)->Id_)[i]) {
                break;
            }
        }
        if(i < 0) {
            return diffMSB;
        } else {
            int64_t xl;
            int64_t yl;
            xl = (*Id_)[i] & int64_t(4294967295LL);
            yl = (*npc(nid)->Id_)[i] & int64_t(4294967295LL);
            return ((yl > xl) ^ diffMSB);
        }
    }
}

bool rice::pastry::Id::checkBit(int32_t i)
{
    auto index = i / int32_t(32);
    auto shift = i % int32_t(32);
    auto val = (*Id_)[index];
    auto mask = (int32_t(1) << shift);
    if((val & mask) != 0) {
        return true;
    } else {
        return false;
    }
}

int32_t rice::pastry::Id::indexOfMSDB(::rice::pastry::Id* nid)
{
    for (auto i = nlen - int32_t(1); i >= 0; i--) {
        auto cmp = (*Id_)[i] ^ (*npc(nid)->Id_)[i];
        if(cmp != 0) {
            int32_t tmp;
            auto j = int32_t(0);
            if((tmp = cmp & int32_t(-65536)) != 0) {
                cmp = tmp;
                j += 16;
            }
            if((tmp = cmp & int32_t(-16711936)) != 0) {
                cmp = tmp;
                j += 8;
            }
            if((tmp = cmp & int32_t(-252645136)) != 0) {
                cmp = tmp;
                j += 4;
            }
            if((tmp = cmp & int32_t(-858993460)) != 0) {
                cmp = tmp;
                j += 2;
            }
            if((tmp = cmp & int32_t(-1431655766)) != 0) {
                cmp = tmp;
                j += 1;
            }
            return int32_t(32) * i + j;
        }
    }
    return -int32_t(1);
}

int32_t rice::pastry::Id::indexOfMSDD(::rice::pastry::Id* nid, int32_t base)
{
    auto ind = indexOfMSDB(nid);
    ind -= IdBitLength % base;
    if(ind < 0) {
        return ind;
    }
    return ind / base;
}

java::lang::String* rice::pastry::Id::toString()
{
    auto buffer = new ::java::lang::StringBuffer();
    npc(buffer)->append(u"<0x"_j);
    auto n = IdBitLength / int32_t(4);
    for (auto i = n - int32_t(1); i >= n - int32_t(6); i--) 
                npc(buffer)->append((*tran_)[getDigit(i, 4)]);

    npc(buffer)->append(u"..>"_j);
    return npc(buffer)->toString();
}

java::lang::String* rice::pastry::Id::toStringBare()
{
    auto buffer = new ::java::lang::StringBuffer();
    auto n = IdBitLength / int32_t(4);
    for (auto i = n - int32_t(1); i >= n - int32_t(6); i--) 
                npc(buffer)->append((*tran_)[getDigit(i, 4)]);

    return npc(buffer)->toString();
}

java::lang::String* rice::pastry::Id::toStringFull()
{
    auto buffer = new ::java::lang::StringBuffer();
    auto n = IdBitLength / int32_t(4);
    for (auto i = n - int32_t(1); i >= 0; i--) 
                npc(buffer)->append((*tran_)[getDigit(i, 4)]);

    return npc(buffer)->toString();
}

bool rice::pastry::Id::clockwise(::rice::p2p::commonapi::Id* nid)
{
    return clockwise(java_cast< ::rice::pastry::Id* >(nid));
}

rice::p2p::commonapi::Id* rice::pastry::Id::addToId(::rice::p2p::commonapi::Id_Distance* offset)
{
    return add(java_cast< Id_Distance* >(offset));
}

rice::p2p::commonapi::Id_Distance* rice::pastry::Id::distanceFromId(::rice::p2p::commonapi::Id* nid)
{
    return distance(java_cast< ::rice::pastry::Id* >(nid));
}

rice::p2p::commonapi::Id_Distance* rice::pastry::Id::longDistanceFromId(::rice::p2p::commonapi::Id* nid)
{
    return longDistance(java_cast< ::rice::pastry::Id* >(nid));
}

int32_tArray* rice::pastry::Id::absDistance(::rice::pastry::Id* nid)
{
    return absDistance(nid, new ::int32_tArray(nlen));
}

int32_tArray* rice::pastry::Id::absDistance(::rice::pastry::Id* nid, ::int32_tArray* dist)
{
    int64_t x;
    int64_t y;
    int64_t diff;
    auto carry = int32_t(0);
    if(compareTo(static_cast< ::rice::p2p::commonapi::Id* >(nid)) > 0) {
        for (auto i = int32_t(0); i < nlen; i++) {
            x = (*Id_)[i] & int64_t(4294967295LL);
            y = (*npc(nid)->Id_)[i] & int64_t(4294967295LL);
            diff = x - y - carry;
            if(diff < 0) {
                carry = 1;
            } else {
                carry = 0;
            }
            (*dist)[i] = static_cast< int32_t >(diff);
        }
    } else {
        for (auto i = int32_t(0); i < nlen; i++) {
            x = (*Id_)[i] & int64_t(4294967295LL);
            y = (*npc(nid)->Id_)[i] & int64_t(4294967295LL);
            diff = y - x - carry;
            if(diff < 0) {
                carry = 1;
            } else {
                carry = 0;
            }
            (*dist)[i] = static_cast< int32_t >(diff);
        }
    }
    return dist;
}

void rice::pastry::Id::invert(::int32_tArray* dist)
{
    auto carry = int32_t(0);
    int64_t diff;
    for (auto i = int32_t(0); i < nlen; i++) {
        diff = (*dist)[i] & int64_t(4294967295LL);
        diff = int64_t(0LL) - diff - carry;
        if(diff < 0) {
            carry = 1;
        }
        (*dist)[i] = static_cast< int32_t >(diff);
    }
}

int16_t rice::pastry::Id::getType()
{
    return TYPE;
}

void rice::pastry::Id::main(::java::lang::StringArray* args)
{
    clinit();
    npc(::java::lang::System::out())->println(npc((new ::rice::pastry::Id(Half_))->getCCW())->toStringFull());
    npc(::java::lang::System::out())->println(npc((new ::rice::pastry::Id(Half_))->getCW())->toStringFull());
    npc(::java::lang::System::out())->println(npc((new ::rice::pastry::Id(Null_))->getCCW())->toStringFull());
    npc(::java::lang::System::out())->println(npc((new ::rice::pastry::Id(Null_))->getCW())->toStringFull());
    npc(::java::lang::System::out())->println(npc((new ::rice::pastry::Id(NegOne_))->getCCW())->toStringFull());
    npc(::java::lang::System::out())->println(npc((new ::rice::pastry::Id(NegOne_))->getCW())->toStringFull());
    npc(::java::lang::System::out())->println(npc((new ::rice::pastry::Id(One_))->getCCW())->toStringFull());
    npc(::java::lang::System::out())->println(npc((new ::rice::pastry::Id(One_))->getCW())->toStringFull());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::Id::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.Id", 14);
    return c;
}

void rice::pastry::Id::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        ID_MAP_ = new ::java::util::WeakHashMap();
        tran_ = (new ::java::lang::StringArray({
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
        Null_ = (new ::int32_tArray({
            int32_t(0)
            , int32_t(0)
            , int32_t(0)
            , int32_t(0)
            , int32_t(0)
        }));
        One_ = (new ::int32_tArray({
            int32_t(1)
            , int32_t(0)
            , int32_t(0)
            , int32_t(0)
            , int32_t(0)
        }));
        NegOne_ = (new ::int32_tArray({
            -int32_t(1)
            , -int32_t(1)
            , -int32_t(1)
            , -int32_t(1)
            , -int32_t(1)
        }));
        Half_ = (new ::int32_tArray({
            int32_t(0)
            , int32_t(0)
            , int32_t(0)
            , int32_t(0)
            , int32_t(-0x7fffffff-1)
        }));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::Id::getClass0()
{
    return class_();
}

