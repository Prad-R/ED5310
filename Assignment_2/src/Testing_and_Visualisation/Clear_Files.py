import csv
import os

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

os.system("rm ./src/Testing_and_Visualisation/Run_Time_2.csv")
os.system("rm ./src/Testing_and_Visualisation/Run_Time_4.csv")

test_cases = 100

for i in range(test_cases):

    filename = f"./src/Testing_and_Visualisation/New_Test_Cases/Test_Case_{i + 4}.csv"

    clear_diagonals(filename)