// Generated from /pastry-2.1/src/rice/pastry/IdRange.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::pastry::IdRange
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::IdRange
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-361018850912613915LL) };
    bool empty {  };
    Id* ccw {  };
    Id* cw {  };
protected:
    void ctor(Id* ccw, Id* cw);
    void ctor();
    void ctor(bool type);
    void ctor(::rice::pastry::IdRange* o);

public:
    int32_t hashCode() override;
    bool equals(::java::lang::Object* obj) override;

private:
    Id_Distance* size();

public:
    bool isEmpty() override;
    virtual bool isFull();
    virtual bool isAdjacent(::rice::pastry::IdRange* o);
    virtual bool contains(Id* key);
    virtual Id* getCCW();
    virtual Id* getCW();
    virtual ::rice::pastry::IdRange* merge(::rice::pastry::IdRange* o);
    virtual ::rice::pastry::IdRange* complement();
    virtual ::rice::pastry::IdRange* intersect(::rice::pastry::IdRange* o);
    virtual ::rice::pastry::IdRange* diff(::rice::pastry::IdRange* o);
    virtual ::rice::pastry::IdRange* subtract(::rice::pastry::IdRange* o, bool cwPart);
    virtual ::rice::pastry::IdRange* ccwHalf();
    virtual ::rice::pastry::IdRange* cwHalf();
    ::java::lang::String* toString() override;
    bool containsId(::rice::p2p::commonapi::Id* key) override;
    ::rice::p2p::commonapi::Id* getCCWId() override;
    ::rice::p2p::commonapi::Id* getCWId() override;
    ::rice::p2p::commonapi::IdRange* getComplementRange() override;
    ::rice::p2p::commonapi::IdRange* mergeRange(::rice::p2p::commonapi::IdRange* range) override;
    ::rice::p2p::commonapi::IdRange* diffRange(::rice::p2p::commonapi::IdRange* range) override;
    ::rice::p2p::commonapi::IdRange* intersectRange(::rice::p2p::commonapi::IdRange* range) override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    IdRange(Id* ccw, Id* cw);
    IdRange();
    IdRange(bool type);
    IdRange(::rice::pastry::IdRange* o);
    IdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    IdRange(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
