#include <iostream>

template <typename K, typename V>
class Map {
private:
    struct element {
        K key;
        V value;
        int index;
    };
    int nr = 0;
    element a[100];

public:
    void Set(const K& key, const V& value) {
        for (int i = 0; i < nr; i++) {
            if (a[i].key == key) {
                a[i].value = value;
                return;
            }
        }
        a[nr] = { key, value, nr };
        nr++;
    }

    bool Get(const K& key, V& value) {
        for (int i = 0; i < nr; i++) {
            if (a[i].key == key) {
                value = a[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() {
        return nr;
    }

    void Clear() {
        nr = 0;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < nr; i++) {
            if (a[i].key == key) {
                for (int j = i + 1; j < nr; j++)
                    a[j - 1] = a[j];
                nr--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& map) {
        for (int i = 0; i < map.nr; i++) {
            V val;
            if (!this->Get(map.a[i].key, val))
                return false;
        }
        return true;
    }

    V& operator[](const K& key) {
        for (int i = 0; i < nr; i++)
            if (a[i].key == key)
                return a[i].value;

        a[nr] = { key, V(), nr };
        nr++;
        return a[nr - 1].value;
    }

    const element* begin() const {
        return &a[0];
    }

    const element* end() const {
        return &a[nr];
    }
};
