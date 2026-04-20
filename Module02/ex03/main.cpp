#include "Fixed.hpp"
#include "Point.hpp"

int main() {
    // Triangle with vertices at (0,0), (10,0), (5,10)
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test cases
    Point inside(5.0f, 3.0f);       // Inside
    Point onEdge(5.0f, 0.0f);       // On edge AB
    Point onVertex(0.0f, 0.0f);     // On vertex A
    Point outside(15.0f, 5.0f);     // Outside

    std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;    // 1
    std::cout << "On edge: " << bsp(a, b, c, onEdge) << std::endl;   // 0
    std::cout << "On vertex: " << bsp(a, b, c, onVertex) << std::endl; // 0
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;  // 0
}
