#ifndef TFG_H
#define TFG_H

typedef struct Q {
    float l;
} TQ;

typedef struct R {
    float b;
    float h;
} TR;

typedef struct TG {
    float b;
    float h;
} TTG;typedef 

struct TP {
    float B;
    float b;
    float h;
} TTP;

typedef struct FG {
    void* info;
    int tipo;
    float area;
} TFG;

#endif
