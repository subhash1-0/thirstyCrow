// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Spliterator.hpp>

struct default_init_tag;

class java::util::Collections_UnmodifiableMap_UnmodifiableEntrySet_UnmodifiableEntrySetSpliterator final
    : public virtual ::java::lang::Object
    , public Spliterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    Spliterator* s {  };

protected:
    void ctor(Spliterator* arg0);

public:
    int32_t characteristics() override;
    int64_t estimateSize() override;
    void forEachRemaining(::java::util::function::Consumer* arg0) override;
    Comparator* getComparator() override;
    int64_t getExactSizeIfKnown() override;
    bool hasCharacteristics(int32_t arg0) override;
    bool tryAdvance(::java::util::function::Consumer* arg0) override;
    Spliterator* trySplit() override;

    // Generated

public: /* package */
    Collections_UnmodifiableMap_UnmodifiableEntrySet_UnmodifiableEntrySetSpliterator(Spliterator* arg0);
protected:
    Collections_UnmodifiableMap_UnmodifiableEntrySet_UnmodifiableEntrySetSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
