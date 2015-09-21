// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::lang::Class_AnnotationData
    : public virtual Object
{

public:
    typedef Object super;

public: /* package */
    ::java::util::Map* annotations {  };
    ::java::util::Map* declaredAnnotations {  };
    int32_t redefinedCount {  };

protected:
    void ctor(::java::util::Map* arg0, ::java::util::Map* arg1, int32_t arg2);

    // Generated

public: /* package */
    Class_AnnotationData(::java::util::Map* arg0, ::java::util::Map* arg1, int32_t arg2);
protected:
    Class_AnnotationData(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
