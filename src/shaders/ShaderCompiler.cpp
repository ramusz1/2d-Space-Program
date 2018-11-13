/*
    code based on http://www.opengl-tutorial.org/
*/

#include "ShaderCompiler.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

string getFileContents(const string& filename)
{
    ifstream in(filename);
    if( !in.is_open() )
    {
        cerr << "unable to open file "<< filename << endl;
        return "";
    }
    stringstream buffer;
    buffer << in.rdbuf();
    return buffer.str();
}

GLuint compileProgram(const string& vertexShaderFile, const string& fragmentShaderFile)
{

    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Get code
    auto vertexShaderCode = getFileContents(vertexShaderFile);
    auto fragmentShaderCode = getFileContents(fragmentShaderFile);

    // Compile vertex shader
    cout << "compiling vertex shader"<< endl;
    const auto vertexCodePointer = vertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &vertexCodePointer, NULL);
    glCompileShader(VertexShaderID);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        cerr << &VertexShaderErrorMessage[0] << endl;
    }

    // Compile fragment Shader
    cout << "compiling fragment shader"<< endl;
    const auto fragmentCodePointer = fragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &fragmentCodePointer, NULL);
    glCompileShader(FragmentShaderID);

    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        cerr << &FragmentShaderErrorMessage[0] << endl;
    }

    // Link the program
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        cout << &ProgramErrorMessage[0] << endl;
    }

    
    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);
    
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}