//
//  Drawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawRequest.h"



namespace Renderer {
    
    class Drawing {
    public:
        Drawing();
        ~Drawing();
        
        void Draw() const;
    };
}
