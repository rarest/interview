//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"
#include <typeinfo>

typedef void(*FUN)(void);


void printVTable(intptr_t *vtb, int n) {
    if (!vtb) return;

    printf("vtb: %p\n", vtb);
    for (int i = 0; i < n; i++) {
        printf("func: %d: %#x->", i, vtb[i]);
        FUN f = (FUN) vtb[i];
        f();
    }
    printf("\n");
}

int main() {
    Base b;
    EmptyChild ec;
    EmptyChildVirturl ecv;
    printf("size of ec %d ecv %d\n",sizeof(ec),sizeof(ecv));

    intptr_t *vtb = (intptr_t *) *(intptr_t *) &b;
    printVTable(vtb, 3);
    Derived d;
    vtb = ((intptr_t *) *(intptr_t *) (&d) + 0);
    printVTable(vtb, 6);

    MultiDerived multiDerived;
    intptr_t **ppvtb = (intptr_t **) &multiDerived;
    FUN func = nullptr;
    func = (FUN) ppvtb[0][0];
    func();
    func = (FUN) ppvtb[0][1];
    func();
    func = (FUN) ppvtb[0][2];
    func();
    func = (FUN) ppvtb[0][3];
    func();
    func = (FUN) ppvtb[0][4];
    cout << func << endl;
    printf("%#X\n", ppvtb[0][4]);

    func = (FUN) ppvtb[1][0];
    func();
    func = (FUN) ppvtb[1][1];
    func();
    func = (FUN) ppvtb[1][2];
    func();
    func = (FUN) ppvtb[1][3];
    cout << func << endl;
    printf("%#X\n", ppvtb[1][3]);

    func = (FUN) ppvtb[2][0];
    func();
    func = (FUN) ppvtb[2][1];
    func();
    func = (FUN) ppvtb[2][2];
    func();
    func = (FUN) ppvtb[2][3];
    cout << func << endl;
    printf("%#X\n", ppvtb[2][3]);


    Base *base = new Derived();
    base->f();
    base->Base::f();
    size_t point_size = sizeof(base);
    size_t emptyClass_size = sizeof(Empty);
    size_t oneFunClass_size = sizeof(OneFunction);
    size_t int_size = sizeof(int);
    size_t oneMemberChar_size = sizeof(OneMemberChar);
    size_t oneMemberInt_size = sizeof(OneMemberInt);
    size_t virtualClass_size = sizeof(Base);
    printf("point_size %d empty_size %d oneFunClass_size %d \nint_size %d oneMember_size %d \noneMemberInt_size %d virtualClass_size %d",
           point_size, emptyClass_size, oneFunClass_size, int_size, oneMemberChar_size, oneMemberInt_size,
           virtualClass_size);
    return 0;
}