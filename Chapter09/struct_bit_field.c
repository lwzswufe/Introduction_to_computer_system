#include <stdio.h>
#include <stddef.h>

struct Date                     // 位字段
{
    unsigned short year  : 12;
    unsigned short mounth: 4;
    unsigned short date  : 5;
    unsigned short test  : 1;
};

void show_date(struct Date* d)
{
    printf("%04d-%02d-%02d\n", d->year, d->mounth, d->date);
}


int main()
{
    struct Date d0={2011, 1, 12, 0}, d1={198, 12, 3, 0};
    printf("size %lld\n", sizeof(int));
    printf("size %lld\n", sizeof(d1));
    // printf("offset mounth: %lld\n", offsetof(struct Date, mounth));
    show_date(&d0);
    show_date(&d1);
    return 0;
}