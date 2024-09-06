import csv
import matplotlib.pyplot as plt
import numpy as np

n = []
O2 = []
O4 = []

filename_2 = "./src/Testing_and_Visualisation/Saved_Data/Run_Time_2.csv"

with open(filename_2, mode = 'r') as file:

        csv_reader = csv.reader(file, delimiter = ' ')

        for row in csv_reader:

            line = ' '.join(row)
            
            if line.startswith("Run:"):
                
                n.append(int(row[1]))
                O2.append(float(row[2]))

filename_4 = "./src/Testing_and_Visualisation/Saved_Data/Run_Time_4.csv"

with open(filename_4, mode = 'r') as file:

        csv_reader = csv.reader(file, delimiter = ' ')

        for row in csv_reader:

            line = ' '.join(row)
            
            if line.startswith("Run:"):
                
                O4.append(float(row[2]))

n = np.array(n)
nlogn = n * np.emath.logn(2, n)

plt.figure(figsize = (10, 7.5))
plt.scatter(n, O2, label = "$O(n^2) =$ Ear Clipping Algorithm", color = 'g')
plt.scatter(n, O4, label = "$O(n^4) =$ Naive Algorithm", color = 'r')
# plt.scatter(n, nlogn, color = 'b', label = "$O(nlog(n)) =$ Fast Algorithm")
plt.legend()
plt.grid()
plt.xticks(np.arange(0, 110, 10))
plt.xlabel("$n \\longrightarrow$", fontsize = 15)
plt.ylabel("Run Time (in $\mu s$) $\\longrightarrow$", fontsize = 15)
plt.title("Run Time Complexity of the Algorithsm", fontsize = 18)
plt.savefig("./src/Testing_and_Visualisation/Complexity.png")
plt.show()