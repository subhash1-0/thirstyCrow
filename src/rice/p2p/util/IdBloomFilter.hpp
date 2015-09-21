// Generated from /pastry-2.1/src/rice/p2p/util/IdBloomFilter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::util::IdBloomFilter
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-9122948172786936161LL) };
    static int32_t NUM_BITS_PER_KEY_;
    static int32_t NUM_HASH_FUNCTIONS_;

public: /* protected */
    ::int8_tArray* array {  };
    BloomFilter* filter {  };
protected:
    void ctor(::rice::p2p::commonapi::IdSet* set);

public: /* protected */
    virtual void checkArray_(::rice::p2p::commonapi::Id* id);
    virtual void addId(::rice::p2p::commonapi::Id* id);

public:
    virtual bool check(::rice::p2p::commonapi::Id* id);
    virtual void check(::rice::p2p::commonapi::IdSet* set, ::rice::p2p::commonapi::IdSet* result, int32_t max);
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

    // Generated
    IdBloomFilter(::rice::p2p::commonapi::IdSet* set);
    IdBloomFilter(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    IdBloomFilter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static int32_t& NUM_BITS_PER_KEY();
    static int32_t& NUM_HASH_FUNCTIONS();

private:
    virtual ::java::lang::Class* getClass0();
};
