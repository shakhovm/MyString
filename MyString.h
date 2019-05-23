#ifndef THESTRING_MYSTRING_H
#define THESTRING_MYSTRING_H

#endif //THESTRING_MYSTRING_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct String{
    int size;
    char* chars;
} String;


//Print string
void strprint(const String* str);

//Compare two strings
int str_cmp(const String* str1, const String* str2);

//Compare first n elements of string
int strn_cmp(const String* str1, const String* str2, int n);

//Copy from k to n element of string
String strkn_cpy(const String* str, int k, int n);

//Copy first n elements
String strn_cpy(const String* str, int n);

//Copy full string
String str_cpy(const String* str);

//Add first n elements of one string to another
void strn_cat(String *str1, const String *str2, int n);

//Add two strings
void str_cat(String *str1, const String *str2);

//Convert string to lowercase
void str_lwr(String *str);

//Convert string to uppercase
void str_upr(String *str);

//Return the index of beginning of substring
int search_substr(const String *main_str, const String *sub_str);

//Return index of char
int search_char(const String *str, char ch);

//Convert cstring to String
String from_cstring(const char* str);

//Convert String to cstring
char *to_cstring(const String *str);


int strn_cmp(const String* str1, const String* str2, int n)
{

    for(int i = 0; i < n; ++i)
    {
        if(i > str2->size)
        {
            return 1;
        }
        if(i > str1->size)
        {
            return -1;
        }
        if(str1->chars[i] > str2->chars[i])
        {
            return 1;
        }
        if(str1->chars[i] < str2->chars[i]){
            return -1;
        }
    }


    return 0;
}
int str_cmp(const String *str1, const String *str2)
{
    int size = str1->size > str2->size ? str1->size : str2->size;
    return strn_cmp(str1, str2, size);
}

String strkn_cpy(const String* str, int k, int n)
{
    int j = k;
    char *new_chars = (char*)malloc(sizeof(char)*(n - k + 1));
    for(int i = 0; i < n - k; ++i)
    {
        new_chars[i] = str->chars[j];
        ++j;
    }
    new_chars[n - k] = '\0';
    String new_string = {n - k, new_chars};
    return new_string;
}

String strn_cpy(const String *str, int n)
{
    return strkn_cpy(str, 0, n);
}
String str_cpy(const String* str)
{
    return strn_cpy(str, str->size);
}


void strn_cat(String *str1, const String *str2, int n)
{
    int j = str1->size;
    int i = 0;
    char *new_place = (char*)realloc(str1->chars, sizeof(char)*((str1->size)+ n + 1));
    char *ptr;
    if(!new_place)
    {
        char *string_place = (char*)malloc(sizeof(char)*((str1->size) + n + 1));
        for(int k = 0; k < str1->size; ++k)
        {
            string_place[k] = str1->chars[k];
        }
        ptr = string_place;
    }
    else
    {
        ptr = str1->chars;
    }

    while(i < n)
    {
        *(ptr + j) = str2->chars[i];
        ++i;
        ++j;
    }
    free(str1->chars);
    str1->chars = ptr;
    str1->size += n;
    str1->chars[str1->size] = '\0';

}

void str_cat(String *str1, const String *str2)
{
    strn_cat(str1, str2, str2->size);
}


void str_lwr(String *str)
{
    for(int i = 0; i < str->size; ++i)
    {
        if('A' <= str->chars[i] && str->chars[i] <= 'Z')
        {
            str->chars[i] = (char)tolower((int)str->chars[i]);
        }
    }
}

void str_upr(String *str)
{
    for(int i = 0; i < str->size; ++i)
    {
        if('a' <= str->chars[i] && str->chars[i] <= 'z')
        {
            str->chars[i] = (char)toupper((int)str->chars[i]);
        }
    }
}

int search_substr(const String *main_str, const String *sub_str)
{
    for(int i = 0; i < main_str->size; ++i)
    {
        String new_str = strkn_cpy(main_str, i, i + sub_str->size);
        if(str_cmp(&new_str, sub_str) == 0)
        {
            return i;
        }
    }
    return -1;
}

int search_char(const String *str, char ch)
{
    for(int i = 0; i < str->size; ++i)
    {
        if(str->chars[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

char* to_cstring(const String* str)
{
    char *cstring = (char*)malloc(sizeof(char)*str->size + 1);
    for(int i = 0; i < str->size; ++i)
    {
        cstring[i] = str->chars[i];
    }
    cstring[str->size] = '\0';
    return cstring;
}

String from_cstring(const char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        ++i;
    }
    char *new_string = (char*)malloc(sizeof(char)*i);
    for(int j = 0; j < i; ++j)
    {
        new_string[j] = str[j];
    }
    new_string[i] = '\0';
    String string = {i, new_string};
    return string;
}

void strprint(const String* str)
{
    printf("%s", str->chars);
    printf("\n");
}
