## Adult dataset
To load the split data from Adult.pickle:
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

## QMNIST dataset
We use [QMNIST](https://github.com/facebookresearch/qmnist) dataset, which can be directly downloaded and processed using torchvision.datasets library. The original paper by Chhavi Yadav and Léon Bottou can be found [here](https://arxiv.org/pdf/1905.10498.pdf)

1. First, you need to execute the script to create QMNIST.pickle
```bash
python split_qmnist.py
```
Libraries used:
* numpy == 1.19.5
* torchvision == 0.9.1

2. Secondly, you load the QMNIST.pickle in the same way as the Adult dataset.
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
The 'x' contains the images as numpy arrays with shape (n_images,28,28), with values from 0 to 255 (dtype=uint8)
The 'y' contains the arrays of targets, with shape (n_images,8). Each of the 8 values contain the following information:

| Position | Description  | Range |
|:------:|--------------|-------|
| 0 | Character class | 0 to 9
| 1 | NIST HSF series | 0, 1, 2, 3, 4, 6, or 7
| 2 | NIST writer ID | 0-2599 and 3100-4099  
| 3 | Digit index for this writer | 0 to 146
| 4 | NIST class code | 30-39
| 5 | Global NIST digit index | 0 to 402952
| 6 | Duplicate | 0
| 7 | Unused | 0

Source: [Original QMNIST repository](https://github.com/facebookresearch/qmnist)
