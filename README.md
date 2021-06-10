#从pickle文件中读取数据
```python
pickle_file = 'pickle.pickle'
with open(pickle_file, 'rb') as f:
  pickle_data = pickle.load(f)       # 反序列化，与pickle.dump相反
  X_train = pickle_data['X_train']
  X_test = pickle_data['X_test']
  y_train = pickle_data['y_train']
  y_test = pickle_data['y_test']
  del pickle_data  # 释放内存
print('Data and modules loaded.')
```
