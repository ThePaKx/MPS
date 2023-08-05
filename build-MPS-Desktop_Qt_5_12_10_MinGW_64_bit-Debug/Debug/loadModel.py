import pandas as pd
import numpy as np
import sys
import joblib

def predict(spec, second_param):
    print("step one")
    print("second_param: ", second_param)

    path = str(second_param)
    spec = pd.DataFrame(spec)
    print("spec shape: ", spec.shape)
    spec = np.array(spec)
    print("spec shape: ", spec.shape)

    # 加载模型
    try:
        loaded_model = joblib.load(path)
        print("已加载模型")
    except FileNotFoundError:
        print(f"文件 '{path}' 不存在，请检查文件路径。")
        return None
    except OSError:
        print(f"无法打开文件 '{path}'，可能是由于权限问题或文件格式不正确。")
        return None
    except Exception as e:
        print(f"加载模型文件 '{path}' 时发生了未预料的异常：{e}")
        return None
    # 使用加载的模型进行预测
    try:
        predicted_class = loaded_model.predict(spec)
        print("已预测")
        result = []
        print("predicted_class.size(): ", predicted_class.shape)
        for i in range(predicted_class.shape[0]):
            result.append(str(predicted_class[i]))

        # 打印预测结果
        print("预测结果：", result)
        print(type(result))
        print(type(result[0]))
        return result
    except Exception:
        print("加载模型失败...")
        return None







