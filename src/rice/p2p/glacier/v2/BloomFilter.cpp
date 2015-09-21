// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/BloomFilter.java
#include <rice/p2p/glacier/v2/BloomFilter.hpp>

#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Arrays.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::BloomFilter::BloomFilter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::BloomFilter::BloomFilter(int32_t length, ::int32_tArray* hashParams) 
    : BloomFilter(*static_cast< ::default_init_tag* >(0))
{
    ctor(length,hashParams);
}

rice::p2p::glacier::v2::BloomFilter::BloomFilter(int32_t length, int32_t numHashes, ::rice::environment::random::RandomSource* rand) 
    : BloomFilter(*static_cast< ::default_init_tag* >(0))
{
    ctor(length,numHashes,rand);
}

rice::p2p::glacier::v2::BloomFilter::BloomFilter(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : BloomFilter(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf);
}

constexpr int64_t rice::p2p::glacier::v2::BloomFilter::serialVersionUID;

void rice::p2p::glacier::v2::BloomFilter::ctor(int32_t length, ::int32_tArray* hashParams)
{
    super::ctor();
    bitfield = new ::int8_tArray((length + int32_t(7)) / int32_t(8));
    ::java::util::Arrays::fill(bitfield, static_cast< int8_t >(int32_t(0)));
    this->hashParams = hashParams;
}

void rice::p2p::glacier::v2::BloomFilter::ctor(int32_t length, int32_t numHashes, ::rice::environment::random::RandomSource* rand)
{
    super::ctor();
    bitfield = new ::int8_tArray((length + int32_t(7)) / int32_t(8));
    ::java::util::Arrays::fill(bitfield, static_cast< int8_t >(int32_t(0)));
    auto numPrimeCandidates = numHashes * int32_t(100);
    if(numPrimeCandidates >= (length - int32_t(5)))
        numPrimeCandidates = length - int32_t(5);

    auto maxFactor = static_cast< int32_t >((::java::lang::Math::sqrt(length)));
    auto offset = length - numPrimeCandidates + int32_t(1);
    auto isPrimeH = new ::boolArray(numPrimeCandidates);
    auto isPrimeL = new ::boolArray(maxFactor + int32_t(1));
    ::java::util::Arrays::fill(isPrimeH, true);
    ::java::util::Arrays::fill(isPrimeL, true);
    for (auto i = int32_t(2); i <= maxFactor; i++) {
        if((*isPrimeL)[i]) {
            for (auto j = int32_t(0); j <= static_cast< int32_t >((maxFactor / i)); j++) 
                                (*isPrimeL)[j * i] = false;

            for (auto j = static_cast< int32_t >(((offset + i - int32_t(1)) / i)); j <= static_cast< int32_t >((length / i)); j++) 
                                (*isPrimeH)[j * i - offset] = false;

        }
    }
    hashParams = new ::int32_tArray(numHashes);
    for (auto i = int32_t(0); i < numHashes; i++) {
        auto index = npc(rand)->nextInt(numPrimeCandidates);
        while (!(*isPrimeH)[index]) 
                        index = (index + int32_t(1)) % numPrimeCandidates;

        (*isPrimeH)[index] = false;
        (*hashParams)[i] = offset + index;
    }
}

int32_tArray* rice::p2p::glacier::v2::BloomFilter::getHashes(::int8_tArray* data)
{
    int64_t cache = int32_t(0);
    auto ctr = int32_t(0);
    auto hash = new ::int32_tArray(npc(hashParams)->length);
    ::java::util::Arrays::fill(hash, int32_t(0));
    for (auto i = int32_t(0); i < npc(data)->length; i++) {
        cache = (cache << int32_t(8)) + (*data)[i] + (((*data)[i] < 0) ? int32_t(256) : int32_t(0));
        if(((++ctr) == 7) || (i == (npc(data)->length - int32_t(1)))) {
            for (auto j = int32_t(0); j < npc(hashParams)->length; j++) 
                                (*hash)[j] += cache % (*hashParams)[j];

            ctr = 0;
            cache = 0;
        }
    }
    for (auto j = int32_t(0); j < npc(hashParams)->length; j++) 
                (*hash)[j] = (*hash)[j] % (*hashParams)[j];

    return hash;
}

void rice::p2p::glacier::v2::BloomFilter::dump(::rice::environment::logging::Logger* logger)
{
    auto s = u""_j;
    for (auto i = int32_t(0); i < npc(bitfield)->length * int32_t(8); i++) 
                if(((*bitfield)[i / int32_t(8)] & (int32_t(1) << (i & int32_t(7)))) == 0)
            s = ::java::lang::StringBuilder(s).append(u"0"_j)->toString();
        else
            s = ::java::lang::StringBuilder(s).append(u"1"_j)->toString();

    s = ::java::lang::StringBuilder(s).append(u"\n"_j)->toString();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(s);

}

void rice::p2p::glacier::v2::BloomFilter::add(::int8_tArray* data)
{
    auto hash = getHashes(data);
    for (auto i = int32_t(0); i < npc(hashParams)->length; i++) 
                (*bitfield)[(*hash)[i] / int32_t(8)] |= (int32_t(1) << ((*hash)[i] & int32_t(7)));

}

bool rice::p2p::glacier::v2::BloomFilter::contains(::int8_tArray* data)
{
    auto hash = getHashes(data);
    for (auto i = int32_t(0); i < npc(hashParams)->length; i++) 
                if(((*bitfield)[(*hash)[i] / int32_t(8)] & (int32_t(1) << ((*hash)[i] & int32_t(7)))) == 0)
            return false;


    return true;
}

java::lang::String* rice::p2p::glacier::v2::BloomFilter::toString()
{
    auto result = ::java::lang::StringBuilder().append(u"[BV "_j)->append((npc(bitfield)->length * int32_t(8)))
        ->append(u"bit = { "_j)->toString();
    for (auto i = int32_t(0); i < npc(hashParams)->length; i++) 
                result = ::java::lang::StringBuilder().append(result)->append(((i == 0) ? u""_j : u", "_j))
            ->append((*hashParams)[i])->toString();

    result = ::java::lang::StringBuilder().append(result)->append(u" }]"_j)->toString();
    return result;
}

void rice::p2p::glacier::v2::BloomFilter::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor();
    hashParams = new ::int32_tArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(hashParams)->length; i++) {
        (*hashParams)[i] = npc(buf)->readInt();
    }
    bitfield = new ::int8_tArray(npc(buf)->readInt());
    npc(buf)->read(bitfield);
}

void rice::p2p::glacier::v2::BloomFilter::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeInt(npc(hashParams)->length);
    for (auto i = int32_t(0); i < npc(hashParams)->length; i++) {
        npc(buf)->writeInt((*hashParams)[i]);
    }
    npc(buf)->writeInt(npc(bitfield)->length);
    npc(buf)->write(bitfield, 0, npc(bitfield)->length);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::BloomFilter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.BloomFilter", 31);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::BloomFilter::getClass0()
{
    return class_();
}

