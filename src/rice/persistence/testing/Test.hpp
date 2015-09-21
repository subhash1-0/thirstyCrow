// Generated from /pastry-2.1/src/rice/persistence/testing/Test.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/persistence/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::persistence::testing::Test
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* SUCCESS_;
    static ::java::lang::String* FAILURE_;

public: /* protected */
    static constexpr int32_t PAD_SIZE { int32_t(60) };

public:
    virtual void start() = 0;

public: /* protected */
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::environment::Environment* env);

public: /* protected */
    virtual void sectionStart(::java::lang::String* name);
    virtual void sectionEnd();
    virtual void stepStart(::java::lang::String* name);
    virtual void stepDone(::java::lang::String* status);
    virtual void stepDone(::java::lang::String* status, ::java::lang::String* message);
    virtual void stepException(::java::lang::Exception* e);

private:
    ::java::lang::String* pad(::java::lang::String* start);

    // Generated

public:
    Test(::rice::environment::Environment* env);
protected:
    Test(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

public: /* protected */
    static ::java::lang::String*& SUCCESS();
    static ::java::lang::String*& FAILURE();

private:
    virtual ::java::lang::Class* getClass0();
};
