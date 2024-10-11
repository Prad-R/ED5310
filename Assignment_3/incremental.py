# Before starting, ensure that all the executable files in the "./src/" directory have execute permissions
# If not, use `chmod 755 ./<relative_path_to_file>/<file_name>` to give the necessary permissions

import os

os.system("make clean -C ./src")

print("\n----------------------------------------------------------------\n")

os.system("make -C ./src")

print("\n----------------------------------------------------------------\n")

n_points = input("Enter the number of points you want to generate : ")

os.system("rm ./src/stl_files/hull.stl")
os.system(f"./src/incremental.bin {n_points}")

print("\n------------------- Hull Complete -----------------------\n")
print("\n----------------------------------------------------------------\n")

os.system("python3 visualizer.py")