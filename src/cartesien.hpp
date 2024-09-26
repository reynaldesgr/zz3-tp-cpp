#ifndef cartesien_h
#define cartesien_h

#include "point.hpp"

class Polaire;

class Cartesien : public Point {

    double x, y;

    public:

        Cartesien(): x(0.0), y(0.0){}
        Cartesien(double x, double y): x(x), y(y){}

        double getX() const { return x; }
        double getY() const { return y; }

        void setX(double x) { this->x = x; }
        void setY(double y) { this->y = y; }

        void afficher() const override;
        void afficher(std::ostream& stream) const;

        void convertir(Point& p) const override;
        void convertir(Polaire& p) const;
};
#endif