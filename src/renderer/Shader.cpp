//
// Created by Anze Wang on 2/2/23.
//

#include "Shader.h"
#include "Renderer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>


Shader::Shader(const std::string &filePath):mFilePath(filePath), mRendererID(0) {
    ShaderProgramSource source = parseShader();
    mRendererID = CreateShader(source.vertexShader, source.fragmentShader);

}

Shader::~Shader() {
    GL_CALL(glDeleteProgram(mRendererID));
}

void Shader::Bind() {
    GL_CALL(glUseProgram(mRendererID));
}

void Shader::UnBind() {
    GL_CALL(glUseProgram(0));
}

unsigned int Shader::CreateShader(const std::string &vertexShader, const std::string &fragmentShader) {
    GL_CALL(unsigned int shaderProgram = glCreateProgram());
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int vf = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
    GL_CALL(glAttachShader(shaderProgram, vs));
    GL_CALL(glAttachShader(shaderProgram, vf));
    GL_CALL(glLinkProgram(shaderProgram));
    GL_CALL(glValidateProgram(shaderProgram));
    GL_CALL(glDeleteShader(vs));
    GL_CALL(glDeleteShader(vf));
    return shaderProgram;
}

ShaderProgramSource Shader::parseShader() {
    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1,
    };

    std::ifstream stream(mFilePath);
    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while(getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                type = ShaderType::VERTEX;
            } else if (line.find("fragment") != std::string::npos) {
                type = ShaderType::FRAGMENT;
            }
        } else {
            ss[(int)type] << line << "\n";
        }
    }
    return {ss[0].str(), ss[1].str()};
}


unsigned int Shader::CompileShader(unsigned int type, const std::string shader) {
    GL_CALL(unsigned int id = glCreateShader(type));
    const char* src = shader.c_str();
    GL_CALL(glShaderSource(id, 1, &src, NULL));
    GL_CALL(glCompileShader(id));
    // check for shader compile errors
    int result;
    char infoLog[512];
    GL_CALL(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
    if (result == GL_FALSE)
    {
        int length;
        GL_CALL(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        char* message = (char*) malloc(length*sizeof(char));
        GL_CALL(glGetShaderInfoLog(id, length, &length, message));
        std::cout << "Fail to compile: "  << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment") << " shader "<< std::endl;
        std::cout << infoLog << std::endl;
        return 0;
    }
    return id;
}

unsigned int Shader::GetUniformLocation(const std::string &name) {
    if(mUniformLocationCache.find(name) != mUniformLocationCache.end())
        return mUniformLocationCache[name];
    GL_CALL(unsigned int location = glGetUniformLocation(mRendererID, name.c_str()));
    if(location == -1) {
        std::cout << "Warning: " << name << " doesn't exist" << std::endl;
    }
    mUniformLocationCache[name] = location;
    return location;
}