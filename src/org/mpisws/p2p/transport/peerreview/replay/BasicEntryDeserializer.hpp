// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/BasicEntryDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/reader/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/reader/EntryDeserializer.hpp>

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

class org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
    , public virtual ::org::mpisws::p2p::transport::peerreview::history::reader::EntryDeserializer
{

public:
    typedef ::java::lang::Object super;
    ::java::lang::String* entryId(int16_t id) override;
    ::java::lang::String* read(::org::mpisws::p2p::transport::peerreview::history::IndexEntry* ie, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history) /* throws(IOException) */ override;
    static void printLog(::java::lang::String* name, ::org::mpisws::p2p::transport::peerreview::history::reader::EntryDeserializer* deserializer, ::rice::environment::Environment* env) /* throws(IOException) */;
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    BasicEntryDeserializer();
protected:
    BasicEntryDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
