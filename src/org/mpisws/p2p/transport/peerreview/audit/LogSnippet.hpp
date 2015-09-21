// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/LogSnippet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::audit::LogSnippet
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::int8_tArray* baseHash {  };

public:
    ::java::util::List* entries {  };
protected:
    void ctor(::int8_tArray* baseHash, ::java::util::List* entries);

public:
    ::java::lang::String* toString() override;
    bool equals(::java::lang::Object* o) override;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize) /* throws(IOException) */;

public:
    virtual ::int8_tArray* getBaseHash();
    virtual int64_t getFirstSeq();
    virtual ::java::lang::Object* getExtInfo();
    virtual bool checkHashChainContains(::int8_tArray* keyNodeHash, int64_t keyNodeSeq, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* transport, ::rice::environment::logging::Logger* logger);

    // Generated
    LogSnippet(::int8_tArray* baseHash, ::java::util::List* entries);
    LogSnippet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize);
protected:
    LogSnippet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
