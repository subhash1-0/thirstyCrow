// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/TreeMap_TreeMapSpliterator.hpp>
#include <java/util/Spliterator.hpp>

struct default_init_tag;

class java::util::TreeMap_DescendingKeySpliterator final
    : public TreeMap_TreeMapSpliterator
    , public Spliterator
{

public:
    typedef TreeMap_TreeMapSpliterator super;

protected:
    void ctor(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5);

public:
    int32_t characteristics() override;
    void forEachRemaining(::java::util::function::Consumer* arg0) override;
    bool tryAdvance(::java::util::function::Consumer* arg0) override;
    TreeMap_DescendingKeySpliterator* trySplit() override;

    // Generated

public: /* package */
    TreeMap_DescendingKeySpliterator(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5);
protected:
    TreeMap_DescendingKeySpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int64_t estimateSize();

private:
    virtual ::java::lang::Class* getClass0();
};
