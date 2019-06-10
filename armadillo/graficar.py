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
	

def graph2SinSeidel(x, labelx, labely, title):
	print("Graficando sin seidel")
	print(len(x))
	print(x)
	objects = ('LU', 'Cholesky', 'QR', 'Givens')
	y = np.arange(len(objects))
	print(y)
	plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return


def graphError(iteraciones, errores, labelx, labely, title):
	# Creates two subplots and unpacks the output array immediately
	x = np.arange(int(iteraciones))
	f, (ax1, ax2) = plt.subplots(1, 2)
	ax1.semilogy(x, errores)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	ax1.set_title(title)
	ax2.set_title("Iteraciones vs Error, sin ajuste logarítmico")
	ax2.plot(x, errores)
	#plt.semilogy(x, errores)
	#plt.ylabel(labely)
	#plt.xlabel(labelx)
	#plt.title(title)
	plt.show()

def graphNano(xSec, xNano, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'Givens', 'Seidel')
	y = np.arange(len(objects))
	cont = 0
	x = xNano[:]
	for i in xNano:
		x[cont] = i + xSec[cont]*10**9
		cont = cont +1
	plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return


def graphNanoSinSeidel(xSec, xNano, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'Givens')
	y = np.arange(len(objects))
	cont = 0
	x = xNano[:]
	for i in xNano:
		x[cont] = i + xSec[cont]*10**9
		cont = cont +1
	plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return

def graphSec(xSec, xNano, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'Givens', 'Seidel')
	y = np.arange(len(objects))
	cont = 0
	x = xNano[:]
	for i in xNano:
		x[cont] = i + xSec[cont]*10**9
		cont = cont +1
	plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return


def graphSecSinSeidel(xSec, xNano, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'Givens')
	y = np.arange(len(objects))
	cont = 0
	x = xNano[:]
	for i in xNano:
		x[cont] = i + xSec[cont]*10**9
		cont = cont +1
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
solucionesSeidel289 = np.fromfile('Seidel289Soluciones.dat',dtype = float)
solucionSeidel289 = np.fromfile('Seidel289Solucion.dat',dtype = float)
erroresSeidel289 = np.fromfile('Seidel289Errores.dat',dtype = float)
iteracionesSeidel289 = np.fromfile('Seidel289Iteraciones.dat',dtype = float)

solucionesSeidel1089 = np.fromfile('Seidel1089Soluciones.dat',dtype = float)
solucionSeidel1089 = np.fromfile('Seidel1089Solucion.dat',dtype = float)
erroresSeidel1089 = np.fromfile('Seidel1089Errores.dat',dtype = float)
iteracionesSeidel1089 = np.fromfile('Seidel1089Iteraciones.dat',dtype = float)


solucionesSeidel4225 = np.fromfile('Seidel4225Soluciones.dat',dtype = float)
solucionSeidel4225 = np.fromfile('Seidel4225Solucion.dat',dtype = float)
erroresSeidel4225 = np.fromfile('Seidel4225Errores.dat',dtype = float)
iteracionesSeidel4225 = np.fromfile('Seidel4225Iteraciones.dat',dtype = float)

inicio = len(solucionSeidel289)-94
fin = len(solucionSeidel289)-1
print(solucionesSeidel289[inicio:fin])
solucionesSeidel289 = solucionesSeidel289.reshape(int(iteracionesSeidel289),289)
errorSeidel289 = np.fromfile('Seidel289error.dat',dtype = float)
print("python.uwu")
print(myarraySEC289)
print("owo")
print(myarrayNSEC289)
print("Soluciones Seidel: ")
print(solucionesSeidel289)
print("Solucion final seidel1: ")
print(solucionesSeidel289[93,:]);
print("Solucion final seidel1: ")
print(solucionSeidel289)
print("###############################")
print("Iteraciones seidel: ")
print(iteracionesSeidel289)
print("errores seidel: ")
print(erroresSeidel289)
print("error seidel: ")
print(errorSeidel289)
print("Dimensiones: ")
print(np.shape(solucionesSeidel289))
print(len(erroresSeidel289))
print(solucionesSeidel289[:,93])
np.savetxt('test.out', solucionesSeidel289[:,93], delimiter=',')
np.savetxt('test2.out', solucionSeidel289, delimiter=',')
print("Finalizando python...")



#graph([1,2,3,4,5],myarrayNSEC,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos, matriz 289x289")
graph2(myarrayNSEC289,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 289x289")
graph2(myarraySEC289,"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 289x289")
graphNano(myarraySEC289, myarrayNSEC289, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 289x289")
graphError(iteracionesSeidel289, erroresSeidel289, "Iteraciones", "Error", "Iteraciones vs Error matriz 289x289, ajuste logarítmico")
graph2SinSeidel(myarraySEC289[:4],"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 289x289")
graphNanoSinSeidel(myarraySEC289[:4], myarrayNSEC289[:4], "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 289x289")
graphSec(myarrayNSEC289,myarraySEC289, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 289x289")
graphSecSinSeidel(myarrayNSEC289[:4],myarraySEC289[:4], "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 289x289")




graph2(myarrayNSEC1089,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 1089x1089")
graph2(myarraySEC1089,"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 1089x1089")
graphNano(myarraySEC1089, myarrayNSEC1089, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 1089x1089")
graphError(iteracionesSeidel1089, erroresSeidel1089, "Iteraciones", "Error", "Iteraciones vs Error, matrix 1089x1089, ajuste logarítmico")
graph2SinSeidel(myarraySEC1089[:4],"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 1089x1089")
graphNanoSinSeidel(myarraySEC1089[:4], myarrayNSEC1089[:4], "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 1089x1089")
graphSec(myarraySEC1089, myarrayNSEC1089, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 1089x1089")
graphSecSinSeidel(myarraySEC1089[:4], myarrayNSEC1089[:4], "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 1089x1089")



graph2(myarrayNSEC4225,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 4225x4225")
graph2(myarraySEC4225,"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 4225x4225")
graphNano(myarraySEC4225, myarrayNSEC4225, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 4225x4225")
graphError(iteracionesSeidel4225, erroresSeidel4225, "Iteraciones", "Error", "Iteraciones vs Error, matriz 4225x4225, ajuste logarítmico")
graph2SinSeidel(myarraySEC4225[:4],"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 4225x4225")
graphNanoSinSeidel(myarraySEC4225[:4], myarrayNSEC4225[:4], "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 4225x4225")
graphSec(myarraySEC4225, myarrayNSEC4225, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 4225x4225")
graphSecSinSeidel(myarraySEC4225[:4], myarrayNSEC4225[:4], "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 4225x4225")

