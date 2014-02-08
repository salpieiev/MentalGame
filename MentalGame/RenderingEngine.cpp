//
//  RenderingEngine.cpp
//  MentalGame
//
//  Created by Sergey Alpeev on 01.02.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "RenderingEngine.h"
#include "GLLogger.h"
#include "ColorGlassDrawing.h"  // TODO: Remove later



namespace Renderer {
    
#pragma mark - Lifecycle
    
    RenderingEngine::RenderingEngine(): m_framebuffer(nullptr), m_rootDrawing(nullptr), m_windowSize(0.0f, 0.0f) {
        m_rootDrawing = new Drawing();
    }
    
    RenderingEngine::~RenderingEngine() {
        delete m_rootDrawing;
    }
    
#pragma mark - Public Methods
    
    void RenderingEngine::SetFramebuffer(Framebuffer *pFramebuffer) {
        m_framebuffer = pFramebuffer;
    }
    
    Framebuffer * RenderingEngine::GetFramebuffer() const {
        return m_framebuffer;
    }
    
    void RenderingEngine::SetWindowSize(const CSize &rSize) {
        m_windowSize = rSize;
        ResetRenderFrame();
        
        // TODO: Remove later
        ColorGlassDrawing *drawing = new ColorGlassDrawing();
        m_rootDrawing->AddSubDrawing(drawing);
    }
    
    CSize RenderingEngine::GetWindowSize() const {
        return m_windowSize;
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
    
    void RenderingEngine::Render() const {
        m_framebuffer->Clear();
        
        m_rootDrawing->DrawHierarchy();
    }
}