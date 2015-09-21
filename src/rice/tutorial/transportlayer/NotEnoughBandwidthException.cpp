// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/NotEnoughBandwidthException.java
#include <rice/tutorial/transportlayer/NotEnoughBandwidthException.hpp>

rice::tutorial::transportlayer::NotEnoughBandwidthException::NotEnoughBandwidthException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::transportlayer::NotEnoughBandwidthException::NotEnoughBandwidthException(int64_t bucketSize, int32_t attemptedToWrite) 
    : NotEnoughBandwidthException(*static_cast< ::default_init_tag* >(0))
{
    ctor(bucketSize,attemptedToWrite);
}

void rice::tutorial::transportlayer::NotEnoughBandwidthException::ctor(int64_t bucketSize, int32_t attemptedToWrite)
{
    super::ctor();
    this->bucketSize = bucketSize;
    this->attemptedToWrite = attemptedToWrite;
}

int64_t rice::tutorial::transportlayer::NotEnoughBandwidthException::getAmountAllowedToWrite()
{
    return bucketSize;
}

int32_t rice::tutorial::transportlayer::NotEnoughBandwidthException::getAttemptedToWrite()
{
    return attemptedToWrite;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::NotEnoughBandwidthException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.transportlayer.NotEnoughBandwidthException", 56);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::NotEnoughBandwidthException::getClass0()
{
    return class_();
}

