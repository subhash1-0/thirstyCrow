// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <rice/Destructable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace rice
{
    namespace p2p
    {
        namespace splitstream
        {
typedef ::SubArray< ::rice::p2p::splitstream::Channel, ::java::lang::ObjectArray > ChannelArray;
        } // splitstream
    } // p2p
} // rice

struct rice::p2p::splitstream::SplitStream
    : public virtual ::rice::Destructable
{
    virtual Channel* attachChannel(ChannelId* id) = 0;
    virtual Channel* createChannel(ChannelId* id) = 0;
    virtual ChannelArray* getChannels() = 0;
    virtual int32_t getStripeBaseBitLength() = 0;
    virtual ::rice::environment::Environment* getEnvironment() = 0;
    /*void destroy(); (already declared) */

    // Generated
    static ::java::lang::Class *class_();
};
