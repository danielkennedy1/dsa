
/*
 * Linear probing, soft deletion
 */

#include <iostream>

template <typename K, typename V> struct MapBucket {
    bool deleted;
    K key;
    V value;
    MapBucket<K, V>(K key, V value) : key(key), value(value) {};
};

template <typename K, typename V> class HashMap {
public:
    HashMap<K, V>(){
        array = new MapBucket<K, V>*[size];
    }

    void rehash(unsigned int newSize) {
        MapBucket<K, V>** newArray = new MapBucket<K, V>*[newSize];

        for (int i = 0; i < size; i++){
            if(array[i] != nullptr && !array[i]->deleted){
                MapBucket<K, V>* bucket = array[i];
                insert(bucket->key, bucket->value, newArray, newSize);
            }
        }
        delete[] array;
        array = newArray;
        size = newSize;
    }

    int size = 4;   // size of array
    int length = 0; // number of elements
    float loadFactorTolerance = 0.5f;
    MapBucket<K, V>** array;

    void insert(K key, V value, MapBucket<K, V>** array, unsigned int arraySize){
        if (((float)length / (float) size) > loadFactorTolerance) rehash(size << 1);
        unsigned int original_hash = hash(key);
        unsigned int offset = 0;

        MapBucket<K, V>* bucket = array[original_hash];
        while (bucket != nullptr && !bucket->deleted) {
            offset++;
            std::cout << "changing to index = " << (original_hash + offset) % size << std::endl;
            bucket = array[(original_hash + offset) % size];
        }

        std::cout << "Inserting at index = " << (original_hash + offset) % size << std::endl;

        if (bucket == nullptr) bucket = new MapBucket<K, V>(key, value);

        bucket->key = key;
        bucket->value = value;

        length++;
    }

    void insert(K key, V value) {
        insert(key, value, array, size);
    }

    V lookup(K key) {
        std::cout << "In lookup" << std::endl;
        unsigned int original_hash = hash(key);
        MapBucket<K, V>* bucket = array[original_hash];

        int i;

        std::cout << "looking from index = " << original_hash << std::endl;

        for (i = 0; i < size; i++){
            if (bucket == nullptr) break;
            if (bucket->key == key) {
                std::cout << "Returning from lookup, value = " << bucket->value << std::endl;
                return bucket->value;
            }
            bucket = array[(original_hash + i) % size];
        }
        std::cout << "Returning from lookup, from index = " << (original_hash + i) % size << std::endl;

        return -1;
    }

    unsigned int hash(K &key) {return hash(key, size);}

    unsigned int hash(K &key, unsigned int arraySize) {
        std::cout << "In hash" << std::endl;
        const char *s = reinterpret_cast<const char *>(&key);
        unsigned int result = 0;
        for (int i = 0; i < sizeof(key); ++i) {
            result = result * 101 + s[i];
        }
        std::cout << "Returning from hash. hash = " << result % arraySize << std::endl;
        return result % arraySize;
    };
};
