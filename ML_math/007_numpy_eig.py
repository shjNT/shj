import numpy as np
"""求特征值和特征向量"""

A = np.random.rand(3, 3) * 10
eig_values, eig_vectors = np.linalg.eig(A)
print(eig_values)
print(eig_vectors)
