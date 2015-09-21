// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::lang::ClassLoader_ParallelLoaders
    : public virtual Object
{

public:
    typedef Object super;

private:
    static ::java::util::Set* loaderTypes_;

    /*void ctor(); (private) */

public: /* package */
    static bool isRegistered(Class* arg0);
    static bool register_(Class* arg0);

    // Generated

public:
    ClassLoader_ParallelLoaders();
protected:
    ClassLoader_ParallelLoaders(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::util::Set*& loaderTypes();
    virtual ::java::lang::Class* getClass0();
};
