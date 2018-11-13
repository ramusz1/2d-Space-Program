#include "UniverseView.hpp"
#include "models/Drawable.hpp"
#include "models/Triangle.hpp"

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
    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glClear( GL_COLOR_BUFFER_BIT );

    auto& drawables = universeModel.getWorldObjects();

    for(auto& drawable : drawables)
    {
        auto vertexBuffer = drawable.getVertexBuffer();
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(
            0,                  // attribute
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    window.swapBuffers();
}