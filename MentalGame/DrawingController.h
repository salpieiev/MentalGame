//
//  DrawingController.h
//  MentalGame
//
//  Created by Sergey Alpeev on 16.03.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "DrawingComposite.h"
#include "TouchesHandler.h"



namespace Renderer {
    
    class DrawingController: public TouchesHandler {
    public:
        DrawingController();
        ~DrawingController();
        
        DrawingComposite *GetDrawing() const;
        
    private:
        DrawingComposite *m_drawing;
    };
}
