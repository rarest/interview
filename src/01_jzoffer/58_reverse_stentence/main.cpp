//
// Created by Chen Shuquan on 2020/5/11.
//


#include "58_reverseSentence.h"

USE_INTERVIEW_NS

int main() {

    char p[] = "i am a student.";

    printf("input sentence: %s\n", p);
    char *result = reverseSentence(p);
    printf("output sentence: %s\n", result);


    char p1[] = "abc, 123, 456, 789";
    printf("input sentence: %s\n", p1);
    char *result1 = reverseSentence(p1);
    printf("output sentence: %s\n", result1);

    char str[] = "abcdefg";

    printf("input str: %s\n", str);
    char *strResult = leftRotateString(str, 3);
    printf("output str: %s\n", strResult);

    return 0;
}