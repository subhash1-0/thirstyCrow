// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectInputStream.java
#include <rice/p2p/util/XMLObjectInputStream_ValidationList.hpp>

#include <java/io/InvalidObjectException.hpp>
#include <java/io/ObjectInputValidation.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/util/XMLObjectInputStream_ValidationList_Callback.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::XMLObjectInputStream_ValidationList::XMLObjectInputStream_ValidationList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::XMLObjectInputStream_ValidationList::XMLObjectInputStream_ValidationList() 
    : XMLObjectInputStream_ValidationList(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::XMLObjectInputStream_ValidationList::ctor()
{
    super::ctor();
}

void rice::p2p::util::XMLObjectInputStream_ValidationList::register_(::java::io::ObjectInputValidation* obj, int32_t priority) /* throws(InvalidObjectException) */
{
    if(obj == nullptr) {
        throw new ::java::io::InvalidObjectException(u"null callback"_j);
    }
    XMLObjectInputStream_ValidationList_Callback* prev = nullptr;
    auto cur = list;
    while (cur != nullptr && priority < npc(cur)->priority) {
        prev = cur;
        cur = npc(cur)->next;
    }
    if(prev != nullptr) {
        npc(prev)->next = new XMLObjectInputStream_ValidationList_Callback(obj, priority, cur);
    } else {
        list = new XMLObjectInputStream_ValidationList_Callback(obj, priority, list);
    }
}

void rice::p2p::util::XMLObjectInputStream_ValidationList::doCallbacks() /* throws(InvalidObjectException) */
{
    try {
        while (list != nullptr) {
            npc(npc(list)->obj)->validateObject();
            list = npc(list)->next;
        }
    } catch (::java::io::InvalidObjectException* ex) {
        list = nullptr;
        throw ex;
    }
}

void rice::p2p::util::XMLObjectInputStream_ValidationList::clear()
{
    list = nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLObjectInputStream_ValidationList::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLObjectInputStream.ValidationList", 49);
    return c;
}

java::lang::Class* rice::p2p::util::XMLObjectInputStream_ValidationList::getClass0()
{
    return class_();
}

