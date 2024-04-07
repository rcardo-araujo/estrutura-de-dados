#ifndef TFG_H
#define TFG_H

struct Q {
    float l;
};

struct R {
    float b;
    float h;
};

struct TG {
    float b;
    float h;
};

struct TP {
    float B;
    float b;
    float h;
};

typedef struct FG {
    int tipo;
    void* figura;
    float area;
} TFG;

#endif
