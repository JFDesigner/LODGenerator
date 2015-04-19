#ifndef TRIANGLEV_H_
#define TRIANGLEV_H_
//----------------------------------------------------------------------------------------------------------------------
/// @file TriangleV.h
/// @brief basic triangle face class and vertex class for the LODGenerator
//----------------------------------------------------------------------------------------------------------------------

#include <ngl/Types.h>
#include <ngl/Vec4.h>
#include <vector>
#include <iostream>

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
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief get vertex id
  /// @returns an int being the Vertex ID in the m_verts list
  //----------------------------------------------------------------------------------------------------------------------
  int getID(){ return m_id; }
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief get list of adjacent verts
  /// @returns a std::vector containing the adjacent vertex data
  //----------------------------------------------------------------------------------------------------------------------
  std::vector< Vertex *> getAdjacentVertList(){return m_vertAdj;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief get list of adjacent triangles
  /// @returns a std::vector containing the adjacent triangle data
  //----------------------------------------------------------------------------------------------------------------------
  std::vector< Triangle *> getAdjacentFaceList(){return m_faceAdj;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief get the collapse cost
  /// @returns a float being the collapse cost value
  //----------------------------------------------------------------------------------------------------------------------
  float getCollapseCost(){return m_cost;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief set the collapse cost
  /// @param[in] _cost new value of m_cost
  //----------------------------------------------------------------------------------------------------------------------
  void setCollapseCost(float _cost){ m_cost = _cost;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief get the collapse vertex for the m_cost value
  /// @returns a Vertex pointer to the smallest cost collapse vertex
  //----------------------------------------------------------------------------------------------------------------------
  Vertex* getCollapseVertex(){return m_collapseVertex;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief set the collapse vertex
  /// @param[in] _v new value of m_collapseVertex
  //----------------------------------------------------------------------------------------------------------------------
  void setCollapseVertex(Vertex* _v){ m_collapseVertex = _v;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief finds out if the vertex has a particular adjacent vertex or not
  /// @param[in] _v the pointer to the vertex to check if it exists adjacen to the vertex
  /// @returns a bool value if the Vertex is adjacent or not
  //----------------------------------------------------------------------------------------------------------------------
  bool hasAdjVert( Vertex *_v);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief finds out if the vertex has a particular adjacent triangle or not
  /// @param[in] _t the pointer to the triangle to check if it exists adjacen to the vertex
  /// @returns a bool value if the Triangle is adjacent or not
  //----------------------------------------------------------------------------------------------------------------------
  bool hasAdjFace( Triangle *_t);

protected:

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief id of the model's vertex number
  //----------------------------------------------------------------------------------------------------------------------
  int m_id;
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
  /// @brief default id constructor
  /// @param[in]  _id id number for the face
  //----------------------------------------------------------------------------------------------------------------------
  Triangle( int _id ):
    m_id(_id){;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default vertex constructor
  /// @param[in]  _v0 vertex zero
  /// @param[in]  _v1 vertex one
  /// @param[in]  _v2 vertex two
  //----------------------------------------------------------------------------------------------------------------------
  Triangle( Vertex *_v0, Vertex *_v1, Vertex *_v2 )
  {
    m_vert.reserve(3);
    m_vert.push_back(_v0);
    m_vert.push_back(_v1);
    m_vert.push_back(_v2);
  }
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief default id and vertex constructor
  /// @param[in]  _id id number for the face
  /// @param[in]  _v0 vertex zero
  /// @param[in]  _v1 vertex one
  /// @param[in]  _v2 vertex two
  //----------------------------------------------------------------------------------------------------------------------
  Triangle( int _id, Vertex *_v0, Vertex *_v1, Vertex *_v2 )
  {
    m_id = _id;
    m_vert.reserve(3);
    m_vert.push_back(_v0);
    m_vert.push_back(_v1);
    m_vert.push_back(_v2);

  }
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief copy ctor
  //----------------------------------------------------------------------------------------------------------------------
  Triangle( const Triangle &_t ):
    m_vert(_t.m_vert),
    m_id(_t.m_id) {;}

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
  /// @brief get Triangle id
  /// @returns an int being the Traingle ID in the m_face list
  //----------------------------------------------------------------------------------------------------------------------
  int getID(){ return m_id; }
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief get Triangle normal
  /// @returns a Vec4 containing the vector of the triangle normal
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec4 getFaceNormal(){ return m_fNormal; }
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief calculates normal and stores in m_fNormal
  /// @param[in] _verts the m_vertex list for the ModelLODTri class to access the vertex co-ordinates
  //----------------------------------------------------------------------------------------------------------------------
  void calculateNormal( std::vector<ngl::Vec3> _verts );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief finds out if the triangle has a particular vertex or not
  /// @param[in] _v the pointer to the vertex to check if it exists in the triangle
  //----------------------------------------------------------------------------------------------------------------------
  bool hasVert( Vertex *_v);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief array of three Vertex vertices that make up the triangle
  //----------------------------------------------------------------------------------------------------------------------
  std::vector<Vertex *> m_vert;

protected:


  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the face normal
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec4 m_fNormal;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the triangle id
  //----------------------------------------------------------------------------------------------------------------------
  int m_id;

};

#endif
//----------------------------------------------------------------------------------------------------------------------

