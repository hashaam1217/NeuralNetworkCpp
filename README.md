# NeuralNetworkCpp

# Neural Network in C++
This is a simple implementation of a neural network in C++. The goal of this project is to provide a basic framework for building and training neural networks from scratch. The network is designed to recognize handwritten digits from the MNIST database.

### Disclaimer: This project is currently a work in progress and may not be fully functional 

# Getting Started
To get started with the project, you will need a C++ compiler and the following libraries:

- iostream
- cmath
- vector
- random

To run the project, simply compile the main.cpp file and run the resulting executable.

# Neural Network Structure
The neural network implemented in this project consists of an input layer, one or more hidden layers, and an output layer. The number of nodes in each layer is configurable, allowing you to customize the network architecture for different tasks.

The weights and biases of the network are randomly initialized using a Gaussian distribution with mean 0 and standard deviation 1. The network uses the ReLU activation function in the hidden layers and the softmax activation function in the output layer.

# Training the Network
The network is trained using backpropagation and stochastic gradient descent. The cost function used is the cross-entropy loss function, which is commonly used for classification tasks.

To train the network, you will need a labeled training dataset. The network can be trained using the train function, which takes in the training dataset as input and updates the weights and biases of the network using stochastic gradient descent.

# Testing the Network
After training, you can test the performance of the network using a validation dataset. The accuracy of the network can be evaluated using the test function, which takes in the validation dataset as input and returns the accuracy of the network on the dataset.

# Customizing the Network
The network architecture, learning rate, number of epochs, and other hyperparameters can be customized by modifying the code in the main.cpp file. You can experiment with different network architectures and hyperparameters to see how they affect the performance of the network.

# Conclusion
This project provides a simple example of how to implement a neural network in C++. By understanding the code and customizing the network, you can gain a better understanding of how neural networks work and how they can be used for various tasks.
