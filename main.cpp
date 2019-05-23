#include <gtest/gtest.h>
#include "MyString.h"
#include "string.h"


class StringFixture : public :: testing::Test{

protected:

    char extra_str1[8] = "example";
    char extra_str2[7] = "simple";
    String str1 = {7, extra_str1};
    String str2 = {6, extra_str2};
};


TEST_F(StringFixture, str_cmp)
{
    char someChar[7] = "simple";
    String someString = {6, someChar};
    EXPECT_EQ(0, str_cmp(&someString, &str2));
    char someChar2[14] = "simpleexample";
    String someString2 = {13, someChar2};
    EXPECT_EQ(0, strn_cmp(&someString2, &someString, 6));
    EXPECT_EQ(-1, str_cmp(&someString, &someString2));
}



TEST_F(StringFixture, str_cat)
{
    char new_char1[14] = "simpleexample";
    str_cat(&str2, &str1);
    EXPECT_EQ(13, str2.size);
    EXPECT_EQ(0, strcmp(new_char1, str2.chars));
}


TEST_F(StringFixture, str_cpy)
{
    String someString = strkn_cpy(&str1, 2, 5);
    char someChar[] = "amp";
    String someString2 = {3, someChar};
    EXPECT_EQ(0, str_cmp(&someString, &someString2));
    String someString3 = str_cpy(&someString2);
    EXPECT_EQ(0, str_cmp(&someString2, &someString3));
}

TEST_F(StringFixture, extra_funcs)
{
    char someChar[] = "EXAMPLE";
    String someString = {7, someChar};
    str_upr(&str1);
    EXPECT_EQ(0, str_cmp(&str1, &someString));
    str_lwr(&str1);
    EXPECT_EQ(1, str_cmp(&str1, &someString));
    EXPECT_EQ(1, search_char(&someString, 'X'));
    String someString2 = strkn_cpy(&someString, 1, 4);
    EXPECT_EQ(1, search_substr(&someString, &someString2));
    EXPECT_EQ(0, strcmp(someChar, to_cstring(&someString)));
    String new_string = from_cstring(someChar);
    EXPECT_EQ(0, str_cmp(&new_string, &someString));
}
