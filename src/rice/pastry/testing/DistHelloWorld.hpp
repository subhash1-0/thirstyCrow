// Generated from /pastry-2.1/src/rice/pastry/testing/DistHelloWorld.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
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

class rice::pastry::testing::DistHelloWorld
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::pastry::PastryNodeFactory* factory {  };
    ::java::util::Vector* pastryNodes {  };
    ::java::util::Vector* helloClients {  };
    static int32_t port_;
    static ::java::lang::String* bshost_;
    static int32_t bsport_;
    static int32_t numnodes_;
    static int32_t nummsgs_;
    static int32_t protocol_;

public:
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public: /* protected */
    virtual ::rice::pastry::NodeHandle* getBootstrap(bool firstNode);

private:
    static void doIinitstuff(::java::lang::StringArray* args, ::rice::environment::Environment* env);

public:
    virtual ::rice::pastry::PastryNode* makePastryNode(bool firstNode);
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    DistHelloWorld(::rice::environment::Environment* env);
protected:
    DistHelloWorld(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static int32_t& port();
    static ::java::lang::String*& bshost();
    static int32_t& bsport();
    static int32_t& numnodes();
    static int32_t& nummsgs();

public:
    static int32_t& protocol();

private:
    virtual ::java::lang::Class* getClass0();
};
