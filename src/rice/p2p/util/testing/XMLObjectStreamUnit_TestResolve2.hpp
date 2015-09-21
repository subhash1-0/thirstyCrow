// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java

#pragma once

#include <rice/p2p/util/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestResolve.hpp>

struct default_init_tag;

class rice::p2p::util::testing::XMLObjectStreamUnit_TestResolve2
    : public XMLObjectStreamUnit_TestResolve
{

public:
    typedef XMLObjectStreamUnit_TestResolve super;

    // Generated
    XMLObjectStreamUnit_TestResolve2();
protected:
    XMLObjectStreamUnit_TestResolve2(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectStreamUnit;
    friend class XMLObjectStreamUnit_testCustomSerializer_1;
    friend class XMLObjectStreamUnit_testBrokenCustomSerializer_2;
    friend class XMLObjectStreamUnit_TestByteSerialization;
    friend class XMLObjectStreamUnit_TestExternalizable;
    friend class XMLObjectStreamUnit_TestSubExternalizable;
    friend class XMLObjectStreamUnit_TestPutFields;
    friend class XMLObjectStreamUnit_TestUnreadData;
    friend class XMLObjectStreamUnit_TestReplace;
    friend class XMLObjectStreamUnit_TestReplace2;
    friend class XMLObjectStreamUnit_TestReplace3;
    friend class XMLObjectStreamUnit_TestResolve;
    friend class XMLObjectStreamUnit_TestResolve3;
    friend class XMLObjectStreamUnit_TestSerialPersistentFields;
};
