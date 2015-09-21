// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::ObjectStreamField, ::java::lang::ObjectArray, ::java::lang::ComparableArray > ObjectStreamFieldArray;
    } // io
} // java

struct default_init_tag;

class java::util::BitSet
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static bool $assertionsDisabled_;
    static constexpr int32_t ADDRESS_BITS_PER_WORD { int32_t(6) };
    static constexpr int32_t BITS_PER_WORD { int32_t(64) };
    static constexpr int32_t BIT_INDEX_MASK { int32_t(63) };
    static constexpr int64_t WORD_MASK { int64_t(-1LL) };
    static ::java::io::ObjectStreamFieldArray* serialPersistentFields_;
    static constexpr int64_t serialVersionUID { int64_t(7997698588986878753LL) };
    bool sizeIsSticky {  };
    ::int64_tArray* words {  };
    int32_t wordsInUse {  };

protected:
    void ctor();
    void ctor(int32_t arg0);
    /*void ctor(::int64_tArray* arg0); (private) */

public:
    virtual void and_(BitSet* arg0);
    virtual void andNot(BitSet* arg0);
    virtual int32_t cardinality();
    /*void checkInvariants(); (private) */
    /*static void checkRange(int32_t arg0, int32_t arg1); (private) */
    virtual void clear();
    virtual void clear(int32_t arg0);
    virtual void clear(int32_t arg0, int32_t arg1);
    ::java::lang::Object* clone() override;
    /*void ensureCapacity(int32_t arg0); (private) */
    bool equals(::java::lang::Object* arg0) override;
    /*void expandTo(int32_t arg0); (private) */
    virtual void flip(int32_t arg0);
    virtual void flip(int32_t arg0, int32_t arg1);
    virtual bool get(int32_t arg0);
    virtual BitSet* get(int32_t arg0, int32_t arg1);
    int32_t hashCode() override;
    /*void initWords(int32_t arg0); (private) */
    virtual bool intersects(BitSet* arg0);
    virtual bool isEmpty();
    virtual int32_t length();
    virtual int32_t nextClearBit(int32_t arg0);
    virtual int32_t nextSetBit(int32_t arg0);
    virtual void or_(BitSet* arg0);
    virtual int32_t previousClearBit(int32_t arg0);
    virtual int32_t previousSetBit(int32_t arg0);
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    /*void recalculateWordsInUse(); (private) */
    virtual void set(int32_t arg0);
    virtual void set(int32_t arg0, bool arg1);
    virtual void set(int32_t arg0, int32_t arg1);
    virtual void set(int32_t arg0, int32_t arg1, bool arg2);
    virtual int32_t size();
    virtual ::java::util::stream::IntStream* stream();
    virtual ::int8_tArray* toByteArray_();
    virtual ::int64_tArray* toLongArray_();
    ::java::lang::String* toString() override;
    /*void trimToSize(); (private) */
    static BitSet* valueOf(::int64_tArray* arg0);
    static BitSet* valueOf(::java::nio::LongBuffer* arg0);
    static BitSet* valueOf(::int8_tArray* arg0);
    static BitSet* valueOf(::java::nio::ByteBuffer* arg0);
    /*static int32_t wordIndex(int32_t arg0); (private) */
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */
    virtual void xor_(BitSet* arg0);

    // Generated
    BitSet();
    BitSet(int32_t arg0);
protected:
    BitSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static bool& $assertionsDisabled();

private:
    static ::java::io::ObjectStreamFieldArray*& serialPersistentFields();
    virtual ::java::lang::Class* getClass0();
};
