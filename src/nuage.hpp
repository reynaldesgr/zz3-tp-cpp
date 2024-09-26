#ifndef nuage_h
#define nuage_h

#include <vector>
#include <memory>

#include "point.hpp"
#include "polaire.hpp"
#include "cartesien.hpp"

class Point;
class Cartesien;
class Polaire;

class Nuage {
    std::vector<Point*> points;

    public:
        static Cartesien barycentre(const Nuage& nuage);

        void ajouter(const Cartesien& point);
        void ajouter(const Polaire& point);

        size_t size() const { return points.size(); };

        using iterator = std::vector<Point*>::iterator;
        using const_iterator = std::vector<Point*>::const_iterator;

        iterator begin() { return points.begin(); }
        iterator end() { return points.end(); }
        
        const_iterator begin() const { return points.cbegin(); }
        const_iterator end() const { return points.cend(); }

        ~Nuage() {
        for (auto point : points) {
            delete point; 
        }
    }
};

class BarycentreCartesien {
    public:
        Cartesien operator()(const Nuage& nuage);
};

class BarycentrePolaire {
    public:
        Polaire operator()(const Nuage& nuage);
};
#endif