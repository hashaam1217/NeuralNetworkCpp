//Hashaam Zafar - My first attempt at writing a neural network.
//Attempt at using a Neural network at number recognition from the MNIST database

#include <iostream>
#include <cmath> 
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

void printnetwork(vector<vector<double>> myVector);
double ReLU(double x);
vector<double> softmax(vector<double> x); 

class NeuralNetwork
{
    public:
        double learning_rate_;
        vector<int> layer_sizes_;
        
        //This function prints weights
        void print()
        {
            cout << "weights start" << endl;

            for (int i = 0; i < weights_.size(); i++)
            {
                for (int j = 0; j < weights_[i].size(); j++)
                {
                    for (int k = 0; k < weights_[i][j].size(); k++)
                    {
                        cout << weights_[i][j][k] << " " << i << " " << j << " " << k << endl;
                        //cout << weights_[i][j][k] << endl;

                    }
                    cout << endl;
                }
                cout <<"end layer"<< endl << endl;
            }
            cout << endl;
        }

        void printbiases()
        {
            printnetwork(biases_);
        }

        //Public forward propagation function
        void fprop(vector<double> input_layer)
        {
            vector<double> output = forward_propagation(input_layer);
            for (int i = 0; i < output.size(); i++)
            {
                cout << output[i] << endl;
            }
        }

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


      vector<vector<double>> current_layer_weights;
      //Randomzing the values of weights 
      for (int i = 0; i < weight_rows.size(); i++)
      {
          vector<double> row(weight_rows[i]);
          //Randomising
          random_device SeedGen;
          mt19937 gen(SeedGen());
          //Creates a normal distribution with mean = 0 and standard deviation = 1.
          normal_distribution<double> distribution(0.0, 1.0); 
           
          for (int j = 0; j < weight_cols[i]; j++)
              {
                  for (int k = 0; k < weight_rows[i]; k++)
                  {
                      row[k] = distribution(gen);    
                  }
                  //Adds the individual row to the current layer weights vector matrix
                  current_layer_weights.push_back(row);
              }
              //Adds the current layer weight matrix of this layer to a vector of matrixes
              weights_.push_back(current_layer_weights);
              current_layer_weights.clear();
      }
      

      //Randomizing the values of biases
      for (int i = 0; i < bias_sizes.size(); i++)
      {
          vector<double> row(bias_sizes[i]);
          //Randomising
          random_device SeedGen;
          mt19937 gen(SeedGen());
          //Creates a normal distribution with mean = 0 and standard deviation = 1.
          normal_distribution<double> distribution(0.0, 1.0);

          for (int j = 0; j < bias_sizes[i]; j++)
          {
              row[j] = distribution(gen);
          }
          
          //Adds the individual row to the final bias vector matrix
          biases_.push_back(row);    
      }
    }
    private:
        vector<vector<vector<double>>> weights_;
        vector<vector<double>> biases_;

        //Note for later: Instead of individual multiplications, we can add all the weights for the current node
        //and then multiply that by the input_vector member.
        vector<double> forward_propagation(vector<double> input_vector)
        {
            //Repeats for each layer 
            for (int i = 0; i < weights_.size(); i++)
            {
                vector<double> current_layer = input_vector;
                input_vector.clear();
                //For number of weights 
                for (int j = 0; j < biases_[i].size(); j++)   
                {
                    double resultant_node = 0;
                    //To add result from each node's weight
                    for (int k = 0; k < weights_[i].size(); k++)
                    {
                        resultant_node += input_vector[j] * weights_[i][k][j];
                    }

                    resultant_node += biases_[i][j];
                    
                    //Applying activation function
                    if (i != weights_[i].size() - 1)
                    {
                        //Apply RelU for hidden layers
                        resultant_node = ReLU(resultant_node);
                    }

                    cout << resultant_node << endl;
                    input_vector.push_back(resultant_node);
                }
                cout << endl;
            }
            //Applying soft max function to final layer.
            return softmax(input_vector);
        }


};
//Prototyping
//void forward_propagation();
//void backward_propagation();
//void cost_function(); 
//void ReLU();
//void loss_function();


int main(void)
{
    cout << "Hello World" << endl;
    vector<int> Kash = {2, 3, 4, 2};
    NeuralNetwork Hash(Kash, 4);
    cout << endl;
    Hash.printbiases();
    Hash.print();
    cout << endl;
    Hash.fprop({2, 2});
}
 
void printnetwork(vector<vector<double>> myVector)
{
    for (int i = 0; i < myVector.size(); i++) 
    {
        for (int j = 0; j < myVector[i].size(); j++) 
        {
            cout << myVector[i][j] << " ";
        }
    cout << endl;
    }
 
}

double ReLU(double x) 
{
    return x > 0 ? x : 0;
}

vector<double> softmax(vector<double> x) 
{
    double maxVal = *max_element(x.begin(), x.end());
    double sum = 0.0;
    vector<double> y(x.size());
    for (int i = 0; i < x.size(); i++) {
        y[i] = exp(x[i] - maxVal);
        sum += y[i];
    }
    for (int i = 0; i < y.size(); i++) {
        y[i] /= sum;
    }
    return y;
}

