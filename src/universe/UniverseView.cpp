#include "UniverseView.hpp"
#include "shapes/Drawable.hpp"

#include "shaders/ShaderCompiler.hpp"

using namespace std;

UniverseView::UniverseView(const Window& window, const UniverseModel& universeModel): 
window(window),
universeModel(universeModel)
{
    programId = compileProgram("src/shaders/VertexShader.vertexshader", "src/shaders/FragmentShader.fragmentshader");

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    glUseProgram(programId);
}

void UniverseView::render()
{
    glClearColor(0.0f, 0.0f, 0.1f, 0.0f);
    glClear( GL_COLOR_BUFFER_BIT );

    auto& drawables = universeModel.getDrawables();

    for(auto& drawable : drawables)
    {
        glBindBuffer(GL_ARRAY_BUFFER, drawable->getVertexBuffer());
        glVertexAttribPointer(
            0,                  // attribute
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glEnableVertexAttribArray(0);
        glDrawArrays(drawable->getMode(), 0, drawable->getVerticesCount());
    }
    window.swapBuffers();
}