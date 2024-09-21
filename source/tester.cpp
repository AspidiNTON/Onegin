#include "tester.h"

Test defaultTests[] {
    {"sfmdghma", "asetjsfrhy", 3},
    {"srj", "syl,kfyl.", 2},
    {"sidguuwhgsfigb", "iolfdgharg", 8},
    {"one", "two", 1},
    {"onetwo", "t", 3},
    {"a", "b", 9},
    {"sdtgjhdghyjmd", "xdd", 5},
    {"", "gggb", 0},
    {"fdgn", "gggb", 1}
};

int runTest(Test *test){
    char *first = strdup(test->f);
    char *second = strdup(test->s);
    char *myFirst = strdup(test->f);
    char *mySecond = strdup(test->s);
    int n = test->n;

    if (myStrchr(first, second[0]) != strchr(first, second[0])) {
        printf("Error at strchar, string %s, char %c\n", test->f, second[0]);
        return 1;
    }

    if (myStrlen(myFirst) != strlen(first)) {
        printf("Error at strlen, string %s\n", test->f);
        return 2;
    }


    first = strdup(test->f);
    second = strdup(test->s);
    myFirst = strdup(test->f);
    mySecond = strdup(test->s);
    strcpy(first, second);
    myStrcpy(myFirst, mySecond);
    if (strcmp(first, myFirst) != 0) {
        printf("Error at strcpy, string %s\n", test->f);
        return 3;
    }

    first = strdup(test->f);
    second = strdup(test->s);
    myFirst = strdup(test->f);
    mySecond = strdup(test->s);
    strncpy(first, second, n);
    myStrncpy(myFirst, mySecond, n);
    if (strcmp(first, myFirst) != 0) {
        printf("Error at strncpy, string %s\n", test->f);
        printf("%s %s\n", first, myFirst);
        return 4;
    }

    first = strdup(test->f);
    second = strdup(test->s);
    myFirst = strdup(test->f);
    mySecond = strdup(test->s);
    strcat(first, second);
    myStrcat(myFirst, mySecond);
    if (strcmp(first, myFirst) != 0) {
        printf("Error at strcat, strings %s and %s\n", test->f, test->s);
        return 5;
    }
    
    first = strdup(test->f);
    second = strdup(test->s);
    myFirst = strdup(test->f);
    mySecond = strdup(test->s);
    strncat(first, second, n);
    myStrncat(myFirst, mySecond, n);
    if (strcmp(first, myFirst) != 0) {
        printf("Error at strncat, strings %s and %s\n", test->f, test->s);
        return 6;
    }

    first = strdup(test->f);
    second = strdup(test->s);
    myFirst = strdup(test->f);
    mySecond = strdup(test->s);
    first = strdup(second);
    myFirst = myStrdup(mySecond);
    if (strcmp(first, myFirst) != 0) {
        printf("Error at strdup, strings %s and %s\n", test->f, test->s);
        return 7;
    }

    return 0;
}

int runDefaultTests(){
    for (size_t i = 0; i < sizeof(defaultTests) / sizeof(Test); ++i) {
        if (runTest(&defaultTests[i]) != 0) {
            printf("Error at test %lld\n", i + 1);
            return i;
        }
    }
    printf("Tests complete successfully\n");
    return 0;
}