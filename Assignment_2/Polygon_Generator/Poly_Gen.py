import random
import matplotlib.pyplot as plt
from scipy.spatial import ConvexHull
import csv

def generate_convex_polygon(num_points, min_coord=0, max_coord=10):
    print(str(num_points) + "\n")
    points = [(random.randint(min_coord, max_coord), random.randint(min_coord, max_coord)) for _ in range(num_points)]
    points = sorted(points, key=lambda p: (p[0], p[1]))
    
    # Create a convex hull from the points
    hull = ConvexHull(points)
    polygon = [points[i] for i in hull.vertices]
    
    return polygon

def perturb_vertices(polygon, perturb_factor=0.3):
    perturbed_polygon = []
    for i, (x, y) in enumerate(polygon):
        if i % 2 == 0:  # Perturb every other vertex to create concavity
            perturb_x = x + random.randint(-1, 1) * perturb_factor * (x - polygon[i-1][0])
            perturb_y = y + random.randint(-1, 1) * perturb_factor * (y - polygon[i-1][1])
            perturbed_polygon.append((int(perturb_x), int(perturb_y)))
        else:
            perturbed_polygon.append((x, y))
    
    return perturbed_polygon

def generate_concave_polygon(num_points, min_coord=0, max_coord=10):
    convex_polygon = generate_convex_polygon(num_points, min_coord, max_coord)
    concave_polygon = perturb_vertices(convex_polygon, 0.8)
    return concave_polygon

# Set this to how many ever test cases have already been generated. Useful to index the test case files
prev_cases = 1

for i in range(1):

    # For generating test case polygons
    concave_polygon = generate_concave_polygon(20, 0, 500)
    print("Generated Concave Polygon Vertices:", concave_polygon)

    # Plot the polygon, verify visually and answer the prompt to add to test cases
    x, y = zip(*concave_polygon)
    plt.fill(x, y, edgecolor='blue', fill=False)
    plt.scatter(x, y)
    plt.grid()
    plt.show()

    # Prompt to add polygon to test cases directory
    append = input("Enter 1 to add to list of polygons. Enter 0 to not add :\n")

    # Adding test case files
    if(append):
        
        prev_cases += 1

        filename = f"Polygon_Generator/Test_Cases/Test_Case_{prev_cases}.csv"

        with open(filename, mode='w', newline='') as file:
            writer = csv.writer(file, delimiter = ' ')

            for vertex in concave_polygon:
                writer.writerow(vertex)
        
        print(f"Coordinates have been written to {filename}")
    else:
        continue