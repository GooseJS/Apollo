#pragma once

#include <GL/gl.h>

namespace Apollo
{
    class IRenderable
    {
    public:
        typedef GLuint VertexArrayObject;
    private:
        VertexArrayObject _vao;
    protected:
        IRenderable() = default;
    public:
        virtual ~IRenderable() = default;

        void bind() { glBindVertexArray }
    };
}