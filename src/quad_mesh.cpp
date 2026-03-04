#include "quad_mesh.h"
#include <vector>
#include <glad/glad.h>

QuadMesh::QuadMesh() {
    std::vector<float> data = {
        -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // 0
         0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // 1
         0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // 2
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f  // 3
    };
    std::vector<unsigned int> elementIndices = {
        0,1,2,
        2,3,0
    };

    vertex_count = 6;
    //setup of VAO VBO and EBO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementIndices.size() * sizeof(unsigned int), elementIndices.data(), GL_STATIC_DRAW);
    
    //VertexAttribPointers

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)12);
    glEnableVertexAttribArray(1);
};

void QuadMesh::draw(){
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, vertex_count, GL_UNSIGNED_INT, 0);
}

QuadMesh::~QuadMesh(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}