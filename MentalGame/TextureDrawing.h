//
//  TextureDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingLeaf.h"



namespace Renderer {
    
    class VertexBuffer;
    class IndexBuffer;
    class TexturePositionInitializer;
    class Texture;
    class DrawRequest;
    
    
    
    class TextureDrawing: public DrawingLeaf {
    public:
        TextureDrawing();
        ~TextureDrawing();
        
    protected:
        void Update(float interval);
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
        TexturePositionInitializer *m_attributeInitializer;
        Texture *m_texture;
        DrawRequest *m_drawRequest;
    };
}
