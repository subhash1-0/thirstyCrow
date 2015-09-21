// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractCollection.hpp>
#include <java/util/Set.hpp>

struct default_init_tag;

class java::util::AbstractSet
    : public AbstractCollection
    , public virtual Set
{

public:
    typedef AbstractCollection super;

protected:
    void ctor();

public:
    bool equals(::java::lang::Object* arg0) override;
    int32_t hashCode() override;
    bool removeAll(Collection* arg0) override;

    // Generated

public: /* protected */
    AbstractSet();
protected:
    AbstractSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool add(::java::lang::Object* arg0);
    bool addAll(Collection* arg0);
    void clear();
    bool contains(::java::lang::Object* arg0);
    bool containsAll(Collection* arg0);
    bool isEmpty();
    bool remove(::java::lang::Object* arg0);
    bool retainAll(Collection* arg0);
    ::java::lang::ObjectArray* toArray_();
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
