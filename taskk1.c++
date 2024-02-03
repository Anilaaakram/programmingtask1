#include <iostream>
#include <string>
#include <cmath>  // Include cmath for std::abs function

const int CLASS_SIZE = 30;
const float MAX_WEIGHT_DIFFERENCE = 2.5;

// Function to validate weight entry
float validateWeight() {
    float weight;
    do {
        std::cout << "Enter the weight in kilograms: ";
        std::cin >> weight;

        if (weight <= 0) {
            std::cout << "Invalid weight. Weight must be positive." << std::endl;
        }

    } while (weight <= 0);

    return weight;
}

int main() {
    // Arrays to store weights and names
    float weights[CLASS_SIZE];
    std::string names[CLASS_SIZE];
    float weightDifference[CLASS_SIZE];

    // Input and store weights and names for 30 pupils
    for (int i = 0; i < CLASS_SIZE; ++i) {
        std::cout << "Enter the name of pupil " << i + 1 << ": ";
        std::cin >> names[i];

        // Validate and store weight
        weights[i] = validateWeight();

        // Calculate and store weight difference
        weightDifference[i] = weights[i] - validateWeight();
    }

    // Output names and weights
    std::cout << "\nNames and Weights of Pupils:\n";
    for (int i = 0; i < CLASS_SIZE; ++i) {
        std::cout << "Name: " << names[i] << ", Weight: " << weights[i] << " kg\n";
    }

    // Output pupils with weight difference more than 2.5 kg
    std::cout << "\nPupils with Weight Difference more than 2.5 kg:\n";
    for (int i = 0; i < CLASS_SIZE; ++i) {
        if (std::abs(weightDifference[i]) > MAX_WEIGHT_DIFFERENCE) {
            std::cout << "Name: " << names[i] << ", Difference: " << std::abs(weightDifference[i])
                      << " kg, " << (weightDifference[i] > 0 ? "Rise" : "Fall") << "\n";
        }
    }

    return 0;
}