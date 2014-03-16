//
//  GLSLVertex.h
//  MentalGame
//
//  Created by Sergey Alpeev on 29.09.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "Point.h"
#include "Color.h"



namespace Renderer
{
    class GLSLVertex1P
    {
    public:
        GLSLVertex1P();
        GLSLVertex1P(Point position);
        
        Point m_position;
    };
    
    
    
    class GLSLVertex1C
    {
    public:
        GLSLVertex1C();
        GLSLVertex1C(Color color);
        
        Color m_color;
    };
    
    
    
    class GLSLVertex1P1C
    {
    public:
        GLSLVertex1P1C();
        GLSLVertex1P1C(Point position, Color color);
        
        Point m_position;
        Color m_color;
    };
}
