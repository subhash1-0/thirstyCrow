// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Externalizable.hpp>

struct default_init_tag;

class rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Externalizable
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int32_t num {  };

public:
    virtual int32_t getNum();
    void writeExternal(::java::io::ObjectOutput* o) /* throws(IOException) */ override;
    void readExternal(::java::io::ObjectInput* i) /* throws(IOException, ClassNotFoundException) */ override;

    // Generated
    XMLObjectStreamUnit_TestExternalizable();
protected:
    void ctor();
    XMLObjectStreamUnit_TestExternalizable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectStreamUnit;
    friend class XMLObjectStreamUnit_testCustomSerializer_1;
    friend class XMLObjectStreamUnit_testBrokenCustomSerializer_2;
    friend class XMLObjectStreamUnit_TestByteSerialization;
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
