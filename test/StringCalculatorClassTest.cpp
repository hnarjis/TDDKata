#include "gmock/gmock.h"
#include "StringCalculatorClass.h"

TEST(StringCalculatorClassTest, CanCallAddWithEmptyString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	int result = stringCalculatorClass_p->add("");

	//Exercise
	ASSERT_EQ(0, result);

	//Teardown
	delete stringCalculatorClass_p;
}

TEST(StringCalculatorClassTest, CanCallAddWithOneNumberString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	int result = stringCalculatorClass_p->add("1");

	//Exercise
	ASSERT_EQ(1, result);

	//Teardown
	delete stringCalculatorClass_p;
}

TEST(StringCalculatorClassTest, CanCallAddWithTwoNumbersString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	int result = stringCalculatorClass_p->add("1,2");

	//Exercise
	ASSERT_EQ(3, result);

	//Teardown
	delete stringCalculatorClass_p;
}

TEST(StringCalculatorClassTest, CanCallAddWithTenNumbersString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	int result = stringCalculatorClass_p->add("1,2,3,4,5,6,7,8,9,10");

	//Exercise
	ASSERT_EQ(55, result);

	//Teardown
	delete stringCalculatorClass_p;
}

TEST(StringCalculatorClassTest, CanCallAddWithOneNewLineString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	int result = stringCalculatorClass_p->add("1\n2,3");

	//Exercise
	ASSERT_EQ(6, result);

	//Teardown
	delete stringCalculatorClass_p;
}

TEST(StringCalculatorClassTest, CanCallAddWithAnotherDelimiterString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	int result = stringCalculatorClass_p->add("//;\n1;2”");

	//Exercise
	ASSERT_EQ(3, result);

	//Teardown
	delete stringCalculatorClass_p;
}

TEST(StringCalculatorClassTest, CanCallAddWithOneNegativeString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	try
	{
		stringCalculatorClass_p->add("-1");
	}
	catch (std::string e)
	{
		ASSERT_EQ("negatives not allowed -1", e);
		return;
	}
	ASSERT_TRUE(false);

	//Teardown
	delete stringCalculatorClass_p;
}

TEST(StringCalculatorClassTest, CanCallAddWithMultipleNegativesString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	try
	{
		stringCalculatorClass_p->add("-1,2,-3");
	}
	catch (std::string e)
	{
		ASSERT_EQ("negatives not allowed -1 -3", e);
		return;
	}
	ASSERT_TRUE(false);

	//Teardown
	delete stringCalculatorClass_p;
}
