#include <stdio.h>
#include "cmather.h"

int main(){
    mather_t *m = mather_create(5);
    mather_incr(m);
    printf("%d\r\n",mather_val(m));
    mather_incr(m);
    printf("%d\r\n",mather_val(m));
    mather_decr(m);
    printf("%d\r\n",mather_val(m));
    // mather_destroy(m);
}