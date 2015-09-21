// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractCollection.hpp>

struct default_init_tag;

class java::util::HashMap_Values final
    : public AbstractCollection
{

public:
    typedef AbstractCollection super;

public: /* package */
    HashMap* this$0 {  };

protected:
    void ctor();

public:
    void clear() override;
    bool contains(::java::lang::Object* arg0) override;
    void forEach(::java::util::function::Consumer* arg0) override;
    Iterator* iterator() override;
    int32_t size() override;
    Spliterator* spliterator() override;

    // Generated

public: /* package */
    HashMap_Values(HashMap *HashMap_this);
protected:
    HashMap_Values(HashMap *HashMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    HashMap *HashMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
