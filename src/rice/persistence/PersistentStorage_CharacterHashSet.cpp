// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_CharacterHashSet.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/persistence/PersistentStorage.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::PersistentStorage_CharacterHashSet::PersistentStorage_CharacterHashSet(PersistentStorage *PersistentStorage_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
{
    clinit();
}

rice::persistence::PersistentStorage_CharacterHashSet::PersistentStorage_CharacterHashSet(PersistentStorage *PersistentStorage_this)
    : PersistentStorage_CharacterHashSet(PersistentStorage_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::persistence::PersistentStorage_CharacterHashSet::ctor()
{
    super::ctor();
    init();
}

void rice::persistence::PersistentStorage_CharacterHashSet::init()
{
    bitMap = new ::boolArray(int32_t(256));
}

void rice::persistence::PersistentStorage_CharacterHashSet::put(char16_t a)
{
    (*bitMap)[static_cast< int32_t >(a)] = true;
}

bool rice::persistence::PersistentStorage_CharacterHashSet::contains(char16_t a)
{
    return (*bitMap)[static_cast< int32_t >(a)];
}

void rice::persistence::PersistentStorage_CharacterHashSet::remove(char16_t a)
{
    (*bitMap)[static_cast< int32_t >(a)] = false;
}

char16_tArray* rice::persistence::PersistentStorage_CharacterHashSet::get()
{
    auto nums = getOffsets();
    auto result = new ::char16_tArray(npc(nums)->length);
    for (auto i = int32_t(0); i < npc(result)->length; i++) 
                (*result)[i] = static_cast< char16_t >((*nums)[i]);

    return result;
}

int32_tArray* rice::persistence::PersistentStorage_CharacterHashSet::getOffsets()
{
    auto result = new ::int32_tArray(count());
    auto index = int32_t(0);
    for (auto i = int32_t(0); i < npc(result)->length; i++) 
                (*result)[i] = getOffset(i);

    return result;
}

int32_t rice::persistence::PersistentStorage_CharacterHashSet::getOffset(int32_t index)
{
    auto location = int32_t(0);
    while (index > 0) {
        if((*bitMap)[location])
            index--;

        location++;
    }
    while (!(*bitMap)[location]) 
                location++;

    return location;
}

int32_t rice::persistence::PersistentStorage_CharacterHashSet::count()
{
    auto total = int32_t(0);
    for (auto i = int32_t(0); i < npc(bitMap)->length; i++) 
                if((*bitMap)[i])
            total++;


    return total;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_CharacterHashSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.PersistentStorage.CharacterHashSet", 51);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_CharacterHashSet::getClass0()
{
    return class_();
}

