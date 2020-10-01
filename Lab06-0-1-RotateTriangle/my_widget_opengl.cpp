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
    m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
                                       "#version 450\n"
                                       "in vec3 position;\n"
                                       "in vec3 color;\n"
                                       "out vec4 fragColor;\n"
                                       "uniform mat4 mv_matrix;\n"
                                       "void main() {\n"
                                       "    fragColor = vec4(color, 1.0);\n"
                                       "    gl_Position = mv_matrix * vec4(position.x*0.5,position.y*0.5,position.z*0.5, 1.0);\n"
                                       "}\n"
                                       );
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                       "#version 450\n"
                                       "in vec4 fragColor;\n"
                                       "out vec4 finalcolor;\n"
                                       "void main() {\n"
                                       "    finalcolor = fragColor;\n"
                                       "}\n"
                                       );
    m_program->link();
    m_program->bind();
    base = QTransform();
    float vertices[] = {
             0.0f,  1.0f, 0.0f,
             1.0f, -1.0f, 0.0f,
             -1.0f, -1.0f, 0.0f
    };

    vao.create();
    vao.bind();


    vbo.create();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.bind();
    vbo.allocate(vertices, sizeof(vertices));
    m_program->enableAttributeArray("position");
    m_program->setAttributeBuffer("position", GL_FLOAT, 0, 3);

    vao.release();
    //vbo.release();
}

void MiWidgetOpenGL::resizeGL(int w, int h)
{

}

void MiWidgetOpenGL::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    m_program->bind();


    base.rotate(1,0.0f,0.0f,1.0f); //GIRA EN BASE AL EJE
    m_program->setUniformValue("mv_matrix",base);

    vao.bind();
    m_program->setAttributeValue("color",QVector3D(1,0,0));
    glDrawArrays(GL_TRIANGLES,0,3);
    update();

}


