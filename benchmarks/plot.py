import matplotlib.pyplot as plt
import pandas as pd

# Load the benchmark results from the file
data = pd.read_csv('benchmark_results.txt')

# Plotting the results
plt.figure(figsize=(10, 6))

# Plot serial addition and NEON addition
plt.plot(data['Size'], data['Serial Add (s)'], label='Serial Add', marker='o')
plt.plot(data['Size'], data['NEON Add (s)'], label='NEON Add', marker='o')

# Plot serial multiplication and NEON multiplication
plt.plot(data['Size'], data['Serial Mul (s)'], label='Serial Mul', marker='s')
plt.plot(data['Size'], data['NEON Mul (s)'], label='NEON Mul', marker='s')

# Adding labels and title
plt.xlabel('Array Size')
plt.ylabel('Average Execution Time (seconds)')
plt.title('Benchmark Comparison: Serial vs NEON')
plt.legend()

# Show the plot
plt.grid(True)
plt.savefig('benchmark_comparison.png', format='png')
plt.show()
