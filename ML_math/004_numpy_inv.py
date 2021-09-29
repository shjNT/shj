import numpy as np
"""矩阵求逆"""

A = np.random.rand(4, 4)
r = np.linalg.inv(A)
print(r)


# 求伪逆
B = np.random.rand(3, 8)
r = np.linalg.pinv(B)
print(r)
