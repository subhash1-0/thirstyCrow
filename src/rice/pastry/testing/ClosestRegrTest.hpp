// Generated from /pastry-2.1/src/rice/pastry/testing/ClosestRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
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

class rice::pastry::testing::ClosestRegrTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static int32_t NUM_NODES_;
    ::rice::pastry::PastryNodeFactory* factory {  };
    ::rice::pastry::direct::NetworkSimulator* simulator {  };
    ::java::util::Vector* pastryNodes {  };

public: /* package */
    int32_t incorrect {  };
    double sum {  };

private:
    ::rice::environment::Environment* environment {  };
protected:
    void ctor() /* throws(IOException) */;

public: /* protected */
    virtual ::rice::pastry::NodeHandle* getBootstrap();
    virtual void run();
    virtual double getAvgNumEntries(::java::util::Collection* nds);
    virtual void test(int32_t i, ::rice::pastry::direct::DirectNodeHandle* handle);

public:
    virtual bool pass();
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated

private:
    ClosestRegrTest();
protected:
    ClosestRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static int32_t& NUM_NODES();

private:
    virtual ::java::lang::Class* getClass0();
};
