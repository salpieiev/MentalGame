//
//  PlainDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 24.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingComposite.h"



namespace Renderer {
    
    class VertexBuffer;
    class IndexBuffer;
    class PositionColorInitializer;
    class ProjectionModelviewInitializer;
    class GLSLDrawRequest;
    class Polyhedron;
    
    
    
    class ColorGlassDrawing: public DrawingComposite {
    public:
        ColorGlassDrawing();
        ~ColorGlassDrawing();
        
        Matrix4 GetModelviewMatrix() const;
        
        // Animation delegate
        Point GetPosition() const;
        Quaternion GetQuaternion() const;
        
        void SetPosition(const Point &rPosition);
        void SetQuaternion(const Quaternion &rQuaternion);
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
        PositionColorInitializer*m_attributeInitializer;
        ProjectionModelviewInitializer *m_uniformInitializer;
        GLSLDrawRequest *m_drawRequest;
        Polyhedron *m_shape;
        
        Point m_position;
        Quaternion m_quaternion;
    };
}
