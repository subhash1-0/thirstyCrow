// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSequentialList.hpp>
#include <java/util/List.hpp>
#include <java/util/Deque.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::LinkedList
    : public AbstractSequentialList
    , public virtual List
    , public virtual Deque
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractSequentialList super;

public: /* package */
    LinkedList_Node* first {  };
    LinkedList_Node* last {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(876323262645176354LL) };

public: /* package */
    int32_t size_ {  };

protected:
    void ctor();
    void ctor(Collection* arg0);

public:
    bool add(::java::lang::Object* arg0) override;
    void add(int32_t arg0, ::java::lang::Object* arg1) override;
    bool addAll(Collection* arg0) override;
    bool addAll(int32_t arg0, Collection* arg1) override;
    void addFirst(::java::lang::Object* arg0) override;
    void addLast(::java::lang::Object* arg0) override;
    /*void checkElementIndex(int32_t arg0); (private) */
    /*void checkPositionIndex(int32_t arg0); (private) */
    void clear() override;
    ::java::lang::Object* clone() override;
    bool contains(::java::lang::Object* arg0) override;
    Iterator* descendingIterator() override;
    ::java::lang::Object* element() override;
    ::java::lang::Object* get(int32_t arg0) override;
    ::java::lang::Object* getFirst() override;
    ::java::lang::Object* getLast() override;
    int32_t indexOf(::java::lang::Object* arg0) override;
    /*bool isElementIndex(int32_t arg0); (private) */
    /*bool isPositionIndex(int32_t arg0); (private) */
    int32_t lastIndexOf(::java::lang::Object* arg0) override;

public: /* package */
    virtual void linkBefore(::java::lang::Object* arg0, LinkedList_Node* arg1);
    /*void linkFirst(::java::lang::Object* arg0); (private) */
    virtual void linkLast(::java::lang::Object* arg0);

public:
    ListIterator* listIterator(int32_t arg0) override;

public: /* package */
    virtual LinkedList_Node* node(int32_t arg0);

public:
    bool offer(::java::lang::Object* arg0) override;
    bool offerFirst(::java::lang::Object* arg0) override;
    bool offerLast(::java::lang::Object* arg0) override;
    /*::java::lang::String* outOfBoundsMsg(int32_t arg0); (private) */
    ::java::lang::Object* peek() override;
    ::java::lang::Object* peekFirst() override;
    ::java::lang::Object* peekLast() override;
    ::java::lang::Object* poll() override;
    ::java::lang::Object* pollFirst() override;
    ::java::lang::Object* pollLast() override;
    ::java::lang::Object* pop() override;
    void push(::java::lang::Object* arg0) override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    ::java::lang::Object* remove() override;
    bool remove(::java::lang::Object* arg0) override;
    ::java::lang::Object* remove(int32_t arg0) override;
    ::java::lang::Object* removeFirst() override;
    bool removeFirstOccurrence(::java::lang::Object* arg0) override;
    ::java::lang::Object* removeLast() override;
    bool removeLastOccurrence(::java::lang::Object* arg0) override;
    ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) override;
    int32_t size() override;
    Spliterator* spliterator() override;
    /*LinkedList* superClone(); (private) */
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;

public: /* package */
    virtual ::java::lang::Object* unlink(LinkedList_Node* arg0);
    /*::java::lang::Object* unlinkFirst(LinkedList_Node* arg0); (private) */
    /*::java::lang::Object* unlinkLast(LinkedList_Node* arg0); (private) */
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated

public:
    LinkedList();
    LinkedList(Collection* arg0);
protected:
    LinkedList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool containsAll(Collection* arg0);
    bool equals(::java::lang::Object* arg0);
    int32_t hashCode();
    bool isEmpty();
    Iterator* iterator();
    virtual ListIterator* listIterator();
    bool removeAll(Collection* arg0);
    bool retainAll(Collection* arg0);
    virtual List* subList(int32_t arg0, int32_t arg1);

private:
    virtual ::java::lang::Class* getClass0();
};
