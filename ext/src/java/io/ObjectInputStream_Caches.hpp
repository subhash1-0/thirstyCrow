// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::io::ObjectInputStream_Caches
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::util::concurrent::ConcurrentMap* subclassAudits_;
    static ::java::lang::ref::ReferenceQueue* subclassAuditsQueue_;

    /*void ctor(); (private) */

    // Generated

public:
    ObjectInputStream_Caches();
protected:
    ObjectInputStream_Caches(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static ::java::util::concurrent::ConcurrentMap*& subclassAudits();
    static ::java::lang::ref::ReferenceQueue*& subclassAuditsQueue();

private:
    virtual ::java::lang::Class* getClass0();
};
