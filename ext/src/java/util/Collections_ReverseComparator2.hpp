// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_ReverseComparator2
    : public virtual ::java::lang::Object
    , public virtual Comparator
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static bool $assertionsDisabled_;

public: /* package */
    Comparator* cmp {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(4374092139857LL) };

protected:
    void ctor(Comparator* arg0);

public:
    int32_t compare(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    bool equals(::java::lang::Object* arg0) override;
    int32_t hashCode() override;
    Comparator* reversed() override;

    // Generated

public: /* package */
    Collections_ReverseComparator2(Comparator* arg0);
protected:
    Collections_ReverseComparator2(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static bool& $assertionsDisabled();

private:
    virtual ::java::lang::Class* getClass0();
};
