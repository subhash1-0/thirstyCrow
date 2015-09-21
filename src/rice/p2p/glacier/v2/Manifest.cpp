// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/Manifest.java
#include <rice/p2p/glacier/v2/Manifest.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/glacier/Fragment.hpp>
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

namespace 
{
typedef ::SubArray< ::int8_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int8_tArrayArray;
} // 

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::Manifest::Manifest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::Manifest::Manifest(::int8_tArray* objectHash, ::int8_tArrayArray* fragmentHash, int64_t expirationDate) 
    : Manifest(*static_cast< ::default_init_tag* >(0))
{
    ctor(objectHash,fragmentHash,expirationDate);
}

rice::p2p::glacier::v2::Manifest::Manifest(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : Manifest(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf);
}

constexpr int64_t rice::p2p::glacier::v2::Manifest::serialVersionUID;

void rice::p2p::glacier::v2::Manifest::ctor(::int8_tArray* objectHash, ::int8_tArrayArray* fragmentHash, int64_t expirationDate)
{
    super::ctor();
    this->objectHash = objectHash;
    this->fragmentHash = fragmentHash;
    this->expirationDate = expirationDate;
    this->signature = nullptr;
}

int8_tArray* rice::p2p::glacier::v2::Manifest::getObjectHash()
{
    return objectHash;
}

int8_tArray* rice::p2p::glacier::v2::Manifest::getFragmentHash(int32_t fragmentID)
{
    return (*fragmentHash)[fragmentID];
}

int8_tArrayArray* rice::p2p::glacier::v2::Manifest::getFragmentHashes()
{
    return fragmentHash;
}

int8_tArray* rice::p2p::glacier::v2::Manifest::getSignature()
{
    return signature;
}

void rice::p2p::glacier::v2::Manifest::setSignature(::int8_tArray* signature)
{
    this->signature = signature;
}

int64_t rice::p2p::glacier::v2::Manifest::getExpiration()
{
    return expirationDate;
}

void rice::p2p::glacier::v2::Manifest::update(int64_t newExpirationDate, ::int8_tArray* newSignature)
{
    expirationDate = newExpirationDate;
    signature = newSignature;
}

bool rice::p2p::glacier::v2::Manifest::validatesFragment(::rice::p2p::glacier::Fragment* fragment, int32_t fragmentID, ::rice::environment::logging::Logger* logger)
{
    if((fragmentID < 0) || (fragmentID >= npc(fragmentHash)->length))
        return false;

    ::java::security::MessageDigest* md = nullptr;
    try {
        md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
    } catch (::java::security::NoSuchAlgorithmException* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"*** SHA-1 not supported ***"_j)->append(toStringFull())->toString());

        return false;
    }
    npc(md)->reset();
    npc(md)->update(npc(fragment)->getPayload());
    auto thisHash = npc(md)->digest();
    if(npc(thisHash)->length != npc((*fragmentHash)[fragmentID])->length) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"*** LENGTH MISMATCH: "_j)->append(npc(thisHash)->length)
                ->append(u" != "_j)
                ->append(npc((*fragmentHash)[fragmentID])->length)
                ->append(u" ***"_j)
                ->append(toStringFull())->toString());

        return false;
    }
    for (auto i = int32_t(0); i < npc(thisHash)->length; i++) {
        if((*thisHash)[i] != (*(*fragmentHash)[fragmentID])[i]) {
            auto s = ::java::lang::StringBuilder().append(u"*** HASH MISMATCH: POS#"_j)->append(i)
                ->append(u", "_j)
                ->append((*thisHash)[i])
                ->append(u" != "_j)
                ->append((*(*fragmentHash)[fragmentID])[i])
                ->append(u" ***\n"_j)->toString();
            s = ::java::lang::StringBuilder(s).append(u"Hash: "_j)->toString();
            for (auto j = int32_t(0); j < npc(thisHash)->length; j++) 
                                s = ::java::lang::StringBuilder(s).append((*thisHash)[j])->toString();

            s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"\n"_j)->append(toStringFull())->toString())->toString();
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(s);

            return false;
        }
    }
    return true;
}

java::lang::String* rice::p2p::glacier::v2::Manifest::dump(::int8_tArray* data, bool linebreak)
{
    clinit();
    auto const hex = u"0123456789ABCDEF"_j;
    auto result = u""_j;
    for (auto i = int32_t(0); i < npc(data)->length; i++) {
        int32_t d = (*data)[i];
        if(d < 0)
            d += 256;

        auto hi = (d >> int32_t(4));
        auto lo = (d & int32_t(15));
        result = ::java::lang::StringBuilder().append(result)->append(npc(hex)->charAt(hi))
            ->append(npc(hex)->charAt(lo))->toString();
        if(linebreak && (((i % int32_t(16)) == 15) || (i == (npc(data)->length - int32_t(1)))))
            result = ::java::lang::StringBuilder().append(result)->append(u"\n"_j)->toString();
        else if(i != (npc(data)->length - int32_t(1)))
            result = ::java::lang::StringBuilder().append(result)->append(u" "_j)->toString();

    }
    return result;
}

java::lang::String* rice::p2p::glacier::v2::Manifest::toString()
{
    return ::java::lang::StringBuilder().append(u"[Manifest obj=["_j)->append(dump(objectHash, false))
        ->append(u"] expires="_j)
        ->append(expirationDate)
        ->append(u"]"_j)->toString();
}

java::lang::String* rice::p2p::glacier::v2::Manifest::toStringFull()
{
    auto result = u""_j;
    result = ::java::lang::StringBuilder().append(result)->append(u"Manifest (expires "_j)
        ->append(expirationDate)
        ->append(u")\n"_j)->toString();
    result = ::java::lang::StringBuilder().append(result)->append(u"  - objectHash = ["_j)
        ->append(dump(objectHash, false))
        ->append(u"]\n"_j)->toString();
    result = ::java::lang::StringBuilder().append(result)->append(u"  - signature  = ["_j)
        ->append(dump(signature, false))
        ->append(u"]\n"_j)->toString();
    for (auto i = int32_t(0); i < npc(fragmentHash)->length; i++) 
                result = ::java::lang::StringBuilder().append(result)->append(u"  - fragmHash"_j)
            ->append(i)
            ->append(u" = ["_j)
            ->append(dump((*fragmentHash)[i], false))
            ->append(u"]\n"_j)->toString();

    return result;
}

void rice::p2p::glacier::v2::Manifest::writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */
{
    npc(oos)->defaultWriteObject();
    npc(oos)->writeInt(npc(objectHash)->length);
    npc(oos)->writeInt(npc(fragmentHash)->length);
    npc(oos)->writeInt(npc((*fragmentHash)[int32_t(0)])->length);
    npc(oos)->writeInt(npc(signature)->length);
    npc(oos)->write(objectHash);
    auto dim1 = npc(fragmentHash)->length;
    auto dim2 = npc((*fragmentHash)[int32_t(0)])->length;
    auto fragmentHashField = new ::int8_tArray(dim1 * dim2);
    for (auto i = int32_t(0); i < dim1; i++) 
                for (auto j = int32_t(0); j < dim2; j++) 
                        (*fragmentHashField)[i * dim2 + j] = (*(*fragmentHash)[i])[j];


    npc(oos)->write(fragmentHashField);
    npc(oos)->write(signature);
}

void rice::p2p::glacier::v2::Manifest::readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */
{
    npc(ois)->defaultReadObject();
    auto objectHashLength = npc(ois)->readInt();
    auto fragmentHashLength = npc(ois)->readInt();
    auto fragmentHashSubLength = npc(ois)->readInt();
    auto signatureLength = npc(ois)->readInt();
    objectHash = new ::int8_tArray(objectHashLength);
    npc(ois)->readFully(objectHash, int32_t(0), objectHashLength);
    auto fragmentHashField = new ::int8_tArray(fragmentHashLength * fragmentHashSubLength);
    npc(ois)->readFully(fragmentHashField, int32_t(0), fragmentHashLength * fragmentHashSubLength);
    fragmentHash = new ::int8_tArrayArray(fragmentHashLength);
    for (auto i = int32_t(0); i < fragmentHashLength; i++) 
                for (auto j = int32_t(0); j < fragmentHashSubLength; j++) 
                        (*(*fragmentHash)[i])[j] = (*fragmentHashField)[i * fragmentHashSubLength + j];


    signature = new ::int8_tArray(signatureLength);
    npc(ois)->readFully(signature, int32_t(0), signatureLength);
}

void rice::p2p::glacier::v2::Manifest::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeInt(npc(objectHash)->length);
    npc(buf)->writeInt(npc(fragmentHash)->length);
    npc(buf)->writeInt(npc((*fragmentHash)[int32_t(0)])->length);
    npc(buf)->writeInt(npc(signature)->length);
    npc(buf)->write(objectHash, 0, npc(objectHash)->length);
    auto dim1 = npc(fragmentHash)->length;
    auto dim2 = npc((*fragmentHash)[int32_t(0)])->length;
    auto fragmentHashField = new ::int8_tArray(dim1 * dim2);
    for (auto i = int32_t(0); i < dim1; i++) 
                for (auto j = int32_t(0); j < dim2; j++) 
                        (*fragmentHashField)[i * dim2 + j] = (*(*fragmentHash)[i])[j];


    npc(buf)->write(fragmentHashField, 0, npc(fragmentHashField)->length);
    npc(buf)->write(signature, 0, npc(signature)->length);
}

void rice::p2p::glacier::v2::Manifest::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor();
    auto objectHashLength = npc(buf)->readInt();
    auto fragmentHashLength = npc(buf)->readInt();
    auto fragmentHashSubLength = npc(buf)->readInt();
    auto signatureLength = npc(buf)->readInt();
    objectHash = new ::int8_tArray(objectHashLength);
    npc(buf)->read(objectHash, 0, objectHashLength);
    auto fragmentHashField = new ::int8_tArray(fragmentHashLength * fragmentHashSubLength);
    npc(buf)->read(fragmentHashField, 0, fragmentHashLength * fragmentHashSubLength);
    fragmentHash = new ::int8_tArrayArray(fragmentHashLength);
    for (auto i = int32_t(0); i < fragmentHashLength; i++) 
                for (auto j = int32_t(0); j < fragmentHashSubLength; j++) 
                        (*(*fragmentHash)[i])[j] = (*fragmentHashField)[i * fragmentHashSubLength + j];


    signature = new ::int8_tArray(signatureLength);
    npc(buf)->read(signature, 0, signatureLength);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::Manifest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.Manifest", 28);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::Manifest::getClass0()
{
    return class_();
}

