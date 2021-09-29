import numpy as np
"""求行列式"""

A = np.random.rand(4, 4)
r = np.linalg.det(A)
print(r)
