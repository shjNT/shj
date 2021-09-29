import numpy as np
"""求矩阵条件数：||A||*||A-1||"""

A = np.random.rand(4, 4)
r = np.linalg.cond(A)
print(r)
