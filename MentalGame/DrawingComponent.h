//
//  DrawingComponent.h
//  MentalGame
//
//  Created by Sergey Alpeev on 10.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#pragma once
#include "AnimationDelegate.h"
#include "TouchesHandler.h"
#include <vector>

using namespace std;



namespace Renderer {
    
    class DrawingComposite;
    
    
    
    class DrawingComponent: public AnimationDelegate, public TouchesHandler {
    public:
        DrawingComponent();
        virtual ~DrawingComponent();
        
        virtual void UpdateHierarchy(float interval);
        virtual void DrawHierarchy() const = 0;
        
        void RemoveFromParentDrawing();
        DrawingComposite * GetParentDrawing() const;
        
    protected:
        virtual void Update(float interval) = 0;
        virtual void Draw() const = 0;
        
        friend class DrawingComposite;
        void SetParentDrawing(DrawingComposite *pDrawing);
        
    private:
        DrawingComposite *m_parentDrawing;
    };
}
