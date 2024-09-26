#ifndef polaire_h
#define polaire_h

#include "point.hpp"

class Cartesien;

class Polaire : public Point {
    
    double theta;
    double dist;

    public:

        Polaire(): theta(0.0), dist(0.0){}
        Polaire(double t, double r):theta(t), dist(r){}

        double getAngle() const;
        double getDistance() const;

        void setAngle(double a);
        void setDistance(double d);

        void afficher() const override;
        void afficher(std::ostream& stream) const override;

        void convertir(Point& p) const override;
        void convertir(Cartesien& c) const;
};
#endif