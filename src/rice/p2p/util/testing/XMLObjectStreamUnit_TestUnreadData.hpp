// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::util::testing::XMLObjectStreamUnit_TestUnreadData
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t num {  };

private:
    void writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */;

public:
    virtual int32_t getNum();

    // Generated
    XMLObjectStreamUnit_TestUnreadData();
protected:
    void ctor();
    XMLObjectStreamUnit_TestUnreadData(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectStreamUnit;
    friend class XMLObjectStreamUnit_testCustomSerializer_1;
    friend class XMLObjectStreamUnit_testBrokenCustomSerializer_2;
    friend class XMLObjectStreamUnit_TestByteSerialization;
    friend class XMLObjectStreamUnit_TestExternalizable;
    friend class XMLObjectStreamUnit_TestSubExternalizable;
    friend class XMLObjectStreamUnit_TestPutFields;
    friend class XMLObjectStreamUnit_TestReplace;
    friend class XMLObjectStreamUnit_TestReplace2;
    friend class XMLObjectStreamUnit_TestReplace3;
    friend class XMLObjectStreamUnit_TestResolve;
    friend class XMLObjectStreamUnit_TestResolve2;
    friend class XMLObjectStreamUnit_TestResolve3;
    friend class XMLObjectStreamUnit_TestSerialPersistentFields;
};
