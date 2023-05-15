//Hashaam Zafar - My first attempt at writing a neural network.
//Attempt at using a Neural network at number recognition from the MNIST database

#include <iostream>
#include <cmath> 
#include <vector>
#include <random>

//iostream is used for simple input/output
//cmath is used to facilitate the more complex math operations being handled
//vector is extremely important since the whole thing is built on the basis of vectors
//random is used for it's Gausian distribution function to initialise weights and biases

using namespace std;

//Defining the shape of the neural network
//const int input_size = 784;
//const int hidden_layers_size = 20;
//const int output_size = 10;

class NeuralNetwork
{
    public:
        vector<int> layer_sizes_;
        double learning_rate_;


        //Defining a constructor
        NeuralNetwork(const vector<int>& layer_sizes, double learning_rate) : layer_sizes_(layer_sizes), learning_rate_(learning_rate)
    {
        //Defining the structure of the weight matrix
        vector<int> weight_rows(layer_sizes_.size() - 1);
        vector<int> weight_cols(layer_sizes_.size() - 1); 
        vector<int> bias_sizes(layer_sizes_.size() - 1);

        for (int i = 0; i < layer_sizes_.size() - 1; i++)
        {
            weight_rows[i] = layer_sizes_[i+1]; //Number of rows in the weight matrix
            weight_cols[i] = layer_sizes_[i]; //Number of columns in the weight matrix
            bias_sizes[i] = layer_sizes_[i+1];
        }

        //Randomzing the values of weights 
        vector<vector<double>> weights;
        for (int i = 0; i < weight_rows.size(); i++)
        {
            vector<double> row(weight_rows[i]);
            //Randomising
            random_device SeedGen;
            mt19937 gen(SeedGen());
            //Creates a normal distribution with mean = 0 and standard deviation = 1.
            normal_distribution<double> distribution(0.0, 1.0); 
           
            for (int j = 0; j < weight_rows[i]; j++)
            {
                row[j] = distribution(gen);    
            }
        }
        //Randomizing the values of biases
        vector<vector<double>> biases;

        for (int i = 0; i < bias_sizes.size(); i++)
        {
            vector<double> row(bias_sizes[i]);
            //Randomising
            random_device SeedGen;
            mt19937 gen(SeedGen());
            //Creates a normal distribution with mean = 0 and standard deviation = 1.
            normal_distribution<double> distribution(0.0, 1.0);

            for (int j = 0; bias_sizes[i]; j++)
            {
                row[j] = distribution(gen);
            }
        }
        
    }
}
//Prototyping
//void forward_propagation();
//void backward_propagation();
//void cost_function(); 
//void ReLu();
//void loss_function();

int main(void)
{
    printf("Hello World");
}
