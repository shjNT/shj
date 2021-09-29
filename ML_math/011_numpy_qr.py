import numpy as np
"""QR分解： 
① 任意方阵 -->> Q:正交，R:上三角
② 非方阵 -->> Q：正交， R:主对角线以下为0
"""

A = np.random.rand(4, 4)
Q, R = np.linalg.qr(A)

print(Q)
print(R)
print(np.dot(Q, Q.T))


A = np.random.rand(4, 6)
Q, R = np.linalg.qr(A)

print(Q)
print(R)
print(np.dot(Q, Q.T))
