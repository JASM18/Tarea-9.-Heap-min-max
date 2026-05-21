/**
 * \file Monton.tpp
 * \brief Este archivo contiene la implementaci&oacute;n de los m&eacute;todos de la plantilla de clase Monton.
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
 * \author Portugal Arreola, Marian Bethsab&eacute;
 * \date 19/05/2026
 */

//***********************************************
// CONSTRUCTORES
//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
Monton<T, Orden>::Monton() : capacidad(31), ultimo(-1), elementos(nullptr)
{
    // Capacidad por default: 5 niveles
    // 1+2+4+8+16 = 31 datos
    try{

        elementos = new T[capacidad];

    }catch(const std::bad_alloc&){
        throw MontonNoMemoria();
    }
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
Monton<T, Orden>::~Monton()
{
    delete[] elementos;
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
Monton<T, Orden>::Monton(const Monton &monton) : capacidad(31), ultimo(-1), elementos(nullptr)
{
    try{

        elementos = new T[capacidad];

    }catch(const std::bad_alloc&){
        throw MontonNoMemoria();
    }

    *this = monton;
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
Monton<T, Orden> & Monton<T, Orden>::operator=(const Monton &monton)
{
    if(this == &monton) return *this;
    Vaciar();

    if(capacidad < monton.capacidad){

        T *nuevo;
        try{
            nuevo = new T[monton.capacidad];

        }catch(const std::bad_alloc&){
            throw MontonNoMemoria();
        }

        delete[] elementos;
        elementos = nuevo;
        capacidad = monton.capacidad;
    }

    for(int i = 0 ; i <= monton.ultimo ; ++i){
        elementos[i] = monton.elementos[i];
    }

    ultimo = monton.ultimo;
    return *this;
}

//***********************************************
// METODOS PUBLICOS
//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
void Monton<T, Orden>::Agregar(T valor)
{
    // Si no hay espacio para un elemento mas, se redimensiona
    if(ultimo + 1 == capacidad){
        Redimensionar();
    }

    ++ultimo;
    elementos[ultimo] = valor;
    EmpujarArriba(ultimo);
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
bool Monton<T, Orden>::Eliminar()
{
    if(EstaVacia()) return false;

    // Se reemplaza la raiz con el ultimo y se empuja hacia abajo.
    elementos[0] = elementos[ultimo];
    --ultimo;
    if(ultimo >= 0) EmpujarAbajo(0);

    return true;
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
T Monton<T, Orden>::ObtenerFrente() const
{
    if(EstaVacia()){
        std::cout << "[El Monton no tiene elementos]";
    }
    return elementos[0];
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
bool Monton<T, Orden>::EstaVacia() const
{
    return ultimo == -1;
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
void Monton<T, Orden>::Vaciar()
{
    ultimo = -1;
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
int Monton<T, Orden>::ObtenerNumElementos() const
{
    return ultimo + 1;
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
int Monton<T, Orden>::ObtenerCapacidad() const
{
    return capacidad;
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
void Monton<T, Orden>::Imprimir() const
{
    if(EstaVacia()){
        std::cout << "[ ]";
        return;
    }

    std::cout << "[ ";

    for(int i = 0 ; i <= ultimo ; ++i){
        std::cout << elementos[i] << ", ";
    }
    if(!EstaVacia()) std::cout << "\b\b ]";
}

//***********************************************
// METODOS PRIVADOS
//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
void Monton<T, Orden>::Redimensionar()
{
    // Se agrega un nivel mas. Si el arbol tenia capacidad 2^n - 1, ahora
    // tendra capacidad 2^(n+1) - 1, es decir, capacidad*2 + 1.
    int nuevaCapacidad = capacidad * 2 + 1;

    T *nuevo;
    try{
        nuevo = new T[nuevaCapacidad];

    }catch(const std::bad_alloc&){
        throw MontonNoMemoria();
    }

    for(int i = 0 ; i <= ultimo ; ++i){
        nuevo[i] = elementos[i];
    }

    delete[] elementos;
    elementos = nuevo;
    capacidad = nuevaCapacidad;
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
void Monton<T, Orden>::EmpujarArriba(int indice)
{
    // Mientras el padre exista y el orden no se cumpla, se intercambia
    while(indice > 0){
        int padre = (indice - 1) / 2;

        if(Orden(elementos[indice], elementos[padre])){
            T temp = elementos[padre];
            elementos[padre] = elementos[indice];
            elementos[indice] = temp;
            indice = padre;
        }else{
            return; // ya esta en orden
        }
    }
}

//***********************************************

template<typename T, bool (*Orden)(const T&, const T&)>
void Monton<T, Orden>::EmpujarAbajo(int indice)
{
    // Se escoge el mayor o el menor de sus hijos según corresponda y se comapara con su padre pa ver si se intercambia
    while(true){
        int hijoIzq = 2 * indice + 1;
        int hijoDer = 2 * indice + 2;
        int mejor = indice;

        if(hijoIzq <= ultimo && Orden(elementos[hijoIzq], elementos[mejor])){
            mejor = hijoIzq;
        }
        if(hijoDer <= ultimo && Orden(elementos[hijoDer], elementos[mejor])){
            mejor = hijoDer;
        }

        if(mejor == indice) return; // ya esta en orden

        T temp = elementos[indice];
        elementos[indice] = elementos[mejor];
        elementos[mejor] = temp;
        indice = mejor;
    }
}

//***********************************
// EXCEPCIONES
//***********************************

template<typename T, bool (*Orden)(const T&, const T&)>
Monton<T, Orden>::MontonNoMemoria::MontonNoMemoria() throw() {}

//***********************************

template<typename T, bool (*Orden)(const T&, const T&)>
const char *Monton<T, Orden>::MontonNoMemoria::what() const throw()
{
    return "No hay memoria disponible.";
}

//**********************************
// Flujos sobrecargados de entrada y salida
//**********************************

template<typename T, bool (*Orden)(const T&, const T&)>
std::ostream& operator<<(std::ostream& salida, const Monton<T, Orden>& monton)
{
    monton.Imprimir();
    return salida;
}
