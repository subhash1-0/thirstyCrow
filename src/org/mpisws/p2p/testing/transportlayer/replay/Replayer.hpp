// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Replayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyEvents.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/EventCallback.hpp>

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

class org::mpisws::p2p::testing::transportlayer::replay::Replayer
    : public virtual ::java::lang::Object
    , public virtual MyEvents
    , public virtual ::org::mpisws::p2p::transport::peerreview::replay::EventCallback
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::net::InetSocketAddress* bootaddress {  };
    ::rice::pastry::PastryNode* node {  };
    MyScribeClient* app {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* bootaddress, int64_t startTime, int64_t randSeed) /* throws(Exception) */;

public:
    static void replayNode(::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* bootaddress, int64_t startTime, int64_t randSeed) /* throws(Exception) */;
    static void printLog(::java::lang::String* arg, ::rice::environment::Environment* env) /* throws(IOException) */;
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;
    void replayEvent(int16_t type, ::rice::p2p::commonapi::rawserialization::InputBuffer* entry) override;

    // Generated
    Replayer(::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* bootaddress, int64_t startTime, int64_t randSeed);
protected:
    Replayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Replayer_Replayer_1;
    friend class Replayer_Replayer_2;
};
