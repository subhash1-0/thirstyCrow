// Generated from /pastry-2.1/src/rice/pastry/testing/DistPastryRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
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

class rice::pastry::testing::DistPastryRegrTest
    : public PastryRegrTest
{

public:
    typedef PastryRegrTest super;

private:
    static int32_t port_;
    static ::java::lang::String* bshost_;
    static int32_t bsport_;
    static int32_t numnodes_;
    static int32_t protocol_;
    ::java::net::InetSocketAddress* bsaddress {  };
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public: /* protected */
    ::rice::pastry::NodeHandle* getBootstrap(bool firstNode) override;

private:
    static void doInitstuff(::java::lang::StringArray* args);

public: /* protected */
    void registerapp(::rice::pastry::PastryNode* pn, RegrTestApp* app) override;

public:
    bool simulate() override;
    void pause(int32_t ms) override;
    bool isReallyAlive(::rice::pastry::NodeHandle* nh) override;

public: /* protected */
    void killNode(::rice::pastry::PastryNode* pn) override;

public:
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    DistPastryRegrTest(::rice::environment::Environment* env);
protected:
    DistPastryRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static int32_t& port();
    static ::java::lang::String*& bshost();
    static int32_t& bsport();
    static int32_t& numnodes();
    static int32_t& protocol();
    virtual ::java::lang::Class* getClass0();
};
