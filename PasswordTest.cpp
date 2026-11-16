/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_repeating_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAAAAAAAAA199434238592");
	ASSERT_EQ(10, actual);
}

TEST(PasswordTest, super_long_repeating_leading_characters)
{
	Password my_password;
	std::string str(513, 'a');
	int actual = my_password.count_leading_characters(str);
	ASSERT_EQ(513, actual);
}

TEST(PasswordTest, no_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, single_leading_character)
{
	Password my_password;
	int actual = my_password.count_leading_characters("12345");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unicode_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("uunicodeθθθθθ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, unicode_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("θθθθθunicode");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, all_lowercase_characters)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aaaabbbbbccccc");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_uppercase_characters)
{
	Password my_password;
	int actual = my_password.has_mixed_case("DEFGHIJK");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_characters)
{
	Password my_password;
	int actual = my_password.has_mixed_case("AbCdEfGHIjkl");
	ASSERT_EQ(true, actual);
}

