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

def clear_diagonals(filename):

    polygon = get_polygon(filename)

    with open(filename, mode = 'w') as file:

        csv_writer = csv.writer(file, delimiter = ' ')

        for row in polygon:

            csv_writer.writerow(row)

test_cases = 15

for i in range(test_cases):

    filename = f"./Polygon_Generator/Test_Cases/Test_Case_{i + 1}.csv"

    clear_diagonals(filename)