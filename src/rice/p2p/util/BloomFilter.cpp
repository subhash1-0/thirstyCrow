// Generated from /pastry-2.1/src/rice/p2p/util/BloomFilter.java
#include <rice/p2p/util/BloomFilter.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/BitSet.hpp>
#include <java/util/Random.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/BloomFilter_main_1.hpp>
#include <rice/p2p/util/BloomFilter_main_2.hpp>
#include <rice/p2p/util/MathUtils.hpp>
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
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::BloomFilter::BloomFilter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::BloomFilter::BloomFilter(int32_t num, int32_t length) 
    : BloomFilter(*static_cast< ::default_init_tag* >(0))
{
    ctor(num,length);
}

rice::p2p::util::BloomFilter::BloomFilter(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : BloomFilter(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf);
}

int32_t& rice::p2p::util::BloomFilter::PARAMETER_LENGTH()
{
    clinit();
    return PARAMETER_LENGTH_;
}
int32_t rice::p2p::util::BloomFilter::PARAMETER_LENGTH_;

void rice::p2p::util::BloomFilter::ctor(int32_t num, int32_t length)
{
    super::ctor();
    ::rice::environment::random::RandomSource* rand = new ::rice::environment::random::simple::SimpleRandomSource(nullptr);
    this->length = length;
    this->set = new ::java::util::BitSet(length);
    this->parameters = new ::int32_tArray(num);
    for (auto i = int32_t(0); i < npc(parameters)->length; i++) 
                (*this->parameters)[i] = MathUtils::randomInt(rand);

}

void rice::p2p::util::BloomFilter::add(::int8_tArray* array)
{
    for (auto i = int32_t(0); i < npc(parameters)->length; i++) 
                npc(set)->set(hash(array, i));

}

bool rice::p2p::util::BloomFilter::check(::int8_tArray* array)
{
    for (auto i = int32_t(0); i < npc(parameters)->length; i++) 
                if(!npc(set)->get(hash(array, i)))
            return false;


    return true;
}

int32_t rice::p2p::util::BloomFilter::hash(::int8_tArray* array, int32_t i)
{
    if(length <= 0)
        return 0;

    return MathUtils::mod(doHash(array, (*parameters)[i]), length);
}

int32_t rice::p2p::util::BloomFilter::doHash(::int8_tArray* array, int32_t seed)
{
    auto tmp = new ::int8_tArray(npc(array)->length + int32_t(4));
    MathUtils::intToByteArray_(seed, tmp, 0);
    ::java::lang::System::arraycopy(array, 0, tmp, 4, npc(array)->length);
    return MathUtils::simpleHash(tmp);
}

java::lang::String* rice::p2p::util::BloomFilter::getBitSet()
{
    auto buffer = new ::java::lang::StringBuffer();
    npc(buffer)->append(u"[BloomFilter "_j);
    for (auto i = int32_t(0); i < length; i++) 
                if(npc(set)->get(i))
            npc(buffer)->append(u"1"_j);
        else
            npc(buffer)->append(u"0"_j);

    npc(buffer)->append(u"]"_j);
    return npc(buffer)->toString();
}

void rice::p2p::util::BloomFilter::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeInt(length);
    npc(buf)->writeInt(npc(parameters)->length);
    for (auto i = int32_t(0); i < npc(parameters)->length; i++) {
        npc(buf)->writeInt((*parameters)[i]);
    }
    auto numBits = npc(set)->length();
    npc(buf)->writeInt(numBits);
    int8_t curByte = int32_t(0);
    for (auto i = int32_t(0); i < numBits; i++) {
        if(i > 0 && i % int32_t(8) == 0) {
            npc(buf)->writeByte(curByte);
            curByte = 0;
        }
        if(npc(set)->get(i))
            curByte |= (int32_t(1) << i % int32_t(8));

    }
    npc(buf)->writeByte(curByte);
}

void rice::p2p::util::BloomFilter::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor();
    length = npc(buf)->readInt();
    parameters = new ::int32_tArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(parameters)->length; i++) {
        (*parameters)[i] = npc(buf)->readInt();
    }
    auto numBits = npc(buf)->readInt();
    set = new ::java::util::BitSet(numBits);
    auto curByte = npc(buf)->readByte();
    for (auto i = int32_t(0); i < numBits; i++) {
        if(((static_cast<int8_t>(static_cast<uint32_t>(curByte) >> i % int32_t(8))) & int32_t(1)) == 1) {
            npc(set)->set(i);
        }
        if(i < numBits - int32_t(1) && i % int32_t(8) == 7) {
            curByte = npc(buf)->readByte();
        }
    }
}

void rice::p2p::util::BloomFilter::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto rng = new ::java::util::Random();
    for (auto i = int32_t(0); i < 135; i++) {
        auto a = new BloomFilter(int32_t(1), i);
        for (auto j = int32_t(0); j < i / int32_t(2); j++) {
            auto flip = npc(rng)->nextInt(i);
            npc(npc(a)->set)->flip(flip);
        }
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a:"_j)->append(static_cast< ::java::lang::Object* >(npc(a)->set))->toString());
        auto const baos = new ::java::io::ByteArrayOutputStream();
        ::rice::p2p::commonapi::rawserialization::OutputBuffer* obuf = new BloomFilter_main_1(baos);
        npc(a)->serialize(obuf);
        auto const bais = new ::java::io::ByteArrayInputStream(npc(baos)->toByteArray_());
        ::rice::p2p::commonapi::rawserialization::InputBuffer* buf = new BloomFilter_main_2(bais);
        auto b = new BloomFilter(buf);
        if(!npc(npc(b)->set)->equals(static_cast< ::java::lang::Object* >(npc(a)->set))) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(i)->append(u"a:"_j)
                ->append(static_cast< ::java::lang::Object* >(npc(a)->set))->toString());
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(i)->append(u"b:"_j)
                ->append(static_cast< ::java::lang::Object* >(npc(b)->set))->toString());
            npc(::java::lang::System::out())->println();
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::BloomFilter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.BloomFilter", 25);
    return c;
}

void rice::p2p::util::BloomFilter::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        PARAMETER_LENGTH_ = int32_t(4);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::util::BloomFilter::getClass0()
{
    return class_();
}

