// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Comparable.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::lang::Enum
    : public virtual Object
    , public virtual Comparable
    , public virtual ::java::io::Serializable
{

public:
    typedef Object super;

private:
    String* name_ {  };
    int32_t ordinal_ {  };

protected:
    void ctor(String* arg0, int32_t arg1);

public: /* protected */
    Object* clone() override;

public:
    int32_t compareTo(Enum* arg0);
    bool equals(Object* arg0) override;

public: /* protected */
    void finalize() override;

public:
    Class* getDeclaringClass();
    int32_t hashCode() override;
    String* name();
    int32_t ordinal();
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    /*void readObjectNoData(); (private) */
    String* toString() override;
    static Enum* valueOf(Class* arg0, String* arg1);

    // Generated

public: /* protected */
    Enum(String* arg0, int32_t arg1);
protected:
    Enum(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(Object* arg0) override;

private:
    virtual ::java::lang::Class* getClass0();
};
