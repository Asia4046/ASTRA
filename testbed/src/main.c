
#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    ASFATAL("A TEST MESSAGE: %f", 3.14f);
    ASERROR("A TEST MESSAGE: %f", 3.14f);
    ASWARN("A TEST MESSAGE: %f", 3.14f);
    ASINFO("A TEST MESSAGE: %f", 3.14f);
    ASDEBUG("A TEST MESSAGE: %f", 3.14f);
    ASTRACE("A TEST MESSAGE: %f", 3.14f);

    ASASSERT(1 == 0);

    return 0;
}