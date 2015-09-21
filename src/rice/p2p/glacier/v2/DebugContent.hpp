// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/DebugContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::DebugContent
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::past::gc::GCPastContent
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Id* myId {  };
    bool isMutable_ {  };
    int64_t version {  };
    ::int8_tArray* payload {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* id, bool isMutable, int64_t version, ::int8_tArray* payload);

public:
    ::rice::p2p::past::PastContent* checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */ override;
    int64_t getVersion() override;
    ::rice::p2p::past::PastContentHandle* getHandle(::rice::p2p::past::Past* local) override;
    ::rice::p2p::past::gc::GCPastContentHandle* getHandle(::rice::p2p::past::gc::GCPast* local, int64_t expiration) override;
    ::rice::p2p::commonapi::Id* getId() override;
    bool isMutable() override;
    virtual ::int8_tArray* getPayload();

private:
    void writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */;
    void readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */;

public:
    ::rice::p2p::past::gc::GCPastMetadata* getMetadata(int64_t expiration) override;

    // Generated
    DebugContent(::rice::p2p::commonapi::Id* id, bool isMutable, int64_t version, ::int8_tArray* payload);
protected:
    DebugContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
