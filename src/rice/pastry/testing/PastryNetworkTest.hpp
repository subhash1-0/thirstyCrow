// Generated from /pastry-2.1/src/rice/pastry/testing/PastryNetworkTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
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

class rice::pastry::testing::PastryNetworkTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::pastry::socket::SocketPastryNodeFactory* factory {  };
    ::java::net::InetSocketAddress* bootstrap {  };
    ::java::util::HashSet* nodes {  };
    ::java::util::HashSet* dead {  };
    ::java::util::HashSet* unknown {  };
    static constexpr int32_t MAX_THREADS { int32_t(100) };
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::environment::Environment* env, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddress* bootstrap);

public: /* package */
    int32_t numThreads {  };

public: /* protected */
    virtual ::java::util::HashMap* fetchLeafSets() /* throws(Exception) */;
    virtual void testLeafSets() /* throws(Exception) */;
    virtual ::java::util::HashMap* fetchRouteRow(int32_t row) /* throws(IOException) */;
    virtual void testRouteRow(int32_t row) /* throws(IOException) */;
    virtual void testRoutingTables() /* throws(Exception) */;

public:
    virtual void start() /* throws(Exception) */;
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    PastryNetworkTest(::rice::environment::Environment* env, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddress* bootstrap);
protected:
    PastryNetworkTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class PastryNetworkTest_fetchLeafSets_1;
};
