// Generated from /pastry-2.1/src/rice/p2p/util/BloomFilter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

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

class rice::p2p::util::BloomFilter
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static int32_t PARAMETER_LENGTH_;

public: /* protected */
    ::int32_tArray* parameters {  };
    int32_t length {  };
    ::java::util::BitSet* set {  };
protected:
    void ctor(int32_t num, int32_t length);

public:
    virtual void add(::int8_tArray* array);
    virtual bool check(::int8_tArray* array);

public: /* protected */
    virtual int32_t hash(::int8_tArray* array, int32_t i);
    virtual int32_t doHash(::int8_tArray* array, int32_t seed);

public:
    virtual ::java::lang::String* getBitSet();
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

public:
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    BloomFilter(int32_t num, int32_t length);
    BloomFilter(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    BloomFilter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static int32_t& PARAMETER_LENGTH();

private:
    virtual ::java::lang::Class* getClass0();
    friend class BloomFilter_main_1;
    friend class BloomFilter_main_2;
};
