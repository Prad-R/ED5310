# Before starting, ensure that all the executable files in the "./src/" directory have execute permissions
# If not, use `chmod 755 ./<relative_path_to_file>/<file_name>` to give the necessary permissions

import os

os.system("make clean -C ./src")

print("\n----------------------------------------------------------------\n")

os.system("make -C ./src")

print("\n----------------------------------------------------------------\n")

os.system("python3 src/Testing_and_Visualisation/Clear_Files.py")

print("\n-------------------Cleared all Diagonals------------------------\n")
print("\n----------------------------------------------------------------\n")

# Can take integral values between 1 and 15
test_cases = 100

# Can take either 2 or 4 as the value
complexity = 2

os.system(f"./src/triangulate.bin {complexity} {test_cases}")

print("\n-------------------Triangulation Complete-----------------------\n")
print("\n----------------------------------------------------------------\n")

# os.system(f"python3 src/Testing_and_Visualisation/Poly_Vis.py {test_cases}")

print("\n-------------------Visualised the Polygons---------------------\n")
print("\n----------------------------------------------------------------\n")