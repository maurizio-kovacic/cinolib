/*********************************************************************************
*  Copyright(C) 2016: Marco Livesu                                               *
*  All rights reserved.                                                          *
*                                                                                *
*  This file is part of CinoLib                                                  *
*                                                                                *
*  CinoLib is dual-licensed:                                                     *
*                                                                                *
*   - For non-commercial use you can redistribute it and/or modify it under the  *
*     terms of the GNU General Public License as published by the Free Software  *
*     Foundation; either version 3 of the License, or (at your option) any later *
*     version.                                                                   *
*                                                                                *
*   - If you wish to use it as part of a commercial software, a proper agreement *
*     with the Author(s) must be reached, based on a proper licensing contract.  *
*                                                                                *
*  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE       *
*  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.     *
*                                                                                *
*  Author(s):                                                                    *
*                                                                                *
*     Marco Livesu (marco.livesu@gmail.com)                                      *
*     http://pers.ge.imati.cnr.it/livesu/                                        *
*                                                                                *
*     Italian National Research Council (CNR)                                    *
*     Institute for Applied Mathematics and Information Technologies (IMATI)     *
*     Via de Marini, 6                                                           *
*     16149 Genoa,                                                               *
*     Italy                                                                      *
**********************************************************************************/
#include <cinolib/map_distortion.h>
#include <cinolib/geometry/vec3.h>
#include <eigen3/Eigen/Dense>

namespace cinolib
{

CINO_INLINE
double aspect_ratio_distortion(const double m[3][3])
{
    using namespace Eigen;

    Matrix3d M;
    from_std_3x3_to_Eigen_3x3(m,M);

    JacobiSVD<Matrix3d> svd(M);
    DiagonalMatrix<double,3> s = DiagonalMatrix<double,3>(svd.singularValues());

    assert(s.diagonal()[0] >= s.diagonal()[1]);
    assert(s.diagonal()[1] >= s.diagonal()[2]);

    return s.diagonal()[0] / std::fabs(s.diagonal()[2]);
}
