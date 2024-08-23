#!/usr/bin/python3
"""Module for Pascal's triangle function."""


def pascal_triangle(n):
    """
    Generates Pascal's triangle up to the nth row.

    Args:
        n (int): The number of rows in Pascal's triangle.

    Returns:
        list of lists: A list of lists, where each sublist represents a row of Pascal's triangle.
    """
    if n <= 0:
        return []
    
    triangle = [[] for _ in range(n)]
    
    for i in range(n):
        for j in range(i + 1):
            if j == 0 or j == i:
                triangle[i].append(1)
            else:
                triangle[i].append(triangle[i - 1][j] + triangle[i - 1][j - 1])
    
    return triangle
