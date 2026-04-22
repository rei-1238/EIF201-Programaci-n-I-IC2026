#include"LoteHoney.h"
#include "LoteLavado.h"
#include"LoteNatural.h"
#include"Beneficio.h"
#include<string>
#include <iostream>
using namespace std;
using namespace EIF201;



int main()
{
    Beneficio beneficio;

    //Datos que pide el constructor
    beneficio.agregarLote(new LoteHoney("finca rei", 70.0, 1235, 50));
    beneficio.agregarLote(new LoteNatural("finca let", 20.0, 400, 20, 13));
    beneficio.agregarLote(new LoteLavado("finca ken", 80.2, 1000, 20));

    cout << " CATALOGO: " << endl;
    beneficio.mostrarInventario();
    cout << endl;

    cout << "Valor total del inventario: "
        << beneficio.valorTotalInventario() << endl;

    LoteCafe* mejor = beneficio.loteMayorCalidad();
    if (mejor != nullptr) {
        cout << "Lote con mayor calidad: " << endl;
        cout << mejor->toString() << endl;
    }

    cout << endl;
    cout << "Cantidad proceso Lavado: "
        << beneficio.contadorPorProceso("Lavado") << endl;

    cout << "Cantidad proceso Natural: "
        << beneficio.contadorPorProceso("Natural") << endl;

    cout << "Promedio calidad Lavado: "
        << beneficio.promedioCalidadPorProceso("Lavado") << endl;

    cout << "Promedio calidad Natural: "
        << beneficio.promedioCalidadPorProceso("Natural") << endl;

    return 0;



}

