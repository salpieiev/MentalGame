//
//  GLSLPositionColorDrawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 09.11.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawing.h"



namespace GLRenderer
{
    class GLSLPositionColorDrawing: public GLSLDrawing
    {
    public:
        GLSLPositionColorDrawing();
        ~GLSLPositionColorDrawing();
        
    private:
        string VertexShaderName() const;
        string FragmentShaderName() const;
    };
}