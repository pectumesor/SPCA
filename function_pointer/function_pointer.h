#include <stddef.h>

struct student {
    char fname[100];
    char lname[100];
    int year;
    int age;
};

extern struct student class[];

int compare_first_name(const void *a, const void *b);
int compare_last_name(const void *a, const void *b);
void apply(struct student *sarr, int nrec, void(*fp)(void *prec, void *arg, char *out), void *arg, char *out);
void printrec(void *prec, void *arg, char *out);
void isolder(void *prec, void *arg, char *out);
