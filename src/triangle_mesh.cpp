#include "triangle_mesh.h"
#include <vector>
#include <glad/glad.h>

TriangleMesh::TriangleMesh() {
    std::vector<float> data = {
        -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // 0
         0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // 1
         0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // 2
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f  // 3
    };

    std::vector<int> elementIndices = {
        0,1,2,
        2,3,0
    };
    vertex_count = 6;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    size_t bufferSize = data.size() * sizeof(float);
    glBufferData(GL_ARRAY_BUFFER, bufferSize, data.data(), GL_STATIC_DRAW);
    

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementIndices.size() * sizeof(int), elementIndices.data(), GL_STATIC_DRAW);
        
    //position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
    glEnableVertexAttribArray(0);

    //color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)12);
    glEnableVertexAttribArray(1);
}

void TriangleMesh::draw() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, vertex_count, GL_UNSIGNED_INT, 0);
}

TriangleMesh::~TriangleMesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
