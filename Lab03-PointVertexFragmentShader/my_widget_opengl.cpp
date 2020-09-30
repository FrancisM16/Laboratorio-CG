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
    sp = new QOpenGLShaderProgram();
    sp->addShaderFromSourceCode(QOpenGLShader::Vertex,
                                "#version 410 \n"
                                "in vec3 position;\n"
                                "void main(){\n"
                                "gl_Position = vec4(0.4*position, 1.0);"
                                "}");
    sp->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                "#version 410 \n"
                                "out vec4 color; \n"
                                "void main(void) { \n"
                                "color = vec4(1.0, 0.0, 0.0, 1.0);"
                                "}");
    sp->link();
    float vertices[]={
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f, 1.0f,  0.0f,
    };
    vao.create();
    vao.bind();

    vbo.create();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.bind();
    vbo.allocate(vertices,sizeof(vertices));

    vao.release();
    vbo.release();
}

void MiWidgetOpenGL::resizeGL(int w, int h)
{

}

void MiWidgetOpenGL::paintGL()
{
    sp->bind();
    vao.bind();
    vbo.bind();
    sp->enableAttributeArray("position");
    sp->setAttributeArray("position",GL_FLOAT,0,3);
    glClearColor(r, g, b, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(20.f);
    glDrawArrays(GL_POINTS,0,3);
}
