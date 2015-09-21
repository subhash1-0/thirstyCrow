// Generated from /pastry-2.1/src/rice/pastry/Id.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

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

struct default_init_tag;

class rice::pastry::Id
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Id
    , public virtual ::rice::p2p::commonapi::rawserialization::RawSerializable
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(1) };

private:
    static ::java::util::WeakHashMap* ID_MAP_;
    static ::java::lang::StringArray* tran_;

public:
    static constexpr int32_t IdBitLength { int32_t(160) };
    static constexpr int32_t nlen { int32_t(5) };

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(2166868464271508935LL) };

private:
    static ::int32_tArray* Null_;
    static ::int32_tArray* One_;
    static ::int32_tArray* NegOne_;
    static ::int32_tArray* Half_;
    ::int32_tArray* Id_ {  };
protected:
    void ctor(::int32_tArray* material);

public:
    static int32_t numDigits(int32_t base);
    static ::rice::pastry::Id* makeRandomId(::java::util::Random* rng);
    static ::rice::pastry::Id* makeRandomId(::rice::environment::random::RandomSource* rng);
    static ::rice::pastry::Id* build(::int32_tArray* material);
    static ::rice::pastry::Id* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static ::rice::pastry::Id* build(::java::lang::String* hex);
    static ::rice::pastry::Id* build(::char16_tArray* chars, int32_t offset, int32_t length);

public: /* protected */
    static int8_t trans(char16_t c);

public:
    static ::rice::pastry::Id* build(::int8_tArray* material);

public: /* protected */
    static ::int32_tArray* trans(::int8_tArray* material);

public:
    static ::rice::pastry::Id* build();

public: /* protected */
    static ::int32_tArray* trans(::java::lang::String* hex);
    static ::rice::pastry::Id* resolve(::java::util::WeakHashMap* map, ::rice::pastry::Id* id);

private:
    ::java::lang::Object* readResolve() /* throws(ObjectStreamException) */;

public:
    virtual ::rice::pastry::Id* getCW();
    virtual ::rice::pastry::Id* getCCW();
    virtual bool isBetween(::rice::pastry::Id* ccw, ::rice::pastry::Id* cw);
    virtual int32_t getDigit(int32_t i, int32_t b);
    virtual ::rice::pastry::Id* getDomainPrefix(int32_t row, int32_t column, int32_t suffixDigit, int32_t b);
    virtual ::rice::pastry::Id* getAlternateId(int32_t num, int32_t b, int32_t i);
    bool isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw) override;

private:
    void setDigit(int32_t i, int32_t v, int32_t b);

public:
    virtual void blit(::int8_tArray* target);
    virtual void blit(::int8_tArray* target, int32_t offset);
    virtual ::int8_tArray* copy();
    bool equals(::java::lang::Object* obj) override;
    virtual int32_t compareTo(::rice::p2p::commonapi::Id* obj);
    ::int8_tArray* toByteArray_() override;
    void toByteArray_(::int8_tArray* array, int32_t offset) override;
    int32_t getByteArrayLength() override;
    int32_t hashCode() override;
    virtual ::rice::pastry::Id* add(Id_Distance* offset);
    virtual Id_Distance* distance(::rice::pastry::Id* nid);
    virtual Id_Distance* distance(::rice::pastry::Id* nid, Id_Distance* d);
    virtual Id_Distance* longDistance(::rice::pastry::Id* nid);
    virtual bool equals(::rice::pastry::Id* nid);
    virtual bool clockwise(::rice::pastry::Id* nid);
    virtual bool checkBit(int32_t i);
    virtual int32_t indexOfMSDB(::rice::pastry::Id* nid);
    virtual int32_t indexOfMSDD(::rice::pastry::Id* nid, int32_t base);
    ::java::lang::String* toString() override;
    virtual ::java::lang::String* toStringBare();
    ::java::lang::String* toStringFull() override;
    bool clockwise(::rice::p2p::commonapi::Id* nid) override;
    ::rice::p2p::commonapi::Id* addToId(::rice::p2p::commonapi::Id_Distance* offset) override;
    ::rice::p2p::commonapi::Id_Distance* distanceFromId(::rice::p2p::commonapi::Id* nid) override;
    ::rice::p2p::commonapi::Id_Distance* longDistanceFromId(::rice::p2p::commonapi::Id* nid) override;

private:
    ::int32_tArray* absDistance(::rice::pastry::Id* nid);
    ::int32_tArray* absDistance(::rice::pastry::Id* nid, ::int32_tArray* dist);
    void invert(::int32_tArray* dist);

public:
    int16_t getType() override;
    static void main(::java::lang::StringArray* args);

    // Generated

public: /* protected */
    Id(::int32_tArray* material);
protected:
    Id(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    virtual int32_t compareTo(::java::lang::Object* arg0) override;

private:
    static ::java::util::WeakHashMap*& ID_MAP();

public:
    static ::java::lang::StringArray*& tran();
    static ::int32_tArray*& Null();
    static ::int32_tArray*& One();
    static ::int32_tArray*& NegOne();
    static ::int32_tArray*& Half();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Id_Distance;
};
