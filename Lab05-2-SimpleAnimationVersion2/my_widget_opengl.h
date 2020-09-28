#ifndef MY_WIDGET_OPENGL_H
#define MY_WIDGET_OPENGL_H
#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class MiWidgetOpenGL: public QOpenGLWidget{

public:
    MiWidgetOpenGL();
    ~MiWidgetOpenGL();
    float r,g,b;
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
private:
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vbo{QOpenGLBuffer::VertexBuffer};
    QOpenGLShaderProgram *sp;
};
#endif // MY_WIDGET_OPENGL_H
