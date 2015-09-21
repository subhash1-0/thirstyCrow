// Generated from /pastry-2.1/src/rice/pastry/testing/PartitionChecker.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
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

class rice::pastry::testing::PartitionChecker
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    static constexpr int32_t MAX_THREADS { int32_t(100) };

public: /* package */
    int32_t numThreads {  };
    ::java::util::HashSet* unmatchedBootstraps {  };
    ::java::util::HashSet* bootstraps {  };
    ::java::io::PrintStream* ps {  };
    ::java::util::ArrayList* rings {  };
    ::rice::environment::Environment* environment {  };
    ::java::util::HashSet* dead {  };
protected:
    void ctor(::java::lang::String* ringIdString) /* throws(Exception) */;

public: /* protected */
    virtual void buildBootstrapSetFromCert(::java::lang::String* ringIdString) /* throws(Exception) */;
    virtual ::rice::pastry::leafset::LeafSet* getLeafSet(::rice::pastry::NodeHandle* nh) /* throws(IOException) */;
    virtual PartitionChecker_Ring* buildRing(::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddress* bootstrap) /* throws(Exception) */;

public:
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    PartitionChecker(::java::lang::String* ringIdString);
protected:
    PartitionChecker(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class PartitionChecker_buildRing_1;
    friend class PartitionChecker_Ring;
};
