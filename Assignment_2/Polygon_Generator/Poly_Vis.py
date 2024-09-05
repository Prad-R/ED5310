import matplotlib.pyplot as plt
import matplotlib.animation as animation
import csv
import numpy as np

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

test_cases = 15

for i in range(test_cases):

    filename = f"./Polygon_Generator/Test_Cases/Test_Case_{i + 1}.csv"

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

    fig, ax = plt.subplots(figsize = (16,9))
    line, = ax.plot([], [], 'ro-', linewidth = 6)

    ax.fill(x, y, facecolor = 'yellow', alpha = 0.5)
    ax.fill(x, y,  edgecolor = 'k', linewidth = 2.5, fill = False)
    ax.scatter(x, y, color = 'r')

    for i in range(len(diagonals)):
        
        ax.plot([x[diag_vertex_1[i]], x[diag_vertex_2[i]]], [y[diag_vertex_1[i]], y[diag_vertex_2[i]]], color = 'g', linewidth = 1)

    # Initialization function
    def init():
        line.set_data([], [])
        return line,

    # Animation function
    def animate(i):
        line.set_data([x[diag_vertex_1[i]], x[diag_vertex_2[i]]], [y[diag_vertex_1[i]], y[diag_vertex_2[i]]])
        return line,

    # Create the animation with more frames and a shorter interval
    ani = animation.FuncAnimation(fig, animate, init_func = init, frames = len(diagonals), interval = 500, repeat = False)

    ax.grid()

    for i in range(len(x)):
        ax.annotate(i, (x[i], y[i]), fontsize = 15, fontweight = 'bold')

    mng = plt.get_current_fig_manager()
    mng.full_screen_toggle()

    plt.show(block = False)
    plt.pause(len(diagonals) * 0.5 + 0.5)
    plt.close()