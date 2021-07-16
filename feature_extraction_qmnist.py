# Script to convert images into tabular data for QMNIST
import pickle
import numpy as np
import cv2 as cv
import tensorflow as tf
from PIL import Image

from tensorflow.keras.models import Model


# Load QMNIST data from QMNIST.pickle
pickle_file = './QMNIST.pickle'
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

# Resize the images
def resize_image(images):
  resized_images = []
  for img in images:
    temp_img = cv.resize(img, (32,32), interpolation=4)
    temp_img = Image.fromarray(temp_img.astype('uint8')).convert('RGB')
    final_img = np.array(temp_img)
    resized_images.append(final_img)
  resized_images = np.array(resized_images)
  return resized_images


if __name__ == '__main__':

  x_private = resize_image(x_private)
  x_attack = resize_image(x_attack)
  x_reserved = resize_image(x_reserved)
  
  base_model = tf.keras.applications.VGG19(weights='imagenet',include_top=False)
  model = Model(inputs=base_model.input, outputs=base_model.get_layer('block5_pool').output)
  
  x_private_features = model.predict(x_private)
  x_attack_features = model.predict(x_attack)
  x_reserved_features = model.predict(x_reserved)
  
  x_private_tabular = x_private_features
  x_attack_tabular = x_attack_features
  x_reserved_tabular = x_reserved_features
  
  x_private_tabular = x_private_tabular.squeeze()
  x_attack_tabular = x_attack_tabular.squeeze()
  x_reserved_tabular = x_reserved_tabular.squeeze()
  print(x_private_tabular.shape)
  # Create dict of partitions
  
  split_dict = dict()
  split_dict['x_private'] = x_private_tabular
  split_dict['x_attack'] = x_attack_tabular
  split_dict['x_reserved'] = x_reserved_tabular
  split_dict['y_private'] = y_private
  split_dict['y_attack'] = y_attack
  split_dict['y_reserved'] = y_reserved

  # Store the dict using pickle
  with open('QMNIST_tabuler.pickle', 'wb') as f:
    pickle.dump(split_dict, f)
    
  print('Tabular data stored.')
