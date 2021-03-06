// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

class org::mpisws::p2p::testing::filetransfer::ProfileFileTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    ProfileFileTest();
protected:
    ProfileFileTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProfileFileTest_main_1;
    friend class ProfileFileTest_main_2;
    friend class ProfileFileTest_main_2_incomingSocket_2_1;
    friend class ProfileFileTest_main_2_incomingSocket_2_2;
    friend class ProfileFileTest_main_3;
    friend class ProfileFileTest_main_4;
    friend class ProfileFileTest_main_4_receiveResult_4_1;
    friend class ProfileFileTest_main_4_receiveResult_4_2;
};
