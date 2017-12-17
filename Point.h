
#ifndef OOP_RAB5_POINT_H
#define OOP_RAB5_POINT_H
class Point{
private: double x, y, z;
public:
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    double getZ() const {
        return z;
    }
    double getRast(){
        return sqrt(x*x+y*y+z*z);
    }
    static double getRast2(Point x1, Point x2){
        return sqrt(((x1.getX()-x2.getX()))*(x1.getX()-x2.getX()) + (x1.getY()-x2.getY())*(x1.getY()-x2.getY()) + (x1.getZ()-x2.getZ())*(x1.getZ()-x2.getZ()));
    }

    bool operator<(const Point &P) const {
        return (x*x + y*y + z*z) < ((P.x*P.x)+(P.y*P.y)+(P.z*P.z));
    }
};
#endif //OOP_RAB5_POINT_H
