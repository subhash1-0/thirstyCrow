// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::util::testing::XMLObjectStreamUnit_testBrokenCustomSerializer_2
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    void writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */;

    // Generated

public:
    XMLObjectStreamUnit_testBrokenCustomSerializer_2(XMLObjectStreamUnit *XMLObjectStreamUnit_this);
    static ::java::lang::Class *class_();
    XMLObjectStreamUnit *XMLObjectStreamUnit_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectStreamUnit;
    friend class XMLObjectStreamUnit_testCustomSerializer_1;
    friend class XMLObjectStreamUnit_TestByteSerialization;
    friend class XMLObjectStreamUnit_TestExternalizable;
    friend class XMLObjectStreamUnit_TestSubExternalizable;
    friend class XMLObjectStreamUnit_TestPutFields;
    friend class XMLObjectStreamUnit_TestUnreadData;
    friend class XMLObjectStreamUnit_TestReplace;
    friend class XMLObjectStreamUnit_TestReplace2;
    friend class XMLObjectStreamUnit_TestReplace3;
    friend class XMLObjectStreamUnit_TestResolve;
    friend class XMLObjectStreamUnit_TestResolve2;
    friend class XMLObjectStreamUnit_TestResolve3;
    friend class XMLObjectStreamUnit_TestSerialPersistentFields;
};
