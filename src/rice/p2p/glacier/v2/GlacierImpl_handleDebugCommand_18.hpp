// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

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

class rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_18
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::glacier::FragmentKey* currentKey {  };
    int32_t totalChecks {  }, totalFailures {  };

public:
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;
    virtual void advance();

    // Generated
    GlacierImpl_handleDebugCommand_18(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::FragmentKey* thisKey, ::java::lang::StringBuffer* result, ::java::util::Iterator* iter, ::java::lang::StringArray* ret);
    static ::java::lang::Class *class_();

private:
    void init();
    GlacierImpl *GlacierImpl_this;
    ::rice::p2p::glacier::FragmentKey* thisKey;
    ::java::lang::StringBuffer* result;
    ::java::util::Iterator* iter;
    ::java::lang::StringArray* ret;
    virtual ::java::lang::Class* getClass0();
    friend class GlacierImpl;
    friend class GlacierImpl_GlacierImpl_1;
    friend class GlacierImpl_startup_2;
    friend class GlacierImpl_startup_2_timeoutExpired_2_1;
    friend class GlacierImpl_startup_2_timeoutExpired_2_1_receiveResult_2_1_1;
    friend class GlacierImpl_startup_3;
    friend class GlacierImpl_startup_3_receiveResult_3_1;
    friend class GlacierImpl_startup_3_receiveResult_3_2;
    friend class GlacierImpl_startup_4;
    friend class GlacierImpl_startup_4_receiveResult_4_1;
    friend class GlacierImpl_startup_4_receiveResult_4_2;
    friend class GlacierImpl_startup_4_receiveResult_4_3;
    friend class GlacierImpl_startup_5;
    friend class GlacierImpl_startup_5_timeoutExpired_5_1;
    friend class GlacierImpl_startup_6;
    friend class GlacierImpl_startup_6_timeoutExpired_6_1;
    friend class GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1;
    friend class GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1;
    friend class GlacierImpl_startup_7;
    friend class GlacierImpl_startup_8;
    friend class GlacierImpl_deleteFragment_9;
    friend class GlacierImpl_deleteFragment_9_receiveResult_9_1;
    friend class GlacierImpl_handleDebugCommand_10;
    friend class GlacierImpl_handleDebugCommand_11;
    friend class GlacierImpl_handleDebugCommand_12;
    friend class GlacierImpl_handleDebugCommand_13;
    friend class GlacierImpl_handleDebugCommand_13_receiveResult_13_1;
    friend class GlacierImpl_handleDebugCommand_14;
    friend class GlacierImpl_handleDebugCommand_15;
    friend class GlacierImpl_handleDebugCommand_16;
    friend class GlacierImpl_handleDebugCommand_17;
    friend class GlacierImpl_handleDebugCommand_19;
    friend class GlacierImpl_refresh_20;
    friend class GlacierImpl_refresh_20_receiveResult_20_1;
    friend class GlacierImpl_refresh_21;
    friend class GlacierImpl_distribute_22;
    friend class GlacierImpl_insert_23;
    friend class GlacierImpl_insert_24;
    friend class GlacierImpl_insert_24_receiveResult_24_1;
    friend class GlacierImpl_insert_24_receiveResult_24_2;
    friend class GlacierImpl_neighborSeen_25;
    friend class GlacierImpl_neighborSeen_25_receiveResult_25_1;
    friend class GlacierImpl_lookupHandles_26;
    friend class GlacierImpl_retrieveManifest_27;
    friend class GlacierImpl_retrieveObject_28;
    friend class GlacierImpl_retrieveFragment_29;
    friend class GlacierImpl_retrieveFragment_29_receiveResult_29_1;
    friend class GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1;
    friend class GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_1;
    friend class GlacierImpl_retrieveFragment_29_receiveResult_29_1_timeoutExpired_29_1_1_receiveResult_29_1_1_2;
    friend class GlacierImpl_retrieveFragment_30;
    friend class GlacierImpl_rateLimitedRetrieveFragment_31;
    friend class GlacierImpl_deliver_32;
    friend class GlacierImpl_deliver_33;
    friend class GlacierImpl_deliver_34;
    friend class GlacierImpl_deliver_35;
    friend class GlacierImpl_deliver_36;
    friend class GlacierImpl_deliver_37;
    friend class GlacierImpl_deliver_37_receiveResult_37_1;
    friend class GlacierImpl_deliver_38;
    friend class GlacierImpl_deliver_38_receiveResult_38_1;
};
