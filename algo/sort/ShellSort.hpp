/*
 * =====================================================================================
 *
 *       Filename:  ShellSort.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/16/2013 03:59:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuai YUAN (galoisplusplus), yszheda@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef SHELLSORT_HPP
#define SHELLSORT_HPP 
#include <vector>
#include <functional>

template <typename T>
void ShellSort( std::vector<T>& elems );

template <typename T, typename Comparator>
void ShellSort( std::vector<T>& elems, Comparator comp );

template <typename T, typename Comparator>
void ShellSort( std::vector<T>& elems, Comparator comp )
{
		int elem_num = elems.size();
		T tmp;
		for (int increment = elem_num / 2; increment > 0; increment /= 2)
		{
				for (int i = increment; i < elem_num; ++i)
				{
						// insertion sort
						tmp = elems[i];
						for (int j = i; j >= increment && comp(tmp, elems[j-increment]) ; --j)
						{
								elems[j] = elems[j-increment];
						}
						elems[j] = tmp;
				}
		}
}

template <typename T>
void ShellSort( std::vector<T>& elems )
{
		ShellSort( elems, std::less<T>() );
}

#endif /* SHELLSORT_HPP */
