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

void printnetwork(vector<vector<double>> myVector);

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
                        cout << weights_[i][j][k] << endl;
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
            forward_propagation(input_layer);
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

        //Haven't added biases yet
        vector<double> forward_propagation(vector<double> input_vector)
        {
            //Repeats for each layer 
            for (int i = 0; i < weights_.size(); i++)
            {
                vector<double> current_layer = input_vector;
                input_vector.clear();
                //For each node
                for (int j = 0; j < weights_[i].size(); j++)   
                {
                    //Taking dot product
                    double resultant_node = inner_product(weights_[i][j].begin(), weights_[i][j].end(), current_layer.begin(), 0.0);
                    resultant_node += biases_[i][j];
                    cout << resultant_node << endl;
                    
                    input_vector.push_back(resultant_node);
                }
                cout << endl;
            }
            return input_vector;
        }


};
//Prototyping
//void forward_propagation();
//void backward_propagation();
//void cost_function(); 
//void ReLu();
//void loss_function();


int main(void)
{
    cout << "Hello World" << endl;
    vector<int> Kash = {3, 3, 3, 3};
    NeuralNetwork Hash(Kash, 4);
    Hash.fprop({1, 1, 1});
    Hash.printbiases();
    Hash.print();
    cout << endl;
}
 
void printnetwork(vector<vector<double>> myVector)
{
    for (int i = 0; i < myVector.size(); i++) {
    for (int j = 0; j < myVector[i].size(); j++) {
        cout << myVector[i][j] << " ";
    }
    cout << endl;
}
 
}
