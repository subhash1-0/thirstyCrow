// Generated from /pastry-2.1/src/rice/p2p/past/testing/DistPastTestContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/ContentHashPastContent.hpp>

struct default_init_tag;

class rice::p2p::past::testing::DistPastTestContent
    : public ::rice::p2p::past::ContentHashPastContent
{

public:
    typedef ::rice::p2p::past::ContentHashPastContent super;

public: /* package */
    ::java::lang::String* content {  };
    int64_t timestamp {  };
protected:
    void ctor(::rice::environment::Environment* env, ::rice::p2p::commonapi::IdFactory* idf, ::java::lang::String* content);

public:
    virtual ::java::lang::String* getContent();
    virtual int64_t getTimestamp();

    // Generated
    DistPastTestContent(::rice::environment::Environment* env, ::rice::p2p::commonapi::IdFactory* idf, ::java::lang::String* content);
protected:
    DistPastTestContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
