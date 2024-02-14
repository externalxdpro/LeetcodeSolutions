#!/usr/bin/env python3

def allSubstrings(s):
    length = len(s)

    subs = []
    for i in range(1, length + 1):
        subs.append(s[:i])

    return subs


def longestCommonPrefix(strs: list[str]) -> str:
    smallestVal = min(strs, key=len)
    subs = allSubstrings(smallestVal)

    common = {}

    for i, iVal in enumerate(strs):
        for j, jVal in enumerate(subs):
            if iVal.startswith(jVal):
                if jVal not in common:
                    common[jVal] = 1
                else:
                    common[jVal] += 1

    longestLen = 0
    result = ""
    for i in common:
        if common[i] == len(strs) and len(i) > longestLen:
            result = i

    return result


print(longestCommonPrefix(["flower", "flow", "flight"]))
# print(allSubstrings("hello world"))
