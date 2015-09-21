// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap.hpp>

#include <java/io/IOException.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/CloneNotSupportedException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/InternalError.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Comparator.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map_Entry.hpp>
#include <java/util/Map.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>
#include <java/util/SortedSet.hpp>
#include <rice/p2p/util/RedBlackMap_keySet_1.hpp>
#include <rice/p2p/util/RedBlackMap_values_2.hpp>
#include <rice/p2p/util/RedBlackMap_entrySet_3.hpp>
#include <rice/p2p/util/RedBlackMap_Entry.hpp>
#include <rice/p2p/util/RedBlackMap_SubMap.hpp>
#include <rice/p2p/util/RedBlackMap_SubWrappedMap.hpp>

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

rice::p2p::util::RedBlackMap::RedBlackMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::RedBlackMap::RedBlackMap() 
    : RedBlackMap(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::util::RedBlackMap::RedBlackMap(::java::util::Comparator* c) 
    : RedBlackMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(c);
}

rice::p2p::util::RedBlackMap::RedBlackMap(::java::util::Map* m) 
    : RedBlackMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(m);
}

rice::p2p::util::RedBlackMap::RedBlackMap(::java::util::SortedMap* m) 
    : RedBlackMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(m);
}

void rice::p2p::util::RedBlackMap::init()
{
    comparator_ = nullptr;
    root = nullptr;
    size_ = int32_t(0);
    modCount = int32_t(0);
    entrySet_ = nullptr;
    keySet_ = nullptr;
    values_ = nullptr;
}

void rice::p2p::util::RedBlackMap::incrementSize()
{
    modCount++;
    size_++;
}

void rice::p2p::util::RedBlackMap::decrementSize()
{
    modCount++;
    size_--;
}

void rice::p2p::util::RedBlackMap::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::RedBlackMap::ctor(::java::util::Comparator* c)
{
    super::ctor();
    init();
    this->comparator_ = c;
}

void rice::p2p::util::RedBlackMap::ctor(::java::util::Map* m)
{
    super::ctor();
    init();
    putAll(m);
}

void rice::p2p::util::RedBlackMap::ctor(::java::util::SortedMap* m)
{
    super::ctor();
    init();
    comparator_ = npc(m)->comparator();
    try {
        buildFromSorted(npc(m)->size(), npc(npc(m)->entrySet())->iterator(), nullptr, nullptr);
    } catch (::java::io::IOException* cannotHappen) {
    } catch (::java::lang::ClassNotFoundException* cannotHappen) {
    }
}

int32_t rice::p2p::util::RedBlackMap::size()
{
    return size_;
}

bool rice::p2p::util::RedBlackMap::containsKey(::java::lang::Object* key)
{
    return getEntry(key) != nullptr;
}

bool rice::p2p::util::RedBlackMap::containsValue(::java::lang::Object* value)
{
    return (root == nullptr ? false : (value == nullptr ? valueSearchNull(root) : valueSearchNonNull(root, value)));
}

bool rice::p2p::util::RedBlackMap::valueSearchNull(RedBlackMap_Entry* n)
{
    if(npc(n)->value == nullptr)
        return true;

    return (npc(n)->left != nullptr && valueSearchNull(npc(n)->left)) || (npc(n)->right != nullptr && valueSearchNull(npc(n)->right));
}

bool rice::p2p::util::RedBlackMap::valueSearchNonNull(RedBlackMap_Entry* n, ::java::lang::Object* value)
{
    if(npc(value)->equals(npc(n)->value))
        return true;

    return (npc(n)->left != nullptr && valueSearchNonNull(npc(n)->left, value)) || (npc(n)->right != nullptr && valueSearchNonNull(npc(n)->right, value));
}

java::lang::Object* rice::p2p::util::RedBlackMap::get(::java::lang::Object* key)
{
    auto p = getEntry(key);
    return (p == nullptr ? static_cast< ::java::lang::Object* >(nullptr) : npc(p)->value);
}

java::util::Comparator* rice::p2p::util::RedBlackMap::comparator()
{
    return comparator_;
}

java::lang::Object* rice::p2p::util::RedBlackMap::firstKey()
{
    return key(firstEntry());
}

java::lang::Object* rice::p2p::util::RedBlackMap::lastKey()
{
    return key(lastEntry());
}

void rice::p2p::util::RedBlackMap::putAll(::java::util::Map* map)
{
    auto mapSize = npc(map)->size();
    if(size_ == 0 && mapSize != 0 && dynamic_cast< ::java::util::SortedMap* >(map) != nullptr) {
        auto c = npc((java_cast< ::java::util::SortedMap* >(map)))->comparator();
        if(c == comparator_ || (c != nullptr && npc(c)->equals(static_cast< ::java::lang::Object* >(comparator_)))) {
            ++modCount;
            try {
                buildFromSorted(mapSize, npc(npc(map)->entrySet())->iterator(), nullptr, nullptr);
            } catch (::java::io::IOException* cannotHappen) {
            } catch (::java::lang::ClassNotFoundException* cannotHappen) {
            }
            return;
        }
    }
    super::putAll(static_cast< ::java::util::Map* >(map));
}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::getEntry(::java::lang::Object* key)
{
    auto p = root;
    while (p != nullptr) {
        auto cmp = compare(key, npc(p)->key);
        if(cmp == 0)
            return p;
        else if(cmp < 0)
            p = npc(p)->left;
        else
            p = npc(p)->right;
    }
    return nullptr;
}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::getCeilEntry(::java::lang::Object* key)
{
    auto p = root;
    if(p == nullptr)
        return nullptr;

    while (true) {
        auto cmp = compare(key, npc(p)->key);
        if(cmp == 0) {
            return p;
        } else if(cmp < 0) {
            if(npc(p)->left != nullptr)
                p = npc(p)->left;
            else
                return p;
        } else {
            if(npc(p)->right != nullptr) {
                p = npc(p)->right;
            } else {
                auto parent = npc(p)->parent;
                auto ch = p;
                while (parent != nullptr && ch == npc(parent)->right) {
                    ch = parent;
                    parent = npc(parent)->parent;
                }
                return parent;
            }
        }
    }
}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::getPrecedingEntry(::java::lang::Object* key)
{
    auto p = root;
    if(p == nullptr)
        return nullptr;

    while (true) {
        auto cmp = compare(key, npc(p)->key);
        if(cmp > 0) {
            if(npc(p)->right != nullptr)
                p = npc(p)->right;
            else
                return p;
        } else {
            if(npc(p)->left != nullptr) {
                p = npc(p)->left;
            } else {
                auto parent = npc(p)->parent;
                auto ch = p;
                while (parent != nullptr && ch == npc(parent)->left) {
                    ch = parent;
                    parent = npc(parent)->parent;
                }
                return parent;
            }
        }
    }
}

java::lang::Object* rice::p2p::util::RedBlackMap::key(RedBlackMap_Entry* e)
{
    clinit();
    if(e == nullptr)
        throw new ::java::util::NoSuchElementException();

    return npc(e)->key;
}

java::lang::Object* rice::p2p::util::RedBlackMap::put(::java::lang::Object* key, ::java::lang::Object* value)
{
    auto t = root;
    if(t == nullptr) {
        incrementSize();
        root = new RedBlackMap_Entry(key, value, nullptr);
        return nullptr;
    }
    while (true) {
        auto cmp = compare(key, npc(t)->key);
        if(cmp == 0) {
            return npc(t)->setValue(value);
        } else if(cmp < 0) {
            if(npc(t)->left != nullptr) {
                t = npc(t)->left;
            } else {
                incrementSize();
                npc(t)->left = new RedBlackMap_Entry(key, value, t);
                fixAfterInsertion(npc(t)->left);
                return nullptr;
            }
        } else {
            if(npc(t)->right != nullptr) {
                t = npc(t)->right;
            } else {
                incrementSize();
                npc(t)->right = new RedBlackMap_Entry(key, value, t);
                fixAfterInsertion(npc(t)->right);
                return nullptr;
            }
        }
    }
}

java::lang::Object* rice::p2p::util::RedBlackMap::remove(::java::lang::Object* key)
{
    auto p = getEntry(key);
    if(p == nullptr)
        return nullptr;

    auto oldValue = npc(p)->value;
    deleteEntry(p);
    return oldValue;
}

java::lang::Object* rice::p2p::util::RedBlackMap::getKey(::java::lang::Object* key)
{
    if(key == nullptr)
        return nullptr;

    auto p = getEntry(key);
    if(p == nullptr)
        return nullptr;

    return npc(p)->key;
}

void rice::p2p::util::RedBlackMap::clear()
{
    modCount++;
    size_ = 0;
    root = nullptr;
}

java::lang::Object* rice::p2p::util::RedBlackMap::clone()
{
    RedBlackMap* clone = nullptr;
    try {
        clone = java_cast< RedBlackMap* >(super::clone());
    } catch (::java::lang::CloneNotSupportedException* e) {
        throw new ::java::lang::InternalError();
    }
    npc(clone)->root = nullptr;
    npc(clone)->size_ = 0;
    npc(clone)->modCount = 0;
    npc(clone)->entrySet_ = nullptr;
    try {
        npc(clone)->buildFromSorted(size_, npc(entrySet())->iterator(), nullptr, nullptr);
    } catch (::java::io::IOException* cannotHappen) {
    } catch (::java::lang::ClassNotFoundException* cannotHappen) {
    }
    return clone;
}

java::util::Set* rice::p2p::util::RedBlackMap::keySet()
{
    if(keySet_.load() == nullptr) {
        keySet_ = new RedBlackMap_keySet_1(this);
    }
    return keySet_.load();
}

java::util::Collection* rice::p2p::util::RedBlackMap::values()
{
    if(values_.load() == nullptr) {
        values_ = new RedBlackMap_values_2(this);
    }
    return values_.load();
}

java::util::Set* rice::p2p::util::RedBlackMap::entrySet()
{
    if(entrySet_.load() == nullptr) {
        entrySet_ = new RedBlackMap_entrySet_3(this);
    }
    return entrySet_.load();
}

java::util::SortedMap* rice::p2p::util::RedBlackMap::subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey)
{
    if(compare(fromKey, toKey) <= 0)
        return new RedBlackMap_SubMap(this, fromKey, toKey);
    else
        return new RedBlackMap_SubWrappedMap(this, fromKey, toKey);
}

java::util::SortedMap* rice::p2p::util::RedBlackMap::headMap(::java::lang::Object* toKey)
{
    return new RedBlackMap_SubMap(this, toKey, true);
}

java::util::SortedMap* rice::p2p::util::RedBlackMap::tailMap(::java::lang::Object* fromKey)
{
    return new RedBlackMap_SubMap(this, fromKey, false);
}

int32_t rice::p2p::util::RedBlackMap::compare(::java::lang::Object* k1, ::java::lang::Object* k2)
{
    return (comparator_ == nullptr ? npc((java_cast< ::java::lang::Comparable* >(k1)))->compareTo(k2) : npc(comparator_)->compare(k1, k2));
}

bool rice::p2p::util::RedBlackMap::valEquals(::java::lang::Object* o1, ::java::lang::Object* o2)
{
    clinit();
    return (o1 == nullptr ? o2 == nullptr : npc(o1)->equals(o2));
}

constexpr bool rice::p2p::util::RedBlackMap::RED;

constexpr bool rice::p2p::util::RedBlackMap::BLACK;

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::firstEntry()
{
    auto p = root;
    if(p != nullptr)
        while (npc(p)->left != nullptr) 
                        p = npc(p)->left;


    return p;
}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::lastEntry()
{
    auto p = root;
    if(p != nullptr)
        while (npc(p)->right != nullptr) 
                        p = npc(p)->right;


    return p;
}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::successor(RedBlackMap_Entry* t)
{
    if(t == nullptr)
        return nullptr;
    else if(npc(t)->deleted) {
        return getCeilEntry(npc(t)->key);
    } else if(npc(t)->right != nullptr) {
        auto p = npc(t)->right;
        while (npc(p)->left != nullptr) 
                        p = npc(p)->left;

        return p;
    } else {
        auto p = npc(t)->parent;
        auto ch = t;
        while (p != nullptr && ch == npc(p)->right) {
            ch = p;
            p = npc(p)->parent;
        }
        return p;
    }
}

bool rice::p2p::util::RedBlackMap::colorOf(RedBlackMap_Entry* p)
{
    clinit();
    return (p == nullptr ? BLACK : npc(p)->color);
}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::parentOf(RedBlackMap_Entry* p)
{
    clinit();
    return (p == nullptr ? static_cast< RedBlackMap_Entry* >(nullptr) : npc(p)->parent);
}

void rice::p2p::util::RedBlackMap::setColor(RedBlackMap_Entry* p, bool c)
{
    clinit();
    if(p != nullptr)
        npc(p)->color = c;

}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::leftOf(RedBlackMap_Entry* p)
{
    clinit();
    return (p == nullptr) ? static_cast< RedBlackMap_Entry* >(nullptr) : npc(p)->left;
}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::rightOf(RedBlackMap_Entry* p)
{
    clinit();
    return (p == nullptr) ? static_cast< RedBlackMap_Entry* >(nullptr) : npc(p)->right;
}

void rice::p2p::util::RedBlackMap::rotateLeft(RedBlackMap_Entry* p)
{
    auto r = npc(p)->right;
    npc(p)->right = npc(r)->left;
    if(npc(r)->left != nullptr)
        npc(npc(r)->left)->parent = p;

    npc(r)->parent = npc(p)->parent;
    if(npc(p)->parent == nullptr)
        root = r;
    else if(npc(npc(p)->parent)->left == p)
        npc(npc(p)->parent)->left = r;
    else
        npc(npc(p)->parent)->right = r;
    npc(r)->left = p;
    npc(p)->parent = r;
}

void rice::p2p::util::RedBlackMap::rotateRight(RedBlackMap_Entry* p)
{
    auto l = npc(p)->left;
    npc(p)->left = npc(l)->right;
    if(npc(l)->right != nullptr)
        npc(npc(l)->right)->parent = p;

    npc(l)->parent = npc(p)->parent;
    if(npc(p)->parent == nullptr)
        root = l;
    else if(npc(npc(p)->parent)->right == p)
        npc(npc(p)->parent)->right = l;
    else
        npc(npc(p)->parent)->left = l;
    npc(l)->right = p;
    npc(p)->parent = l;
}

void rice::p2p::util::RedBlackMap::fixAfterInsertion(RedBlackMap_Entry* x)
{
    npc(x)->color = RED;
    while (x != nullptr && x != root && npc(npc(x)->parent)->color == RED) {
        if(parentOf(x) == leftOf(parentOf(parentOf(x)))) {
            auto y = rightOf(parentOf(parentOf(x)));
            if(colorOf(y) == RED) {
                setColor(parentOf(x), BLACK);
                setColor(y, BLACK);
                setColor(parentOf(parentOf(x)), RED);
                x = parentOf(parentOf(x));
            } else {
                if(x == rightOf(parentOf(x))) {
                    x = parentOf(x);
                    rotateLeft(x);
                }
                setColor(parentOf(x), BLACK);
                setColor(parentOf(parentOf(x)), RED);
                if(parentOf(parentOf(x)) != nullptr)
                    rotateRight(parentOf(parentOf(x)));

            }
        } else {
            auto y = leftOf(parentOf(parentOf(x)));
            if(colorOf(y) == RED) {
                setColor(parentOf(x), BLACK);
                setColor(y, BLACK);
                setColor(parentOf(parentOf(x)), RED);
                x = parentOf(parentOf(x));
            } else {
                if(x == leftOf(parentOf(x))) {
                    x = parentOf(x);
                    rotateRight(x);
                }
                setColor(parentOf(x), BLACK);
                setColor(parentOf(parentOf(x)), RED);
                if(parentOf(parentOf(x)) != nullptr)
                    rotateLeft(parentOf(parentOf(x)));

            }
        }
    }
    npc(root)->color = BLACK;
}

void rice::p2p::util::RedBlackMap::deleteEntry(RedBlackMap_Entry* p)
{
    decrementSize();
    if(npc(p)->left != nullptr && npc(p)->right != nullptr) {
        auto s = successor(p);
        npc(p)->key = npc(s)->key;
        npc(p)->value = npc(s)->value;
        p = s;
    }
    auto replacement = (npc(p)->left != nullptr ? npc(p)->left : npc(p)->right);
    if(replacement != nullptr) {
        npc(replacement)->parent = npc(p)->parent;
        if(npc(p)->parent == nullptr)
            root = replacement;
        else if(p == npc(npc(p)->parent)->left)
            npc(npc(p)->parent)->left = replacement;
        else
            npc(npc(p)->parent)->right = replacement;
        npc(p)->left = npc(p)->right = npc(p)->parent = nullptr;
        if(npc(p)->color == BLACK)
            fixAfterDeletion(replacement);

    } else if(npc(p)->parent == nullptr) {
        root = nullptr;
    } else {
        if(npc(p)->color == BLACK)
            fixAfterDeletion(p);

        if(npc(p)->parent != nullptr) {
            if(p == npc(npc(p)->parent)->left)
                npc(npc(p)->parent)->left = nullptr;
            else if(p == npc(npc(p)->parent)->right)
                npc(npc(p)->parent)->right = nullptr;

            npc(p)->parent = nullptr;
        }
    }
    npc(p)->deleted = true;
}

void rice::p2p::util::RedBlackMap::fixAfterDeletion(RedBlackMap_Entry* x)
{
    while (x != root && colorOf(x) == BLACK) {
        if(x == leftOf(parentOf(x))) {
            auto sib = rightOf(parentOf(x));
            if(colorOf(sib) == RED) {
                setColor(sib, BLACK);
                setColor(parentOf(x), RED);
                rotateLeft(parentOf(x));
                sib = rightOf(parentOf(x));
            }
            if(colorOf(leftOf(sib)) == BLACK && colorOf(rightOf(sib)) == BLACK) {
                setColor(sib, RED);
                x = parentOf(x);
            } else {
                if(colorOf(rightOf(sib)) == BLACK) {
                    setColor(leftOf(sib), BLACK);
                    setColor(sib, RED);
                    rotateRight(sib);
                    sib = rightOf(parentOf(x));
                }
                setColor(sib, colorOf(parentOf(x)));
                setColor(parentOf(x), BLACK);
                setColor(rightOf(sib), BLACK);
                rotateLeft(parentOf(x));
                x = root;
            }
        } else {
            auto sib = leftOf(parentOf(x));
            if(colorOf(sib) == RED) {
                setColor(sib, BLACK);
                setColor(parentOf(x), RED);
                rotateRight(parentOf(x));
                sib = leftOf(parentOf(x));
            }
            if(colorOf(rightOf(sib)) == BLACK && colorOf(leftOf(sib)) == BLACK) {
                setColor(sib, RED);
                x = parentOf(x);
            } else {
                if(colorOf(leftOf(sib)) == BLACK) {
                    setColor(rightOf(sib), BLACK);
                    setColor(sib, RED);
                    rotateLeft(sib);
                    sib = leftOf(parentOf(x));
                }
                setColor(sib, colorOf(parentOf(x)));
                setColor(parentOf(x), BLACK);
                setColor(leftOf(sib), BLACK);
                rotateRight(parentOf(x));
                x = root;
            }
        }
    }
    setColor(x, BLACK);
}

constexpr int64_t rice::p2p::util::RedBlackMap::serialVersionUID;

void rice::p2p::util::RedBlackMap::writeObject(::java::io::ObjectOutputStream* s) /* throws(java.io.IOException) */
{
    npc(s)->defaultWriteObject();
    npc(s)->writeInt(size_);
    for (auto *i = npc(entrySet())->iterator(); npc(i)->hasNext(); ) {
        auto e = java_cast< RedBlackMap_Entry* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        npc(s)->writeObject(npc(e)->key);
        npc(s)->writeObject(npc(e)->value);
    }
}

void rice::p2p::util::RedBlackMap::readObject(::java::io::ObjectInputStream* s) /* throws(java.io.IOException, ClassNotFoundException) */
{
    npc(s)->defaultReadObject();
    auto size = npc(s)->readInt();
    buildFromSorted(size, nullptr, s, nullptr);
}

void rice::p2p::util::RedBlackMap::readTreeSet(int32_t size, ::java::io::ObjectInputStream* s, ::java::lang::Object* defaultVal) /* throws(java.io.IOException, ClassNotFoundException) */
{
    buildFromSorted(size, nullptr, s, defaultVal);
}

void rice::p2p::util::RedBlackMap::addAllForTreeSet(::java::util::SortedSet* set, ::java::lang::Object* defaultVal)
{
    try {
        buildFromSorted(npc(set)->size(), npc(set)->iterator(), nullptr, defaultVal);
    } catch (::java::io::IOException* cannotHappen) {
    } catch (::java::lang::ClassNotFoundException* cannotHappen) {
    }
}

void rice::p2p::util::RedBlackMap::buildFromSorted(int32_t size, ::java::util::Iterator* it, ::java::io::ObjectInputStream* str, ::java::lang::Object* defaultVal) /* throws(java.io.IOException, ClassNotFoundException) */
{
    this->size_ = size;
    root = buildFromSorted(0, 0, size - int32_t(1), computeRedLevel(size), it, str, defaultVal);
}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap::buildFromSorted(int32_t level, int32_t lo, int32_t hi, int32_t redLevel, ::java::util::Iterator* it, ::java::io::ObjectInputStream* str, ::java::lang::Object* defaultVal) /* throws(java.io.IOException, ClassNotFoundException) */
{
    clinit();
    if(hi < lo)
        return nullptr;

    auto mid = (lo + hi) / int32_t(2);
    RedBlackMap_Entry* left = nullptr;
    if(lo < mid)
        left = buildFromSorted(level + int32_t(1), lo, mid - int32_t(1), redLevel, it, str, defaultVal);

    ::java::lang::Object* key;
    ::java::lang::Object* value;
    if(it != nullptr) {
        if(defaultVal == nullptr) {
            auto entry = java_cast< ::java::util::Map_Entry* >(java_cast< ::java::lang::Object* >(npc(it)->next()));
            key = java_cast< ::java::lang::Object* >(npc(entry)->getKey());
            value = java_cast< ::java::lang::Object* >(npc(entry)->getValue());
        } else {
            key = java_cast< ::java::lang::Object* >(npc(it)->next());
            value = defaultVal;
        }
    } else {
        key = npc(str)->readObject();
        value = (defaultVal != nullptr ? defaultVal : npc(str)->readObject());
    }
    auto middle = new RedBlackMap_Entry(key, value, nullptr);
    if(level == redLevel)
        npc(middle)->color = RED;

    if(left != nullptr) {
        npc(middle)->left = left;
        npc(left)->parent = middle;
    }
    if(mid < hi) {
        auto right = buildFromSorted(level + int32_t(1), mid + int32_t(1), hi, redLevel, it, str, defaultVal);
        npc(middle)->right = right;
        npc(right)->parent = middle;
    }
    return middle;
}

int32_t rice::p2p::util::RedBlackMap::computeRedLevel(int32_t sz)
{
    clinit();
    auto level = int32_t(0);
    for (auto m = sz - int32_t(1); m >= 0; m = m / int32_t(2) - int32_t(1)) 
                level++;

    return level;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RedBlackMap", 25);
    return c;
}

bool rice::p2p::util::RedBlackMap::equals(::java::lang::Object* o)
{
    return AbstractMap::equals(o);
}

int32_t rice::p2p::util::RedBlackMap::hashCode()
{
    return AbstractMap::hashCode();
}

bool rice::p2p::util::RedBlackMap::isEmpty()
{
    return AbstractMap::isEmpty();
}

bool rice::p2p::util::RedBlackMap::remove(::java::lang::Object* key, ::java::lang::Object* value)
{
    return super::remove(key, value);
}

java::lang::Class* rice::p2p::util::RedBlackMap::getClass0()
{
    return class_();
}

