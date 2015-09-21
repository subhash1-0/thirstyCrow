// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Application.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    BandwidthMeasuringTLTest();
protected:
    BandwidthMeasuringTLTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthMeasuringTLTest_MyMsg;
    friend class BandwidthMeasuringTLTest_main_1;
    friend class BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1;
};
