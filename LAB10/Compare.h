#pragma once

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
    virtual ~Compare() = default;
};

class CompareInt : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int* a = static_cast<int*>(e1);
        int* b = static_cast<int*>(e2);
        if (*a > *b) return 1;
        if (*a < *b) return -1;
        return 0;
    }
};
