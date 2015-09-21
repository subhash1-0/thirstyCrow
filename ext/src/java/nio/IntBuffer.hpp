// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/nio/Buffer.hpp>
#include <java/lang/Comparable.hpp>
#include <Array.hpp>

struct default_init_tag;

class java::nio::IntBuffer
    : public Buffer
    , public virtual ::java::lang::Comparable
{

public:
    typedef Buffer super;

public: /* package */
    ::int32_tArray* hb {  };
    bool isReadOnly_ {  };
    int32_t offset {  };

protected:
    void ctor(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3);
    void ctor(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, ::int32_tArray* arg4, int32_t arg5);

public:
    static IntBuffer* allocate(int32_t arg0);
    ::int32_tArray* array() override;
    int32_t arrayOffset() override;
    virtual IntBuffer* asReadOnlyBuffer() = 0;
    virtual IntBuffer* compact() = 0;
    /*static int32_t compare(int32_t arg0, int32_t arg1); (private) */
    virtual int32_t compareTo(IntBuffer* arg0);
    virtual IntBuffer* duplicate() = 0;
    bool equals(::java::lang::Object* arg0) override;
    /*static bool equals(int32_t arg0, int32_t arg1); (private) */
    virtual int32_t get() = 0;
    virtual int32_t get(int32_t arg0) = 0;
    virtual IntBuffer* get(::int32_tArray* arg0);
    virtual IntBuffer* get(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    bool hasArray_() override;
    int32_t hashCode() override;
    bool isDirect() = 0;
    virtual ByteOrder* order() = 0;
    virtual IntBuffer* put(int32_t arg0) = 0;
    virtual IntBuffer* put(IntBuffer* arg0);
    IntBuffer* put(::int32_tArray* arg0);
    virtual IntBuffer* put(int32_t arg0, int32_t arg1) = 0;
    virtual IntBuffer* put(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    virtual IntBuffer* slice() = 0;
    ::java::lang::String* toString() override;
    static IntBuffer* wrap(::int32_tArray* arg0);
    static IntBuffer* wrap(::int32_tArray* arg0, int32_t arg1, int32_t arg2);

    // Generated

public: /* package */
    IntBuffer(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3);
    IntBuffer(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, ::int32_tArray* arg4, int32_t arg5);
protected:
    IntBuffer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* arg0) override;

private:
    virtual ::java::lang::Class* getClass0();
};
