from polygenerator import (
    random_polygon,
    random_star_shaped_polygon,
    random_convex_polygon,
)

import matplotlib.pyplot as plt
import random
import csv

for i in range(4, 201):
    n_vertices = i
    scale_factor = 2000

    polygon = random_polygon(num_points = n_vertices)

    x = []
    y = []
    vertices = []

    for i in range(len(polygon)):
        x.append(int(polygon[i][0] * scale_factor))
        y.append(int(polygon[i][1] * scale_factor))
        vertices.append([x[i], y[i]])

    """ fig, ax = plt.subplots()

    ax.fill(x, y, facecolor = 'yellow', alpha = 0.5)
    ax.fill(x, y,  edgecolor = 'k', linewidth = 2.5, fill = False)
    ax.scatter(x, y, color = 'r')
    ax.grid()

    for i in range(len(x)):
        ax.annotate(i, (x[i], y[i]), fontsize = 10, fontweight = 'bold')

    plt.show() """

    filename = f"./src/Testing_and_Visualisation/New_Test_Cases/Test_Case_{i + 1}.csv"

    with open(filename, mode = 'w', newline = '') as file:
        writer = csv.writer(file, delimiter = ' ')

        for vertex in vertices:
            writer.writerow(vertex)