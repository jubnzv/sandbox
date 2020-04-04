#include <stdint.h>

typedef enum {
    A1 = 0,
    A2 = 1
} __attribute__((packed)) a_t;
_Static_assert(sizeof(a_t) == 1, "sizeof a_t");

#pragma pack(push, 2)
typedef struct {
    a_t a;
    uint16_t v1;
    uint64_t v2;
} b_t;
#pragma pack(pop)
_Static_assert(sizeof(b_t) == (2 + 8 + 2), "sizeof b_t");

int main(int argc, char *argv[])
{
    return 0;
}
