#include <iostream>
#include <ostream>
#include <string>

template <typename K, typename V> struct MapNode {
    K key;
    V value;
    MapNode<K, V> *next;
    MapNode<K, V>(K key, V value) : key(key), value(value), next(nullptr){};
};

template <typename K, typename V> class HashMap {
public:
    HashMap<K, V>() { 
        table = new MapNode<K, V> *[size]; 
        for (int i = 0; i < size; i++) table[i] = nullptr;
    }

    void rehash(unsigned int newSize) {
        MapNode<K, V> **newArray = new MapNode<K, V> *[newSize];

        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr) {
                MapNode<K, V> *node = table[i];
                while (node != nullptr) {
                    put(node->key, node->value, newArray, newSize);
                    node = node->next;
                }
            }
        }
        delete[] table;
        table = newArray;
        size = newSize;
    }

    int size = 4; // size of array
    MapNode<K, V> **table;
    // int count = 0; // number of elements
    // float loadFactorTolerance = 0.5f;

    void put(K key, V value, MapNode<K, V> **table, unsigned int arraySize) {
        unsigned int location = hash(key, arraySize);
        MapNode<K, V> *node = table[location];

        if (node == nullptr) {
            table[location] = new MapNode<K, V>(key, value);
            return;
        }

        while (node->key != key) {
            if (node->next == nullptr) {
                node->next = new MapNode<K, V>(key, value);
            }
            node = node->next;
        }

        // count++;
    }

    void put(K key, V value) { put(key, value, table, size); }

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

    unsigned int hash(K &key) { return hash(key, size); }

    unsigned int hash(K key, unsigned int arraySize) {
        const char *s = reinterpret_cast<const char*>(&key);
        unsigned int result = 0;
        for (int i = 0; i < sizeof(key); ++i) {
            result = result * 101 + s[i];
        }
        return result % arraySize;
    };
};
