// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java

#pragma once

#include <rice/p2p/util/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestReplace.hpp>

struct default_init_tag;

class rice::p2p::util::testing::XMLObjectStreamUnit_TestReplace3
    : public XMLObjectStreamUnit_TestReplace
{

public:
    typedef XMLObjectStreamUnit_TestReplace super;

    // Generated
    XMLObjectStreamUnit_TestReplace3();
protected:
    XMLObjectStreamUnit_TestReplace3(const ::default_init_tag&);


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
    friend class XMLObjectStreamUnit_TestResolve;
    friend class XMLObjectStreamUnit_TestResolve2;
    friend class XMLObjectStreamUnit_TestResolve3;
    friend class XMLObjectStreamUnit_TestSerialPersistentFields;
};
