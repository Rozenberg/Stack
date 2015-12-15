#include "TStack.h"
#include "gtest.h"

TEST(TStack, stack_create_positive_MaxSize)
{
	ASSERT_NO_THROW(TStack<char> st(5));
}

TEST(TStack, stack_throws_negative_MaxSize)
{
	ASSERT_ANY_THROW(TStack<char> st(-3));

}

TEST(TStack, stack_throws_Top_when_Empty)
{
	TStack<char> st(5);
	ASSERT_ANY_THROW(st.Top());
}

TEST(TStack, stack_throws_Pop_when_Empty)
{
	TStack<char> st(5);
	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, stack_throws_Push_when_Full)
{
	TStack<char> st(2);
	st.Push('a'); st.Push('b');
	ASSERT_ANY_THROW(st.Push('c'));
}

TEST(TStack, stack_create_copied)
{
	TStack<int> st1(4);
	st1.Push(2); st1.Push(3);
	TStack<int> st2(st1);
	EXPECT_EQ(st1, st2);
}

TEST(TStack, stack_check_get_size)
{
	TStack<int> st1(4);
	st1.Push(2); st1.Push(3);
	EXPECT_EQ(2, st1.Size());
}

TEST(TStack, stack_check_function_clear)
{
	TStack<int> st1(4);
	st1.Push(2); st1.Push(3);
	st1.Clear();
	EXPECT_EQ(0, st1.Size());
}

TEST(TStack, stack_check_IsEmpty)
{
	TStack<int> st1(4);
	st1.Push(2); st1.Push(3);
	EXPECT_FALSE(st1.IsEmpty());
}

TEST(TStack, stack_check_IsFull)
{
	TStack<int> st1(4);
	st1.Push(2); st1.Push(3); st1.Push(4); st1.Push(5);
	EXPECT_TRUE(st1.IsFull());
}