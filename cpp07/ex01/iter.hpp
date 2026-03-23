#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T *address, const size_t length, F function)
{
    if (!address)
        return;

    for (size_t i = 0; i < length; i++)
    {
        function(address[i]);
    }
}

#endif