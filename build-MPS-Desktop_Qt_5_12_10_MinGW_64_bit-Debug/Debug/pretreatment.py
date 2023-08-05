#!/usr/bin/env bin
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from pandas import DataFrame
from pandas.compat import numpy
from sklearn import preprocessing
from scipy.signal import savgol_filter
from copy import deepcopy
# import pywt
from scipy import signal
import random
import scipy.stats as st
from collections import Counter

def msc(sdata):
    """
    多元散射校正
    shape (n_features, n_samples)
    """
    sdata = deepcopy(sdata)
    if isinstance(sdata, pd.DataFrame):
        sdata = sdata.values

    n = sdata.shape[1]  # 样本数量
    k = np.zeros(sdata.shape[1])
    b = np.zeros(sdata.shape[1])

    M = np.array(np.mean(sdata, axis=1))

    from sklearn.linear_model import LinearRegression

    for i in range(n):
        y = sdata[:, i]
        y = y.reshape(-1, 1)
        M = M.reshape(-1, 1)
        model = LinearRegression()
        model.fit(M, y)
        k[i] = model.coef_
        b[i] = model.intercept_

    spec_msc = np.zeros_like(sdata)
    for i in range(n):
        bb = np.repeat(b[i], sdata.shape[0])
        kk = np.repeat(k[i], sdata.shape[0])
        temp = (sdata[:, i] - bb) / kk
        spec_msc[:, i] = temp

    return spec_msc