#include <math.h>
#include "model.h"
#include "model_data.h"

// Function for ReLU activation
inline float relu(float x) {
    return fmax(0.0f, x);  // ReLU(x) = max{0, x}
}

// Function to perform forward pass of the model
float predict(float x) {
    // Step 1: First layer (input -> hidden layer 1)
    float h1[DENSE1_SIZE];
    
    // Perform W1 * x + b1 and apply ReLU
    for (int i = 0; i < DENSE1_SIZE; ++i) {
        h1[i] = relu(W1_data[i] * x + b1_data[i]);
    }
    
    // Step 2: Second layer (hidden layer 1 -> hidden layer 2)
    float h2[DENSE2_SIZE];
    
    // Matrix multiplication W2 * h1 + b2 and apply ReLU
    for (int i = 0; i < DENSE2_SIZE; ++i) {
        float sum = 0.0f;
        for (int j = 0; j < DENSE1_SIZE; ++j) {
            sum += W2_data[i * DENSE1_SIZE + j] * h1[j];  // Matrix multiplication
        }
        h2[i] = relu(sum + b2_data[i]);  // Apply ReLU to the second layer output
    }
    
    // Step 3: Output layer (hidden layer 2 -> output)
    float y = 0.0f;
    
    // Matrix multiplication W3 * h2 and add bias b3
    for (int i = 0; i < DENSE2_SIZE; ++i) {
        y += W3_data[i] * h2[i];
    }
    
    // Add bias b3 to the final output
    float final_output = y + b3_data[0];
    
    // Step 4: Return the sine of the final output for modulation
    return sinf(final_output);
}
