// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::util::Collections
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int32_t BINARYSEARCH_THRESHOLD { int32_t(5000) };
    static constexpr int32_t COPY_THRESHOLD { int32_t(10) };
    static List* EMPTY_LIST_;
    static Map* EMPTY_MAP_;
    static Set* EMPTY_SET_;
    static constexpr int32_t FILL_THRESHOLD { int32_t(25) };
    static constexpr int32_t INDEXOFSUBLIST_THRESHOLD { int32_t(35) };
    static constexpr int32_t REPLACEALL_THRESHOLD { int32_t(11) };
    static constexpr int32_t REVERSE_THRESHOLD { int32_t(18) };
    static constexpr int32_t ROTATE_THRESHOLD { int32_t(100) };
    static constexpr int32_t SHUFFLE_THRESHOLD { int32_t(5) };
    static Random* r_;

    /*void ctor(); (private) */

public:
    static bool addAll(Collection* arg0, ::java::lang::ObjectArray* arg1);
    static Queue* asLifoQueue(Deque* arg0);
    static int32_t binarySearch(List* arg0, ::java::lang::Object* arg1);
    static int32_t binarySearch(List* arg0, ::java::lang::Object* arg1, Comparator* arg2);
    static Collection* checkedCollection(Collection* arg0, ::java::lang::Class* arg1);
    static List* checkedList(List* arg0, ::java::lang::Class* arg1);
    static Map* checkedMap(Map* arg0, ::java::lang::Class* arg1, ::java::lang::Class* arg2);
    static NavigableMap* checkedNavigableMap(NavigableMap* arg0, ::java::lang::Class* arg1, ::java::lang::Class* arg2);
    static NavigableSet* checkedNavigableSet(NavigableSet* arg0, ::java::lang::Class* arg1);
    static Queue* checkedQueue(Queue* arg0, ::java::lang::Class* arg1);
    static Set* checkedSet(Set* arg0, ::java::lang::Class* arg1);
    static SortedMap* checkedSortedMap(SortedMap* arg0, ::java::lang::Class* arg1, ::java::lang::Class* arg2);
    static SortedSet* checkedSortedSet(SortedSet* arg0, ::java::lang::Class* arg1);
    static void copy(List* arg0, List* arg1);
    static bool disjoint(Collection* arg0, Collection* arg1);
    static Enumeration* emptyEnumeration();
    static Iterator* emptyIterator();
    static List* emptyList();
    static ListIterator* emptyListIterator();
    static Map* emptyMap();
    static NavigableMap* emptyNavigableMap();
    static NavigableSet* emptyNavigableSet();
    static Set* emptySet();
    static SortedMap* emptySortedMap();
    static SortedSet* emptySortedSet();
    static Enumeration* enumeration(Collection* arg0);

public: /* package */
    static bool eq(::java::lang::Object* arg0, ::java::lang::Object* arg1);

public:
    static void fill(List* arg0, ::java::lang::Object* arg1);
    static int32_t frequency(Collection* arg0, ::java::lang::Object* arg1);
    /*static ::java::lang::Object* get(ListIterator* arg0, int32_t arg1); (private) */
    static int32_t indexOfSubList(List* arg0, List* arg1);
    /*static int32_t indexedBinarySearch(List* arg0, ::java::lang::Object* arg1); (private) */
    /*static int32_t indexedBinarySearch(List* arg0, ::java::lang::Object* arg1, Comparator* arg2); (private) */
    /*static int32_t iteratorBinarySearch(List* arg0, ::java::lang::Object* arg1); (private) */
    /*static int32_t iteratorBinarySearch(List* arg0, ::java::lang::Object* arg1, Comparator* arg2); (private) */
    static int32_t lastIndexOfSubList(List* arg0, List* arg1);
    static ArrayList* list(Enumeration* arg0);
    static ::java::lang::Object* max(Collection* arg0);
    static ::java::lang::Object* max(Collection* arg0, Comparator* arg1);
    static ::java::lang::Object* min(Collection* arg0);
    static ::java::lang::Object* min(Collection* arg0, Comparator* arg1);
    static List* nCopies(int32_t arg0, ::java::lang::Object* arg1);
    static Set* newSetFromMap(Map* arg0);
    static bool replaceAll(List* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2);
    static void reverse(List* arg0);
    static Comparator* reverseOrder();
    static Comparator* reverseOrder(Comparator* arg0);
    static void rotate(List* arg0, int32_t arg1);
    /*static void rotate1(List* arg0, int32_t arg1); (private) */
    /*static void rotate2(List* arg0, int32_t arg1); (private) */
    static void shuffle(List* arg0);
    static void shuffle(List* arg0, Random* arg1);
    static Set* singleton(::java::lang::Object* arg0);

public: /* package */
    static Iterator* singletonIterator(::java::lang::Object* arg0);

public:
    static List* singletonList(::java::lang::Object* arg0);
    static Map* singletonMap(::java::lang::Object* arg0, ::java::lang::Object* arg1);

public: /* package */
    static Spliterator* singletonSpliterator(::java::lang::Object* arg0);

public:
    static void sort(List* arg0);
    static void sort(List* arg0, Comparator* arg1);
    static void swap(List* arg0, int32_t arg1, int32_t arg2);
    /*static void swap(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2); (private) */
    static Collection* synchronizedCollection(Collection* arg0);

public: /* package */
    static Collection* synchronizedCollection(Collection* arg0, ::java::lang::Object* arg1);

public:
    static List* synchronizedList(List* arg0);

public: /* package */
    static List* synchronizedList(List* arg0, ::java::lang::Object* arg1);

public:
    static Map* synchronizedMap(Map* arg0);
    static NavigableMap* synchronizedNavigableMap(NavigableMap* arg0);
    static NavigableSet* synchronizedNavigableSet(NavigableSet* arg0);
    static Set* synchronizedSet(Set* arg0);

public: /* package */
    static Set* synchronizedSet(Set* arg0, ::java::lang::Object* arg1);

public:
    static SortedMap* synchronizedSortedMap(SortedMap* arg0);
    static SortedSet* synchronizedSortedSet(SortedSet* arg0);
    static Collection* unmodifiableCollection(Collection* arg0);
    static List* unmodifiableList(List* arg0);
    static Map* unmodifiableMap(Map* arg0);
    static NavigableMap* unmodifiableNavigableMap(NavigableMap* arg0);
    static NavigableSet* unmodifiableNavigableSet(NavigableSet* arg0);
    static Set* unmodifiableSet(Set* arg0);
    static SortedMap* unmodifiableSortedMap(SortedMap* arg0);
    static SortedSet* unmodifiableSortedSet(SortedSet* arg0);

public: /* package */
    static ::java::lang::ObjectArray* zeroLengthArray_(::java::lang::Class* arg0);

    // Generated

public:
    Collections();
protected:
    Collections(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static List*& EMPTY_LIST();
    static Map*& EMPTY_MAP();
    static Set*& EMPTY_SET();

private:
    static Random*& r();
    virtual ::java::lang::Class* getClass0();
};
