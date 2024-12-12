#include <math.h>
#include "model.h"
#include "model_data.h"

// Function for ReLU activation
inline float relu(float x) {
    // TODO: Implement the ReLU activation function.
}

// Function to perform forward pass of the model
float predict(float x) {
    // The activations of the first layer are small enough to store on the stack (16 floats = 64 bytes).
    float h1[DENSE1_SIZE];

    // First dense layer. Since there is only one input neuron, we don't need to perform a full-blown matrix multiply.
    for (int i = 0; i < DENSE1_SIZE; ++i) {
        // TODO: Compute the activation of the first layer (16 x 1 vector)
    }

    // Second dense layer.
    float h2(0.0f);
    for (int i = 0; i < DENSE2_SIZE; ++i) {
        for (int j = 0; j < DENSE1_SIZE; ++j) {
            // TODO: Compute the activation of the second layer. (1 x 1 Scalar)
        }
    }

    // Output layer.
    float y(0.0f);
    for (int i = 0; i < DENSE2_SIZE; ++i) {
        // TODO: Compute the output activation. (1 x 1 Scalar)
    }

    // Final dense layer.
    return y + b3();
}
