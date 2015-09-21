// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/FragmentMetadata.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::FragmentMetadata
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(3380538644355999384LL) };

public: /* protected */
    int64_t currentExpirationDate {  };
    int64_t previousExpirationDate {  };
    int64_t storedSince {  };
protected:
    void ctor(int64_t currentExpirationDate, int64_t previousExpirationDate, int64_t storedSince);

public: /* package */
    virtual int64_t getCurrentExpiration();
    virtual int64_t getPreviousExpiration();
    virtual int64_t getStoredSince();

public:
    virtual int32_t compareTo(FragmentMetadata* object);

    // Generated
    FragmentMetadata(int64_t currentExpirationDate, int64_t previousExpirationDate, int64_t storedSince);
protected:
    FragmentMetadata(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
};
