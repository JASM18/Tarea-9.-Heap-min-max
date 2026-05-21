#include <iostream>

#include "CapturaSegura.hpp"
#include "Monton.hpp"

using namespace std;

/**
 * \brief Opciones del men&uacute; principal para el &aacute;rbol AVL.
 */
enum Opciones_principales {
    AGREGAR = 1,
    ELIMINAR,
    OBTFRENTE,
    ESTAVACIA,
    VACIAR,
    NUMELEM,
    CAPACIDAD,
    IMPRIMIR,
    CAMBIAR,
    SALIR               ///< Termina la ejecuci&oacute;n del programa.
};

int main()
{
    int opcion = -1;
    Monton<int> arbol;

    int valor;

    do{
        cout << "==================================" << endl;
        cout << "Tarea 9. Heap (minimo/maximo)" << endl;
        cout << "==================================" << endl << endl;

        cout << "--- \265RBOL ACTUAL ---" << endl;
        if(arbol.EstaVacia()){
            cout << "El \240rbol est\240 vac\241o." << endl;
        }else{
            arbol.ImprimirComoArbol();
        }
        cout << "--------------------" << endl << endl;

        cout << "Opciones:" << endl;
        cout << "\t" << AGREGAR << ") Agregar un valor." << endl;
        cout << "\t" << ELIMINAR << ") Eliminar un valor." << endl;
        cout << "\t" << BUSCAR << ") Buscar un valor." << endl;
        cout << "\t" << NUMNODOS << ") Obtener n\243mero total de nodos." << endl;
        cout << "\t" << ALTURA << ") Obtener la altura del \240rbol." << endl;
        cout << "\t" << ESTAVACIA << ") Saber si el \240rbol est\240 vac\241o." << endl;
        cout << "\t" << IMP_ASC << ") Imprimir en orden ascendente." << endl;
        cout << "\t" << IMP_DESC << ") Imprimir en orden descendente." << endl;
        cout << "\t" << IMP_NIVELES << ") Imprimir por niveles." << endl;
        cout << "\t" << IMP_ARBOL << ") Imprimir como \240rbol." << endl;
        cout << "\t" << VACIAR << ") Vaciar todo el \240rbol." << endl;
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
                    if(arbol.Agregar(valor)) cout << "Valor agregado correctamente." << endl;
                    else cout << "El valor ya exist\241a en el \240rbol." << endl;
                break;

                case ELIMINAR:
                    if(arbol.EstaVacia()){
                        cout << "El \240rbol est\240 vac\241o, no hay nada que eliminar." << endl;
                    }else{
                        CapturarNumero(valor, "Valor a eliminar: ");
                        if(arbol.Eliminar(valor)) cout << "Valor eliminado correctamente." << endl;
                        else cout << "El valor no existe en el \240rbol." << endl;
                    }
                break;

                case BUSCAR:
                    CapturarNumero(valor, "Valor a buscar: ");
                    if(arbol.BuscarNodo(valor)) cout << "El valor S\326 se encuentra en el \240rbol." << endl;
                    else cout << "El valor NO se encuentra en el \240rbol." << endl;
                break;

                case NUMNODOS:
                    cout << "El \240rbol tiene " << arbol.ObtenerNumNodos() << " nodos." << endl;
                break;

                case ALTURA:
                    cout << "La altura del \240rbol es: " << arbol.ObtenerAltura() << endl;
                break;

                case ESTAVACIA:
                    if(arbol.EstaVacia()) cout << "El \240rbol S\326 est\240 vac\241o." << endl;
                    else cout << "El \240rbol NO est\240 vac\241o." << endl;
                break;

                case IMP_ASC:
                    if(arbol.EstaVacia()){
                        cout << "El \240rbol est\240 vac\241o." << endl;
                    }else{
                        cout << "Orden ascendente: ";
                        arbol.ImprimirAsc();
                        cout << endl;
                    }
                break;

                case IMP_DESC:
                    if(arbol.EstaVacia()){
                        cout << "El \240rbol est\240 vac\241o." << endl;
                    }else{
                        cout << "Orden descendente: ";
                        arbol.ImprimirDesc();
                        cout << endl;
                    }
                break;

                case IMP_NIVELES:
                    if(arbol.EstaVacia()){
                        cout << "El \240rbol est\240 vac\241o." << endl;
                    }else{
                        cout << "Por niveles: ";
                        arbol.ImprimirPorNiveles();
                        cout << endl;
                    }
                break;

                case IMP_ARBOL:
                    if(arbol.EstaVacia()){
                        cout << "El \240rbol est\240 vac\241o." << endl;
                    }else{
                        cout << "Estructura del \240rbol:";
                        arbol.ImprimirComoArbol();
                    }
                break;

                case VACIAR:
                    arbol.Vaciar();
                    cout << "El \240rbol ha sido vaciado por completo." << endl;
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
