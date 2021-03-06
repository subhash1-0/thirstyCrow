// Generated from /pastry-2.1/src/rice/p2p/splitstream/StripeId.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::splitstream::StripeId
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Id* id {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* id);

public:
    virtual ::rice::p2p::commonapi::Id* getId();
    ::java::lang::String* toString() override;
    int32_t hashCode() override;
    bool equals(::java::lang::Object* o) override;

    // Generated
    StripeId(::rice::p2p::commonapi::Id* id);
protected:
    StripeId(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
