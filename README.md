#load the splited data from Adult.pickle
```python
pickle_file = 'Adult.pickle'
with open(pickle_file, 'rb') as f:
  pickle_data = pickle.load(f)
  x_private = pickle_data['x_private']
  x_attack = pickle_data['x_attack']
  x_reserved = pickle_data['x_reserved']
  y_private = pickle_data['y_private']
  y_attack = pickle_data['y_attack']
  y_reserved = pickle_data['y_reserved']
  del pickle_data
print('Data loaded.')
```
