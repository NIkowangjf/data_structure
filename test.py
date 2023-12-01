import matplotlib.pyplot as plt
import numpy as np

# Define the Weibull hazard function
def weibull_hazard(t, beta, eta, gamma):
    return (beta/eta)*((t-gamma)/eta)**(beta-1)

# Set the parameters
beta = 2
eta = 10
gamma = 0

# Generate the x and y values
t = np.linspace(0, 30, 100)
l = weibull_hazard(t, beta, eta, gamma)

# Plot the function
plt.plot(t, l, color='orange', label='lambda(t)')
plt.xlabel('t')
plt.ylabel('lambda(t)')
plt.title('Weibull hazard with beta=2, eta=10, gamma=0')
plt.legend()
plt.show()