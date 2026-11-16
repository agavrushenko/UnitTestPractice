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

TEST(PasswordTest, all_lower_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aaaabbbbbccccc");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_upper_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("DEFGHIJK");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("AbCdEfGHIjkl");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, all_number_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("123455578");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, numbers_and_lower_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("12abc2445");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, numbers_lower_and_special_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("123abc!@#{}>?");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, unicode_and_lower_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("θθθθθunicode");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, every_character_type_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("θθθθθunicodeANDupperAND!@#$():");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, all_lower_last_upper_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("lowerU");
	ASSERT_EQ(true, actual);
}

