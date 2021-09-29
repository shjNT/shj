from sympy import *
"""求积分"""

# 1.不定积分
x = symbols('x')
r = integrate(cosh(x), x)
print(r)

# 2.定积分
x = symbols('x')
r = integrate(cos(x), (x, 0, pi/2))
print(r)
