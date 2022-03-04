class characterStrngCalculateExpressionStack:
    def calculate(self,s:str)->int:
        stack = []
        sign = '+'
        num = 0
        for i in range(len(s)):
            if s[i].isdigit():
                num = num * 10 + ord(s[i]) - ord('0')
            if i == len(s) - 1 or s[i] in '+-*/': # 并列条件
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack.append(stack.pop() * num)
                else:
                    stack.append(int(stack.pop() / num))
                sign = s[i]
                num = 0
        return sum(stack)
if __name__ == '__main__':
    solution = characterStrngCalculateExpressionStack()
    a = '3 * 17 + 100 / 3 - 5 * 3 '
    print("ans is " ,solution.calculate(a))