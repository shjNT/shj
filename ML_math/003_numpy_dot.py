import numpy as np
"""矩阵、向量乘法"""

A = np.random.random((2, 3))
B = np.random.random((3, 4))
r = np.dot(A, B)
print(r)
