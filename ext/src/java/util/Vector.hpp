// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractList.hpp>
#include <java/util/List.hpp>
#include <java/util/RandomAccess.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Vector
    : public AbstractList
    , public virtual List
    , public virtual RandomAccess
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractList super;

private:
    static constexpr int32_t MAX_ARRAY_SIZE { int32_t(2147483639) };

public: /* protected */
    int32_t capacityIncrement {  };
    int32_t elementCount {  };
    ::java::lang::ObjectArray* elementData_ {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(-2767605614048989439LL) };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(Collection* arg0);
    void ctor(int32_t arg0, int32_t arg1);

public:
    bool add(::java::lang::Object* arg0) override;
    void add(int32_t arg0, ::java::lang::Object* arg1) override;
    bool addAll(Collection* arg0) override;
    bool addAll(int32_t arg0, Collection* arg1) override;
    virtual void addElement(::java::lang::Object* arg0);
    virtual int32_t capacity();
    void clear() override;
    ::java::lang::Object* clone() override;
    bool contains(::java::lang::Object* arg0) override;
    bool containsAll(Collection* arg0) override;
    virtual void copyInto(::java::lang::ObjectArray* arg0);
    virtual ::java::lang::Object* elementAt(int32_t arg0);

public: /* package */
    virtual ::java::lang::Object* elementData(int32_t arg0);

public:
    virtual Enumeration* elements();
    virtual void ensureCapacity(int32_t arg0);
    /*void ensureCapacityHelper(int32_t arg0); (private) */
    bool equals(::java::lang::Object* arg0) override;
    virtual ::java::lang::Object* firstElement();
    void forEach(::java::util::function::Consumer* arg0) override;
    ::java::lang::Object* get(int32_t arg0) override;
    /*void grow(int32_t arg0); (private) */
    int32_t hashCode() override;
    /*static int32_t hugeCapacity(int32_t arg0); (private) */
    int32_t indexOf(::java::lang::Object* arg0) override;
    virtual int32_t indexOf(::java::lang::Object* arg0, int32_t arg1);
    virtual void insertElementAt(::java::lang::Object* arg0, int32_t arg1);
    bool isEmpty() override;
    Iterator* iterator() override;
    virtual ::java::lang::Object* lastElement();
    int32_t lastIndexOf(::java::lang::Object* arg0) override;
    virtual int32_t lastIndexOf(::java::lang::Object* arg0, int32_t arg1);
    ListIterator* listIterator() override;
    ListIterator* listIterator(int32_t arg0) override;
    bool remove(::java::lang::Object* arg0) override;
    ::java::lang::Object* remove(int32_t arg0) override;
    bool removeAll(Collection* arg0) override;
    virtual void removeAllElements();
    virtual bool removeElement(::java::lang::Object* arg0);
    virtual void removeElementAt(int32_t arg0);
    bool removeIf(::java::util::function::Predicate* arg0) override;

public: /* protected */
    void removeRange(int32_t arg0, int32_t arg1) override;

public:
    void replaceAll(::java::util::function::UnaryOperator* arg0) override;
    bool retainAll(Collection* arg0) override;
    ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) override;
    virtual void setElementAt(::java::lang::Object* arg0, int32_t arg1);
    virtual void setSize(int32_t arg0);
    int32_t size() override;
    void sort(Comparator* arg0) override;
    Spliterator* spliterator() override;
    List* subList(int32_t arg0, int32_t arg1) override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;
    ::java::lang::String* toString() override;
    virtual void trimToSize();
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    Vector();
    Vector(int32_t arg0);
    Vector(Collection* arg0);
    Vector(int32_t arg0, int32_t arg1);
protected:
    Vector(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
