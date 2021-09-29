import numpy as np
"""
矩阵的奇异值分解:
A = U sigma V.T -->> A的奇异值为AA.T的特征值的非负平方根
U、V正交
"""

A = np.random.rand(4, 5)
U, sigma, VT = np.linalg.svd(A)
print(U)
print(sigma)
print(VT)
