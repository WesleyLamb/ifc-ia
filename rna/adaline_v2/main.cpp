#include <iostream>
#include <vector>
#include <numeric> // For std::inner_product

class Adaline {
public:
    // Constructor
    Adaline(int num_inputs, double learning_rate = 0.01, int epochs = 100)
        : num_inputs_(num_inputs), learning_rate_(learning_rate), epochs_(epochs) {
        // Initialize weights with small random values
        weights_.resize(num_inputs + 1); // +1 for bias weight
        weights_.at(0) = -0.5;
        weights_.at(1) = 0;
        weights_.at(2) = 0.5;
        // for (int i = 0; i <= num_inputs; ++i) {
        //     weights_[i] = (double)rand() / RAND_MAX * 0.1 - 0.05; // Random values between -0.05 and 0.05
        // }
    }

    // Train the Adaline network
    void train(const std::vector<std::vector<double>>& X, const std::vector<double>& y) {
        for (int epoch = 0; epoch < epochs_; ++epoch) {
            double total_error = 0.0;
            for (size_t i = 0; i < X.size(); ++i) {
                // Add bias input (x0 = 1)
                std::vector<double> x_with_bias = X[i];
                x_with_bias.insert(x_with_bias.begin(), 1.0); // Bias input at index 0

                // Calculate net input
                double net_input = calculate_net_input(x_with_bias);

                // Calculate output (linear activation for Adaline)
                double output = net_input;

                // Calculate error
                double error = y[i] - output;
                total_error += error * error;

                // Update weights using the Delta Rule
                for (int j = 0; j <= num_inputs_; ++j) {
                    weights_[j] += learning_rate_ * error * x_with_bias[j];
                }
            }
            // Optional: Print average MSE for each epoch
            std::cout << "Epoch " << epoch + 1 << ", MSE: " << total_error / X.size() << std::endl;
        }
    }

    // Predict output for a given input
    double predict(const std::vector<double>& x) const {
        std::vector<double> x_with_bias = x;
        x_with_bias.insert(x_with_bias.begin(), 1.0); // Bias input

        double net_input = calculate_net_input(x_with_bias);
        return (net_input >= 0.0) ? 1.0 : -1.0; // Step function for final classification
    }

private:
    int num_inputs_;
    double learning_rate_;
    int epochs_;
    std::vector<double> weights_;

    // Helper function to calculate the weighted sum of inputs
    double calculate_net_input(const std::vector<double>& x_with_bias) const {
        return std::inner_product(x_with_bias.begin(), x_with_bias.end(), weights_.begin(), 0.0);
    }
};

int main() {
    // Training data for an OR gate
    std::vector<std::vector<double>> X = {
        {-1.0, -1.0},
        {-1.0, 1.0},
        {1.0, -1.0},
        {1.0, 1.0}
    };

    // Create and train Adaline
    {
        std::vector<double> y = {-1.0, -1.0, -1.0, 1.0}; // Desired outputs
        Adaline adaline(2, 0.1, 10); // 2 inputs, learning rate 0.1, 100 epochs
        adaline.train(X, y);

        std::cout << "And" << std::endl;
        for (size_t i = 0; i < X.size(); ++i) {
            double prediction = adaline.predict(X[i]);
            std::cout << prediction << std::endl;
            // std::cout << "Input: {" << X[i][0] << ", " << X[i][1] << "}, Predicted: " << prediction
            //           << ", Actual: " << y[i] << std::endl;
        }
    }
    // Create and train Adaline
    {
        std::vector<double> y = {-1.0, 1.0, 1.0, 1.0}; // Desired outputs
        Adaline adaline(2, 0.1, 10); // 2 inputs, learning rate 0.1, 100 epochs
        adaline.train(X, y);

        std::cout << "Or" << std::endl;
        for (size_t i = 0; i < X.size(); ++i) {
            double prediction = adaline.predict(X[i]);
            std::cout << prediction << std::endl;
            // std::cout << "Input: {" << X[i][0] << ", " << X[i][1] << "}, Predicted: " << prediction
            //           << ", Actual: " << y[i] << std::endl;
        }
    }// Create and train Adaline
    {
        std::vector<double> y = {-1.0, 1.0, 1.0, -1.0}; // Desired outputs
        Adaline adaline(2, 0.1, 10); // 2 inputs, learning rate 0.1, 100 epochs
        adaline.train(X, y);

        std::cout << "Xor" << std::endl;
        for (size_t i = 0; i < X.size(); ++i) {
            double prediction = adaline.predict(X[i]);
            std::cout << prediction << std::endl;
            // std::cout << "Input: {" << X[i][0] << ", " << X[i][1] << "}, Predicted: " << prediction
            //           << ", Actual: " << y[i] << std::endl;
        }
    }

    return 0;
}