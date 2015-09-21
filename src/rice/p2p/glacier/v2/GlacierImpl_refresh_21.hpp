// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/GlacierContinuation.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi

        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;
typedef ::SubArray< ::rice::p2p::glacier::VersionKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray, ::java::io::SerializableArray > VersionKeyArray;

            namespace v2
            {
typedef ::SubArray< ::rice::p2p::glacier::v2::Manifest, ::java::lang::ObjectArray, ::java::io::SerializableArray > ManifestArray;
            } // v2
        } // glacier

        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::IdArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > IdArrayArray;
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > NodeHandleArrayArray;
        } // commonapi

        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::FragmentKeyArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > FragmentKeyArrayArray;
        } // glacier
    } // p2p
} // rice

namespace 
{
typedef ::SubArray< ::boolArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > boolArrayArray;
} // 

struct default_init_tag;

class rice::p2p::glacier::v2::GlacierImpl_refresh_21
    : public GlacierContinuation
{

public:
    typedef GlacierContinuation super;

public: /* package */
    int32_t minAcceptable {  };
    ::rice::p2p::glacier::FragmentKeyArrayArray* fragmentKey {  };
    ::rice::p2p::glacier::VersionKeyArray* versionKey {  };
    ::rice::p2p::commonapi::IdArrayArray* fragmentLocation {  };
    ::rice::p2p::commonapi::NodeHandleArrayArray* fragmentHolder {  };
    ::boolArrayArray* fragmentChecked {  };
    ::java::util::Vector* holders {  };
    ManifestArray* manifests {  };
    ::int32_tArray* successes {  };
    bool answered {  };
    int64_t nextTimeout {  };
    int32_t currentStage {  };
    int32_t retriesRemaining {  };
    static constexpr int32_t stageProbing { int32_t(1) };
    static constexpr int32_t stageFetchingManifests { int32_t(2) };
    static constexpr int32_t stagePatching { int32_t(3) };

public:
    ::java::lang::String* toString() override;
    void init_() override;
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;
    void timeoutExpired() override;
    int64_t getTimeout() override;

    // Generated
    GlacierImpl_refresh_21(GlacierImpl *GlacierImpl_this, ::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* versions, ::rice::Continuation* command, ::int64_tArray* expirations);
    static ::java::lang::Class *class_();

private:
    void init();
    GlacierImpl *GlacierImpl_this;
    ::rice::p2p::commonapi::IdArray* ids;
    ::int64_tArray* versions;
    ::rice::Continuation* command;
    ::int64_tArray* expirations;
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
    friend class GlacierImpl_handleDebugCommand_18;
    friend class GlacierImpl_handleDebugCommand_19;
    friend class GlacierImpl_refresh_20;
    friend class GlacierImpl_refresh_20_receiveResult_20_1;
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
