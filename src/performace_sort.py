import matplotlib.pyplot as plt
import os

resultados_path = "src/output/resultados.txt"
if not os.path.exists(resultados_path):
    print("First, run the main C program to generate the time results in 'resultados.txt'")
    exit(1)

output_dir = "src/output"
results_path = os.path.join(output_dir, "resultados.txt")
resultados = {}
try:
    with open(results_path, "r") as file:
        for line in file:
            algoritmo, tempo = line.strip().split(": ")
            resultados[algoritmo] = float(tempo)
except FileNotFoundError:
    print(f"The file '{results_path}' was not found.")
    exit(1)

algoritmos = list(resultados.keys())
tempos = list(resultados.values())

plt.figure(figsize=(10, 5))
plt.bar(algoritmos, tempos, color='skyblue')
plt.xlabel("Sorting Algorithms")
plt.ylabel("Execution Time (seconds)")
plt.title("Execution Time Comparison of Sorting Algorithms")

# Save the chart as an image, as some systems do not support displaying the graph interactively
grafico_path = os.path.join(output_dir, "grafico.png")
plt.savefig(grafico_path)
print(f"Chart saved as '{grafico_path}'")
