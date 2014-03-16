//
//  GLSLDrawRequest.h
//  MentalGame
//
//  Created by Sergey Alpeev on 07.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>
#include <vector>
#include <map>
#include "GLConstants.h"

using namespace std;



namespace Renderer
{
    class VertexBuffer;
    class IndexBuffer;
    class VertexArray;
    class GLSLAttributeInitializer;
    class UniformInitializer;
    class Attribute;
    class Uniform;
    
    
    
#pragma mark - GLSLDrawRequest
    
    class GLSLDrawRequest
    {
    public:
        GLSLDrawRequest();
        GLSLDrawRequest(const GLSLDrawRequest &rDrawRequest) = delete;
        virtual ~GLSLDrawRequest();
        
        void SetAttributeInitializer(GLSLAttributeInitializer *pAttributeInitializer);
        void SetUniformInitializer(UniformInitializer *pUniformInitializer);
        void SetRenderMode(GLSL_RENDER_MODE renderMode);
        void SetStartDrawIndex(GLint startDrawIndex);
        void SetDrawElementsCount(GLsizei drawElementsCount);
        
        GLSLAttributeInitializer * GetAttributeInitializer() const;
        UniformInitializer * GetUniformInitializer() const;
        GLSL_RENDER_MODE GetRenderMode() const;
        GLint GetStartDrawIndex() const;
        GLsizei GetDrawElementsCount() const;
        
        void ResetStartDrawIndex();
        void ResetDrawCount();
        void ResetStartDrawIndexAndDrawElementsCount();
        
        void Draw(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        
        virtual GLsizei GetVerticesCount() const = 0;
        
    protected:
        virtual void Activate() const = 0;
        virtual void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const = 0;
        virtual void Draw() const = 0;
        
    private:
        GLSLAttributeInitializer *m_attributeInitializer;
        UniformInitializer *m_uniformInitalizer;
        GLSL_RENDER_MODE m_renderMode;
        GLint m_startDrawIndex;
        GLsizei m_drawElementsCount;
    };
    
    
    
#pragma mark - VertexBufferIndexBufferRequest
    
    class VertexBufferIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        VertexBufferIndexBufferRequest(VertexBuffer *pVertexBuffer, IndexBuffer *pIndexBuffer);
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        IndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - VertexBufferShortIndicesRequest
    
    class VertexBufferShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        VertexBufferShortIndicesRequest(VertexBuffer *pVertexBuffer, vector<GLushort> &rIndices);
        ~VertexBufferShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - VertexBufferByteIndicesRequest
    
    class VertexBufferByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        VertexBufferByteIndicesRequest(VertexBuffer *pVertexBuffer, vector<GLubyte> &rIndices);
        ~VertexBufferByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - VertexBufferRequest
    
    class VertexBufferRequest: public GLSLDrawRequest
    {
    public:
        VertexBufferRequest(VertexBuffer *pVertexBuffer);
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexBuffer *m_vertexBuffer;
    };
    
    
    
#pragma mark - VertexArrayIndexBufferRequest
    
    class VertexArrayIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        VertexArrayIndexBufferRequest(VertexArray &rVertexArray, IndexBuffer *pIndexBuffer);
        ~VertexArrayIndexBufferRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexArray *m_vertexArray;
        IndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - VertexArrayShortIndicesRequest
    
    class VertexArrayShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        VertexArrayShortIndicesRequest(VertexArray &rVertexArray, vector<GLushort> &rIndices);
        ~VertexArrayShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexArray *m_vertexArray;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - VertexArrayByteIndicesRequest
    
    class VertexArrayByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        VertexArrayByteIndicesRequest(VertexArray &rVertexArray, vector<GLubyte> &rIndices);
        ~VertexArrayByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexArray *m_vertexArray;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - VertexArrayRequest
    
    class VertexArrayRequest: public GLSLDrawRequest
    {
    public:
        VertexArrayRequest(VertexArray &rVertexArray);
        ~VertexArrayRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        VertexArray *m_vertexArray;
    };
    
    
    
#pragma mark - VertexArraysIndexBufferRequest
    
    class VertexArraysIndexBufferRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        VertexArraysIndexBufferRequest(vector<VertexArray> &rVertexArrays, IndexBuffer *pIndexBuffer);
        ~VertexArraysIndexBufferRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        vector<VertexArray *> *m_vertexArrays;
        IndexBuffer *m_indexBuffer;
    };
    
    
    
#pragma mark - VertexArraysShortIndicesRequest
    
    class VertexArraysShortIndicesRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        VertexArraysShortIndicesRequest(vector<VertexArray> &rVertexArrays, vector<GLushort> &rIndices);
        ~VertexArraysShortIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        vector<VertexArray *> *m_vertexArrays;
        vector<GLushort> *m_indices;
    };
    
    
    
#pragma mark - VertexArraysByteIndicesRequest
    
    class VertexArraysByteIndicesRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        VertexArraysByteIndicesRequest(vector<VertexArray> &rVertexArrays, vector<GLubyte> &rIndices);
        ~VertexArraysByteIndicesRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
    private:
        vector<VertexArray *> *m_vertexArrays;
        vector<GLubyte> *m_indices;
    };
    
    
    
#pragma mark - VertexArraysRequest
    
    class VertexArraysRequest: public GLSLDrawRequest
    {
    public:
        // TODO: Replace pointer with value?
        VertexArraysRequest(vector<VertexArray> &rVertexArrays);
        ~VertexArraysRequest();
        
        GLsizei GetVerticesCount() const;
        
    protected:
        void Activate() const;
        void Initialize(map<string, Attribute *> *pAttributes, map<string, Uniform *> *pUniforms) const;
        void Draw() const;
        
        void CalculateVerticesCount();
        
    private:
        vector<VertexArray *> *m_vertexArrays;
        GLsizei m_verticesCount;
    };
}
