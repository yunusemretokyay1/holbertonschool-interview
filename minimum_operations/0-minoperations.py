#!/usr/bin/python3
"""
Calculates the fewest number of operations needed to result
in exactly n H characters in the file.
"""

def minOperations(n):
   

    if n <= 1:
        return 0

   operation_count = 1

    while True:
        operation_count += 1

        if n / prime_factor % 1 == 0:
            return operation_count + minOperations(n // operation_count)
