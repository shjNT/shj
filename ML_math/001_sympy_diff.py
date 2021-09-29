from sympy import *
"""求导数"""


x = symbols('x')
r = diff(cos(x), x)
print(r)

# 多元函数
x, y = symbols('x y')
e = exp(x*y)
r = diff(x)
print(x)
