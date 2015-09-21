// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractCollection.hpp>
#include <java/util/Queue.hpp>

struct default_init_tag;

class java::util::AbstractQueue
    : public AbstractCollection
    , public virtual Queue
{

public:
    typedef AbstractCollection super;

protected:
    void ctor();

public:
    bool add(::java::lang::Object* arg0) override;
    bool addAll(Collection* arg0) override;
    void clear() override;
    ::java::lang::Object* element() override;
    ::java::lang::Object* remove() override;

    // Generated

public: /* protected */
    AbstractQueue();
protected:
    AbstractQueue(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool contains(::java::lang::Object* arg0);
    virtual bool containsAll(Collection* arg0);
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();
    virtual bool isEmpty();
    virtual bool remove(::java::lang::Object* arg0);
    virtual bool removeAll(Collection* arg0);
    virtual bool retainAll(Collection* arg0);
    virtual ::java::lang::ObjectArray* toArray_();
    virtual ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
