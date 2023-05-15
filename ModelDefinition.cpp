//Hashaam Zafar - My first attempt at writing a neural network.
//Attempt at using a Neural network at number recognition from the MNIST database

#include <iostream>
#include <cmath> 
#include <vector>


using namespace std;

//Defining the shape of the neural network
const int input_size = 784;
const int hidden_layers_size = 20;
const int output_size = 10;

//Prototyping
void forward_propagation();
void backward_propagation();
void cost_function(); 
void ReLu();
void loss_function();

int main(void)
{
    printf("Hello World");
}