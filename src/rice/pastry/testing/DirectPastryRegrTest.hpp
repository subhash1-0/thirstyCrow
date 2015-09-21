// Generated from /pastry-2.1/src/rice/pastry/testing/DirectPastryRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/PastryRegrTest.hpp>

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

class rice::pastry::testing::DirectPastryRegrTest
    : public PastryRegrTest
{

public:
    typedef PastryRegrTest super;

private:
    ::rice::pastry::direct::NetworkSimulator* simulator {  };
protected:
    void ctor() /* throws(IOException) */;

public: /* protected */
    ::rice::pastry::NodeHandle* getBootstrap(bool firstNode) override;
    void registerapp(::rice::pastry::PastryNode* pn, RegrTestApp* app) override;
    bool simulate() override;

public:
    void pause(int32_t ms) override;

public: /* protected */
    bool isReallyAlive(::rice::pastry::NodeHandle* nh) override;
    void killNode(::rice::pastry::PastryNode* pn) override;
    void checkRoutingTable(RegrTestApp* rta) override;

public:
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated

private:
    DirectPastryRegrTest();
protected:
    DirectPastryRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
