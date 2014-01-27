//
//  GLDefaultConstants.h
//  MentalGame
//
//  Created by Sergey Alpeev on 26.12.13.
//  Copyright (c) 2013 Sergey Alpeev. All rights reserved.
//

#pragma once
#include <OpenGLES/ES2/gl.h>



enum GLSL_BUFFER
{
    GLSL_ARRAY_BUFFER = GL_ARRAY_BUFFER,
    GLSL_ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER
};

enum GLSL_BUFFER_USAGE
{
    GLSL_BUFFER_USAGE_STREAM_DRAW = GL_STREAM_DRAW,
    GLSL_BUFFER_USAGE_STATIC_DRAW = GL_STATIC_DRAW,
    GLSL_BUFFER_USAGE_DYNAMIC_DRAW = GL_DYNAMIC_DRAW
};

enum GLSL_SHADER_TYPE
{
    GLSL_SHADER_TYPE_VERTEX = GL_VERTEX_SHADER,
    GLSL_SHADER_TYPE_FRAGMENT = GL_FRAGMENT_SHADER
};

enum GLSL_GET
{
    // TODO: New values should be added
    GLSL_GET_ARRAY_BUFFER_BINDING = GL_ARRAY_BUFFER_BINDING,
    GLSL_GET_CURRENT_PROGRAM = GL_CURRENT_PROGRAM,
    GLSL_GET_ELEMENT_ARRAY_BUFFER_BINDING = GL_ELEMENT_ARRAY_BUFFER_BINDING,
    GLSL_GET_FRAMEBUFFER_BINDING = GL_FRAMEBUFFER_BINDING,
    GLSL_GET_RENDERBUFFER_BINDING = GL_RENDERBUFFER_BINDING
};

enum GLSL_DATA_TYPE
{
    GLSL_DATA_TYPE_BYTE = GL_BYTE,
    GLSL_DATA_TYPE_UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
    GLSL_DATA_TYPE_SHORT = GL_SHORT,
    GLSL_DATA_TYPE_UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
    GLSL_DATA_TYPE_INT = GL_INT,
    GLSL_DATA_TYPE_UNSIGNED_INT = GL_UNSIGNED_INT,
    GLSL_DATA_TYPE_FLOAT = GL_FLOAT,
    GLSL_DATA_TYPE_FIXED = GL_FIXED
};

enum GLSL_RENDER_MODE
{
    GLSL_RENDER_MODE_POINTS = GL_POINTS,
    GLSL_RENDER_MODE_LINE_STRIP = GL_LINE_STRIP,
    GLSL_RENDER_MODE_LINE_LOOP = GL_LINE_LOOP,
    GLSL_RENDER_MODE_LINES = GL_LINES,
    GLSL_RENDER_MODE_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
    GLSL_RENDER_MODE_TRIANGLE_FAN = GL_TRIANGLE_FAN,
    GLSL_RENDER_MODE_TRIANGLES = GL_TRIANGLES
};

enum GLSL_ERROR
{
    GLSL_ERROR_NO_ERROR = GL_NO_ERROR,
    GLSL_ERROR_INVALID_ENUM = GL_INVALID_ENUM,
    GLSL_ERROR_INVALID_VALUE = GL_INVALID_VALUE,
    GLSL_ERROR_INVALID_OPERATION = GL_INVALID_OPERATION,
    GLSL_ERROR_INVALID_FRAMEBUFFER_OPERATION = GL_INVALID_FRAMEBUFFER_OPERATION,
    GLSL_ERROR_OUT_OF_MEMORY = GL_OUT_OF_MEMORY
};

enum GLSL_BOOL
{
    GLSL_FALSE = GL_FALSE,
    GLSL_TRUE = GL_TRUE
};

enum GLSL_PROGRAM_IV
{
    GLSL_PROGRAM_IV_DELETE_STATUS = GL_DELETE_STATUS,
    GLSL_PROGRAM_IV_LINK_STATUS = GL_LINK_STATUS,
    GLSL_PROGRAM_IV_VALIDATE_STATUS = GL_VALIDATE_STATUS,
    GLSL_PROGRAM_IV_INFO_LOG_LENGTH = GL_INFO_LOG_LENGTH,
    GLSL_PROGRAM_IV_ATTACHED_SHADERS = GL_ATTACHED_SHADERS,
    GLSL_PROGRAM_IV_ACTIVE_ATTRIBUTES = GL_ACTIVE_ATTRIBUTES,
    GLSL_PROGRAM_IV_ACTIVE_ATTRIBUTE_MAX_LENGTH = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
    GLSL_PROGRAM_IV_ACTIVE_UNIFORMS = GL_ACTIVE_UNIFORMS,
    GLSL_PROGRAM_IV_ACTIVE_UNIFORM_MAX_LENGTH = GL_ACTIVE_UNIFORM_MAX_LENGTH
};

enum GLSL_SHADER_IV
{
    GLSL_SHADER_IV_SHADER_TYPE = GL_SHADER_TYPE,
    GLSL_SHADER_IV_DELETE_STATUS = GL_DELETE_STATUS,
    GLSL_SHADER_IV_COMPILE_STATUS = GL_COMPILE_STATUS,
    GLSL_SHADER_IV_INFO_LOG_LENGTH = GL_INFO_LOG_LENGTH,
    GLSL_SHADER_IV_SHADER_SOURCE_LENGTH = GL_SHADER_SOURCE_LENGTH
};

enum GLSL_GET_VERTEX_ATTRIB
{
    GLSL_GET_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING,
    GLSL_GET_VERTEX_ATTRIB_ARRAY_ENABLED = GL_VERTEX_ATTRIB_ARRAY_ENABLED,
    GLSL_GET_VERTEX_ATTRIB_ARRAY_SIZE = GL_VERTEX_ATTRIB_ARRAY_SIZE,
    GLSL_GET_VERTEX_ATTRIB_ARRAY_STRIDE = GL_VERTEX_ATTRIB_ARRAY_STRIDE,
    GLSL_GET_VERTEX_ATTRIB_ARRAY_TYPE = GL_VERTEX_ATTRIB_ARRAY_TYPE,
    GLSL_GET_VERTEX_ATTRIB_ARRAY_NORMALIZED = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED,
    GLSL_GET_VERTEX_ATTRIB_CURRENT_VERTEX_ATTRIB = GL_CURRENT_VERTEX_ATTRIB
};

enum FRAMEBUFFER_OBJECT {
    FRAMEBUFFER_OBJECT_FRAMEBUFFER = GL_FRAMEBUFFER,
    FRAMEBUFFER_OBJECT_RENDERBUFFER = GL_RENDERBUFFER
};

enum FRAMEBUFFER_ATTACHMENT {
    FRAMEBUFFER_ATTACHMENT_COLOR0 = GL_COLOR_ATTACHMENT0,
    FRAMEBUFFER_ATTACHMENT_DEPTH = GL_DEPTH_ATTACHMENT,
    FRAMEBUFFER_ATTACHMENT_STENCIL = GL_STENCIL_ATTACHMENT
};

enum COLOR_RENDERBUFFER_FORMAT {
    COLOR_RENDERBUFFER_FORMAT_RGBA4 = GL_RGBA4,
    COLOR_RENDERBUFFER_FORMAT_RGB565 = GL_RGB565,
    COLOR_RENDERBUFFER_FORMAT_RGB5_A1 = GL_RGB5_A1
};

enum DEPTH_RENDERBUFFER_FORMAT {
    DEPTH_RENDERBUFFER_FORMAT_COMPONENT16 = GL_DEPTH_COMPONENT16
};

enum STENCIL_RENDERBUFFER_FORMAT {
    STENCIL_RENDERBUFFER_FORMAT_INDEX8 = GL_STENCIL_INDEX8
};