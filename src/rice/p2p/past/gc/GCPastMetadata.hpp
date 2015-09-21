// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastMetadata.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCPastMetadata
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-2432306227012003387LL) };

public: /* protected */
    int64_t expiration {  };
protected:
    void ctor(int64_t expiration);

public:
    virtual int64_t getExpiration();
    virtual GCPastMetadata* setExpiration(int64_t expiration);
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;
    virtual int32_t compareTo(GCPastMetadata* other);
    ::java::lang::String* toString() override;

private:
    void readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */;

    // Generated

public:
    GCPastMetadata(int64_t expiration);
protected:
    GCPastMetadata(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
};
