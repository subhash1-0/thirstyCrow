// Generated from /pastry-2.1/src/rice/p2p/commonapi/exception/AppNotRegisteredException.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/exception/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/exception/AppSocketException.hpp>

struct default_init_tag;

class rice::p2p::commonapi::exception::AppNotRegisteredException
    : public AppSocketException
{

public:
    typedef AppSocketException super;

private:
    int32_t appid {  };
protected:
    void ctor(int32_t appid);

public:
    virtual int32_t getAppid();

    // Generated
    AppNotRegisteredException(int32_t appid);
protected:
    AppNotRegisteredException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
