// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestExternalizable.hpp>

struct default_init_tag;

class rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable
    : public XMLObjectStreamUnit_TestExternalizable
{

public:
    typedef XMLObjectStreamUnit_TestExternalizable super;
protected:
    void ctor(::java::lang::Object* o);
    void ctor();

public:
    void writeExternal(::java::io::ObjectOutput* o) /* throws(IOException) */ override;
    void readExternal(::java::io::ObjectInput* i) /* throws(IOException, ClassNotFoundException) */ override;

private:
    void readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */;
    void writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */;

    // Generated

public:
    XMLObjectStreamUnit_TestSubExternalizable(::java::lang::Object* o);

private:
    XMLObjectStreamUnit_TestSubExternalizable();
protected:
    XMLObjectStreamUnit_TestSubExternalizable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectStreamUnit;
    friend class XMLObjectStreamUnit_testCustomSerializer_1;
    friend class XMLObjectStreamUnit_testBrokenCustomSerializer_2;
    friend class XMLObjectStreamUnit_TestByteSerialization;
    friend class XMLObjectStreamUnit_TestExternalizable;
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
