#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>

template<typename K, typename V>
class Dictionary {
private:
    static const size_t INITIAL_CAPACITY = 16;
    static const float LOAD_FACTOR = 0.75f;

    struct Entry {
        K key;
        V value;

        Entry(const K& k, const V& v) : key(k), value(v) {}
        Entry(K&& k, V&& v) : key(std::move(k)), value(std::move(v)) {}
    };

    std::vector<std::list<Entry>> table;
    size_t currentSize;

    size_t hash(const K& key) const {
        return std::hash<K>{}(key) % table.size();
    }

    void rehash() {
        std::vector<std::list<Entry>> oldTable = table;
        table.resize(table.size() * 2);
        for (auto& bucket : table) bucket.clear();
        currentSize = 0;

        for (const auto& bucket : oldTable) {
            for (const auto& entry : bucket) {
                insert(entry.key, entry.value);
            }
        }
    }

public:
    Dictionary() : table(INITIAL_CAPACITY), currentSize(0) {}

    // Вставка с поддержкой move-семантики
    void insert(const K& key, const V& value) {
        insert_impl(key, value);
    }

    void insert(K&& key, V&& value) {
        insert_impl(std::move(key), std::move(value));
    }

    // Удаление с проверкой существования ключа
    bool remove(const K& key) {
        size_t index = hash(key);
        auto& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                --currentSize;
                return true;
            }
        }
        return false;
    }

    // Доступ по ключу с исключением
    V& get(const K& key) {
        return const_cast<V&>(static_cast<const Dictionary*>(this)->get(key));
    }

    const V& get(const K& key) const {
        size_t index = hash(key);
        for (const auto& entry : table[index]) {
            if (entry.key == key) {
                return entry.value;
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Оператор [] для удобного доступа
    V& operator[](const K& key) {
        size_t index = hash(key);
        for (auto& entry : table[index]) {
            if (entry.key == key) {
                return entry.value;
            }
        }

        // Если ключа нет - вставляем значение по умолчанию
        if ((float)currentSize / table.size() > LOAD_FACTOR) {
            rehash();
            index = hash(key);
        }

        table[index].emplace_back(key, V());
        ++currentSize;
        return table[index].back().value;
    }

    bool contains(const K& key) const {
        size_t index = hash(key);
        for (const auto& entry : table[index]) {
            if (entry.key == key) {
                return true;
            }
        }
        return false;
    }

    size_t size() const { return currentSize; }
    bool empty() const { return currentSize == 0; }

    // Получение ключей и значений
    std::vector<K> keys() const {
        std::vector<K> allKeys;
        allKeys.reserve(currentSize);
        for (const auto& bucket : table) {
            for (const auto& entry : bucket) {
                allKeys.push_back(entry.key);
            }
        }
        return allKeys;
    }

    std::vector<V> values() const {
        std::vector<V> allValues;
        allValues.reserve(currentSize);
        for (const auto& bucket : table) {
            for (const auto& entry : bucket) {
                allValues.push_back(entry.value);
            }
        }
        return allValues;
    }

    // Дополнительные методы для работы с наборами
    bool contains_all_keys(const std::vector<K>& keys) const {
        return std::all_of(keys.begin(), keys.end(),
            [this](const K& key) { return contains(key); });
    }

    void merge(const Dictionary<K, V>& other) {
        for (const auto& bucket : other.table) {
            for (const auto& entry : bucket) {
                insert(entry.key, entry.value);
            }
        }
    }

    void clear() {
        for (auto& bucket : table) bucket.clear();
        currentSize = 0;
    }

private:
    template<typename Key, typename Value>
    void insert_impl(Key&& key, Value&& value) {
        if ((float)currentSize / table.size() > LOAD_FACTOR) {
            rehash();
        }

        size_t index = hash(key);
        for (auto& entry : table[index]) {
            if (entry.key == key) {
                entry.value = std::forward<Value>(value);
                return;
            }
        }

        table[index].emplace_back(std::forward<Key>(key), std::forward<Value>(value));
        ++currentSize;
    }
};