#include <iostream>
#include "stringEx.h"

int main()
{
    stringEx p;

    p = "Hello";

    stringEx s( p );

    stringEx t = s;

    /*stringEx::print( p );

    stringEx s = p;

    std::cout << std::endl;

    stringEx::print( s );

    std::cout << std::endl;

    stringEx o( p );

    stringEx::print( o );

    p.getLengthEx();*/

    std::cout << p << " " << s << " " << t;
}
