// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/NotEnoughBandwidthException.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/tutorial/transportlayer/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class rice::tutorial::transportlayer::NotEnoughBandwidthException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

public: /* package */
    int64_t bucketSize {  };
    int32_t attemptedToWrite {  };
protected:
    void ctor(int64_t bucketSize, int32_t attemptedToWrite);

public:
    virtual int64_t getAmountAllowedToWrite();
    virtual int32_t getAttemptedToWrite();

    // Generated
    NotEnoughBandwidthException(int64_t bucketSize, int32_t attemptedToWrite);
protected:
    NotEnoughBandwidthException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
