//
//  RenderingEngine.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "RenderingEngine.h"
#include "Logger.h"
#include "GLConstants.h"



namespace Renderer {
    
#pragma mark - Lifecycle
    
    // TODO: Size has default constructor, that initializes to 0. Is initialization required here?
    RenderingEngine::RenderingEngine(): m_framebuffer(nullptr), m_drawingController(nullptr), m_windowSize(0.0f, 0.0f) {
        m_touches = new vector<Touch *>;
    }
    
    RenderingEngine::~RenderingEngine() {
        delete m_drawingController;
        
        for (vector<Touch *>::iterator iterator = m_touches->begin(); iterator != m_touches->end(); iterator++) {
            delete *iterator;
        }
        delete m_touches;
    }
    
#pragma mark - Public Methods
    
    void RenderingEngine::SetFramebuffer(Framebuffer *pFramebuffer) {
        m_framebuffer = pFramebuffer;
    }
    
    Framebuffer * RenderingEngine::GetFramebuffer() const {
        return m_framebuffer;
    }
    
    void RenderingEngine::SetDrawingController(DrawingController *pDrawingController) {
        delete m_drawingController;
        m_drawingController = pDrawingController;
    }
    
    DrawingController * RenderingEngine::GetDrawingController() const {
        return m_drawingController;
    }
    
    void RenderingEngine::SetWindowSize(const CSize &rSize) {
        m_windowSize = rSize;
        ResetRenderFrame();
    }
    
    CSize RenderingEngine::GetWindowSize() const {
        return m_windowSize;
    }
    
    void RenderingEngine::SetProjection(const Projection &rProjection) {
        m_projection = rProjection;
    }
    
    Projection RenderingEngine::GetProjection() const {
        return m_projection;
    }
    
    void RenderingEngine::SetRenderFrame(const Rect &rFrame) const {
        // TODO: GL_MAX_VIEWPORT_DIMS
        glViewport(rFrame.x, rFrame.y, rFrame.width, rFrame.height);
        CheckError();
    }
    
    void RenderingEngine::ResetRenderFrame() const {
        Rect renderFrame(0.0f, 0.0f, m_windowSize.width, m_windowSize.height);
        SetRenderFrame(renderFrame);
    }
    
    Rect RenderingEngine::GetRenderFrame() const {
        Rect renderFrame;
        glGetFloatv(GET_PARAMETER_VIEWPORT, (GLfloat *)(&renderFrame));
        CheckError();
        
        return renderFrame;
    }
    
    void RenderingEngine::Render(float interval) const {
        m_framebuffer->Clear();
        
        m_drawingController->GetDrawing()->UpdateHierarchy(interval);
        m_drawingController->GetDrawing()->DrawHierarchy();
    }
    
#pragma mark Touches
    
    Touch * RenderingEngine::GetTouchForSystemTouch(const void *pSystemTouch) const {
        for (int touchIndex = 0; touchIndex < m_touches->size(); touchIndex++) {
            Touch *touch = m_touches->at(touchIndex);
            if (touch->GetSystemTouch() == pSystemTouch) {
                return touch;
            }
        }
        
        return nullptr;
    }
    
    void RenderingEngine::HandleTouchesBegan(vector<Touch *> &rTouches) const {
        m_touches->insert(m_touches->end(), rTouches.begin(), rTouches.end());
        
        Touch *touch = rTouches[0];
        Point touchPosition = touch->GetProjectionPosition();
        const DrawingComponent *hitDrawing = m_drawingController->GetDrawing()->HitTest(touchPosition);
        Log("%p", hitDrawing);
    }
    
    void RenderingEngine::HandleTouchesMoved(vector<Touch *> &rTouches) const {
        
    }
    
    void RenderingEngine::HandleTouchesEnded(vector<Touch *> &rTouches) const {
        for (int touchIndex = 0; touchIndex < rTouches.size(); touchIndex++) {
            Touch *touch = rTouches[touchIndex];
            m_touches->erase(remove(m_touches->begin(), m_touches->end(), touch));
            delete touch;
        }
    }
    
    void RenderingEngine::HandleTouchesCancelled(vector<Touch *> &rTouches) const {
        for (int touchIndex = 0; touchIndex < rTouches.size(); touchIndex++) {
            Touch *touch = rTouches[touchIndex];
            m_touches->erase(remove(m_touches->begin(), m_touches->end(), touch));
            delete touch;
        }
    }
}
