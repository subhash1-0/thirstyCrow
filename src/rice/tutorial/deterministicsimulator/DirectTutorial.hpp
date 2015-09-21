// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/DirectTutorial.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/tutorial/deterministicsimulator/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

class rice::tutorial::deterministicsimulator::DirectTutorial
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Vector* apps {  };
protected:
    void ctor(int32_t numNodes, ::rice::environment::Environment* env) /* throws(Exception) */;

public:
    virtual void scheduleBootTask(int32_t numNodes, ::rice::pastry::NodeIdFactory* nidFactory, ::rice::pastry::PastryNodeFactory* factory, ::rice::environment::Environment* env);
    virtual void scheduleDeliveryTask(::rice::pastry::NodeIdFactory* nidFactory, ::rice::environment::Environment* env);
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    DirectTutorial(int32_t numNodes, ::rice::environment::Environment* env);
protected:
    DirectTutorial(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class DirectTutorial_scheduleBootTask_1;
    friend class DirectTutorial_scheduleBootTask_1_run_1_1;
    friend class DirectTutorial_scheduleDeliveryTask_2;
    friend class DirectTutorial_scheduleDeliveryTask_3;
};
