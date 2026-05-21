/**
 * \file Monton.hpp
 * \brief Este archivo contiene la definici&oacute;n de la plantilla de clase Monton, estructurada como un arreglo din&aacute;mico.
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
 * \author Portugal Arreola, Marian Bethsab&eacute;
 * \date 19/05/2026
 * \code{.cpp}
#include <iostream>

#include "Monton.hpp"

using namespace std;

int main()
{
    try{

        Monton<int, minimo> minMont;
        Monton<int, minimo> maxMont;

        cout << "==============" << endl;
        cout << "MONTÍCULO MINIMO" << endl;
        cout << "==============" << endl;

        cout << "-> Capacidad: " << minMont.ObtenerCapacidad() << endl;

        if(minMont.EstaVacia()) cout << "El mont\241culo S\326 est\240 vac\241o." << endl;
        else cout << "El mont\241culo NO est\240 vac\241o." << endl;

        cout << "\n-> Agregando valores..." << endl;

        minMont.Agregar(67);
        minMont.Agregar(30);
        minMont.Agregar(20);
        minMont.Agregar(13);
        minMont.Agregar(10);
        minMont.Agregar(8);
        minMont.Agregar(16);

        cout << "Elementos en el mont\241culo: " << minMont << endl;
        cout << "Hay " << minMont.ObtenerNumElementos() << " eleemntos" << endl;

        cout << "La raíz es " << minMont.ObtenerFrente() << endl;

        cout << "\n-> Eliminando la raíz..." << endl;
        minMont.Eliminar();

        cout << "La raíz ahora es " << minMont.ObtenerFrente() << endl;
        cout << "Mont\241culo actual: " << minMont << endl;

        if(minMont.EstaVacia()) cout << "El mont\241culo S\326 est\240 vac\241o" << endl;
        else cout << "El mont\241culo NO est\240 vac\241o" << endl << endl;

        cout << "-> Vaciando el mont\241culo..." << endl;
        minMont.Vaciar();
        if(minMont.EstaVacia()) cout << "El mont\241culo S\326 est\240 vac\241o" << endl;
        else cout << "El mont\241culo NO est\240 vac\241o" << endl << endl;

        cout << "\n==============" << endl;
        cout << "MONT\241CULO MA\240XIMO" << endl;
        cout << "==============" << endl;

        cout << "-> Capacidad: " << maxMont.ObtenerCapacidad() << endl;

        if(maxMont.EstaVacia()) cout << "El mont\241culo S\326 est\240 vac\241o." << endl;
        else cout << "El mont\241culo NO est\240 vac\241o." << endl;

        cout << "\n-> Agregando valores..." << endl;

        maxMont.Agregar(67);
        maxMont.Agregar(30);
        maxMont.Agregar(20);
        maxMont.Agregar(13);
        maxMont.Agregar(10);
        maxMont.Agregar(8);
        maxMont.Agregar(16);

        cout << "Elementos en el mont\241culo: " << maxMont << endl;
        cout << "Hay " << maxMont.ObtenerNumElementos() << " eleemntos" << endl;

        cout << "La raíz es " << maxMont.ObtenerFrente() << endl;

        cout << "\n-> Eliminando la raíz..." << endl;
        maxMont.Eliminar();

        cout << "La raíz ahora es " << maxMont.ObtenerFrente() << endl;
        cout << "Mont\241culo actual: " << maxMont << endl;

        if(maxMont.EstaVacia()) cout << "El mont\241culo S\326 est\240 vac\241o" << endl;
        else cout << "El mont\241culo NO est\240 vac\241o" << endl << endl;

        cout << "-> Vaciando el mont\241culo..." << endl;
        maxMont.Vaciar();
        if(maxMont.EstaVacia()) cout << "El mont\241culo S\326 est\240 vac\241o" << endl;
        else cout << "El mont\241culo NO est\240 vac\241o" << endl << endl;

    }catch(const char* mensaje){
        cerr << "Error: " << mensaje << endl;
    }catch(const exception &error){
        cerr << "Error: " << error.what() << endl;
    }catch(...){
        cerr << "El programa tuvo un error inesperado." << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}
 * \endcode
 */

#ifndef MONTON_HPP_INCLUDED
#define MONTON_HPP_INCLUDED

#include <iostream>
#include <exception>

// Funciones de orden para el monton.

/** \brief Funci&oacute;n de comparaci&oacute;n para establecer un Mont&oacute;n M&iacute;nimo.
 * \tparam T Tipo de dato a comparar.
 * \param a Primer valor.
 * \param b Segundo valor.
 * \return true si 'a' es menor o igual a 'b'.
 */
template <typename T>
bool minimo(const T &a, const T &b) {
    return a <= b;
}

/** \brief Funci&oacute;n de comparaci&oacute;n para establecer un Mont&oacute;n M&aacute;ximo.
 * \tparam T Tipo de dato a comparar.
 * \param a Primer valor.
 * \param b Segundo valor.
 * \return true si 'a' es mayor o igual a 'b'.
 */
template <typename T>
bool maximo(const T &a, const T &b) {
    return a >= b;
}

//************* para que no haga berrinche el compilador

// Declaraciones adelantadas necesarias para que el operador << sea amigo de la clase
template<typename T, bool (*Orden)(const T&, const T&)>
class Monton;

template<typename T, bool (*Orden)(const T&, const T&)>
std::ostream& operator<<(std::ostream& salida, const Monton<T, Orden>& monton);

//*************

/**
 * \brief Plantilla de clase que implementa la estructura Mont&oacute;n (Heap) utilizando un arreglo din&aacute;mico.
 * Permite configurarse como mont&iacute;culo m&iacute;nimo (por default) o mont&iacute;culo m&aacute;ximo mediante un puntero a funci&oacute;n.
 *
 * \tparam T Tipo de dato que almacenar&aacute; el mont&oacute;n.
 * \tparam Orden Puntero a la funci&oacute;n que determina si el mont&iacute;culo ser&aacute; m&iacute;nimo o m&aacute;ximo.
 */
template <typename T, bool (*Orden)(const T&, const T&) = minimo<T> >
class Monton {

    /** \brief Sobrecarga del operador de inserci&oacute;n para imprimir el arreglo del mont&oacute;n.
     * \param salida Flujo de salida.
     * \param monton Referencia constante al mont&oacute;n a imprimir.
     * \return Referencia al flujo de salida modificado.
     */
    friend std::ostream& operator<< <>(std::ostream& salida, const Monton<T, Orden>& monton);

public:
    // Constructores

    /** \brief Constructor por default que inicializa el mont&oacute;n con una capacidad inicial para 5 niveles (31 datos).
     * \throw MontonNoMemoria Lanza excepci&oacute;n si falla la asignaci&oacute;n de memoria inicial.
     */
    Monton();

    /** \brief Constructor de copias que inicializa un mont&oacute;n a partir de otro existente.
     * \param monton Referencia constante al mont&oacute;n que se desea copiar.
     * \throw MontonNoMemoria Lanza excepci&oacute;n si falla la asignaci&oacute;n de memoria durante la copia.
     */
    Monton(const Monton &monton);

    /** \brief Destructor por default que libera la memoria del arreglo din&aacute;mico.
     */
    ~Monton();

    /** \brief Operador de asignaci&oacute;n sobrecargado.
     * \param monton Referencia constante al mont&oacute;n origen.
     * \return Una referencia al mont&oacute;n actual (*this).
     * \throw MontonNoMemoria Lanza excepci&oacute;n si se requiere redimensionar y falla la memoria.
     */
    Monton& operator=(const Monton &monton);

    // Métodos publicos

    /** \brief Agrega un nuevo elemento al mont&oacute;n y restablece el orden empujando hacia arriba.
     * \param valor Dato a agregar.
     * \return void
     * \throw MontonNoMemoria Lanza excepci&oacute;n si se llena el arreglo y falla la memoria al redimensionar.
     */
    void Agregar(const T valor);

    /** \brief Elimina la ra&iacute;z del mont&oacute;n y reordena los elementos.
     * \return true si se elimin&oacute; correctamente, false si el mont&oacute;n ya estaba vac&iacute;o.
     */
    bool Eliminar();

    /** \brief Obtiene el elemento ubicado en el frente (la ra&iacute;z) del mont&oacute;n.
     * \return El dato almacenado en el &iacute;ndice 0.
     * \warning Si el mont&oacute;n est&aacute; vac&iacute;o, imprimir&aacute; una advertencia.
     */
    T ObtenerFrente() const; // Obtiene la raíz

    /** \brief Consulta si el mont&oacute;n est&aacute; vac&iacute;o.
     * \return true si el mont&oacute;n est&aacute; vac&iacute;o, false en caso contrario.
     */
    bool EstaVacia() const;

    /** \brief Vac&iacute;a el mont&oacute;n.
     * \return void
     */
    void Vaciar();

    /** \brief Obtiene la cantidad de elementos en el mont&oacute;n.
     * \return N&uacute;mero entero con la cantidad de elementos.
     */
    int ObtenerNumElementos() const;

    /** \brief Obtiene la capacidad m&aacute;xima actual del arreglo din&aacute;mico.
     * \return N&uacute;mero entero con la capacidad m&aacute;xima del arreglo din&aacute;mico.
     */
    int ObtenerCapacidad() const;

    /** \brief Imprime los elementos del mont&oacute;n seg&uacute;n su orden en el arreglo.
     * \return void
     */
    void Imprimir() const;

    /**
     * \brief Excepci&oacute;n lanzada cuando ocurren fallos de memoria din&aacute;mica.
     */
    class MontonNoMemoria : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n MontonNoMemoria.
         */
        MontonNoMemoria() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando no haya memoria disponible.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

private:

    int capacidad;      ///< Tama&ntilde;o actual del arreglo din&aacute;mico.
    int ultimo;         ///< &Iacute;ndice del &uacute;ltimo elemento almacenado (inicia en -1 si el arreglo est&aacute; vac&iacute;o).
    T* elementos;       ///< Puntero al arreglo din&aacute;mico que contiene los datos.

    // Métodos privadps

    /** \brief M&eacute;todo auxiliar que duplica la capacidad del arreglo m&aacute;s uno para aceptar un nuevo nivel del &aacute;rbol.
     * \return void
     * \throw MontonNoMemoria Lanza excepci&oacute;n si falla la memoria con el nuevo arreglo.
     */
    void Redimensionar();

    /** \brief M&eacute;todo auxiliar que compara un nodo con sus padres e intercambia posiciones hasta cumplir la propiedad del mont&oacute;n.
     * \param indice Posici&oacute;n inicial desde donde se comenzar&aacute; a evaluar hacia la ra&iacute;z.
     * \return void
     */
    void EmpujarArriba(int indice);

    /** \brief M&eacute;todo auxiliar que compara un nodo con sus hijos e intercambia sus posiciones hasta cumplir la propiedad.
     * \param indice Posici&oacute;n inicial desde donde se comenzar&aacute; a evaluar hacia abajo.
     * \return void
     */
    void EmpujarAbajo(int indice);
};

#include "Monton.tpp"

#endif // MONTON_HPP_INCLUDED
