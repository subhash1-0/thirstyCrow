// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdRange.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringIdRange
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::IdRange
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::IdRange* range {  };
    ::rice::p2p::commonapi::Id* ringId {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdRange* range);

public: /* protected */
    virtual ::rice::p2p::commonapi::IdRange* getRange();

public:
    bool containsId(::rice::p2p::commonapi::Id* key) override;
    ::rice::p2p::commonapi::Id* getCCWId() override;
    ::rice::p2p::commonapi::Id* getCWId() override;
    ::rice::p2p::commonapi::IdRange* getComplementRange() override;
    ::rice::p2p::commonapi::IdRange* mergeRange(::rice::p2p::commonapi::IdRange* merge) override;
    ::rice::p2p::commonapi::IdRange* diffRange(::rice::p2p::commonapi::IdRange* diff) override;
    ::rice::p2p::commonapi::IdRange* intersectRange(::rice::p2p::commonapi::IdRange* intersect) override;
    bool isEmpty() override;
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;
    ::java::lang::String* toString() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated

public: /* protected */
    MultiringIdRange(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdRange* range);

public:
    MultiringIdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    MultiringIdRange(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
