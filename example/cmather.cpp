#include "cmather.h"
#include "cppmath.h"
#include <stdlib.h>

struct mather{
    void *obj;
};

mather_t *mather_create(int start){
    mather_t *m;
    CPPMather *obj;
    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPMather(start);
    m->obj = obj;
    return m;
}

void mather_destroy(mather_t *m){
    if(m == NULL) return;
    delete static_cast<CPPMather *>(m->obj);
    free(m);
}

void mather_incr(mather_t *m){
    CPPMather *obj;
    if(m == NULL) return;
    obj = static_cast<CPPMather *>(m->obj);
    obj->incr();
}

void mather_decr(mather_t *m){
    CPPMather *obj;
    if(m == NULL) return;
    obj = static_cast<CPPMather *>(m->obj);
    obj->decr();
}

int mather_val(mather_t *m){
    CPPMather *obj;
    if(m == NULL) return -123;
    obj = static_cast<CPPMather *>(m->obj);
    return obj->value();

}