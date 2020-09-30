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
                                "#version 450\n"
                                "in vec2 position;\n"
                                "layout (location = 1)in vec3 color;\n"
                                "layout (location = 0)out vec4 fragColor;\n"
                                "void main(){\n"
                                "fragColor=vec4(color,1.0);\n"
                                "gl_Position = vec4(position,0.0,1.0);\n"
                                "}");
    sp->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                "#version 450\n"
                                "in vec4 fragColor;\n"
                                "out vec4 fColor;\n"
                                "void main(){\n"
                                "fColor = fragColor;\n"
                                "}");
    sp->link();
    float vertices[]={
        -0.5f,  0.5f, // P0:Top-left
         0.5f,  0.5f, // P1:Top-right
         0.5f, -0.5f, // P2:Bottom-right

        -0.5f,  0.5f, // P0:Top-left
        -0.5f, -0.5f, // P3:Bottom-left
         0.5f, -0.5f, // P2:Bottom-right

         1.0f, 0.0f, 0.0f,
         0.0f, 1.0f, 0.0f,
         0.0f, 0.0f, 1.0f,

         1.0f, 0.0f, 0.0f,
         1.0f, 1.0f, 1.0f,
         0.0f, 0.0f, 1.0f
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
    sp->setAttributeArray("position",GL_FLOAT,0,2);
    sp->enableAttributeArray("color");
    sp->setAttributeArray("color",GL_FLOAT,(void*)(12*sizeof(float)),3);
    glClearColor(r, g, b, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES,0,6);
}


