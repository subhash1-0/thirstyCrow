// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::util::Observable
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    bool changed {  };
    Vector* obs {  };

protected:
    void ctor();

public:
    virtual void addObserver(Observer* arg0);

public: /* protected */
    virtual void clearChanged();

public:
    virtual int32_t countObservers();
    virtual void deleteObserver(Observer* arg0);
    virtual void deleteObservers();
    virtual bool hasChanged();
    virtual void notifyObservers();
    virtual void notifyObservers(::java::lang::Object* arg0);

public: /* protected */
    virtual void setChanged();

    // Generated

public:
    Observable();
protected:
    Observable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
