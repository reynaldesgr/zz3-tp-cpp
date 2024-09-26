#ifndef point_h
#define point_h

#include <sstream>

class Point {
    public: 
        virtual void afficher() const = 0;
        virtual void afficher(std::ostream& stream) const = 0;
        virtual void convertir(Point& p) const = 0;
};

std::ostream& operator<<(std::ostream& stream, Point const & p);

#endif                                              