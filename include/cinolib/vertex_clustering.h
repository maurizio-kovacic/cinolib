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
#ifndef CINO_VERTEX_CLUSTERING_H
#define CINO_VERTEX_CLUSTERING_H

#include <cinolib/cinolib.h>
#include <set>

namespace cinolib
{

/* Groups a list of vertices in clusters of elements closer
 * to each other less than a given proximity threshold
 *
 * NOTE: class Vertex should implement the dist() operator
*/

template<class Vertex>
CINO_INLINE
void vertex_clustering(const std::vector<Vertex>   & points,
                       const double                  proximity_thresh,
                       std::vector<std::set<uint>> & clusters);

}

#ifndef  CINO_STATIC_LIB
#include "vertex_clustering.cpp"
#endif

#endif // CINO_VERTEX_CLUSTERING_H
