#ifndef MONTON_HPP_INCLUDED
#define MONTON_HPP_INCLUDED

#include <iostream>
#include <exception>

// Funciones de orden para el monton.

template <typename T>
bool minimo(const T &a, const T &b) {
    return a <= b;
}

template <typename T>
bool maximo(const T &a, const T &b) {
    return a >= b;
}

//************* para que me haga berrinche el copilador

template<typename T, bool (*Orden)(const T&, const T&)>
class Monton;

template<typename T, bool (*Orden)(const T&, const T&)>
std::ostream& operator<<(std::ostream& salida, const Monton<T, Orden>& monton);

//*************

template <typename T, bool (*Orden)(const T&, const T&) = minimo<T> >
class Monton {
    friend std::ostream& operator<< <>(std::ostream& salida, const Monton<T, Orden>& monton);

public:
    // Constructores
    Monton();
    Monton(const Monton &monton);
    ~Monton();
    Monton& operator=(const Monton &monton);

    // Métodos publicos
    void Agregar(const T valor);
    bool Eliminar();

    T ObtenerFrente() const; // Obtiene la raíz

    bool EstaVacia() const;
    void Vaciar();

    int ObtenerNumElementos() const;
    int ObtenerCapacidad() const;

    void Imprimir() const;

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

    int capacidad; // Tamaño actual del arreglo dinámico
    int ultimo;    // Índice del último elemento (inicia en -1)
    T* elementos;  // Puntero al arreglo dinámico

    // Métodos privadps
    void Redimensionar();
    void EmpujarArriba(int indice);
    void EmpujarAbajo(int indice);
};

#include "Monton.tpp"

#endif // MONTON_HPP_INCLUDED
