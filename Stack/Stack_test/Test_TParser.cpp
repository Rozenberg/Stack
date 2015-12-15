#include "TParser.h"
#include "gtest.h"

TEST(TParser, TParser_check_of_creat)
{
	char str[10] = "123456789";
	TParser prs(str);
	bool f = true;
	for (int i = 0; i < 10; i++)
		if (prs.Get_Inf()[i] != str[i]) f = false;
	EXPECT_EQ(f, true);
}

TEST(TParser, TParser_check_of_brackets)
{
	TParser prs("()()()");
	ASSERT_TRUE(prs.Check_of_brackets());
}

TEST(TParser, TParser_check_Polish_system)
{
	TParser prs("3 + 3 * 3 / (1 + 2)");
	prs.InfToPost();
	EXPECT_EQ(prs.Polish_system(), 6);
}

TEST(TParser, TParser_check_pointer_NULL)
{
	TParser prs;
	EXPECT_EQ('\0',prs.Get_Inf()[0]);
}

TEST(TParser, TParser_check_Inf_negative)
{
	TParser prs("3 + 3 * 2 / (1 + 1)");
	prs.InfToPost();
	EXPECT_EQ(prs.Polish_system(), 6);
}


TEST(TParser, TParser_throws_Polish_System)
{
	TParser prs("3 + 3 * 2 / (1 + 5)))))");
	ASSERT_ANY_THROW(prs.InfToPost());
}

TEST(TParser, TParser_check_Priority)
{
	TParser prs;
	EXPECT_EQ(prs.Priority('*'), 2);
}

TEST(TParser, TParser_check_IsOperation)
{
	TParser prs;
	ASSERT_TRUE(prs.IsOpearation('^'));
}
