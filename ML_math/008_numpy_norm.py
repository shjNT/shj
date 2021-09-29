import numpy as np
"""求矩阵、向量范数"""

A = np.array([[1, 1], [0, 1]])
a = np.array([2, 2, 1])

# 1.矩阵的F范数和向量的2范数
r1 = np.linalg.norm(A)
r2 = np.linalg.norm(a)
print(r1)
print(r2)

# 2.矩阵的谱范数和向量的2范数
r1 = np.linalg.norm(A, ord=2)
r2 = np.linalg.norm(a, ord=2)
print(r1)
print(r2)

# 3.矩阵的1范数和向量的1范数
r1 = np.linalg.norm(A, ord=1)
r2 = np.linalg.norm(a, ord=1)
print(r1)
print(r2)

# 4.矩阵和向量的无穷范数
r1 = np.linalg.norm(A, ord=np.inf)
r2 = np.linalg.norm(a, ord=np.inf)
print(r1)
print(r2)
print("=="*20)

# 5.矩阵的核范数：矩阵奇异值的和
r1 = np.linalg.norm(A, ord='nuc')
# r2 = np.linalg.norm(a, ord='nuc')
print(r1)
# print(r2)