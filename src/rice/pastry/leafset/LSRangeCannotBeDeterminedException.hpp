// Generated from /pastry-2.1/src/rice/pastry/leafset/LSRangeCannotBeDeterminedException.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/RangeCannotBeDeterminedException.hpp>

struct default_init_tag;

class rice::pastry::leafset::LSRangeCannotBeDeterminedException
    : public ::rice::p2p::commonapi::RangeCannotBeDeterminedException
{

public:
    typedef ::rice::p2p::commonapi::RangeCannotBeDeterminedException super;
    int32_t r {  };
    int32_t pos {  };
    int32_t uniqueCount {  };
    ::rice::p2p::commonapi::NodeHandle* nh {  };
protected:
    void ctor(::java::lang::String* string, int32_t r, int32_t pos, int32_t uniqueNodes, ::rice::p2p::commonapi::NodeHandle* nh, LeafSet* ls);

    // Generated

public:
    LSRangeCannotBeDeterminedException(::java::lang::String* string, int32_t r, int32_t pos, int32_t uniqueNodes, ::rice::p2p::commonapi::NodeHandle* nh, LeafSet* ls);
protected:
    LSRangeCannotBeDeterminedException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
