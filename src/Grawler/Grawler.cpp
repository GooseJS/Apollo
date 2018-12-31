#define ASSETSYS_IMPLEMENTATION
#define STRPOOL_IMPLEMENTATION
#include "assetsys.h"

#include "Grawler.h"

Apollo::Application* Apollo::createApplication()
{
    return new Grawler;
}

void Grawler::onWindowOpen(Apollo::IEvent& _event)
{
    glGenVertexArrays(1, &_vertexArrayID);
    glBindVertexArray(_vertexArrayID);

    const GLfloat vertexBufferData[] =
            {
                    -1.0f, -1.0f, 0.0f,
                    1.0f, -1.0f, 0.0f,
                    0.0f,  1.0f, 0.0f,
            };

    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

    APOLLO_INFO("Window opened!");

    loadShaders("", "");
}

void Grawler::onUpdate()
{

}

void Grawler::onRender()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
}

GLuint Grawler::loadShaders(const char *vertexFilePath, const char *fragmentFilePath)
{
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    assetsys_t* assetsys = assetsys_create(0);

    assetsys_mount(assetsys, ".", "/data");

    assetsys_file_t file;
    assetsys_file( assetsys, "/data/shader.vert", &file );
    int size = assetsys_file_size( assetsys, file );
    int fileSize = 0;
    char* vertexShaderCode = (char*) malloc(static_cast<size_t>(size + 1)); // extra space for '\0'
    assetsys_file_load(assetsys, file, &fileSize, vertexShaderCode, size);
    vertexShaderCode[size] = '\0'; // zero terminate the text file

    printf("%s\n", &vertexShaderCode[0]);

    glShaderSource(vertexShaderID, 1, &vertexShaderCode , nullptr);
    glCompileShader(vertexShaderID);

    GLint result = GL_FALSE;
    int infoLogLength;

    // Check Vertex Shader
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0)
    {
        std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);
        glGetShaderInfoLog(vertexShaderID, infoLogLength, nullptr, &vertexShaderErrorMessage[0]);
        printf("%s\n", &vertexShaderErrorMessage[0]);
    }

    free(vertexShaderCode);
    assetsys_destroy( assetsys );

}
