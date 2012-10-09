#ifndef TO_GLSL_H
#define TO_GLSL_H

#include "languages.h"

typedef struct
{
    int shaderType; //One of the GL enums.
    char* sourceCode;
} GLSLShader;

/*HLSL constant buffers are treated as default-block unform arrays by default. This is done
  to support versions of GLSL which lack ARB_uniform_buffer_object functionality.
  Setting this flag causes each one to have its own uniform block.
  Note: Currently the nth const buffer will be named UnformBufferN. This is likey to change to the original HLSL name in the future.*/
static const unsigned int HLSLCC_FLAG_UNIFORM_BUFFER_OBJECT = 0x1;

int TranslateHLSLFromFile(const char* filename, unsigned int flags, GLLang language, GLSLShader* result);
void TranslateHLSLFromMem(const char* shader, unsigned int flags, GLLang language, GLSLShader* result);

#endif
