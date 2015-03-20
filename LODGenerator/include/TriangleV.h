#ifndef TRIANGLEV_H_
#define TRIANGLEV_H_
//----------------------------------------------------------------------------------------------------------------------
/// @file TriangleV.h
/// @brief basic triangle face class and vertex class for the LODGenerator
//----------------------------------------------------------------------------------------------------------------------

#include <ngl/Types.h>
#include <ngl/Vec4.h>
#include <vector>

//----------------------------------------------------------------------------------------------------------------------
/// @class TriangleV "include/TriangleV.h"
/// @brief used to store vertex and face/triangle information for the ModelLOD
/// class and the imported model
/// @author Jonathan Flynn
/// @version 0.1
/// @date 07/03/15 moved the Triangle.h and Vertex.h together
/// @todo change the ctor for the triangle to calculate the face normal
/// @todo change ctor of vertex to calculate adjacent vertices and faces
/// @todo write function to calculate adjacent verticies and faces
/// @todo this will need to be in the ModelLOD.h
//----------------------------------------------------------------------------------------------------------------------

class Triangle;

class Vertex
{

public:

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default constructor
  /// @param[in]  _id of the model's vertex number
  //----------------------------------------------------------------------------------------------------------------------
  Vertex( const int _id=0):
    m_id(_id){;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief copy ctor
  //----------------------------------------------------------------------------------------------------------------------
  Vertex( const Vertex& _v ):
    m_id(_v.m_id){;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief check for equality uses FCompare (from Util.h) as float values
  /// @param[in] _v the vertex to check against
  /// @returns true or false
  //----------------------------------------------------------------------------------------------------------------------
  bool operator==( const Vertex& _v )const;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief not equal check
  /// @param[in] _v the vertex to check against
  /// @returns true of false
  //----------------------------------------------------------------------------------------------------------------------
  bool operator!=( const Vertex& _v )const;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief assignment operator set the current vecrtex to rhs
  /// @param[in] _v the vertex to set
  /// @returns a new vertex
  //----------------------------------------------------------------------------------------------------------------------
  Vertex& operator=( const Vertex& _v );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief remove adjacent triangle
  /// @param[in] pointer to triangle face
  //----------------------------------------------------------------------------------------------------------------------
  void remAdjFace( Triangle *_t );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief remove adjacent vertex
  /// @param[in] pointer to vertex
  //----------------------------------------------------------------------------------------------------------------------
  void remAdjVert( Vertex* _v );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief add adjacent traingle
  /// @param[in] pointer to triangle face
  //----------------------------------------------------------------------------------------------------------------------
  void addAdjFace( Triangle* _t);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief add adjacent vertext
  /// @param[in] pointer to vertex
  //----------------------------------------------------------------------------------------------------------------------
  void addAdjVert( Vertex* _v);

protected:

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief id of the model's vertex number
  //----------------------------------------------------------------------------------------------------------------------
  int m_id;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief stores the vertices from the mesh
  //----------------------------------------------------------------------------------------------------------------------
  std::vector<ngl::Vec3> m_verts;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief stores the adjacent vertices to the current vertex
  //----------------------------------------------------------------------------------------------------------------------
  std::vector<Vertex *> m_vertAdj;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief stores the adjacent faces to the current vertex
  //----------------------------------------------------------------------------------------------------------------------
  std::vector<Triangle *> m_faceAdj;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief value for the lowest amount of change cost to remove this vertex
  //----------------------------------------------------------------------------------------------------------------------
  float m_cost;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the vertex to collapse onto to create the lowest cost "m_cost"
  //----------------------------------------------------------------------------------------------------------------------
  Vertex* m_collapseVertex;

};
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
class Triangle
{

public:
  Triangle(){;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default constructor
  /// @param[in]  _v0 vertex zero
  /// @param[in]  _v1 vertex one
  /// @param[in]  _v2 vertex two
  //----------------------------------------------------------------------------------------------------------------------
  Triangle( Vertex *_v0, Vertex *_v1, Vertex *_v2 )
  {
    m_vert[0] = _v0;
    m_vert[1] = _v1;
    m_vert[2] = _v2;
  }
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief copy ctor
  //----------------------------------------------------------------------------------------------------------------------
  Triangle( const Triangle &_t ):
    m_vert(_t.m_vert){;}

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief check for equality uses FCompare (from Util.h) as float values
  /// @param[in] _v the vertex to check against
  /// @returns true or false
  //----------------------------------------------------------------------------------------------------------------------
  bool operator==( const Triangle &_t )const;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief not equal check
  /// @param[in] _v the vertex to check against
  /// @returns true of false
  //----------------------------------------------------------------------------------------------------------------------
  bool operator!=(  const Triangle &_t )const;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief assignment operator set the current vecrtex to rhs
  /// @param[in] _v the vertex to set
  /// @returns a new vertex
  //----------------------------------------------------------------------------------------------------------------------
  Triangle& operator =( Triangle &_t );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief calculates normal and stores in m_fNormal
  //----------------------------------------------------------------------------------------------------------------------
  void calculateNormal( );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief array of three vertices that make up the triangle
  //----------------------------------------------------------------------------------------------------------------------
  std::vector<Vertex *> m_vert;

protected:


  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the face normal
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec4 m_fNormal;

};

#endif
//----------------------------------------------------------------------------------------------------------------------
