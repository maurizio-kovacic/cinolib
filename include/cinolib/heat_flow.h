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
#ifndef CINO_HEAT_FLOW_H
#define CINO_HEAT_FLOW_H

#include <cinolib/cinolib.h>
#include <cinolib/scalar_field.h>
#include <cinolib/linear_solvers.h>

namespace cinolib
{

/* Solve the heat flow problem  (M - t * L) u = u0,
 * subject to certain Dirichlet boundary conditions
*/

template<class M, class V, class E, class P>
CINO_INLINE
ScalarField heat_flow(const AbstractMesh<M,V,E,P> & m,
                      const std::vector<uint>     & heat_charges,
                      const double                  time = 1.0,
                      const int                     laplacian_mode = COTANGENT);
}

#ifndef  CINO_STATIC_LIB
#include "heat_flow.cpp"
#endif

#endif // CINO_HEAT_FLOW_H
