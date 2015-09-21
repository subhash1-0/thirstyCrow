// Generated from /pastry-2.1/src/rice/pastry/testing/PastryTest.java

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

class rice::pastry::testing::PastryTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::pastry::direct::DirectPastryNodeFactory* factory {  };
    ::rice::pastry::direct::NetworkSimulator* simulator {  };
    ::java::util::Vector* pastryNodes {  };
    ::java::util::Vector* pingClients {  };
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::environment::Environment* env);

private:
    ::rice::pastry::NodeHandle* getBootstrap();

public:
    virtual void makePastryNode();
    virtual void sendPings(int32_t k);
    virtual bool simulate();
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    PastryTest(::rice::environment::Environment* env);
protected:
    PastryTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
