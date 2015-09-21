// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/MagicNumberTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/WireTest.hpp>

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

class org::mpisws::p2p::testing::transportlayer::MagicNumberTest
    : public WireTest
{

public:
    typedef WireTest super;

private:
    static ::int8_tArray* BAD_HDR_;
    static ::int8_tArray* GOOD_HDR_;
    static ::int8_tArray* NO_HDR_;
    static ::org::mpisws::p2p::transport::TransportLayer* carol_;
    static ::org::mpisws::p2p::transport::TransportLayer* dave_;

protected:
    void ctor();

public:
    static void main(::java::lang::StringArray* args);
    static void setUpBeforeClass();
    virtual void stallTCP();
    virtual void wrongHeaderTCP();
    virtual void wrongHeaderUDP();

    // Generated
    MagicNumberTest();
protected:
    MagicNumberTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static ::int8_tArray*& BAD_HDR();
    static ::int8_tArray*& GOOD_HDR();
    static ::int8_tArray*& NO_HDR();

public: /* package */
    static ::org::mpisws::p2p::transport::TransportLayer*& carol();
    static ::org::mpisws::p2p::transport::TransportLayer*& dave();

private:
    virtual ::java::lang::Class* getClass0();
};
