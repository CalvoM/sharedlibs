#ifndef __CMATHER__H_
#define __CMATHER__H_

#ifdef __cplusplus
extern "C"{
#endif

struct mather;
typedef struct mather mather_t;

mather_t *mather_create(int start);
void mather_destroy(mather_t *m);
void mather_incr(mather_t *m);
void mather_decr(mather_t *m);
int mather_val(mather_t *m);


#ifdef __cplusplus
}
#endif
#endif