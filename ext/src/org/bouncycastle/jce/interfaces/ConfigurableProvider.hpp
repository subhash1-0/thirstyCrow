// Generated from /pastry-2.1/lib/bouncycastle.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/jce/interfaces/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::bouncycastle::jce::interfaces::ConfigurableProvider
    : public virtual ::java::lang::Object
{

private:
    static ::java::lang::String* EC_IMPLICITLY_CA_;
    static ::java::lang::String* THREAD_LOCAL_EC_IMPLICITLY_CA_;


public:
    virtual void setParameter(::java::lang::String* arg0, ::java::lang::Object* arg1) = 0;

    // Generated
    static ::java::lang::Class *class_();
    static ::java::lang::String*& EC_IMPLICITLY_CA();
    static ::java::lang::String*& THREAD_LOCAL_EC_IMPLICITLY_CA();
};
