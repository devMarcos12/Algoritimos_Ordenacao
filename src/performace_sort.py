import matplotlib.pyplot as plt
import os

resultados_path = "src/output/resultados.txt"
if not os.path.exists(resultados_path):
    print("First, run the main C program to generate the time results in 'resultados.txt'")
    exit(1)

tempos_algoritmos = {
    "Bubble Sort": [],
    "Merge Sort": [],
    "Selection Sort": [],
    "Insertion Sort": [],
    "Heap Sort": [],
    "Quick Sort": []
}

tamanhos = [100, 1000, 10000, 50000, 100000]

with open(resultados_path, "r") as file:
    algoritmo_atual = ""
    for line in file:
        line = line.strip()
        if not line:
            continue 
        if "Tamanho do array" in line:
            continue 
        else:
            algoritmo, tempo = line.split(": ")
            tempo = float(tempo)
            tempos_algoritmos[algoritmo].append(tempo)

plt.figure(figsize=(10, 6))
for algoritmo, tempos in tempos_algoritmos.items():
    plt.plot(tamanhos, tempos, marker='o', label=algoritmo)

plt.xlabel("Array Size")
plt.ylabel("Execution Time (seconds)")
plt.title("Execution Time Comparison of Sorting Algorithms")
plt.xscale("log")
plt.yscale("log")
plt.legend()
plt.grid(True)

# Some setups don’t support generating graphs, so they are saved as PNG files.
output_dir = "src/output"
grafico_path = os.path.join(output_dir, "grafico.png")
plt.savefig(grafico_path)
print(f"Chart saved as '{grafico_path}'")
