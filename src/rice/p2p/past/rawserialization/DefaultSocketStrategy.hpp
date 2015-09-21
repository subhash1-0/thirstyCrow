// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/DefaultSocketStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/rawserialization/SocketStrategy.hpp>

struct default_init_tag;

class rice::p2p::past::rawserialization::DefaultSocketStrategy
    : public virtual ::java::lang::Object
    , public virtual SocketStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    bool answer {  };
protected:
    void ctor(bool answer);

public:
    bool sendAlongSocket(int32_t sendType, ::rice::p2p::past::PastContent* content) override;

    // Generated
    DefaultSocketStrategy(bool answer);
protected:
    DefaultSocketStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
