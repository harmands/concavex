#include <cmath>

#include "include/common.h"
#include "include/constants.h"
#include "include/utils.h"

bool pointComparator(const Point & a, const Point & b)
{
    if (a.second > b.second)
        return false;
    if (a.second == b.second && a.first > b.first)
        return false;
    return true;
}

double calSlope(const Point &a, const Point &b)
{
    double x1 = a.first, y1 = a.second;
    double x2 = b.first, y2 = b.second;
    double slope;
    if (x1 == x2)
        slope = INF;
    else
        slope = (y1 - y2) / (x1 - x2);
    return slope;
}

double calAngleWithXAxis(const Point &a, const Point &b)
{
    double angle = atan(calSlope(a, b));
    if (angle < 0)
        angle += 2 * M_PIl;
    return angle;
}

bool isClose(double val1, double val2)
{
    if (int(val1 * 1000) == int(val2 * 1000))
        return true;
    return false;
}

double calAngle(const Point& p1, const Point& p2, const Point& p3)
{
    DirVector v1 = std::make_pair(p3.first - p2.first, p3.second - p2.second);
    DirVector v2 = std::make_pair(p1.first - p2.first, p1.second - p2.second);
    double v1Mag = sqrt(v1.first * v1.first + v1.second * v1.second);
    double v2Mag = sqrt(v2.first * v2.first + v2.second * v2.second);
    double v1v2dot = v1.first * v2.first + v1.second * v2.second;
    double v1v2cross = v1.first * v2.second - v2.first * v1.second;
    double cosTheta = v1v2dot / (v1Mag * v2Mag);
    double sinTheta = v1v2cross / (v1Mag * v2Mag);
    double angle1 = asin(sinTheta);
    double angle2 = angle1 > 0 ? M_PIl - angle1 : -M_PIl - angle1;
    double cos1 = cos(angle1);
    double res;
    if (isClose(cos1, cosTheta))
        res = angle1;
    else
        res = angle2;
    return res > 0 ? res : 2 * M_PIl + res;
}

AngleSort::AngleSort(const Point &refPoint)
{
    this->refPoint = refPoint;
}
bool AngleSort::operator()(const Point &a, const Point &b)
{
    double angle_ar = calAngleWithXAxis(a, refPoint);
    double angle_br = calAngleWithXAxis(b, refPoint);
    return angle_ar < angle_br;
}
