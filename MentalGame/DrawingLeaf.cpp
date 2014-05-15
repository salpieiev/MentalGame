//
//  DrawingLeaf.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 12.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "DrawingLeaf.h"



namespace Renderer {
    
    void DrawingLeaf::UpdateHierarchy(float interval) {
        DrawingComponent::UpdateHierarchy(interval);
        Update(interval);
    }
    
    void DrawingLeaf::DrawHierarchy() const {
        Draw();
    }
    
    DrawingComponent * DrawingLeaf::HitTest(const Point3 &rPoint) {
        if (PointInside(rPoint)) {
            return this;
        }
        
        return nullptr;
    }
    
    void DrawingLeaf::Update(float interval) {
        
    }
    
    void DrawingLeaf::Draw() const {
        
    }
}
