//
// Created by Anze Wang on 2/2/23.
//

#ifndef OGLRENDER_SHADER_H
#define OGLRENDER_SHADER_H

#include <string>
#include <glad/glad.h>

struct ShaderProgramSource;

struct ShaderProgramSource {
    std::string  vertexShader;
    std::string  fragmentShader;
};

class Shader {
private:
    std::string mFilePath;
    unsigned int mRendererID;

public:
    Shader(const std::string& filePath);
    ~Shader();

    void Bind();
    void UnBind();

    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3){
        glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
    }

private:
    unsigned int GetUniformLocation(const std::string& name) {
       return glGetUniformLocation(mRendererID, name.c_str());
    }
    ShaderProgramSource parseShader();
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    unsigned int CompileShader(unsigned int type, const std::string source);

};


#endif //OGLRENDER_SHADER_H
