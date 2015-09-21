// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/BloomFilter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::BloomFilter
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-3938913031743354080LL) };
    ::int8_tArray* bitfield {  };
    ::int32_tArray* hashParams {  };
protected:
    void ctor(int32_t length, ::int32_tArray* hashParams);
    void ctor(int32_t length, int32_t numHashes, ::rice::environment::random::RandomSource* rand);

private:
    ::int32_tArray* getHashes(::int8_tArray* data);
    void dump(::rice::environment::logging::Logger* logger);

public:
    virtual void add(::int8_tArray* data);
    virtual bool contains(::int8_tArray* data);
    ::java::lang::String* toString() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

    // Generated
    BloomFilter(int32_t length, ::int32_tArray* hashParams);
    BloomFilter(int32_t length, int32_t numHashes, ::rice::environment::random::RandomSource* rand);
    BloomFilter(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    BloomFilter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
