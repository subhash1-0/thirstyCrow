// Generated from /pastry-2.1/src/rice/p2p/glacier/ErasureCodec.java
#include <rice/p2p/glacier/ErasureCodec.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Arrays.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/rawserialization/JavaSerializedPastContent.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;
        } // glacier
    } // p2p
} // rice

namespace 
{
typedef ::SubArray< ::int64_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int64_tArrayArray;
} // 

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

rice::p2p::glacier::ErasureCodec::ErasureCodec(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::ErasureCodec::ErasureCodec(int32_t _numFragments, int32_t _numSurvivors, ::rice::environment::Environment* env) 
    : ErasureCodec(*static_cast< ::default_init_tag* >(0))
{
    ctor(_numFragments,_numSurvivors,env);
}

constexpr int32_t rice::p2p::glacier::ErasureCodec::Lfield;

constexpr int32_t rice::p2p::glacier::ErasureCodec::MultField;

int32_tArray*& rice::p2p::glacier::ErasureCodec::ExpToFieldElt()
{
    clinit();
    return ExpToFieldElt_;
}
int32_tArray* rice::p2p::glacier::ErasureCodec::ExpToFieldElt_;

int32_tArray*& rice::p2p::glacier::ErasureCodec::FieldEltToExp()
{
    clinit();
    return FieldEltToExp_;
}
int32_tArray* rice::p2p::glacier::ErasureCodec::FieldEltToExp_;

bool& rice::p2p::glacier::ErasureCodec::isEltInitialized()
{
    clinit();
    return isEltInitialized_;
}
bool rice::p2p::glacier::ErasureCodec::isEltInitialized_;

void rice::p2p::glacier::ErasureCodec::ctor(int32_t _numFragments, int32_t _numSurvivors, ::rice::environment::Environment* env)
{
    super::ctor();
    environment = env;
    logger = npc(npc(environment)->getLogManager())->getLogger(getClass(), nullptr);
    numFragments = _numFragments;
    numSurvivors = _numSurvivors;
    if(!isEltInitialized_)
        initElt();

}

void rice::p2p::glacier::ErasureCodec::dump(::int8_tArray* data)
{
    auto hex = u"0123456789ABCDEF"_j;
    auto s = u""_j;
    for (auto i = int32_t(0); i < npc(data)->length; i++) {
        int32_t d = (*data)[i];
        if(d < 0)
            d += 256;

        auto hi = (d >> int32_t(4));
        auto lo = (d & int32_t(15));
        s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(npc(hex)->charAt(hi))->append(u""_j)
            ->append(npc(hex)->charAt(lo))->toString())->toString();
        if(((i % int32_t(16)) == 15) || (i == (npc(data)->length - int32_t(1))))
            s = ::java::lang::StringBuilder(s).append(u"\n"_j)->toString();
        else
            s = ::java::lang::StringBuilder(s).append(u" "_j)->toString();
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(s);

}

rice::p2p::glacier::FragmentArray* rice::p2p::glacier::ErasureCodec::encodeObject(::rice::p2p::past::PastContent* obj, ::boolArray* generateFragment)
{
    return encodeObject(dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(obj) != nullptr ? java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(obj) : static_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(obj)), generateFragment);
}

rice::p2p::glacier::FragmentArray* rice::p2p::glacier::ErasureCodec::encodeObject(::rice::p2p::past::rawserialization::RawPastContent* obj, ::boolArray* generateFragment)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Serialize object: "_j)->append(static_cast< ::java::lang::Object* >(obj))->toString());

    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(sob)->writeShort(npc(obj)->getType());
        npc(obj)->serialize(sob);
        return encode(npc(sob)->getBytes(), npc(sob)->getWritten(), generateFragment);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot serialize object: "_j)->append(static_cast< ::java::lang::Object* >(ioe))->toString());

        return nullptr;
    }
}

void rice::p2p::glacier::ErasureCodec::encodeChunk(::int32_tArray* buffer)
{
    for (auto row = int32_t(0); row < (numFragments - numSurvivors); row++) {
        for (auto col = int32_t(0); col < numSurvivors; col++) {
            auto exponent = (MultField - (*FieldEltToExp_)[(row ^ col) ^ (int32_t(1) << (Lfield - int32_t(1)))]) % MultField;
            for (auto row_bit = int32_t(0); row_bit < Lfield; row_bit++) 
                                for (auto col_bit = int32_t(0); col_bit < Lfield; col_bit++) 
                                        if(((*ExpToFieldElt_)[exponent + row_bit] & (int32_t(1) << col_bit)) != 0)
                        (*buffer)[numSurvivors * Lfield + row * Lfield + row_bit] ^= (*buffer)[col_bit + col * Lfield];



        }
    }
}

rice::p2p::glacier::FragmentArray* rice::p2p::glacier::ErasureCodec::encode(::int8_tArray* bytes, int32_t length, ::boolArray* generateFragment)
{
    auto wantFragments = int32_t(0);
    for (auto i = int32_t(0); i < npc(generateFragment)->length; i++) 
                if((*generateFragment)[i])
            wantFragments++;


    auto numWords = (length + int32_t(3)) / int32_t(4);
    auto wordsPerGroup = (numSurvivors * Lfield);
    auto numGroups = (numWords + (wordsPerGroup - int32_t(1))) / wordsPerGroup;
    auto wordsPerFragment = numGroups * Lfield;
    auto buffer = new ::int32_tArray(numFragments * Lfield);
    auto frag = new FragmentArray(numFragments);
    for (auto i = int32_t(0); i < numFragments; i++) {
        if((*generateFragment)[i])
            frag->set(i, new Fragment(wordsPerFragment * int32_t(4)));
        else
            frag->set(i, nullptr);
    }
    for (auto g = int32_t(0); g < numGroups; g++) {
        auto offset = g * wordsPerGroup * int32_t(4);
        auto wordsHere = ::java::lang::Math::min((length - offset + int32_t(3)) / int32_t(4), wordsPerGroup);
        ::java::util::Arrays::fill(buffer, int32_t(0));
        for (auto i = int32_t(0); i < wordsHere; i++) {
            auto b0 = (offset + int32_t(4) * i + int32_t(0) < length) ? (*bytes)[offset + int32_t(4) * i + int32_t(0)] : static_cast< int8_t >(int32_t(0));
            auto b1 = (offset + int32_t(4) * i + int32_t(1) < length) ? (*bytes)[offset + int32_t(4) * i + int32_t(1)] : static_cast< int8_t >(int32_t(0));
            auto b2 = (offset + int32_t(4) * i + int32_t(2) < length) ? (*bytes)[offset + int32_t(4) * i + int32_t(2)] : static_cast< int8_t >(int32_t(0));
            auto b3 = (offset + int32_t(4) * i + int32_t(3) < length) ? (*bytes)[offset + int32_t(4) * i + int32_t(3)] : static_cast< int8_t >(int32_t(0));
            (*buffer)[i] = (b0 << int32_t(24)) | ((b1 << int32_t(16)) & int32_t(16711680)) | ((b2 << int32_t(8)) & int32_t(65280))| (b3 & int32_t(255));
        }
        encodeChunk(buffer);
        for (auto i = int32_t(0); i < numFragments; i++) {
            if((*generateFragment)[i]) {
                for (auto j = int32_t(0); j < Lfield; j++) {
                    (*npc((*frag)[i])->payload)[int32_t(4) * (g * Lfield + j) + int32_t(0)] = static_cast< int8_t >((((*buffer)[i * Lfield + j]) & int32_t(255)));
                    (*npc((*frag)[i])->payload)[int32_t(4) * (g * Lfield + j) + int32_t(1)] = static_cast< int8_t >((((*buffer)[i * Lfield + j] >> int32_t(8)) & int32_t(255)));
                    (*npc((*frag)[i])->payload)[int32_t(4) * (g * Lfield + j) + int32_t(2)] = static_cast< int8_t >((((*buffer)[i * Lfield + j] >> int32_t(16)) & int32_t(255)));
                    (*npc((*frag)[i])->payload)[int32_t(4) * (g * Lfield + j) + int32_t(3)] = static_cast< int8_t >((((*buffer)[i * Lfield + j] >> int32_t(24)) & int32_t(255)));
                }
            }
        }
    }
    return frag;
}

void rice::p2p::glacier::ErasureCodec::decodeChunk(::int32_tArray* buffer, int32_t nExtra, ::int32_tArray* RowInd, ::boolArray* haveFragment, ::int64_tArrayArray* InvMat, ::int32_tArray* ColInd)
{
    auto M = new ::int32_tArray((numFragments - numSurvivors) * Lfield);
    for (auto i = int32_t(0); i < nExtra; i++) 
                for (auto j = int32_t(0); j < Lfield; j++) 
                        (*M)[i * Lfield + j] = (*buffer)[((*RowInd)[i] + numSurvivors) * Lfield + j];


    for (auto row = int32_t(0); row < nExtra; row++) {
        for (auto col = int32_t(0); col < numSurvivors; col++) {
            if((*haveFragment)[col]) {
                auto exponent = (MultField - (*FieldEltToExp_)[(*RowInd)[row] ^ col ^ (int32_t(1) << (Lfield - int32_t(1)))]) % MultField;
                for (auto row_bit = int32_t(0); row_bit < Lfield; row_bit++) 
                                        for (auto col_bit = int32_t(0); col_bit < Lfield; col_bit++) 
                                                if(((*ExpToFieldElt_)[exponent + row_bit] & (int32_t(1) << col_bit)) != 0)
                            (*M)[row_bit + row * Lfield] ^= (*buffer)[col_bit + col * Lfield];



            }
        }
    }
    for (auto row = int32_t(0); row < nExtra; row++) {
        for (auto col = int32_t(0); col < nExtra; col++) {
            auto exponent = static_cast< int32_t >((*(*InvMat)[row])[col]);
            for (auto row_bit = int32_t(0); row_bit < Lfield; row_bit++) 
                                for (auto col_bit = int32_t(0); col_bit < Lfield; col_bit++) 
                                        if(((*ExpToFieldElt_)[exponent + row_bit] & (int32_t(1) << col_bit)) != 0)
                        (*buffer)[row_bit + (*ColInd)[row] * Lfield] ^= (*M)[col_bit + col * Lfield];



        }
    }
}

rice::p2p::past::PastContent* rice::p2p::glacier::ErasureCodec::decode(FragmentArray* frag, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd)
{
    Fragment* firstFrag = nullptr;
    for (auto i = int32_t(0); i < npc(frag)->length; i++) 
                if((*frag)[i] != nullptr)
            firstFrag = (*frag)[i];


    if(npc(frag)->length != numFragments)
        return nullptr;

    auto firstFragment = -int32_t(1);
    for (auto i = int32_t(0); (i < numFragments) && (firstFragment == -int32_t(1)); i++) 
                if((*frag)[i] != nullptr)
            firstFragment = i;


    auto wordsPerFragment = (npc(npc((*frag)[firstFragment])->payload)->length + int32_t(3)) / int32_t(4);
    auto numGroups = wordsPerFragment / Lfield;
    auto haveFragment = new ::boolArray(numFragments);
    ::java::util::Arrays::fill(haveFragment, false);
    for (auto i = int32_t(0); i < numFragments; i++) 
                if((*frag)[i] != nullptr)
            (*haveFragment)[i] = true;


    auto ColInd = new ::int32_tArray(numSurvivors);
    auto RowInd = new ::int32_tArray(numFragments - numSurvivors);
    auto nMissing = int32_t(0);
    auto nExtra = int32_t(0);
    for (auto i = int32_t(0); i < numSurvivors; i++) 
                if(!(*haveFragment)[i])
            (*ColInd)[nMissing++] = i;


    for (auto i = int32_t(0); i < (numFragments - numSurvivors); i++) 
                if((*haveFragment)[numSurvivors + i])
            (*RowInd)[nExtra++] = i;


    if(nMissing > nExtra)
        return nullptr;

    if(nMissing < nExtra)
        nExtra = nMissing;

    ::int32_tArray* C;
    ::int32_tArray* D;
    ::int32_tArray* E;
    ::int32_tArray* F;
    C = new ::int32_tArray(numFragments - numSurvivors);
    ::java::util::Arrays::fill(C, int32_t(0));
    D = new ::int32_tArray(numFragments - numSurvivors);
    ::java::util::Arrays::fill(D, int32_t(0));
    E = new ::int32_tArray(numFragments - numSurvivors);
    ::java::util::Arrays::fill(E, int32_t(0));
    F = new ::int32_tArray(numFragments - numSurvivors);
    ::java::util::Arrays::fill(F, int32_t(0));
    for (auto row = int32_t(0); row < nExtra; row++) {
        for (auto col = int32_t(0); col < nExtra; col++) {
            if(col != row) {
                (*C)[row] += (*FieldEltToExp_)[(*RowInd)[row] ^ (*RowInd)[col]];
                (*D)[row] += (*FieldEltToExp_)[(*ColInd)[row] ^ (*ColInd)[col]];
            }
            (*E)[row] += (*FieldEltToExp_)[(*RowInd)[row] ^ (*ColInd)[col] ^ (int32_t(1) << (Lfield - int32_t(1)))];
            (*F)[col] += (*FieldEltToExp_)[(*RowInd)[row] ^ (*ColInd)[col] ^ (int32_t(1) << (Lfield - int32_t(1)))];
        }
    }
    auto InvMat = new ::int64_tArrayArray(nExtra);
    for (auto row = int32_t(0); row < nExtra; row++) {
        for (auto col = int32_t(0); col < nExtra; col++) {
            (*(*InvMat)[row])[col] = (*E)[col] + (*F)[row] - (*C)[col] - (*D)[row] - (*FieldEltToExp_)[(*RowInd)[col] ^ (*ColInd)[row] ^ (int32_t(1) << (Lfield - int32_t(1)))];
            if((*(*InvMat)[row])[col] >= 0) {
                (*(*InvMat)[row])[col] = (*(*InvMat)[row])[col] % MultField;
            } else {
                (*(*InvMat)[row])[col] = (MultField - (-(*(*InvMat)[row])[col] % MultField)) % MultField;
            }
        }
    }
    auto bytes = new ::int8_tArray(numSurvivors * wordsPerFragment * int32_t(4));
    auto buffer = new ::int32_tArray(numFragments * Lfield);
    for (auto g = int32_t(0); g < numGroups; g++) {
        ::java::util::Arrays::fill(buffer, int32_t(0));
        for (auto i = int32_t(0); i < numFragments; i++) {
            if((*haveFragment)[i]) {
                for (auto j = int32_t(0); j < Lfield; j++) {
                    (*buffer)[i * Lfield + j] = (((*npc((*frag)[i])->payload)[int32_t(4) * (g * Lfield + j) + int32_t(0)]) & int32_t(255)) + (((*npc((*frag)[i])->payload)[int32_t(4) * (g * Lfield + j) + int32_t(1)] << int32_t(8)) & int32_t(65280)) + (((*npc((*frag)[i])->payload)[int32_t(4) * (g * Lfield + j) + int32_t(2)] << int32_t(16)) & int32_t(16711680))+ ((*npc((*frag)[i])->payload)[int32_t(4) * (g * Lfield + j) + int32_t(3)] << int32_t(24));
                }
            }
        }
        decodeChunk(buffer, nExtra, RowInd, haveFragment, InvMat, ColInd);
        for (auto i = int32_t(0); i < (numSurvivors * Lfield); i++) {
            (*bytes)[int32_t(4) * (g * (numSurvivors * Lfield) + i) + int32_t(0)] = static_cast< int8_t >(((*buffer)[i] >> int32_t(24)));
            (*bytes)[int32_t(4) * (g * (numSurvivors * Lfield) + i) + int32_t(1)] = static_cast< int8_t >((((*buffer)[i] >> int32_t(16)) & int32_t(255)));
            (*bytes)[int32_t(4) * (g * (numSurvivors * Lfield) + i) + int32_t(2)] = static_cast< int8_t >((((*buffer)[i] >> int32_t(8)) & int32_t(255)));
            (*bytes)[int32_t(4) * (g * (numSurvivors * Lfield) + i) + int32_t(3)] = static_cast< int8_t >((((*buffer)[i]) & int32_t(255)));
        }
    }
    try {
        return deserialize(bytes, endpoint, pcd);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u""_j, ioe);

    } catch (::java::lang::ClassNotFoundException* cnfe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u""_j, cnfe);

    } catch (::java::lang::IllegalStateException* ise) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u""_j, ise);

    }
    return nullptr;
}

rice::p2p::past::PastContent* rice::p2p::glacier::ErasureCodec::deserialize(::int8_tArray* bytes, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException, ClassNotFoundException) */
{
    auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(bytes);
    auto type = npc(sib)->readShort();
    return npc(pcd)->deserializePastContent(sib, endpoint, type);
}

void rice::p2p::glacier::ErasureCodec::initElt()
{
    auto const polymask = (new ::int32_tArray({
        int32_t(0)
        , int32_t(3)
        , int32_t(7)
        , int32_t(11)
        , int32_t(19)
        , int32_t(37)
        , int32_t(67)
        , int32_t(131)
        , int32_t(285)
        , int32_t(529)
        , int32_t(1033)
        , int32_t(2053)
        , int32_t(4179)
        , int32_t(8219)
        , int32_t(16427)
        , int32_t(32771)
    }));
    ExpToFieldElt_ = new ::int32_tArray(MultField + Lfield);
    (*ExpToFieldElt_)[int32_t(0)] = 1;
    for (auto i = int32_t(1); i < MultField + Lfield - int32_t(1); i++) {
        (*ExpToFieldElt_)[i] = (*ExpToFieldElt_)[i - int32_t(1)] << int32_t(1);
        if(((*ExpToFieldElt_)[i] & (int32_t(1) << Lfield)) != 0) {
            (*ExpToFieldElt_)[i] ^= (*polymask)[Lfield];
        }
    }
    FieldEltToExp_ = new ::int32_tArray(MultField + int32_t(1));
    (*FieldEltToExp_)[int32_t(0)] = -int32_t(1);
    for (auto i = int32_t(0); i < MultField; i++) {
        (*FieldEltToExp_)[(*ExpToFieldElt_)[i]] = i;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::ErasureCodec::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.ErasureCodec", 29);
    return c;
}

void rice::p2p::glacier::ErasureCodec::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        isEltInitialized_ = false;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::glacier::ErasureCodec::getClass0()
{
    return class_();
}

