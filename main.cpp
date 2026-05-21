/**
 * \file main.cpp
 * \brief Este archivo contiene la ejecuci&oacute;n principal y el men&uacute; interactivo para probar la clase Monton.
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
 * \author Portugal Arreola, Marian Bethsab&eacute;
 * \date 19/05/2026
 */

#include <iostream>

#include "CapturaSegura.hpp"
#include "Monton.hpp"

using namespace std;

/**
 * \brief Opciones del men&uacute; principal para el mont&iacute;culo.
 */
enum Opciones_principales {
    AGREGAR = 1,        ///< Agrega un nuevo valor al mont&iacute;culo actual.
    ELIMINAR,           ///< Elimina la ra&iacute;z del mont&iacute;culo actual.
    OBTFRENTE,          ///< Muestra el elemento al frente (la ra&iacute;z).
    ESTAVACIA,          ///< Indica si el mont&iacute;culo actual no tiene elementos.
    VACIAR,             ///< Elimina todos los elementos del mont&iacute;culo actual.
    NUMELEM,            ///< Muestra el n&uacute;mero de elementos.
    CAPACIDAD,          ///< Muestra la capacidad del arreglo interno.
    IMPRIMIR,           ///< Imprime los elementos del mont&iacute;culo actual.
    CAMBIAR,            ///< Alterna entre mont&iacute;culo m&iacute;nimo y m&aacute;ximo.
    SALIR               ///< Termina el programa.
};

int main()
{
    int opcion = -1;

    // Llevamos dos monticulos independientes y una bandera para saber cual esta activo.
    Monton<int> mtMin; // monticulo minimo (default)
    Monton<int, maximo> mtMax; // monticulo maximo

    bool modoMaximo = false; // false = minimo, true = maximo

    int valor;

    do{
        cout << "==================================" << endl;
        cout << "Tarea 9. Heap (m\241nimo/m\240ximo)" << endl;
        cout << "==================================" << endl << endl;

        cout << "Modo activo: " << (modoMaximo ? "M\265XIMO" : "M\326NIMO") << endl << endl;

        cout << "--- MONT\326CULO ACTUAL ---" << endl;
        if(modoMaximo){
            if(mtMax.EstaVacia()) cout << "El mont\241culo est\240 vac\241o." << endl;
            else{ cout << mtMax; cout << endl; }
        }else{
            if(mtMin.EstaVacia()) cout << "El mont\241culo est\240 vac\241o." << endl;
            else{ cout << mtMin; cout << endl; }
        }
        cout << "------------------------" << endl << endl;

        cout << "Opciones:" << endl;
        cout << "\t" << AGREGAR << ") Agregar un valor." << endl;
        cout << "\t" << ELIMINAR << ") Eliminar la ra\241z." << endl;
        cout << "\t" << OBTFRENTE << ") Obtener el elemento al frente (la ra\241z)." << endl;
        cout << "\t" << ESTAVACIA << ") Saber si el mont\241culo est\240 vac\241o." << endl;
        cout << "\t" << VACIAR << ") Vaciar el mont\241culo." << endl;
        cout << "\t" << NUMELEM << ") Obtener el n\243mero de elementos." << endl;
        cout << "\t" << CAPACIDAD << ") Obtener la capacidad del mont\241culo." << endl;
        cout << "\t" << IMPRIMIR << ") Imprimir." << endl;
        cout << "\t" << CAMBIAR << ") Cambiar entre mont\241culo m\241nimo y m\240ximo." << endl;
        cout << "\t" << SALIR << ") Salir del programa." << endl;

        do{
            CapturarNumero(opcion, "Elige una opci\242n: ");
        }while(opcion > SALIR || opcion < AGREGAR);

        if(opcion == SALIR) continue;

        try{
            cout << "- - - - -" << endl;
            switch(opcion){

                case AGREGAR:
                    CapturarNumero(valor, "Valor a agregar: ");
                    if(modoMaximo){
                        mtMax.Agregar(valor);
                    }else{
                        mtMin.Agregar(valor);
                    }
                    cout << "Valor agregado correctamente." << endl;
                break;

                case ELIMINAR:
                    if(modoMaximo){
                        mtMax.Eliminar();
                    }else{
                        mtMin.Eliminar();
                    }
                    cout << "Se elimin\242 la ra\241z del mont\241culo." << endl;
                break;

                case OBTFRENTE:
                    if(modoMaximo){
                        cout << "Elemento al frente: " << mtMax.ObtenerFrente() << endl;
                    }else{
                        cout << "Elemento al frente: " << mtMin.ObtenerFrente() << endl;
                    }
                break;

                case ESTAVACIA:
                    if(modoMaximo){
                        if(mtMax.EstaVacia()){
                            cout << "El mont\241culo S\326 est\240 vac\241o." << endl;
                        }else{
                            cout << "El mont\241culo NO est\240 vac\241o." << endl;
                        }
                    }else{
                        if(mtMin.EstaVacia()){
                            cout << "El mont\241culo S\326 est\240 vac\241o." << endl;
                        }else{
                            cout << "El mont\241culo NO est\240 vac\241o." << endl;
                        }
                    }
                break;

                case VACIAR:
                    if(modoMaximo){
                        mtMax.Vaciar();
                    }else{
                        mtMin.Vaciar();
                    }
                    cout << "El mont\241culo ha sido vaciado por completo." << endl;
                break;

                case NUMELEM:
                    if(modoMaximo){
                        cout << "El mont\241culo tiene " << mtMax.ObtenerNumElementos() << " elementos." << endl;
                    }else{
                        cout << "El mont\241culo tiene " << mtMin.ObtenerNumElementos() << " elementos." << endl;
                    }
                break;

                case CAPACIDAD:
                    if(modoMaximo){
                        cout << "Capacidad actual: " << mtMax.ObtenerCapacidad() << endl;
                    }else{
                        cout << "Capacidad actual: " << mtMin.ObtenerCapacidad() << endl;
                    }
                break;

                case IMPRIMIR:
                    if(modoMaximo){
                        cout << "Elementos: "; mtMax.Imprimir(); cout << endl;
                    }else{
                        cout << "Elementos: "; mtMin.Imprimir(); cout << endl;
                    }
                break;

                case CAMBIAR:
                    modoMaximo = !modoMaximo;
                    cout << "Modo cambiado a: " << (modoMaximo ? "M\265XIMO" : "M\315NIMO") << endl;
                    cout << "(Cada mont\241culo conserva su propio contenido.)" << endl;
                break;
            }

        }catch(const char* mensaje){
            cerr << "Error: " << mensaje << endl;
        }catch(const exception &error){
            cerr << "Error: " << error.what() << endl;
        }catch(...){
            cerr << "El programa tuvo un error inesperado." << endl;
        }

        cout << endl;
        system ("pause");
        system("CLS");
    }while(opcion != SALIR);

    cout << "\nEl programa ha terminado." << endl;

    system("pause");
    return 0;
}
