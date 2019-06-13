import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab
import scipy.io as sio


def graph(x, y, labelx, labely, title):
    plt.title(title)
    plt.xlabel(labelx)
    plt.ylabel(labely)
    plt.plot(x, y)
    plt.show()
    return
def graph2(x, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'LS','Givens', 'Seidel')
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
	objects = ('LU', 'Cholesky', 'QR', 'LS', 'Givens')
	y = np.arange(len(objects))
	print(y)
	plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return


def graphError(iteraciones, errores,matlabErrors, labelx, labely, title):
	# Creates two subplots and unpacks the output array immediately
	x = np.arange(int(iteraciones))
	xx = np.arange(len(matlabErrors))
	
	f, (ax1, ax2) = plt.subplots(1, 2)
	ax1.semilogy(x, errores)
	ax1.semilogy(xx, matlabErrors)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	ax1.set_title(title)
	ax1.legend(['Error Seidel Armadillo','Error Seidel Matlab'])
	ax2.set_title("Iteraciones vs Error, sin ajuste logarítmico")
	ax2.plot(x, errores)
	ax2.plot(xx,matlabErrors)
	ax2.legend(['Error Seidel Armadillo','Error Seidel Matlab'])

	#plt.semilogy(x, errores)
	#plt.ylabel(labely)
	#plt.xlabel(labelx)
	#plt.title(title)
	plt.show()

def graphNano(xSec, xNano, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR',  'LS','Givens', 'Seidel')
	y = np.arange(len(objects))
	cont = 0
	x = xNano[:]
	xSec2 = xSec[:]
	for i in xNano:
		x[cont] = i + xSec2[cont]*10**9
		cont = cont +1
	print("nanosegundos: ")
	print(x)
	plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return


def graphNanoSinSeidel(xSec, xNano,matlab, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'LS','Givens')
	y = np.arange(len(objects))
	cont = 0
	x = xNano[:]
	xSec2 = xSec[:]
	matlab2 = matlab[:]
	for i in xNano:
		x[cont] = i + xSec2[cont]*10**9
		cont = cont +1
	p1 = plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	p2 = plt.bar(y, matlab2*10**9, align='center', alpha=0.5, bottom = x)
	plt.legend((p1[0], p2[0]), ('Armadillo', 'Matlab'))
	plt.show()
	return

def graphSec(xSec, xNano, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'LS','Givens', 'Seidel')
	y = np.arange(len(objects))
	cont = 0
	x = xSec[:]
	xNano2 = xNano[:]
	print("graph sec con seidel")
	print("nanosegundos")
	print(xNano2)
	for i in xSec:
		x[cont] = i + xNano2[cont]*(10**(-9))
		print(xNano2[cont]*(10**(-9)))
		cont = cont +1
	print("Segundos: ")
	print(x)
	plt.bar(y, x, align='center', alpha=0.5)
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return


def graphSecSinSeidel(xSec, xNano,matlab, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'LS','Givens')
	y = np.arange(len(objects))
	cont = 0
	x = xSec[:]
	xNano2 = xNano[:]
	for i in xSec:
		x[cont] = i + xNano2[cont]*10**(-9)
		cont = cont +1
	print("Grafico segundos sin seidel: ")
	print("Segundos armadillo: ")
	print(x)
	print("Segundos matlab: ")
	print(matlab)
	p1 = plt.bar(y, x, align='center', alpha=0.5)
	p2 = plt.bar(y, matlab, align='center', alpha=0.5, bottom = x)
	plt.legend((p1[0], p2[0]), ('Armadillo', 'Matlab'))
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return


errorLU289 = np.fromfile('LUError289.dat', dtype=float)
errorLU1089 = np.fromfile('LUError1089.dat', dtype=float)
errorLU4225 = np.fromfile('LUError4225.dat', dtype=float)

errorCholesky289 = np.fromfile('CholError289.dat', dtype=float)
errorCholesky1089 = np.fromfile('CholError1089.dat', dtype=float)
errorCholesky4225 = np.fromfile('CholError4225.dat', dtype=float)

errorQR289 = np.fromfile('QRError289.dat', dtype=float)
errorQR1089 = np.fromfile('QRError1089.dat', dtype=float)
errorQR4225 = np.fromfile('QRError4225.dat', dtype=float)

errorGiv289 = np.fromfile('GivensError289.dat', dtype=float)
errorGiv1089 = np.fromfile('GivensError1089.dat', dtype=float)
errorGiv4225 = np.fromfile('GivensError4225.dat', dtype=float)

errorSeidelMat289 = np.fromfile('eGS289.dat', dtype=float, sep = " ")
errorSeidelMat1089 = np.fromfile('eGS1089.dat', dtype=float, sep = " ")
errorSeidelMat4225 = np.fromfile('eGS4225.dat', dtype=float, sep = " ")


print("####################")
myarraySEC289 = np.fromfile('timeSegundos289.dat', dtype=float)
myarrayNSEC289 = np.fromfile('timeNanoSegundos289.dat', dtype=float)
myarraySEC1089 = np.fromfile('timeSegundos1089.dat', dtype=float)
myarrayNSEC1089 = np.fromfile('timeNanoSegundos1089.dat', dtype=float)
myarraySEC4225 = np.fromfile('timeSegundos4225.dat', dtype=float)
myarrayNSEC4225 = np.fromfile('timeNanoSegundos4225.dat', dtype=float)

print("Tiempo segundos 4225: ")
print(myarraySEC4225)
print("#########")
print("Tiempo segundos 1089: ")
print(myarraySEC1089)
print("#########")

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
#LU CHOLESKY QR LS GIVENS SEIDEL

#tiemposMatlab289SS = [0.145, 0.467, 0.268, 0.314,0.232]
#tiemposMatlab1089SS = [3.562, 6.894, 5.893, 0.153,1.211]
#tiemposMatlab4225SS = [325.422, 314.324, 502.967, 5.026, 12.985]
#seidelMatlab289 = [0.624]
#seidelMatlab1089 = [68.654]
#seidelMatlab4225 = [8656.435]
#np.save("tiemposMatlab289.npy", tiemposMatlab289SS)
#np.save("tiemposMatlab1089.npy", tiemposMatlab1089SS)
#np.save("tiemposMatlab4225.npy", tiemposMatlab4225SS)
#
#np.save("seidelMatlab289.npy", seidelMatlab289)
#np.save("seidelMatlab1089.npy", seidelMatlab1089)
#np.save("seidelMatlab4225.npy", seidelMatlab4225)

tiemposMatlab289SS = np.load("tiemposMatlab289.npy")
tiemposMatlab1089SS = np.load("tiemposMatlab1089.npy")
tiemposMatlab4225SS = np.load("tiemposMatlab4225.npy")
seidelMatlab289 = np.load("seidelMatlab289.npy")
seidelMatlab1089 = np.load("seidelMatlab1089.npy")
seidelMatlab4225 = np.load("seidelMatlab4225.npy")
print("Finalizando python...")
print(myarraySEC289)
print(myarrayNSEC289)

#graph([1,2,3,4,5],myarrayNSEC,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos, matriz 289x289")
#graphNano(myarraySEC289, myarrayNSEC289, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 289x289")
graphSec(myarraySEC289,myarrayNSEC289, "Métodos","Tiempo [Sec]", "Métodos vs Tiempos[Sec], matriz 289x289")
graphError(iteracionesSeidel289, erroresSeidel289,errorSeidelMat289, "Iteraciones", "Error", "Iteraciones vs Error matriz 289x289, ajuste logarítmico")
graphNanoSinSeidel(myarraySEC289[:5], myarrayNSEC289[:5],tiemposMatlab289SS, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 289x289 (Sin Seidel)")
graphSecSinSeidel(myarraySEC289[:5],myarrayNSEC289[:5],tiemposMatlab289SS, "Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 289x289 (Sin Seidel)")
print("nanosegundos")
print(myarrayNSEC289)
print("segundos")
print(myarraySEC289)


#graphNano(myarraySEC1089, myarrayNSEC1089, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 1089x1089")
graphError(iteracionesSeidel1089, erroresSeidel1089,errorSeidelMat1089, "Iteraciones", "Error", "Iteraciones vs Error, matrix 1089x1089, ajuste logarítmico")
graphNanoSinSeidel(myarraySEC1089[:5], myarrayNSEC1089[:5],tiemposMatlab1089SS, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 1089x1089")
graphSec(myarraySEC1089, myarrayNSEC1089, "Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 1089x1089")
graphSecSinSeidel(myarraySEC1089[:5], myarrayNSEC1089[:5],tiemposMatlab1089SS, "Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 1089x1089")


#graphNano(myarraySEC4225, myarrayNSEC4225, "Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 4225x4225")
graphError(iteracionesSeidel4225, erroresSeidel4225,errorSeidelMat4225, "Iteraciones", "Error", "Iteraciones vs Error, matriz 4225x4225, ajuste logarítmico")
graphNanoSinSeidel(myarraySEC4225[:5], myarrayNSEC4225[:5], tiemposMatlab4225SS,"Métodos","Tiempo [Nanosegundos]", "Métodos vs Tiempos[nSec], matriz 4225x4225")
graphSec(myarraySEC4225, myarrayNSEC4225, "Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 4225x4225")
graphSecSinSeidel(myarraySEC4225[:5], myarrayNSEC4225[:5], tiemposMatlab4225SS,"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 4225x4225")

