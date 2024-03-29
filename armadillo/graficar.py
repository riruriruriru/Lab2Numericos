import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab
import scipy.io as sio



def graphError(iteraciones, errores,matlabErrors, labelx, labely, title):
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
	plt.show()
	return

def graphResultados(LU, Chol,QR,LS,Giv,Sei,xlabel,ylabel,title):
	x = np.arange(len(LU))
	y = [LU,Chol,QR,LS,Giv,Sei]
	names = ["LU","Cholesky","QR","LS","Giv","Sei"]
	cont = 0
	
	for marker in ['o', '.', 'd', 'x', '+', 'v']:
		plt.plot(x, y[cont], marker, label=names[cont]+"='{0}'".format(marker))
		cont = cont +1
	plt.legend(numpoints=1)
	plt.ylabel(ylabel)
	plt.xlabel(xlabel)
	plt.title(title)
	plt.show()

def graphSecSeidelGiv(GivSec, GivNano,SeiSec,SeiNano,matlabGiv,matlabSei, labelx, labely, title):
	objects = ('Givens', 'Seidel')
	y = np.arange(len(objects))
	cont = 0
	x = [GivSec+GivNano*10**(-9), SeiSec+SeiNano*10**(-9)]
	xx = [matlabGiv, matlabSei]
	print("Grafico segundos sin seidel: ")
	print("Segundos armadillo: ")
	print(x)
	print("Segundos matlab: ")
	print(xx)
	p1 = plt.bar(y, x, align='center', alpha=0.5)
	p2 = plt.bar(y, xx, align='center', alpha=0.5, bottom = x)
	plt.legend((p1[0], p2[0]), ('Armadillo', 'Matlab'))
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	plt.show()
	return



def graphSecSinSeidel(xSec, xNano,matlab, labelx, labely, title):
	objects = ('LU', 'Cholesky', 'QR', 'LS')
	y = np.arange(len(objects))
	cont = 0
	x = xSec[:]
	xNano2 = xNano[:]
	for i in xSec:
		x[cont] = i + xNano2[cont]*10**(-9)
		cont = cont +1
	print("Segundos matlab: ")
	print(matlab)
	print("Segundos armadillo: ")
	print(x)
	p1 = plt.bar(y, x, align='center', alpha=0.5)
	p2 = plt.bar(y, matlab, align='center', alpha=0.5, bottom = x)
	plt.legend((p1[0], p2[0]), ('Armadillo', 'Matlab'))
	plt.xticks(y, objects)
	plt.ylabel(labely)
	plt.xlabel(labelx)
	plt.title(title)
	
	plt.show()
	return


errorLU289 = np.fromfile('Archivos/LUError289.dat', dtype=float)
errorLU1089 = np.fromfile('Archivos/LUError1089.dat', dtype=float)
errorLU4225 = np.fromfile('Archivos/LUError4225.dat', dtype=float)

errorCholesky289 = np.fromfile('Archivos/CholError289.dat', dtype=float)
errorCholesky1089 = np.fromfile('Archivos/CholError1089.dat', dtype=float)
errorCholesky4225 = np.fromfile('Archivos/CholError4225.dat', dtype=float)

errorQR289 = np.fromfile('Archivos/QRError289.dat', dtype=float)
errorQR1089 = np.fromfile('Archivos/QRError1089.dat', dtype=float)
errorQR4225 = np.fromfile('Archivos/QRError4225.dat', dtype=float)

errorGiv289 = np.fromfile('Archivos/GivensError289.dat', dtype=float)
errorGiv1089 = np.fromfile('Archivos/GivensError1089.dat', dtype=float)
errorGiv4225 = np.fromfile('Archivos/GivensError4225.dat', dtype=float)

errorSeidelMat289 = np.fromfile('Archivos/eGS289.dat', dtype=float, sep = " ")
errorSeidelMat1089 = np.fromfile('Archivos/eGS1089.dat', dtype=float, sep = " ")
errorSeidelMat4225 = np.fromfile('Archivos/eGS4225.dat', dtype=float, sep = " ")

errorLS289 = np.fromfile('Archivos/MinError289.dat', dtype=float)
errorLS1089 = np.fromfile('Archivos/MinError1089.dat', dtype=float)
errorLS4225 = np.fromfile('Archivos/MinError4225.dat', dtype=float)


print("####################")
myarraySEC289 = np.fromfile('Archivos/timeSegundos289.dat', dtype=float)
myarrayNSEC289 = np.fromfile('Archivos/timeNanoSegundos289.dat', dtype=float)
myarraySEC1089 = np.fromfile('Archivos/timeSegundos1089.dat', dtype=float)
myarrayNSEC1089 = np.fromfile('Archivos/timeNanoSegundos1089.dat', dtype=float)
myarraySEC4225 = np.fromfile('Archivos/timeSegundos4225.dat', dtype=float)
myarrayNSEC4225 = np.fromfile('Archivos/timeNanoSegundos4225.dat', dtype=float)

myarraySEC4225[5] = myarraySEC4225[5]/10
myarraySEC4225[4] = myarraySEC4225[4]/10
myarray2SEC4225 = np.fromfile('Archivos/2timeSegundos4225.dat', dtype=float, sep = " ")


solucionesSeidel289 = np.fromfile('Archivos/Seidel289Soluciones.dat',dtype = float)
solucionSeidel289 = np.fromfile('Archivos/Seidel289Solucion.dat',dtype = float)
erroresSeidel289 = np.fromfile('Archivos/Seidel289Errores.dat',dtype = float)
iteracionesSeidel289 = np.fromfile('Archivos/Seidel289Iteraciones.dat',dtype = float)

solucionesSeidel1089 = np.fromfile('Archivos/Seidel1089Soluciones.dat',dtype = float)
solucionSeidel1089 = np.fromfile('Archivos/Seidel1089Solucion.dat',dtype = float)
erroresSeidel1089 = np.fromfile('Archivos/Seidel1089Errores.dat',dtype = float)
iteracionesSeidel1089 = np.fromfile('Archivos/Seidel1089Iteraciones.dat',dtype = float)


solucionesSeidel4225 = np.fromfile('Archivos/Seidel4225Soluciones.dat',dtype = float)
solucionSeidel4225 = np.fromfile('Archivos/Seidel4225Solucion.dat',dtype = float)
erroresSeidel4225 = np.fromfile('Archivos/Seidel4225Errores.dat',dtype = float)
iteracionesSeidel4225 = np.fromfile('Archivos/Seidel4225Iteraciones.dat',dtype = float)

lu289 = np.fromfile('Archivos/LU289.dat',dtype = float)
chol289 = np.fromfile('Archivos/Chol289.dat',dtype = float)
qr289 = np.fromfile('Archivos/QR289.dat',dtype = float)
ls289 = np.fromfile('Archivos/Min289.dat',dtype = float)
giv289 = np.fromfile('Archivos/Givens289.dat',dtype = float)

lu1089 = np.fromfile('Archivos/LU1089.dat',dtype = float)
chol1089 = np.fromfile('Archivos/Chol1089.dat',dtype = float)
qr1089 = np.fromfile('Archivos/QR1089.dat',dtype = float)
ls1089 = np.fromfile('Archivos/Min1089.dat',dtype = float)
giv1089 = np.fromfile('Archivos/Givens1089.dat',dtype = float)

lu4225 = np.fromfile('Archivos/LU4225.dat',dtype = float)
chol4225 = np.fromfile('Archivos/Chol4225.dat',dtype = float)
qr4225 = np.fromfile('Archivos/QR4225.dat',dtype = float)
ls4225 = np.fromfile('Archivos/Min4225.dat',dtype = float)
giv4225 = np.fromfile('Archivos/Givens4225.dat',dtype = float)



tiemposMatlab289SS = np.load("Archivos/tiemposMatlab289.npy")
tiemposMatlab1089SS = np.load("Archivos/tiemposMatlab1089.npy")
tiemposMatlab4225SS = np.load("Archivos/tiemposMatlab4225.npy")
seidelMatlab289 = np.load("Archivos/seidelMatlab289.npy")
seidelMatlab1089 = np.load("Archivos/seidelMatlab1089.npy")
seidelMatlab4225 = np.load("Archivos/seidelMatlab4225.npy")

graphError(iteracionesSeidel289, erroresSeidel289,errorSeidelMat289, "Iteraciones", "Error", "Iteraciones vs Error matriz 289x289, ajuste logarítmico")
graphSecSinSeidel(myarraySEC289[:4],myarrayNSEC289[:4],tiemposMatlab289SS[:4], "Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 289x289 (Sin Seidel)")
graphSecSeidelGiv(myarraySEC289[4], myarrayNSEC289[4],myarraySEC289[5],myarrayNSEC289[5],tiemposMatlab289SS[4],seidelMatlab289[0], "Métodos", "Tiempo [Segundos]", "Métodos vs Tiempo, matriz 289x289")
graphResultados(lu289, chol289,qr289,ls289,giv289,solucionSeidel289,"x","y","Resultados Métodos Armadillo")

graphError(iteracionesSeidel1089, erroresSeidel1089,errorSeidelMat1089, "Iteraciones", "Error", "Iteraciones vs Error, matrix 1089x1089, ajuste logarítmico")
graphSecSinSeidel(myarraySEC1089[:4], myarrayNSEC1089[:4],tiemposMatlab1089SS[:4], "Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 1089x1089")
graphSecSeidelGiv(myarraySEC1089[4], myarrayNSEC1089[4],myarraySEC1089[5],myarrayNSEC1089[5],tiemposMatlab1089SS[4],seidelMatlab1089[0], "Métodos", "Tiempo [Segundos]", "Métodos vs Tiempo, matriz 1089x1089")
graphResultados(lu1089, chol1089,qr1089,ls1089,giv1089,solucionSeidel1089,"x","y","Resultados Métodos Armadillo")

graphError(iteracionesSeidel4225, erroresSeidel4225,errorSeidelMat4225[:1000], "Iteraciones", "Error", "Iteraciones vs Error, matriz 4225x4225, ajuste logarítmico")
graphSecSinSeidel(myarraySEC4225[:4], myarrayNSEC4225[:4], tiemposMatlab4225SS[:4],"Métodos","Tiempo [Segundos]", "Métodos vs Tiempos[Sec], matriz 4225x4225")
graphSecSeidelGiv(myarraySEC4225[4], myarrayNSEC4225[4],myarraySEC4225[5],myarrayNSEC4225[5],tiemposMatlab4225SS[4],seidelMatlab4225[0], "Métodos", "Tiempo [Segundos]", "Métodos vs Tiempo, matriz 4225x4225")
graphResultados(lu4225, chol4225,qr4225,ls4225,giv4225,solucionSeidel4225,"x","y","Resultados Métodos Armadillo")

print("##########################")
print("ERRORES ARMADILLO")
print(errorLU289)
print(errorLU1089)
print(errorLU4225)
print(errorCholesky289) 
print(errorCholesky1089)
print(errorCholesky4225)

print(errorQR289)
print(errorQR1089)
print(errorQR4225)

print(errorGiv289)
print(errorGiv1089)
print(errorGiv4225)

print("##########################")
print("ERRORES SEIDEL ARMADILLO")
print(erroresSeidel289[len(erroresSeidel289)-1])
print(erroresSeidel1089[len(erroresSeidel1089)-1])
print(erroresSeidel4225[len(erroresSeidel4225)-1])
print("##########################")
print("ERRORES SEIDEL MATLAB")
print(errorSeidelMat289[len(errorSeidelMat289)-1])
print(errorSeidelMat1089[len(errorSeidelMat1089)-1])
print(errorSeidelMat4225[999])
print("ERRORES MINIMOS CUADRADOS: \n##################")
print(errorLS289)
print(errorLS1089)
print(errorLS4225)
print("Iteraciones Gauss Seidel Armadillo:")
print(iteracionesSeidel289)
print(iteracionesSeidel1089)
print(iteracionesSeidel4225)
