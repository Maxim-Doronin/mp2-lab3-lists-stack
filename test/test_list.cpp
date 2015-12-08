#include <gtest.h>

#include "list.h"

TEST(List, can_create_list){
	List *list;
	ASSERT_NO_THROW(list = new List());
}

TEST(List, can_create_copied_list) {
	List list1;
	list1.insertLast(1);
	ASSERT_NO_THROW(List list2(list1));
}

TEST(List, copied_list_is_equal_to_sourse_one) {
	List list1;
	list1.insertLast(1);
	List list2(list1);
	EXPECT_EQ(list2.getFirst()->key, 1);
}

TEST(List, copied_list_has_its_own_memory) {
	List list1;
	list1.insertLast(1);
	List list2(list1);
	list2.insertLast(2);
	list2.erase(1);
	EXPECT_NE(list2.getFirst()->key, list1.getFirst()->key);
}

TEST(List, can_print_list) {
	List list1;
	list1.insertLast(25);
	ASSERT_NO_THROW(list1.print());
}

TEST(List, can_print_empty_list) {
	List list1;
	ASSERT_NO_THROW(list1.print());
}

TEST(List, can_search_element_with_actual_value) {
	List list1;
	list1.insertLast(2);
	list1.insertLast(5);
	list1.insertLast(3);
	list1.insertLast(6);
	ASSERT_TRUE(list1.search(3) != 0);
}

TEST(List, return_null_when_cant_search_element) {
	List list1;
	list1.insertLast(2);
	list1.insertLast(5);
	list1.insertLast(3);
	list1.insertLast(6);
	ASSERT_TRUE(list1.search(11) == 0);
}

TEST(List, throws_when_search_in_empty_list) {
	List list1;
	ASSERT_ANY_THROW(list1.search(11));
}

TEST(List, can_erase_element_with_actual_value) {
	List list1;
	list1.insertLast(2);
	list1.insertLast(5);
	list1.insertLast(3);
	list1.insertLast(6);
	ASSERT_NO_THROW(list1.erase(5));
}

TEST(List, throws_when_try_erase_not_actual_value) {
	List list1;
	list1.insertLast(2);
	list1.insertLast(5);
	list1.insertLast(3);
	list1.insertLast(6);
	ASSERT_ANY_THROW(list1.erase(11));
}

TEST(List, can_erase_first_element) {
	List list1;
	list1.insertLast(2);
	list1.insertLast(5);
	list1.insertLast(3);
	list1.insertLast(6);
	ASSERT_NO_THROW(list1.erase(2));
}

TEST(List, list_after_erase_looks_right){
	List list1;
	list1.insertLast(2);
	list1.insertLast(5);
	list1.insertLast(3);
	list1.insertLast(6);
	list1.erase(5);
	EXPECT_EQ(list1.getFirst()->key, 2);
	list1.erase(list1.getFirst()->key);
	EXPECT_EQ(list1.getFirst()->key, 3);
	list1.erase(list1.getFirst()->key);
	EXPECT_EQ(list1.getFirst()->key, 6);
}

TEST(List, list_after_erase_first_looks_right){
	List list1;
	list1.insertLast(2);
	list1.insertLast(5);
	list1.insertLast(3);
	list1.insertLast(6);
	list1.erase(2);
	EXPECT_EQ(list1.getFirst()->key, 5);
}

TEST(List, throws_when_try_erase_in_empty_list) {
	List list;
	ASSERT_ANY_THROW(list.erase(1));
}

TEST(List, can_insert_first_element) {
	List list;
	ASSERT_NO_THROW(list.insertFirst(5));
}

TEST(List, list_after_insertion_first_looks_right) {
	List list;
	list.insertFirst(5);
	EXPECT_EQ(list.getFirst()->key, 5);
}

TEST(List, can_insert_last_element) {
	List list;
	list.insertFirst(2);
	ASSERT_NO_THROW(list.insertLast(5));
}

TEST(List, can_insert_last_element_when_list_is_empty) {
	List list;
	ASSERT_NO_THROW(list.insertLast(5));
}

TEST(List, list_after_insertion_last_looks_right) {
	List list;
	list.insertLast(5);
	EXPECT_EQ(5, list.getFirst()->key);
}

TEST(List, can_insert_element_before) {
	List list;
	list.insertLast(5);
	list.insertLast(7);
	list.insertLast(9);
	NODE *elem = new NODE;
	elem->key = 1;
	ASSERT_NO_THROW(list.insertBefore(7, elem));
}

TEST(List, throws_when_cant_find_place_to_insert_before) {
	List list;
	list.insertLast(5);
	list.insertLast(7);
	list.insertLast(9);
	NODE *elem = new NODE;
	elem->key = 1;
	ASSERT_ANY_THROW(list.insertBefore(8, elem));
}

TEST(List, can_insert_before_when_it_first) {
	List list;
	list.insertLast(5);
	list.insertLast(7);
	list.insertLast(9);
	NODE *elem = new NODE;
	elem->key = 1;
	ASSERT_NO_THROW(list.insertBefore(5, elem));
}

TEST(List, throws_when_insert_before_in_empty_list) {
	List list;
	NODE *elem = new NODE;
	elem->key = 1;
	ASSERT_ANY_THROW(list.insertBefore(5, elem));
}

TEST(List, can_insert_after) {
	List list;
	list.insertLast(5);
	list.insertLast(7);
	list.insertLast(9);
	NODE *elem = new NODE;
	elem->key = 1;
	ASSERT_NO_THROW(list.insertAfter(7, elem));
}

TEST(List, can_insert_after_when_it_last) {
	List list;
	list.insertLast(5);
	list.insertLast(7);
	list.insertLast(9);
	NODE *elem = new NODE;
	elem->key = 1;
	ASSERT_NO_THROW(list.insertAfter(9, elem));
}

TEST(List, throws_when_cant_find_place_to_insert_after) {
	List list;
	list.insertLast(5);
	list.insertLast(7);
	list.insertLast(9);
	NODE *elem = new NODE;
	elem->key = 1;
	ASSERT_ANY_THROW(list.insertAfter(8, elem));
}

TEST(List, throws_when_insert_after_in_empty_list) {
	List list;
	NODE *elem = new NODE;
	elem->key = 1;
	ASSERT_ANY_THROW(list.insertAfter(5, elem));
}

TEST(List, can_get_first) {
	List list;
	list.insertLast(5);
	list.insertLast(7);
	list.insertLast(9);
	ASSERT_NO_THROW(list.getFirst());
}

TEST(List, can_get_first_key){
	List list;
	list.insertLast(5);
	list.insertLast(7);
	list.insertLast(9);
	EXPECT_EQ(5, list.getFirst()->key);
}