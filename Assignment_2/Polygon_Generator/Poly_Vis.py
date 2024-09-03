import matplotlib.pyplot as plt
import csv

def get_polygon(filename):

    polygon = []

    with open (filename, mode = 'r') as file:

        csv_reader = csv.reader(file, delimiter = ' ')

        for row in csv_reader:

            line = ' '.join(row)
            
            if not line.startswith("Diag:"):

                polygon.append((row[0], row[1]))


    return polygon

def get_diagonals(filename):

    diagonals = []

    with open (filename, mode = 'r') as file:

        csv_reader = csv.reader(file, delimiter = ' ')

        for row in csv_reader:

            line = ' '.join(row)
            
            if line.startswith("Diag:"):

                diagonals.append((row[1], row[2]))

    return diagonals

filename = "./Polygon_Generator/Test_Cases/Test_Case_2.csv"

polygon = get_polygon(filename)

diagonals = get_diagonals(filename)

x = []
y = []
diag_vertex_1 = []
diag_vertex_2 = []

for vertex in polygon:

    x.append(int(vertex[0]))
    y.append(int(vertex[1]))

for diagonal in diagonals:

    diag_vertex_1.append(int(diagonal[0]))
    diag_vertex_2.append(int(diagonal[1]))

print(diag_vertex_1)
print(diag_vertex_2)

plt.fill(x, y, edgecolor='blue', fill=False)
plt.scatter(x, y)

for i in range(len(diagonals)):
    
    plt.plot([x[diag_vertex_1[i]], x[diag_vertex_2[i]]], [y[diag_vertex_1[i]], y[diag_vertex_2[i]]], color = 'm')

plt.grid()

for i in range(len(x)):
    plt.annotate(i, (x[i], y[i]))

plt.show()