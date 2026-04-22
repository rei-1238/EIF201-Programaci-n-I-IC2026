
#include "Cancion.h"
#include "Podcast.h"
#include "AudioLibro.h"
#include "Plataforma.h"
#include "Contenido.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
using namespace EIF201;


int main(){
    Plataforma plataforma;

    plataforma.agregarContenido(new Cancion("Volar", 210, "Pop", 50000));
    plataforma.agregarContenido(new Podcast("Cafe y codigo", 5400, 12, true, 3000));
    plataforma.agregarContenido(new AudioLibro("Codigo", 4000, 25, 5000, 1500));


    cout << "CATALOGO" << endl;
    plataforma.mostrarCatalogo();

    cout << endl;

    cout << "Regalias Totales: " << plataforma.regaliasTotales() << endl;
    Contenido* rentable = plataforma.contenidoMasRentable();
    if (rentable != nullptr) {
        cout << endl;
        cout << "Contenido mas rentable: " << endl;
        cout << rentable->toString() << endl;

    }

    Contenido* popular = plataforma.contenidoMasPopular();
    if (popular != nullptr) {
        cout << endl;
        cout << " Contenidp mas popular: " << endl;
        cout << popular->toString() << endl;

    }


    cout << endl;
    cout << "Cantidad de canciones: " << plataforma.contarPorTipo("Cancion") << endl;
    cout << "Cantidad de podcast: " << plataforma.contarPorTipo("Podcast") << endl;
    cout << "Cantidad de audiolibros: " << plataforma.contarPorTipo("AudioLibro") << endl;

    cout << endl;
    cout << "Promedio de regalias Cancion: "
        << plataforma.promedioDeRegaliasPorTipo("Cancion") << endl;

    cout << "Promedio de regalias Podcast: "
        << plataforma.promedioDeRegaliasPorTipo("Podcast") << endl;

    cout << "Promedio de regalias AudioLibro: "
        << plataforma.promedioDeRegaliasPorTipo("AudioLibro") << endl;

    return 0;
}


