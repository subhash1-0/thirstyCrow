// Generated from /pastry-2.1/src/rice/pastry/testing/HelloWorld.java

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

class rice::pastry::testing::HelloWorld
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::pastry::PastryNodeFactory* factory {  };
    ::rice::pastry::direct::NetworkSimulator* simulator {  };
    ::java::util::Vector* pastryNodes {  };
    ::java::util::Vector* helloClients {  };
    static int32_t numnodes_;
    static int32_t nummsgs_;
    static bool simultaneous_joins_;
    static bool simultaneous_msgs_;

public: /* package */
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::environment::Environment* env);

private:
    ::rice::pastry::NodeHandle* getBootstrap();

public:
    virtual void makePastryNode(int32_t num);

private:
    void printLeafSets();
    void sendRandomMessage();
    bool simulate();
    static void doIinitstuff(::java::lang::StringArray* args, ::rice::environment::Environment* env);

public:
    static void main(::java::lang::StringArray* args);

    // Generated
    HelloWorld(::rice::environment::Environment* env);
protected:
    HelloWorld(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static int32_t& numnodes();
    static int32_t& nummsgs();
    static bool& simultaneous_joins();
    static bool& simultaneous_msgs();
    virtual ::java::lang::Class* getClass0();
};
