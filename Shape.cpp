#include "Shape.h"
#include <fstream>

const char* Shape::getColor() const {
    switch (m_color) {
    case(COLORS::RED):      return "black";
    case(COLORS::GREEN):    return "green";
    case(COLORS::BLUE):     return "blue";
    case(COLORS::WHITE):    return "white";
    case(COLORS::BLACK):    return "black";
    default:                       return "undef_color";
    }
}

Rect::Rect(int x1, int y1, int x2, int y2, COLORS color) :
    m_x1(x1), m_x2(x2), m_y1(y1), m_y2(y2), Shape(color)
{}

double Rect::getS() const {
    int width = 0;

    if (m_y1 > m_y2) {
        width = m_y1 - m_y2;
    }
    else {
        width = m_y2 - m_y1;
    }

    int height = 0;
    if (m_x1 > m_x2) {
        height = m_x1 - m_x2;
    }
    else {
        height = m_x2 - m_x1;
    }

    unsigned int S = width * height;

    return static_cast<double>(S);
}

void Rect::print(std::ofstream& out) const
{
	int x1, y1, x2, y2;
	getCoordinates(x1, y1, x2, y2);
	out << 'R' << ' ' << x1 <<' ' << y1 << ' '<< x2 << ' ' << y2 << ' '<< getColor() << '\n' ;
}

bool Rect::operator==(const Shape& shape) const{

    if (typeid(shape) == typeid(Rect)) {
        const Rect* tmp = static_cast<const Rect*> (&shape);
        bool colorCheck = Shape::operator==(shape);
        return colorCheck && tmp->m_x1 == m_x1 && tmp->m_y1 == m_y1 &&
            tmp->m_x2 == m_x2 && tmp->m_y2 == m_y2;
    }
    else return false;
}

std::ostream& operator<< (std::ostream& out, const Rect& r)
{
    out << r.getColor() << " rect with coordinates: {" << r.m_x1 << 
        ", " << r.m_x2 << "}, {" << r.m_y1 << ", " << r.m_y2 << "}\n";
    return out;
}

Circle::Circle(int xCenter, int yCenter, int rad, COLORS color) :
    m_xCenter(xCenter), m_yCenter(yCenter), m_rad(rad), Shape(color)
{}

bool Circle::operator==(const Shape& shape) const {
    if (typeid(shape) == typeid(Circle)) {
        const Circle* tmp = static_cast<const Circle*> (&shape);
        bool colorCheck = Shape::operator==(shape);
        return colorCheck && tmp->m_xCenter == m_xCenter && tmp->m_yCenter == m_yCenter &&
            tmp->m_rad == m_rad;
    }
    else return false;
}

void Circle::print(std::ofstream& out) const {


	out << 'C' << ' ' << getXCenter() << ' ' << getYCenter() << ' ' << getRad() << ' ' <<Shape::getColor()<< ' '  << '\n';

}

std::ostream& operator<< (std::ostream& out, const Circle& c) {
    out << c.getColor() << " circle with coordinates of center: {" << c.m_xCenter << ", " << c.m_yCenter
        << "} and radius = " << c.m_rad << '\n';
    return out;
}

