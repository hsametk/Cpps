#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Value not found!";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw NotFoundException();

    return it;
}
#endif

// c deki hali arraylerdir. c de array mallocladığın veya initilaze ettiğin sayı kadar tutulur.
// vector container ı ise 
// Buradaki vector, int türündeki değerleri tutan bir container’dır.
/*Container neden kullanılır?

Container’lar şu işlemleri kolaylaştırır:

Veri ekleme
Veri silme
Veriye erişme
Arama yapma
Elemanları sıralama
Belleği otomatik yönetme
*/


/*
Temel fonksiyonları:
numbers.push_back(40); // Sona eleman ekler
numbers.pop_back();    // Son elemanı siler
numbers.size();        // Eleman sayısını verir
numbers.empty();       // Boş mu kontrol eder
numbers.clear();       // Tüm elemanları siler
numbers.front();       // İlk eleman
numbers.back();        // Son eleman

Sequence Containers olarak geçiyor bunları handellamaya gerek yok demiş pdf.
*/