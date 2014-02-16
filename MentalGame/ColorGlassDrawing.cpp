//
//  PlainDrawing.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 24.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "ColorGlassDrawing.h"
#include "GLLogger.h"
#include "GLSLVertex.h"
#include "GLSLVertexBuffer.h"
#include "GLSLIndexBuffer.h"
#include "GLSLPositionColorInitializer.h"
#include "GLSLProjectionModelviewInitializer.h"
#include "GLSLProgramContainer.h"
#include "Polyhedron.h"



namespace Renderer {
    
    ColorGlassDrawing::ColorGlassDrawing() {
        
        glEnable(GL_CULL_FACE);
        
        Point point0(-1.0, -1.0, 0.25);
        Point point1(1.0, -1.0, 0.25);
        Point point2(1.0, 1.0, 0.25);
        Point point3(-1.0, 1.0, 0.25);
        Point point4(-1.0, -1.0, -0.25);
        Point point5(1.0, -1.0, -0.25);
        Point point6(1.0, 1.0, -0.25);
        Point point7(-1.0, 1.0, -0.25);
        
        // Rendering
        vector<GLSLVertex1P1C> vertices;
        vertices.push_back(GLSLVertex1P1C(point0, GLColor(1.0, 0.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(point1, GLColor(0.0, 1.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(point2, GLColor(0.0, 0.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point3, GLColor(1.0, 1.0, 0.0)));
        vertices.push_back(GLSLVertex1P1C(point4, GLColor(0.0, 1.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point5, GLColor(1.0, 0.0, 1.0)));
        vertices.push_back(GLSLVertex1P1C(point6, GLColor(0.4, 0.2, 0.9)));
        vertices.push_back(GLSLVertex1P1C(point7, GLColor(0.7, 0.2, 0.0)));
        
        vector<GLushort> indices;
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(2);
        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(3);
        indices.push_back(1);
        indices.push_back(5);
        indices.push_back(6);
        indices.push_back(1);
        indices.push_back(6);
        indices.push_back(2);
        indices.push_back(5);
        indices.push_back(4);
        indices.push_back(7);
        indices.push_back(5);
        indices.push_back(7);
        indices.push_back(6);
        indices.push_back(4);
        indices.push_back(0);
        indices.push_back(3);
        indices.push_back(4);
        indices.push_back(3);
        indices.push_back(7);
        indices.push_back(3);
        indices.push_back(2);
        indices.push_back(6);
        indices.push_back(3);
        indices.push_back(6);
        indices.push_back(7);
        indices.push_back(1);
        indices.push_back(0);
        indices.push_back(4);
        indices.push_back(1);
        indices.push_back(4);
        indices.push_back(5);
        
        m_vertexBuffer = new GLSLVertexBuffer();
        m_vertexBuffer->LoadBufferData(&vertices[0], sizeof(GLSLVertex1P1C), vertices.size());
        
        m_indexBuffer = new GLSLIndexBuffer();
        m_indexBuffer->LoadBufferData(indices);
        
        m_attributeInitializer = new GLSLPositionColorInitializer();
        m_uniformInitializer = new GLSLProjectionModelviewInitializer();
        m_uniformInitializer->GetModelviewMatrix().Translate(0.0, 0.0, -5.5).RotateY(M_PI_4);
        
        m_drawRequest = new GLSLVertexBufferIndexBufferRequest(m_vertexBuffer, m_indexBuffer);
        m_drawRequest->SetAttributeInitializer(m_attributeInitializer);
        m_drawRequest->SetUniformInitializer(m_uniformInitializer);
        m_drawRequest->SetRenderMode(GLSL_RENDER_MODE_TRIANGLES);
        
        // Collision
        vector<Plane> planes;
        planes.push_back(Plane(point0, point1, point2));
        planes.push_back(Plane(point1, point5, point6));
        planes.push_back(Plane(point5, point4, point7));
        planes.push_back(Plane(point4, point0, point3));
        planes.push_back(Plane(point1, point0, point4));
        planes.push_back(Plane(point3, point2, point6));
        
        m_shape = new Polyhedron(planes);
        
        
        
        
        
        
        Matrix4 m;
//        m.x.x = 1; m.x.y = 2; m.x.z = 3; m.x.w = 4;
//        m.y.x = 5; m.y.y = 6; m.y.z = 7; m.y.w = 8;
//        m.z.x = 9; m.z.y = 10; m.z.z = 11; m.z.w = 12;
//        m.w.x = 13; m.w.y = 14; m.w.z = 15; m.w.w = 16;
        
//        m.x.x = 2; m.x.y = 2; m.x.z = 3; m.x.w = 4;
//        m.y.x = 5; m.y.y = 6; m.y.z = 7; m.y.w = 8;
//        m.z.x = 9; m.z.y = 7; m.z.z = 11; m.z.w = 12;
//        m.w.x = 13; m.w.y = 14; m.w.z = 15; m.w.w = 16;
        
        m.x.x = 1; m.x.y = 1; m.x.z = 1; m.x.w = 1;
        m.y.x = 1; m.y.y = -1; m.y.z = 1; m.y.w = 1;
        m.z.x = 1; m.z.y = 1; m.z.z = -1; m.z.w = 1;
        m.w.x = 1; m.w.y = 1; m.w.z = 1; m.w.w = -1;
        
        Log("%f", m.Determinant());
    }
    
    ColorGlassDrawing::~ColorGlassDrawing() {
        delete m_vertexBuffer;
        delete m_indexBuffer;
        delete m_attributeInitializer;
        delete m_uniformInitializer;
        delete m_shape;
    }
    
    void ColorGlassDrawing::Update(float interval) {
        m_uniformInitializer->GetModelviewMatrix().RotateX(interval).RotateY(interval).RotateZ(interval);
    }
    
    void ColorGlassDrawing::Draw() const {
        Program *pProgram = GLSLProgramContainer::SharedInstance().GetPerspectiveProgram();
        pProgram->ExecuteDrawRequest(m_drawRequest);
    }
}
