// Generated from /pastry-2.1/src/rice/pastry/testing/PingMessageNew.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/Message.hpp>

struct default_init_tag;

class rice::pastry::testing::PingMessageNew
    : public ::rice::pastry::messaging::Message
{

public:
    typedef ::rice::pastry::messaging::Message super;

private:
    ::rice::pastry::Id* target {  };
    int32_t nHops {  };
    double fDistance {  };
protected:
    void ctor(int32_t pingAddress, ::rice::pastry::NodeHandle* src, ::rice::pastry::Id* tgt);

public:
    ::java::lang::String* toString() override;
    virtual void incrHops();
    virtual void incrDistance(double dist);
    virtual int32_t getHops();
    virtual double getDistance();
    virtual ::rice::pastry::Id* getSource();

    // Generated
    PingMessageNew(int32_t pingAddress, ::rice::pastry::NodeHandle* src, ::rice::pastry::Id* tgt);
protected:
    PingMessageNew(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
