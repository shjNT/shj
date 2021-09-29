import numpy as np
A = np.random.rand(4, 4)
A = np.dot(A, A.T)
l = np.linalg.cholesky(A)
print(l)
