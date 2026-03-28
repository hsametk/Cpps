#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
private:
    T*              _array;
    unsigned int    _size;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
    ~Array();
};

// --- Default constructor ---
template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

// --- n-parameter constructor ---
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

// --- Copy constructor (deep copy) ---
template <typename T>
Array<T>::Array(const Array &other) : _array(NULL), _size(0)
{
    *this = other;
}

// --- Assignment operator (deep copy) ---
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this == &other)
        return *this;

    // Önce yeni hafızayı hazırla (exception safety)
    T *newArray = new T[other._size]();
    for (unsigned int i = 0; i < other._size; i++)
        newArray[i] = other._array[i];

    // Sonra eskiyi sil
    delete[] _array;
    _array = newArray;
    _size = other._size;
    return *this;
}

// --- operator[] non-const ---
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Array: index out of bounds");
    return _array[index];
}

// --- operator[] const ---
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Array: index out of bounds");
    return _array[index];
}

// --- size() ---
template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

// --- Destructor ---
template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

#endif