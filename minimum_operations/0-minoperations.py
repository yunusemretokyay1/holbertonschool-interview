#!/usr/bin/python3
"""
Calculates the fewest number of operations needed to result
in exactly n H characters in the file.
"""


def min_operations(n):
    operation_count = 0
    number = 2
    if type(n) is not int or n <= 1:
        return operation_count
    while n > 1:
        if n % number == 0:
            operation_count += number
            n /= number
        else:
            number += 1
    return operation_count
