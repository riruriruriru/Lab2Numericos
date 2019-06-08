import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab

def graph(x, y, labelx, labely, title):
    plt.title(title)
    plt.xlabel(labelx)
    plt.ylabel(labely)
    plt.plot(x, y)
    plt.show()
    return
def graph2(x, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'Givens', 'Seidel')
	y = np.arange(len(objects))

	plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return

myarraySEC289 = np.fromfile('timeSegundos289.dat', dtype=float)
myarrayNSEC289 = np.fromfile('timeNanoSegundos289.dat', dtype=float)
myarraySEC1089 = np.fromfile('timeSegundos1089.dat', dtype=float)
myarrayNSEC1089 = np.fromfile('timeNanoSegundos1089.dat', dtype=float)
myarraySEC4225 = np.fromfile('timeSegundos4225.dat', dtype=float)
myarrayNSEC4225 = np.fromfile('timeNanoSegundos4225.dat', dtype=float)
print("python.uwu")
print(myarraySEC289)
print("owo")
print(myarrayNSEC289)
print("Finalizando python...")
#graph([1,2,3,4,5],myarrayNSEC,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos, matriz 289x289")
graph2(myarrayNSEC289,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 289x289")
graph2(myarraySEC289,"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 289x289")

graph2(myarrayNSEC1089,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 1089x1089")
graph2(myarraySEC1089,"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 1089x1089")

graph2(myarrayNSEC4225,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 4225x4225")
graph2(myarraySEC4225,"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 4225x4225")
