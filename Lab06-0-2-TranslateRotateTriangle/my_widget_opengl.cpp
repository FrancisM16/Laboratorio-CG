#include "my_widget_opengl.h"
MiWidgetOpenGL::MiWidgetOpenGL()
{
    r = 0;
    g = 0;
    b = 0;
}

MiWidgetOpenGL::~MiWidgetOpenGL()
{

}

void MiWidgetOpenGL::initializeGL()
{
    vao.create();
    vao.bind();

    vbo.create();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.bind();

    vao.release();
    vbo.release();
}

void MiWidgetOpenGL::resizeGL(int w, int h)
{

}

void MiWidgetOpenGL::paintGL()
{
    vao.bind();
    vbo.bind();
    glClearColor(r, g, b, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

}


