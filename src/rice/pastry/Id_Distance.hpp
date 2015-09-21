// Generated from /pastry-2.1/src/rice/pastry/Id.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>

struct default_init_tag;

class rice::pastry::Id_Distance
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Id_Distance
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(5464763824924998962LL) };
    ::int32_tArray* difference {  };
protected:
    void ctor();
    void ctor(::int8_tArray* diff);
    void ctor(::int32_tArray* diff);

public:
    virtual void blit(::int8_tArray* target);
    virtual void blit(::int8_tArray* target, int32_t offset);
    virtual ::int8_tArray* copy();
    virtual int32_t compareTo(::rice::p2p::commonapi::Id_Distance* obj);
    bool equals(::java::lang::Object* obj) override;
    virtual ::rice::pastry::Id_Distance* shift(int32_t cnt, int32_t fill);
    virtual ::rice::pastry::Id_Distance* shift(int32_t cnt, int32_t fill, bool roundUp);
    int32_t hashCode() override;
    ::java::lang::String* toString() override;
    ::rice::p2p::commonapi::Id_Distance* shiftDistance(int32_t cnt, int32_t fill) override;

private:
    void inc();

    // Generated

public:
    Id_Distance();
    Id_Distance(::int8_tArray* diff);
    Id_Distance(::int32_tArray* diff);
protected:
    Id_Distance(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* arg0) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Id;
};
