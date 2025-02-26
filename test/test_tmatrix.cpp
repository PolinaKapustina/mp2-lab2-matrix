#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	TMatrix<int> copy(m);
	EXPECT_EQ(m, copy);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> m1(5);
  TMatrix<int> m2(m1);
  EXPECT_NE(&m1, &m2);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	TVector<int> v(5);
	for (int i = 0; i < 5; i++)
		v[i] = i * i - 1;
	m[1] = v;
	EXPECT_EQ(v, m[1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[7]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(5);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(7);
	m1 = m2;
	EXPECT_EQ(m1.GetSize(), m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(7);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{

	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	EXPECT_EQ(true, m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(5);
	EXPECT_EQ(true, m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(7);
	EXPECT_EQ(false, m1 == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
		{
			m1[i][j] = 3;
			m2[i][j] = 4;
		}
	TMatrix<int> standart(m1);
	for (int i = 0; i < 5; i++)
		standart[i] = m2[i] + standart[i];
	EXPECT_EQ(standart, (m1 + m2));
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(7);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
		{
			m1[i][j] = 3; 
			m2[i][j] = 4;
		}
	TMatrix<int> standart(m1);
	for (int i = 0; i < 5; i++)
		standart[i] = m2[i] - standart[i];
	EXPECT_EQ(standart, (m2 - m1));
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(7);
	ASSERT_ANY_THROW(m2 - m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(7);
	ASSERT_ANY_THROW(m2 - m1);
}

TEST(TMatrix, can_add_any_matrices_with_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(5);
	TMatrix<int> m3(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
		{
			m1[i][j] = 3;
			m2[i][j] = 4;
			m3[i][j] = 5;
		}
	TMatrix<int> standart(m1);
	for (int i = 0; i < 5; i++)
		standart[i] = m2[i] + standart[i]+m3[i];
	EXPECT_EQ(standart, (m1 + m2 + m3));
}
