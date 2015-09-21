// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/FragmentMetadata.java
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::FragmentMetadata::FragmentMetadata(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::FragmentMetadata::FragmentMetadata(int64_t currentExpirationDate, int64_t previousExpirationDate, int64_t storedSince) 
    : FragmentMetadata(*static_cast< ::default_init_tag* >(0))
{
    ctor(currentExpirationDate,previousExpirationDate,storedSince);
}

constexpr int64_t rice::p2p::glacier::v2::FragmentMetadata::serialVersionUID;

void rice::p2p::glacier::v2::FragmentMetadata::ctor(int64_t currentExpirationDate, int64_t previousExpirationDate, int64_t storedSince)
{
    super::ctor();
    this->currentExpirationDate = currentExpirationDate;
    this->previousExpirationDate = previousExpirationDate;
    this->storedSince = storedSince;
}

int64_t rice::p2p::glacier::v2::FragmentMetadata::getCurrentExpiration()
{
    return currentExpirationDate;
}

int64_t rice::p2p::glacier::v2::FragmentMetadata::getPreviousExpiration()
{
    return previousExpirationDate;
}

int64_t rice::p2p::glacier::v2::FragmentMetadata::getStoredSince()
{
    return storedSince;
}

int32_t rice::p2p::glacier::v2::FragmentMetadata::compareTo(FragmentMetadata* object)
{
    auto metadata = java_cast< FragmentMetadata* >(object);
    if(npc(metadata)->currentExpirationDate > currentExpirationDate)
        return -int32_t(1);
    else if(npc(metadata)->currentExpirationDate < currentExpirationDate)
        return 1;
    else if(npc(metadata)->previousExpirationDate < previousExpirationDate)
        return -int32_t(1);
    else if(npc(metadata)->previousExpirationDate > previousExpirationDate)
        return 1;
    else if(npc(metadata)->storedSince < storedSince)
        return -int32_t(1);
    else if(npc(metadata)->storedSince > storedSince)
        return 1;
    else
        return 0;
}

int32_t rice::p2p::glacier::v2::FragmentMetadata::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< FragmentMetadata* >(o));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::FragmentMetadata::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.FragmentMetadata", 36);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::FragmentMetadata::getClass0()
{
    return class_();
}

