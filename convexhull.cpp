#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "include/common.h"
#include "include/utils.h"


PointVector getConvexHull(PointVector& ip)
{
    PointVector::iterator lowerMostItr = std::min_element(
            ip.begin(), ip.end(), pointComparator);
    Point lowerMostPoint = *lowerMostItr;
    ip.erase(lowerMostItr);
    sort(ip.begin(), ip.end(), AngleSort(lowerMostPoint));
    PointVector hullStack;
    hullStack.push_back(lowerMostPoint);
    hullStack.push_back(ip[0]);
    hullStack.push_back(ip[1]);
    for (int i = 2; i < int(ip.size()); i++)
    {
        while (calAngle(hullStack.end()[-2],
                        hullStack.end()[-1], ip[i]) > M_PIl)
            hullStack.pop_back();
        hullStack.push_back(ip[i]);
    }
    return hullStack;
}

// void getConcaveHull(PointVector& ip)
// {
//     // PointVector convexHull = getConvexHull(ip);
//     // return convexHull;
// }

// main()
// {
//     PointVector p;
//     std::srand(0);
//     int npoints = 1000;
//     for (int i = 0; i < npoints; i++)
//     {
//         int val1 = std::rand() % 10, val2 = std::rand() % 10;
//         std::cout << val1 << " " << val2 << std::endl;
//         p.push_back(std::make_pair(val1, val2));
//     }
//     getConvexHull(p);
// }