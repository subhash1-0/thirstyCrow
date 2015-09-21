// Generated from /pastry-2.1/src/rice/tutorial/past/PastTutorial.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/tutorial/past/fwd-pastry-2.1.hpp>
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
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::Boolean, ObjectArray, ::java::io::SerializableArray, ComparableArray > BooleanArray;
    } // lang
} // java

struct default_init_tag;

class rice::tutorial::past::PastTutorial_PastTutorial_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::java::lang::BooleanArray* results);
    void receiveException(::java::lang::Exception* result) override;

    // Generated
    PastTutorial_PastTutorial_1(PastTutorial *PastTutorial_this, ::rice::p2p::past::PastContent* myContent);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    PastTutorial *PastTutorial_this;
    ::rice::p2p::past::PastContent* myContent;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastTutorial;
    friend class PastTutorial_PastTutorial_2;
    friend class PastTutorial_PastTutorial_3;
};
