## load the split data from Adult.pickle
```python
import pickle 

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

## Execute the script to split the QMNIST data and create QMNIST.pickle
Libraries needed:
numpy >=1.19.5
```bash
python split_qmnist.py
```
## load the split data from QMNIST.pickle
```python
import pickle 

pickle_file = 'QMNIST.pickle'
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