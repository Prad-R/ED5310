import pyvista as pv
from stl import mesh

# Load STL file using numpy-stl
mesh = pv.read("./src/stl_files/hull.stl")

# Plot it using pyvista
plotter = pv.Plotter()
plotter.add_mesh(mesh, color = 'yellow', show_edges = True, edge_color = 'black')
plotter.add_axes()  # Add axes for reference
plotter.show()  # Show the 3D interactive window
