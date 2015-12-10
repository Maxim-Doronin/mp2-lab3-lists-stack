#include <gtest.h>

#include "stack.h"
#include "stack.cpp"

TEST(Stack, can_create_stack){
	Stack<double> *s;
	ASSERT_NO_THROW(s = new Stack<double>());
}

TEST(Stack, can_create_copied_stack){
	Stack<char> s1;
	s1.push(3);
	s1.push(2);
	ASSERT_NO_THROW(Stack<char> s2(s1));
}

TEST(Stack, copied_stack_is_equal_to_sourse_one){
	Stack<char> s1;
	s1.push(3);
	Stack<char> s2(s1);
	EXPECT_EQ(s1.look(), s2.look());
}

TEST(Stack, copied_list_has_its_own_memory){
	Stack<char> s1;
	s1.push(1);
	s1.push(2);
	Stack<char> s2(s1);
	s2.pop();
	s2.push(3);
	EXPECT_NE(s1.look(), s2.look());
}

TEST(Stack, IsEmpty_returns_1_when_stack_is_empty){
	Stack<char> s;
	EXPECT_EQ(1, s.isEmpty());
}

TEST(Stack, IsEmpty_returns_0_when_stack_isnt_empty){
	Stack<char> s;
	s.push(1);
	EXPECT_EQ(0, s.isEmpty());
}

TEST(Stack, IsFull_returns_0_when_stack_isnt_full){
	Stack<char> s;
	s.push(1);
	EXPECT_EQ(0, s.isFull());
}

TEST(Stack, can_push_new_element){
	Stack<char> s;
	ASSERT_NO_THROW(s.push(1));
}

TEST(Stack, throws_when_try_pop_element_when_stack_is_empty){
	Stack<char> s;
	ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_pop_element_from_no_empty_stack){
	Stack<char> s;
	s.push(1);
	ASSERT_NO_THROW(s.pop());
}

TEST(Stack, poped_element_is_equal_to_pushed_one){
	Stack<char> s;
	s.push(1);
	EXPECT_EQ(1, s.pop());
}

TEST(Stack, throws_when_try_look_element_when_stack_is_empty){
	Stack<char> s;
	ASSERT_ANY_THROW(s.look());
}

TEST(Stack, can_look_element_from_no_empty_stack){
	Stack<char> s;
	s.push(1);
	ASSERT_NO_THROW(s.look());
}

TEST(Stack, looked_element_is_equal_to_pushed_one){
	Stack<char> s;
	s.push(1);
	EXPECT_EQ(1, s.look());
}