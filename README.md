
## Instalação

Instale as dependências necessárias.

```bash
  pip install -r requirements.txt
```
    
## Como Executar os Testes
Compile o programa em C que gera os resultados de desempenho:


```bash
  gcc main.c -o main
```
Execute o programa para gerar os dados de desempenho em resultados.txt:

```bash
  ./main
```
Para visualizar os resultados com o gráfico gerado em Python, execute:
```bash
  python src/performace_sort.py
```
O gráfico será salvo automaticamente em src/output/grafico.png.
