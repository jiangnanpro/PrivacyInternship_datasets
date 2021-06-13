# Script to reproduce the split of QMNIST.pickle
import pickle

from torchvision.datasets import QMNIST # version 0.9.1
import numpy as np # version 1.19.5

# Load QMNIST data from torchvision.datasets
qall = QMNIST('qmnist', what='nist', download=True, compat=False)

qmnist_images = qall.data.numpy()
qmnist_targets = qall.targets.numpy()

qmnist_len = qmnist_images.shape[0]

# Set the size of each partition of the split
private_partition_ratio = 1/5
reserved_partition_ratio = 1/5

private_partition_size = int(qmnist_len*private_partition_ratio)+10
reserved_partition_size = int(qmnist_len*reserved_partition_ratio)+10

# Randomly selecting the images for each partition
rng = np.random.RandomState(2021)
random_seq = rng.choice(qmnist_len,size=private_partition_size+reserved_partition_size, replace=False)

private_partition_indexes = random_seq[0:private_partition_size]
reserved_partition_indexes = random_seq[private_partition_size:]
attack_partition_indexes = np.setdiff1d(np.array(range(qmnist_len)),random_seq, assume_unique=True)

# Create dict of partitions
split_dict = dict()
split_dict['x_private'] = qmnist_images[private_partition_indexes]
split_dict['x_attack'] = qmnist_images[attack_partition_indexes]
split_dict['x_reserved'] = qmnist_images[reserved_partition_indexes]
split_dict['y_private'] = qmnist_targets[private_partition_indexes]
split_dict['y_attack'] = qmnist_targets[attack_partition_indexes]
split_dict['y_reserved'] = qmnist_targets[reserved_partition_indexes]

# Store the dict using pickle
with open('QMNIST.pickle', 'wb') as f:
    pickle.dump(split_dict, f)