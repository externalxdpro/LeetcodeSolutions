#!/usr/bin/env python3

def divide(dividend: int, divisor: int) -> int:
    result = 0
    sign = 1

    # if dividend < 0 ^ divisor < 0:    # xor didn't work for some reason
    if (dividend < 0 and divisor >= 0) or (dividend >= 0 and divisor < 0):
        sign = -1

    dividend = abs(dividend)
    divisor = abs(divisor)

    while dividend >= divisor:
        dividend -= divisor
        result += 1

    if sign == -1:
        result = -result

    return result

    # if dividend >= 0:
    #     if divisor > 0:
    #         while dividend >= divisor:
    #             dividend = dividend - divisor
    #             result = result + 1
    #     elif divisor < 0:
    #         while dividend >= 0:
    #             dividend = dividend + divisor
    #             result = result - 1
    # elif dividend < 0:
    #     if divisor > 0:
    #         while dividend <= 0:
    #             dividend = dividend + divisor
    #             result = result - 1
    #     elif divisor < 0:
    #         while dividend <= divisor:
    #             dividend = dividend - divisor
    #             result = result + 1

    # result = result * sign
    # return result


# Testcases
# print(divide(10, 3))
# print(divide(-10, 3))
# print(divide(7, -3))
# print(divide(-7, -3))
print(divide(-2147483647, 1))
# print(divide(0, -1))
