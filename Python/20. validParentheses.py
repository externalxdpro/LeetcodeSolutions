class Solution:
    def isValid(s: str) -> bool:
        if (len(s) % 2 != 0):
            return False

        sList = list(s)
        index = 1
        stack = [sList[0]]

        while index < len(sList):

            if len(stack) == 0:
                stack.append(sList[index])
                index = index + 1


            current = stack.pop()
            if (current == "(" and sList[index] == ")") or (current == "{" and sList[index] == "}") or (current == "[" and sList[index] == "]"):
                index = index + 1
                continue
            if sList[index] == ")" or sList[index] == "}" or sList[index] == "]":
                return False

            stack.append(current)
            stack.append(sList[index])
            index = index + 1

        if len(stack) > 0:
            return False
        return True

    print(isValid(s = "({}[])({}"))
