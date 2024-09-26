#include "nuage.hpp"

void Nuage::ajouter(const Cartesien& point) {
    Point * p = new Cartesien(point);
    points.push_back(p);
}

void Nuage::ajouter(const Polaire& point){
    Point * p = new Polaire(point);
    points.push_back(p);
}

Cartesien Nuage::barycentre(const Nuage& n){
    double sumX = 0.0;
    double sumY = 0.0;
    std::size_t count = n.points.size();

    for (const auto& point : n.points) {
        if (auto* cartesien = dynamic_cast<Cartesien*>(point)) {
            sumX += cartesien->getX();
            sumY += cartesien->getY();
        } else if (auto* polaire = dynamic_cast<Polaire*>(point))
        {
            Cartesien cartesien(*polaire); 
            sumX += cartesien.getX();
            sumY += cartesien.getY();
        }
    }

    return Cartesien(sumX / count, sumY / count);
}

Cartesien BarycentreCartesien::operator()(const Nuage& n){
    return Nuage::barycentre(n);
}

Polaire BarycentrePolaire::operator()(const Nuage& n){
    return Nuage::barycentre(n);
}