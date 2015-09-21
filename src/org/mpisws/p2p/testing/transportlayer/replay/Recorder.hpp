// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyEvents.hpp>

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

class org::mpisws::p2p::testing::transportlayer::replay::Recorder
    : public virtual ::java::lang::Object
    , public virtual MyEvents
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::ArrayList* apps {  };
    ::java::util::Map* storedRandSeed {  };
    ::java::util::Map* recorders {  };
protected:
    void ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env) /* throws(Exception) */;

public:
    virtual void printLog(::java::lang::String* arg, ::rice::environment::Environment* env) /* throws(IOException) */;
    static void printTree(::java::util::ArrayList* apps);
    static ::rice::p2p::commonapi::NodeHandle* getRoot(::rice::p2p::commonapi::NodeHandle* seed, ::java::util::Hashtable* appTable);
    static void recursivelyPrintChildren(::rice::p2p::commonapi::NodeHandle* curNode, int32_t recursionDepth, ::java::util::Hashtable* appTable);
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    Recorder(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env);
protected:
    Recorder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class Recorder_Recorder_1;
    friend class Recorder_Recorder_1_getBootstrapper_1_1;
    friend class Recorder_Recorder_2;
    friend class Recorder_AppInvokation;
    friend class Recorder_SubscribeInvokation;
    friend class Recorder_PublishInvokation;
};
