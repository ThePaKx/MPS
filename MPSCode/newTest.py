import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.decomposition import PCA
import pandas as pd
import numpy as np

def hello():
    iris = load_iris()
    X = iris.data
    y = iris.target
    print(pd.DataFrame(X))

    # 调用PCA
    pca = PCA(n_components=2)  # 实例化 此处使用2代表降维到2个特征值，也可取mle让程序使用最大似然估计自己找寻最合适的降维超参数
    pca = pca.fit(X)  # 拟合模型
    X_dr = pca.transform(X)  # 获取新矩阵
    # X_dr = PCA(2).fit_transform(X)  # 同上两步
    print(X_dr.shape)

    plt.figure()
    colors = ['red', 'black', 'orange']
    for i in range(0, 3):
        # 画点图
        plt.scatter(X_dr[y==i, 0], X_dr[y==i, 1]
                    , alpha=.7 # 透明度设置
                    , c=colors[i], label=iris.target_names[i])
    plt.legend()
    plt.title('PCA of IRIS dataset')
    plt.show()

    # 查看降维后每个新特征向量上所带的信息量大小，即方差大小
    print(pca.explained_variance_)

    # 查看降维后每个新特征向量所占的信息量占原始数据总信息量的百分比
    # 又叫可解释性方差贡献率
    print(pca.explained_variance_ratio_)

    print(pca.explained_variance_ratio_.sum())

    # 累计可解释方差贡献率曲线来选择最好的n_components
    pca_line = PCA().fit(X)
    plt.plot([1, 2, 3, 4], np.cumsum(pca_line.explained_variance_ratio_))
    plt.xticks([1, 2, 3, 4])  # 限制坐标轴显示为整数
    plt.xlabel("number of components after dimension reduction")
    plt.ylabel("cumulative explained variance")
    plt.show()

hello()
