import numpy as np
"""求解非齐次线性方程组的解： 当有唯一解"""

A = np.random.rand(3, 3)
b = np.random.rand(3, )
x = np.linalg.solve(A, b)
print(x)
