#include "my_widget_opengl.h"
MiWidgetOpenGL::MiWidgetOpenGL()
{
    r = 0;
    g = 0;
    b = 0;
    primitiva = 0;
}

MiWidgetOpenGL::~MiWidgetOpenGL()
{

}

void MiWidgetOpenGL::initializeGL()
{
    float x = 0;
    float y = 0;
    float z = 0;
    float radius = 1;
    int numberOfSides = 50; // 50
    numberOfVertices = numberOfSides+1; // points + one center point
    float twicePi = 2.0f * M_PI;

    float verticesX[numberOfVertices];
    float verticesY[numberOfVertices];
    float verticesZ[numberOfVertices];

    verticesX[0] = x;
    verticesY[0] = y;
    verticesZ[0] = z;

    for (int i = 1; i < numberOfVertices; i++) {
        verticesX[i] = x + (radius * cos(i * twicePi / numberOfSides));
        verticesY[i] = y + (radius * sin(i * twicePi / numberOfSides));
        verticesZ[i] = z;
    }
    dimVertices = (numberOfVertices) * 3;
    float m_Vertices[dimVertices];

    for (int i = 0; i < numberOfVertices; i++) {
        m_Vertices[i * 3] = verticesX[i];
        m_Vertices[i * 3 + 1] = verticesY[i];
        m_Vertices[i * 3 + 2] = verticesZ[i];
    }

    initializeOpenGLFunctions();
    vao.create();
    vao.bind();

    vbo.create();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.bind();
    vbo.allocate(m_Vertices, sizeof(m_Vertices));

    vao.release();
    vbo.release();
}

void MiWidgetOpenGL::resizeGL(int w, int h)
{

}

void MiWidgetOpenGL::paintGL()
{
    glClearColor(r, g, b, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    vao.bind();
    vbo.bind();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0, // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*) 0            // array buffer offset
    );
    GLenum mode[7] = {
                    GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP,
                    GL_TRIANGLES, GL_TRIANGLE_FAN, GL_TRIANGLE_STRIP };
    switch(primitiva){
        case 0:
            glDrawArrays(mode[primitiva], 0, numberOfVertices);
            break;
        case 1:
            glDrawArrays(mode[primitiva], 0, numberOfVertices);
            break;
        case 2:
            glDrawArrays(mode[primitiva], 0, numberOfVertices);
            break;
        case 3:
            glDrawArrays(mode[primitiva], 0, numberOfVertices);
            break;
        case 4:
            glDrawArrays(mode[primitiva], 0, numberOfVertices);
            break;
        case 5:
            glDrawArrays(mode[primitiva], 0, numberOfVertices);
            break;
        case 6:
            glDrawArrays(mode[primitiva], 0, numberOfVertices);
            break;

    }

}
