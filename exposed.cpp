#include <iostream>

#include <boost/python.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

#include "include/common.h"
#include "include/convexhull.h"

boost::python::list convex_hull(boost::python::list ip)
{
    boost::python::ssize_t len = boost::python::len(ip);
    PointVector inputPv;
    boost::python::list result;
    for (int i = 0; i < len; i++)
    {
        boost::python::tuple val = boost::python::extract<boost::python::tuple>(ip[i]);
        double x = boost::python::extract<double>(val[0]);
        double y = boost::python::extract<double>(val[1]);
        inputPv.push_back(std::make_pair(x, y));
    }
    PointVector opPv = getConvexHull(inputPv);
    for (int i=0; i<int(opPv.size()); i++)
        result.append(boost::python::make_tuple(opPv[i].first, opPv[i].second));
    return result;
}

BOOST_PYTHON_MODULE(libcavehull)
{
    boost::python::def("convex_hull", convex_hull);
}