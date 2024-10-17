#include <iostream>

template <typename K, typename V> struct MapNode {
    K key;
    V value;
    MapNode<K, V> *next;
    MapNode<K, V>(K key, V value) : key(key), value(value), next(nullptr) {};
};

template <typename K, typename V> class HashMap {
public:
    HashMap<K, V>() {
        table = new MapNode<K, V> *[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    int size = 4; // size of array
    MapNode<K, V> **table;
    int count = 0; // number of elements
    double loadFactorTolerance = 0.5f;

    void put(K key, V value) {
        unsigned int hashValue = hash(key);
        MapNode<K, V> *prev = nullptr;
        MapNode<K, V> *node = table[hashValue];

        while (node != nullptr && node->key != key) {
            prev = node;
            node = node->next;
        }

        if (node == nullptr) {
            MapNode<K, V> *entry = new MapNode<K, V>(key, value);
            count++;
            if (prev == nullptr) {
                table[hashValue] = entry;
            } else {
                prev->next = entry;
            }
        } else {
            node->value = value;
        }
    }


    void remove(const K &key) {
        unsigned long hashValue = hash(key);
        MapNode<K, V> *prev = NULL;
        MapNode<K, V> *entry = table[hashValue];

        while (entry != NULL && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == NULL) {
            return;
        }

        else {
            if (prev == NULL) {
                if (entry->next != NULL) {
                    table[hashValue] = entry->next;
                } else {
                    table[hashValue] = NULL;
                }
            } else {
                prev->next = entry->next;
            }
            delete entry;
        }
    }

    bool lookup(K key, V &output) {
        unsigned int location = hash(key);
        MapNode<K, V> *node = table[location];

        while (node != nullptr) {
            if (node->key == key) {
                output = node->value;
                return true;
            }
            node = node->next;
        }

        return false;
    }

    unsigned int hash(K key) {
        const char *s = reinterpret_cast<const char *>(&key);
        unsigned int result = 0;
        for (int i = 0; i < sizeof(key); ++i) {
            result = result * 101 + s[i];
        }
        return result % size;
    };
};
